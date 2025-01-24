#include "Robot/PID.h"
#include "Autonomous/auton-functions.h"
#include "vex.h"

#include <iostream>
#include <cmath>

int auton_color = 0; // 0 is red, 1 is blue, 2 is no color sorting.
bool intake_interrupt = false;
bool color_sort_override = false;

double wrapAngleDeg(double angle) {
    angle = fmod(angle + 180.0, 360.0);
    return (angle >= 0) ? angle - 180.0 : angle + 180.0;
}

double getDistance(double x1, double y1, double x2, double y2) {
    double a = (x1 - x2) * (x1 - x2);
    double b = (y1 - y2) * (y1 - y2);
    double dist = sqrt(a + b);

    return dist;
}

void turnToHeading(double heading, double turnSpeed) {
    double error = wrapAngleDeg(heading - inertial_sensor.heading());
    double previousTime = Brain.Timer.system();

    double timeout = ((std::abs(wrapAngleDeg(heading - inertial_sensor.heading())) * 2.43) + 450);

    bool notDone = true;
    PID turnPid = PID(0.59, 0.0001, 0.71, 0.5, 5, 100, &notDone, timeout, 230);//.61, 0, 1.05

    while (notDone) {
        error = wrapAngleDeg(heading - inertial_sensor.heading());

        double speed = turnPid.Update(error, (Brain.Timer.system() - previousTime));

        leftDrive.spin(forward, speed * (turnSpeed / 100), percent);
        rightDrive.spin(reverse, speed * (turnSpeed / 100), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

    }

    //std::cout << heading - inertial_sensor.heading() << std::endl;

    leftDrive.stop();
    rightDrive.stop();

}

void driveFor(double distance, double speed) {
    //std::cout << "-------------------" << std::endl;
    double targetHeading = inertial_sensor.heading();
    double encoderStart = forwardTrackingWheel.position(turns);


    bool driving = true;
    bool turning = true;

    int timeout = (std::abs(distance) / 12) * 260 + 450;

    PID drivePID = PID(5.3, 0.001, 0.70, 0.2, 10, speed, &driving, timeout, 100); // 3.5, 0, 1, 0.25
    PID turnPID = PID(0.5875, 0.0001, 0.705, 100, 3, speed, &turning, 9999999, 100);

    double driveError = distance;
    double turnError = wrapAngleDeg(targetHeading - inertial_sensor.heading());

    double previousTime = Brain.Timer.system();

    while (driving) {
        double encoderChange = forwardTrackingWheel.position(turns) - encoderStart;
        double inchesMoved = encoderChange * 1.75 * M_PI; // Circumference of Wheels

        driveError = distance - inchesMoved;

        turnError = wrapAngleDeg(targetHeading - inertial_sensor.heading());

        double dt = (Brain.Timer.system() - previousTime);

        double driveOutput = drivePID.Update(driveError, dt);
        double turnOutput = turnPID.Update(turnError, dt);

        leftDrive.spin(forward, (driveOutput + turnOutput), percent);
        rightDrive.spin(forward, (driveOutput - turnOutput), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

        //std::cout << "Error: " << driveError << std::endl;
    }

    leftDrive.stop();
    rightDrive.stop();
}

void pointAt(double x, double y, double turnSpeed, vex::directionType dir) {
    float targetOrientation = atan2(x - Position_Tracking.GlobalXPos, y - Position_Tracking.GlobalYPos);

    if (std::abs(wrapAngleDeg(targetOrientation * (180/M_PI) - inertial_sensor.heading())) <= 3) {
        return;
    }

    if (dir == forward) {
        turnToHeading(targetOrientation * (180/M_PI), turnSpeed);
    } else if (dir == reverse) {
        turnToHeading(targetOrientation * (180/M_PI) + 180, turnSpeed);
    }
}

void driveTo(double x, double y, double speed, vex::directionType dir) {
    pointAt(x, y, 100, dir);

    if (dir == forward) {
        double dist = getDistance(Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos, x, y);
        driveFor(dist, speed);
    }

    if (dir == reverse) {
        double dist = getDistance(Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos, x, y);
        driveFor(-dist, speed);
    }
}

void moveLiftToAngle(float targetAngle, bool pushing) {
    // PID for arm lift

    ringLiftArm.setStopping(hold);

    float currentArmAngle = lift_arm_potentiometer.angle(degrees);
    float goalArmAngle = targetAngle;
    float error = goalArmAngle - currentArmAngle;

    float startTime = Brain.Timer.system();
    float timeSinceStart = Brain.Timer.system() - startTime;

    if (pushing) {
        leftDrive.spin(forward, 6, percent);
        rightDrive.spin(forward, 6, percent);
    }

    while (std::abs(error) >= 1.0) {
        if (ringLiftArm.torque(Nm) >= 0.8) {
            break;
        }

        if (pushing) {
            float shakeVal = (Brain.Timer.system() / 200.00) * 3.14;
            float shake = sin(shakeVal) * 11;

            float driveVal = (Brain.Timer.system() / 400.00) * 3.14;
            float drive = sin(driveVal) * 6 + 3;

            leftDrive.spin(forward, drive + shake, percent);
            rightDrive.spin(forward, drive - shake, percent);
        }

        timeSinceStart = Brain.Timer.system() - startTime;

        if (timeSinceStart >= 1500) {
            ringLiftArm.stop();
            
            if (pushing) {
                leftDrive.stop();
                rightDrive.stop(); 
            }

            return;
        }
        
        std::cout << "Torque: "<< ringLiftArm.torque(Nm) << std::endl;

        currentArmAngle = lift_arm_potentiometer.angle(degrees);
        error = goalArmAngle - currentArmAngle;

        ringLiftArm.spin(reverse, error * 0.6, percent);
    }

    ringLiftArm.stop();
    
    if (pushing) {
        leftDrive.stop();
        rightDrive.stop();
    }
}

vex::task createRaiseArmTask(int targetAngle) {
    return vex::task([](void* param) -> int {
        int arg = *static_cast<int*>(param);
        moveLiftToAngle(arg, false); // Replace with your actual function
        delete static_cast<int*>(param); // Clean up allocated memory
        return 0;
    }, new int(targetAngle));
}

int previousSwitchState = 0;
int previousColor = 0;

int sortColorTask(void) {
    color_sensor.setLight(ledState::on);
    color_sensor.setLightPower(100, percent);

    int detectedColor = 2;
    int colorSortColor = 2;

    while (true) {
        if (color_sensor.isNearObject()) {
            if (color_sensor.color() == red) {
                detectedColor = 0;
            } else if (color_sensor.color() == blue) {
                detectedColor = 1;
            }
        } else {
            detectedColor = 2;
        }

        if (previousColor != detectedColor && detectedColor == 2) {
            colorSortColor = previousColor;
        }

        if (previousSwitchState == 0 && ring_switch.value() == 1) {
            if (colorSortColor != auton_color) {
                if (color_sort_override == false) {
                    //Controller.rumble("-");
                    intake_interrupt = true;
                    ringIntake2.stop();

                    wait(70, msec);

                    ringIntake2.spin(forward, 100, percent);
                    intake_interrupt = false;
                }
            }
        }
        
        previousSwitchState = ring_switch.value();
        previousColor = detectedColor;
        wait(10, msec);
    }
    return 1;
}
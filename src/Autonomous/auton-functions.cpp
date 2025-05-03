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

    double timeout = ((std::abs(wrapAngleDeg(heading - inertial_sensor.heading())) * 4.5) + 300);

    bool notDone = true;
    PID turnPid = PID(0.50, 0.0001, 0.4, 0.5, 5, 100, &notDone, timeout, 250);//0.59, 0.0001, 0.71

    while (notDone) {
        error = wrapAngleDeg(heading - inertial_sensor.heading());

        double speed = turnPid.Update(error, (Brain.Timer.system() - previousTime));

        //std::cout << error << std::endl;

        leftDrive.spin(forward, speed * (turnSpeed / 100), percent);
        rightDrive.spin(reverse, speed * (turnSpeed / 100), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

    }

    Controller.rumble(".");

    //std::cout << heading - inertial_sensor.heading() << std::endl;

    leftDrive.setStopping(brake);
    rightDrive.setStopping(brake);
    
    leftDrive.stop();
    rightDrive.stop();

    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);
}

void driveFor(double distance, double speed) {
    //std::cout << "-------------------" << std::endl;
    double targetHeading = inertial_sensor.heading();
    double encoderStart = forwardTrackingWheel.position(turns);


    bool driving = true;
    bool turning = true;

    int timeout = (std::abs(distance) / 12) * 300 + 300;

    PID drivePID = PID(4.0, 0.001, 0.65, 0.15, 10, speed, &driving, timeout, 300); // 3.5, 0, 1, 0.25
    PID turnPID = PID(0.525, 0.0005, 0.3, 100, 5, 100, &turning, 9999999, 300);

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

    //Controller.rumble("-");

    //std::cout << "Drive Error: " << driveError << std::endl;

    leftDrive.stop();
    rightDrive.stop();
}

void driveCurve(double distance, double speed, double curve) {
    //std::cout << "-------------------" << std::endl;
    double targetHeading = inertial_sensor.heading();
    double encoderStart = forwardTrackingWheel.position(turns);


    bool driving = true;
    bool turning = true;

    int timeout = (std::abs(distance) / 12) * 260 + 450;

    PID drivePID = PID(5.3, 0.001, 0.70, 0.15, 10, speed, &driving, timeout, 100); // 3.5, 0, 1, 0.25
    PID turnPID = PID(0.5875, 0.0001, 0.705, 100, 3, speed, &turning, 9999999, 100);

    double driveError = distance;
    double turnError = wrapAngleDeg(targetHeading - inertial_sensor.heading());

    double previousTime = Brain.Timer.system();

    double cumulativeCurve = 0;

    while (driving) {
        double encoderChange = forwardTrackingWheel.position(turns) - encoderStart;
        double inchesMoved = encoderChange * 1.75 * M_PI; // Circumference of Wheels

        driveError = distance - inchesMoved;

        turnError = wrapAngleDeg((targetHeading + cumulativeCurve) - inertial_sensor.heading());
        cumulativeCurve += curve;

        double dt = (Brain.Timer.system() - previousTime);

        double driveOutput = drivePID.Update(driveError, dt);
        double turnOutput = turnPID.Update(turnError, dt);

        leftDrive.spin(forward, (driveOutput + turnOutput), percent);
        rightDrive.spin(forward, (driveOutput - turnOutput), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

        //std::cout << "Error: " << driveError << std::endl;
    }

    //std::cout << "Drive Error: " << driveError << std::endl;

    leftDrive.stop();
    rightDrive.stop();
}

void curveToPoint(double x, double y, double speed, vex::directionType dir) {


    //std::cout << "-------------------" << std::endl;
    //double targetHeading = inertial_sensor.heading();
    //double encoderStart = forwardTrackingWheel.position(turns);
//
    //bool driving = true;
    //bool turning = true;
//
    //int timeout = (std::abs(36) / 12) * 260 + 450 + 2000;
//
    //PID drivePID = PID(5.3, 0.001, 0.70, 0.15, 10, speed, &driving, timeout, 100); // 3.5, 0, 1, 0.25
    //PID turnPID = PID(0.5875, 0.0001, 0.705, 100, 3, speed, &turning, timeout, 100);
//
    //double previousTime = Brain.Timer.system();
//
    //double num = pow((x - Position_Tracking.GlobalXPos), 2) + pow((y - Position_Tracking.GlobalYPos), 2);
    //double denom = 2 * (cos(inertial_sensor.heading() * M_PI / 180.0) * (y - Position_Tracking.GlobalYPos) - sin(inertial_sensor.heading() * M_PI / 180.0) * (x - Position_Tracking.GlobalXPos));
//
    //double R = num / denom;
    //double absR = std::abs(R);
//
    //double xc = Position_Tracking.GlobalXPos + R * sin(inertial_sensor.heading() * M_PI / 180.0);
    //double yc = Position_Tracking.GlobalYPos - R * cos(inertial_sensor.heading() * M_PI / 180.0);
//
    //double d = sqrt(pow((Position_Tracking.GlobalXPos - xc), 2)) + sqrt(pow((Position_Tracking.GlobalYPos - yc), 2));
//
    //double turnError = d - absR;
    //double driveError = sqrt(pow((x - Position_Tracking.GlobalXPos), 2)) + sqrt(pow((y - Position_Tracking.GlobalYPos), 2));

    // NOT DONE
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
    float previousWallstakeArmError = error;
    float derivative = error - previousWallstakeArmError;

    float kP = 0.7;
    float kD = 0.8;

    float startTime = Brain.Timer.system();
    float timeSinceStart = Brain.Timer.system() - startTime;

    while (std::abs(error) >= 1.5) {
        //if (ringLiftArm.torque(Nm) >= 0.8) {
        //    break;
        //}

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

        currentArmAngle = lift_arm_potentiometer.angle(degrees);
        error = goalArmAngle - currentArmAngle;

        //std::cout << Brain.Timer.system() << ", " << error << std::endl;

        ringLiftArm.spin(forward, error * kP + derivative * kD, percent);

        previousWallstakeArmError = error;
    }

    std::cout << "Done" << std::endl;

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

int previousColor = 0;
int detectedColor = 0;

int previousDistanceSensorState = 0;
int currentDistanceSensorState = 0;

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

        // Sets color we need to look out for

        if (previousColor != detectedColor && detectedColor == 2) {
            colorSortColor = previousColor;
        }

        //std::cout << colorToSort << std::endl;

        // Sets current distance sensor status

        if (distance_sensor.objectDistance(distanceUnits::mm) <= 40) {
            currentDistanceSensorState = 1;
        } else {
            currentDistanceSensorState = 0;
        }

        // Ejects ring if needed

        if (previousDistanceSensorState == 1 && currentDistanceSensorState == 0) { // When we stop sensing the ring (it's at the peak of travel)
            //std::cout << colorToSort << ", " << robot.Alliance_Color << std::endl;
            if (colorSortColor != auton_color && auton_color != 2) {
                // Ejection sequence
                if (color_sort_override == false) {
                    color_sort_override = true;

                    ringIntake.setStopping(brake);
                    ringIntake.stop();

                    std::cout << "Stop!" << std::endl;

                    Controller.rumble("-");

                    wait(250, msec);

                    color_sort_override = false;

                    ringIntake.setStopping(coast);
                    ringIntake.spin(forward, 100, percent);

                    std::cout << "Resume" << std::endl;
                }
            }
        }

        previousColor = detectedColor;
        previousDistanceSensorState = currentDistanceSensorState;
        wait(10, msec);
    }
    return 1;
}
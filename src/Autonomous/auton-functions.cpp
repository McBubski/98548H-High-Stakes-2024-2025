#include "Robot/PID.h"
#include "Autonomous/auton-functions.h"
#include "vex.h"

#include <iostream>
#include <cmath>

int auton_color = 0; // 0 is red, 1 is blue, 2 is no color sorting.

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
    double previousError = error;
    double previousTime = Brain.Timer.system();

    double timeout = ((std::abs(wrapAngleDeg(heading - inertial_sensor.heading())) * 2.45) + 400);

    bool notDone = true;
    PID turnPid = PID(0.59, 0.0001, 0.73, 0.5, 5, 100, &notDone, timeout, 700);//.61, 0, 1.05

    while (notDone) {
        error = wrapAngleDeg(heading - inertial_sensor.heading());

        double previousError = error;

        double speed = turnPid.Update(error, (Brain.Timer.system() - previousTime));

        leftDrive.spin(forward, speed * (turnSpeed / 100), percent);
        rightDrive.spin(reverse, speed * (turnSpeed / 100), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

        //std::cout << "Error: " << error << std::endl;
    }

    leftDrive.stop();
    rightDrive.stop();

}

void driveFor(double distance, double speed) {
    //std::cout << "-------------------" << std::endl;
    double targetHeading = inertial_sensor.heading();
    double encoderStart = forwardTrackingWheel.position(turns);


    bool driving = true;
    bool turning = true;

    int timeout = (std::abs(distance) / 12) * 260 + 550;

    PID drivePID = PID(4.48, 0.001, 0.24, 0.1, 10, speed, &driving, timeout, 100); // 3.5, 0, 1, 0.25
    PID turnPID = PID(0.62, 0, 1.1, 100, 3, speed, &turning, 9999999, 100);

    double driveError = distance;
    double turnError = wrapAngleDeg(targetHeading - inertial_sensor.heading());

    double previousTime = Brain.Timer.system();

    while (driving) {
        double encoderChange = forwardTrackingWheel.position(turns) - encoderStart;
        double inchesMoved = encoderChange * 2.75 * M_PI; // Circumference of Wheels

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
        Brain.Screen.printAt(50, 50, "%f", driveError);
    }

    leftDrive.stop();
    rightDrive.stop();
}

void pointAt(double x, double y, double turnSpeed, vex::directionType dir) {
    float targetOrientation = atan2(x - Position_Tracking.GlobalXPos, y - Position_Tracking.GlobalYPos);
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

        if (timeSinceStart >= 2000) {
            ringLiftArm.stop();
            leftDrive.stop();
            rightDrive.stop(); 

            return;
        }

        //std::cout << "Torque: "<< ringLiftArm.torque(Nm) << std::endl;

        currentArmAngle = lift_arm_potentiometer.angle(degrees);
        error = goalArmAngle - currentArmAngle;

        ringLiftArm.spin(reverse, error * 2.5, percent);
    }

    ringLiftArm.stop();
    leftDrive.stop();
    rightDrive.stop();
}

int sortColorTask(void) {
    color_sensor.setLight(ledState::on);
    color_sensor.setLightPower(25, percent);

    while (true) {
        if (auton_color == 0) { // Red
            if ((color_sensor.isNearObject() && color_sensor.color() == blue)) {
                ring_sorter.set(true);
                wait(350, msec);
            } else {
                ring_sorter.set(false);
            }
        } else if (auton_color == 1) { // Blue
             if ((color_sensor.isNearObject() && color_sensor.color() == red)) {
                ring_sorter.set(true);
                wait(350, msec);
            } else {
                ring_sorter.set(false);
            }
        }
        wait(20, msec);
    }
    return 1;
}
#include "Robot_Functions/PID.h"
#include "Autonomous/auton-functions.h"
#include "vex.h"

#include <iostream>
#include <cmath>

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

    double timeout = std::abs(wrapAngleDeg(heading - inertial_sensor.heading())) * 3 + 800;

    bool notDone = true;
    PID turnPid = PID(0.58, 0, 0.3, 1, 5, 100, &notDone, timeout, 800);//0.48, 0.0001, 2.75,

    while (notDone) {
        error = wrapAngleDeg(heading - inertial_sensor.heading());

        double previousError = error;

        double speed = turnPid.Update(error, (Brain.Timer.system() - previousTime));

        leftDrive.spin(forward, speed * (turnSpeed / 100), percent);
        rightDrive.spin(reverse, speed * (turnSpeed / 100), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

        Brain.Screen.printAt(50, 50, "%f", error);
        Brain.Screen.printAt(50, 100, "%f", inertial_sensor.heading());

        std::cout << "Error: " << error << std::endl;
    }

    leftDrive.stop();
    rightDrive.stop();
}

void driveFor(double distance, double speed) {
    std::cout << "-------------------" << std::endl;
    double targetHeading = inertial_sensor.heading();
    double encoderStart = forwardTrackingWheel.position(turns);


    bool driving = true;
    bool turning = true;

    int timeout = (std::abs(distance) / 12) * 250 + 550;

    PID drivePID = PID(3.5, 0, 1, 0.25, 10, speed, &driving, timeout, 100);
    PID turnPID = PID(0.58, 0, 0.3, 100, 3, speed, &turning, 9999999, 50);

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

        std::cout << "Error: " << driveError << std::endl;
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

void moveLiftByDegrees(float degrees) {
 
}
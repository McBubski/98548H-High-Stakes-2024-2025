#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

using namespace vex;

int auton_path = 1;

double startingPositions[3][3] = {
    {63.5, -63.5, 0}, // Left Side Auton
    {10, 10, 90}, // Right Side Auton
    {40, 40, 180} // Skills
};

void autonomous(void) {
    ringLift.setStopping(hold);
    ringIntake.spin(reverse, 100, percent);
    driveFor(20, 100);
    ringIntake.stop();
    turnToHeading(270, 100);
    driveFor(-4, 100);

    ringLift.spin(forward, 80, percent);
    wait(600, msec);
    ringLift.stop();

    driveFor(8, 100);

    ringLift.spin(reverse, 80, percent);
    wait(400, msec);
    ringLift.setStopping(coast);
    ringLift.stop();   

    driveFor(-16, 100); 

    turnToHeading(320, 100);
    driveFor(-38, 40);
    goal_clamp.set(true);
    turnToHeading(180, 100);

    ringIntake.spin(forward, 100, percent);
    driveFor(28, 100);
    wait(1500, msec);
    driveFor(-26, 100);
    turnToHeading(110, 100);
    driveFor(8, 100);

    ringIntake.stop();
    corner_arm.set(true);
    turnToHeading(45, 100); 

    //ringIntake.spin(forward, 100, percent);
    //wait(300, msec);
    //ringIntake.stop();
//
    //wait(300, msec);
    //driveFor(4, 100);
    //driveFor(-6, 100);
    //driveFor(6, 100);
    //turnToHeading(205, 100);
    //driveFor(-36, 30);
//
    //goal_clamp.set(true);
//
    //wait(300, msec);
//
    //turnToHeading(265, 100);
    //driveFor(-40, 100);
//
    //goal_clamp.set(false);
    //driveFor(48, 100);
}

void changeAuton(int direction) {
    auton_path += direction;

    if (auton_path < 1) {
        auton_path = 3;
    } else if (auton_path > 3) {
        auton_path = 1;
    }

    Position_Tracking.SetAuton(auton_path);
}
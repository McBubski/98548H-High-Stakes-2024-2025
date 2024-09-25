#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

using namespace vex;

int auton_path = 1;

int startingPositions[3][3] = {
    {0, 0, 45}, // Left Side Auton
    {10, 10, 90}, // Right Side Auton
    {40, 40, 180} // Skills
};

void autonomous(void) {
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
#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

#include "AutonPaths/skills.h"
#include "AutonPaths/blue.h"
#include "AutonPaths/red.h"

using namespace vex;

int auton_path = 5;

double startingPositions[6][3] = {
    {-56.5, -62.0, 270}, // Goal Rush Right
    {56.5, 16.5, 90}, // Goal Fill Right    //// NEW POSITION
    {56.5, -62.0, 90}, // Goal Rush Left
    {-56.5, 16.5, 270}, // Goal Fill Left
    {-60.75, 0, 90}, // Skills
    {61.25, 17, 180} // Failsafe Auton
};

void autonomous(void) {
    switch (auton_path) {
        case 1:
            Red_Right_Auton();
            break;
        case 2:
            Blue_Right_Auton();
            break;
        case 3:
            Blue_Left_Auton();
            break;
        case 4:
            Red_Left_Auton();
            break;
        case 5:
            Skills_Auton();
            break;
        case 6:
            Failsafe();
            break;
        default:
            Failsafe();
    }
    // OLD OLD

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
        auton_path = 6;
    } else if (auton_path > 6) {
        auton_path = 1;
    }

    Position_Tracking.SetAuton(auton_path);
}
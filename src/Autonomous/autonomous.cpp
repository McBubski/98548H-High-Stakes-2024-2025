#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

#include "AutonPaths/skills.h"
#include "AutonPaths/blue.h"
#include "AutonPaths/red.h"

using namespace vex;

int auton_path = 7;

double startingPositions[7][3] = {
    {-56.5, -62.0, 270}, // Goal Rush Right
    {56.5, 16.5, 90}, // Goal Fill Right    //// NEW POSITION
    {56.5, -62.0, 90}, // Goal Rush Left
    {-56.5, 16.5, 270}, // Goal Fill Left
    {-61, 0, 90}, // Skills
    {56.5, 16.5, 90}, // Win Point Blue
    {-56.5, 16.5, 270} // Win Point Red
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
            Blue_Win_Point();
            break;
        case 7:
            Red_Win_Point();
            break;
        default:
            Blue_Win_Point();
    }
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
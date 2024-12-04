#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

#include "AutonPaths/skills.h"
#include "AutonPaths/blue.h"
#include "AutonPaths/red.h"

using namespace vex;

int auton_path = 5;

double startingPositions[9][3] = {
    {-54.5, -40.0, 270}, // Goal Rush Right
    {50.5, 25.0, 57.3}, // Goal Fill Right    //// NEW POSITION
    {54.5, -40.0, 90}, // Goal Rush Left
    {-50.5, 25.0, 302.7}, // Goal Fill Left
    {-60.5, 0, 90}, // Skills
    {59, -40, 113}, // Win Point Blue
    {-59, -40, 247}, // Win Point Red
    {56.5, -16.5, 90}, // Elims Blue
    {-56.5, -16.5, 270} // Elims Red
};

void autonomous(void) {
    std::cout << "Auton: " << auton_path << std::endl;
    switch (auton_path) {
        case 1:
            auton_color = 0;
            Red_Right_Auton();
            break;
        case 2:
            auton_color = 1;
            Blue_Right_Auton();
            break;
        case 3:
            auton_color = 1;
            Blue_Left_Auton();
            break;
        case 4:
            auton_color = 0;
            Red_Left_Auton();
            break;
        case 5:
            auton_color = 0;
            Skills_Auton();
            break;
        case 6:
            auton_color = 1;
            Blue_Win_Point();
            break;
        case 7:
            auton_color = 0;
            Red_Win_Point();
            break;
        case 8:
            auton_color = 1;
            Blue_Elims();
            break;
        case 9:
            auton_color = 0;
            Red_Elims();
            break;
        default:
            auton_color = 1;
            Blue_Win_Point();
    }
}

void changeAuton(int direction) {
    auton_path += direction;

    if (auton_path < 1) {
        auton_path = 9;
    } else if (auton_path > 9) {
        auton_path = 1;
    }

    Position_Tracking.SetAuton(auton_path);
}
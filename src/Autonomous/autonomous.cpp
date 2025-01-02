#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

#include "AutonPaths/skills.h"
#include "AutonPaths/blue.h"
#include "AutonPaths/red.h"

using namespace vex;

int auton_path = 4;

double startingPositions[11][3] = {
    {-53, -29.3, 105}, // Goal Rush Right
    {60, 21, 144.7}, // Goal Fill Right    //// NEW POSITION
    {53, -29.3, 245}, // Goal Rush Left
    {-60, 21, 215.3}, // Goal Fill Left
    {-60.5, 0, 90}, // Skills
    {59, -40, 113}, // Win Point Blue
    {-59, -40, 247}, // Win Point Red
    {59, -40, 113}, // Elims Blue
    {-59, -40, 247}, // Elims Red
    {59, -40, 113}, // TOP SECRET!!!!! Blue
    {-59, -40, 247} // TOP SECRET!!!!! Red
};

void autonomous(void) {
    float startTime = Brain.Timer.systemHighResolution();

    switch (auton_path) {
        setColorSort();
        case 1:
            Goal_Rush_Right_Auton();
            break;
        case 2:
            Goal_Fill_Right_Auton();
            break;
        case 3:
            Goal_Rush_Left_Auton();
            break;
        case 4:
            Goal_Fill_Left_Auton();
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
        case 8:
            Blue_Elims();
            break;
        case 9:
            Red_Elims();
            break;
        case 10:
            Blue_Secret();
            break;
        case 11:
            Red_Secret();
            break;
        default:
            Blue_Win_Point();
    }

    float endTime = Brain.Timer.systemHighResolution();
    float totalTime = (endTime - startTime) / 1000000.0000;
    float timeLeft;

    if (auton_color == 5) { // Skills
        timeLeft = 60.0 - totalTime;
    } else {
        timeLeft = 15.0 - totalTime;
    }

    std::cout << "Auton Took: " << totalTime <<  "s | Time Remaining: " << timeLeft << "s" << std::endl;
}

void setColorSort() {
    switch (auton_path) {
        case 1:
            auton_color = 0;
            break;
        case 2:
            auton_color = 1;
            break;
        case 3:
            auton_color = 1;
            break;
        case 4:
            auton_color = 0;
            break;
        case 5:
            auton_color = 0;
            break;
        case 6:
            auton_color = 1;
            break;
        case 7:
            auton_color = 0;
            break;
        case 8:
            auton_color = 1;
            break;
        case 9:
            auton_color = 0;
            break;
        case 10:
            auton_color = 1;
            break;
        case 11:
            auton_color = 0;
            break;
        default:
            auton_color = 1;
    }
}

void changeAuton(int direction) {
    auton_path += direction;

    if (auton_path < 1) {
        auton_path = 11;
    } else if (auton_path > 11) {
        auton_path = 1;
    }

    setColorSort();
    Position_Tracking.SetAuton(auton_path);
}
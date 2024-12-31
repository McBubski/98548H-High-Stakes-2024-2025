#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

#include "AutonPaths/skills.h"
#include "AutonPaths/blue.h"
#include "AutonPaths/red.h"

using namespace vex;

int auton_path = 2;

double startingPositions[11][3] = {
    {-54.5, -40.0, 270}, // Goal Rush Right
    {60, 21, 144.7}, // Goal Fill Right    //// NEW POSITION
    {54.3, -29.0, 232}, // Goal Rush Left
    {-50.5, 49.0, 302.7}, // Goal Fill Left
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
        case 10:
            auton_color = 1;
            Blue_Secret();
            break;
        case 11:
            auton_color = 0;
            Red_Secret();
            break;
        default:
            auton_color = 1;
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

void changeAuton(int direction) {
    auton_path += direction;

    if (auton_path < 1) {
        auton_path = 11;
    } else if (auton_path > 11) {
        auton_path = 1;
    }

    Position_Tracking.SetAuton(auton_path);
}
#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

#include "AutonPaths/skills.h"
#include "AutonPaths/blue.h"
#include "AutonPaths/red.h"

using namespace vex;

int auton_path = 16;

double startingPositions[16][3] = {
    {-48.6, -36.0, 112}, // Goal Rush Right (1)
    {60, 21, 144.7}, // Goal Fill Right (2)
    {48.5, -58, 294}, // Goal Rush Left (3)
    {-60, 21, 215.3}, // Goal Fill Left (4)
    {-59.2, -14.4, 317.5}, // Skills (5)
    {59, -13, 34.7}, // Win Point Blue (6)
    {-59, -13, 325.3}, // Win Point Red (7)
    {60, 21, 144.7}, // Elims Blue (8)
    {-60, 21, 215.3}, // Elims Red (9)
    {60, 21, 144.7}, // Sig Point Blue (10)
    {-60, 21, 215.3}, // Sig Point Red (11)
    {-60.5, -6, 287.6}, // New Skills (12)
    {-48.6, -36.0, 112}, // Positive Elims Red
    {48.5, -58, 294}, //  Positive Elims Blue
    {-54, -40, 117.3}, // Corner Clear New Red
    {54, -40, 117.3} //  Corner Clear New Blue Blue
};

void autonomous(void) {
    float startTime = Brain.Timer.systemHighResolution();   

    switch (auton_path) {
        case 1:
            setColorSort();
            Goal_Rush_Right_Auton();
            break;
        case 2:
            setColorSort();
            Goal_Fill_Right_Auton();
            break;
        case 3:
            setColorSort();
            Goal_Rush_Left_Auton();
            break;
        case 4:
            setColorSort();
            Goal_Fill_Left_Auton();
            break;
        case 5:
            setColorSort();
            Skills_Auton();
            break;
        case 6:
            setColorSort();
            Blue_Win_Point();
            break;
        case 7:
            setColorSort();
            Red_Win_Point();
            break;
        case 8:
            setColorSort();
            Blue_Elims();
            break;
        case 9:
            setColorSort();
            Red_Elims();
            break;
        case 10:
            setColorSort();
            Blue_Sig_Point();
            break;
        case 11:
            setColorSort();
            Red_Sig_Point();
            break;
        case 12:
            setColorSort();
            New_Skills_Auton();
            break;
        case 13:
            setColorSort();
            Positive_Elims_Red();
            break;
        case 14:
            setColorSort();
            Positive_Elims_Blue();
            break;
        case 15:
            setColorSort();
            Corner_Clear_Red();
            break;
        case 16:
            setColorSort();
            Corner_Clear_Blue();
            break;
        default:
            setColorSort();
            Blue_Win_Point();
            break;
    }

    float endTime = Brain.Timer.systemHighResolution();
    float totalTime = (endTime - startTime) / 1000000.0000;
    float timeLeft;

    if (auton_path == 5 || auton_path == 12) { // Skills
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
        case 12:
            auton_color = 0;
            break;
        case 13:
            auton_color = 0;
            break;
        case 14:
            auton_color = 1;
            break;
        case 15:
            auton_color = 0;
            break;
        case 16:
            auton_color = 1;
            break;
        default:
            auton_color = 1;
    }
}

void changeAuton(int direction) {
    auton_path += direction;

    if (auton_path < 1) {
        auton_path = 16;
    } else if (auton_path > 16) {
        auton_path = 1;
    }

    setColorSort();
    Position_Tracking.SetAuton(auton_path);
}
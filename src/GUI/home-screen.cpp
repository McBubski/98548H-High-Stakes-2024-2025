#include "GUI/home-screen.h"
#include "GUI/gui-main.h"

#include "Graphics/text.h"
#include "Graphics/button.h"

#include "Autonomous/autonomous.h"
#include <cmath>

bool screenDebounce = false;

// Calibrate Button
Button CalibrateButton = Button(125, 190, 230, 40, "Calibrate", "#2ec943", CalibrateInertial); // Shamrock-ish Green\\

// Window Buttons

Button OdometryWindowButton = Button(10, 190, 100, 40, "Odometry", "#498afc", SwitchToOdometryWindow);
Button SystemWindowButton = Button(370, 190, 100, 40, "System", "#f09521", SwitchToSystemWindow);

// Auton Buttons

Button SwitchAutonLeftButton = Button(10, 60, 100, 50, "<", "#f04221", SwitchAutonLeft);
Button SwitchAutonRightButton = Button(10, 125, 100, 50, ">", "#f04221", SwitchAutonRight);

// Main Loop

// Auton

const char* auton = "Left Side Auton";


void drawHomeScreen(void) {
    // Draw Team Number
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(black);

    drawText("98548H | Revamped", 230 - Brain.Screen.getStringWidth("98548H | Revamped") / 2, 25, mono20);

    ShowBatteryLevel();

    // Draw Heading
    Brain.Screen.setPenColor(white);
    drawText("Heading: ", 480 - Brain.Screen.getStringWidth("Heading: "), 25, mono20);
    Brain.Screen.printAt(400, 45, "%.1f°", inertial_sensor.heading(degrees));

    Brain.Screen.printAt(10, 25, "X: %.2f", Position_Tracking.GlobalXPos);
    Brain.Screen.printAt(10, 45, "Y: %.2f", Position_Tracking.GlobalYPos);
    
    // Auton Info

    Brain.Screen.setFont(mono40);
    Brain.Screen.printAt(240 - Brain.Screen.getStringWidth(auton) / 2 + 50, 120, auton);

    Brain.Screen.setFont(mono20);
    Brain.Screen.setPenWidth(2);

    // Show Progression

    Brain.Screen.printAt(260, 150, "(%d/14)", auton_path);

    // Display Buttons

    ShowCalibrateButton();
    UpdateAutonInformation();

    OdometryWindowButton.display();
    SystemWindowButton.display();

    SwitchAutonLeftButton.display();
    SwitchAutonRightButton.display();

    // Check Press
    checkButtonPresses();
}


//////   DISPLAYS BUTTONS


// Calibrate Button

void ShowCalibrateButton(void) {
    // Calibrate Button

    if (inertial_sensor.installed()) {
        if (!inertial_sensor.isCalibrating()) {
            CalibrateButton.text = "Calibrate";
            CalibrateButton.backgroud_color = "#2ec943";
        } else {
            CalibrateButton.text = "Calibrating...";
            CalibrateButton.backgroud_color = "#fcdc26";
        }
    } else {
        CalibrateButton.text = "(!) Inertial Not Found";
        CalibrateButton.backgroud_color = "#dc2f0a";
    }

    CalibrateButton.display();
}

void ShowBatteryLevel(void) {
    int batteryLevel = Brain.Battery.capacity(percent);

    if (batteryLevel >= 60) {
        Brain.Screen.setPenColor(green);
    } else if (batteryLevel < 60 && batteryLevel >= 25) {
        Brain.Screen.setPenColor(yellow);
    } else if (batteryLevel < 25) {
        Brain.Screen.setPenColor(red);
    }

   Brain.Screen.printAt(205, 45, "%d%s", batteryLevel, "%");
}

void UpdateAutonInformation(void) {
    switch (auton_path) {
        case 1:
            auton = "Goal Rush Right";
            break;
        case 2:
            auton = "Goal Fill Right";
            break;
        case 3:
            auton = "Goal Rush Left";
            break;
        case 4:
            auton = "Goal Fill Left";
            break;
        case 5:
            auton = "Skills";
            break;
        case 6:
            auton = "Blue Solo WP";
            break;
        case 7:
            auton = "Red Solo WP";
            break;
        case 8:
            auton = "Elims Blue";
            break;
        case 9:
            auton = "Elims Red";
            break;
        case 10:
            auton = "Sigpoint Blue";
            break;
        case 11:
            auton = "Sigpoint Red";
            break;
        case 12:
            auton = "New Skills";
            break;
        case 13:
            auton = "Pos. Elims Red";
            break;
        case 14:
            auton = "Pos. Elims Blue";
            break;
        default:
            auton = "Blue Auton";
    }
}


//////   BUTTON FUNCTIONS


void CalibrateInertial(void) {
    if (!inertial_sensor.isCalibrating()) {
        inertial_sensor.calibrate();
    }

    Position_Tracking.SetAuton(auton_path);
}

// Switches screen to odometry window

void SwitchToOdometryWindow(void) {
    window = "Odometry";
}
void SwitchToSystemWindow(void) {
    window = "System";
}

// Auton Buttons

void SwitchAutonLeft(void) {
    changeAuton(-1);
}
void SwitchAutonRight(void) {
    changeAuton(1);
}

// Checks for button presses

void checkButtonPresses(void) {
    if (Brain.Screen.pressing()) {
        if (screenDebounce == false) {
            screenDebounce = true;

            int x = Brain.Screen.xPosition();
            int y = Brain.Screen.yPosition(); 

            CalibrateButton.checkPress(x, y);
            OdometryWindowButton.checkPress(x, y);
            SystemWindowButton.checkPress(x, y);

            SwitchAutonLeftButton.checkPress(x, y);
            SwitchAutonRightButton.checkPress(x, y);
        }
    } else {
        screenDebounce = false;
    }
}
#include "Screens/odometry-screen.h"
#include "GUI/gui-main.h"

#include "Graphics/text.h"
#include "Graphics/button.h"

bool screenDebounce_ = false;

float robotSize = 20;

// Calibrate Button
Button ReturnButton = Button(240, 10, 230, 40, "Return", "#ff1100", ReturnToMainScreen);

void drawOdometryScreen(void) {
    // Draws Field
    Brain.Screen.drawImageFromFile("HighStakesField.png", 10, 10);

    drawRobotGraphic();

    // Draw Button
    ReturnButton.display();

    checkButtonPresses_();
}

void drawRobotGraphic(void) {
 
}

void ReturnToMainScreen(void) {
    window = "Main";
}

void checkButtonPresses_(void) {
    if (Brain.Screen.pressing()) {
        if (screenDebounce_ == false) {
            screenDebounce_ = true;

            int x = Brain.Screen.xPosition();
            int y = Brain.Screen.yPosition(); 

            ReturnButton.checkPress(x, y);
        }
    } else {
        screenDebounce_ = false;
    }
}
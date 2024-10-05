#include "GUI/odometry-screen.h"
#include "GUI/gui-main.h"

#include "Graphics/text.h"
#include "Graphics/button.h"

bool screenDebounce_ = false;

float robotSize = 11;

// Calibrate Button
Button ReturnButton = Button(240, 10, 230, 40, "Return", "#ff1100", ReturnToMainScreen);

void drawOdometryScreen(void) {
    // Draws Field
    Brain.Screen.drawImageFromFile("HighStakesField.png", 10, 10);

    drawRobotGraphic();

    // Displays robot info

    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(black);

    drawText("Heading: ", 480 - Brain.Screen.getStringWidth("Heading: "), 75, mono20);
    Brain.Screen.printAt(400, 95, "%.1f°", inertial_sensor.heading(degrees));

    Brain.Screen.printAt(240, 75, "X: %.2f", Position_Tracking.GlobalXPos);
    Brain.Screen.printAt(240, 95, "Y: %.2f", Position_Tracking.GlobalYPos);

    // Draw Button
    Brain.Screen.setPenWidth(2);
    ReturnButton.display();

    checkButtonPresses_();
}

void drawRobotGraphic(void) {
    // Calculates where robot should be drawn
    float pixelsPerInch = (110.0 / 72.0);
    float XOnBrainScreen = 120 + (pixelsPerInch * Position_Tracking.GlobalXPos);
    float YOnbrainScreen = 120 + (-pixelsPerInch * Position_Tracking.GlobalYPos);

    // Calculates line offsets for drawing border
    float headingInRadians = (inertial_sensor.angle(degrees) * M_PI / 180.0);

    float lineOffset1 = sqrt(2) * robotSize * cos(-headingInRadians + M_PI_4);
    float lineOffset2 = sqrt(2) * robotSize * cos(-headingInRadians - M_PI_4);

    float headingX = sin(headingInRadians);
    float headingY = cos(headingInRadians);

    // Fills in robot first
    Brain.Screen.setPenColor(cyan);
    Brain.Screen.setPenWidth(robotSize * 2);
    
    Brain.Screen.drawLine(
        XOnBrainScreen - headingX * robotSize, 
        YOnbrainScreen + headingY * robotSize, 
        XOnBrainScreen + headingX * robotSize, 
        YOnbrainScreen - headingY * robotSize
    );

    // Draws border around robot
    Brain.Screen.setPenColor(black);
    Brain.Screen.setPenWidth(4);

    Brain.Screen.drawLine(XOnBrainScreen + lineOffset1, YOnbrainScreen - lineOffset2, XOnBrainScreen + lineOffset2, YOnbrainScreen + lineOffset1);
    Brain.Screen.drawLine(XOnBrainScreen + lineOffset2, YOnbrainScreen + lineOffset1, XOnBrainScreen - lineOffset1, YOnbrainScreen + lineOffset2);
    Brain.Screen.drawLine(XOnBrainScreen - lineOffset1, YOnbrainScreen + lineOffset2, XOnBrainScreen - lineOffset2, YOnbrainScreen - lineOffset1);
    Brain.Screen.drawLine(XOnBrainScreen - lineOffset2, YOnbrainScreen - lineOffset1, XOnBrainScreen + lineOffset1, YOnbrainScreen - lineOffset2);

    // Draws heading indication arrow
    Brain.Screen.setPenColor(red);
    Brain.Screen.setPenWidth(4);
    
    Brain.Screen.drawLine(XOnBrainScreen, YOnbrainScreen, XOnBrainScreen + headingX * 20, YOnbrainScreen - headingY * 20);
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
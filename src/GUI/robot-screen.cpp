#include "GUI/robot-screen.h"
#include "GUI/gui-main.h"

#include "Graphics/text.h"
#include "Graphics/button.h"

bool screenDebounce_ScreenMenu = false;

// Calibrate Button
Button ReturnButton_ScreenMenu= Button(10, 190, 100, 40, "Return", "#ff1100", ReturnToMainScreen_ScreenMenu);

void drawRobotScreen(void) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFont(mono20);

    // MicroSD Card

    Brain.Screen.printAt(10, 30, "MicroSD Card: ");

    if (Brain.SDcard.isInserted()) {
        Brain.Screen.setPenColor(green);
        Brain.Screen.printAt(20, 50, "Installed");
    } else {
        Brain.Screen.setPenColor(red);
        Brain.Screen.printAt(20, 50, "Not Found");
    }

    // Color sort

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(330, 30, "Color Sensor: ");    

    color col = color_sensor.color();

    if (col == red && color_sensor.isNearObject()) {
        Brain.Screen.setPenColor(red);
        Brain.Screen.printAt(340, 50, "Red");
    } else if (col == blue && color_sensor.isNearObject()) {
        Brain.Screen.setPenColor(blue);
        Brain.Screen.printAt(340, 50, "Blue");
    } else {
        Brain.Screen.setPenColor("#666666");
        Brain.Screen.printAt(340, 50, "No Ring");
    }

    // Tracking Wheels

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(170, 30, "Odom Wheels: ");   

    if (forwardTrackingWheel.installed() && sidewaysTrackingWheel.installed()) {
        Brain.Screen.setPenColor(green);
        Brain.Screen.printAt(180, 50, "Installed");
    } else {
        Brain.Screen.setPenColor(red);
        Brain.Screen.printAt(180, 50, "Error (!)");
    }

    // Battery

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(10, 90, "Battery: ");

    int batteryLevel = Brain.Battery.capacity(percent);

    if (batteryLevel >= 60) {
        Brain.Screen.setPenColor(green);
    } else if (batteryLevel < 60 && batteryLevel >= 25) {
        Brain.Screen.setPenColor(yellow);
    } else if (batteryLevel < 25) {
        Brain.Screen.setPenColor(red);
    }

    Brain.Screen.printAt(20, 110, "%d%c", batteryLevel, '%');
    Brain.Screen.setPenColor(white);

    // Arm angle

    Brain.Screen.printAt(10, 150, "Arm Angle: ");
    Brain.Screen.setPenColor(cyan);
    Brain.Screen.printAt(20, 170, "%.1f", lift_arm_potentiometer.angle(degrees));

    // Motor Temp

    displayMotorTemperature();

    // Draw Button
    Brain.Screen.setPenWidth(2);
    ReturnButton_ScreenMenu.display();

    checkButtonPresses_ScreenMenu();
}

void displayMotorTemperature() {
    
    // FL

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(170, 90, "FL Motor: ");

    Brain.Screen.setPenColor(orange);
    Brain.Screen.printAt(180, 110, "%.f%c Heat", motorML.temperature(percent), '%');

    // ML

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(170, 150, "BL Motor: ");

    Brain.Screen.setPenColor(orange);
    Brain.Screen.printAt(180, 170, "%.f%c Heat", motorBL.temperature(percent), '%');

    // TL

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(170, 210, "TL Motor: ");

    Brain.Screen.setPenColor(orange);
    Brain.Screen.printAt(180, 230, "%.f%c Heat", motorTL.temperature(percent), '%');



    // FR

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(330, 90, "FR Motor: ");

    Brain.Screen.setPenColor(orange);
    Brain.Screen.printAt(340, 110, "%.f%c Heat", motorMR.temperature(percent), '%');

    // MR

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(330, 150, "BR Motor: ");

    Brain.Screen.setPenColor(orange);
    Brain.Screen.printAt(340, 170, "%.f%c Heat", motorBR.temperature(percent), '%');

    // TR

    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(330, 210, "TR Motor: ");

    Brain.Screen.setPenColor(orange);
    Brain.Screen.printAt(340, 230, "%.f%c Heat", motorTR.temperature(percent), '%');
}

void ReturnToMainScreen_ScreenMenu(void) {
    window = "Main";
}

void checkButtonPresses_ScreenMenu(void) {
    if (Brain.Screen.pressing()) {
        if (screenDebounce_ScreenMenu == false) {
            screenDebounce_ScreenMenu = true;

            int x = Brain.Screen.xPosition();
            int y = Brain.Screen.yPosition(); 

            ReturnButton_ScreenMenu.checkPress(x, y);
        }
    } else {
        screenDebounce_ScreenMenu = false;
    }
}
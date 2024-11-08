#include "GUI/gui-main.h"
#include "Graphics/text.h"

#include "GUI/home-screen.h"
#include "GUI/odometry-screen.h"

#include "Autonomous/auton-functions.h"

#include <iostream>
#include <string.h>

using namespace vex;

const char* window = "Main";

int drawScreen(void) {
    Brain.Screen.render();

    while (true) {
        if (strncmp(window, "Main", 2) == 0) {
            drawHomeScreen();
        } else if (strncmp(window, "Odometry", 2) == 0) {
            drawOdometryScreen();
        } else if (strncmp(window, "System", 2)) {
           
        }

        // Renders then clears screen

        Controller.Screen.setCursor(1, 1);
        Controller.Screen.print("%.2f", inertial_sensor.heading(degrees));
        Controller.Screen.setCursor(1, 15);

        if (auton_color == 0) {
            Controller.Screen.print("CS: RED");
        } else if (auton_color == 1) {
            Controller.Screen.print("CS: BLU");
        } 


        // Testing color sensor

        //Brain.Screen.printAt(50, 50, "%f %d", color_sensor.hue(), color_sensor.isNearObject());


        Brain.Screen.render();

        wait(100, msec);

        Controller.Screen.clearLine();

        Brain.Screen.clearScreen();
    }

    return 1;
}
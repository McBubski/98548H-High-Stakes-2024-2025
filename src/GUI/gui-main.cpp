#include "GUI/gui-main.h"
#include "Graphics/text.h"

#include "Screens/home-screen.h"
#include "Screens/odometry-screen.h"

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
        }

        // Renders then clears screen

        Brain.Screen.render();

        wait(100, msec);

        Brain.Screen.clearScreen();
    }

    return 1;
}
#include "GUI/gui-main.h"
#include "Graphics/text.h"

#include "Screens/home-screen.h"

#include <iostream>

using namespace vex;

int drawScreen(void) {
    Brain.Screen.render();

    while (true) {
        drawHomeScreen();

        // Renders then clears screen

        Brain.Screen.render();

        wait(20, msec);

        Brain.Screen.clearScreen();
    }

    return 1;
}
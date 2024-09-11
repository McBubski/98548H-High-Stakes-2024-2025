#include "GUI/Screens/home-screen.h"
#include "GUI/text.h"
#include <iostream>


void drawHomeScreen(void) {
    // Draw Team Number
    Brain.Screen.setPenColor(white);

    int centerOffset = getCenterOffset("98548H | REVAMPED");
    Brain.Screen.drawRectangle(235 - centerOffset, 10, centerOffset * 2 + 10, 30);
    drawText("98548H | REVAMPED", 240 - centerOffset, 30, mono20);

    // Draw Heading
    drawText("Heading: ", 480 - Brain.Screen.getStringWidth("Heading: "), 20, mono20);
    //drawText("120.0°", 480 - Brain.Screen.getStringWidth("120.0°") * 1.25, 40, mono20);
    Brain.Screen.printAt(400, 40, "%.1f°", inertial_sensor.heading(degrees));

    // Draw Coordinates
    //drawText(" X: 12.03", 0, 20, mono20);
    //drawText(" Y: -5.65", 0, 40, mono20);

    Brain.Screen.printAt(0, 20, "X: %.2f", Position_Tracking.GlobalXPos);
    Brain.Screen.printAt(0, 40, "Y: %.2f", Position_Tracking.GlobalYPos);
}
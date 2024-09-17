#include "Graphics/text.h"

using namespace vex;

void drawText(const char* text, int x, int y, fontType font) {
    Brain.Screen.setFont(font);
    Brain.Screen.printAt(x, y, text);
}

int getCenterOffset(const char* text) {
    return Brain.Screen.getStringWidth(text) / 2;
}
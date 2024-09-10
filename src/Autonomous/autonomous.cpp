#include "Autonomous/autonomous.h"

using namespace vex;

void autonomous(void) {
    lift.spin(forward, 100, percent);
    wait(10, sec);
    lift.stop();
}
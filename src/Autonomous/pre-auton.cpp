#include "Autonomous/pre-auton.h"

using namespace vex;

void pre_auton(void) {
    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);

    lift.setStopping(brake);

    wait(100, msec);

    // Zero out sensors

    forwardTrackingWheel.resetPosition();
    sidewaysTrackingWheel.resetPosition();
}
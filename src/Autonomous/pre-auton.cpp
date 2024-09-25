#include "Autonomous/pre-auton.h"
#include "Autonomous/autonomous.h"

using namespace vex;

void pre_auton(void) {
    Position_Tracking.SetAuton(auton_path);
    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);

    lift.setStopping(brake);

    wait(100, msec);

    // Zero out sensors

    forwardTrackingWheel.resetPosition();
    sidewaysTrackingWheel.resetPosition();
}
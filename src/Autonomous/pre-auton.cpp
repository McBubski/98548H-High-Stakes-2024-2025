#include "Autonomous/pre-auton.h"
#include "Autonomous/autonomous.h"

using namespace vex;

void pre_auton(void) {
    Position_Tracking.SetAuton(auton_path);
    setColorSort();
    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);

    wait(100, msec);

    // Zero out sensors

    forwardTrackingWheel.resetPosition();
    sidewaysTrackingWheel.resetPosition();

    // Sensors
    color_sensor.setLight(ledState::on);
    color_sensor.setLightPower(100, percent);

    ai_sensor.modelDetection(true);
}
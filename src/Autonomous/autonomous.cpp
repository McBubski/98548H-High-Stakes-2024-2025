#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"

using namespace vex;

void autonomous(void) {
    ringIntake.spin(forward, 100, percent);
    wait(300, msec);
    ringIntake.stop();

    wait(300, msec);
    driveFor(4, 100);
    driveFor(-6, 100);
    driveFor(6, 100);
    turnToHeading(205, 100);
    driveFor(-36, 30);

    goal_clamp.set(true);

    wait(300, msec);

    turnToHeading(265, 100);
    driveFor(-40, 100);

    goal_clamp.set(false);
    driveFor(48, 100);
}
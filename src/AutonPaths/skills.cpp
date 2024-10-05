#include "AutonPaths/skills.h"
#include "Autonomous/auton-functions.h"

void Skills_Auton(void) {
    // SKILLS

    // Spin first ring onto alliance stake
    ringIntake.spin(forward, 100, percent);
    wait(400, msec);
    ringIntake.stop();

    ringLift.spinFor(150, degrees, true);
    ringLift.spinFor(-150, degrees, true);
//
    // Get first goal
    driveFor(16, 100);
    driveTo(-48, 28, 40, reverse);
    goal_clamp.set(true);

    // Gets rings

    // Ring 1
    ringIntake.spin(forward, 80, percent);
    turnToHeading(90, 100);
    driveFor(24, 100);

    // Ring 2

    driveTo(-26, 58, 100, forward);

    // Ring 3

    driveTo(-46, 59, 100, forward);
    driveFor(-8, 100);

    // Ring 4

    driveTo(-48, 48, 100, forward);

    // Ring 5

    driveTo(-58, 46, 100, forward);
    wait(400, msec);

    // Drop off goal

    driveTo(-62, 56, 100, reverse);
    goal_clamp.set(false);
    ringIntake.stop();

    // Get second goal

    driveTo(-48, 24, 100, forward);
    driveTo(-48, -50, 35, reverse);
    goal_clamp.set(true);
    
    // Ring 1

    ringIntake.spin(forward, 75, percent);
    driveTo(-20, -16, 100, forward);

    // Ring 2

    driveTo(-26, -54, 100, forward);

    // Ring 3

    driveTo(-48, -58, 100, forward);
    driveFor(-12, 100);

    // Ring 4

    driveTo(-48, -44, 100, forward);
//
    //// Ring 5
//
    driveTo(-60, -46, 100, forward);
    wait(300, msec);
//
    //// Drop off goal
//
    driveTo(-64, -58, 100, reverse);
    ringIntake.spin(reverse, 100, percent);
    wait(100, msec);
    ringIntake.stop();

    goal_clamp.set(false);
    ringIntake.stop();
//
    driveFor(22, 100);

    // Elevate

    while (lift_potentiometer.angle(degrees) >= 198.0) {
        ringLift.spin(forward, 50, percent);
        wait(20, msec);
    }
    ringLift.setStopping(hold);
    ringLift.stop();

    driveTo(0, 0, 100, forward);
    ringLift.spinFor(-200, degrees);
}
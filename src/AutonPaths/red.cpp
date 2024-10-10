#include "AutonPaths/red.h"
#include "Autonomous/auton-functions.h"

void Red_Left_Auton(void) {
    // Raise Arm
    ringLift.spinFor(forward, 150, degrees, false);

    // Get first goal

    driveFor(-18, 100);
    ringLift.spinFor(reverse, 150, degrees, false);
    turnToHeading(240, 100);
    driveFor(-10, 20);
    goal_clamp.set(true);

    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(300, msec);

    // Grab second ring

    driveTo(-28, 48, 100, forward);
    wait(300, msec);
    driveFor(-8, 100);

    // Grab third ring

    driveTo(-14, 44, 60, forward);
//
    //// Grab to last ring 
    //
    driveTo(-10, 47, 60, forward);
//
    //// Touch bar
//
    driveTo(-24, 22, 40, reverse);
    turnToHeading(90, 100);
    corner_arm.set(true);
    driveFor(2.5, 100);
    turnToHeading(60, 100);
}

void Red_Right_Auton(void) {
    // Rush goal
    //ringLift.spinFor(forward, 150, degrees, false);
    driveFor(-36, 100);
    //ringLift.spinFor(reverse, 150, degrees, false);
    driveTo(-10.5, -53.5, 30, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(400, msec);

    // Second ring

    driveTo(-30, -54, 100, forward);
    ringIntake.stop();
    turnToHeading(0, 100);
    goal_clamp.set(false);

    // Get second goal

    turnToHeading(180, 100);
    driveFor(-18, 40);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    wait(500, msec);

    // Touch bar

    driveFor(-4, 100);
    turnToHeading(90, 100);
    driveFor(10, 100);
    corner_arm.set(true);
    turnToHeading(20, 50);
}
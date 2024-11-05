#include "AutonPaths/red.h"
#include "Autonomous/auton-functions.h"

void Red_Left_Auton(void) {
    // Raise Arm
    ringLift.spinFor(forward, 150, degrees, false);

    // Get first goal

    driveFor(-18, 100);
    ringLift.spinFor(reverse, 150, degrees, false);
    turnToHeading(243, 100);
    driveFor(-10, 20);
    goal_clamp.set(true);

    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(300, msec);

    // Grab second ring

    driveTo(-28, 48, 60, forward);
    wait(300, msec);
    driveFor(-8, 100);

    // Grab third ring

    driveTo(-13.5, 45, 60, forward);
    wait(500, msec);

    // Grab to last ring 
    
    driveTo(-8.5, 52, 60, forward);
    wait(500, msec);

//
    //// Touch bar
//
    driveTo(-24, 22, 40, reverse);
    turnToHeading(135, 100);
    driveFor(4, 100);
    moveLiftToAngle(100, false);
}

void Red_Right_Auton(void) {
    // Rush goal
    driveFor(-36, 100);
    driveTo(-7, -53, 30, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(800, msec);

    // Second ring

    driveTo(-26, -50, 100, forward);
    ringIntake.stop();
    turnToHeading(0, 100);
    goal_clamp.set(false);

    // Get second goal

    driveTo(-22, -30, 40, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    wait(500, msec);

    // Touch bar

    turnToHeading(45, 100);
    driveFor(7, 100);
    moveLiftToAngle(90, false);

    //driveFor(-5, 100);
    //turnToHeading(65, 100);
    //driveFor(14, 100);
    //corner_arm.set(true);
    //turnToHeading(110, 50);
}

void Red_Win_Point(void) {
    driveTo(-54, 0.2, 100, reverse);
    turnToHeading(90, 100);
    driveFor(-11.5, 100);

    ringIntake.spin(forward, 100, percent);
    wait(500, msec);
    ringIntake.stop();

    driveFor(12, 100);

    driveTo(-19.5, 26, 40, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    driveTo(-9.5, 41, 80, forward);
    wait(1000, msec);
    driveFor(-16, 100);
    driveTo(-21, 48, 100, forward);
    driveTo(-17, 15.5, 100, forward);

    turnToHeading(135, 100);
    driveFor(2, 100);
    moveLiftToAngle(100, false);
}
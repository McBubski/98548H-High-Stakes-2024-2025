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

    // Grab third ring

    driveTo(-12.5, 42, 60, forward);
    wait(500, msec);

    // Grab to last ring 
    
    driveTo(-8, 52, 60, forward);
    wait(500, msec);

    // Grab second ring

    driveTo(-30, 46, 60, forward);
    wait(300, msec);


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
    driveTo(-9, -54, 30, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(400, msec);

    // Second ring

    driveTo(-26, -50, 100, forward);
    ringIntake.stop();
    ringIntake2.spin(forward, 100, percent);
    turnToHeading(0, 100);
    goal_clamp.set(false);

    // Get second goal

    pointAt(-24, -30, 100, reverse);
    driveFor(-24.5, 40);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    wait(500, msec);

    // Touch bar

    turnToHeading(45, 100);
    driveFor(2, 100);
    moveLiftToAngle(90, false);

    //driveFor(-5, 100);
    //turnToHeading(65, 100);
    //driveFor(14, 100);
    //corner_arm.set(true);
    //turnToHeading(110, 50);
}

void Red_Win_Point(void) {
        // Get first goal

    driveFor(-18, 100);
    ringLift.spinFor(reverse, 150, degrees, false);
    turnToHeading(300, 100);
    driveFor(-14, 20);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Second goal

    driveTo(-51, -24, 100, forward);
    driveTo(-51, 32, 40, forward);
    
    ringIntake.stop();
    ringIntake1.spin(forward, 100, percent);
    //wait(1300, msec);
    driveFor(-6, 100);
    goal_clamp.set(false);

    pointAt(-20, 22, 100, reverse);
    driveTo(-18, 22, 35, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Get next ring
    driveTo(-26, 44, 90, forward);
    driveFor(-20, 100);

    // Touch bar

    moveLiftToAngle(100, false);
    driveTo(-14, 14, 100, forward);
    //driveTo(-54, 0.2, 100, reverse);
    //turnToHeading(90, 100);
    //driveFor(-11.5, 100);
//
    //ringIntake.spin(forward, 100, percent);
    //wait(500, msec);
    //ringIntake.stop();
//
    //driveFor(12, 100);
//
    //driveTo(-19.5, 26, 40, reverse);
    //goal_clamp.set(true);
//
    //ringIntake.spin(forward, 100, percent);
    //driveTo(-9.5, 41, 80, forward);
    //wait(1000, msec);
    //driveFor(-16, 100);
    //driveTo(-21, 48, 100, forward);
    //driveTo(-17, 15.5, 100, forward);
//
    //turnToHeading(135, 100);
    //driveFor(2, 100);
    //moveLiftToAngle(100, false);
}

void Red_Elims(void) {
     // Get first goal

    driveFor(-18, 100);
    ringLift.spinFor(reverse, 150, degrees, false);
    turnToHeading(300, 100);
    driveFor(-10, 20);
    goal_clamp.set(true);

    // Get next ring (with ring sort :D)

    ringIntake.spin(forward, 80, percent);
    driveTo(-58, 7, 45, forward);
    wait(200, msec);

    // Get third ring

    driveFor(-10, 100);
    driveTo(-25, -49, 90, forward);
    wait(200, msec);
    driveFor(-12, 100);
  
    // Get last ring

    driveTo(-80, -83, 40, forward);
    wait(500, msec);

    // Wiggle

    driveFor(-4, 100);
    driveFor(16, 100);
    wait(200, msec);
    driveFor(-12, 100);
    //driveFor(16, 100);
    //driveFor(-6, 100);
    //driveFor(16, 100);
    //driveFor(-12, 100);   
}
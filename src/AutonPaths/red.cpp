#include "AutonPaths/red.h"
#include "Autonomous/auton-functions.h"

void Red_Left_Auton(void) {
    // Get first goal

    driveFor(-32, 40);
    goal_clamp.set(true);

    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(100, msec);

    // Grab third ring

    driveTo(-13.5, 51, 60, forward);
    wait(100, msec);

    // Grab to last ring 
    
    driveTo(-6, 62, 60, forward);
    wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    driveTo(-24, 57, 60, forward);
    wait(100, msec);

    // Get corner ring

    driveTo(-56, 56, 100, forward);
    driveTo(-70, 70, 100, forward);
//
    //// Touch bar
//
    driveFor(-36, 100);
    driveTo(-22, 22, 100, forward);
    //turnToHeading(135, 100);
    //driveFor(8, 100);
    moveLiftToAngle(100, false);
}

void Red_Right_Auton(void) {
    auton_color = 0; // Disable color sort

    // Rush goal

    driveFor(-32, 100);
    driveTo(-11.0, -51.0, 30, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // First ring

    //driveTo(-24, -49, 100, forward);

    // Put in corner

    driveTo(-48, -56, 100, forward);
    wait(500, msec);
    ringIntake.stop();
    ringIntake1.spin(forward, 100, percent);
    turnToHeading(300, 1000);
    goal_clamp.set(false);

    // Get next goal

    driveTo(-41, -46, 100, forward);
    ringIntake.spin(reverse, 100, percent);
    //driveTo(-32, -34, 100, reverse);
    driveTo(-14, -18, 40, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    driveTo(-68.5, 4, 50, forward);

    // Touch BAR WOOOO

    driveTo(-24, -26, 100, reverse);
    turnToHeading(45, 100);
    moveLiftToAngle(90, false);
}

void Red_Win_Point(void) {
    auton_color = 2;
    // Get first goal

    driveFor(-40, 40);
    goal_clamp.set(true);

    // Second ring

    pointAt(-30, -46, 100, forward);
    ringIntake.spin(forward, 100, percent);
    driveTo(-30, -46, 100, forward);
    driveFor(-12, 100);

    // Get third ring

    auton_color = 0;
    driveTo(-64, 16, 40, forward);
    goal_clamp.set(false);
    ringIntake.stop();
    ringIntake2.spin(forward, 100, percent);

    pointAt(-25, 24, 100, reverse);
    driveTo(-25, 24, 40, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    driveTo(-28, 48, 100, forward);

    // Touch bar

    driveTo(-31, 28, 100, reverse);
    driveTo(-20, 16, 100, forward);

    moveLiftToAngle(100, false);

    //driveFor(-18, 100);
    //ringLift.spinFor(reverse, 150, degrees, false);
    //turnToHeading(300, 100);
    //driveFor(-14, 20);
    //goal_clamp.set(true);
    //ringIntake.spin(forward, 100, percent);
//
    //// Second goal
//
    //driveTo(-51, -24, 100, forward);
    //driveTo(-51, 32, 40, forward);
    //
    //ringIntake.stop();
    //ringIntake1.spin(forward, 100, percent);
    ////wait(1300, msec);
    //driveFor(-6, 100);
    //goal_clamp.set(false);
//
    //pointAt(-20, 22, 100, reverse);
    //driveTo(-18, 22, 35, reverse);
    //goal_clamp.set(true);
    //ringIntake.spin(forward, 100, percent);
//
    //// Get next ring
    //driveTo(-26, 44, 90, forward);
    //driveFor(-20, 100);
//
    //// Touch bar
//
    //driveTo(-13.5, 13.5, 100, forward);
    //moveLiftToAngle(100, false);
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

    driveFor(-40, 40);
    goal_clamp.set(true);

    // Get next ring (with ring sort :D)

    pointAt(-58, 7, 100, forward);
    ringIntake.spin(forward, 80, percent);
    driveTo(-58, 7, 40, forward);
    wait(100, msec);

    // Get third ring

    driveFor(-10, 100);
    driveTo(-27, -49, 100, forward);
    wait(200, msec);
    driveFor(-12, 100);
  
    // Get last ring

    driveTo(-77, -83, 60, forward);
    // Wiggle

    driveFor(-6, 100);
    driveFor(16, 100);
    driveFor(-36, 100);

    //driveFor(16, 100);
    //driveFor(-6, 100);
    //driveFor(16, 100);
    //driveFor(-12, 100);   
}


void Red_Secret(void) {
     // Get first goal

    driveFor(-40, 40);
    goal_clamp.set(true);

    // Get next ring (with ring sort :D)

    pointAt(-58, 7, 100, forward);
    ringIntake.spin(forward, 80, percent);
    driveTo(-58, 7, 40, forward);
    wait(100, msec);

    // Get third ring

    driveFor(-10, 100);
    driveTo(-27, -49, 100, forward);
    wait(200, msec);
    driveFor(-12, 100);
  
    // Get last ring

    driveTo(-77, -83, 60, forward);

    // Wiggle

    driveFor(-6, 100);
    driveFor(16, 100);

    // SECRET

    turnToHeading(110, 100);
    goal_clamp.set(false);

    driveTo(-12, -60, 100, forward);
    pointAt(0, -48, 100, reverse);      
}
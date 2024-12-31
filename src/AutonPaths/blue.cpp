#include "AutonPaths/blue.h"
#include "Autonomous/auton-functions.h"

void Goal_Rush_Left_Auton(void) {
    auton_color = 1; // Disable color sort

    // Get first ring

    moveLiftToAngle(205, false);
    ringIntake1.spin(forward, 60, percent);
    driveTo(29, -52, 100, forward);

    // Put ring on goal

    driveTo(14.5, -48, 100, forward);
    moveLiftToAngle(275, false);
    ringIntake.stop();
    driveFor(2, 100);
    pointAt(29, -24, 100, reverse);
    ringIntake.spin(forward, 3, percent);

    // Get second goal

    driveFor(-30, 35);
    moveLiftToAngle(320, false);
    goal_clamp.set(true);

    // Next ring

    ringIntake.spin(forward, 90, percent);
    pointAt(59, 8.5, 100, forward);
    wait(250, msec);
    goal_clamp.set(false);
    moveLiftToAngle(200, false);
    driveTo(59, 8.5, 40, forward); // Ring Stack
    wait(400, msec);
    moveLiftToAngle(75, false);
    ringIntake.spin(forward, 100, percent);
    waitUntil(ringIntake2.torque(Nm) >= 2.3);
    ringIntake.spinFor(reverse, 50, degrees);
    ringIntake.stop();

    // Last wallstake
    driveFor(-16, 100);
    pointAt(70, -5.2, 100, forward);
    driveFor(10, 100);
    moveLiftToAngle(250, false);   

    driveFor(-4, 100);

    moveLiftToAngle(45, false);
    turnToHeading(270, 100);
    ringIntake.spin(forward, 100, percent);
    driveFor(28, 45);

    leftDrive.spin(forward, 5, percent);
    rightDrive.spin(forward, 5, percent);

    wait(2000, msec);

    leftDrive.stop();
    rightDrive.stop();
}

void Goal_Fill_Right_Auton(void) {
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(1000, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    moveLiftToAngle(45, false);

    driveTo(22, 32.5, 40, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(100, msec);

    // Grab third ring

    driveTo(11, 51, 60, forward);
    wait(100, msec);

    // Grab to last ring 
    
    driveTo(9.5, 61, 60, forward);
    wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    driveTo(24, 57, 60, forward);
    wait(100, msec);

    // Get corner ring

    driveTo(56, 56, 100, forward);
    driveTo(70, 70, 100, forward);
    wait(200, msec);
//
    //// Touch bar
//
    driveFor(-36, 100);
    driveTo(22, 22, 100, forward);
    //turnToHeading(135, 100);
    //driveFor(8, 100);
    moveLiftToAngle(240, false);
}

void Blue_Win_Point(void) {
    // Get first goal

    driveFor(-34, 50);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Second ring

    driveTo(30, -46, 100, forward);
    driveFor(-12, 100);

    // Get third ring

    driveTo(48, 0, 100, forward);
    goal_clamp.set(false);
    ringIntake.stop();

    pointAt(30, 23, 100, reverse);
    driveTo(30, 23, 40, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    driveTo(27, 44, 100, forward);

    // Touch bar

    driveTo(31, 28, 100, reverse);
    driveTo(20, 16, 100, forward);

    moveLiftToAngle(100, false);


    //driveTo(53, -24, 100, forward);
    //driveTo(53, 36, 35, forward);
    ////wait(1300, msec);
    //driveFor(-6, 100);
    //wait(300, msec);
    //goal_clamp.set(false);
//
    //pointAt(19, 26, 100, reverse);
    //driveTo(19, 26, 35, reverse);
    //goal_clamp.set(true);
    //ringIntake.spin(forward, 100, percent);
//
    //// Get next ring
    //driveTo(26, 46, 100, forward);
    //driveFor(-20, 100);
//
    //// Touch bar
//
    //driveTo(13.5, 13.5, 100, forward);
    //moveLiftToAngle(100, false);

    //driveTo(54, -0.1, 100, reverse);
    //turnToHeading(270, 100);
    //driveFor(-9, 100);
//
    //ringIntake.spin(forward, 100, percent);
    //wait(500, msec);
    //ringIntake.stop();
//
    //driveFor(12, 100);
//
    //driveTo(19.5, 28.5, 40, reverse);
    //goal_clamp.set(true);
//
    //ringIntake.spin(forward, 100, percent);
    //driveTo(8.5, 41, 80, forward);
    //wait(1000, msec);
    //driveFor(-16, 100);
    //driveTo(19.5, 48, 100, forward);
    //driveTo(17, 15.5, 100, forward);
//
    //turnToHeading(225, 100);
    //driveFor(-2, 100);
    //moveLiftToAngle(100, false);
}

void Blue_Elims(void) {
    // Get first goal

    driveFor(-40, 40);
    goal_clamp.set(true);

    // Get next ring (with ring sort :D)

    pointAt(60, 7, 100, forward);
    ringIntake.spin(forward, 80, percent);
    driveTo(60, 7, 50, forward);
    wait(100, msec);

    // Get third ring

    driveFor(-10, 100);
    driveTo(25, -46, 100, forward);
    wait(200, msec);
    driveFor(-12, 100);

    // Get last ring

    driveTo(73, -81, 60, forward);

    // Wiggle

    driveFor(-6, 100);
    driveFor(16, 100);
    driveFor(-14, 100);
    driveFor(16, 100);
    driveFor(-14, 100);

}

void Blue_Secret(void) {
    // Get first goal

    driveFor(-40, 40);
    goal_clamp.set(true);

    // Get next ring (with ring sort :D)

    pointAt(60, 7, 100, forward);
    ringIntake.spin(forward, 80, percent);
    driveTo(60, 7, 50, forward);
    wait(100, msec);

    // Get third ring

    driveFor(-10, 100);
    driveTo(25, -46, 100, forward);
    wait(200, msec);
    driveFor(-12, 100);

    // Get last ring

    driveTo(73, -81, 60, forward);

    // Wiggle

    driveFor(-6, 100);
    driveFor(16, 100);
    
    // SECRET

    turnToHeading(110, 100);
    goal_clamp.set(false);

    driveTo(12, -60, 100, forward);
    pointAt(0, -48, 100, reverse);
}
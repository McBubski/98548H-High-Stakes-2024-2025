#include "AutonPaths/blue.h"
#include "Autonomous/auton-functions.h"

void Blue_Left_Auton(void) {
        auton_color = 1; // Disable color sort

    // Rush goal

    driveFor(-32, 100);
    driveTo(5.5, -50.5, 30, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // First ring

    //driveTo(-24, -49, 100, forward);

    // Put in corner

    driveTo(48, -56, 100, forward);
    ringIntake.stop();
    ringIntake1.spin(forward, 100, percent);
    //turnToHeading(60, 100);
    goal_clamp.set(false);

    // Get next goal

    driveTo(41, -46, 100, forward);
    ringIntake.spin(reverse, 100, percent);
    //driveTo(-32, -34, 100, reverse);
    driveTo(18, -20, 40, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    driveTo(68.5, 5, 50, forward);

    // Touch BAR WOOOO

    driveTo(29, 0, 75, forward);
    moveLiftToAngle(90, false);
    //moveLiftToAngle(100, false);

    //

    

   //driveFor(-36, 100);
   //driveTo(9.5, -52.5, 30, reverse);
   //goal_clamp.set(true);

   //ringIntake.spin(forward, 100, percent);
   //wait(400, msec);

   //// Second ring

   //driveTo(28, -50, 100, forward);
   //ringIntake.stop();
   //ringIntake2.spin(forward, 100, percent);
   //turnToHeading(0, 100);
   //goal_clamp.set(false);

   //// Get second goal

   //pointAt(25.5, -24, 100, reverse);
   //driveFor(-22, 40);
   //goal_clamp.set(true);
   //ringIntake.spin(forward, 100, percent);

   //wait(500, msec);

   //// Touch bar

   ////driveFor(-5, 100);
   ////turnToHeading(280, 100);
   ////driveFor(8, 100);
   ////corner_arm.set(true);
   ////turnToHeading(200, 50);

   //turnToHeading(315, 100);
   //driveFor(4, 100);
   //moveLiftToAngle(100, false);
}

void Blue_Right_Auton(void) {
    // Get first goal

    driveFor(-32, 40);
    goal_clamp.set(true);

    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(100, msec);

    // Grab third ring

    driveTo(14, 51, 60, forward);
    wait(100, msec);

    // Grab to last ring 
    
    driveTo(6.5, 62, 60, forward);
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
    moveLiftToAngle(100, false);
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

    ringIntake.spin(forward, 80, percent);
    driveTo(58, 7, 50, forward);
    wait(200, msec);

    // Get third ring

    driveFor(-10, 100);
    driveTo(25, -46, 100, forward);
    wait(200, msec);
    driveFor(-12, 100);

    // Get last ring

    driveTo(74, -79, 60, forward);

    // Wiggle

    driveFor(-6, 100);
    driveFor(16, 100);
    driveFor(-14, 100);
    driveFor(16, 100);
    driveFor(-14, 100);

}
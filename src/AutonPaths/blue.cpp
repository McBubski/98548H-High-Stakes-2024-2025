#include "AutonPaths/blue.h"
#include "Autonomous/auton-functions.h"

void Blue_Left_Auton(void) {
        // Rush goal
    ringLift.spinFor(forward, 250, degrees, false);
    driveFor(-36, 100);
    ringLift.spinFor(reverse, 250, degrees, false);
    driveTo(9.5, -52.5, 40, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(400, msec);

    // Second ring

    driveTo(30, -54, 100, forward);
    ringIntake.stop();
    turnToHeading(0, 100);
    goal_clamp.set(false);

    // Get second goal

    pointAt(26, -28, 100, reverse);
    driveTo(26, -28, 30, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    wait(500, msec);

    // Touch bar

    //driveFor(-5, 100);
    //turnToHeading(280, 100);
    //driveFor(8, 100);
    //corner_arm.set(true);
    //turnToHeading(200, 50);

    turnToHeading(225, 100);
}

void Blue_Right_Auton(void) {
    // Raise Arm
    ringLift.spinFor(forward, 150, degrees, false);

    // Get first goal

    driveFor(-18, 100);
    ringLift.spinFor(reverse, 150, degrees, false);
    turnToHeading(120, 100);
    driveFor(-10, 20);
    goal_clamp.set(true);

    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(300, msec);

    // Grab second ring

    driveTo(28, 48, 100, forward);
    wait(300, msec);
    driveFor(-8, 100);

    // Grab third ring

    driveTo(15, 44, 60, forward);

    // Grab to last ring 
    
    driveTo(10, 48, 60, forward);

    // Touch bar

    driveTo(24, 22, 40, reverse);
    turnToHeading(270, 100);
    corner_arm.set(true);
    driveFor(6, 100);
    turnToHeading(240, 100);
}

void Failsafe(void) {
    ringLift.setStopping(hold);
    ringIntake.spin(reverse, 100, percent);
    driveFor(20, 100);
    ringIntake.stop();
    turnToHeading(275, 100);
    driveFor(-4, 100);

    ringLift.spin(forward, 80, percent);
    wait(600, msec);
    ringLift.stop();

    driveFor(6, 100);

    ringLift.spin(reverse, 80, percent);
    wait(400, msec);
    ringLift.setStopping(coast);
    ringLift.stop();   

    driveFor(-16, 100); 

    turnToHeading(320, 100);
    driveFor(-38, 40);
    goal_clamp.set(true);
    turnToHeading(180, 100);

    ringIntake.spin(forward, 100, percent);
    driveFor(28, 100);
    wait(1500, msec);
    driveFor(-28, 100);
    turnToHeading(110, 100);
    driveFor(10, 100);

    ringIntake.stop();
    corner_arm.set(true);
    turnToHeading(35, 100); 
}
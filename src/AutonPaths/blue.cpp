#include "AutonPaths/blue.h"
#include "Autonomous/auton-functions.h"

void Goal_Rush_Left_Auton(void) {
    auton_color = 1; // Disable color sort
    vex::task raiseArm;
    
    // Get first ring on goql

    raiseArm = createRaiseArmTask(230);
    driveTo(18.5, -46.5, 70, forward);
    moveLiftToAngle(275, false);

    // Get second goal

    driveTo(28.0, -20.5, 25, reverse);
    goal_clamp.set(true);

    // Get next ring

    ringIntake.spin(forward, 100, percent);
    raiseArm = createRaiseArmTask(290);
    driveTo(22, -60, 100, forward);

    // Move to next ring

    driveFor(-24, 100);
    pointAt(54, 5, 100, forward);
    raiseArm = createRaiseArmTask(64);
    goal_clamp.set(false);
    driveTo(54, 8, 60, forward);
    wait(400, msec);
    ringIntake2.stop();
    raiseArm = createRaiseArmTask(101);
    driveTo(48, -7, 100, reverse);
    ringIntake2.spin(forward, 100, percent);

    // Alliance Stake

    pointAt(70, -2.8, 100, forward);
    driveFor(2.75, 100);
    ringIntake.stop();
    ringIntake2.spinFor(reverse, 100, degrees);
    ringLiftArm.spin(reverse, 100, percent);
    wait(850, msec);
    ringLiftArm.stop();
    driveFor(-23, 25);

    // Put ring on goal

    //driveTo(14.5, -48, 100, forward);
    //raiseArm = createRaiseArmTask(275);
    //ringIntake.stop();
    //driveFor(2, 100);
    //pointAt(29, -24, 100, reverse);
    //ringIntake.spin(forward, 3, percent);
//
    //// Get second goal
//
    //driveFor(-30, 35);
    //raiseArm = createRaiseArmTask(320);
    //goal_clamp.set(true);
//
    //// Next ring
//
    //ringIntake.spin(forward, 90, percent);
    //pointAt(59, 8.5, 100, forward);
    //wait(250, msec);
    //goal_clamp.set(false);
    //raiseArm = createRaiseArmTask(200);
    //driveTo(59, 8.5, 40, forward); // Ring Stack
    //wait(400, msec);
    //raiseArm = createRaiseArmTask(75);
    //ringIntake.spin(forward, 100, percent);
    //waitUntil(ringIntake2.torque(Nm) >= 2.3);
    //ringIntake.spinFor(reverse, 50, degrees);
    //ringIntake.stop();
//
    //// Last wallstake
    //driveFor(-16, 100);
    //pointAt(70, -5.2, 100, forward);
    //driveFor(10, 100);
    //moveLiftToAngle(250, false);   
//
    //driveFor(-4, 100);
//
    //moveLiftToAngle(45, false);
    //turnToHeading(270, 100);
    //ringIntake.spin(forward, 100, percent);
    //driveFor(28, 45);
//
    //leftDrive.spin(forward, 5, percent);
    //rightDrive.spin(forward, 5, percent);
//
    //wait(2000, msec);
//
    //leftDrive.stop();
    //rightDrive.stop();
}

void Goal_Fill_Right_Auton(void) {
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(1000, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    driveTo(21, 34.5, 40, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(100, msec);

    // Grab third ring

    driveTo(15.5, 50.25, 60, forward);
    wait(100, msec);

    // Grab to last ring 
    
    //driveTo(16.25, 62, 60, forward);
    turnToHeading(355, 100);
    driveFor(16, 100);
    wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    driveTo(24, 55, 60, forward);
    wait(100, msec);

    // Get corner ring

    driveTo(60, 60, 100, forward);
    driveTo(70, 70, 100, forward);
    wait(200, msec);
//
    //// Touch bar
//
    driveFor(-36, 90);
    raiseArm = createRaiseArmTask(220);
    driveTo(30, 30, 100, forward);
    //turnToHeading(135, 100);
    //driveFor(8, 100);
}

void Blue_Win_Point(void) {
    // Get alliance stake

    ringLiftArm.spin(reverse, 100, percent);
    wait(900, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    // Grab goal

    driveTo(21, -27, 40, reverse);
    goal_clamp.set(true);
    
    // Get lifted ring
    
    lifted_intake.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(43, -6, 100, forward);
    lifted_intake.set(false);
    driveFor(-12, 100);

    // Get second ring

    driveTo(28, -50, 100, forward);

    // Get corner ring

    driveTo(66, -68, 50, forward);
    driveFor(-4, 100);
    driveFor(8, 100);

    // Touch bar

    driveTo(28, -50, 100, reverse);

    raiseArm = createRaiseArmTask(230);

    driveTo(23, -23, 60, forward);
    turnToHeading(315, 100);
}

int delayRaiseIntakeButOnlyForThisSpecificAutonLmao() {
    wait(800, msec);
    lifted_intake.set(true);
    return 1;
}

void Blue_Elims(void) {
    auton_color = 1;
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(800, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    driveTo(19, 34, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(13.5, 48, 80, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(11.5, 58.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-12, 100);

    // Grab second ring

    //driveTo(24, 54, 60, forward);
    //wait(100, msec);

    // Get corner ring

    //driveTo(60, 64, 100, forward);
    driveTo(80, 84, 45, forward);
    wait(200, msec);
    driveFor(-12, 100);

    // Get middle ring

    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonLmao);
    driveTo(54, 8, 100, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    driveTo(24, -48, 100, forward); 
    //driveFor(-6, 100);
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
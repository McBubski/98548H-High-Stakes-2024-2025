#include "AutonPaths/blue.h"
#include "Autonomous/auton-functions.h"

int dumbArmTask2(void) {
    ringIntake.spin(forward, 100, percent);
    wait(100, msec);
    goal_rush_arm.set(true);

    return 1;
}

void Goal_Rush_Left_Auton(void) {
    // Do everything really fast 
    task raiseArm = createRaiseArmTask(98);
    task rushArm = task(dumbArmTask2);

    // Rush and grab goal
    driveFor(30.5, 100);
    goal_rush_arm_clamp.set(true);
    driveFor(-20, 100);

    // Put on goal

    goal_rush_arm_clamp.set(false);
    goal_rush_arm.set(false);
    turnToHeading(281, 100);
    driveFor(5.5, 100);
    ringIntake.spinFor(reverse, 50, degrees);
    ringLiftArm.spin(reverse, 100, percent);
    wait(950, msec);
    ringLiftArm.stop();
    raiseArm = createRaiseArmTask(64);
    driveFor(-12, 100);

    // Get next goal

    ringIntake2.spin(reverse, 50, percent);
    driveTo(24.5, -19.5, 55, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    driveTo(64, -58, 60, forward);
    turnToHeading(160, 100);
    driveFor(24, 30);

    // Clear corner
    driveFor(-8, 100);
    goal_rush_arm.set(true);
    driveFor(3, 100);
    turnToHeading(227, 100);
    goal_rush_arm.set(false);
    goal_clamp.set(false);

    driveTo(24, -50, 60, reverse);
}


int delayRaiseIntakeButOnlyForThisSpecificAutonLmao() {
    wait(800, msec);
    lifted_intake.set(true);
    return 1;
}

void Goal_Fill_Right_Auton(void) {
    //auton_color = 1;
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(800, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    driveTo(17.5, 36.5, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(16, 48, 80, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(10.25, 58.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);

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
    driveTo(52, 8, 100, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    raiseArm = createRaiseArmTask(220);
    turnToHeading(260, 100);
    driveFor(16, 100);
    //driveFor(-6, 100);
}

void Blue_Win_Point(void) {
    // Get alliance stake

    ringLiftArm.spin(reverse, 100, percent);
    wait(900, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    // Grab goal

    driveTo(18, -26.5, 40, reverse);
    goal_clamp.set(true);
    
    // Get lifted ring
    
    lifted_intake.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(44, -5, 100, forward);
    lifted_intake.set(false);
    driveFor(-12, 100);

    // Get second ring

    driveTo(28, -50, 100, forward);

    // Get corner ring

    driveTo(66, -70, 50, forward);
    driveFor(-4, 100);
    driveFor(8, 100);

    // Touch bar

    driveTo(28, -50, 100, reverse);

    raiseArm = createRaiseArmTask(230);

    driveTo(23, -23, 60, forward);
    turnToHeading(315, 100);
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
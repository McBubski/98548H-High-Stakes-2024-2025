#include "AutonPaths/red.h"
#include "Autonomous/auton-functions.h"

int delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao() {
    wait(800, msec);
    lifted_intake.set(true);
    return 1;
}

void Goal_Fill_Left_Auton(void) {
    //auton_color = 0;
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(800, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    driveTo(-17.5 , 36.5, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(-17.25, 46, 90, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(-12, 58.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    //driveTo(24, 54, 60, forward);
    //wait(100, msec);

    // Get corner ring

    //driveTo(60, 64, 100, forward);
    driveTo(-80, 84, 45, forward);
    wait(200, msec);
    driveFor(-14, 100);

    // Get middle ring

    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao);
    driveTo(-54, 8, 100, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    raiseArm = createRaiseArmTask(220);
    turnToHeading(105, 100);
    driveFor(16, 100);
}

int dumbArmTask(void) {
    //ringIntake.spin(forward, 100, percent);
    wait(100, msec);
    goal_rush_arm.set(true);

    return 1;
}

void Goal_Rush_Right_Auton(void) {
    // Do everything really fast 
    task raiseArm = createRaiseArmTask(140);
    task rushArm = task(dumbArmTask);
    ringIntake1.spin(forward, 100, percent);
    ringIntake2.stop();

    // Rush and grab goal
    driveFor(31.5, 100);
    goal_rush_arm_clamp.set(true);
    driveFor(-20, 100);

    // Put on goal

    goal_rush_arm_clamp.set(false);
    goal_rush_arm.set(false);
    turnToHeading(270, 100);
    driveFor(-18, 40);
    goal_clamp.set(true);
    //ringIntake.spinFor(reverse, 50, degrees);
    //ringLiftArm.spin(reverse, 100, percent);
    ringIntake.spin(forward, 100, percent);
    //wait(950, msec);
    //raiseArm = createRaiseArmTask(64);
    //goal_clamp.set(false);
    driveTo(-60, -48, 70, forward);

    driveTo(-66, -67, 30, forward);
    ringIntake.stop();
    ringIntake1.spin(forward, 100, percent);
    //wait(200, msec);

    driveFor(-10, 100);
    goal_rush_arm.set(true);
    goal_rush_arm_clamp.set(true);
    driveFor(2, 100);
    turnToHeading(310, 100);
    goal_rush_arm.set(false);
    goal_rush_arm_clamp.set(false);

    turnToHeading(30, 100);
    goal_clamp.set(false);

    driveTo(-17, -24, 60, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    //ringIntake.spin(forward, 100, percent);

    driveTo(-20, -60, 100, forward);
    raiseArm = createRaiseArmTask(180);

    turnToHeading(130, 100);//pointAt(0.75, -72, 90, forward);
    driveFor(5, 60);
    raiseArm = createRaiseArmTask(209);

    //goal_rush_arm_clamp.set(false);
    //goal_rush_arm.set(false);
    //turnToHeading(90, 100);
    //driveFor(4, 100);
    //ringIntake.spinFor(reverse, 17, degrees);
    //ringLiftArm.spin(reverse, 100, percent);
    //wait(1000, msec);
    //ringLiftArm.stop();
    //raiseArm = createRaiseArmTask(48);
    //driveFor(-8, 100);
//
    //// Get next goal
//
    //ringIntake2.spin(reverse, 100, percent);
    ////pointAt(-22.5, -19.5, 55, reverse);
    ////driveFor(12, 100);
    //driveTo(-18.5, -23.5, 55, reverse);
    //goal_clamp.set(true);
//
    //ringIntake.spin(forward, 100, percent);
    //driveTo(-64, -48, 60, forward);
    //turnToHeading(200, 100);
    //driveFor(46, 40);
//
    //// Clear corner
    //driveFor(-10, 100);
    //goal_rush_arm.set(true);
    //driveFor(3, 100);
    //turnToHeading(315, 100);
    //turnToHeading(315, 100);
    //goal_rush_arm.set(false);
    //goal_clamp.set(false);
    //driveFor(4, 100);
//
    //driveTo(-24, -46, 60, reverse);
    ////goal_clamp.set(true);
}

void Red_Win_Point(void) {
    // Get alliance stake

    ringLiftArm.spin(reverse, 100, percent);
    wait(900, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    // Grab goal

    driveTo(-21, -27, 40, reverse);
    goal_clamp.set(true);
    
    // Get lifted ring
    
    lifted_intake.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-44.5, -6, 100, forward);
    lifted_intake.set(false);
    driveFor(-12, 100);

    // Get second ring

    driveTo(-28, -50, 100, forward);

    // Get corner ring

    driveTo(-66, -68, 50, forward);
    driveFor(-4, 100);
    driveFor(8, 100);

    // Touch bar

    driveTo(-28, -50, 100, reverse);

    raiseArm = createRaiseArmTask(230);

    driveTo(-25, -25, 100, forward);
    turnToHeading(45, 100);

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
    moveLiftToAngle(100, false);
}

void Red_Elims(void) {
    auton_color = 0;
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(800, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    driveTo(-19 , 34, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(-17.25, 46, 90, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(-11.5, 58.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    //driveTo(24, 54, 60, forward);
    //wait(100, msec);

    // Get corner ring

    //driveTo(60, 64, 100, forward);
    driveTo(-84, 87, 45, forward);
    wait(200, msec);
    driveFor(-12, 60);
    //lifted_intake.set(true);
    //driveFor(12, 100);
    //lifted_intake.set(false);
    //driveFor(-12, 100);

    // Get middle ring

    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao);
    driveTo(-57.5, 8, 100, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    //driveTo(-24, -48, 100, forward); 
    //driveFor(-4, 100);
    //raiseArm = createRaiseArmTask(200);
    //turnToHeading(95, 100);
    //driveFor(12, 100);
    //driveFor(-6, 100);
}


void Red_Sig_Point(void) {
   // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(700, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(64);

    driveTo(-19 , 34, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(-17, 47.5, 90, forward);
    wait(25, msec);

    // Grab to last ring 

    driveFor(-6, 100);    
    driveTo(-26, 52, 100, forward);

    // Get ring stack

    ringIntake1.spin(forward, 100, percent);
    pointAt(-56.5, 10, 100, forward);
    lifted_intake.set(true);
    driveFor(getDistance(Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos, -59, 10), 100);
    
    lifted_intake.set(false);

    // Drop goal

    //driveFor(-8, 100);
    goal_clamp.set(false);
    //driveFor(6, 100);

    // Get next goal

    pointAt(-26.5, -15, 55, reverse);
    ringIntake2.stop();
    driveTo(-26.5, -15, 55, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Get final ring

    driveTo(-36, -37.5, 100, forward);

    // Touch

    driveFor(-24, 100);
    task armTask = createRaiseArmTask(230);
    turnToHeading(45, 100);
    driveFor(8, 100);
}
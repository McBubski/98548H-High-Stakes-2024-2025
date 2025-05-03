#include "AutonPaths/red.h"
#include "Autonomous/auton-functions.h"
#include "Competition/user-functions.h"

#include <cmath>
#include <iostream>

int delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao() {
    wait(800, msec);
    lifted_intake.set(true);
    return 1;
}

void Goal_Fill_Left_Auton(void) {
    //auton_color = 0;
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    driveTo(-20.5 , 35.5, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(-12.5, 49, 90, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(-6.5, 58.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    //driveTo(24, 54, 60, forward);
    //wait(100, msec);

    // Get corner ring

    //driveTo(60, 64, 100, forward);
    driveTo(-74, 90, 50, forward);
    wait(200, msec);
    ringIntake.spinFor(reverse, 30, degrees);
    ringIntake.spin(forward, 100, percent);
    driveFor(-18, 100);

    // Get middle ring

    //ringIntake.stop();
    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao);
    driveTo(-45.5, 7, 100, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    raiseArm = createRaiseArmTask(120);
    turnToHeading(105, 100);
    ringIntake.spinFor(reverse, 30, degrees);
    ringIntake.spin(forward, 100, percent);
    driveFor(18, 100);
}

int dumbArmTask(void) {
    //ringIntake.spin(forward, 100, percent);
    wait(100, msec);
    goal_rush_arm_right.set(true);

    return 1;
}

void Goal_Rush_Right_Auton(void) {
    // Do everything really fast 
    goal_rush_arm_right_clamp.set(true);
    task raiseArm = createRaiseArmTask(210);
    task rushArm = task(dumbArmTask);
    ringIntake.spin(forward, 10, percent);

    // Rush and grab goal
    driveFor(33.5, 100);
    goal_rush_arm_right_clamp.set(false);

    driveFor(-20, 100);

    // Grab goal 
    goal_rush_arm_right_clamp.set(true);
    goal_rush_arm_right.set(false);
    turnToHeading(255, 100);
    driveFor(-24, 30);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-50, -48, 70, forward);

    driveTo(-74, -70, 35, forward);

    // Grab Corner Ring
    ringIntake.spin(forward, 10, percent);
    driveFor(-16, 100);
    goal_rush_arm_right.set(true);
    goal_rush_arm_right_clamp.set(true);
    driveFor(4, 100);
    turnToHeading(113, 100);
    goal_rush_arm_right.set(false);
    goal_rush_arm_right_clamp.set(false);

    turnToHeading(330, 100);
    goal_clamp.set(false);
    ringIntake.stop();

    driveTo(-21, -21, 50, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    driveTo(-24, -48, 100, forward);

    driveTo(-10, -65, 100, forward);
    raiseArm = createRaiseArmTask(130);
    pointAt(0, -72, 100, forward);
}

void Red_Win_Point(void) {
    // Get alliance stake

    ringLiftArm.spin(reverse, 100, percent);
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    // Grab goal

    driveTo(-16, -27, 40, reverse);
    goal_clamp.set(true);
    
    // Get lifted ring
    
    lifted_intake.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-42.5, -5, 100, forward);
    lifted_intake.set(false);
    driveFor(-12, 100);

    // Get second ring

    driveTo(-24, -50, 100, forward);
    wait(50, msec);

    raiseArm = createRaiseArmTask(120);

    // Get corner ring

    driveTo(-66, -70, 50, forward);
    driveFor(-4, 100);
    lifted_intake.set(true);
    driveFor(12, 100);
    lifted_intake.set(false);

    // Touch bar

    driveTo(-28, -50, 100, reverse);

    //raiseArm = createRaiseArmTask(125);

    driveTo(-18, -18, 60, forward);
    //turnToHeading(315, 100);

    //driveFor(4, 100);
}

void Red_Elims(void) {
    auton_color = 0;
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(800, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    driveTo(-19.5, 32.5, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(-17.75, 46, 90, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(-11.5, 58.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);
    raiseArm = createRaiseArmTask(110);

    // Grab second ring

    driveTo(-78, 92, 45, forward);
    wait(200, msec);
    driveFor(-16, 100);

    // Get middle ring

    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao);
    driveTo(-63, 6, 100, forward);
    raiseArm = createRaiseArmTask(280);
    lifted_intake.set(false);

    driveFor(-6, 100);
    driveTo(-75, -10, 100, reverse);
    //driveTo(-24,-48, 100, forward); 
    //driveFor(-4, 100);
    //raiseArm = createRaiseArmTask(200);
    //turnToHeading(95, 100);
    //driveFor(12, 100);
    //driveFor(-6, 100);
}


void Red_Sig_Point(void) {
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    driveTo(-22.5 , 36, 50, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);

    // Grab third ring

    driveTo(-11.5, 49.5, 80, forward);
    wait(25, msec);

    // Grab to last ring 

    driveFor(-6, 100);
    ringIntake.spinFor(reverse, 50, degrees, true);
    ringIntake.spin(forward, 100, percent);    
    driveTo(-24, 54, 100, forward);

    // Get ring stack
  
    ringIntake.spinFor(reverse, 50, degrees, true);
    ringIntake.spin(forward, 100, percent); 
    pointAt(-55, 10, 100, forward);
    lifted_intake.set(true);
    driveFor(getDistance(Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos, -55.5, 10), 100);

    lifted_intake.set(false);
    //ringIntake1.spin(forward, 100, percent);

    // Drop goal

    //driveFor(-8, 100);
    goal_clamp.set(false);
    //driveFor(6, 100);

    // Get next goal

    pointAt(-20.5, -12.5, 100, reverse);
    ringIntake.spin(forward, 5, percent);
    //ringIntake2.stop();
    driveTo(-19, -14.5, 55, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Get final ring

    driveTo(-20, -37.5, 100, forward);

    // Touch

    driveFor(-24, 100);
    task armTask = createRaiseArmTask(120);
    turnToHeading(45, 100);
    driveFor(10, 100);
}

void Positive_Elims_Red(void) {
    auton_color = 0;
    ringIntake1.spin(forward, 100, percent);
    ringIntake2.stop();

    task raiseArm = createRaiseArmTask(280);

    // Grab first ring

    driveFor(28, 100);

    // Grab goal

    driveTo(-23, -24, 40, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(300, msec);

    // Drive to ring stack

    lifted_intake.set(true);
    driveTo(-49, -8, 100, forward);

    // Get lifted ring

    lifted_intake.set(false);
    //driveFor(-16, 100);

    // Reverse

    driveTo(-52, -49, 100, reverse);
    ringIntake2.spinFor(reverse, 40, degrees);
    ringIntake.spin(forward, 100, percent);

    // Get corner

    driveTo(-73, -68.5, 40, forward);
    ringIntake2.spin(forward, 50, percent);
    moveLiftToAngle(251, false);
    driveFor(-8, 100);

    // Get second corner ring
    raiseArm = createRaiseArmTask(280);
    driveFor(-8, 100);
    ringIntake2.spin(forward, 100, percent);

    // Put in corner

    driveFor(12, 100);

    // Change this depending on alliance

    driveCurve(-42, 100, 2.7);
    goal_clamp.set(false);
    turnToHeading(0, 100);
    driveFor(12, 100);
    //driveTo(-36, -46, 100, forward);
    driveTo(-16, Position_Tracking.GlobalYPos, 100, reverse);
    //driveTo(-18, -46, 100, reverse);
}

void Corner_Clear_Red(void) {
    task raiseArm = createRaiseArmTask(210);

    // Grab goal

    driveFor(-getDistance(-22, -22, Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos), 45);
    goal_clamp.set(true);

    // Get first ring

    ringIntake.spin(forward, 100, percent);
    driveTo(-25.5, -48, 100, forward);

    // Get second ring

    driveTo(-50, -56, 100, forward);

    // Get corner

    pointAt(-72, -73, 100, forward);
    driveFor(30, 40);
    wait(200, msec);

    // Clear corner
    driveFor(-6, 40);
    //goal_rush_arm_right.set(true);
    //goal_rush_arm_right_clamp.set(true);
    //wait(400, msec);
    //driveFor(8, 80);

    lifted_intake.set(true);
    driveFor(12, 40);
    lifted_intake.set(false);

    //turnToHeading(105, 70);
    //goal_rush_arm_right.set(false);
    //goal_rush_arm_right_clamp.set(false);
    //driveFor(10, 100);
    driveFor(-10, 100);

    // Wallstake

    driveTo(-10, -62, 100, forward);
    ///turnToHeading(135, 100);
    pointAt(0, -70, 100, forward);
    driveFor(5, 100);
    raiseArm = createRaiseArmTask(130);

    // This is where you add the part to make the arm stay out for driver. I hope this comment isn't
    // foreshadowing anything, that would be funny. Please add this back. If this causes problems,
    // at least I recognized it in advance lmao.
}
#include "AutonPaths/blue.h"
#include "Autonomous/auton-functions.h"

#include <cmath>
#include <iostream>

int dumbArmTask2(void) {
    //ringIntake.spin(forward, 100, percent);
    wait(100, msec);
    goal_rush_arm.set(true);

    return 1;
}

void Goal_Rush_Left_Auton(void) {
    // Do everything really fast 
    goal_rush_arm_clamp.set(true);
    task raiseArm = createRaiseArmTask(210);
    task rushArm = task(dumbArmTask2);
    ringIntake.spin(forward, 10, percent);

    // Rush and grab goal
    driveFor(33.5, 100);
    goal_rush_arm_clamp.set(false);

    driveFor(-20, 100);

    // Grab goal 
    goal_rush_arm_clamp.set(true);
    goal_rush_arm.set(false);
    turnToHeading(105, 100);
    driveFor(-24, 30);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(50, -48, 70, forward);

    driveTo(74, -70, 35, forward);

    // Grab Corner Ring
    ringIntake.spin(forward, 10, percent);
    driveFor(-16, 100);
    goal_rush_arm.set(true);
    goal_rush_arm_clamp.set(true);
    driveFor(4, 100);
    turnToHeading(247, 100);
    goal_rush_arm.set(false);
    goal_rush_arm_clamp.set(false);

    turnToHeading(30, 100);
    goal_clamp.set(false);
    ringIntake.stop();

    driveTo(18.5, -23, 60, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    driveTo(24, -56, 100, forward);

    driveTo(9, -65, 100, forward);
    raiseArm = createRaiseArmTask(130);
    pointAt(0, -72, 100, forward);
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
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    driveTo(20.5, 33, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(12.5, 49, 80, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(9.5, 57.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);

    // Grab second ring

    //driveTo(24, 54, 60, forward);
    //wait(100, msec);

    // Get corner ring

    //driveTo(60, 64, 100, forward);
    driveTo(80, 87, 50, forward);
    wait(200, msec);
    driveFor(-14, 100);

    // Get middle ring

    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonLmao);
    driveTo(54.5, 7, 80, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    raiseArm = createRaiseArmTask(140);
    turnToHeading(260, 100);
    ringIntake.spinFor(reverse, 30, degrees);
    ringIntake.spin(forward, 100, percent);
    driveFor(16, 100);
    //driveFor(-6, 100);
}

void Blue_Win_Point(void) {
    // Get alliance stake

    ringLiftArm.spin(reverse, 100, percent);
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    // Grab goal

    driveTo(17, -28, 40, reverse);
    goal_clamp.set(true);
    
    // Get lifted ring
    
    lifted_intake.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(46.5, -5, 100, forward);
    lifted_intake.set(false);
    driveFor(-12, 100);

    // Get second ring

    driveTo(28, -50, 100, forward);

    raiseArm = createRaiseArmTask(120);

    // Get corner ring

    driveTo(66, -70, 50, forward);
    driveFor(-8, 100);
    lifted_intake.set(true);
    driveFor(12, 100);
    lifted_intake.set(false);

    // Touch bar

    driveTo(28, -50, 100, reverse);

    //raiseArm = createRaiseArmTask(125);

    driveTo(18, -18, 60, forward);
    //turnToHeading(315, 100);

    //driveFor(4, 100);
}

void Blue_Elims(void) {
    auton_color = 1;
    // Score first ring

    //ringLiftArm.spin(reverse, 100, percent);
    //wait(800, msec);
    //ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    driveTo(20.5, 36.5, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(19.5, 48, 80, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(13.75, 60.5, 100, forward);
    //turnToHeading(355, 100);
    //driveFor(16, 100);
    //wait(100, msec);
    driveFor(-10, 100);
    raiseArm = createRaiseArmTask(100);

    // Grab second ring

    //driveTo(24, 54, 60, forward);
    //wait(100, msec);

    // Get corner ring

    //driveTo(60, 64, 100, forward);
    driveTo(80, 84, 50, forward);
    wait(200, msec);
    driveFor(-14, 100);

    // Get middle ring

    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonLmao);
    driveTo(59, 8, 100, forward);
    raiseArm = createRaiseArmTask(280);
    lifted_intake.set(false);

    driveFor(-6, 100);
    ringIntake1.stop();
    pointAt(75, -50, 100, reverse);
    goal_clamp.set(false);
    driveTo(75, -50, 100, reverse);
    //driveTo(24, -48, 100, forward); 
    //driveFor(-6, 100);
}

void Blue_Sig_Point(void) {
    // Score first ring

    ringLiftArm.spin(reverse, 100, percent);
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    driveTo(18.5 , 36, 50, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);

    // Grab third ring

    driveTo(11.5, 49.5, 80, forward);
    wait(25, msec);

    // Grab to last ring 

    driveFor(-6, 100);    
    driveTo(24, 54, 100, forward);

    // Get ring stack

    ringIntake.spin(forward, 100, percent);
    pointAt(47, 10, 100, forward);
    lifted_intake.set(true);
    driveFor(getDistance(Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos, 55.5, 10), 100);

    lifted_intake.set(false);
    //ringIntake1.spin(forward, 100, percent);

    // Drop goal

    //driveFor(-8, 100);
    goal_clamp.set(false);
    //driveFor(6, 100);

    // Get next goal

    pointAt(26.5, -12.5, 100, reverse);
    ringIntake.spin(forward, 15, percent);
    //ringIntake2.stop();
    driveTo(24.5, -14.5, 55, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Get final ring

    driveTo(28, -37.5, 100, forward);

    // Touch

    driveFor(-24, 100);
    task armTask = createRaiseArmTask(120);
    turnToHeading(315, 100);
    driveFor(10, 100);
}

void Positive_Elims_Blue(void) {
    //std::cout << auton_color << std::endl;
    auton_color = 2;
    ringIntake1.spin(forward, 100, percent);
    ringIntake2.stop();

    task raiseArm = createRaiseArmTask(280);

    // Grab first ring

    driveFor(28, 100);

    // Grab goal

    driveTo(23.5, -24, 40, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(200, msec);

    // Put arm down on ring across

    pointAt(11, -9.5, 100, forward);
    ringIntake.stop();
    driveTo(11, -9.5, 60, forward);

    goal_rush_arm_clamp.set(true);
    goal_rush_arm.set(true);

    wait(300, msec);

    goal_rush_arm_clamp.set(false);

    // Pull ring across

    driveFor(-24, 100);
    auton_color = 1;

    // Point At Ring Stack

    turnToHeading(52, 100);
    goal_rush_arm.set(false);

    // Drive to ring stack

    ringIntake.spin(forward, 100, percent);
    lifted_intake.set(true);
    driveTo(48, -1, 100, forward);

    // Get lifted ring

    //driveFor(12, 80);
    lifted_intake.set(false);
    //wait(200, msec);

    // Reverse

    driveTo(44, -49, 100, reverse);
    ringIntake2.spinFor(reverse, 40, degrees);
    ringIntake.spin(forward, 100, percent);
    //raiseArm = createRaiseArmTask(75);

    // Get corner

    driveTo(74, -62.5, 60, forward);
    ringIntake2.spin(forward, 50, percent);
    moveLiftToAngle(251, false);
    driveFor(-8, 100);

    // Get second corner ring
    raiseArm = createRaiseArmTask(280);
    driveFor(-8, 100);
    ringIntake2.spin(forward, 100, percent);

    // Put in corner

    goal_rush_arm.set(true);
    wait(150, msec);
    driveFor(12, 100);
    turnToHeading(inertial_sensor.heading(degrees) + 165, 100);
    goal_rush_arm.set(false);
    raiseArm = createRaiseArmTask(280);
    //driveFor(12, 100);

    //driveCurve(30, 30, 0.65);
}

void Corner_Clear_Blue(void) {
    task raiseArm = createRaiseArmTask(210);

    // Grab goal

    driveFor(-getDistance(22, -22, Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos), 45);
    goal_clamp.set(true);

    // Get first ring

    ringIntake.spin(forward, 100, percent);
    driveTo(26.5, -48, 100, forward);

    // Get second ring

    driveTo(50, -50, 100, forward);

    // Get corner

    pointAt(74, -73, 100, forward);
    driveFor(26, 40);
    wait(200, msec);

    // Clear corner
    driveFor(-6, 100);
    //goal_rush_arm.set(true);
    //goal_rush_arm_clamp.set(true);
    //wait(400, msec);
    //driveFor(8, 80);

    driveFor(12, 70);
    driveFor(-6, 100);
    driveFor(12, 70);

    //lifted_intake.set(true);
    //driveFor(12, 100);
    //lifted_intake.set(false);

    //turnToHeading(255, 70);
    //goal_rush_arm.set(false);
    //goal_rush_arm_clamp.set(false);
    //driveFor(10, 100);
    driveFor(-8, 100);

    // Wallstake

    driveTo(10.5, -62, 100, forward);
    pointAt(-7.5, -72, 100, forward);
    driveFor(6.5, 100);
    raiseArm = createRaiseArmTask(130);

    // This is where you add the part to make the arm stay out for driver. I hope this comment isn't
    // foreshadowing anything, that would be funny. Please add this back. If this causes problems,
    // at least I recognized it in advance lmao.
}
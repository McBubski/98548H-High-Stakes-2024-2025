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
    wait(250, msec);
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

    driveTo(67.5, 49, 90, forward);
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
    driveTo(-80, 87, 50, forward);
    wait(200, msec);
    driveFor(-14, 100);

    // Get middle ring

    //ringIntake.stop();
    task raiseLift = task(delayRaiseIntakeButOnlyForThisSpecificAutonButRedLmao);
    driveTo(-54, 7, 100, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    raiseArm = createRaiseArmTask(120);
    turnToHeading(90, 100);
    ringIntake.spinFor(reverse, 30, degrees);
    ringIntake.spin(forward, 100, percent);
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
    task raiseArm = createRaiseArmTask(280);
    task rushArm = task(dumbArmTask);
    ringIntake1.spin(forward, 100, percent);
    ringIntake2.stop();

    // Rush and grab goal
    driveFor(31.5, 100);
    goal_rush_arm_clamp.set(true);
    //driveFor(-20, 100);
    
    double encoderStart = forwardTrackingWheel.position(turns);
    double error = -20;

    while (std::abs(error) >= 0.5) {
        double encoderChange = forwardTrackingWheel.position(turns) - encoderStart;
        double inchesMoved = encoderChange * 1.75 * M_PI; // Circumference of Wheels
        error = -20 - inchesMoved;

        //std::cout << forwardTrackingWheel.position(turns) << ", " << error << std::endl;

        leftDrive.spin(reverse, 100, percent);
        rightDrive.spin(reverse, 100, percent);

        wait(20, msec);
    }

    leftDrive.stop();
    rightDrive.stop();

    // Put on goal

    goal_rush_arm_clamp.set(false);
    goal_rush_arm.set(false);
    turnToHeading(273, 100);
    turnToHeading(273, 100);
    driveFor(-19.5, 40);
    goal_clamp.set(true);
    goal_rush_arm.set(true);
    ringIntake.spin(forward, 100, percent);
    wait(400, msec);
    ringIntake.stop();
    //ringIntake.spinFor(reverse, 50, degrees);
    //ringLiftArm.spin(reverse, 100, percent);
    //raiseArm = createRaiseArmTask(64);
    //goal_clamp.set(false);
    //driveTo(-60, -48, 70, forward);
    //ringIntake.spin(forward, 100, percent);

    driveTo(-55, -58, 50, forward);
    turnToHeading(310, 30);

    turnToHeading(0, 100);
    goal_rush_arm.set(false);
    goal_clamp.set(false);
    driveFor(4, 100);
    turnToHeading(285, 100);
    driveFor(-14, 100);

    driveTo(-19.5, -26, 45, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    //ringIntake.spin(forward, 100, percent);

    driveTo(-26, -54, 100, forward);
    //raiseArm = createRaiseArmTask(180);
//
    //turnToHeading(131, 100);//pointAt(0.75, -72, 90, forward);
    //driveFor(6, 60);
    //goalArmPos = 2;
    //ringLiftArm.spin(reverse, 20, percent);
    //wait(650, msec);
    //ringLiftArm.stop();

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
    wait(300, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

    // Grab goal

    driveTo(-17, -28, 40, reverse);
    goal_clamp.set(true);
    
    // Get lifted ring
    
    lifted_intake.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-46.5, -5, 100, forward);
    lifted_intake.set(false);
    driveFor(-12, 100);

    // Get second ring

    driveTo(-28, -50, 100, forward);

    raiseArm = createRaiseArmTask(120);

    // Get corner ring

    driveTo(-66, -70, 50, forward);
    driveFor(-8, 100);
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
    wait(700, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(280);

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
    task armTask = createRaiseArmTask(140);
    turnToHeading(45, 100);
    driveFor(8, 100);
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

    driveTo(-22, -22, 45, reverse);
    goal_clamp.set(true);

    // Get first ring

    ringIntake.spin(forward, 100, percent);
    driveTo(-25.5, -48, 100, forward);

    // Get second ring

    driveTo(-50, -50, 100, forward);

    // Get corner

    pointAt(-72, -73, 100, forward);
    driveFor(26, 40);
    wait(200, msec);

    // Clear corner
    driveFor(-6, 60);
    //goal_rush_arm_right.set(true);
    //goal_rush_arm_right_clamp.set(true);
    //wait(400, msec);
    //driveFor(8, 80);

    lifted_intake.set(true);
    driveFor(6, 40);

    //turnToHeading(105, 70);
    //goal_rush_arm_right.set(false);
    //goal_rush_arm_right_clamp.set(false);
    //driveFor(10, 100);
    driveFor(-6, 100);
    lifted_intake.set(false);

    // Wallstake

    driveTo(-9, -56, 100, forward);
    pointAt(3, -72, 100, forward);
    driveFor(5, 100);
    raiseArm = createRaiseArmTask(130);

    // This is where you add the part to make the arm stay out for driver. I hope this comment isn't
    // foreshadowing anything, that would be funny. Please add this back. If this causes problems,
    // at least I recognized it in advance lmao.
}
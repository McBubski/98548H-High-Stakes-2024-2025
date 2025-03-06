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
    task raiseArm = createRaiseArmTask(168);
    task rushArm = task(dumbArmTask2);
    ringIntake1.spin(forward, 100, percent);
    ringIntake2.stop();

    // Rush and grab goal
    driveFor(30.5, 100);
    goal_rush_arm_clamp.set(true);
   
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
    turnToHeading(95, 100);
    driveFor(-18, 30);
    goal_clamp.set(true);
    //ringIntake.spinFor(reverse, 50, degrees);
    //ringLiftArm.spin(reverse, 100, percent);
    ringIntake.spin(forward, 100, percent);
    //wait(950, msec);
    //raiseArm = createRaiseArmTask(64);
    //goal_clamp.set(false);
    driveTo(60, -48, 70, forward);

    driveTo(66, -64, 30, forward);
    ringIntake.stop();
    ringIntake1.spin(forward, 100, percent);
    //wait(200, msec);

    driveFor(-10, 100);
    goal_rush_arm.set(true);
    goal_rush_arm_clamp.set(true);
    driveFor(2, 100);
    turnToHeading(247, 100);
    goal_rush_arm.set(false);
    goal_rush_arm_clamp.set(false);

    turnToHeading(30, 100);
    goal_clamp.set(false);

    driveTo(15, -21, 60, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    //ringIntake.spin(forward, 100, percent);

    driveTo(22, -40, 100, forward);
    //raiseArm = createRaiseArmTask(125);

    //turnToHeading(225, 100);//
    pointAt(6, -72, 90, forward);
    driveFor(17, 40);
    raiseArm = createRaiseArmTask(110);

    //pointAt(71, -0.5, 100, forward);
    //ringLiftArm.spin(reverse, 100, percent);
    //driveFor(2, 100);

    // Get next goal

    //ringIntake2.spin(reverse, 50, percent);
    //driveTo(21.5, -13.5, 55, reverse);
    //goal_clamp.set(true);
//
    //ringIntake.spin(forward, 100, percent);
    //driveTo(64, -58, 60, forward);
    //turnToHeading(160, 100);
    //driveFor(24, 30);
//
    //// Clear corner
    //driveFor(-8, 100);
    //goal_rush_arm.set(true);
    //driveFor(3, 100);
    //turnToHeading(227, 100);
    //goal_rush_arm.set(false);
    //goal_clamp.set(false);
//
    //driveTo(24, -50, 60, reverse);
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
    wait(700, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(209);

    driveTo(20.5, 36.5, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(17, 48, 80, forward);
    wait(25, msec);

    // Grab to last ring 
    
    driveTo(11.25, 60.5, 100, forward);
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
    driveTo(58, 8, 80, forward);
    lifted_intake.set(false);

    driveFor(-6, 100);
    raiseArm = createRaiseArmTask(100);
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

    task raiseArm = createRaiseArmTask(209);

    // Grab goal

    driveTo(17, -25.5, 40, reverse);
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

    driveTo(66, -70, 60, forward);
    driveFor(-4, 100);
    driveFor(8, 100);

    // Touch bar

    driveTo(28, -50, 100, reverse);

    raiseArm = createRaiseArmTask(100);

    driveTo(23, -23, 60, forward);
    turnToHeading(315, 100);
}

void Blue_Elims(void) {
    auton_color = 1;
    // Score first ring

    //ringLiftArm.spin(reverse, 100, percent);
    //wait(800, msec);
    //ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(209);

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
    raiseArm = createRaiseArmTask(209);
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
    wait(700, msec);
    ringLiftArm.stop();
    driveFor(-6, 100);

    task raiseArm = createRaiseArmTask(209);

    driveTo(18.5 , 36, 50, reverse);
    goal_clamp.set(true);
//
    // Put on first ring

    ringIntake.spin(forward, 100, percent);
    wait(25, msec);

    // Grab third ring

    driveTo(18.5, 47.5, 80, forward);
    wait(25, msec);

    // Grab to last ring 

    driveFor(-6, 100);    
    driveTo(28, 52, 100, forward);

    // Get ring stack

    ringIntake1.spin(forward, 100, percent);
    pointAt(58.5, 10, 100, forward);
    lifted_intake.set(true);
    driveFor(getDistance(Position_Tracking.GlobalXPos, Position_Tracking.GlobalYPos, 58.5, 10), 100);

    lifted_intake.set(false);
    //ringIntake1.spin(forward, 100, percent);

    // Drop goal

    //driveFor(-8, 100);
    goal_clamp.set(false);
    //driveFor(6, 100);

    // Get next goal

    pointAt(26.5, -12.5, 100, reverse);
    ringIntake2.stop();
    driveTo(24.5, -14.5, 55, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Get final ring

    driveTo(34, -37.5, 100, forward);

    // Touch

    driveFor(-24, 100);
    task armTask = createRaiseArmTask(100);
    turnToHeading(315, 100);
    driveFor(7, 100);
}

void Positive_Elims_Blue(void) {
    //std::cout << auton_color << std::endl;
    auton_color = 2;
    ringIntake1.spin(forward, 100, percent);
    ringIntake2.stop();

    task raiseArm = createRaiseArmTask(209);

    // Grab first ring

    driveFor(28, 100);

    // Grab goal

    driveTo(26, -24, 40, reverse);
    goal_clamp.set(true);

    ringIntake.spin(forward, 100, percent);
    wait(200, msec);

    // Put arm down on ring across

    pointAt(11, -9, 100, forward);
    ringIntake.stop();
    driveTo(11, -9, 60, forward);

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
    driveTo(50, -1, 100, forward);

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

    driveTo(75, -60.5, 60, forward);
    ringIntake2.spin(forward, 50, percent);
    moveLiftToAngle(186, false);
    driveFor(-8, 100);

    // Get second corner ring
    raiseArm = createRaiseArmTask(209);
    driveFor(-8, 100);
    ringIntake2.spin(forward, 100, percent);

    // Put in corner

    goal_rush_arm.set(true);
    wait(150, msec);
    driveFor(12, 100);
    turnToHeading(inertial_sensor.heading(degrees) + 165, 100);
    goal_rush_arm.set(false);
    raiseArm = createRaiseArmTask(209);
    //driveFor(12, 100);

    //driveCurve(30, 30, 0.65);
}
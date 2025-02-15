#include "AutonPaths/skills.h"
#include "Autonomous/auton-functions.h"

// Change these values for arm position

void Skills_Auton(void) {
    task raiseArm;

    // Places ring on alliance stake, and then clamps the goal.
    ringLiftArm.spin(reverse, 100, percent);
    wait(850, msec);
    ringLiftArm.stop();
    driveFor(-24, 45);
    raiseArm = createRaiseArmTask(64);
    goal_clamp.set(true);

    // Get first ring
    ringIntake.spin(forward, 100, percent);
    driveTo(-27, -17, 100, forward);

    // Get next ring, and put it in lady brown

    driveTo(-21, -47, 100, forward);

    // Drive to align with wallstake

    pointAt(1, -58.5, 100, forward);
    raiseArm = createRaiseArmTask(99);
    driveTo(1, -58.5, 100, forward);
    ringIntake.spin(forward, 80, percent);
    wait(400, msec);
    ringIntake.spin(forward, 100, percent);

    // Put ring on wallstake

    driveFor(-4, 100);
    pointAt(-1, -71, 100, forward);
    //waitUntil(ringIntake2.torque(Nm) >= 2.2);

    leftDrive.spin(forward, 25, percent);
    rightDrive.spin(forward, 25, percent);
    wait(750, msec);
    leftDrive.stop();
    rightDrive.stop();
    ringIntake.stop();
    ringIntake.spinFor(reverse, 30, degrees);

    ringLiftArm.spin(reverse, 100, percent);
    wait(550, msec);
    ringLiftArm.stop();

    driveFor(-12, 100);
    ringIntake.spin(forward, 100, percent);

    // Get next ring

    raiseArm = createRaiseArmTask(64);
    ringIntake.spin(reverse, 100, percent);
    wait(600, msec);
    ringIntake.spin(forward, 100, percent);
    driveTo(24, -26, 100, forward);
    ringIntake.spin(forward, 100, percent);

    // Get next three

    ringIntake.spin(forward, 70, percent);
    driveTo(24, -47, 100, forward);
    ringIntake.spin(forward, 100, percent);
    driveTo(44, -50, 75, forward);
    driveTo(46, -58, 75, forward);
    wait(200, msec);

    // Drop goal
    
    pointAt(62, -62, 100, reverse);
    goal_clamp.set(false);
    driveFor(-16, 80);
    driveFor(16, 100);

    // Goal push

    //ringIntake.spin(forward, 100, percent);
    driveTo(45.5, 6, 60, reverse);
    goal_clamp.set(true);
    turnToHeading(145, 100);
    goal_clamp.set(false);

    // Grab dropped goal
    driveFor(4, 100);
    ringIntake.spin(reverse, 100, percent);
    driveTo(55, 53, 100, forward);
    turnToHeading(5, 100);
    driveFor(-20, 100);
    driveTo(34.0, 3.5, 45, reverse);
    goal_clamp.set(true);

    //Get next ring

    ringIntake.spin(forward, 100, percent);
    driveTo(19, 23.5, 100, forward);
    driveTo(-44, -44, 100, forward);
    //driveTo(-50, -50, 100, forward);

    // Get next two rings

    driveTo(-46, -68, 80, forward);
    driveFor(-18, 100);
    driveTo(-59.5, -54.5, 100, forward);

    // Drop goal in corner

    turnToHeading(30, 100);
    driveFor(-14, 100);
    goal_clamp.set(false);
    ringIntake.spinFor(reverse, 20, degrees, false);
    driveFor(25, 100);
    driveTo(-50, -8, 100, reverse);

    // Grab goal

    //pointAt(-51, 7, 100, reverse);
    driveTo(-50.5, 18, 50, reverse);
    //driveTo(-52, 22, 20, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-30, 10, 100, forward);
    driveTo(0, 40, 100, forward);
    driveTo(38, 39, 100, forward);

    // Get second wallstake

    driveTo(-4, 38, 100, reverse);

    ringIntake.spin(forward, 100, percent);

    // Get next ring

    //raiseArm = createRaiseArmTask(64);

    // Get next three rings

    //driveTo(-70, 29, 45, forward);    
    turnToHeading(270, 100);
    turnToHeading(270, 100);
    driveFor(80, 45);

    // Drop goal in corner

    turnToHeading(160, 100);
    driveFor(-20, 100);
    goal_clamp.set(false);
    ringIntake.spinFor(reverse, 20, degrees, false);
    driveFor(12, 100);

    // Hang

    raiseArm = createRaiseArmTask(150);
    //driveTo(-24, 24, 100, reverse);
    driveTo(-7.6, -1.5, 90, reverse);

}

void New_Skills_Auton(void) {
    // Put ring on alliance stake
    ringLiftArm.spin(reverse, 100, percent);
    wait(350, msec);

    // Grab first goal
    task raiseArm = createRaiseArmTask(86);
    driveFor(-4, 100);
    driveTo(-46, -28, 40, reverse);
    goal_clamp.set(true);

    // Grab first ring
    ringIntake.spin(forward, 100, percent);
    driveTo(-30, -17, 100, forward);

    // Grab next ring
    driveTo(26, -42, 100, forward);
    ringIntake.spin(forward, 90, percent);
    raiseArm = createRaiseArmTask(100);

    // Line up to wall stake
    driveTo(-1, -40, 100, reverse);
    ringIntake.spin(forward, 100, percent);

    // Score wallstake
    turnToHeading(170, 100);
    ringIntake.spinFor(reverse, 30, degrees);
    raiseArm = createRaiseArmTask(150);
    driveFor(40, 50);
    ringIntake.spin(forward, 100, percent);
    ringLiftArm.spin(reverse, 100, percent);
    leftDrive.spin(forward, 25, percent);
    rightDrive.spin(forward, 25, percent);
    wait(600, msec);
    ringLiftArm.stop();
    leftDrive.stop();
    rightDrive.stop();
    raiseArm = createRaiseArmTask(86);

    // Get next three rings

    driveFor(-12, 100);
    driveTo(-53.5, -56, 60, forward);

    // Get last ring

    driveTo(-43, -62, 100, forward);

    // Drop goal
    
    turnToHeading(70, 100);
    driveFor(-10, 100);
    goal_clamp.set(false);

    driveFor(12, 100);
}
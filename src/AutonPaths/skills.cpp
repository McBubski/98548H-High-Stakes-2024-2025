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
    raiseArm = createRaiseArmTask(207);
    goal_clamp.set(true);

    // Get first ring
    ringIntake.spin(forward, 100, percent);
    driveTo(-27, -17, 100, forward);

    // Get next ring, and put it in lady brown

    driveTo(-21, -47, 100, forward);

    // Drive to align with wallstake

    pointAt(1, -58.5, 100, forward);
    raiseArm = createRaiseArmTask(192);
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

    raiseArm = createRaiseArmTask(207);
    ringIntake.spin(reverse, 100, percent);
    wait(600, msec);
    ringIntake.spin(forward, 100, percent);
    driveTo(24, -26, 100, forward);
    ringIntake.spin(forward, 100, percent);

    // Get next three

    ringIntake.spin(forward, 70, percent);
    driveTo(26, -47, 100, forward);
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
    driveTo(47.5, 6, 60, reverse);
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
    driveTo(-48, -8, 100, reverse);

    // Grab goal

    //pointAt(-51, 7, 100, reverse);
    driveTo(-47.5, 18, 50, reverse);
    //driveTo(-52, 22, 20, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-30, 10, 100, forward);
    driveTo(0, 38.5, 100, forward);
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

    raiseArm = createRaiseArmTask(166);
    //driveTo(-24, 24, 100, reverse);
    driveTo(-7.6, -1.5, 90, reverse);

}

void New_Skills_Auton(void) {
    // Put ring on alliance stake
    ringLiftArm.spin(reverse, 100, percent);
    wait(350, msec);

    // Grab first goal
    task raiseArm = createRaiseArmTask(209);
    driveFor(-4, 100);
    driveTo(-44.5, -29, 40, reverse);
    goal_clamp.set(true);

    // Grab first ring
    ringIntake.spin(forward, 100, percent);
    driveTo(-30, -17, 100, forward);

    // Grab next ring
    driveTo(26, -40, 100, forward);
    ringIntake.spin(forward, 90, percent);
    raiseArm = createRaiseArmTask(193);

    // Line up to wall stake
    driveTo(-1.5, -40, 100, reverse);
    ringIntake.spin(forward, 100, percent);

    // Score wallstake
    turnToHeading(172, 100);
    ringIntake.spinFor(reverse, 30, degrees);
    raiseArm = createRaiseArmTask(155);
    driveFor(30, 50);

    ringIntake.spin(forward, 100, percent);
    ringLiftArm.spin(reverse, 100, percent);
    leftDrive.spin(forward, 15, percent);
    rightDrive.spin(forward, 15, percent);
    wait(400, msec);
    leftDrive.stop();
    rightDrive.stop();

    // Get next three rings

    driveFor(-12, 100);
    ringLiftArm.stop();
    raiseArm = createRaiseArmTask(209);
    driveTo(-55.5, -62.5, 60, forward);

    // Get last ring

    driveTo(-40, -62, 90, forward);

    // Drop goal
    
    pointAt(48, -52, 100, forward);
    driveFor(-12, 100);
    goal_clamp.set(false);

    // Grab next ring

    ringIntake2.stop();
    driveTo(45, -48, 100, forward);
    goal_rush_arm.set(true);

    // Grab second goal

    driveTo(57, -20, 35, reverse);
    //ringIntake.stop();
    goal_rush_arm.set(false);
    goal_clamp.set(true);

    // Put goal in corner

    driveFor(24, 100);
    turnToHeading(300, 100);
    goal_clamp.set(false);
    driveFor(-18, 60);
    driveFor(12, 100);

    // Grab third goal

    driveTo(44, 4.5, 50, reverse);
    goal_clamp.set(true);

    // Line up with alliance stake

    turnToHeading(93, 100);
    raiseArm = createRaiseArmTask(193);
    ringIntake.spin(forward, 100, percent);
    driveFor(24, 50);

    // Alliance Stake Macro

    ringLiftArm.spin(reverse, 100, percent);
    ringIntake2.spinFor(reverse, 25, degrees, false);
    driveFor(-7.5, 100);
    wait(150, msec);
    ringLiftArm.stop();
}
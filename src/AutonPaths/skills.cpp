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

    pointAt(0, -57.5, 100, forward);
    raiseArm = createRaiseArmTask(101
    );
    driveTo(0, -57.5, 100, forward);
    ringIntake.spin(forward, 80, percent);
    wait(400, msec);
    ringIntake.spin(forward, 100, percent);

    // Put ring on wallstake

    driveFor(-2.5, 100);
    pointAt(-0.5, -71, 100, forward);
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
    driveTo(24, -24, 100, forward);
    ringIntake.spin(forward, 100, percent);

    // Get next three

    ringIntake.spin(forward, 70, percent);
    driveTo(24, -44.5, 100, forward);
    ringIntake.spin(forward, 100, percent);
    driveTo(44, -46.5, 75, forward);
    driveTo(46, -54, 75, forward);
    wait(200, msec);

    // Drop goal
    
    pointAt(62, -62, 100, reverse);
    goal_clamp.set(false);
    driveFor(-16, 80);
    driveFor(16, 100);

    // Goal push

    //ringIntake.spin(forward, 100, percent);
    driveTo(44, 6, 60, reverse);
    goal_clamp.set(true);
    turnToHeading(145, 100);
    goal_clamp.set(false);

    // Grab dropped goal

    driveFor(4, 100);
    ringIntake.spin(reverse, 100, percent);
    driveTo(56, 52, 100, forward);
    turnToHeading(5, 100);
    driveFor(-20, 100);
    driveTo(34.0, 2.5, 45, reverse);
    goal_clamp.set(true);

    //Get next ring

    ringIntake.spin(forward, 100, percent);
    driveTo(19, 21, 100, forward);
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
    driveFor(24, 100);
    driveTo(-49.5, -8, 100, reverse);

    // Grab goal

    //pointAt(-51, 7, 100, reverse);
    driveTo(-49, 14, 50, reverse);
    //driveTo(-52, 22, 20, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);
    driveTo(-30, 6.5, 100, forward);
    driveTo(0, 30, 100, forward);
    driveTo(36, 36, 100, forward);

    // Get second wallstake

    driveTo(-4, 34, 100, reverse);
   //raiseArm = createRaiseArmTask(101);
   //driveTo(-2.5, 56, 70, forward);
   //waitUntil(ringIntake2.torque(Nm) >= 2);
   //wait(250, msec);
   //ringIntake.spin(forward, 80, percent);

   //// Put ring on wallstake

   ////pointAt(-4.5, 71, 100, forward);

   //leftDrive.spin(forward, 40, percent);
   //rightDrive.spin(forward, 40, percent);
   //wait(400, msec);
   //leftDrive.stop();
   //rightDrive.stop();
   //ringIntake.spinFor(reverse, 20, degrees);

   //moveLiftToAngle(214, true);

   //driveFor(-16, 100);
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
    goal_clamp.set(false);
    driveFor(-20, 100);
    ringIntake.spinFor(reverse, 20, degrees, false);
    driveFor(12, 100);

    // Hang

    raiseArm = createRaiseArmTask(150);
    //driveTo(-24, 24, 100, reverse);
    driveTo(-6.6, -0.5, 90, reverse);


//
    //ringIntake.spin(forward, 100, percent);
    //wait(300, msec);
    //ringIntake.stop();
////
    ////// Get next goal
////
    //driveFor(13, 100);
    //driveTo(-49, -20, 35, reverse);
    //goal_clamp.set(true);
//
    //// Get first ring
    //ringIntake.spin(forward, 100, percent);
    //driveTo(-24, -18, 80, forward);
//
    //// Get next ring
    //driveTo(-2, -56, 100, forward);
//
    //driveTo(1, -47, 100, reverse);
//
    //ringIntake.spin(forward, 100, percent);
    //driveTo(-84, -47, 45, forward);
//
    //// Get final ring
    //turnToHeading(225, 100);
    //driveFor(-6, 100);
    //driveTo(-50, -60, 100, forward);
//
    //// Set goal in corner
    //driveTo(-64, -68, 100, reverse);
    //ringIntake.stop();
    //ringIntake.spinFor(-100, degrees, false);
    //goal_clamp.set(false);
    //driveTo(-48, -46, 100, forward);
//
    //// Get second goal
    //
    //driveTo(-46, 12, 80, reverse);
    //driveTo(-46, 34, 20, reverse);
    //goal_clamp.set(true);
//
    //// Get first ring
    //ringIntake.spin(forward, 100, percent);
    //driveTo(-20, 22.5, 80, forward);
//
    //// Drive to wallstake
//
    //pointAt(0, 58, 100, forward);
    //driveTo(0, 58, 100, forward);
//
    ////driveTo(-3, 62.5, 80, forward);
    //moveLiftToAngle(203, false);
    //waitUntil(ringIntake.torque(Nm) >= 2);
    //wait(200, msec);
    //pointAt(0, 70, 100, forward);
    ////pointAt(1.0, 70, 100, forward);
    //driveFor(7, 100);
    //ringIntake.stop();
    //ringIntake1.spinFor(reverse, 20, degrees);
    //moveLiftToAngle(95, true);
//
    //// Reverse
    //moveLiftToAngle(220, false);
    //ringIntake1.spin(reverse, 50, percent);
    //driveTo(0, 50, 100, reverse);
    //ringIntake.spin(forward, 100, percent);
//
    //// Get next two rings
    //driveTo(-66, 54, 60, forward);
//
    //// Get last ring
    //turnToHeading(290, 100);
    //driveFor(-10, 100);
    //driveTo(-50, 62, 100, forward);
//
    //// Drop off in corner
//
    //driveTo(-64, 68, 100, reverse);
    //ringIntake.stop();
    //ringIntake.spinFor(-100, degrees, false);
    //goal_clamp.set(false);
    //driveFor(8, 100);
//
    //// Wallstake
//
    ////ringIntake.spin(forward, 100, percent);
    //driveTo(0, 40, 100, forward);
    ////moveLiftToAngle(201, false);
    ////driveTo(0, 60, 60, forward);
    ////turnToHeading(0, 100);
//
    //// Intakes until torque spike, indicating the ring is in fully
    ////waitUntil(ringIntake.torque(Nm) >= 2);
    ////wait(300, msec);
    ////ringIntake.stop();
//
    ////moveLiftToAngle(103, true);
    ////moveLiftToAngle(220, false);
//
    //// Get next ring
//
    ////driveFor(-4, 100);
    //ringIntake.spin(forward, 100, percent);
    //driveTo(31, 16, 80, forward);
    //ringIntake.stop();
    //ringIntake2.spin(forward, 100, percent);
//
    //// Get next goal
//
    //pointAt(48, -4.5, 100, reverse);
    //driveTo(48, -4.5, 40, reverse);
    //goal_clamp.set(true);
    //ringIntake.spin(forward, 100, percent);
//
    //// Drop goal
//
    //wait(300, msec);
    //turnToHeading(110, 100);
    //driveFor(-4, 100);
    //ringIntake.stop();
    //goal_clamp.set(false);
//
    //// Shove in corner
//
    //driveTo(69.5, 49.5, 100, forward);
//
    //// Last shove
//
    //driveTo(50, 0, 100, reverse);
    //driveTo(72, -66, 100, reverse);
//
    //driveFor(6, 100);
//
    //// Elevate
//
    //driveTo(-6, -5, 100, forward);
    //corner_arm.set(true);
    //turnToHeading(312, 100);
    //driveFor(-25, 80);
    //driveFor(1.5, 100);
    //ringIntake.spin(reverse, 100, percent);
    //wait(5000, msec);
    //ringIntake.stop();
    //driveFor(-4, 100);
    //driveFor(12, 100);
}
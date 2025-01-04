#include "AutonPaths/skills.h"
#include "Autonomous/auton-functions.h"

// Change these values for arm position

void Skills_Auton(void) {
    auton_color = 2;
    task raiseArm;

    // Places ring on alliance stake, and then clamps the goal.
    moveLiftToAngle(250, false);
    driveFor(-20, 50);
    goal_clamp.set(true);

    // Get first ring
    raiseArm = createRaiseArmTask(45);
    ringIntake.spin(forward, 100, percent);
    driveTo(-26, -22, 100, forward);

    // Get next ring, and put it in lady brown

    driveTo(-23, -46, 100, forward);

    // Drive to align with wallstake

    driveTo(-2, -56, 100, forward);
    raiseArm = createRaiseArmTask(72);
    wait(400, msec);
    waitUntil(ringIntake2.torque(Nm) >= 2.2);
    wait(150, msec);
    ringIntake.spinFor(reverse, 50, degrees);
    raiseArm = createRaiseArmTask(125);
    
    // Put ring on wallstake

    pointAt(3, -71, 100, forward);

    leftDrive.spin(forward, 40, percent);
    rightDrive.spin(forward, 40, percent);
    wait(600, msec);
    leftDrive.stop();
    rightDrive.stop();

    moveLiftToAngle(205, true);

    driveFor(-12, 100);
    ringIntake.spin(forward, 100, percent);

    // Get next ring

    raiseArm = createRaiseArmTask(45);
    driveTo(25.5, -22.5, 100, forward);

    // Get next three

    driveTo(0, -40, 90, reverse);
    driveTo(48, -36, 75, forward);
    driveTo(48, -60, 100, forward);
    wait(200, msec);

    // Drop goal
    
    pointAt(66, -66, 100, reverse);
    goal_clamp.set(false);
    driveFor(-16, 80);
    driveFor(36, 100);

    // Goal push

    driveTo(48, -4, 60, reverse);
    driveTo(36, 6, 100, reverse);

    driveTo(70, 62, 100, forward);
    driveTo(26, 16, 60, reverse);
    goal_clamp.set(true);


    //// Put ring on alliance stake
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
#include "AutonPaths/skills.h"
#include "Autonomous/auton-functions.h"

// Change these values for arm position

void Skills_Auton(void) {
    //// Put ring on alliance stake
//
    ringIntake.spin(forward, 100, percent);
    wait(300, msec);
    ringIntake.stop();
//
    //// Get next goal
//
    driveFor(13, 100);
    driveTo(-48.5, -20, 35, reverse);
    goal_clamp.set(true);

    // Get first ring
    ringIntake.spin(forward, 100, percent);
    driveTo(-24, -18, 80, forward);

    // Get next ring
    driveTo(-2, -56, 100, forward);

    driveTo(1, -47, 100, reverse);
    // Pick up wallstake ring
    //driveTo(1.25, -42, 80, reverse);
    //moveLiftToAngle(201, false);
    //driveTo(1.25, -62, 60, forward);
    //turnToHeading(180, 100);

    // Intakes until torque spike, indicating the ring is in fully

    //waitUntil(ringIntake.torque(Nm) >= 2);
    //wait(300, msec);
    //ringIntake.stop();
//
    //moveLiftToAngle(103, true);
    //moveLiftToAngle(220, false);

    // Get next three rings
    //driveFor(-12, 100);
    ringIntake.spin(forward, 100, percent);
    driveTo(-94, -47, 45, forward);

    // Get final ring
    turnToHeading(225, 100);
    driveFor(-6, 100);
    driveTo(-50, -60, 100, forward);

    // Set goal in corner
    driveTo(-64, -68, 100, reverse);
    ringIntake.stop();
    ringIntake.spinFor(-100, degrees, false);
    goal_clamp.set(false);
    driveTo(-48, -46, 100, forward);

    // Get second goal

    // UNCOMMENT ABOVE

    
    driveTo(-46, 12, 80, reverse);
    driveTo(-46, 34, 20, reverse);
    goal_clamp.set(true);

    // Get first ring
    ringIntake.spin(forward, 100, percent);
    driveTo(-20, 21.5, 80, forward);

    // Drive to wallstake

    driveTo(0.5, 59.5, 100, forward);
    moveLiftToAngle(201, false);

    //driveTo(-3, 62.5, 80, forward);
    pointAt(0, 70.5, 80, forward);
    waitUntil(ringIntake.torque(Nm) >= 2);
    wait(200, msec);
    ringIntake.stop();
    ringIntake.spinFor(reverse, 100, degrees);
    moveLiftToAngle(103, true);
    moveLiftToAngle(220, false);

    // Reverse
    driveTo(0, 50, 100, reverse);
    ringIntake.spin(forward, 100, percent);

    driveTo(-30, 52, 100, forward);

    // Get next two rings
    driveTo(-74, 52, 40, forward);

    // Get last ring
    turnToHeading(290, 100);
    driveFor(-10, 100);
    driveTo(-50, 62, 100, forward);

    // Drop off in corner

    driveTo(-64, 68, 100, reverse);
    ringIntake.stop();
    ringIntake.spinFor(-100, degrees, false);
    goal_clamp.set(false);
    driveFor(8, 100);

    // Wallstake

    //ringIntake.spin(forward, 100, percent);
    driveTo(0, 40, 100, forward);
    //moveLiftToAngle(201, false);
    //driveTo(0, 60, 60, forward);
    //turnToHeading(0, 100);

    // Intakes until torque spike, indicating the ring is in fully
    //waitUntil(ringIntake.torque(Nm) >= 2);
    //wait(300, msec);
    //ringIntake.stop();

    //moveLiftToAngle(103, true);
    //moveLiftToAngle(220, false);

    // Get next ring

    //driveFor(-4, 100);
    ringIntake.spin(forward, 100, percent);
    driveTo(31, 16, 80, forward);
    ringIntake.stop();
    ringIntake2.spin(forward, 100, percent);

    // Get next goal

    driveTo(52, -8.5, 40, reverse);
    goal_clamp.set(true);
    ringIntake.spin(forward, 100, percent);

    // Drop goal

    wait(300, msec);
    turnToHeading(40, 100);
    driveFor(-4, 100);
    ringIntake.stop();
    goal_clamp.set(false);

    // Shove in corner

    driveTo(66.5, 47.5, 100, forward);

    // Last shove

    driveTo(50, 0, 100, reverse);
    driveTo(74, -68, 100, reverse);

    driveFor(6, 100);

    // Elevate

    driveTo(-3, 1, 100, forward);
    corner_arm.set(true);
    turnToHeading(312, 100);
    driveFor(-23, 80);
    //driveFor(-4, 100);
    //driveFor(12, 100);


    // SKILLS

    // Spin first ring onto alliance stake
    //ringIntake.spin(forward, 100, percent);
    //wait(400, msec);
    //ringIntake.stop();
//
    //ringLift.spinFor(forward, 150, degrees, false);
////
    //// Get first goal
    //driveFor(16, 100);
    //ringLift.spinFor(reverse, 150, degrees, false);
    //driveTo(-44, 23, 30, reverse);
    //goal_clamp.set(true);
//
    //// Gets rings
//
    //// Ring 1
    //ringIntake.spin(forward, 80, percent);
    //turnToHeading(85, 100);
    //driveFor(24, 100);
//
    //// Ring 2
//
    //driveTo(2, 52, 100, forward);
//
    //// Ring 3
//
    //driveTo(-24, 48, 100, forward);
//
    //// Rings 4 & 5
//
    //driveTo(-60, 46, 35, forward);
//
    //wait(1400, msec);
//
    //// Ring 6
//
    //driveFor(-30, 100);
//
    //ringLift.spinFor(reverse, 150, degrees, false);
//
    //driveTo(-54, 58, 100, forward);
//
    //wait(500, msec);
//
    //// Corner
//
    //turnToHeading(125, 100);
    //driveFor(-22, 100);
    //ringIntake.spinFor(reverse, 50, degrees, false);
    //goal_clamp.set(false);
//
    //driveFor(8, 100);
//
    //// Get second goal
//
    //driveTo(-42.5, 24, 100, forward);
    //pointAt(-42.5, -22, 100, reverse);
    //driveTo(-42.5, -22, 50, reverse);
    //goal_clamp.set(true);
//
    //// Ring 1
//
    //ringIntake.spin(forward, 80, percent);
////
    //driveTo(-19, -18, 100, forward);
////
//////
    ////// Ring 2
//////
    //driveTo(-1, -50, 100, forward);
//////
    //////// Ring 3
//////
    //driveTo(-19.5, -45, 100, forward);
//////
    //////// Rings 4 & 5
//////
    //driveTo(-55.5, -43.5, 35, forward);
//////
    //wait(1000, msec);
//////
    ////// Ring 6
//////
    //driveFor(-30, 100);
//////
    //driveTo(-48, -58, 100, forward);
    //wait(500, msec);
////
    //////
    ////// Corner
//////
    //turnToHeading(65, 100);
    //driveFor(-24, 100);
    //ringIntake.spinFor(reverse, 50, degrees, false);
    //goal_clamp.set(false);
    //driveFor(12, 100);
//
    //// Get third goal (rip)
//
    //driveTo(0, -48, 100, forward);
    //driveTo(54, 0, 100, forward);
    ////driveTo(48.5, -27, 100, forward);
//
    //turnToHeading(330, 100);
    //driveFor(-60, 100);
//
    ////pointAt(55.5, -26, 100, reverse);
    ////driveTo(57.5, -24, 40, reverse);
//
    ////goal_clamp.set(true);
////
    ////driveTo(60, -52, 100, reverse);
////
    ////goal_clamp.set(false);
    //
    //driveFor(8, 100);
//
//
    //// Last goal (FULL SEND)
//
    //driveTo(66, 60, 100, reverse);
//
    //goal_clamp.set(false);
//
    //driveFor(12, 100);
    
////
    //driveFor(8, 100);
//
    //// Elevate
//
    //while (lift_potentiometer.angle(degrees) >= 198.0) {
    //    ringLift.spin(forward, 50, percent);
    //    wait(20, msec);
    //}
    //ringLift.setStopping(hold);
    //ringLift.stop();
//
    //driveTo(0, 0, 100, forward);
    //ringLift.spinFor(-200, degrees);
}
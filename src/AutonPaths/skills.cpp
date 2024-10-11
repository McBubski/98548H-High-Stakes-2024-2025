#include "AutonPaths/skills.h"
#include "Autonomous/auton-functions.h"

void Skills_Auton(void) {
    // SKILLS

    // Spin first ring onto alliance stake
    ringIntake.spin(forward, 100, percent);
    wait(400, msec);
    ringIntake.stop();

    ringLift.spinFor(forward, 150, degrees, false);
//
    // Get first goal
    driveFor(16, 100);
    ringLift.spinFor(reverse, 150, degrees, false);
    driveTo(-46.5, 23, 30, reverse);
    goal_clamp.set(true);

    // Gets rings

    // Ring 1
    ringIntake.spin(forward, 80, percent);
    turnToHeading(85, 100);
    driveFor(24, 100);

    // Ring 2

    driveTo(2, 52, 100, forward);

    // Ring 3

    driveTo(-24, 48, 100, forward);

    // Rings 4 & 5

    driveTo(-60, 46, 55, forward);

    wait(1400, msec);

    // Ring 6

    driveFor(-30, 100);

    ringLift.spinFor(reverse, 150, degrees, false);

    driveTo(-54, 58, 100, forward);

    wait(500, msec);

    // Corner

    turnToHeading(125, 100);
    driveFor(-22, 100);
    ringIntake.spinFor(reverse, 50, degrees, false);
    goal_clamp.set(false);

    driveFor(8, 100);

    // Get second goal

    driveTo(-46.5, 24, 100, forward);
    pointAt(-46.5, -22, 100, reverse);
    driveTo(-46.5, -22, 50, reverse);
    goal_clamp.set(true);

    // Ring 1

    ringIntake.spin(forward, 80, percent);
//
    driveTo(-19, -21, 100, forward);
//
////
    //// Ring 2
////
    driveTo(-1, -52, 100, forward);
////
    ////// Ring 3
////
    driveTo(-19.5, -45, 100, forward);
////
    ////// Rings 4 & 5
////
    driveTo(-55.5, -43.5, 55, forward);
////
    wait(1000, msec);
////
    //// Ring 6
////
    driveFor(-30, 100);
////
    driveTo(-48, -58, 100, forward);
    wait(500, msec);
//
    ////
    //// Corner
////
    turnToHeading(65, 100);
    driveFor(-24, 100);
    ringIntake.spinFor(reverse, 50, degrees, false);
    goal_clamp.set(false);
    driveFor(12, 100);

    // Get third goal (rip)

    driveTo(0, -48, 100, forward);
    driveTo(48.5, -27, 100, forward);

    pointAt(55.5, -22, 100, reverse);
    driveTo(57.5, -20, 40, reverse);

    goal_clamp.set(true);

    driveTo(60, -52, 100, reverse);

    goal_clamp.set(false);
    
    driveFor(8, 100);


    // Last goal (FULL SEND)

    driveTo(60, 60, 100, reverse);

    goal_clamp.set(false);

    driveFor(12, 100);
    
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
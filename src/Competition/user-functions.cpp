#include "Competition/user-functions.h"

using namespace vex;

bool slowIntake = false;
bool liftRaising = false;

void initializeUserControl(void) {
    // Sets drivetrain stopping to coast
    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);

    // Sets lift stopping to hold
    ringLift.setStopping(hold);

    // Sets intake stopping to brake
    ringIntake.setStopping(brake);

    // Connects controller inputs to functions
    Controller.ButtonDown.pressed(toggleGoalClamp);
    Controller.ButtonRight.pressed(toggleCornerArm);
    Controller.ButtonB.pressed(raiseArmToElevationHeight);
}

void toggleGoalClamp(void) {
    goal_clamp.set(!goal_clamp.value());
}

void toggleCornerArm(void) {
  corner_arm.set(!corner_arm.value());
}

void toggleIntakeSpeed(void) {
  slowIntake = !slowIntake;
}

void raiseArmToElevationHeight(void) {
  liftRaising = true;
  while (lift_potentiometer.angle(degrees) >= 200.0) {
    ringLift.spin(forward, 50, percent);
    wait(20, msec);
  }
  liftRaising = false;
  ringLift.stop();
}
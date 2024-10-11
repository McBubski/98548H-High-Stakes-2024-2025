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
    Controller.ButtonY.pressed(raiseArmToWallStakeHeight);
    
    // Macro

    Controller.ButtonX.pressed(autoSkillsStart);

    corner_arm.set(false);
}

void autoSkillsStart(void) {

    std::cout << "boop!" << std::endl;
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
  if (liftRaising == true) {
    return;
  } else {
    liftRaising = true;
  }

  while (lift_potentiometer.angle(degrees) >= 196.5) {
    ringLift.spin(forward, 100, percent);
    wait(20, msec);
  }
  liftRaising = false;
  ringLift.stop();
}

void raiseArmToWallStakeHeight(void) {
  if (liftRaising == true) {
    return;
  } else {
    liftRaising = true;
  }

  while (lift_potentiometer.angle(degrees) >= 205.0) {
    ringLift.spin(forward, 100, percent);
    wait(20, msec);
  }
  liftRaising = false;
  ringLift.stop();
}
#include "Competition/user-functions.h"

using namespace vex;

bool slowIntake = false;
bool liftRaising = false;

int goalArmPos = 0;

void initializeUserControl(void) {
    // Sets drivetrain stopping to coast
    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);

    // Sets lift stopping to hold
    ringLift.setStopping(hold);
    ringLiftArm.setStopping(hold);

    // Sets intake stopping to brake
    ringIntake.setStopping(brake);

    // Connects controller inputs to functions
    Controller.ButtonDown.pressed(toggleGoalClamp);
    Controller.ButtonRight.pressed(toggleCornerArm);
    Controller.ButtonL2.pressed(cycleRingArmTarget);
    Controller.ButtonL1.pressed(lowerRingArm);
    
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

void cycleRingArmTarget(void) {
  goalArmPos++;

  if (goalArmPos > 2) {
    goalArmPos = 1;
  }
}

void lowerRingArm(void) {
  goalArmPos = 0;
}
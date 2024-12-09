#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"

using namespace vex;

bool slowIntake = false;
bool liftRaising = false;

int goalArmPos = 0;

int previousAutonColor = 0;

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
    Controller.ButtonB.pressed(toggleColorSorter);
    Controller.ButtonL2.pressed(cycleRingArmTarget);
    Controller.ButtonL1.pressed(lowerRingArm);

    previousAutonColor = auton_color;
    auton_color = 2;
    
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

  if (corner_arm.value() == false) {
    goalArmPos = 0;
    ringLiftArm.setStopping(coast);
  }
}

void toggleIntakeSpeed(void) {
  slowIntake = !slowIntake;
}

void cycleRingArmTarget(void) {
  ringLiftArm.setStopping(hold);
  goalArmPos++;

  if (goalArmPos > 2) {
    goalArmPos = 1;
  }
}

void lowerRingArm(void) {
  goalArmPos = 0;
}

void toggleColorSorter(void) {
  Controller.rumble(".");
  if (auton_color == previousAutonColor) {
    auton_color = 2;
  } else {
    auton_color = previousAutonColor;
  }
}
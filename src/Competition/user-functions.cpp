#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"

using namespace vex;

bool slowIntake = false;
bool liftRaising = false;
bool armOverride = false;

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
    Controller.ButtonRight.pressed(toggleElevation);
    Controller.ButtonL2.pressed(cycleRingArmTarget);
    Controller.ButtonL1.pressed(lowerRingArm);
    Controller.ButtonA.pressed(toggleColorSorter);
    Controller.ButtonUp.pressed(toggleLiftedIntake);

    color_sort_override = true;
    
    // Macro

    //Controller.ButtonX.pressed(autoSkillsStart);
}

void autoSkillsStart(void) {

    std::cout << "boop!" << std::endl;
}

void toggleGoalClamp(void) {
    goal_clamp.set(!goal_clamp.value());
}

void toggleLiftedIntake(void) {
  lifted_intake.set(!lifted_intake.value());
}

void toggleElevation(void) {
  goalArmPos = 2;
}

void toggleIntakeSpeed(void) {
  slowIntake = !slowIntake;
}

void cycleRingArmTarget(void) {
  if (armOverride == true) {
    armOverride = false;
    goalArmPos = 1;
    return;
  }

  armOverride = false;

  ringLiftArm.setStopping(hold);
  goalArmPos++;

  if (goalArmPos > 2) {
    goalArmPos = 1;
  }
}

void toggleColorSorter(void) {
  color_sort_override = !color_sort_override;
}

void lowerRingArm(void) {
  armOverride = false;
  goalArmPos = 0;
}
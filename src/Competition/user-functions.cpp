#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"
#include "Autonomous/autonomous.h"

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

    Controller.ButtonLeft.pressed(toggleGoalRushArm);
    Controller.ButtonX.pressed(toggleGoalRushArmClamp);

    color_sort_override = true;
    
    // Macro

    Controller.ButtonB.pressed(setRingArmTargetToAllianceStake);
}

void autoSkillsStart(void) {

    std::cout << "boop!" << std::endl;
}

void toggleGoalClamp(void) {
    goal_clamp.set(!goal_clamp.value());
}

void toggleGoalRushArm(void) {
  goal_rush_arm.set(!goal_rush_arm.value());
}

void toggleGoalRushArmClamp(void) {
  goal_rush_arm_clamp.set(!goal_rush_arm_clamp.value());
}

void toggleLiftedIntake(void) {
  lifted_intake.set(!lifted_intake.value());
}

void toggleElevation(void) {
  armOverride = false;
  goalArmPos = 4;
}

void toggleIntakeSpeed(void) {
  slowIntake = !slowIntake;
}

void setRingArmTargetToAllianceStake(void) {
  
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
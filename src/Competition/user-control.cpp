#include "Competition/user-control.h"
#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"
#include "Autonomous/autonomous.h"

#include <cmath>

using namespace vex;

bool intakeSpinning = false;
bool skillsSetupHasRun = false;

// Change these values for arm position

float armPositions[5] = {
  84,    // Rest position
  101,    // First ring position
  222,   // Wall stake position
  275,   // Alliance stake position
  150     // Hang position
};

void usercontrol(void) {
  // Initializes robot before driving
  initializeUserControl();

  while (1) {
    wait(20, msec);
  
    // Stick position returned as a percentage
    float leftStickPos = Controller.Axis3.position();
    float rightStickPos = Controller.Axis2.position();

    // Motor speed mapped directly to stick position
    leftDrive.spin(forward, leftStickPos, percent);
    rightDrive.spin(forward, rightStickPos, percent);

    // PID for arm lift

    if (Controller.ButtonB.pressing()) {
      armOverride = true;
      ringLiftArm.spin(reverse, 100, percent);
    } else if (Controller.ButtonY.pressing()) {
      if (auton_path == 5) {
        ringIntake2.spinFor(reverse, 25, degrees, false);
        driveFor(-7.5, 100);
        ringLiftArm.spin(reverse, 100, percent);
        wait(400, msec);
        ringLiftArm.stop();
      } else {
        armOverride = true;
        ringLiftArm.spin(forward, 100, percent);
      }
    } else {
      if (armOverride) {
        ringLiftArm.setStopping(hold);
        ringLiftArm.stop();
      }
    } 

    std::cout << goalArmPos << ", " << previousGoalArmPos << std::endl;

    if (!armOverride) {
      float currentArmAngle = lift_arm_potentiometer.angle(degrees);
      float goalArmAngle = armPositions[goalArmPos];
      float error = goalArmAngle - currentArmAngle;

      if (std::abs(error) >= 1.0) {
        if (goalArmPos == 2) {
          ringLiftArm.spin(reverse, error * 0.7, percent);
        } if (goalArmPos == 1) {
          if (previousGoalArmPos == 2) {
            ringLiftArm.spin(reverse, error * 0.53, percent);
          } else if (previousGoalArmPos == 0) {
            ringLiftArm.spin(reverse, error * 0.45, percent);
          }
        } else {
          ringLiftArm.spin(reverse, error * 0.55, percent);
        }
      } else {
        ringLiftArm.stop();
      }
    }

    // Sets intakeSpeed to however fast it should be

    // Spins intake depending on direction and speed

    if (!intake_interrupt) {
      if (Controller.ButtonR1.pressing()) {
        ringIntake.spin(forward, 100, percent);
        intakeSpinning = true;
      } else if (Controller.ButtonR2.pressing()) {
        ringIntake.spin(reverse, 100, percent);
        intakeSpinning = true;
      } else {
        ringIntake.stop();
        intakeSpinning = false;
      }
    }
  }
}


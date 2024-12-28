#include "Competition/user-control.h"
#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"

#include <cmath>

using namespace vex;

bool intakeSpinning = false;
bool skillsSetupHasRun = false;

// Change these values for arm position

float armPositions[3] = {
  45,    // Rest position
  75,    // First ring position
  205      // Wall stake position
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
      armOverride = true;
      ringLiftArm.spin(forward, 100, percent);
    } else {
      if (armOverride) {
        ringLiftArm.stop();
      }
    }

    if (!armOverride) {
      float currentArmAngle = lift_arm_potentiometer.angle(degrees);
      float goalArmAngle = armPositions[goalArmPos];
      float error = goalArmAngle - currentArmAngle;

      if (std::abs(error) >= 1.0) {
        ringLiftArm.spin(reverse, error * 2, percent);
      } else {
        ringLiftArm.stop();
      }
    }

    // Sets intakeSpeed to however fast it should be

    // Spins intake depending on direction and speed

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

    if (Controller.ButtonX.pressing()) {  
        if (!skillsSetupHasRun) {
          skillsSetupHasRun = true;
          //ringLift.spinFor(forward, 200, degrees, false);
          ringIntake.spin(forward, 100, percent);
          wait(400, msec);
          ringIntake.stop();
          wait(400, msec);
          ringLift.spinFor(reverse, 200, degrees, true);
        }
    }
  }
}


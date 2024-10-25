#include "Competition/user-control.h"
#include "Competition/user-functions.h"

#include <cmath>

using namespace vex;

bool intakeSpinning = false;
bool skillsSetupHasRun = false;

// Change these values for arm position

float armPositions[3] = {
  199,    // Rest position
  175,    // First ring position
  80      // Wall stake position
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

    float currentArmAngle = lift_arm_potentiometer.angle(degrees);
    float goalArmAngle = armPositions[goalArmPos];
    float error = goalArmAngle - currentArmAngle;

    if (std::abs(error) >= 1.0) {
      if (goalArmPos == 3) { // If goal pos is wall stake, go faster
        ringLiftArm.spin(reverse, error * 5, percent);
      } else {
        ringLiftArm.spin(reverse, error * 2.5, percent);
      }
    } else {
      ringLiftArm.stop();
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


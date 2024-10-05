#include "Competition/user-control.h"
#include "Competition/user-functions.h"

using namespace vex;

float liftMaxAngle = 196;
float liftMinAngle = 213;
float intakeLiftMinAngle = 213;

bool intakeSpinning = false;

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



    // Moves lift up and down

    if (Controller.ButtonL1.pressing()) {
      liftRaising = false;
      ringLift.spin(forward, 100, percent);
    } else if (Controller.ButtonL2.pressing()) {
      liftRaising = false;
      ringLift.spin(reverse, 100, percent);
    } else {
      if (!liftRaising) {
        ringLift.stop();
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
  }
}


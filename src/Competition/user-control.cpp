#include "Competition/user-control.h"
#include "Competition/user-functions.h"

using namespace vex;

int slowIntakeSpeed = 25;
int fastIntakeSpeed = 75;

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
      ringLift.spin(forward, 75, percent);
    } else if (Controller.ButtonL2.pressing()) {
      ringLift.spin(reverse, 75, percent);
    } else {
      //if (intakeSpinning && lift_potentiometer.angle(degrees) > intakeLiftMinAngle) {
      //  ringLift.spin(forward, 75, percent);
      //} else {
        ringLift.stop();
      //}
    }

    // Sets intakeSpeed to however fast it should be

    int intakeSpeed;

    if (slowIntake) {
      intakeSpeed = slowIntakeSpeed;
    } else {
      intakeSpeed = fastIntakeSpeed;
    }

    // Spins intake depending on direction and speed

    if (Controller.ButtonR1.pressing()) {
      ringIntake.spin(forward, intakeSpeed, percent);
      intakeSpinning = true;
    } else if (Controller.ButtonR2.pressing()) {
        ringIntake.spin(reverse, intakeSpeed, percent);
        intakeSpinning = true;
    } else {
      ringIntake.stop();
      intakeSpinning = false;
    }
  }
}


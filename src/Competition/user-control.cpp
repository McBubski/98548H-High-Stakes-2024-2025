#include "Competition/user-control.h"
#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"
#include "Autonomous/autonomous.h"

#include <cmath>

using namespace vex;

bool intakeSpinning = false;
bool skillsSetupHasRun = false;

// Change these values for arm position

float armPositions[6] = {
  85.5,    // Rest position
  100,    // First ring position
  125,    // Temp arm fix
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
        ringLiftArm.spin(reverse, 100, percent);
        ringIntake2.spinFor(reverse, 25, degrees, false);
        driveFor(-7.5, 100);
        wait(150, msec);
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

    if (!armOverride) {
      float currentArmAngle = lift_arm_potentiometer.angle(degrees);
      float goalArmAngle = armPositions[goalArmPos];
      float error = goalArmAngle - currentArmAngle;

      //std::cout << error << ", " << currentArmAngle << ", " << goalArmAngle << std::endl;
      std::cout << lift_arm_potentiometer.angle(turns) << std::endl;
      //if (std::abs(error) >= 0.5) {
        ringLiftArm.spin(reverse, error * 1.8, percent);
      //} else {
        //ringLiftArm.stop();
      //}
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


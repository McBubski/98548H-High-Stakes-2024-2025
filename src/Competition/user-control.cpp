#include "Competition/user-control.h"
#include "Competition/user-functions.h"
#include "Autonomous/auton-functions.h"
#include "Autonomous/autonomous.h"

#include <cmath>

using namespace vex;

bool intakeSpinning = false;
bool skillsSetupHasRun = false;
int previousWallstakeArmError = 0;
float Wallstake_Arm_kP = 0.7;
float Wallstake_Arm_kD = 0.8;

// Change these values for arm position

float armPositions[6] = {
  280.0,//87.5,    // Rest position
  261.0,    // First ring position
  210.0,    // Mid Position
  130.0,   // Wall stake position
  85.0,   // Alliance stake position
  220.0     // Hang position
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

    if (Controller.ButtonY.pressing()) {
      armOverride = true;
      ringLiftArm.spin(forward, 100, percent);
    } else if (Controller.ButtonB.pressing()) {
      if (auton_path == 5) {
        ringLiftArm.spin(forward, 100, percent);
        ringIntake2.spinFor(reverse, 25, degrees, false);
        driveFor(-7.5, 100);
        wait(150, msec);
        ringLiftArm.stop();
      } else {
        armOverride = true;
        ringLiftArm.spin(reverse, 100, percent);
      }
    } else {
      if (armOverride) {
        ringLiftArm.setStopping(hold);
        ringLiftArm.stop();
      }
    } 

    if (!armOverride) {
        // Calculate how far the arm needs to travel to be at target

        float currentArmAngle = lift_arm_potentiometer.angle(degrees);
        float goalArmAngle = armPositions[goalArmPos];
 
        float error = goalArmAngle - currentArmAngle;
        float derivative = error - previousWallstakeArmError;

        float kP = Wallstake_Arm_kP;
        float kD = Wallstake_Arm_kD;

        if (goalArmPos <= 1 && previousGoalArmPos > 1) { // If we're moving forward, basically.
          kP = 0.4;
          kD = 0.08;
         } 

      //std::cout << error << ", " << currentArmAngle << ", " << goalArmAngle << std::endl;

      //std::cout << lift_arm_potentiometer.angle(degrees) << std::endl;

      if (std::abs(error) >= 0.5) {
       ringLiftArm.spin(forward, error * kP + derivative * kD, percent);
      } else {
       ringLiftArm.stop();
      }

      previousWallstakeArmError = error;
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


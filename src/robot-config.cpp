#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

// Left Drive

motor motorTL = motor(PORT2, ratio6_1, true);
motor motorML = motor(PORT3, ratio6_1, false);
motor motorBL = motor(PORT17, ratio6_1, true);

motor_group leftDrive = motor_group(motorTL, motorML, motorBL);

// Right Drive

motor motorTR = motor(PORT10, ratio6_1, false);
motor motorMR = motor(PORT9, ratio6_1, true);
motor motorBR = motor(PORT19, ratio6_1, false);

motor_group rightDrive = motor_group(motorTR, motorMR, motorBR);

// Lift

motor ringIntake = motor(PORT1, ratio36_1, false);
motor ringLift = motor(PORT12, ratio36_1, true);

motor_group lift = motor_group(ringIntake, ringLift);

// Sensors

pot lift_potentiometer = pot(Brain.ThreeWirePort.C);
inertial inertial_sensor = inertial(PORT21);

// Pneumatics

digital_out goal_clamp = digital_out(Brain.ThreeWirePort.B);

void vexcodeInit(void) {
  
}
#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

// Left Drive

motor motorTL = motor(PORT17, ratio6_1, true);
motor motorML = motor(PORT18, ratio6_1, false);
motor motorBL = motor(PORT19, ratio6_1, true);

motor_group leftDrive = motor_group(motorTL, motorML, motorBL);

// Right Drive

motor motorTR = motor(PORT8, ratio6_1, false);
motor motorMR = motor(PORT9, ratio6_1, true);
motor motorBR = motor(PORT10, ratio6_1, false);

motor_group rightDrive = motor_group(motorTR, motorMR, motorBR);

void vexcodeInit(void) {
  
}
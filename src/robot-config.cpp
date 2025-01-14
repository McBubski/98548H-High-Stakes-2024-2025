#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

// Left Drive
//Rename PPPPLLLLEEEAAASSEEE
motor motorTL = motor(PORT2, ratio6_1, false);
motor motorML = motor(PORT1, ratio6_1, true);
motor motorBL = motor(PORT3, ratio6_1, true);

motor_group leftDrive = motor_group(motorTL, motorML, motorBL);

// Right Drive

motor motorTR = motor(PORT6, ratio6_1, true);
motor motorMR = motor(PORT4, ratio6_1, false);
motor motorBR = motor(PORT5, ratio6_1, false);

motor_group rightDrive = motor_group(motorTR, motorMR, motorBR);

// Lift

motor ringIntake1 = motor(PORT12, ratio36_1, false);
motor ringIntake2 = motor(PORT11, ratio36_1, true);
motor ringLift = motor(PORT17, ratio36_1, true);
motor ringLiftArm = motor(PORT16, ratio36_1, true);

motor_group ringIntake = motor_group(ringIntake1, ringIntake2);

// Sensors

rotation lift_arm_potentiometer = rotation(PORT15, false);
inertial inertial_sensor = inertial(PORT7);

rotation sidewaysTrackingWheel = rotation(PORT13, true);
rotation forwardTrackingWheel = rotation(PORT14, false);

optical color_sensor = optical(PORT20);
aivision ai_sensor = aivision(PORT17);

digital_in ring_switch = digital_in(Brain.ThreeWirePort.C);

// Pneumatics

digital_out goal_clamp = digital_out(Brain.ThreeWirePort.A);
digital_out lifted_intake = digital_out(Brain.ThreeWirePort.B);

digital_out goal_rush_arm = digital_out(Brain.ThreeWirePort.E);
digital_out goal_rush_arm_clamp = digital_out(Brain.ThreeWirePort.F);

// Odometry

// Tracking Wheel Radius, Forward Tracking Wheel Distance, Sideways Tracking Wheel Distance, Starting Heading, Starting X, Starting Y
Odometry Position_Tracking = Odometry(2.75 / 2, 0, 0.75, 0.0, 0.0, 0.0);

void vexcodeInit(void) {
  
}
#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

// Left Drive
//Rename PPPPLLLLEEEAAASSEEE
motor motorTL = motor(PORT16, ratio6_1, true);
motor motorML = motor(PORT20, ratio6_1, true);
motor motorBL = motor(PORT14, ratio6_1, true);

motor_group leftDrive = motor_group(motorTL, motorML, motorBL);

// Right Drive

motor motorTR = motor(PORT7, ratio6_1, false);
motor motorMR = motor(PORT8, ratio6_1, false);
motor motorBR = motor(PORT10, ratio6_1, false);

motor_group rightDrive = motor_group(motorTR, motorMR, motorBR);

// Lift

motor ringIntake1 = motor(PORT5, ratio36_1, false);
motor ringIntake2 = motor(PORT5, ratio36_1, true);
motor ringLiftArm = motor(PORT3, ratio36_1, false);

motor_group ringIntake = motor_group(ringIntake1, ringIntake2);

// Sensors

//rotation lift_arm_potentiometer = rotation(PORT17, false);
rotation lift_arm_potentiometer = rotation(PORT6, false);
inertial inertial_sensor = inertial(PORT9);

rotation sidewaysTrackingWheel = rotation(PORT13, false);
rotation forwardTrackingWheel = rotation(PORT11, true);

optical color_sensor = optical(PORT19);
distance distance_sensor = distance(PORT12);

digital_in ring_switch = digital_in(Brain.ThreeWirePort.C);

// Pneumatics

digital_out goal_clamp = digital_out(Brain.ThreeWirePort.A);
digital_out lifted_intake = digital_out(Brain.ThreeWirePort.B);

digital_out goal_rush_arm = digital_out(Brain.ThreeWirePort.C);
digital_out goal_rush_arm_clamp = digital_out(Brain.ThreeWirePort.D);

digital_out goal_rush_arm_right = digital_out(Brain.ThreeWirePort.E);
digital_out goal_rush_arm_right_clamp = digital_out(Brain.ThreeWirePort.H);

// Odometry

// Tracking Wheel Radius, Forward Tracking Wheel Distance, Sideways Tracking Wheel Distance, Starting Heading, Starting X, Starting Y
Odometry Position_Tracking = Odometry(2.75 / 2, 0.875, 1, 0.0, 0.0, 0.0);

void vexcodeInit(void) {
  
}
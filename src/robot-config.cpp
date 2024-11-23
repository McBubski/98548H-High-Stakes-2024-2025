#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

// Left Drive

motor motorTL = motor(PORT6, ratio6_1, false);
motor motorML = motor(PORT5, ratio6_1, true);
motor motorBL = motor(PORT10, ratio6_1, true);

motor_group leftDrive = motor_group(motorTL, motorML, motorBL);

// Right Drive

motor motorTR = motor(PORT3, ratio6_1, true);
motor motorMR = motor(PORT1, ratio6_1, false);
motor motorBR = motor(PORT8, ratio6_1, false);

motor_group rightDrive = motor_group(motorTR, motorMR, motorBR);

// Lift

motor ringIntake1 = motor(PORT21, ratio36_1, true);
motor ringIntake2 = motor(PORT17, ratio36_1, true);
motor ringLift = motor(PORT12, ratio36_1, true);
motor ringLiftArm = motor(PORT14, ratio36_1, true);

motor_group ringIntake = motor_group(ringIntake1, ringIntake2);

// Sensors

pot lift_arm_potentiometer = pot(Brain.ThreeWirePort.C);
inertial inertial_sensor = inertial(PORT9);

rotation sidewaysTrackingWheel = rotation(PORT19, false);
rotation forwardTrackingWheel = rotation(PORT18, false);

optical color_sensor = optical(PORT13);
aivision ai_sensor = aivision(PORT2);

// Pneumatics

digital_out goal_clamp = digital_out(Brain.ThreeWirePort.A);
digital_out corner_arm = digital_out(Brain.ThreeWirePort.B);
digital_out ring_sorter = digital_out(Brain.ThreeWirePort.D);

// Odometry

// Tracking Wheel Radius, Forward Tracking Wheel Distance, Sideways Tracking Wheel Distance, Starting Heading, Starting X, Starting Y
Odometry Position_Tracking = Odometry(2.75 / 2, 1.25, 1.25, 0.0, 0.0, 0.0);

void vexcodeInit(void) {
  
}
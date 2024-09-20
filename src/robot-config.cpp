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

rotation sidewaysTrackingWheel = rotation(PORT5, false);
rotation forwardTrackingWheel = rotation(PORT7, false);

aivision ai_vision = aivision(PORT8);

// Pneumatics

digital_out goal_clamp = digital_out(Brain.ThreeWirePort.B);
digital_out corner_arm = digital_out(Brain.ThreeWirePort.D);

// Odometry

// Tracking Wheel Radius, Forward Tracking Wheel Distance, Sideways Tracking Wheel Distance, Starting Heading, Starting X, Starting Y
Odometry Position_Tracking = Odometry(2.75 / 2, 1.25, 1.25, 0.0, 0.0, 0.0);

void vexcodeInit(void) {
  
}
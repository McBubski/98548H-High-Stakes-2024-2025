#include "Autonomous/odometry.h"

using namespace vex;

extern brain Brain;
extern controller Controller;

// Left Drive

extern motor motorTL;
extern motor motorML;
extern motor motorBL;

extern motor_group leftDrive;

// Right Drive

extern motor motorTR;
extern motor motorMR;
extern motor motorBR;

extern motor_group rightDrive;

// Lift

extern motor ringIntake;
extern motor ringLift;
extern motor_group lift;

// Sensors

extern pot lift_potentiometer;
extern inertial inertial_sensor;

extern rotation sidewaysTrackingWheel;
extern rotation forwardTrackingWheel;

// Pneumatics

extern digital_out goal_clamp;

// Odometry

extern Odometry Position_Tracking;

void vexcodeInit(void);

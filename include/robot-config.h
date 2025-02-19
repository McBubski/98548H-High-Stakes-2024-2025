using namespace vex;

#include "Robot/odometry.h"

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

extern motor ringIntake1;
extern motor ringIntake2;
extern motor ringLift;
extern motor ringLiftArm;

extern motor_group ringIntake;

// Sensors

//extern rotation lift_arm_potentiometer;
extern pot lift_arm_potentiometer;
extern inertial inertial_sensor;

extern rotation sidewaysTrackingWheel;
extern rotation forwardTrackingWheel;

extern optical color_sensor;
extern aivision ai_sensor;

extern digital_in ring_switch;

// Pneumatics

extern digital_out goal_clamp;
extern digital_out lifted_intake;

extern digital_out goal_rush_arm;
extern digital_out goal_rush_arm_clamp;

// Odometry

extern Odometry Position_Tracking;

void vexcodeInit(void);

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

extern pot lift_arm_potentiometer;
extern inertial inertial_sensor;

extern rotation sidewaysTrackingWheel;
extern rotation forwardTrackingWheel;

extern optical color_sensor;
extern aivision ai_sensor;

// Pneumatics

extern digital_out goal_clamp;
extern digital_out corner_arm;
extern digital_out ring_sorter;

// Odometry

extern Odometry Position_Tracking;

void vexcodeInit(void);

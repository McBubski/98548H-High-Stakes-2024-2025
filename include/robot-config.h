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

// Pneumatics

extern digital_out goal_clamp;

void vexcodeInit(void);

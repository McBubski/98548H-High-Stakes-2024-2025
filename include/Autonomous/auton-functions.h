#include "vex.h"

void turnToHeading(double heading, double turnSpeed);
void pointAt(double x, double y, double turnSpeed, vex::directionType dir);
void driveFor(double distance, double speed);
void driveTo(double x, double y, double speed, vex::directionType dir);
double wrapAngleDeg(double angle);
void moveLiftToAngle(float targetAngle, bool pushing);
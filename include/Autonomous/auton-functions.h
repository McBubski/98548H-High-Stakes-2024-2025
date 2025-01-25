#include "vex.h"

extern int auton_color;
extern bool intake_interrupt;
extern bool color_sort_override;

void turnToHeading(double heading, double turnSpeed);
void pointAt(double x, double y, double turnSpeed, vex::directionType dir);
void driveFor(double distance, double speed);
void driveTo(double x, double y, double speed, vex::directionType dir);

double getDistance(double x1, double y1, double x2, double y2);
double wrapAngleDeg(double angle);

void moveLiftToAngle(float targetAngle, bool pushing);
vex::task createRaiseArmTask(int targetAngle);

int sortColorTask(void);
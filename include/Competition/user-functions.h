#include "vex.h"

void initializeUserControl(void);
void toggleGoalClamp(void);
void toggleRingClamp(void);
void toggleCornerArm(void);
void toggleIntakeSpeed(void);
void cycleRingArmTarget(void);
void lowerRingArm(void);
void autoSkillsStart(void);
void toggleColorSorter(void);

extern bool slowIntake;
extern bool liftRaising;

extern int goalArmPos;
extern int previousAutonColor;
#include "vex.h"

void initializeUserControl(void);
void toggleGoalClamp(void);
void toggleRingClamp(void);
void toggleCornerArm(void);
void toggleIntakeSpeed(void);
void raiseArmToElevationHeight(void);
void raiseArmToWallStakeHeight(void);

extern bool slowIntake;
extern bool liftRaising;
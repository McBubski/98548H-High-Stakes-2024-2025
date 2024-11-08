#include "vex.h"

// Competition

#include "Competition/user-control.h"
#include "Autonomous/autonomous.h"
#include "Autonomous/auton-functions.h"
#include "Autonomous/pre-auton.h"

#include "GUI/gui-main.h"

using namespace vex;

competition Competition;

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  task guiTask = task(drawScreen);
  task odometryTask = task(UpdateOdometry);
  task color_sort_task = task(sortColorTask);

  while (true) {
    wait(100, msec);
  }
}



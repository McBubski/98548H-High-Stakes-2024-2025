#include "vex.h"

// Competition

#include "Competition/user-control.h"
#include "Autonomous/autonomous.h"
#include "Autonomous/pre-auton.h"

using namespace vex;

competition Competition;

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}

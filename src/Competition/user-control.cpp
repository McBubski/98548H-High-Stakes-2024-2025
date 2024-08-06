#include "vex.h"
#include "Competition/user-control.h"

using namespace vex;

void usercontrol(void) {
  while (1) {
    wait(20, msec);
    
    float leftStickPos = Controller.Axis3.position();
    float rightStickPos = Controller.Axis2.position();

    leftDrive.spin(forward, leftStickPos, percent);
    rightDrive.spin(forward, rightStickPos, percent);
  }
}
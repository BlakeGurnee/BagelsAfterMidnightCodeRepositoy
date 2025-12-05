#include "main.h"

void setIntake(int intakePower) 
{
  lowerIntake.move(intakePower);
  upperIntake.move(intakePower);
}

void descoreSwitch()
{
 if (descorePiston.is_extended())
  {
    descorePiston.retract();
  }
 else
  {
    descorePiston.extend();
  }
}

void matchloadSwitch()
{
 if (matchloadPiston.is_extended())
  {
    matchloadPiston.retract();
  }
 else
  {
    matchloadPiston.extend();
  }
}

void centerGoalSwitch()
{
 if (centerGoalPiston.is_extended())
  {
    centerGoalPiston.retract();
  }
 else
  {
    centerGoalPiston.extend();
  }
}

void ParkMacro() {
    parkPiston.retract();  // Retract parking piston to prepare for parking
    // Keep checking until object detected
    while (true) {

        int dist = parkSensor.get();   // returns mm

        // Trigger when object detected within 80mm
        if (dist > 0 && dist < 80) {
            upperIntake.move(0);
            lowerIntake.move(0);

            parkPistons.toggle();  // Activate parking piston

            break;                // exit macro
        }

        // No object detected → run intake in reverse slowly
        setIntake(-80);

        pros::delay(10);          // prevent task starvation
    }
}

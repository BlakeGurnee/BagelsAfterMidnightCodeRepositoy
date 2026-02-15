#include "main.h"

void setIntake(int intakePower) 
{
  lowerIntake.move(intakePower);
  upperIntake.move(intakePower);
}

void blockHold()
{
  upperIntake.move(-50);
  lowerIntake.move(127);
}

void midGoal()
{
  upperIntake.move(0);
  lowerIntake.move(100);
}

void lowGoal()
{
  upperIntake.move(0);
  lowerIntake.move(-100);
}

void stopIntake() 
{
  lowerIntake.move(0);
  upperIntake.move(0);
}

void discardBlock(int intakePower)
{
  lowerIntake.move(intakePower);
  upperIntake.move(-intakePower);
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

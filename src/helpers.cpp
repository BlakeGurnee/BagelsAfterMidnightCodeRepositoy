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
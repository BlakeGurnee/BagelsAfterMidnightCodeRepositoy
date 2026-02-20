#include "main.h"

// Set Intake function takes in an intake power and sets both the upper and lower intake to that power
void setIntake(int intakePower) 
{
  lowerIntake.move(intakePower);
  upperIntake.move(intakePower);
}

// Block Hold function sets the upper intake to a low power and the lower intake to full power to hold blocks in place
void blockHold()
{
  upperIntake.move(-50);
  lowerIntake.move(127);
}

// Mid Goal function sets the upper intake to 0 and the lower intake to full power to score on the mid goal
void midGoal()
{
  upperIntake.move(0);
  lowerIntake.move(100);
}

// Low Goal function sets the upper intake to 0 and the lower intake to reverse slowly to score on the low goal
void lowGoal()
{
  upperIntake.move(0);
  lowerIntake.move(-100);
}

// Stop Intake function sets both the upper and lower intake to 0 to stop the intake
void stopIntake() 
{
  lowerIntake.move(0);
  upperIntake.move(0);
}

// Discard Block function takes in an intake power and sets the lower intake to that power and the upper intake to the negative of that power to discard blocks
void discardBlock(int intakePower)
{
  lowerIntake.move(intakePower);
  upperIntake.move(-intakePower);
}

// Descore Switch function toggles the descore piston between the extended and retracted position
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

// Matchload Switch function toggles the matchload piston between the extended and retracted position
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

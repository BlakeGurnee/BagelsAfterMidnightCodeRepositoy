#include "main.h"

void redRightMain() {

  // Drive to matchloader
  chassis.pid_odom_set(32_in, 110);  
  chassis.pid_wait();
  
  // Activate Matchload Piston
  matchloadPiston.set_value(true);

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 85);
  chassis.pid_wait();

  // Activate Block Hold Intake and drive into matchloader
  blockHold();
  chassis.pid_odom_set(10_in, 60);  
  chassis.pid_wait();

  // Short delay to give the intake time to collect the blocks
  pros::delay(550);

  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();
 
  // Drive backwards into the long goal
  chassis.pid_odom_set(-30_in, 110);  
  chassis.pid_wait();

  // Activate full intake to score the blocks
  setIntake(127);

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Wait for two seconds to give it time to score the blocks
  pros::delay(2000);
 
  // Swing off long goal to blocks
  chassis.pid_swing_relative_set(ez::LEFT_SWING, 80_deg, 110);
  chassis.pid_wait();

  // Turn more to face blocks
  chassis.pid_turn_relative_set(40_deg, 90);
  chassis.pid_wait();

  // Block Hold
  blockHold();

  // Drive to blocks and intake them
  chassis.pid_odom_set(15_in, 60);  
  chassis.pid_wait();

  // Turn a little more to face goal
  chassis.pid_turn_relative_set(10_deg, 90);
  chassis.pid_wait();

  // Drive to goal
  chassis.pid_odom_set(15_in, 90);  
  chassis.pid_wait();

  // If the auton is a left side auton score on high middle if not score on low middle.
   if (chassis.odom_y_direction_get() == true) {
      // Spin upper intake to score blocks on high goal
      midGoal();
   } else 
   {
      // Spin lower intake reverse slowly to score blocks on low goal
      lowGoal();
   }
}
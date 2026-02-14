#include "main.h"

void redRightMain() {
  
  // Drive to matchloader
  chassis.pid_odom_set(35_in, 110);  
  chassis.pid_wait();
  
  // Activate Matchload Piston
  matchloadPiston.set_value(true);

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  // Activate Block Hold Intake and drive into matchloader
  lowerIntake.move(127);
  chassis.pid_odom_set(10_in, 60);  
  chassis.pid_wait();

  // Short delay to give the intake time to collect the blocks
  pros::delay(550);
 
  // Drive backwards into the long goal
  chassis.pid_odom_set(-30_in, 90);  
  chassis.pid_wait();

  // Activate full intake to score the blocks
  upperIntake.move(127);

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Wait for two seconds to give it time to score the blocks
  pros::delay(2000);
 
  // Swing off long goal to blocks
  chassis.pid_swing_relative_set(ez::LEFT_SWING, 85_deg, 90);
  chassis.pid_wait();

  // Turn more to face blocks
  chassis.pid_turn_relative_set(35_deg, 90);
  chassis.pid_wait();

  // Set lower intake to hold blocks
  lowerIntake.move(127);

  // Drive to blocks and intake them
  chassis.pid_odom_set(15_in, 60);  
  chassis.pid_wait();

  // Turn a little more to face goal
  chassis.pid_turn_relative_set(5_deg, 90);
  chassis.pid_wait();

  // Drive to goal
  chassis.pid_odom_set(15_in, 90);  
  chassis.pid_wait();

  // Spin lower intake reverse slowly to score blocks on low goal
  lowerIntake.move(-100);
}




/*

// Activate Matchload Piston
  matchloadPiston.set_value(true);
  
  // Drive to Matchloader
  chassis.pid_drive_set(33_in, 110);
  chassis.pid_wait();

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  // Activate Block Hold Intake and drive into matchloader
  lowerIntake.move(127);
  chassis.pid_drive_set(10_in, 60);
  chassis.pid_wait();

  // Short delay to give the intake time to collect the blocks
  pros::delay(550);

  // Drive backwards into the long goal
  chassis.pid_drive_set(-30_in, 100);
  chassis.pid_wait();

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Activate full intake to score the blocks
  upperIntake.move(127);

  // Wait for three seconds to give it time to score the blocks
  pros::delay(3000);

  // Drive 10" back towards the matchloader
  chassis.pid_drive_set(10_in, 40);
  chassis.pid_wait();
  
  // Turn right to prepare for pushing blocks
  chassis.pid_turn_set(180_deg, 60);
  chassis.pid_wait();

  // Activate descore wing
  descorePiston.set_value(true);

  // Drive forward a bit to align with the side of the long goal
  chassis.pid_drive_set(-15_in, 30);
  chassis.pid_wait();

  // Turn 90 degrees to face long goal
  chassis.pid_turn_set(90_deg, 60);
  chassis.pid_wait();

  // Run into long goal with descore wing to push the blocks into the control bonus
  chassis.pid_drive_set(-32_in, 100);
  chassis.pid_wait();

  // Stop intake to save battery and motor temp
  setIntake(0);

*/
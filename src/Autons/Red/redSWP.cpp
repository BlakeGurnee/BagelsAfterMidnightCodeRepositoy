#include "main.h"

void redSWP() {
   // Set odom position to (0, 0, 0)
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);

  // Drive to matchloader
  chassis.pid_odom_set(35_in, 110);  
  chassis.pid_wait();
  
  // Activate Matchload Piston
  matchloadPiston.set_value(true);

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 85);
  chassis.pid_wait();

  // Activate Block Hold Intake and drive into matchloader
  blockHold();
  chassis.pid_odom_set(10_in, 50);  
  chassis.pid_wait();

  // Short delay to give the intake time to collect the blocks
  pros::delay(300);

  // Align with long goal
  chassis.pid_turn_set(90_deg, 100);
  chassis.pid_wait();
 
  // Drive backwards into the long goal
  chassis.pid_odom_set(-30_in, 110);  
  chassis.pid_wait();

  // Activate full intake to score the blocks
  setIntake(127);

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Wait for a few seconds to give it time to score the blocks
  pros::delay(1400);
 
 // Drive forward towards the matchloader
  chassis.pid_odom_set(20_in, 110);  
  chassis.pid_wait();

  // Turn to the blocks
  chassis.pid_turn_relative_set(130_deg, 90);
  chassis.pid_wait();

   // Block Hold
   blockHold();

   // Drive to blocks and intake them
   chassis.pid_odom_set(30_in, 60);  
   chassis.pid_wait();

   // Drive to low goal
   chassis.pid_odom_set(15_in, 100);  
   chassis.pid_wait();

   // Score on low goal
   lowGoal();

   // Backup
   chassis.pid_odom_set(-15_in, 110);  
   chassis.pid_wait();

   // Turn to the blocks
  chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();

  // block hold
  blockHold();

  // Drive to blocks and intake them
  chassis.pid_odom_set(50_in, 60); 
  chassis.pid_wait();

  matchloadPiston.set_value(true);

  // Turn to the long goal
  chassis.pid_turn_set(270_deg, 100);
  chassis.pid_wait();

  // Drive to long goal
  chassis.pid_odom_set(25_in, 110);  
  chassis.pid_wait();

  // Turn to face long goal
  chassis.pid_turn_set(90_deg, 100);
  chassis.pid_wait();

  // Drive backwards into long goal
  chassis.pid_odom_set(-25_in, 110);  
  chassis.pid_wait();

  // Intake
  setIntake(127);
}
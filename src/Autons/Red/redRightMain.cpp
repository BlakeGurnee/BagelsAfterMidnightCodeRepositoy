#include "main.h"

void redRightMain() {
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
  chassis.pid_odom_set(10_in, 60);  
  chassis.pid_wait();


  // Short delay to give the intake time to collect the blocks
  pros::delay(300);


  // Align with long goal
  chassis.pid_turn_set(90_deg, 90);
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
  chassis.pid_odom_set(15_in, 80);  
  chassis.pid_wait();


  // If left side turn a different direction
  if (chassis.odom_y_direction_get() == true) {
      // Turn to the blocks
      chassis.pid_turn_relative_set(-55_deg, 90);
      chassis.pid_wait();
  } else
  {
      // Turn to the blocks
      chassis.pid_turn_relative_set(130_deg, 90);
      chassis.pid_wait();
  }


   // Block Hold
   blockHold();


   // Drive to blocks and intake them
   chassis.pid_odom_set(25_in, 60);  
   chassis.pid_wait();


   if (chassis.odom_y_direction_get() == true) { // Left side
      // Turn completely around to face goal
      chassis.pid_turn_relative_set(250_deg, 90);
      chassis.pid_wait();


      // Drive to goal
      chassis.pid_odom_set(-22_in, 90);  
      chassis.pid_wait();


      // Activate Center Goal
      centerGoalSwitch();


      pros::delay(1000); // Wait for 1.5 seconds to score the blocks


      // Ensure all blocks are in goal
      chassis.pid_odom_set(-3_in, 90);  
      chassis.pid_wait();


      chassis.pid_odom_set(3_in, 90);  
      chassis.pid_wait();


      // Disarm center goal
      centerGoalSwitch();
     
   } else
   {
       // Drive to goal
      chassis.pid_odom_set(10_in, 90);  
      chassis.pid_wait();

      // Score on low goal
      lowGoal();
   }


}


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
 

  printf("Y direction: %d\n", chassis.odom_y_direction_get());
  pros::delay(500);

  // Swing off long goal to blocks
   if (chassis.odom_y_direction_get() == true) {
      chassis.pid_swing_relative_set(ez::LEFT_SWING, -80_deg, 110);
      chassis.pid_wait();
      printf("Swinging left\n");
      
   } else 
   {
     chassis.pid_swing_relative_set(ez::RIGHT_SWING, 80_deg, 110);
     chassis.pid_wait();
     printf("Swinging right\n");
   }

   // Turn more to face blocks
   chassis.pid_turn_relative_set(40_deg, 90);
   chassis.pid_wait();

  // Block Hold
  blockHold();

  // Drive to blocks and intake them
  chassis.pid_odom_set(15_in, 60);  
  chassis.pid_wait();

   if (chassis.odom_y_direction_get() == true) { // Left side
      // Turn completely around to face goal
      chassis.pid_turn_relative_set(250_deg, 90);
      chassis.pid_wait();

      // Drive to goal
      chassis.pid_odom_set(-22_in, 90);  
      chassis.pid_wait();

      centerGoalSwitch();

      pros::delay(1000); // Wait for 1.5 seconds to score the blocks

      chassis.pid_odom_set(-3_in, 90);  
      chassis.pid_wait();

      chassis.pid_odom_set(3_in, 90);  
      chassis.pid_wait();

      centerGoalSwitch();
      
   } else 
   {
      // Turn a little more to face goal
      chassis.pid_turn_relative_set(10_deg, 90);
      chassis.pid_wait();

         // Drive to goal
      chassis.pid_odom_set(15_in, 90);  
      chassis.pid_wait();

      lowGoal();
   }

}
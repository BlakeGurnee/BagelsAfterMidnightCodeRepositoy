#include "main.h"

void redRightMain() {
  // Set odom position to (0, 0, 0)
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);

  // Drive forward to align with blocks
  chassis.pid_odom_set(25_in, 110);
  chassis.pid_wait();

  // Turn to face the blocks
  chassis.pid_turn_set(20_deg, 90);
  chassis.pid_wait();

  lowerIntake.move(100); // Start lower intake

  // Wait a split second before activating matchload
  pros::delay(500);

  // Set Matchloader
  matchloadPiston.set_value(true);

  // Drive forward to collect blocks
  chassis.pid_odom_set(20_in, 70);
  chassis.pid_wait();

  pros::delay(500); // Give time to collect blocks

  // Turn to face the goal
  chassis.pid_turn_set(140_deg, 100);
  chassis.pid_wait();

  // Drive to the goal
  chassis.pid_odom_set(35_in, 100);
  chassis.pid_wait();
  
  // Turn to face the goal scoring position
  chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

  // Drive backwards to score the blocks
  chassis.pid_odom_set(-25_in, 100);
  pros::delay(1000); // Wait to ensure blocks have scored

  upperIntake.move(127); // Start upper intake to score

  pros::delay(1500); // Wait for 3 seconds to score

  upperIntake.move(0); // Stop upper intake
  lowerIntake.move(127); // lower intake

  // Drive forward to matchloader
  chassis.pid_turn_set(180_deg, 75);
  chassis.pid_wait();
  chassis.pid_odom_set(30_in, 80);
  chassis.pid_wait();
  
  
  pros::delay(800); // Short delay for matchloading

  // Make sure robot is still aligned
  chassis.pid_turn_set(180_deg, 75);

  // Drive backwards into the long goal
  chassis.pid_odom_set(-30_in, 90);
  pros::delay(1000); // Wait to ensure robot is in position

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Activate full intake to score the blocks
  upperIntake.move(127);

  // Wait for three seconds to give it time to score the blocks
  pros::delay(3000);

  // Hit the blocks
  chassis.pid_odom_set(5_in, 127);
  chassis.pid_wait();
  chassis.pid_odom_set(-10_in, 127);
}

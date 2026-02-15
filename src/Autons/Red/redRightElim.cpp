#include "main.h"

void redRightElim() {
  // Set odom position to (0, 0, 0)
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);

  // Drive forward to align with blocks
  chassis.pid_odom_set(25_in, 110);
  chassis.pid_wait();

  // Turn to face the blocks
  chassis.pid_turn_set(20_deg, 90);
  chassis.pid_wait();

  // Start block hold
  blockHold();

  // Wait a split second before activating matchload
  pros::delay(500);

  // Set Matchloader
  matchloadPiston.set_value(true);

  // Drive forward to collect blocks
  chassis.pid_odom_set(25_in, 70);
  chassis.pid_wait();

  pros::delay(500); // Give time to collect blocks

  // Turn to face the goal
  chassis.pid_turn_set(140_deg, 100);
  chassis.pid_wait();

  // Drive to the goal
  chassis.pid_odom_set(45_in, 100);
  chassis.pid_wait();
  
  // Turn to face the goal scoring position
  chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

  // Drive backwards to score the blocks
  chassis.pid_odom_set(-25_in, 100);
  pros::delay(1000); // Wait to ensure blocks have scored

  // Intake to score
  setIntake(127);

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
  setIntake(127);

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
}
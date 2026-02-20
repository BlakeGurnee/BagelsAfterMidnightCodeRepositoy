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
  pros::delay(200);

  // Set Matchloader
  matchloadPiston.set_value(true);

  // Drive forward to collect blocks
  chassis.pid_odom_set(20_in, 60);
  chassis.pid_wait();

  pros::delay(600); // Give time to collect blocks

  // Turn to face the goal
  chassis.pid_turn_set(140_deg, 100);
  chassis.pid_wait();

  // Drive to the goal
  chassis.pid_odom_set(38_in, 110);
  chassis.pid_wait();
  
  // Turn to face the goal scoring position
  chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

  // Drive backwards to score the blocks
  chassis.pid_odom_set(-25_in, 110);
  pros::delay(900); // Wait to ensure blocks have scored

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
  pros::delay(600); // Short delay for matchloading

  // Make sure robot is still aligned
  chassis.pid_turn_set(180_deg, 75);

  // Drive backwards into the long goal
  chassis.pid_odom_set(-30_in, 110);
  pros::delay(800); // Wait to ensure robot is in position

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Activate full intake to score the blocks
  setIntake(127);

  // Wait for three seconds to give it time to score the blocks
  pros::delay(1000);

  // Drive 10" back towards the matchloader
  chassis.pid_drive_set(10_in, 100);
  chassis.pid_wait();
  
  chassis.pid_turn_relative_set(-45_deg, 90);
  chassis.pid_wait();

  // Activate descore wing
  descorePiston.set_value(true);

  // Drive forward a bit to align with the side of the long goal
  chassis.pid_drive_set(-15_in, 900);
  chassis.pid_wait();

  // Turn 90 degrees to face long goal
  chassis.pid_turn_set(180_deg, 80);
  chassis.pid_wait();

  // Activate descore wing
  descorePiston.set_value(false);

  // Run into long goal with descore wing to push the blocks into the control bonus
  chassis.pid_drive_set(-18_in, 110);
  chassis.pid_wait();

  // Stop intake to save battery and motor temp
  setIntake(0);
}
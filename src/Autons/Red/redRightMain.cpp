#include "main.h"

void redRightMain() {

  // Drive forward to align with blocks
  chassis.pid_drive_set(25_in, 110);
  chassis.pid_wait();

  // Turn to face the blocks
  chassis.pid_turn_set(30_deg, 90);
  chassis.pid_wait();

  lowerIntake.move(127); // Start lower intake

  // Drive forward to collect blocks
  chassis.pid_drive_set(16_in, 40);
  chassis.pid_wait();

  pros::delay(100); // Short delay to give the intake time to collect the blocks

  // Turn to face the goal
  chassis.pid_turn_set(135_deg, 90);
  chassis.pid_wait();

  // Drive to the goal
  chassis.pid_drive_set(32_in, 40);
  chassis.pid_wait();

  // Turn to face the goal scoring position
  chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

  // Drive backwards to score the blocks
  chassis.pid_drive_set(-25_in, 40);
  chassis.pid_wait();

  upperIntake.move(127); // Start upper intake to score

  matchloadPiston.set_value(true); // Activate matchload piston

  pros::delay(3000); // Wait for 3 seconds to score

  lowerIntake.move(127); // lower intake

  // Drive forward to matchloader
  chassis.pid_drive_set(25_in, 60);
  chassis.pid_wait();

  // Short delay to give the intake time to collect the blocks
  pros::delay(550);

  // Drive backwards into the long goal
  chassis.pid_drive_set(-30_in, 80);
  chassis.pid_wait();

  // De-activate matchload Piston
  matchloadPiston.set_value(false);

  // Activate full intake to score the blocks
  upperIntake.move(127);

  // Wait for three seconds to give it time to score the blocks
  pros::delay(3000);
}

#include "main.h"

void skillsMain() {
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
   // Activate Matchload Piston
  matchloadPiston.set_value(true);
  pros::delay(500);
  
  // Drive to Matchloader
  chassis.pid_odom_set(33_in, 110);
  chassis.pid_wait();

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  // Activate Block Hold Intake and drive into matchloader
  lowerIntake.move(127);
  chassis.pid_odom_set(15_in, 75);
  pros::delay(1000);

  // Short delay to give the intake time to collect the blocks
  pros::delay(2500);

  // Drive more backwards
  chassis.pid_odom_set(-10_in, 60);
  chassis.pid_wait();

  // Deactive matchload
  matchloadPiston.set_value(false);
  

  pros::delay(100);

  // turn
  chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();

  chassis.pid_odom_set(20_in, 50);
  chassis.pid_wait();
  
  chassis.pid_turn_set(-95_deg, 90);
  chassis.pid_wait();

  //setIntake(0);

  // drive across field
  chassis.pid_odom_set(90_in, 100);
  chassis.pid_wait();

  chassis.pid_turn_set(-180_deg, 90);
  chassis.pid_wait();

  chassis.pid_odom_set(-20_in, 100);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, 90);
  chassis.pid_wait();

  chassis.pid_odom_set(-25_in, 100);
  chassis.pid_wait();

  matchloadPiston.set_value(true);

  lowerIntake.move(127);

  pros::delay(2000);

  chassis.pid_odom_set(25_in, 100);
  chassis.pid_wait();
}

/*
setIntake(127);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  chassis.pid_odom_set(10_in, 127);
*/
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
  pros::delay(3000);

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

/*

  

*/

/*
chassis.odom_xyt_set(0_in, 0_in, 0_deg);
chassis.pid_wait();
chassis.pid_odom_set({0_in, -38.204_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({-12.873_in, -37.997_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({29.068_in, -37.374_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({29.068_in, -51.493_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({102.155_in, -50.662_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({101.739_in, -36.543_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({121.464_in, -36.751_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({81.184_in, -37.374_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({101.532_in, -15.365_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({102.362_in, 57.514_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({122.295_in, 56.476_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({82.222_in, 57.306_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({81.392_in, 71.425_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({26.784_in, 71.84_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({9.759_in, 56.476_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({-10.797_in, 56.476_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({29.276_in, 56.476_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({7.682_in, 33.221_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({-12.25_in, 33.636_in}, 90);
chassis.pid_wait();
chassis.pid_odom_set({-11.835_in, 9.966_in}, 90);
chassis.pid_wait();
*/
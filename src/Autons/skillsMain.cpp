#include "main.h"

void skillsMain() {
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  lowerIntake.move(127);
  pros::delay(100);
  chassis.pid_drive_set(-20_in, 127);
  pros::delay(350);
  chassis.pid_drive_set(50_in, 127);
  pros::delay(800);
  chassis.pid_wait();
}

/*
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

  // Activate descore wing
  descorePiston.set_value(true);

  chassis.pid_turn_set(45_deg, 80);
  chassis.pid_wait();

  blockhold();

  chassis.pid_drive_set(25_in, 110);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 80);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, 110);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, 80);
  chassis.pid_wait();

  chassis.pid_drive_set(25_in, 110);
  chassis.pid_wait();


  chassis.pid_turn_set(180_deg, 80);
  chassis.pid_wait();

  chassis.pid_drive_set(25_in, 110);
  chassis.pid_wait();

  setIntake(127);


*/









/*
  Backup 20 point skills

 chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  lowerIntake.move(127);
  pros::delay(100);
  chassis.pid_drive_set(20_in, 127);
  pros::delay(350);
  chassis.pid_drive_set(-50_in, 127);
  pros::delay(800);
  chassis.pid_wait(); */

/* Work in progress skills auton with potential with control?

chassis.odom_xyt_set(0_in, 0_in, 0_deg);
   // Activate Matchload Piston
  matchloadPiston.set_value(true);
  pros::delay(500);
  
  // Drive to Matchloader
  chassis.pid_odom_set(35_in, 110);
  chassis.pid_wait();

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  // Activate Block Hold Intake and drive into matchloader
  lowerIntake.move(127);
  chassis.pid_odom_set(15_in, 75);
  pros::delay(3000);
  chassis.pid_odom_set(-10_in, 90);
  pros::delay(300);
  chassis.pid_odom_set(10_in, 75);
  pros::delay(500);

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
  pros::delay(1000);

  matchloadPiston.set_value(false);

  chassis.pid_odom_set(-15_in, 75);
  pros::delay(1000);

  chassis.pid_odom_set(5_in, 75);
  pros::delay(300);
  chassis.pid_odom_set(-5_in, 75);
  pros::delay(500);


*/
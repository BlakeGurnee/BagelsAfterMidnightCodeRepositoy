#include "main.h"

void skillsMain() {
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  lowerIntake.move(127);
  pros::delay(100);
  chassis.pid_drive_set(-10_in, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, 127);
  chassis.pid_wait();
}

/* Work in progress skills auton with potential with control?

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
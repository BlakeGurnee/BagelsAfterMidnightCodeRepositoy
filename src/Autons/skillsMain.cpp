#include "main.h"

void skillsMain() {

   // Drive to Matchloader
  chassis.pid_odom_set(33_in, 110);
  chassis.pid_wait();

  // Turn to face matchloader
  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  // Activate Matchload Piston


  // Activate Block Hold Intake and drive into matchloader
  lowerIntake.move(127);
  chassis.pid_odom_set(10_in, 60);
  chassis.pid_wait();

  // Short delay to give the intake time to collect the blocks
  pros::delay(550);

  // Drive backwards 15 inches
  chassis.pid_odom_set(-15_in, 100);
  chassis.pid_wait();

  // Turn to face right
  chassis.pid_turn_set(180_deg, 60);
  chassis.pid_wait();

  // Drive forward a little
  chassis.pid_odom_set(15_in, 100);
  chassis.pid_wait();

  // Turn back to face straight
  chassis.pid_turn_set(90_deg, 60);
  chassis.pid_wait();

  // Drive to the other side of the field
  chassis.pid_odom_set(48_in, 100);
  chassis.pid_wait();

  // Turn to face left
  chassis.pid_turn_set(-180_deg, 60);
  chassis.pid_wait();

  // Drive forwards a bit
  chassis.pid_odom_set(15_in, 100);
  chassis.pid_wait();

  // Turn to face left again
  chassis.pid_turn_set(-180_deg, 60);
  chassis.pid_wait();

}



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
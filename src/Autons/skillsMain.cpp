#include "main.h"

void skillsMain() {
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);


  // Drive forward to align with blocks
  chassis.pid_odom_set(25_in, 110);
  chassis.pid_wait();


  // Turn to face the blocks
  chassis.pid_turn_set(20_deg, 90);
  chassis.pid_wait();


  lowerIntake.move(100); // Start lower intake


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


  pros::delay(2500); // Wait for 3 seconds to score


  upperIntake.move(0); // Stop upper intake
  lowerIntake.move(127); // lower intake


  // Drive forward to matchloader
  chassis.pid_turn_set(180_deg, 75);
  chassis.pid_wait();
  chassis.pid_odom_set(30_in, 65);
  chassis.pid_wait();
 
 
  pros::delay(4000); // Short delay before activating matchload piston
  chassis.pid_odom_set(-5_in, 80);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_odom_set(25_in, 80);
  pros::delay(1000);
 
 // matchloadPiston.set_value(true);


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


  chassis.pid_odom_set(5_in, 127);
  chassis.pid_wait();
  chassis.pid_odom_set(-10_in, 127);
  pros::delay(1000);


  // Drive 10" back towards the matchloader
  chassis.pid_odom_set(10_in, 60);
  chassis.pid_wait();


  // Deactive matchload
  matchloadPiston.set_value(false);
 
  // Wait
  pros::delay(100);


  // turn
  chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();
 
  chassis.pid_turn_set(-95_deg, 90);
  chassis.pid_wait();




  // Stop intake to stop it from collecting blocks in the way
  setIntake(0);




  // drive across the field
  chassis.pid_odom_set(45_in, 127);
  chassis.pid_wait();




  chassis.pid_turn_set(-180_deg, 127);
  chassis.pid_wait();




  setIntake(127);




  chassis.pid_odom_set(-20_in, 127);
  chassis.pid_wait();




  chassis.pid_odom_set(50_in, 127);
  chassis.pid_wait();




}

/* 20 point Skills (Drive over park intake blocks and stop)
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  lowerIntake.move(127);
  pros::delay(100);
  chassis.pid_odom_set(-10_in, 127);
  chassis.pid_odom_set(15_in, 127);
  */


/*

*/

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
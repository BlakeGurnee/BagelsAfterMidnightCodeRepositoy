#include "main.h"
#include "splash_screens.hpp"

// Chassis constructor
ez::Drive chassis(
    // Drive Motors
    {-18, -17, -16},     // Left Chassis Ports (negative will reverse it)
    {8, 9, 10},  // Right Chassis Ports (negative will reverse it)

    11,      // IMU Port
    3.25,  // Wheel Diameter
    360);   // Wheel RPM = cartridge * (motor gear / wheel gear)

// Vertical Tracking Wheel
ez::tracking_wheel vert_tracker(-3, 2, -0.25);   // This tracking wheel is parallel to the drive wheels

// Horizontal Tracking Wheel
ez::tracking_wheel horiz_tracker(15, 2, -1.82);  // This tracking wheel is perpendicular to the drive wheels

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure


  // Look at your horizontal tracking wheel and decide if it's in front of the midline of your robot or behind it
  //  - change `back` to `front` if the tracking wheel is in front of the midline
  //  - ignore this if you aren't using a horizontal tracker
  chassis.odom_tracker_back_set(&horiz_tracker);
  // Look at your vertical tracking wheel and decide if it's to the left or right of the center of the robot
  //  - change `left` to `right` if the tracking wheel is to the right of the centerline
  //  - ignore this if you aren't using a vertical tracker
  chassis.odom_tracker_left_set(&vert_tracker);


  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);   // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0);   // Sets the active brake kP. We recommend ~2.  0 will disable.
  // chassis.opcontrol_curve_default_set(0.0, 0.0);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to the correct constants from autons.cpp
  default_constants();

  // Initialize chassis and auton selector
  chassis.initialize();
  pros::lcd::initialize();
  showSplashScreen();

  master.rumble(chassis.drive_imu_calibrated() ? "." : "---");

  //chassis.pid_tuner_disable();  // Enable the PID tuner, this gives you a GUI to tune your PID values live in the driver control period.  We recommend disabling this for competition runs.
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    // Show match start screen
    showMatchStartScreen();
    
    // Run the selected autonomous routine
    switch(autonSelection) {
        case 1:
            // Red Left Main
            pros::lcd::print(0, "Running Red Left Main");
            redLeftMain();
            break;
            
        case 2:
            // Red Right Main
            pros::lcd::print(0, "Running Red Right Main");
            redRightMain();
            break;
            
        case 3:
            // Red Left Elim
            pros::lcd::print(0, "Running Red Left Elim");
            redLeftElim();
            break;
            
        case 4:
            // Red Right Elim
            pros::lcd::print(0, "Running Red Right Elim");
            redRightElim();
            break;
            
        case 5:
            // Red SWP
            pros::lcd::print(0, "Running Red SWP");
            redSWP();
            break;
            
        case 6:
            // Blue Left Main
            pros::lcd::print(0, "Running Blue Left Main");
            blueLeftMain();
            break;
            
        case 7:
            // Blue Right Main
            pros::lcd::print(0, "Running Blue Right Main");
            blueRightMain();
            break;
            
        case 8:
            // Blue Left Elim
            pros::lcd::print(0, "Running Blue Left Elim");
            blueLeftElim();
            break;
            
        case 9:
            // Blue Right Elim
            pros::lcd::print(0, "Running Blue Right Elim");
            blueRightElim();
            break;
            
        case 10:
            // Blue SWP
            pros::lcd::print(0, "Running Blue SWP");
            blueSWP();
            break;

        case 11:
            // SKILLS
            pros::lcd::print(0, "Running SKILLS");
            skillsMain();
            break;
            
        default:
            // No selection
            pros::lcd::print(0, "No auton selected!");
            break;
    }
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  while (true) {

    chassis.opcontrol_tank();  // Tank control
 
    if (master.get_digital(DIGITAL_L1)) // Normal intake
    {
      setIntake(127);
    }
    else if (master.get_digital(DIGITAL_L2)) // Normal Intake Reverse
    {
      setIntake(-127);
    }
    else if (master.get_digital(DIGITAL_R1)) // Block Hold Intake
    {
      blockHold();
    }
    else if (master.get_digital(DIGITAL_R2)) // Block Hold Intake Stop
    {
      setIntake(0);
    }

    if (master.get_digital_new_press(DIGITAL_RIGHT)) // Stop Intake
    {
      centerGoalSwitch();
    }

    if (master.get_digital_new_press(DIGITAL_B)) // Matchload piston toggle
    {
      matchloadSwitch();
    }

    if (master.get_digital_new_press(DIGITAL_DOWN)) // Descore piston toggle
    {
      descoreSwitch();
    }
    
    /* Testing without a comp switch only
    if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) // Have the auton run if we hit the B and Down button makes it so we don't need to have a comp switch to test autons
    {
      autonomous();
    }
    */

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
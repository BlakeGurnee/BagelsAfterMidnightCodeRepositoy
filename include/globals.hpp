#include "main.h"

extern Drive chassis; // Declare the chassis so it can be used in other files

// -------- MOTORS -------- //
extern pros::Motor lowerIntake;
extern pros::Motor upperIntake;


// -------- PNEUMATICS -------- //
extern pros::adi::Pneumatics matchloadPiston;
extern pros::adi::Pneumatics parkPiston;
extern pros::adi::Pneumatics descorePiston;


// -------- SENSORS -------- //
extern pros::Optical optical_sensor;
extern pros::Distance frontSensor;
extern pros::Distance rightSensor;
extern pros::Distance parkSensor;
extern pros::Imu imu;

// -------- VARIABLES -------- //
extern int alliance;
extern bool Red_Alliance;
extern bool intakeActive;
extern int intakeState; // 1 = intake, -1 = outtake, 0 = off
#include "main.h"

extern Drive chassis; // Declare the chassis so it can be used in other files

// -------- MOTORS -------- //
extern pros::Motor lowerIntake;
extern pros::Motor upperIntake;


// -------- PNEUMATICS -------- //
extern pros::adi::Pneumatics matchloadPiston;
//extern pros::adi::Pneumatics centerGoalPiston;
extern pros::adi::Pneumatics descorePiston;


// -------- SENSORS -------- //
extern pros::Optical optical_sensor;
extern pros::Distance frontSensor;
extern pros::Distance rightSensor;
extern pros::Imu imu;

// -------- VARIABLES -------- //
extern bool Red_Alliance;
extern bool antiJamEnabled;
extern bool intakeActive;
extern int intakeState; // 0 = OFF, 1 = IN, -1 = OUT
#include "main.h"

extern Drive chassis; // Declare the chassis so it can be used in other files

// -------- MOTORS -------- //
extern pros::Motor lowerIntake;
extern pros::Motor upperIntake;


// -------- PNEUMATICS -------- //
extern pros::adi::Pneumatics matchloadPiston;
extern pros::adi::Pneumatics descorePiston;
extern pros::adi::Pneumatics centerGoalPiston;


// -------- SENSORS -------- //
extern pros::Distance backSensor;
extern pros::Distance rightSensor;
extern pros::Distance leftSensor;
extern pros::Imu imu;
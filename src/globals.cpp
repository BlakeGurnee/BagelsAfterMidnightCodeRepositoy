#include "main.h"

// -------- MOTORS --------//
pros::Motor lowerIntake(-4, pros::v5::MotorGears::blue); // Motor is a reversed blue motor on port 4 and is reversed
pros::Motor upperIntake(-5, pros::v5::MotorGears::blue); // Motor is a normal blue motor on port 5 and is reversed

// -------- PNEUMATICS --------//
pros::adi::Pneumatics descorePiston('A', false); // Starts descore in the false (Down) position when the code starts in port A
pros::adi::Pneumatics matchloadPiston('B', false); // Starts matchload in the true (Up) position when the code starts in port B


// -------- SENSORS --------//
pros::Distance backSensor(6); // Back Distance Sensor in port 6
pros::Distance rightSensor(20); // Right side Distance Sensor in port 20
pros::Distance leftSensor(7); // Left side Distance Sensor in port 7
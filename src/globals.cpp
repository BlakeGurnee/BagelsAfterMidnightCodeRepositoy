#include "main.h"

// -------- MOTORS --------//
pros::Motor lowerIntake(-4, pros::v5::MotorGears::blue); // Motor is a reversed blue motor on port 4
pros::Motor upperIntake(-5, pros::v5::MotorGears::blue); // Motor is a normal blue motor on port 16

// -------- PNEUMATICS --------//
pros::adi::Pneumatics matchloadPiston('B', false); // Starts matchload in the true (Up) position when the code starts in port A
pros::adi::Pneumatics descorePiston('A', false); // Starts descore in the false (Down) position when the code starts in port B
//pros::adi::Pneumatics matchloadPiston2('C', false); // Center goal Piston in port E

// -------- SENSORS --------//
pros::Optical optical_sensor(9); // Optical Sensor in port 9
pros::Distance backSensor(6); // Back Distance Sensor in port 6
pros::Distance rightSensor(20); // Right side Distance Sensor in port 20
pros::Distance leftSensor(7); // Left side Distance Sensor in port 2

// -------- VARIABLES --------//
int alliance = 1; // Default alliance is 1 which is red
bool intakeActive = false;
bool Red_Alliance = true;
int intakeState = 0; // 1 = intake, -1 = outtake, 0 = off
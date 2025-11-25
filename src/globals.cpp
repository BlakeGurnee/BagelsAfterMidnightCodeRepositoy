#include "main.h"

// -------- MOTORS --------//
pros::Motor lowerIntake(-4, pros::v5::MotorGears::blue); // Motor is a reversed blue motor on port 4
pros::Motor upperIntake(16, pros::v5::MotorGears::blue); // Motor is a normal blue motor on port 16

// -------- PNEUMATICS --------//
pros::adi::Pneumatics matchloadPiston('A', true); // Starts matchload in the true (Up) position when the code starts in port A
pros::adi::Pneumatics descorePiston('B', true); // Starts descore in the True (Up) position when the code starts in port B
pros::adi::Pneumatics parkPiston('C', true); // Starts the Park pistion in the True (Up) position when the code starts in port C

// -------- SENSORS --------//
pros::Optical optical_sensor(14); // Optical Sensor in port 14
pros::Distance frontSensor(12); // Front Distance Sensor in port 12
pros::Distance rightSensor(13); // Right side Distance Sensor in port 13
pros::Distance parkSensor(11); // Park Distance Sensor in port 11

// -------- VARIABLES --------//
int alliance = 1; // Default alliance is 1 which is red
bool intakeActive = false;
bool Red_Alliance = false;
int intakeState = 0; // 1 = intake, -1 = outtake, 0 = off
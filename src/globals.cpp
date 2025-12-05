#include "main.h"

// -------- MOTORS --------//
pros::Motor lowerIntake(15, pros::v5::MotorGears::blue); // Motor is a reversed blue motor on port 4
pros::Motor upperIntake(-2, pros::v5::MotorGears::blue); // Motor is a normal blue motor on port 16

// -------- PNEUMATICS --------//
pros::adi::Pneumatics matchloadPiston('A', false); // Starts matchload in the true (Up) position when the code starts in port A
pros::adi::Pneumatics descorePiston('B', false); // Starts descore in the false (Down) position when the code starts in port B
pros::adi::Pneumatics parkPistons('C', true); // Starts the Park pistions in the True (Up) position when the code starts in port C
pros::adi::Pneumatics parkPiston('D', true); // Single Solenoid piston for parking
pros::adi::Pneumatics centerGoalPiston('E', true); // Center goal Piston in port E

// -------- SENSORS --------//
pros::Optical optical_sensor(9); // Optical Sensor in port 9
pros::Distance frontSensor(8); // Front Distance Sensor in port 8
pros::Distance rightSensor(1); // Right side Distance Sensor in port 1
pros::Distance parkSensor(10); // Park Distance Sensor in port 10

// -------- VARIABLES --------//
int alliance = 1; // Default alliance is 1 which is red
bool intakeActive = false;
bool Red_Alliance = true;
int intakeState = 0; // 1 = intake, -1 = outtake, 0 = off
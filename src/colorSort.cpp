#include "colorSort.hpp"
#include "main.h"
#include "pros/apix.h"

pros::Task* colorTask = nullptr;

// Your same color logic, untouched
void colorSortControl() {
    double hue = optical_sensor.get_hue();
    bool incorrectColor = false;

    bool isRed = (hue < 30 || hue > 330);
    bool isBlue = (hue > 180 && hue < 250);

    if (Red_Alliance && isBlue) incorrectColor = true;
    if (!Red_Alliance && isRed) incorrectColor = true;

    if (!intakeActive) return;

    if (incorrectColor) {
        lowerIntake.move(127);
        upperIntake.move(-127);
        pros::delay(250);
        upperIntake.move(127);
        return;
    }

    if (intakeState == 1) setIntake(127);
    else if (intakeState == -1) {
        lowerIntake.move(127);
        upperIntake.brake();
    }
    else setIntake(0);
}

// Start the task
void startColorSortTask() {
    optical_sensor.set_led_pwm(100);
    optical_sensor.set_integration_time(5);
    if (colorTask == nullptr)
        colorTask = new pros::Task([] {
            while (true) {
                colorSortControl();
                pros::delay(20);
            }
        });
}

// Color sort stop function
void stopColorSortTask() {
    if (colorTask != nullptr) {
        colorTask->remove();
        delete colorTask;
        colorTask = nullptr;
    }
}

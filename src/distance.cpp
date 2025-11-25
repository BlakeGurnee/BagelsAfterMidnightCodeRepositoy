#include "main.h"

double mmToIn(double mm) { return mm / 25.4; }

void resetPoseWithDistance() {
    // read sensors
    double front = mmToIn(frontSensor.get());  // inches
    double right = mmToIn(rightSensor.get());  // inches

    // compute coordinates
    double x = 141 - right;
    double y = 141 - front;

    // read heading
    double theta = imu.get_heading();

    // update odometry
    chassis.odom_xyt_set(x, y, theta);
}


#include "distance.hpp"

double mmToIn(double mm) { return mm / 25.4; }

void resetPoseWithDistance() {
    // read sensors
    double front = mmToIn(backSensor.get_distance());  // inches
    double right = mmToIn(rightSensor.get_distance());  // inches
    double left = mmToIn(leftSensor.get_distance());  // inches

    // determine which side sensor is closest to wall and use that for x
    double closestSideDistance = (left < right) ? left : right;

    // compute coordinates
    double x = 141 - closestSideDistance;
    double y = 141 - front;

    // read heading
    double theta = imu.get_heading();

    // update odometry
    chassis.odom_xyt_set(x, y, theta);
}
#include "main.h"
#include <cmath>

using namespace okapi;
using namespace mik;

float wallPosConstant(wall_position wall) {
    switch (wall) {
        case wall_position::TOP_WALL: return 70.0;
        case wall_position::BOTTOM_WALL: return -70.0;
        case wall_position::LEFT_WALL: return -70.0;
        case wall_position::RIGHT_WALL: return 70.0;
    }
    return 0.0;
}

float sensorOffsetConstant(distance_position sensor) {
    switch (sensor) {
        case distance_position::FRONT_SENSOR: return 0.0;
        case distance_position::RIGHT_SENSOR: return 270.0;
    }
    return 0.0;
}

bool resetAxis(distance_position sensorPos,
                    wall_position wallPos,
                    float maxResetDistance) {

    // Get current odometry
    double odomX = chassis.odom_x_get();      // already in inches
    double odomY = chassis.odom_y_get();      // already in inches
    double heading = chassis.odom_theta_get(); // degrees

    // Pick the correct sensor
    pros::Distance* sensor = nullptr;
    if (sensorPos == distance_position::FRONT_SENSOR)
        sensor = &frontSensor;
    else if (sensorPos == distance_position::RIGHT_SENSOR)
        sensor = &rightSensor;
    else
        return false; // unsupported sensor

    // Compute new position based on sensor reading
    double distance = sensor->get(); // returns in millimeters
    distance /= 25.4;               // convert to inches

    double theta = heading + sensorOffsetConstant(sensorPos);
    double newPos = wallPosConstant(wallPos) - distance * cos(theta * M_PI / 180.0);

    bool resetX = (wallPos == wall_position::LEFT_WALL || wallPos == wall_position::RIGHT_WALL);

    if (resetX && fabs(newPos - odomX) < maxResetDistance) {
        chassis.odom_xyt_set(newPos * 1_in, odomY * 1_in, heading * 1_deg);
        pros::lcd::print(0, "Reset X OK");
        return true;
    }

    if (!resetX && fabs(newPos - odomY) < maxResetDistance) {
        chassis.odom_xyt_set(odomX * 1_in, newPos * 1_in, heading * 1_deg);
        pros::lcd::print(0, "Reset Y OK");
        return true;
    }

    pros::lcd::print(0, "Reset failed");
    return false;
}

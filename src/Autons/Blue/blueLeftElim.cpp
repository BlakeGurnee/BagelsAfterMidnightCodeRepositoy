#include "main.h"

void blueLeftElim() {
  // Your auton code here :)
  chassis.odom_x_flip();
  chassis.odom_y_flip();
  chassis.odom_theta_flip();
  redLeftElim();
}
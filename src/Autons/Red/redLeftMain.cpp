#include "main.h"

void redLeftMain() {
  // Your auton code here :)
  chassis.odom_y_flip();
  chassis.odom_theta_flip();
  redRightMain();
}
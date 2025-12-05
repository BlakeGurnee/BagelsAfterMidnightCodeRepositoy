#include "main.h"

void blueLeftMain() {
  // Your auton code here :)
  chassis.odom_x_flip();
  chassis.odom_y_flip(); // If auton is messsed up this would probably be why
  chassis.odom_theta_flip();
  redRightMain();
}
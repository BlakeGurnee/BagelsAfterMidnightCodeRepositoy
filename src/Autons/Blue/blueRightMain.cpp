#include "main.h"

void blueRightMain() {
  // Your auton code here :)
  chassis.odom_x_flip();
  chassis.odom_y_flip();
  redRightMain();
}
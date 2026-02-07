#include "main.h"

void blueRightSWP() {
  // Your auton code here :)
  chassis.odom_x_flip();
  chassis.odom_y_flip();
  redRightSWP();
}
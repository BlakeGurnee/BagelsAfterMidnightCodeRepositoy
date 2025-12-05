#include "main.h"

void blueRightElim() {
  // Your auton code here :)
  chassis.odom_x_flip();
  chassis.odom_y_flip();
  redRightElim();
}
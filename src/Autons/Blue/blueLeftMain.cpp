#include "main.h"

void blueLeftMain() {
  // Your auton code here :)
  chassis.odom_x_flip();
  chassis.odom_y_flip(); 
  redRightMain();
}
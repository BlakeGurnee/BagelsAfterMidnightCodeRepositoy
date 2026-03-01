#include "main.h"

void redLeftElim() {
  chassis.odom_y_flip();
  chassis.odom_theta_flip();
  redRightElim();
}
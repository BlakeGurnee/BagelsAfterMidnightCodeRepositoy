#ifndef SPLASH_SCREENS_HPP
#define SPLASH_SCREENS_HPP

#include "main.h"

// Declare your converted images
LV_IMG_DECLARE(midnight_bagels_splash);
LV_IMG_DECLARE(bagels_match_start);

// Team colors - Midnight Blue and White
#define MIDNIGHT_BLUE lv_color_make(25, 25, 60)
#define BAGELS_WHITE lv_color_make(255, 255, 255)
#define BAGELS_YELLOW lv_color_make(255, 223, 0)
#define BAGELS_RED lv_color_make(200, 0, 0)
#define BAGELS_BLUE lv_color_make(0, 100, 200)

// Global variables
extern int autonSelection;
extern bool autonConfirmed;

// Function declarations
void showSplashScreen();
void createAutonSelector();
void showMatchStartScreen();

#endif
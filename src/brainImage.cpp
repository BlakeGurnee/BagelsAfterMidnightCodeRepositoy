#include "main.h"
#include "brainImage.hpp"
lv_obj_t* image;


void display_img_c_array()
{
    // create a variable for the c array (image)
    LV_IMG_DECLARE(Image);

    // declare and define the image object
    image = lv_img_create(lv_scr_act());

    // set the image source and size
    lv_img_set_src(image, &Image);
    lv_obj_set_size(image, 480, 272);

    // align the image to the center of the screen
    lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);
}
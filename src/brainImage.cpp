#include "main.h"


void display_img_from_file()
{
    // declare and define the image object
    lv_obj_t* img = lv_img_create(lv_scr_act());

    // set the source data for the image
    lv_img_set_src(img, "S:/logo.bin");

    // align image
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
}
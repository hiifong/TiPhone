//
// Created by hiifong on 2024/7/21.
//

#ifndef INIT_H
#define INIT_H

#include "lvgl/lvgl.h"

// ==> background image start
LV_IMAGE_DECLARE(iphone15bg);
// <== background image end

// ==> icon start
LV_IMAGE_DECLARE(brightness);
LV_IMAGE_DECLARE(calculator);
LV_IMAGE_DECLARE(calendar);
LV_IMAGE_DECLARE(camera);
LV_IMAGE_DECLARE(dashboard);
LV_IMAGE_DECLARE(fileview);
LV_IMAGE_DECLARE(hdmiin);
LV_IMAGE_DECLARE(health);
LV_IMAGE_DECLARE(key);
LV_IMAGE_DECLARE(led);
LV_IMAGE_DECLARE(linkman);
LV_IMAGE_DECLARE(music);
LV_IMAGE_DECLARE(notepad);
LV_IMAGE_DECLARE(pcba);
LV_IMAGE_DECLARE(photoview);
LV_IMAGE_DECLARE(player);
LV_IMAGE_DECLARE(printbrush);
LV_IMAGE_DECLARE(reader);
LV_IMAGE_DECLARE(recorder);
LV_IMAGE_DECLARE(reminders);
LV_IMAGE_DECLARE(settings);
LV_IMAGE_DECLARE(slideshow);
LV_IMAGE_DECLARE(udpchat);
LV_IMAGE_DECLARE(weather);
// <== icon end

void init();

#endif //INIT_H

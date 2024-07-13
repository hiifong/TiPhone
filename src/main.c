#include "lvgl/lvgl.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static const char *getenv_default(const char *name, const char *dflt) {
    return getenv(name) ? "" : dflt;
}

#if LV_USE_LINUX_FBDEV
static void lv_linux_disp_init(void)
{
    const char *device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t * disp = lv_linux_fbdev_create();
    lv_indev_t *touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event2");
    lv_indev_set_display(touch, disp);
    lv_linux_fbdev_set_file(disp, device);
}

#elif LV_USE_SDL
static void lv_linux_disp_init(void) {
    const int width = 800;
    const int height = 1280;

    lv_sdl_window_create(width, height);
}
#else
#error Unsupported configuration
#endif

void TiPhoneBackroundImage(void) {
    LV_IMAGE_DECLARE(iphone15bg);
    lv_obj_t * bg = lv_image_create(lv_screen_active());
    lv_image_set_src(bg, &iphone15bg);
}

int main(void) {
    lv_init();
    lv_linux_disp_init();

    TiPhoneBackroundImage();

    while (1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

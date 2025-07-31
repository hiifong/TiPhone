//
// Created by hiifong on 2024/7/21.
//

#include "init.h"

static const char * getenv_default(const char * name, const char * dflt)
{
    return getenv(name) ? "" : dflt;
}

#if LV_USE_LINUX_FBDEV
static void lv_linux_disp_init(void)
{
    const char * device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t * disp = lv_linux_fbdev_create();
    lv_indev_t * touch  = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event2");
    lv_indev_set_display(touch, disp);
    lv_linux_fbdev_set_file(disp, device);
}
#elif LV_USE_LINUX_DRM
static void lv_linux_disp_init(void)
{
    const char *device = getenv_default("LV_LINUX_DRM_CARD", "/dev/dri/card0");
    lv_display_t * disp = lv_linux_drm_create();

    lv_linux_drm_set_file(disp, device, -1);
}
#elif LV_USE_SDL
static void lv_linux_disp_init(void)
{
    const int width  = 800;
    const int height = 1280;

    lv_sdl_window_create(width, height);
    lv_sdl_mouse_create();
    lv_sdl_mousewheel_create();
    lv_sdl_keyboard_create();
}
#else
#error Unsupported configuration
#endif

void init() {
    lv_init();
    lv_linux_disp_init();
}

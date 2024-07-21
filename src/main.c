#include "init.h"
#include "dock/dock.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



static void btn_event_cb(lv_event_t * e)
{
    LV_LOG_INFO("Clicked");
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn       = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

void demo(void)
{
    lv_obj_t * img;

    img = lv_image_create(lv_screen_active());
    lv_image_set_src(img, &iphone15bg);
    lv_obj_center(img);

    lv_obj_t * btn = lv_button_create(lv_screen_active());

    lv_obj_set_size(btn, 120, 40);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 300);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);

    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    lv_obj_t * qr = lv_qrcode_create(lv_screen_active());
    lv_qrcode_set_size(qr, 400);
    lv_qrcode_set_dark_color(qr, fg_color);
    lv_qrcode_set_light_color(qr, bg_color);

    /*Set data*/
    const char * data = "https://hiif.ong";
    lv_qrcode_update(qr, data, strlen(data));
    lv_obj_center(qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);

    // Dock
    t_dock_item item1 = {
        .title = "udpchat",
        .icon  = &udpchat,
    };
    t_dock_item item2 = {
        .title = "linkman",
        .icon  = &linkman,
    };
    t_dock_item item3 = {
        .title = "camera",
        .icon  = &camera,
    };
    t_dock_item item4 = {
        .title = "photoview",
        .icon  = &photoview,
    };
    t_dock_item item5 = {
        .title = "settings",
        .icon  = &settings,
    };
    t_dock_obj dock = {
        .len  = 5,
        .list = {item1, item2, item3, item4, item5},
    };
    lv_obj_t * obj = t_create_dock(lv_screen_active(), &dock);
    lv_obj_center(obj);
}

int main(void)
{
    init();
    demo();

    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

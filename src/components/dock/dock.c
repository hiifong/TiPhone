#include "dock/dock.h"

static void msg_box_event_cb(lv_event_t * e)
{
    lv_obj_t * btn   = lv_event_get_target(e);
    lv_obj_t * label = lv_obj_get_child(btn, 0);
    LV_LOG_INFO("Clicked botton label is %s", lv_label_get_text(label));
}
static void clicked_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char * title = lv_event_get_user_data(e);
    if(code == LV_EVENT_CLICKED) {
        LV_LOG_INFO("Clicked item title: %s", title);
        lv_obj_t * mb = lv_msgbox_create(NULL);

        lv_msgbox_add_title(mb, title);

        lv_msgbox_add_text(mb, "This is a message box with two buttons.");
        lv_msgbox_add_close_button(mb);

        lv_obj_t * btn;
        btn = lv_msgbox_add_footer_button(mb, "Apply");
        lv_obj_add_event_cb(btn, msg_box_event_cb, LV_EVENT_CLICKED, NULL);
        btn = lv_msgbox_add_footer_button(mb, "Cancel");
        lv_obj_add_event_cb(btn, msg_box_event_cb, LV_EVENT_CLICKED, NULL);
    }
}

lv_obj_t * t_create_dock(lv_obj_t * parent, t_dock_obj * dock)
{
    lv_obj_t * cont_row = lv_obj_create(parent);
    lv_obj_set_size(cont_row, 700, 165);
    lv_obj_align(cont_row, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_obj_set_flex_flow(cont_row, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_align(cont_row, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    static lv_style_t style;
    lv_style_init(&style);

    /*Set a background color and a radius*/
    lv_style_set_radius(&style, 20);
    lv_style_set_bg_opa(&style, LV_OPA_20);
    lv_obj_add_style(cont_row, &style, 0);
    for(uint8_t i = 0; i < dock->len; i++) {
        lv_obj_t * obj = lv_imagebutton_create(cont_row);
        lv_obj_set_size(obj, 120, 120);
        lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
        lv_imagebutton_set_src(
            obj,
            LV_IMAGEBUTTON_STATE_RELEASED,
            dock->list[i].icon,
            dock->list[i].icon,
            dock->list[i].icon
        );
        lv_obj_add_event_cb(obj, clicked_event_cb, LV_EVENT_CLICKED, dock->list[i].title);
    }

    return parent;
}

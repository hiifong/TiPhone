#ifndef T_DOCK_H
#define T_DOCK_H

#include "components.h"

typedef struct dock_item
{
    char * title;
    lv_image_dsc_t * icon;
} t_dock_item;

typedef struct dock
{
    uint8_t len;
    t_dock_item list[5];
} t_dock_obj;

lv_obj_t * t_create_dock(lv_obj_t * obj, t_dock_obj * dock);

#endif
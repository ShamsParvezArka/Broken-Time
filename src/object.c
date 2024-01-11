#include "object.h"
#include "literals.h"

Object2D objects[] = {
    {STATIC_ONE_WAY, {0, WINDOW_HEIGHT - 30, WINDOW_WIDTH, 30}},
    {STATIC_ONE_WAY, {30, WINDOW_HEIGHT - 100, 100, 30}},
    {STATIC_ONE_WAY, {350, WINDOW_HEIGHT- 100, 100, 30}},
};

size_t object_count = sizeof(objects)/sizeof(objects[0]);

void draw_object_hitbox(Object2D *objects)
{
    for (int i = 0; i < object_count; i++) {
        Rectangle hitbox = objects[i].hitbox;
        Color hitbox_color = WHITE;
        DrawRectangleLinesEx((Rectangle) { hitbox.x, hitbox.y, hitbox.width, hitbox.height }, 1.0f, hitbox_color);
    }
}


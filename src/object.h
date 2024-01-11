#ifndef OBJECT_H_
#define OBJECT_H_

#include <raylib.h>

typedef enum {
    STATIC_ONE_WAY = 0,
    STATIC_BOTH_WAY = 2,
    BACKGROUND = 3
} Object_Type;

typedef struct Object2D {
    Object_Type type;
    Rectangle hitbox;
} Object2D;

extern Object2D objects[];
extern size_t object_count;

extern void draw_object_hitbox(Object2D *objects);

#endif

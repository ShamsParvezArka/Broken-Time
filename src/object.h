#ifndef OBJECT_H_
#define OBJECT_H_

#include <raylib.h>

typedef enum {
    STATIC = 0,
    BACKGROUND = 1
} Object_Type;

typedef struct Object2D {
    Object_Type type;
    Rectangle hitbox;
} Object2D;

extern Object2D objects[];
extern size_t object_count;

#endif

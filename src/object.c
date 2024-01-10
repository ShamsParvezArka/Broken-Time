#include "object.h"

Object2D objects[] = {
    {STATIC, {0, 450 - 30, 800, 30}},
    {STATIC, {30, 450 - 100, 100, 30}},
    {STATIC, {350, 450- 100, 100, 30}},
};

size_t object_count = sizeof(objects)/sizeof(objects[0]);

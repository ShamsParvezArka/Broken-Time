#ifndef ENTITY_H_
#define ENTITY_H_

#include <stdlib.h>
#include <assert.h>
#include "raylib.h"

typedef struct Component_List {
	size_t index;
	size_t size;
	Rectangle *es;
} Component_List;

Component_List component_list_alloc(size_t size);
void component_list_push(Component_List *dst, Rectangle rec);
void component_list_free(Component_List c);
void render_component_list(Component_List c);

#endif //ENTITY_H_

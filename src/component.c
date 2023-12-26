#include "component.h"

Component_List component_list_alloc(size_t size)
{
	Component_List c;
	c.index = 0;
	c.size = size;
	c.es = COMPONENT_ALLOC(sizeof(*c.es) * size);
	assert(c.es != NULL);

	return c;
}

void component_list_push(Component_List *dst, Rectangle rec)
{
	if (dst->index > (size_t) (dst->size * 70) / 100) {
		size_t new_size = dst->size + 20;
		dst->es = COMPONENT_REALLOC(dst->es, sizeof(*dst->es) * new_size);
		dst->size = new_size;
	}
	dst->es[dst->index] = rec;
	dst->index += 1;
}

void render_component_list(Component_List c)
{
	for (size_t i = 0; i < c.index; i++)
		DrawRectangleRec(c.es[i], WHITE);
}

void component_list_free(Component_List c)
{
	free(c.es);
}
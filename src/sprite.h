#ifndef SPRITE_H_
#define SPRITE_H_

#include "raylib.h"
#include "util.h"

typedef struct Sprite2D {
	Texture2D texture;
	Dimension2D frame;
	float zoom;
	Rectangle source;
	Rectangle destination;
	Vector2 origin;
} Sprite2D;

extern Sprite2D load_sprite(const char *filename, float zoom);
extern void sprite_set_position_x(Sprite2D *sprite, int x);
extern void sprite_set_position_y(Sprite2D *sprite, int y);
extern void sprite_set_frame(Sprite2D *sprite, float frame_width, float frame_height);
extern void sprite_set_zoom(Sprite2D *sprite, float zoom);
extern void sprite_flip_horizontal(Sprite2D *sprite);
extern void draw_sprite(Sprite2D sprite, Color tint);

#endif


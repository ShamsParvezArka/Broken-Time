#include "literals.h"
#include "sprite.h"

Sprite2D load_sprite(const char *filename, float zoom)
{
	Texture2D texture = LoadTexture(filename);
	float frame_width = texture.width;
	float frame_height = texture.height;
	Rectangle source = {0.0f, 0.0f, frame_width, frame_height};
	Rectangle dest = {0.0f, 0.0f, frame_width*zoom, frame_height*zoom};
	Vector2 origin = {0.0f, 0.0f};

	Sprite2D sprite = {
		.texture = texture,
		.frame = {frame_width, frame_height},
		.zoom = zoom,
		.source = source,
		.destination = dest,
		.origin = origin
	};
	return sprite;
}

void sprite_set_position_x(Sprite2D *sprite, int x)
{
	sprite->destination.x = (float) x;
	
}

void sprite_set_position_y(Sprite2D *sprite, int y)
{
	sprite->destination.y = (float) y;
}

void sprite_set_frame(Sprite2D *sprite, float frame_width, float frame_height)
{
	sprite->frame.width = frame_width;
	sprite->frame.height = frame_height;

	sprite->source.width = frame_width;
	sprite->source.height = frame_height;
	sprite->destination.width = frame_width*sprite->zoom;
	sprite->destination.height = frame_height*sprite->zoom;
}

void sprite_set_zoom(Sprite2D *sprite, float zoom)
{
	sprite->zoom = zoom;
	sprite->destination.width = sprite->frame.width*zoom;
	sprite->destination.height = sprite->frame.height*zoom;
}

void sprite_flip_horizontal(Sprite2D *sprite)
{
	sprite->source.width *= -1;
}

void draw_sprite(Sprite2D sprite, Color tint)
{
	DrawTexturePro(sprite.texture, sprite.source, sprite.destination, sprite.origin, 0, tint);
}
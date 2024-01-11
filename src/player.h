#ifndef PLAYER_H_
#define PLAYER_H_

#include "object.h"
#include "sprite.h"
#include "util.h"

typedef struct Player2D {
	Vector2 position;
	Dimension2D dimension;
	float velocity;
	int available_jumps;
	bool can_jump;
	Sprite2D sprite;
} Player2D;

extern Player2D player;

extern void init_player_sprite();
extern void update_player(Player2D *player, Object2D *objects, float dt);
extern void apply_gravity(Player2D *player, float dt);
extern void jump(Player2D *player);
extern bool check_collision(Player2D *player, Object2D *objects, float dt);
extern void draw_player_hitbox(Player2D player);

#endif

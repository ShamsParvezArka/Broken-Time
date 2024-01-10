#ifndef PLAYER_H_
#define PLAYER_H_

#include "object.h"

#define ACCELARATION_RATE 400
#define JUMP_FORCE 200
#define HORIZONTAL_VELOCITY 150
#define JUMP_MAX 2

typedef struct Dimension2D {
	float width;
	float height;
} Dimension2D;

typedef struct Player2D {
	Vector2 position;
	Dimension2D dimension;
	float velocity;
	int available_jumps;
	bool can_jump;
} Player2D;

extern Player2D player;

extern void update_player(Player2D *player, Object2D *objects, float dt);
extern void apply_gravity(Player2D *player, float dt);
extern void jump(Player2D *player);
extern bool check_collision_detection(Player2D *player, Object2D *objects, float dt);

#endif

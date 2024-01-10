#include "player.h"

Player2D player = {
	.position = {800/2.0f, 450/2.0f},
	.dimension = {30.0f, 30.0f},
	.velocity = 0,
	.available_jumps = JUMP_MAX,
	.can_jump = true
};

void update_player(Player2D *player, Object2D *objects, float dt)
{
	if (IsKeyDown(KEY_A))
		player->position.x -= HORIZONTAL_VELOCITY * dt;
	if (IsKeyDown(KEY_D))
		player->position.x += HORIZONTAL_VELOCITY * dt;
	if (IsKeyPressed(KEY_W) && player->can_jump) {
		jump(player);
	}

	if (!check_collision_detection(player, objects, dt))
		apply_gravity(player, dt);
}

void apply_gravity(Player2D *player, float dt)
{
	player->position.y += player->velocity*dt;
	player->velocity += ACCELARATION_RATE*dt;
}

bool check_collision_detection(Player2D *player, Object2D *objects, float dt)
{
	for (size_t i = 0; i < object_count; i++) {
		Rectangle object = objects[i].hitbox;
		Object_Type object_type = objects[i].type;
		if (object_type == STATIC &&
			object.x <= player->position.x &&
			object.x + object.width >= player->position.x &&
			object.y >= player->position.y &&
			object.y <= player->position.y + player->velocity*dt) {

			player->available_jumps = JUMP_MAX;
			player->can_jump = true;
			player->velocity = 0.0f;
			player->position.y = object.y - player->dimension.height;
			return true;
		}
	}
	return false;
}

void jump(Player2D *player)
{
	player->velocity = -JUMP_FORCE;
	player->available_jumps--;
	//printf("aj: %d\n", player->available_jumps);
	if (player->available_jumps <= 0) {
		player->can_jump = false;
		return;
	}
}
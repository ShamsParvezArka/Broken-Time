#include "literals.h"
#include "player.h"
#include "sprite.h"

Player2D player = {
	.position = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f},
	.dimension = {30.0f, 30.0f},
	.velocity = 0,
	.available_jumps = JUMP_MAX,
	.can_jump = true,
	.sprite = NULL
};

void init_player_sprite()
{
	Sprite2D s = load_sprite("assets/player/idle.png", 1.0f);
	sprite_set_frame(&s, s.frame.width/10, s.frame.height);
	sprite_set_position_x(&s, player.position.x);
	sprite_set_position_y(&s, player.position.y);
	player.dimension.width = s.frame.width;
	player.dimension.height = s.frame.height;

	player.sprite = s;

}

void update_player(Player2D *player, Object2D *objects, float dt)
{
	if (IsKeyDown(KEY_A)) {
		if (player->sprite.source.width > 0)
			sprite_flip_horizontal(&player->sprite);
		player->position.x -= HORIZONTAL_VELOCITY*dt;
		sprite_set_position_x(&player->sprite, player->position.x);
	}
	if (IsKeyDown(KEY_D)) {
		if (player->sprite.source.width < 0)
			sprite_flip_horizontal(&player->sprite);
		player->position.x += HORIZONTAL_VELOCITY*dt;
		sprite_set_position_x(&player->sprite, player->position.x);
	}
	if (IsKeyPressed(KEY_W) && player->can_jump) {
		jump(player);
	}
	if (!check_collision(player, objects, dt))
		apply_gravity(player, dt);
}

void apply_gravity(Player2D *player, float dt)
{
	player->position.y += player->velocity*dt;
	sprite_set_position_y(&player->sprite, player->position.y);
	player->velocity += ACCELARATION_RATE*dt;
}

bool check_collision(Player2D *player, Object2D *objects, float dt)
{
	for (size_t i = 0; i < object_count; i++) {
		Rectangle object = objects[i].hitbox;
		Object_Type object_type = objects[i].type;
		if (object_type == STATIC_ONE_WAY &&
			player->position.y + player->dimension.height <= object.y &&
			object.x <= player->position.x + player->dimension.width &&
			object.x + object.width >= player->position.x &&
			object.y <= player->position.y + player->dimension.height + player->velocity*dt &&
			object.y + object.height >= player->position.y) {

			player->available_jumps = JUMP_MAX;
			player->can_jump = true;
			player->velocity = 0.0f;
			//player->position.y = object.y;// - player->dimension.height;
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

void draw_player_hitbox(Player2D player)
{
	DrawRectangleLinesEx((Rectangle) {player.position.x, player.position.y, player.dimension.width, player.dimension.height}, 2.0f, WHITE);
	draw_sprite(player.sprite, WHITE);
}

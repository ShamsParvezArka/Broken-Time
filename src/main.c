#define _CRT_NO_SECURE_WARNIGNS

#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>

#include "player.h"
#include "object.h"
#include "literals.h"
#include "sprite.h"
#include "util.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Broken Time");
	SetTargetFPS(60);

	init_player_sprite();
	
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		update_player(&player, objects, dt);
		BeginDrawing();
		{
			ClearBackground(BLACK);
			draw_object_hitbox(objects);
			draw_player_hitbox(player);
		}
		EndDrawing();
	}

	return 0;
}

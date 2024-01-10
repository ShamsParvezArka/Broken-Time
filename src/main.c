#define _CRT_NO_SECURE_WARNIGNS

#include <stdio.h>
#include <stdbool.h>

#include "player.h"
#include "object.h"

int main()
{
	const int window_width = 800;
	const int window_height = 450;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(window_width, window_height, "Broken Time");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		update_player(&player, objects, dt);
		BeginDrawing();
		{
			ClearBackground(BLACK);
			for (int i = 0; i < object_count; i++) {
				DrawRectangleRec((Rectangle) { objects[i].hitbox.x, objects[i].hitbox.y, objects[i].hitbox.width, objects[i].hitbox.height }, GRAY);
			}
			DrawRectangleLinesEx((Rectangle) { player.position.x, player.position.y, player.dimension.width, player.dimension.height }, 2.0f, WHITE);
		}
		EndDrawing();
	}

	return 0;
}

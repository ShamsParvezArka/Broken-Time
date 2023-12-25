#include <stdio.h>
#include "component.h"

float randf(float min, float max);

int main()
{
	const int window_width = 480;
	const int window_height = 270;
	const char *title = "Broken Time";
	InitWindow(window_width, window_height, title);

	Component_List hitbox_list = component_list_alloc(10);
	printf("COMPONENT SIZE: %zu\n", sizeof(hitbox_list));
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		Rectangle hb = {
			randf(0.0f, (float) window_width),
			randf(0.0f, (float) window_height),
			10.0f,
			10.0f
		};
		component_list_push(&hitbox_list, hb);
	}

	while (!WindowShouldClose()) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Rectangle new_hb = {
				GetMousePosition().x,
				GetMousePosition().y,
				10.0f,
				10.0f
			};
			component_list_push(&hitbox_list, new_hb);
			printf("(SIZE, INDEX): (%zu, %zu)\n", hitbox_list.size, hitbox_list.index);
		}
		
		BeginDrawing();
		{
			ClearBackground(BLACK);
			render_component_list(hitbox_list);
		}
		EndDrawing();
	}
	CloseWindow();

	return 0;
}

float randf(float min, float max)
{
	float magic_n = (float) rand() / (float) RAND_MAX * max;

	return magic_n < min ? magic_n + min : magic_n;
}

int main2()
{
	const int window_width = 480;
	const int window_height = 270;
	const char *game_title = "Broken Time";

	InitWindow(window_width, window_height, game_title);
	
	Image map = LoadImage("assets/maps/map.png");
	Texture2D map_texture = LoadTextureFromImage(map);
	UnloadImage(map);

#if 1
	Image player = LoadImage("assets/player/idle.png");
	Texture2D player_texture = LoadTextureFromImage(player);
	UnloadImage(player);
	Rectangle player_frame = {
		0.0f, 
		0.0f, 
		(float) player_texture.width / 10, 
		(float) player_texture.height
	};
	Vector2 player_position = {60.0f, 124.0f};
	
	Rectangle player_hit_box = {
		player_position.x + 10, 
		player_position.y + 5, 
		player_frame.width - 20, 
		player_frame.width - 5
	};
#endif

	int current_frame = 0;
	int frame_counter = 0;
	int frame_speed = 8;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		frame_counter++;
		if (frame_counter >= (60 / frame_speed)) {
			frame_counter = 0;
			current_frame++;

			if (current_frame > 10) 
				current_frame = 0;
			player_frame.x = (float) current_frame * (float) player.width / 10;
		}
		BeginDrawing();
		{
			DrawTexture(map_texture, 0, 0, WHITE);
			DrawTextureRec(player_texture, player_frame, player_position, WHITE);
			DrawRectangleLinesEx(player_hit_box, 1.0f, WHITE);

		}
		EndDrawing();
	}

	return 0;
}

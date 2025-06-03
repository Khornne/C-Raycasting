#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int screenWidth = 1024;
const int screenHeight = 512;
int map_x = 8, map_y = 8, map_s = 64;
Vector2 playerPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

const uint8_t map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

#define TILE_SIZE 40

void display_map2D(const uint8_t map[10][10]) {
  for (uint8_t row = 0; row < 10; row++) {
    for (uint8_t col = 0; col < 10; col++) {
      Color color = BLACK;
      if (map[row][col] == 1) {
        color = WHITE;
      };
      DrawRectangle(col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE,
                    color);
    };
  }
}

void display_player2D() { DrawCircleV(playerPosition, 5, RED); }

// Player movement
void player_movement() {
  if (IsKeyDown(KEY_W))
    playerPosition.y -= 2.0f;
  if (IsKeyDown(KEY_S))
    playerPosition.y += 2.0f;
  if (IsKeyDown(KEY_A))
    playerPosition.x -= 2.0f;
  if (IsKeyDown(KEY_D))
    playerPosition.x += 2.0f;
};

// Initialise and Draws window

int main(void) {
  SetTargetFPS(60);
  InitWindow(screenWidth, screenHeight, "Raycaster");

  while (!WindowShouldClose()) {
    player_movement();
    BeginDrawing();

    ClearBackground(GRAY);

    display_map2D(map);
    display_player2D();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

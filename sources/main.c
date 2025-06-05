#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// DEFINES
#define TILE_SIZE 55

// GLOBALS
const int screenWidth = 1024;
const int screenHeight = 512;

const uint8_t map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

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

void display_player2D(const Vector2 position) {
  DrawCircle(position.x * TILE_SIZE + TILE_SIZE / 2,
             position.y * TILE_SIZE + TILE_SIZE / 2, 6, RED);
};

// Player movement
void player_movement() {
  double playerX = 2.0;
  double playerY = 2.0;
  double player_angle = 0;

  if (IsKeyDown(KEY_W)) {
    playerX += cos(player_angle) * 0.01;
    playerY += sin(player_angle) * 0.01;
  }
  if (IsKeyDown(KEY_S)) {
    playerX -= cos(player_angle) * 0.01;
    playerY -= sin(player_angle) * 0.01;
  }
  if (IsKeyDown(KEY_A)) {
    player_angle -= 0.5;
  }
  if (IsKeyDown(KEY_D)) {
    player_angle += 0.5;
  }
};

// Initialise and Draws window

int main(void) {
  SetTargetFPS(60);
  InitWindow(screenWidth, screenHeight, "Raycaster");

  while (!WindowShouldClose()) {
    Vector2 playerPosition = (Vector2){1, 1};
    player_movement();
    BeginDrawing();

    ClearBackground(GRAY);

    display_map2D(map);
    display_player2D(playerPosition);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

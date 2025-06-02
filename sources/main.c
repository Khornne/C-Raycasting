#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int screenWidth = 1024;
const int screenHeight = 512;
Vector2 playerPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

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
int display(void) {
  SetTargetFPS(60);
  InitWindow(screenWidth, screenHeight, "Raycaster");

  while (!WindowShouldClose()) {
    player_movement();
    BeginDrawing();
    ClearBackground(GRAY);
    DrawCircleV(playerPosition, 10, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

int main(int argc, char *argv[]) {
  display();
  return 0;
}

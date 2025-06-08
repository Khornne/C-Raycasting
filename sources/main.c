#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// DEFINES
#define mapWidth 10
#define mapHeight 10
#define screenWidth 1280
#define screenHeight 720

int worldMap[mapWidth][mapHeight] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 2, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 2, 2, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 3, 0, 3, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main() {
  double playerX = 2.0, playerY = 2.0; // x and y start postition
  double dirX = -1, dirY = 0;          // intial direction vector
  double planeX = 0, planeY = 0.66;    // 2d raycaster version of camera plane

  double time = 0;    // time of current frame
  double oldTime = 0; // time of previous frame

  printf("Starting Game....\n");

  InitWindow(screenWidth, screenHeight, "Raycaster");
  SetTargetFPS(60);

  // Main Loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

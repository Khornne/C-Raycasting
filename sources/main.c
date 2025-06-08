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
    // calculate ray position and direction
    for (int i = 0; i < screenWidth; i++) {
      double cameraX =
          2 * i / (double)screenWidth - 1; // x-coord in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;

      // Which box of the map we're in
      int mapX = (int)playerX;
      int mapY = (int)playerY;

      // length of ray from current pos
      double sideDistX;
      double sideDistY;
      double prepWallDist;

      // Length of ray from y or x side to next y or x side
      double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
      double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

      // Direction to step in x or y-direction (+1 or 1)
      int stepX;
      int stepY;

      int hit = 0; // check for wall collision
      int side;

      // Calculate step and initial sideDist
      if (rayDirX < 0) {
        stepX = -1;
        sideDistX = (playerX - mapX) * deltaDistX;
      } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - playerX) * deltaDistX;
      }
    }
    BeginDrawing();
    ClearBackground(GRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

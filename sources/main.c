#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINES
#define mapWidth 10
#define mapHeight 10
#define screenWidth 1280
#define screenHeight 720
#define brightMax -0.1
#define brightMin -0.9
#define FOV 8;
#define rayStep 0.01

// give x and y sides different brightness
double brightness(double rayDist) {
  if (brightMin + 1 / rayDist > brightMax) {
    return brightMax;
  } else {
    return brightMin + 1 / rayDist;
  }
}

int worldMap[mapWidth][mapHeight] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 2, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 2, 2, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 3, 0, 3, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main() {
  double playerX = 2.0, playerY = 2.0; // x and y start postition
  double playerAngle = 0;
  double fov = FOV

      printf("Starting Game....\n");

  InitWindow(screenWidth, screenHeight, "Raycaster");
  SetTargetFPS(60);

  // Main Loop
  while (!WindowShouldClose()) {

    if (IsKeyDown(KEY_W)) {
      playerX += cos(playerAngle) * 0.01;
      playerY += sin(playerAngle) * 0.01;
    }
    if (IsKeyDown(KEY_S)) {
      playerX -= cos(playerAngle) * 0.01;
      playerY -= sin(playerAngle) * 0.01;
    }
    if (IsKeyDown(KEY_A)) {
      playerAngle -= 0.05;
    }
    if (IsKeyDown(KEY_D)) {
      playerAngle += 0.05;
    }
    BeginDrawing();
    ClearBackground(GRAY);
    // start for loop for each column of pixels on screen
    for (int i = 0; i < screenWidth; i++) {
      // Ray angle by removing half of the FOC from the player angle thne slowly
      // adding FOV to ray angle
      double rayAngle =
          (playerAngle - fov / 2.0) + ((double)i / (double)screenWidth) * fov;
      bool hitWall = false;
      double rayDist = 0;
      double eyeX = cos(rayAngle);
      double eyeY = sin(rayAngle);

      // Test if ray angle intersects
      int testX = (int)(playerX + eyeX * rayDist);
      int testY = (int)(playerY + eyeY * rayDist);

      // Ray cassting loop
      while (!hitWall) {
        rayDist += rayStep * sqrt(eyeX * eyeX + eyeY + eyeY);
        // Create plane that casts rays out of player
        testX = (int)(playerX + eyeX * rayDist);
        testY = (int)(playerY + eyeY * rayDist);

        // Multiply ray distance to increase distance travelled
        if (testX < 0 || testX > screenWidth || testY > screenHeight ||
            testY < 0) {
          hitWall = true;
          rayDist = 20.0;
        } else {
          if (worldMap[testX][testY] > 0) {
            hitWall = true;
          }
        }
      }
    }
  }
  DrawFPS(10, 10);
  EndDrawing();
  CloseWindow();
  return 0;
}

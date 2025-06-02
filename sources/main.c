#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

const int screenWidth = 1024;
const int screenHeight = 512;

int display(void) {
  SetTargetFPS(60);

  InitWindow(screenWidth, screenHeight, "Raycaster");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

int main(int argc, char *argv[]) {
  display();

  return 0;
}

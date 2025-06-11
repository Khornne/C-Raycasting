#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926535

float playerX, playerY, playerDeltaX, playerDeltaY,
    playerAngle; // player position

// MAP
int mapX = 10, mapY = 10, mapS = 55;
int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
    0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

void drawMap2D() {
  int x, y, offsetX, offsetY;
  for (y = 0; y < mapY; y++) {
    for (x = 0; x < mapX; x++) {
      if (map[y * mapX + x] == 1) {
        glColor3f(1, 1, 1); // Wall Colour white
      } else {
        glColor3f(0, 0, 0); // Air / No wall is black
      }
      offsetX = x * mapS;
      offsetY = y * mapS;
      glBegin(GL_QUADS);
      // +1 & -1 draw as cubes on map
      glVertex2i(offsetX + 1, offsetY + 1);
      glVertex2i(offsetX + 1, offsetY + mapS - 1);
      glVertex2i(offsetX + mapS - 1, offsetY + mapS - 1);
      glVertex2i(offsetX + mapS - 1, offsetY + 1);
      glEnd();
    }
  }
}

// Function to draw the Player
void drawPlayer() {
  glColor3f(1, 1, 0);
  glPointSize(8);
  glBegin(GL_POINTS);
  glVertex2i(playerX, playerY);
  glEnd();

  glLineWidth(3);
  glBegin(GL_LINES);
  glVertex2i(playerX, playerY);
  glVertex2i(playerX + playerDeltaX * 5, playerY + playerDeltaY * 5);
  glEnd();
}

void drawRays3D() {
  float rayX, rayY, rayAngle, offsetX, offsetY;
  int ray, map_x, map_y, map_ray, dof;

  rayAngle = playerAngle;
  for (ray = 0; ray < 1; ray++) {
    dof = 0;
    float angleTan = -1 / tan(rayAngle);
    // Check for looking up
    if (rayAngle > PI) {
      ray = (((int)playerY >> 6) << 6) - 0.0001;
      rayX = (playerY - rayY) * angleTan + playerX;
      offsetY = -55;
      offsetX = offsetY * angleTan;
    }
    if (rayAngle < PI) {
      ray = (((int)playerY >> 6) << 6) + 55;
      rayX = (playerY - rayY) * angleTan + playerX;
      offsetY = 55;
      offsetX = offsetY * angleTan;
    }
    // Looking left or right
    if (rayAngle == 0 || rayAngle == PI) {
      rayX = playerX;
      rayY = playerY;
      dof = 8;
    }
    // While loop checks for if a ray hits a wall
    while (dof < 8) {
      map_x = (int)(rayX) >> 6;
      map_y = (int)(rayY) >> 6;
      map_ray = map_y * mapX + map_x;
      if (map_ray < mapX * mapY && map[map_ray] == 1) {
        dof = 8;
      } else { // Checks for the next line
        rayX += offsetX;
        rayY += offsetY;
        dof += 1;
      }
    }
    glColor3f(0, 0, 1);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(playerX, playerY);
    glVertex2i(rayX, rayY);
    glEnd();
  }
}

// Function to update display
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawMap2D();
  drawPlayer();
  glutSwapBuffers();
}

// Player Movement
void playerMvmt(unsigned char key, int x, int y) {
  if (key == 'w') {
    playerX += playerDeltaX;
    playerY += playerDeltaY;
  }
  if (key == 's') {
    playerX -= playerDeltaX;
    playerY -= playerDeltaY;
  }
  if (key == 'a') {
    playerAngle -= 0.1;
    if (playerAngle < 0) {
      playerAngle += 2 * PI;
    }
    playerDeltaX = cos(playerAngle) * 5;
    playerDeltaY = sin(playerAngle) * 5;
  }
  if (key == 'd') {
    playerAngle += 0.1;
    if (playerAngle < 2 * PI) {
      playerAngle += 2 * PI;
    }
    playerDeltaX = cos(playerAngle) * 5;
    playerDeltaY = sin(playerAngle) * 5;
  }
  glutPostRedisplay();
}

// Initalise function
void init() {
  glClearColor(0.3, 0.3, 0.3, 0);
  gluOrtho2D(0, 1024, 512, 0);
  playerX = 300;
  playerY = 300;
  playerDeltaX = cos(playerAngle) * 5;
  playerDeltaY = sin(playerAngle) * 5;
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(1280, 720);
  glutCreateWindow("Raycaster");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(playerMvmt);
  glutMainLoop();
}

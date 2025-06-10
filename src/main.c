#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float playerX, playerY; // player position

// Function to draw the Player
void drawPlayer() {
  glColor3f(1, 1, 0);
  glPointSize(8);
  glBegin(GL_POINTS);
  glVertex2i(playerX, playerY);
  glEnd();
}

// Function to update display
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawPlayer();
  glutSwapBuffers();
}

// Player Movement
void playerMvmt(unsigned char key, int x, int y) {
  if (key == 'w') {
    playerY -= 5;
  }
  if (key == 's') {
    playerY += 5;
  }
  if (key == 'a') {
    playerX -= 5;
  }
  if (key == 'd') {
    playerX += 5;
  }
  glutPostRedisplay();
}
// Initalise function
void init() {
  glClearColor(0.3, 0.3, 0.3, 0);
  gluOrtho2D(0, 1024, 512, 0);
  playerX = 300;
  playerY = 300;
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(1024, 512);
  glutCreateWindow("Raycaster");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(playerMvmt);
  glutMainLoop();
}

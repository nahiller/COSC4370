/*******************************************************
 * Homework 2: OpenGL       tar -xzvf freeglut-3.2.1.tar.gz *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0, 1, 4, 1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 3;

float specular[] = {1.0, 1.0, 1.0, 1.0};
float shininess[] = {50.0};

void drawStaircase(int number_of_stairs){
  glTranslatef(0.9, .2, 0.);
  for(int i=number_of_stairs; i>0; i--){
    glutSolidCube(1.);
    glTranslatef(.9, 0., 0.);
    }
  glTranslatef(-0.9, .2, 0.);
  for(int i=number_of_stairs; i>0; i--){
    glutSolidCube(1.);
    glTranslatef(-.9, 0., 0.);
    }
}

void drawTeapotStack(bool pos, int number_of_teapots){
  for(int i=0; i<number_of_teapots; i++)
    if (pos==true){
      glTranslatef(3.0, 0., 0.);
      glutSolidTeapot(1.);
    }
    else{
      glTranslatef(-3.0, 0., 0.);
      glutSolidTeapot(1.);
    }
}

void problem1() {
  glTranslatef(0., 5., 0.);
  for(int i=0; i<9; i++){
	  glutSolidTeapot(1.);
    glRotatef(360.0/10.0,0.,0.0,1.0);
    glTranslatef(4., 4., 0.0);
    glutSolidTeapot(1.);
  }
}

void problem2() {
  for(int i=19; i>0; i--){
    glutSolidCube(1.);
    glTranslatef(-.9, 0., 0.);
  }
  for(int i=18; i>0; i--)
    drawStaircase(i);
}

void problem3() {

  for(int i=1; i<6; i++){
    bool position=true;
  }
	glutSolidTeapot(1.);
  glTranslatef(-1.5, 2.0, 0.);
  glutSolidTeapot(1.);
  drawTeapotStack(true, 1);
  glTranslatef(1.5, 2.0, 0.);
  glutSolidTeapot(1.);
  drawTeapotStack(false, 2);
  glTranslatef(-1.5, 2., 0.);
  glutSolidTeapot(1.);
  drawTeapotStack(true, 3);
  glTranslatef(1.5, 2., 0.0);
  glutSolidTeapot(1.);
  drawTeapotStack(false, 4);
  glTranslatef(-1.5, 2., 0.0);
  glutSolidTeapot(1.);
  drawTeapotStack(true, 5);
}

void problem4() {
  glutSolidSphere(1., 10, 10);
  glPushMatrix();
  for(int i=0; i<9; i++){
    glTranslatef(1., 1., 0.);
    glutSolidSphere(1., 10, 10);
  }
  glPushMatrix();
  for(int i=0; i<9; i++){
    glTranslatef(-1., 1., 0.);
    glutSolidSphere(1., 10, 10);
  }
  glPopMatrix();


  
  glPopMatrix();
  glPushMatrix();
  for(int i=0; i<9; i++){
    glTranslatef(-1.,1., 0.);
    glutSolidSphere(1., 10, 10);
  }
  glPushMatrix();
  for(int i=0; i<9; i++){
    glTranslatef(1., 1., 0.);
    glutSolidSphere(1., 10, 10);
  }
  glPopMatrix();
  glPopMatrix();

  }



void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1)
		problem1();
	if (curProblem == 2)
		problem2();
	if (curProblem == 3)
		problem3();
	if (curProblem == 4)
		problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON)
		rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown)
		yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}

	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}

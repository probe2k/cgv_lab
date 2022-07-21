#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int d = 0;

void spinCube() {
	d++;
	glutPostRedisplay();
}

void drawFace(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {
	glBegin(GL_POLYGON);
	glVertex3fv(A);
	glVertex3fv(B);
	glVertex3fv(C);
	glVertex3fv(D);
	glEnd();
}

void drawCube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[]) {
	glColor3f(1, 0, 0);
	drawFace(V0, V1, V2, V3);
	glColor3f(0, 1, 0);
	drawFace(V4, V5, V6, V7);
	glColor3f(0, 0, 1);
	drawFace(V4, V0, V3, V7);
	glColor3f(1, 0, 1);
	drawFace(V4, V5, V1, V0);
	glColor3f(1, 1, 0);
	drawFace(V7, V3, V2, V6);
	glColor3f(0, 1, 1);
	drawFace(V5, V1, V2, V6);
}

void display() {
	GLfloat V[8][3] = { {-0.5, 0.5, 0.5},
						{0.5, 0.5, 0.5},
						{0.5, -0.5, 0.5},
						{-0.5, -0.5, 0.5},
						{-0.5, 0.5, -0.5},
						{0.5, 0.5, -0.5},
						{0.5, -0.5, -0.5},
						{-0.5, -0.5, -0.5} };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	GLfloat rV[8][3];

	GLfloat r = 45 * 3.14 / 180;

	for (int i = 0; i < 8; i++) {
		rV[i][1] = V[i][1] * cos(10 * 3.14 / 180) - V[i][2] * sin(10 * 3.14 / 180);
		rV[i][2] = V[i][1] * sin(10 * 3.14 / 180) + V[i][2] * cos(10 * 3.14 / 180);
		rV[i][0] = V[i][0];
	}

	drawCube(rV[0], rV[1], rV[2], rV[3], rV[4], rV[5], rV[6], rV[7]);

	glutSwapBuffers();
	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(20, 20);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMainLoop();
	return 0;
}

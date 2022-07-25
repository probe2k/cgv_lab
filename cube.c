#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

GLfloat V[8][3] = { { -0.5, 0.5, 0.5 },
					{ 0.5, 0.5, 0.5 },
					{ 0.5, -0.5, 0.5 },
					{ -0.5, -0.5, 0.5 },
					{ -0.5, 0.5, -0.5 },
					{ 0.5, 0.5, -0.5 },
					{ 0.5, -0.5, -0.5 },
					{ -0.5, -0.5, -0.5 } };

int t[] = {0, 0, 0};
int ax = 2;

void spincube() {
	t[ax] += 1;
	if (t[ax] == 360)
		t[ax] -= 360;
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		ax = 0;

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		ax = 1;

	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		ax = 2;
}

void drawFace(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {
	glBegin(GL_POLYGON);
	glVertex3fv(A);
	glVertex3fv(B);
	glVertex3fv(C);
	glVertex3fv(D);
	glEnd();
}

void drawCube() {
	glColor3f(1, 0, 0);
	drawFace(V[0], V[1], V[2], V[3]);
	glColor3f(0, 1, 0);
	drawFace(V[4], V[5], V[6], V[7]);
	glColor3f(0, 0, 1);
	drawFace(V[4], V[0], V[3], V[7]);
	glColor3f(1, 0, 1);
	drawFace(V[4], V[5], V[1], V[0]);
	glColor3f(1, 1, 0);
	drawFace(V[7], V[3], V[2], V[6]);
	glColor3f(0, 1, 1);
	drawFace(V[5], V[1], V[2], V[6]);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(t[0], 1, 0, 0);
	glRotatef(t[1], 0, 1, 0);
	glRotatef(t[2], 0, 0, 1);
	drawCube();
	glutSwapBuffers();

	glFlush();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-4, 4, -4, 4, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cube");
	init();
	glutIdleFunc(spincube);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 1;
}

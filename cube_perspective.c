#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat Cx = 0, Cy = 0, Cz = 3;

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 'x':
			Cx -= 0.5;
			break;
		case 'X':
			Cx += 0.5;
			break;
		case 'y':
			Cy -= 0.5;
			break;
		case 'Y':
			Cy += 0.5;
			break;
		case 'z':
			Cz -= 0.5;
			break;
		case 'Z':
			Cz += 0.5;
			break;
	}
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

	glLoadIdentity();
	gluLookAt(Cx, Cy, Cz, 0, 0, 0, 0, 1, 0);
	drawCube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

	glutSwapBuffers();
	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 2, 10);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowPosition(40, 40);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cube perspective");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

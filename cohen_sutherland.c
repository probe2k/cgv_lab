#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat xMin = -0.5, xMax = 0.5, yMin = -0.5, yMax = 0.5;
GLfloat xOne = -0.4, xTwo = 0.3, yOne = 0.7, yTwo = 0.3;
int ClipFlag = 0;

int left = 1, right = 2, top = 8, bottom = 4;
int C1, C2;

int Get_Code(GLfloat x, GLfloat y) {
	int C = 0;

	if (x < xMin)
		C = C | left;
	if (x > xMax)
		C = C | right;
	if (y < yMin)
		C = C | bottom;
	if (y > yMax)
		C = C | top;

	return C;
}

void Clip() {
	int C;
	GLfloat x, y;

	if (C1)
		C = C1;
	else
		C = C2;
	
	if (C & left) {
		x = xMin;
		y = yOne + (yTwo - yOne) * ((xMin - xOne) / (xTwo - xOne));
	}
	if (C & right) {
		x = xMax;
		y = yOne + (yTwo - yOne) * ((xMax - xOne) / (xTwo - xOne));
	}
	if (C & bottom) {
		y = yMin;
		x = xOne + (xTwo - xOne) * ((yMin - yOne) / (yTwo - yOne));
	}
	if (C & top) {
		y = yMax;
		x = xOne + (xTwo - xOne) * ((yMax - yOne) / (yTwo - yOne));
	}

	if (C == C1) {
		xOne = x;
		yOne = y;
	} else {
		xTwo = x;
		yTwo = y;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xMin, yMin);
	glVertex2f(xMin, yMax);
	glVertex2f(xMax, yMax);
	glVertex2f(xMax, yMin);
	glEnd();

	glColor3f(1, 0, 1);
	glBegin(GL_LINES);
	glVertex2f(xOne, yOne);
	glVertex2f(xTwo, yTwo);
	glEnd();
	
	while((1 & ClipFlag) == 1) {
		C1 = Get_Code(xOne, yOne);
		C2 = Get_Code(xTwo, yTwo);

		if ((C1 | C2) == 0)
			break;
		else if ((C1 & C2) != 0)
			break;
		else
			Clip();
	}

	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 1);
}

void Key(unsigned char key, int x, int y) {
	ClipFlag = 1;
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Clipping");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(Key);
	glutMainLoop();
	return 0;
}

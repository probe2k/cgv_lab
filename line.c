#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat x1 = 10, y1 = 30, x2 = 95, y2 = 90;
	float x, y, m;
	if ((x2 - x1) == 0)
		m = (y2 - y1);
	else
		m = (y2 - y1) / (x2 - x1);

	int dx = x2 - x1;
	int dy = y2 - y1;
	int p = 2 * dy - dx;
	x = x1;
	y = y1;

	glBegin(GL_POINTS);
	while (x <= x2) {
		glVertex2f(x, y);
		x += 1;
		if (p >= 1) {
			y++;
			p = p + 2 * (dy - dx);
		} else {
			p = p + 2 * dy;
		}
	}
	glEnd();
	glFlush();
}

void init() {
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Test");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

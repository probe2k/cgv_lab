#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.1, 0.4);
	glVertex2f(0.7, 0.4);
	glVertex2f(0.4, 0.8);
	glEnd();

	glTranslatef(0.1, 0.3, 0);
	glRotatef(45, 0, 0, 1);
	glTranslatef(-0.1, -0.3, 0);

	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.1, 0.4);
	glVertex2f(0.7, 0.4);
	glVertex2f(0.4, 0.8);
	glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Triangle");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

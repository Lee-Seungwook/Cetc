#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include<stdio.h>




void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
	glBegin(GL_TRIANGLES);
		glColor4f(1.0, 0.0, 0.0, 0.9);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glDisable(GL_BLEND);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGl Sample Drawing");
	glClearColor(0.9, 0.9, 0.9, 0.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}

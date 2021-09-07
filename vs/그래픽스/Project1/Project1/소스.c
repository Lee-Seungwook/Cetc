#include <gl/glut.h>
#include <gl/GL.h>
#include<gl/GLU.h>

float Tx = 2.5;
float Ty = 2.5;
float Tz = 2.5;
float Rx = 0.0;
float Ry = 0.0;
float Rz = 0.0;

void InitLight() {
	GLfloat mat_diffuse[] = { 0.5,0.4,0.4,1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat light_ambient[] = { 0.3,0.3,0.3,1.0 };
	GLfloat light_position[] = { -3,6,3.0,0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Tx, Ty, Tz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //ī�޶� �̵�
	glRotatef((GLfloat)Rx, 2.0, 0.0, 0.0); //��ü x�� ȸ��
	glRotatef((GLfloat)Ry, 0.0, 2.0, 0.0); //��ü y�� ȸ��
	glRotatef((GLfloat)Rz, 0.0, 0.0, 2.0); //��ü z�� ȸ��
	glutSolidTeapot(0.5);
	glFlush();
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, 1.0, 2.0, 30.0); //���� ���� ����
}
void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'a': //x�� �̵�
		Tx += 1.0;
		glutPostRedisplay();
		break;
	case 's': //x�� �̵�
		Tx -= 1.0;
		glutPostRedisplay();
		break;
	case 'd':  //y�� �̵�	
		Ty += 1.0;
		glutPostRedisplay();
		break;
	case 'f':  //y�� �̵�
		Ty -= 1.0;
		glutPostRedisplay();
		break;
	case 'z':  //z�� �̵�
		Tz += 1.0;
		glutPostRedisplay();
		break;
	case 'x':  //z�� �̵�
		Tz -= 1.0;
		glutPostRedisplay();
		break;
	case 'g':  //x�� ȸ��
		Rx += 1.0;
		glutPostRedisplay();
		break;
	case 'h':  //x�� ȸ��
		Rx -= 1.0;
		glutPostRedisplay();
		break;
	case 'j':  //y�� ȸ��
		Ry += 1.0;
		glutPostRedisplay();
		break;
	case 'k':  //y�� ȸ��
		Ry -= 1.0;
		glutPostRedisplay();
		break;
	case 'l':  //z�� ȸ��
		Rz += 1.0;
		glutPostRedisplay();
		break;
	case 'm':  //z�� ȸ��
		Rz -= 1.0;
		glutPostRedisplay();
		break;
	}

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGl Sample Drawing");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}

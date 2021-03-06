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
	GLfloat mat_diffuse[] = { 0.5,0.4,0.4,1.0 }; //물체 특성
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_shininess[] = { 15.0 };

	GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; //전역 주변반사

	GLfloat light0_ambient[] = { 0.1, 0.5, 0.5, 1.0 }; // 0번 광원 특성, 색
	GLfloat light0_diffuse[] = { 0.5, 0.4, 0.3, 1.0 }; //확산 반사의 입사광
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat light1_ambient[] = { 0.5, 1, 0.1, 1.0 }; // 1번 광원 특성, 색
	GLfloat light1_diffuse[] = { 0.5, 0.2, 0.3, 1.0 }; //확산 반사의 입사광
	GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };

	GLfloat light2_ambient[] = { 0.5, 0.5, 1, 1.0 }; // 2번 광원 특성, 색 
	GLfloat light2_diffuse[] = { 0.1, 0.2, 0.7, 1.0 }; //확산 반사의 입사광
	GLfloat light2_specular[] = { 0.0, 0., 0.0, 1.0 };



	/*GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat light_ambient[] = { 0.3,0.3,0.3,1.0 };
	GLfloat light_position[] = { -3,6,3.0,0.0 };*/
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	//glEnable(GL_NORMALIZE);
	/*glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);*/

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);   //0번 광원 특성할당
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	glEnable(GL_LIGHT1);        //1번 광원 활성화
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);   //1번 광원 특성할당
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glEnable(GL_LIGHT2);        //2번 광원 활성화
	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);   //2번 광원 특성할당
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); //물체 특성할당
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //전역주변반사
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);    //근접시점
}

void MyDisplay() {
	GLfloat LightPosition0[] = { 3.0, 3.0, 2.0, 1.0 };     //0번 광원위치 설정
	GLfloat LightPosition1[] = { 1.0, 1.0, 1.0, 1.0 };     //1번 광원위치 설정
	GLfloat LightDirection1[] = { -0.5, -1.0, -1.0 };       //1번 광원 방향
	GLfloat SpotAngle1[] = { 20.0 };                        //1번 광원 각도
	GLfloat LightPosition2[] = { -3,6,3.0,0.0 };     //2번 광원위치 설정

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Tx, Ty, Tz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //카메라 이동
	glRotatef((GLfloat)Rx, 2.0, 0.0, 0.0); //물체 x축 회전
	glRotatef((GLfloat)Ry, 0.0, 2.0, 0.0); //물체 y축 회전
	glRotatef((GLfloat)Rz, 0.0, 0.0, 2.0); //물체 z축 회전

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);      //위치성 광원 위치 할당
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);      //스포트라이트 위치 할당
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);   //방향
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngle1);       //각도
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);             //코사인 승수
	glLightfv(GL_LIGHT2, GL_POSITION, LightPosition2); //방향성 광원 위치 할당

	glutSolidTeapot(0.5);
	glFlush();
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, 1.0, 2.0, 30.0); //원근 투상 적용
}
void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'a': //x축 이동
		Tx += 1.0;
		glutPostRedisplay();
		break;
	case 's': //x축 이동
		Tx -= 1.0;
		glutPostRedisplay();
		break;
	case 'd':  //y축 이동	
		Ty += 1.0;
		glutPostRedisplay();
		break;
	case 'f':  //y축 이동
		Ty -= 1.0;
		glutPostRedisplay();
		break;
	case 'z':  //z축 이동
		Tz += 1.0;
		glutPostRedisplay();
		break;
	case 'x':  //z축 이동
		Tz -= 1.0;
		glutPostRedisplay();
		break;
	case 'g':  //x축 회전
		Rx += 1.0;
		glutPostRedisplay();
		break;
	case 'h':  //x축 회전
		Rx -= 1.0;
		glutPostRedisplay();
		break;
	case 'j':  //y축 회전
		Ry += 1.0;
		glutPostRedisplay();
		break;
	case 'k':  //y축 회전
		Ry -= 1.0;
		glutPostRedisplay();
		break;
	case 'l':  //z축 회전
		Rz += 1.0;
		glutPostRedisplay();
		break;
	case 'm':  //z축 회전
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

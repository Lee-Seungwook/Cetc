#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include <gl/GL.h>
#include<gl/GLU.h>
#include <GL/glaux.h>
#pragma comment (lib, "glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

unsigned int MyTextureObject[1];
AUX_RGBImageRec *pTextureImage[1];

float Tx = 2.5;
float Ty = 2.5;
float Tz = 2.5;
float Rx = 0.0;
float Ry = 0.0;
float Rz = 0.0;

void InitLight() {
	
	GLfloat mat_diffuse[] = { 0.5,0.4,0.4,1.0 }; //��ü Ư��
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_shininess[] = { 15.0 };

	GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; //���� �ֺ��ݻ�

	GLfloat light0_ambient[] = { 0.1, 0.5, 0.5, 1.0 }; // 0�� ���� Ư��, ��
	GLfloat light0_diffuse[] = { 0.5, 0.4, 0.3, 1.0 }; //Ȯ�� �ݻ��� �Ի籤
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat light1_ambient[] = { 0.5, 1, 0.1, 1.0 }; // 1�� ���� Ư��, ��
	GLfloat light1_diffuse[] = { 0.5, 0.2, 0.3, 1.0 }; //Ȯ�� �ݻ��� �Ի籤
	GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };

	GLfloat light2_ambient[] = { 0.5, 0.5, 1, 1.0 }; // 2�� ���� Ư��, �� 
	GLfloat light2_diffuse[] = { 0.1, 0.2, 0.7, 1.0 }; //Ȯ�� �ݻ��� �Ի籤
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
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);   //0�� ���� Ư���Ҵ�
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	glEnable(GL_LIGHT1);        //1�� ���� Ȱ��ȭ
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);   //1�� ���� Ư���Ҵ�
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glEnable(GL_LIGHT2);        //2�� ���� Ȱ��ȭ
	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);   //2�� ���� Ư���Ҵ�
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); //��ü Ư���Ҵ�
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //�����ֺ��ݻ�
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);    //��������
}

void MyDisplay() {
	GLfloat LightPosition0[] = { 3.0, 3.0, 2.0, 1.0 };     //0�� ������ġ ����
	GLfloat LightPosition1[] = { 1.0, 1.0, 1.0, 1.0 };     //1�� ������ġ ����
	GLfloat LightDirection1[] = { -0.5, -1.0, -1.0 };       //1�� ���� ����
	GLfloat SpotAngle1[] = { 20.0 };                        //1�� ���� ����
	GLfloat LightPosition2[] = { -3,6,3.0,0.0 };     //2�� ������ġ ����

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
	
	static GLfloat MyPlane[] = { 1.0, 0.0, 0.0, 0.0 }; //�ڵ� ���� ����
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_R, GL_OBJECT_PLANE, MyPlane);
	glEnable(GL_TEXTURE_GEN_R);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Tx, Ty, Tz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //ī�޶� �̵�
	glRotatef((GLfloat)Rx, 2.0, 0.0, 0.0); //��ü x�� ȸ��
	glRotatef((GLfloat)Ry, 0.0, 2.0, 0.0); //��ü y�� ȸ��
	glRotatef((GLfloat)Rz, 0.0, 0.0, 2.0); //��ü z�� ȸ��

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);      //��ġ�� ���� ��ġ �Ҵ�
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);      //����Ʈ����Ʈ ��ġ �Ҵ�
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);   //����
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngle1);       //����
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);             //�ڻ��� �¼�
	glLightfv(GL_LIGHT2, GL_POSITION, LightPosition2); //���⼺ ���� ��ġ �Ҵ�


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


AUX_RGBImageRec * LoadBMP(char *szFilename) {
	FILE * pFile = NULL;
	if (!szFilename) {
		return NULL;
	}
	pFile = fopen(szFilename, "r");
	if (pFile) {
		fclose(pFile);
		return auxDIBImageLoad(szFilename);
	}
	return NULL;
}

int LoadGLTextures(char *szFilePath) { //������ �ε��ϰ� �ؽ�ó�� ��ȯ
	int Status = FALSE;
	glClearColor(0.5, 0.5, 0.5, 0.5);
	memset(pTextureImage, 0, sizeof(void *) * 1);

	if (pTextureImage[0] = LoadBMP(szFilePath)) {
		Status = TRUE;
		glGenTextures(1, &MyTextureObject[0]);
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage[0]->sizeX, pTextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
	}
	if (pTextureImage[0]) {
		if (pTextureImage[0]->data) {
			free(pTextureImage[0]->data);
		}
		free(pTextureImage[0]);
	}
	return Status;
}

int main(int argc, char** argv) {
	if (argc <= 1) {
		printf("\n%s\n\n", "Usage : TextureDLG#_Consol.exe[BMPFileName.bmp]");
		exit(1);
	}
	else if (argc > 2) {
		printf("\nToo Many Arguments!\nArgument is Only one\n");
		exit(1);
	}
	else {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowSize(400, 400);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("�ؽ��ĸ���");
		//glClearColor(0.4, 0.4, 0.4, 0.0);
		InitLight();
		glutDisplayFunc(MyDisplay);
		glutReshapeFunc(MyReshape);
		glutKeyboardFunc(MyKeyboard);
		if (LoadGLTextures(argv[1])) {
			glEnable(GL_TEXTURE_2D);
			glShadeModel(GL_SMOOTH);
			glClearDepth(1.0);
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LEQUAL);
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
			glutMainLoop();
		}
	}
}

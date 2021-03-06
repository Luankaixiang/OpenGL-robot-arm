#include"stdafx.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;

static int theta1 = 0;
static int theta2 = 0;
static int theta3 = 0;
static int l1 = 1;
static int l2 = 2;

void base()
{
	glPushMatrix();
	glColor3f(0.9, 0.9, 0.9f);
	glTranslatef(0.0, 0.5, 0.0);//平移函数
	glScalef(1.0, 0.5, 1.0);
	glutSolidCube(1.5);
	glPopMatrix();
}

void lower_arm()
{
	glPushMatrix();
	glColor3f(0.8, 0.8, 0.8);
	glTranslatef(0.0, 1.0, 0.0);
	glScalef(0.4, 2.0, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
}

void upper_arm()
{
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0.0, 1.0, 0.0);
	glScalef(0.4, 2.0, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
}

void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//设置清除颜色
	glShadeModel(GL_FLAT);//用于控制opengl中绘制指定两点间其他点颜色的过渡模式
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//把窗口清除为当前颜色
	glPushMatrix();

	glRotatef(theta1, 0.0, 1.0, 0.0);
	base();
	glTranslatef(0.0, l1, 0.0);
	glRotatef(theta2, 0.0, 0.0, 1.0);
	lower_arm();
	glTranslatef(0.0, l2, 0.0);
	glRotatef(theta3, 0.0, 0.0, 1.0);
	upper_arm();

	glPopMatrix();
	glutSwapBuffers();//交换缓冲区
}

void reshape(int w, int h)//重置坐标系统和投影矩阵
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//(x，y)指定视口矩形左下角，以像素为单位。默认值为（0，0）。width, height 分别指定宽度和高度。根据窗口的实时变化重绘窗口。
	glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影矩阵
	glLoadIdentity(); //把矩阵设为单位矩阵
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); 
	glMatrixMode(GL_MODELVIEW); //对模型视景矩阵操作
	glLoadIdentity();
	glTranslatef(0.0, -3.0, -6.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		theta1 = (theta1 + 5) % 360;
		glutPostRedisplay();
		break;

	case 'a':
		theta1 = (theta1 - 5) % 360;
		glutPostRedisplay();
		break;

	case 'w':
		theta2 = (theta2 + 5) % 360;
		glutPostRedisplay();
		break;

	case 's':
		theta2 = (theta2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		theta3 = (theta3 + 5) % 360;
		glutPostRedisplay();
		break;

	case 'd':
		theta3 = (theta3 - 5) % 360;
		glutPostRedisplay(); //标记当前窗口需要重新绘制
		break;
	default:
		break;
	}
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);//初始化GLUT库
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//设置了程序所使用窗口的类型
	glutInitWindowPosition(100, 10);
	glutInitWindowSize(1000, 800);//设置所需的窗口大小
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();//无限执行的循环，负责一直处理窗口和操作系统的用户输入等操作
    return 0;
}

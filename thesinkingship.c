#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 
#define PI 3.14285
void ice();
void sun();
void display1();
void display2();
void display3();
void ship();
void night();
void day();
void water();
void animate();
void revanimate();
void stopanimate();
GLint p=0,a=0,b=0,c=0,d=0,e=0,f=0,g=500,h=600,x=0,i=0,ani=0;
GLfloat theta=0.0,col1=0.0,col2=0.0,col3=0.0;
static void Timer(int value)
{
	if(ani==1)
	{
	a+=4.0;
	p=a;
	glutPostRedisplay();
	glutTimerFunc(200,Timer,0);
	}
	if(ani==2)
	{
	a-=4.0;
	p=a;
	glutPostRedisplay();
	glutTimerFunc(200,Timer,0);
	}
	if(ani==0)
	{
	a=p;
	glutPostRedisplay();
	}
}
/*
static void stopTimer(int value)
{
	a=p;
	glutPostRedisplay();
	glutTimerFunc(0,stopTimer,0);
}
static void revTimer(int value)
{
	a-=4.0;
	p=a;
	glutPostRedisplay();
	glutTimerFunc(200,stopanimate,0);
}
*/
void animate()
{
	ani=1;
	Timer(0);
	glutPostRedisplay();
}
void stopanimate()
{
	ani=0;
	//stopTimer(0);
	glutPostRedisplay();
}
void revanimate()
{
	ani=2;
	Timer(0);
	glutPostRedisplay();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	display1();
	if(a>950)

	{
		b+=10;
		display2();
	}if(b>250)
	{

		c+=10;
		display3();

	}

	glFlush();
	glutSwapBuffers();
}

void display1()
{
	sun();
	glPushMatrix();
	glTranslated(a,75,0.0);
	ship();
	glPopMatrix();
	water();
}

void display2()
{

	glClear(GL_COLOR_BUFFER_BIT);
	//sun();
	ice();
	glPushMatrix();
	glTranslated(b,75,0.0);
	ship();
	glPopMatrix();
	water();

}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//sun();
	x-=1;
	ice();
	glPushMatrix();
	glTranslated(c,100+x*5,0.0);
	glRotated(-15,0,0,1);
	ship();
	glPopMatrix();
	water();


}
 
void night()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	col1=1.0;
	col2=0.5;
	col3=0.7;
	glutPostRedisplay();
}
void day()
{
	glClearColor(0.0f,1.0f,1.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	col1=col2=col3=0.0;
	glutPostRedisplay();
}
/* DRAW WATER */
void water()
{

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1000,0);
		glVertex2f(1000,100);
		glVertex2f(0,100);
	glEnd();
}
//Draw Sun
void sun() 
{
float a,i;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
//float x,y;
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0);
for (i = 0; i <360; i++)
{
a=i*(PI/180);
glVertex2f(800+50*cos(a),700+50*sin(a));
}
glEnd();
}

void ship()
{
    glScaled(20,20,0);
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	 glVertex2f(3.5,5.5);
	 glVertex2f(3.5,8.5);
	 glVertex2f(19.5,8.5);
	 glVertex2f(19.5,5.5);
	glEnd();
	glColor3f(col1,col2,col3);
	glBegin(GL_POLYGON);
	 glVertex2f(1,5.5);
	 glVertex2f(4,1);
	 glVertex2f(19,1);
	 glVertex2f(21.5,5.5);
	glEnd();
	glColor3f(0.7,0.4,0.2);
	glBegin(GL_POLYGON);
	glVertex2f(4,5.5);
	glVertex2f(4,8);
	glVertex2f(5,8);
	glVertex2f(5,5.5);
	glEnd();
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(7,7.5);
	glVertex2f(7,8);
	glVertex2f(10,8);
	glVertex2f(10,7.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(11.5,7.5);
	glVertex2f(11.5,8);
	glVertex2f(15,8);
	glVertex2f(15,7.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(16,7.5);
	glVertex2f(16,8);
	glVertex2f(19,8);
	glVertex2f(19,7.5);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(4.5,8.5);
	glVertex2f(4.5,10);
	glVertex2f(18.5,10);
	glVertex2f(18.5,8.5);
	glEnd();
	glColor3f(col1,col2,col3);
	glBegin(GL_POLYGON);
	glVertex2f(5.5,10);
	glVertex2f(5.5,12.9);
	glVertex2f(7,12.9);
	glVertex2f(7,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
	glVertex2f(5.5,12.9);
	glVertex2f(5.5,13.5);
	glVertex2f(7,13.5);
	glVertex2f(7,12.9);
	glEnd();
	glColor3f(col1,col2,col3);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,10);
		glVertex2f(8.5,12.9);
		glVertex2f(10,12.9);
		glVertex2f(10,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,12.9);
		glVertex2f(8.5,13.5);
		glVertex2f(10,13.5);
		glVertex2f(10,12.9);
	glEnd();
	glColor3f(col1,col2,col3);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,10);
		glVertex2f(11.5,12.9);
		glVertex2f(13,12.9);
		glVertex2f(13,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,12.9);
		glVertex2f(11.5,13.5);
		glVertex2f(13,13.5);
		glVertex2f(13,12.9);
	glEnd();
	glColor3f(col1,col2,col3);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,10);
		glVertex2f(14.5,12.9);
		glVertex2f(16,12.9);
		glVertex2f(16,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,12.9);
		glVertex2f(14.5,13.5);
		glVertex2f(16,13.5);
		glVertex2f(16,12.9);
	    glEnd();
	    glColor3f(col1,col2,col3);
	    glBegin(GL_LINE_LOOP);
		glVertex2f(1.5,5.5);
		glVertex2f(1.5,6.5);
		glVertex2f(2,6.2);
		glVertex2f(3,6.2);
		glVertex2f(3.5,6.5);
		glVertex2f(3.5,5.5);
	    glEnd();
	    glBegin(GL_LINE_LOOP);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,6.5);
		glVertex2f(4,6.2);
		glVertex2f(5,6.2);
		glVertex2f(5.5,6.5);
		glVertex2f(5.5,5.5);
	    glEnd();
	    glBegin(GL_LINE_LOOP);
		glVertex2f(5.5,5.5);
		glVertex2f(5.5,6.5);
		glVertex2f(6,6.2);
		glVertex2f(7,6.2);
		glVertex2f(7.5,6.5);
		glVertex2f(7.5,5.5);
	    glEnd();
	    glBegin(GL_LINE_LOOP);
		glVertex2f(7.5,5.5);
		glVertex2f(7.5,6.5);
		glVertex2f(8,6.2);
		glVertex2f(9,6.2);
		glVertex2f(9.5,6.5);
		glVertex2f(9.5,5.5);
	    glEnd();
	    glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,5.5);
		glVertex2f(9.5,6.5);
		glVertex2f(10,6.2);
		glVertex2f(11,6.2);
		glVertex2f(11.5,6.5);
		glVertex2f(11.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(11.5,5.5);
		glVertex2f(11.5,6.5);
		glVertex2f(12,6.2);
		glVertex2f(13,6.2);
		glVertex2f(13.5,6.5);
		glVertex2f(13.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(13.5,5.5);
		glVertex2f(13.5,6.5);
		glVertex2f(14,6.2);
		glVertex2f(15,6.2);
		glVertex2f(15.5,6.5);
		glVertex2f(15.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15.5,5.5);
		glVertex2f(15.5,6.5);
		glVertex2f(16,6.2);
		glVertex2f(17,6.2);
		glVertex2f(17.5,6.5);
		glVertex2f(17.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17.5,5.5);
		glVertex2f(17.5,6.5);
		glVertex2f(18,6.2);
		glVertex2f(19,6.2);
		glVertex2f(19.5,6.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(19.5,5.5);
		glVertex2f(19.5,6.5);
		glVertex2f(20,6.2);
		glVertex2f(20.5,6.2);
		glVertex2f(21,6.5);
		glVertex2f(21,5.5);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(4.5,3.5);
		glVertex2f(4.5,4.5);
		glVertex2f(5.5,4.5);
		glVertex2f(5.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,3.5);
		glVertex2f(7,4.5);
		glVertex2f(8,4.5);
		glVertex2f(8,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,3.5);
		glVertex2f(9.5,4.5);
		glVertex2f(10.5,4.5);
		glVertex2f(10.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(12,3.5);
		glVertex2f(12,4.5);
		glVertex2f(13,4.5);
		glVertex2f(13,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(14.5,3.5);
		glVertex2f(14.5,4.5);
		glVertex2f(15.5,4.5);
		glVertex2f(15.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17,3.5);
		glVertex2f(17,4.5);
		glVertex2f(18,4.5);
		glVertex2f(18,3.5);
	glEnd();
	glColor3f(col1,col2,col3);
	glBegin(GL_LINE_LOOP);
		glVertex2f(5,10);
		glVertex2f(5,11);
		glVertex2f(5.5,10.8);
		glVertex2f(6.5,10.8);
		glVertex2f(7,11);
		glVertex2f(7,10);
	glEnd();
	    glBegin(GL_LINE_LOOP);
		glVertex2f(7,10);
		glVertex2f(7,11);
		glVertex2f(7.5,10.8);
		glVertex2f(8.5,10.8);
		glVertex2f(9,11);
		glVertex2f(9,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9,10);
		glVertex2f(9,11);
		glVertex2f(9.5,10.8);
		glVertex2f(10.5,10.8);
		glVertex2f(11,11);
		glVertex2f(11,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(11,10);
		glVertex2f(11,11);
		glVertex2f(11.5,10.8);
		glVertex2f(12.5,10.8);
		glVertex2f(13,11);
		glVertex2f(13,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(13,10);
		glVertex2f(13,11);
		glVertex2f(13.5,10.8);
		glVertex2f(14.5,10.8);
		glVertex2f(15,11);
		glVertex2f(15,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15,10);
		glVertex2f(15,11);
		glVertex2f(15.5,10.8);
		glVertex2f(16.5,10.8);
		glVertex2f(17,11);
		glVertex2f(17,10);
	glEnd();
}

/* TO DRAW ICEBERG */
void ice()
{
	glPushMatrix();
	glTranslated(450,50,0.0);
	glScaled(10,10,0);
	glColor3f(0.0,1.0,1.0);
	if(c>0)
	{glPushMatrix();
	glTranslated(0,x,0);
    glPushMatrix();
	glTranslated(7,2,0.0);
		glRotated(-x,0,0,1);
		glTranslated(-7,-2,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(7,2);
		glVertex2f(8,3);
		glVertex2f(11,18);
		glVertex2f(12,19);
		glVertex2f(12,3);
		glEnd();
		glPopMatrix();
		glPushMatrix();
        glTranslated(12,3,0.0);
		glRotated(x,0,0,1);
		glTranslated(-12,-3,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(12,3);
		glVertex2f(12,19);
		glVertex2f(17,18);
		glVertex2f(18,3);
		glVertex2f(19,3);
		glEnd();
		glPopMatrix();
		glPopMatrix();
	}
	else
	{
		glBegin(GL_POLYGON);
			glVertex2f(7,2);
			glVertex2f(8,3);
			glVertex2f(11,18);
			glVertex2f(12,19);
			glVertex2f(12,3);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(12,3);
			glVertex2f(12,19);
			glVertex2f(17,18);
			glVertex2f(18,3);
			glVertex2f(19,3);
			glEnd();
	}


	glPopMatrix();

}

static void special(int Key,int x,int y)
{
	switch(Key)
	{
		case GLUT_KEY_RIGHT:    animate();
					break;
		case GLUT_KEY_LEFT:    revanimate();
					break;
		case GLUT_KEY_DOWN:	stopanimate();
					break;
	}
}

void NormalKey(GLubyte key,GLint x,GLint y)
{
	switch(key)
	{
		case 'F':animate();
			break;
		case 'f':animate();
			break;
		case 'R':revanimate();
			break;
		case 'r':revanimate();
			break;
		case 'S':stopanimate();
			break;
		case 's':stopanimate();
			break;
		case 'N': night();
			  break;
		case 'n': night();
			  break;
		case 'D':day();
			break;
		case 'd':day();
			break;
	}
}
void myinit()
{
	glClearColor(0.0f,1.0f,1.0f,1.0f);
/*	GLfloat light_pos[] = {1.0, 2.0, 3.0, 1.0};
// ---- Rest of init( ) ----
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity( );
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_pos);	*/
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
}

int main(int argc, char* argv[])

{
	int key=0;
	printf("The Sinking Ship\n");
	printf("MENU\n");
	printf("1.START\n0.EXIT\n");
	printf("Press f or F for the ship to move forward\n");
	printf("Press r or R for the ship to move in reverse direction\n");
	printf("Press d or D to switch to day mode\n");
	printf("Press n or N to switch to night mode\n");
	printf("Press s or S to stop the movement of the ship\n");
	scanf("%d",&key);
	if(key==0) return 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1024.0,768.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("titanic ship");
	glutDisplayFunc(display);
	glutSpecialFunc(special);
	glutKeyboardFunc(NormalKey);
	myinit();
	glutMainLoop();
	return 0;
}
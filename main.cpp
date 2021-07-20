/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#include<math.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>

void init(void);
void display(void);
main(int argc, char *argv[]){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(10,10);
	glutCreateWindow("LINES");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,10,0,10);
}
void display(void){
    //garis AB
    float ax=1,ay=1,bx=5,by=5;

    //garis CD
    float cx=1,cy=3,dx=5,dy=1;

    float m1,c1,m2,c2,ex,ey;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	glBegin(GL_LINES);
        glVertex2f(ax,ay);
        glVertex2f(bx,by);

        glVertex2f(cx,cy);
        glVertex2f(dx,dy);
	glEnd();

	//menentukan persamaan garis
	//AB
	m1=(by-ay)/(bx-ax);
	c1=ay-(m1*ax);

	//CD
    m2=(dy-cy)/(dx-cx);
    c2=cy-(m2*cx);

    //menentukan titik potong
    ex=(c2-c1)/(m1-m2);
    ey=(m1*ex)+c1;

    printf("%f,%f",ex,ey);

    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex2f(ex,ey);
    glEnd();

	glFlush();
}

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

using namespace std;

double a=0,b=0,c=0,d=0;

float round_value(float v)
{
  return floor(v + 0.5);
}

void LineDDA(double X1,double Y1,double X2,double Y2)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
  							
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));	 
 xInc=dx/(float)steps;
  yInc=dy/(float)steps;
								 
        glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);	
  	glVertex2d(x,y); 	 

  int k;
  for(k=0;k<steps;k++)		  {
    x=x+xInc;
    y=y+yInc;
    glVertex2d(round_value(x), round_value(y));
  
  }
 	 glEnd();
	glFlush();
}



void display(void)
{
glClear(GL_COLOR_BUFFER_BIT); 
 	
LineDDA(a,b,c,d);

}

void Init()
{
  
  glClearColor(1.0,1.0,1.0,0);	
  glColor3f(1.0,0.0,0.0); 	
  glViewport(0 , 0 , 640 , 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); 
  gluOrtho2D(0 , 640 , 0 , 480);
}


int main(int argc, char **argv)
{
 printf("\nEnter values of First endpoint");
 scanf("%lf%lf",&a,&b);
 printf("\nEnter values of Second endpoint");
 scanf("%lf%lf",&c,&d);
 glutInit(&argc,argv);				 	
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
	glutInitWindowSize(640,480);			
    	glutInitWindowPosition(0,0);
  
  	glutCreateWindow("Assignment 1 DDA");		
 
  	Init(); 					
	
	glutDisplayFunc(display); 			
	glFlush();
  
  	glutMainLoop();					
}
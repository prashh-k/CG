#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
using namespace std;
float R=0,G=0,B=0;
int Algo;
void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void mouse(int btn, int state, int x, int y){
    y = 480-y;
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bcol[] = {1,0,0};
            float newCol[] = {R,G,B};
           float oldcol[] = {1,1,1};
 	
           
        }
    }
}
void goMenu(int value){
switch(value){
case 1:
  R = 0, G = 1, B=0;
 break;
 case 2:
 R = 1, G = 1, B=0;
 break;
 case 3:
 R = 1, G = 0, B=1;
 break;
 case 4:
 R = 0, G = 0, B=1;
 break;
}
glutPostRedisplay();
}
void world()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150,100);
        glVertex2i(300,300);
        glVertex2i(450,100);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640,480);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Polygon filling Methods");
 init();
 glutCreateMenu(goMenu);
 glutAddMenuEntry("Color 1 Green",1);
 glutAddMenuEntry("Color 2 Yellow",2);
 glutAddMenuEntry("Color 3 Pink",3);
  glutAddMenuEntry("Color 4 Blue",4);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 
 glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}

#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400,400,-400,400);
}

inline int round_off(const float a){
    return int(a+0.5);
}

void lineDDA(int x1, int y1, int x2, int y2){
    int dx=(x2-x1);
    int dy=(y2-y1);
    int steps,k;

    float xinc, yinc;
    float x=x1;
    float y=y1;

    if (fabs(dx)>fabs(dy))
    {
        steps = fabs(dx);
    }
    else{
        steps = fabs(dy);
    }

    xinc = float (dx) / float (steps);
    yinc = float (dy) / float (steps);

    glBegin(GL_POINTS);
        glVertex2i(round_off(x), round_off(y));
    glEnd();

    for (k = 0; k < steps; k++)
    {
        x += xinc;
        y += yinc;
        glBegin(GL_POINTS);
            glVertex2i(round_off(x), round_off(y));
        glEnd();
    }
    glFlush();
}

void Draw(void){
    int x1,y1,x2,y2;
    cout<<"\nEnter first point";
    cin>>x1>>y1;
    cout<<"\nEnter second poin";
    cin>>x2>>y2;

    lineDDA(x1,y1,x2,y2);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("DDA");

    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
}
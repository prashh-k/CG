#include <GL/glut.h>

void Init(void){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400.0f, 400.0f, -400.0f, 400.0f);
}

void Draw_triangle(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.7f, 0.3f);
    glBegin(GL_TRIANGLES);
        glVertex2i(-200, -200);
        glVertex2i(200, -200);
        glVertex2i(0, 150);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Triangle");

    Init();
    glutDisplayFunc(Draw_triangle);
    glutMainLoop();
}
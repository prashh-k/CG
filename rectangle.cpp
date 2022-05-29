#include <GL/glut.h>

void Init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}

void draw_rectangle(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.7, 0.3);
    glBegin(GL_QUADS);
        glVertex2i(-220, -220);
        glVertex2i(220, -220);
        glVertex2i(220, 220);
        glVertex2i(-220, 220);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rectangle");

    Init();
    glutDisplayFunc(draw_rectangle);
    glutMainLoop();
}
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "vector"

using namespace std;

float WinWid = 400.0;
float WinHei = 400.0;

class Cube {
public:
    int x, y;
    Cube(int x_, int y_):x(x_), y(y_) {}
    void draw() {
        glTranslatef(x, y, 0);
        glutSolidCube(10);
        glLoadIdentity();
    }
};

vector<Cube> cubes;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    for(vector<Cube>::iterator i = cubes.begin(); i!=cubes.end(); i++) {
        i->draw();
    }
    
    glutSwapBuffers();
}

void Timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, Timer, value);
}

void Mouse(int botton, int state, int x, int y) {
    Cube c(x, y);
    cubes.push_back(c);
}

void Reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -15, 15);
    glMatrixMode(GL_MODELVIEW);
}

void Init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WinWid, WinHei, 0, -15.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    
    glutCreateWindow("Lesson 16");
    glutDisplayFunc(Draw);
    Init();
    glutTimerFunc(50, Timer, 0);
    glutMouseFunc(Mouse);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    
    return 0;
}

/*
    This software is owned by Mehmet Tezel.
    You can change and use as you wish.
    (Provided that the source is specified)
*/

#include <GL/glut.h>
#include <cstdlib>

float x = 0.0, x2 = 0.0;
float y = 0.0, y2 = 0.0;
float z = -10.0, z2 = -10.0;
const float step = 0.1;
float angle = 0.0f;

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
    case 'f':
        glutFullScreen();
        break;
    /* DON'T USE 
    case '0':
        angle += 1;
    case '1':
        x2 += -1;
    case '2':
        x2 += 1;
    case '3':
        y2 += -1;
    case '4':
        y2 += 1;
    case '5':
        z2 += -1;
    case '6':
        z2 += 1; */
    }

}

void speckeyboard(int key, int, int) // from Stackoverflow
{

    if (GLUT_KEY_LEFT == key)
    {
        x -= step;
    }
    if (GLUT_KEY_RIGHT == key)
    {
        x += step;
    }
    if (GLUT_KEY_UP == key)
    {
        y += step;
    }
    if (GLUT_KEY_DOWN == key)
    {
        y -= step;
    }
    /*if (GLUT_KEY_F1 == key) DON'T USE
    {
        x2 += step;
    }
    if (GLUT_KEY_F2 == key)
    {
        y2 += step;
    }
    if (GLUT_KEY_F3 == key)
    {
        z2 += step;
    }*/
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, z);
    glRotatef(angle, 1.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);

    // Top Edge
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Bottom Edge
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Right Edge
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Left Edge
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Front
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Back
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    angle += 0.1f;

    glEnd();
    glFlush();

    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0)
    {
        return;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("WF CUBE");
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(speckeyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

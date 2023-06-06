 #include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>

using namespace std;

const int width = 1000;
const int height = 1000;

GLfloat eyeX = 0;
GLfloat eyeY = 0;
GLfloat eyeZ = 30;

GLfloat lookX = 0;
GLfloat lookY = 0;
GLfloat lookZ = 0;

static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float r,float g,float b)
{

    glBegin(GL_QUADS);
    glColor3d(r,g,b);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);

    glPushMatrix();

    glTranslated(-15,0,0);

    // Draw 2
    glPushMatrix();
    glScaled(1,5,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


glPushMatrix();
    glScaled(6,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,5,0);
    glScaled(6,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,10,0);
    glScaled(6,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

glPushMatrix();
    glTranslated(5,5,0);
    glScaled(1,6,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

    //0

    glPushMatrix();
    glTranslated(9,5,0);
    glRotated(45,0,0,1);
    glScaled(7,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


     glPushMatrix();
    glTranslated(8,0,0);
    glScaled(1,11,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

glPushMatrix();
    glTranslated(9,5,0);
    glRotated(-45,0,0,1);
    glScaled(7,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


    // Draw 2
    glPushMatrix();
    glTranslated(17,0,0);
    glScaled(5,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


glPushMatrix();
glTranslated(17,0,0);
    glScaled(1,6,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


    glPushMatrix();
    glTranslated(17,5,0);
    glScaled(5,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

glPushMatrix();
    glTranslated(22,5,0);
    glScaled(1,6,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

glPushMatrix();
    glTranslated(17,10,0);
    glScaled(6,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

  //3

    glPushMatrix();
    glTranslated(27,0,0);
    glScaled(5,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();


    glPushMatrix();
    glTranslated(32,0,0);
    glScaled(1,10,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

    glPushMatrix();
    glTranslated(27,10,0);
    glScaled(6,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();

        glPushMatrix();
    glTranslated(27,5,0);
    glScaled(6,1,1);
    cube(0.0,1.0,0.0); // green cube
    glPopMatrix();



    glPopMatrix();
    glutSwapBuffers();
}





static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'w':
        eyeY=eyeY+0.1;
        break;
    case 's':
        eyeY=eyeY-0.1;
        break;
    case 'd':
        eyeX=eyeX+0.1;
        break;
    case 'a':
        eyeX=eyeX-0.1;
    break;

    case 'i':
        lookY=lookY+0.1;
        break;
    case 'k':
        lookY=lookY-0.1;
        break;
    case 'j':
        lookX=lookX+0.1;
        break;
    case 'l':
        lookX=lookX-0.1;
        break;


    case '+':
        eyeZ=eyeZ+0.1;
        break;
    case '-':
        eyeZ=eyeZ-0.1;
        break;

    }

    glutPostRedisplay();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Triangle-Demo");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();

    return 0;
}

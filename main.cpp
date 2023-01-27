#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include <iostream>
#include "BmpLoader.h"
double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1000, windowWidth=1000;
GLfloat nightTheta=0, t=42,t2=44, sunx=0,suny=0, alpha = 0.0, theta = 0.0,thetaa = 0.0, beta = 0.0, axis_x=0.0, axis_y=0.0, axis_z=0.0, theta_fan_rotate = 0.0, tap_dis1 = 4.5, tap_dis2 = 4.3;
GLboolean  bRotate = false, uRotate = false, tRotate = false, fan_Rotate = false,light_0_on = true, light_1_on = true, light_2_on = true, light_toggle = false, tap_open = false;
GLboolean  amb_light_0 = true, dif_light_0 = true, spec_light_0 = true, amb_light_1 = true, dif_light_1 = true, spec_light_1 = true, amb_light_2 = true, dif_light_2 = true, spec_light_2 = true;
GLboolean nag_Rotate=false, activate_pitch = false, activate_yaw = false, activate_roll = false;
GLfloat skyTheta=0, door_theta = 0,theta_circle = 0.0;
GLboolean dRotate1 = false,skyRotate=false,night =false ;
GLboolean dRotate=false, dRotate2 = true;
GLfloat eyeX = 0;
GLfloat eyeY = 3;
GLfloat eyeZ = 120;

GLfloat lookX = 0;
GLfloat lookY = 0;
GLfloat lookZ = 50;


GLfloat upx = 0;
GLfloat upy = 1;
GLfloat upz = 0;


GLdouble cardx = -9.6;
GLdouble cardz = -14.8, cashz=-13.6;

GLfloat scale_x = 1;
GLfloat scale_y = 1;
GLfloat scale_z = 1;

double limit = 360;
double roll_value = 5;
GLfloat angleYaw =90.0, anglePitch = 0.0, angleRoll = 90.0;
GLfloat angleYawLimit1 = 180.0, anglePitchLimit1 = 90.0, angleRollLimit1 = 270.0;
GLfloat angleYawLimit2 = 0.0, anglePitchLimit2 = -90.0, angleRollLimit2 = -90.0;
GLdouble ttx=0,tty=0,ttz=0;
int f = 0;

GLfloat lidTheta = 0,doorDistx1 = 0, doorDistx2 =   0, doorDistz=0;
GLfloat pirateBoatTheta = 0.0;
GLboolean pirateBoatFlag = false, pirateBoatCheck = false,lidOpen = false, lidClose=false,doorOpen= false, doorClose=false;
unsigned int ID,ID1;




#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>	//Needed for console output (debugging)
#include <gl/freeglut.h>
#include <vector>
#include <iostream>
#include <thread>

#ifdef WIN32
#include "gltools.h"
#include <windows.h>		// Must have for Windows platform builds
//#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
//#include <gl\glu.h>			// OpenGL Utilities
//#include "glm.h"

#endif

//refernce files
#include "3DExample1\\camera.h"
#include "3DExample1\\vec.h"
#include "3DExample1\\assets.h"
#include <sstream>


#define OBJPATH = "3DExample1\\objects\\";
#define TEXTUREPATH = "3DExample1\\textures\\";

vec3 color = { 0.8, 0.8, 0.8 };

asset sun;


//////////////////////////////////////////////////////////////////////

GLfloat PI = 3.14159265;
static GLfloat cube[8][3] =
{
    {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0},
    {1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0},


    {-1.0, -1.0, -1.0},
    {1.0, -1.0, -1.0},
    {1.0, 1.0, -1.0},
    {-1.0, 1.0, -1.0},

};



//static GLubyte p_Indices[2][3] =
//{
//    {0, 1, 2},
//    {3, 4, 5}
//};

static GLubyte quadIndices[6][4] =
{
    {0,1,2,3},
    {7,6,5,4},
    {2,6,7,3},

    {0,4,5,1},
    {2,1,5,6},
    {7,4,0,3},

};

static GLfloat colors[6][3] =
{
    {0.0, 0.0, 1.0},
    {0.5, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.5,0.5,0.5},
};
static GLfloat cube2[8][3] =
{
    {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0},
    {1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0},


    {-1.0, -1.0, -1.0},
    {1.0, -1.0, -1.0},
    {1.0, 1.75, -1.0},
    {-1.0, 1.75, -1.0},

};
void drawcube2(GLint c1, GLint c2, GLint c3, GLboolean emission = false)
{

    GLfloat r = c1/255.0;
    GLfloat g = c2/255.0;
    GLfloat b = c3/255.0;

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    GLfloat mat_em[] = {r,g,b,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);




    for (GLint i = 0; i <6; i++)
        for (GLint i = 0; i <6; i++)
        {
            glBegin(GL_QUADS);

            glVertex3fv(&cube2[quadIndices[i][0]][0]);
            glTexCoord2f(1,1);
            glVertex3fv(&cube2[quadIndices[i][1]][0]);
            glTexCoord2f(1,0);
            glVertex3fv(&cube2[quadIndices[i][2]][0]);
            glTexCoord2f(0,0);
            glVertex3fv(&cube2[quadIndices[i][3]][0]);
            glTexCoord2f(0,1);
            glEnd();
        }

}


void drawcube(GLint c1, GLint c2, GLint c3, GLboolean emission = false)
{

    GLfloat r = c1/255.0;
    GLfloat g = c2/255.0;
    GLfloat b = c3/255.0;

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    GLfloat mat_em[] = {r,g,b,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);




    for (GLint i = 0; i <6; i++)
    {
            glBegin(GL_QUADS);

            glVertex3fv(&cube[quadIndices[i][0]][0]);
            glTexCoord2f(1,1);
            glVertex3fv(&cube[quadIndices[i][1]][0]);
            glTexCoord2f(1,0);
            glVertex3fv(&cube[quadIndices[i][2]][0]);
            glTexCoord2f(0,0);
            glVertex3fv(&cube[quadIndices[i][3]][0]);
            glTexCoord2f(0,1);
            glEnd();
    }



}


void cylinder(GLint c1, GLint c2,GLint c3)
{

    GLfloat r = c1/255.0;
    GLfloat g = c2/255.0;
    GLfloat b = c3/255.0;

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};


    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    const double PI = 3.14159;

    /* top triangle */
    double i, resolution  = 0.1;
    double height = 1;
    double radius = 0.5;

    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    //top Circle
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(0, height, 0);  /* center */
        for (i = 2 * PI; i >= 0; i -= resolution)

        {
            glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
        /* close the loop back to 0 degrees */
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(radius, height, 0);
    glEnd();


    //bottom Circle
     glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(0, 0, 0);  /* center */
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
            glVertex3f(radius * cos(i), 0, radius * sin(i));
        }
    glEnd();



    //cylinder side
    glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            const float tc = ( i / (float)( 2 * PI ) );
            glTexCoord2f( tc, 0.0 );
            glVertex3f(radius * cos(i), 0, radius * sin(i));
            glTexCoord2f( tc, 1.0 );
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
        /* close the loop back to zero degrees */
        glTexCoord2f( 0.0, 0.0 );
        glVertex3f(radius, 0, 0);
        glTexCoord2f( 0.0, 1.0 );
        glVertex3f(radius, height, 0);
    glEnd();

    glPopMatrix();


}
void fan_handle_s()
{
    glPushMatrix();
    glTranslatef( 0,18.8,0);
    glScalef(0.2,1.0,0.2);
    drawcube(0, 0, 0);
    glPopMatrix();
}
void fan_s()
{
    glPushMatrix();
    glRotatef(theta_fan_rotate, 0.0, 1.0, 0.0);
    glTranslatef( 0,18,0);
    glScalef(0.4, 0.4, 0.4);
    for(int i = 0; i < 180; i++){
        glPushMatrix();
        glScalef(2.0,0.5,1.0);
        glRotatef(theta_circle+=2, 0.0, 1.0, 0.0);
        drawcube(0, 0, 0);
        glPopMatrix();
    }
    glPushMatrix();
    glScalef(7.0,0.3,2.0);
    drawcube(0, 0, 0);
    glPopMatrix();
    glPushMatrix();
    glRotatef(120, 0.0, 1.0, 0.0);
    glScalef(7.0,0.3,2.0);
    drawcube(0, 0, 0);
    glPopMatrix();
    glPushMatrix();
    glRotatef(240, 0.0, 1.0, 0.0);
    glScalef(7.0,0.3,1.5);
    drawcube(0, 0, 0);
    glPopMatrix();
    glPopMatrix();
}
void pillow()
{
        //blanket
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,5.6+.75+.2,7);
    glScalef(4.3,.4, 2);
    glBindTexture(GL_TEXTURE_2D, 12);
    drawcube(255,255, 0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //pillow
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-2.1,5.6+.75+.2,-7);
    glScalef(1.9,.5, 2);
     glBindTexture(GL_TEXTURE_2D, 13);
    drawcube(255,255, 255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(2.1,5.6+.75+.2,-7);
    glScalef(1.9,.5, 2);
     glBindTexture(GL_TEXTURE_2D, 13);
    drawcube(255,255, 255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
}
void singlebed()
{
        //bed

//bed floor
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,40);
    glPushMatrix();

    glTranslatef(14,6,0);
    glScalef(4,.2,10);
    drawcube(200,75,75);

    glPopMatrix();

    //bed uporer wall
    glPushMatrix();
    glTranslatef(14,7,-10);
    glScalef(4,1,.1);
    drawcube(200,75,75);

    glPopMatrix();
//bed nicher wall
    glPushMatrix();
    glTranslatef(14,6,10);
    glScalef(4,.8,.1);
    drawcube(200,75,75);
    glPopMatrix();
//bed nicher paa
    glPushMatrix();
    glTranslatef(11,4,9);
    glScalef(.5,2,.5);
    drawcube(200,75,75);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(17,4,9);
    glScalef(.5,2,.5);
    drawcube(200,75,75);
    glPopMatrix();
    glPushMatrix();

    //bed uporer paa


    glTranslatef(11,4,-8);
    glScalef(.5,2,.5);
    drawcube(200,75,75);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(17,4,-8);
    glScalef(.5,2,.5);
    drawcube(200,75,75);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //bed uporer mattress

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(14,7,.5);
    glScalef(3.8,.4,9.3);
    glBindTexture(GL_TEXTURE_2D,41);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}




void doublebed()
{
        //bed
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,40);
//bed floor
    glPushMatrix();

    glTranslatef(14,6,0);
    glScalef(6.5,.2,10);
    drawcube(255,255,255);

    glPopMatrix();

    //bed uporer wall
    glPushMatrix();
    glTranslatef(14,7,-10);
    glScalef(6.5,1,.1);
    drawcube(255,255,255);

    glPopMatrix();
//bed nicher wall
    glPushMatrix();
    glTranslatef(14,6,10);
    glScalef(6.5,.8,.1);
    drawcube(255,255,255);
    glPopMatrix();
//bed nicher paa

    glPushMatrix();

    glTranslatef(9,4,9);
    glScalef(.5,2,.5);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(19,4,9);
    glScalef(.5,2,.5);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();


    //bed uporer paa
    glTranslatef(9,4,-8);
    glScalef(.5,2,.5);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(19,4,-8);
    glScalef(.5,2,.5);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //bed uporer mattress
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    glTranslatef(14,7,.5);
    glScalef(6.3,.4,9.3);
    glBindTexture(GL_TEXTURE_2D,41);
    drawcube(255,255,255);

    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
}

void disk(GLfloat r,
          GLfloat g,
          GLfloat b,
          GLboolean emission = false )
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);

    GLUquadric* qobj;
    qobj = gluNewQuadric();
    gluDisk(qobj,0,5,20,10);
}
void draw_door(){
    //door
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,7,20);
    glScalef(4,7,.3);
    glBindTexture(GL_TEXTURE_2D,24);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void draw_room()
{

    //ceil
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,20,0);
    glScalef(20,0.1,20);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(168, 168, 168);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //floor
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(20,0.1,20);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(168, 168, 168);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //fan
    glPushMatrix();
    fan_s();
    fan_handle_s();
    glPopMatrix();


    //tiles
    glPushMatrix();
    for(GLint hCount=1; hCount<40; hCount+=4)
    {
        for(GLint vCount=1; vCount<40; vCount+=4)
        {
            if((hCount+vCount)%2==0)
            {
                glPushMatrix();
                glTranslatef(-19+hCount,0.1,-19+vCount);
                glScalef(1.5,0.1,1.5);

                drawcube(25,25,25);
                glPopMatrix();
            }

        }

    }
    glPopMatrix();


    //left wall
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-20,10,0);
    glScalef(.1,10,20);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //right wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(20,10,0);
    glScalef(.1,10,20);
    glBindTexture(GL_TEXTURE_2D,25);
   drawcube(0,166,166);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //back wall left
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-12,10,-20);
    glRotatef(180,0,1,0);
    glScalef(8,10,.1);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //backwall right
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(12,10,-20);
    glRotatef(180,0,1,0);
    glScalef(8,10,.1);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //backwall bottom
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,2.5,-20);
    glScalef(8,2.5,.1);
    glRotatef(180,0,1,0);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //backwall top
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,17.5,-20);
    glScalef(8,2.5,.1);
    glRotatef(180,0,1,0);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //windowframe
    glPushMatrix();
    glTranslatef(0,10,-20);
    glScalef(.5,5,.1);
    glRotatef(180,0,1,0);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,4*2.5,-20);
    glRotatef(180,0,1,0);
    glScalef(4,0.5,.1);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,10,-20);
    glRotatef(180,0,1,0);
    glScalef(.5,5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,10,-20);
    glRotatef(180,0,1,0);
    glScalef(.5,5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,5*3,-20);
    glRotatef(180,0,1,0);
    glScalef(4.9,0.5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.5*3,-20);
    glRotatef(180,0,1,0);
    glScalef(4.9,0.5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();


    //bathroom
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-10, 10, -10);
    glScalef(0.2, 10, 10);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(200,200,125);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-15,10,0);
    glScalef(5,10,.2);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(200,200,125);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //bathroom door

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-15,6,0.1);
    glScalef(3,6,.2);
    glBindTexture(GL_TEXTURE_2D,24);
    drawcube(200,75,75);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(-13,6,0.1);
    glScalef(.2,.5,.3);
    drawcube(100,37,37);
    glPopMatrix();




    ///frontwalls

    //front leftwall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-12,10,20);
    glScalef(8,10,.2);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
    //front rightwall
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(12,10,20);
    glScalef(8,10,.2);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
    //front topwall
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,17,20);
    glScalef(4,3,.2);
    glBindTexture(GL_TEXTURE_2D,25);
    drawcube(0,166,166);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);





    //door
    glPushMatrix();
    glTranslatef(-4,7,20);
    glRotatef(door_theta, 0,1,0);
    glTranslatef(4,-7,-20);
    draw_door();
    glPopMatrix();

}
void roof(){

    glPushMatrix();
    glTranslatef(0,40.2,1);
    glScalef(64,.4,22);
    drawcube(166,166,166);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-5,41,5);
    glScalef(70,.6,30);
    drawcube(66,66,66);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,46,34.2);
    glScalef(70,5,1);
    drawcube(66,66,66);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,46,-26);
    glScalef(70,5,1);
    drawcube(66,66,66);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,46,-26);
    glScalef(70,5,1);
    drawcube(66,66,66);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(64.2,46,4.6);
    glScalef(1,5,30);
    drawcube(66,66,66);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-74.2,46,9.8);
    glScalef(1,5,25);
    drawcube(66,66,66);
    glPopMatrix();

        //extraShiri
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-81,40.6,-23.2);
    glScalef(6,1,2);
    glBindTexture(GL_TEXTURE_2D,17);
    drawcube(244,201,105);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
}


void firstFloorFence(){


    //horizontal lines
    glPushMatrix();

    glTranslatef(-8.3,27,31.6);
    glScalef(77,.4,.4);
    drawcube(50,50,50);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(68.8,27,26.2);
    glScalef(.4,.4,6);
    drawcube(50,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-85,27,27);
    glScalef(.4,.4,4.5);
    drawcube(50,50,50);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(64.6,27,19.8);
    glScalef(4.5,.4,.4);
    drawcube(50,50,50);
    glPopMatrix();



    //vertical lines

    for(GLint i = 0; i<76;i++){
        glPushMatrix();
        glTranslatef(67.2-i*2,23,31.4);
        glScalef(.4,3.6,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }
    //fence towards z axis right
    for(GLint i = 1; i<7;i++){
        glPushMatrix();
        glTranslatef(68.4,23,32.2-i*2);
        glScalef(.4,3.6,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }
    //fence towards z axis left
    for(GLint i = 1; i<7;i++){
        glPushMatrix();
        glTranslatef(-84.8,23,33.2-i*2);
        glScalef(.4,3.6,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }
    for(GLint i = 1; i<5;i++){
        glPushMatrix();
        glTranslatef(69-i*2,23,19.8);
        glScalef(.4,3.6,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }





}


void groundFence(){

    //horizontal lines
    //right
    glPushMatrix();
    glTranslatef(40.5,7,29);
    glScalef(20,.4,.4);
    drawcube(50,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(58,7,24.5);
    glScalef(.4,.4,4.5);
    drawcube(50,50,50);
    glPopMatrix();


    //left
     glPushMatrix();
    glTranslatef(-45.5,7,29);
    glScalef(25,.4,.4);
    drawcube(50,50,50);
    glPopMatrix();


    //vertical fences
    //right
    for(GLint i = 0; i<20;i++){
        glPushMatrix();
        glTranslatef(58-i*2,3.5,29);
        glScalef(.4,3.2,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }
    //left
     for(GLint i = 40; i<65;i++){
        glPushMatrix();
        glTranslatef(58-i*2,3.5,29);
        glScalef(.4,3.2,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }



    //fence towards z axis right
    for(GLint i = 1; i<5;i++){
        glPushMatrix();
        glTranslatef(58,3.5,29-i*2);
        glScalef(.4,3.2,.4);
        drawcube(255,255,255);
        glPopMatrix();
    }




}
void washingMachine()
{
                                    //washingMachine
    glPushMatrix();
    glTranslatef(-16.8,3.4,14.2);
    glScalef(2.2,3.1,2.2);
    drawcube(255,255,255);
    glPopMatrix();
    //buttonHolder
    glPushMatrix();
    glTranslatef(-14.6,5.8,14.2);
    glScalef(.2,.5,2);
    drawcube(0,0,0);
    glPopMatrix();

    //window
    glPushMatrix();
    glTranslatef(-14.4,2.8,14.2);
    glRotatef(90,0,1,0);
    glScalef(.35,.35,.35);
    disk( .3, .2, .3);
    glPopMatrix();

    //windowHandle
    glPushMatrix();
    glTranslatef(-14.4,2.8,13);
    glScalef(.08,.5,.18);
    drawcube(0,0,0);
    glPopMatrix();


        //golla button
    glPushMatrix();
    glTranslatef(-14.2,5.9,15.5);
    glRotatef(90,0,1,0);
    glScalef(.06,.06,.06);
    disk(1,1,1);
    glPopMatrix();

    //button
    glPushMatrix();
    glTranslatef(-14.4,5.6,12.4);
    glScalef(.07,.07,.07);
    drawcube(255,255,255);
    glTranslatef(0,3,0);
    drawcube(255,255,255);
    glTranslatef(0,3,0);
    drawcube(255,255,255);
    glTranslatef(0,-3,4);
    drawcube(255,255,255);
    glTranslatef(0,-3,0);
    drawcube(255,255,255);
    glTranslatef(0,0,4);
    drawcube(255,255,255);
    glTranslatef(0,3,0);
    drawcube(255,255,255);
    glTranslatef(0,0,4);
    drawcube(255,255,255);
    glTranslatef(0,-3,0);
    drawcube(255,255,255);
    glTranslatef(0,0,4);
    drawcube(255,255,255);
    glTranslatef(0,3,0);
    drawcube(255,255,255);
    glTranslatef(0,3,0);
    drawcube(255,255,255);
    glPopMatrix();
}
void atm()
{
    //atm
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.2, -11.4, -14.85);
    glScalef(2.3,1.5,1.7);
    glBindTexture(GL_TEXTURE_2D,3);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.2, -8.2,-15.9);
    glScalef(2.3,1.7,0.6);
    glBindTexture(GL_TEXTURE_2D,3);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //atm shade
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.2, -6.1,-14.6);
    glRotatef(-25,1,0,0);
    glScalef(2.3,0.5,1.8);
    glBindTexture(GL_TEXTURE_2D,3);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //atm card port

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-9.6, -8.6, -15.2);
    glScalef(0.1,0.1,0.1);
    //glBindTexture(GL_TEXTURE_2D,1);
    disk( 1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //atm card
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(cardx, -8.6, cardz);
    glScalef(0.2,0.02,0.35);
    glBindTexture(GL_TEXTURE_2D,1);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //atm screen
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.8, -8.4,-15.5);
    glScalef(1.5,1.4,0.3);
    glBindTexture(GL_TEXTURE_2D,2);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //atm keyboard
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.8,-10.18, -14.6);
    glRotatef(90,1,0,0);
    glScalef(1.5,1.4,0.3);
    glBindTexture(GL_TEXTURE_2D,4);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //atm divider
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-5, -9.2, -13.8);
    glRotatef(90,0,1,0);
    glScalef(3,3.6,0.3);
    glBindTexture(GL_TEXTURE_2D,3);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //cashport
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.2, -10.8, -13.6);
    glScalef(1.5,0.2,0.5);
    glBindTexture(GL_TEXTURE_2D,3);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //cash
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-11.2, -10.7, cashz);
    glScalef(0.22,0.02,0.35);
    glBindTexture(GL_TEXTURE_2D,5);
    drawcube(1,1,1);
    glTranslatef(0,-3,0.1);
    glBindTexture(GL_TEXTURE_2D,5);
    drawcube(1,1,1);
    glTranslatef(0,-3,0.1);
    glBindTexture(GL_TEXTURE_2D,5);
    drawcube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}



void firstFloor()
{
    glPushMatrix();
    draw_room();
    glTranslatef(-40,0,0);
    singlebed();
    washingMachine();
    glPopMatrix();

    glPushMatrix();
    singlebed();
    washingMachine();
    glTranslatef(40,0,0);
    singlebed();
    washingMachine();
    draw_room();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40,0,0);

    draw_room();
    glPopMatrix();
}

void secondFloor()
{
    glPushMatrix();
    glTranslatef(0,20,0);
    draw_room();
    washingMachine();
    glTranslatef(-2,0,0);
    doublebed();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,20,0);
    draw_room();
    washingMachine();
     glTranslatef(-2,0,0);
    doublebed();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40,20,0);
    draw_room();
    washingMachine();
     glTranslatef(-2,0,0);
    doublebed();
    glPopMatrix();
}
void sofa()
{
    glPushMatrix();
    glScalef(4,2,.6);
    drawcube(55,255,55);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.6, -0.4,1.4);
    glScalef(.6, 1.6, 2);
    drawcube(244,55,89);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4.6, -0.4,1.4);
    glScalef(.6, 1.6, 2);
    drawcube(244,244,89);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-.8,1.8);
    glScalef(4,.4,1.2);
    drawcube(55,100,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1.2, 3);
    glScalef(4,.7,.3);
    drawcube(255,255,255);
    glPopMatrix();


    //sofa
    glPushMatrix();
    glTranslatef(-1.95, 1, 0.8);
    glScalef(1.9,1,.2);
    drawcube(255,70,70);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.95, 1, 0.8);
    glScalef(1.9,1,.2);
    drawcube(255,70,70);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.95, -0.2, 1.8);
    glScalef(1.9,.2,1.2);
    drawcube(55,200,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.95, -0.2, 1.8);
    glScalef(1.9,.2,1.2);
    drawcube(55,200,255);
    glPopMatrix();

    //cushion
    glPushMatrix();
    glTranslatef(-3.2, 0.8, 1.8);
    glRotatef(45, 0,1,0);
    glScalef(.8,.8, .3);
    drawcube(255,255,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.2, 0.8, 1.8);
    glRotatef(-45, 0,1,0);
    glScalef(.8,.8, .3);
    drawcube(255,255,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0.8, 1.3);
    glScalef(.8,.8, .3);
    drawcube(255,255,255);
    glPopMatrix();





    //feet


    glPushMatrix();
    glTranslatef(4.9, -2.3, 0);
    glRotatef(15,1,0,0);
    glRotatef(15,0,0,1);
    glScalef(.2,.6,.2);
    cylinder(97, 47, 11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.9, -2.3, 3);
    glRotatef(-15,1,0,0);
    glRotatef(15,0,0,1);
    glScalef(.2,.6,.2);
    cylinder(97, 47, 11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9, -2.3, 3);
    glRotatef(-15,1,0,0);
    glRotatef(-15,0,0,1);
    glScalef(.2,.6,.2);
    cylinder(97, 47, 11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9, -2.3, 0);
    glRotatef(15,1,0,0);
    glRotatef(-15,0,0,1);
    glScalef(.2,.6,.2);
    cylinder(97, 47, 11);
    glPopMatrix();


}

void computer()
{

    //monitor
    glPushMatrix();
    glScalef(3.2,1.8,.2);
    drawcube(255,255,255);
    glPopMatrix();
    ///frames
    glPushMatrix();
    glTranslatef( 0, -1.7, 0.3);
    glScalef(3.2,.1,.1);
    drawcube(0,155,100);
    glPopMatrix();


    glPushMatrix();
    glTranslatef( 0, 1.7, 0.3);
    glScalef(3.2,.1,.1);
    drawcube(0,155,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.1, 0, 0.3);
    glScalef(.1,1.6,.1);
    drawcube(0,100,155);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.1, 0, 0.3);
    glScalef(.1,1.6,.1);
    drawcube(0,100,155);
    glPopMatrix();

    //texture
    glPushMatrix();
    glTranslatef(0, 0, 0.2);
    glScalef(3,1.6,.05);
    drawcube(170,50,50);
    glPopMatrix();


    //neck
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glRotatef(15,1,0,0);
    glScalef(.4,.6,.2);
    drawcube(120,120,120);
    glPopMatrix();

    //base plate

    glPushMatrix();
    glTranslatef(0, -2.8, 0);
    glScalef(1.5,.3,1.5);
    cylinder(120,120, 0);
    glPopMatrix();




    //keyboard
    glPushMatrix();
    glTranslatef(0,-2.8, 2.3);
    glScalef(1.8,.15,.8);
    drawcube(120,120,120);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-2.65,2.3);
    glScalef(1.8,.001,.8);
    drawcube(120,0,120);
    glPopMatrix();

    //mouse
    glPushMatrix();
    glTranslatef(2.8,-2.8, 2);
    glScalef(.2,.1,.5);
    drawcube(120,120,120);
    glPopMatrix();

}
void slidingDoor()
{

    glPushMatrix();
    glTranslatef(-0.2, 7.1, 20);
    glScalef(.2,7.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.9, 7.1, 20);
    glScalef(.2,7.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.1, .1,20);
    glScalef(3.7,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.1, 14.1,20);
    glScalef(3.7,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4, 7.2, 19.9);
    glScalef(3.7,7,.2);
    drawcube(86,134,136);
    glPopMatrix();
}

void windowFrame()
{
    //windowframe
    glPushMatrix();
    glTranslatef(0,10,-20);
    glRotatef(180,0,1,0);
    glScalef(.5,5,.1);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,4*2.5,-20);
    glRotatef(180,0,1,0);
    glScalef(4,0.5,.1);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,10,-20);
    glRotatef(180,0,1,0);
    glScalef(.5,5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,10,-20);
    glRotatef(180,0,1,0);
    glScalef(.5,5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,5*3,-20);
    glRotatef(180,0,1,0);
    glScalef(4.9,0.5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.5*3,-20);
    glRotatef(180,0,1,0);
    glScalef(4.9,0.5,.3);
    drawcube(173, 123, 7);
    glPopMatrix();


}

void draw_counter()
{
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,24,18);
    glScalef(18,4,1);
    glBindTexture(GL_TEXTURE_2D,38);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //ceil
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,20,0);
    glScalef(20,0.4,20);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255, 255, 255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //ceil frame
//    glPushMatrix();
//    glTranslatef(0, 20, 20.2);
//    glScalef(22, .5, .2);
//    drawcube(25,25,25);
//    glPopMatrix();




    //floor
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(20,0.1,20);
    glBindTexture(GL_TEXTURE_2D,31);
    drawcube(255, 255, 255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);






    //left wall
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-20,10,0);
    glScalef(.1,10,20);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    // right wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(20,10,0);
    glScalef(.1,10,20);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);


    ///backwall
    //back wall left
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-12,10,-20);
    glRotatef(180,0,1,0);
    glScalef(8,10,.1);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //backwall right
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(12,10,-20);
    glRotatef(180,0,1,0);
    glScalef(8,10,.1);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //backwall bottom
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,2.5,-20);
    glRotatef(180,0,1,0);
    glScalef(4,2.5,.1);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //backwall top
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(0,17.5,-20);
    glRotatef(180,0,1,0);
    glScalef(4,2.5,.1);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    windowFrame();
    glPopMatrix();


    ///bathroom
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-10, 10, -10);
    glScalef(0.2, 10, 10);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(200,200,200);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-15,10,0);
    glScalef(5,10,.2);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(200,200,125);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
    //bathroom door

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-15,6,0.1);
    glScalef(3,6,.2);
    glBindTexture(GL_TEXTURE_2D,24);
    drawcube(200,75,75);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(-13,6,0.1);
    glScalef(.2,.5,.3);
    drawcube(100,37,37);
    glPopMatrix();


    ///counter table

    glPushMatrix();
    glTranslatef(2.2, 3, -2.8);
    glScalef(12, 3, 3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2, 6.3, -.8);
    glScalef(12, .3, 1);
    drawcube(155,155,155);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.2, 6.9, -.8);
    glScalef(12, .3, 1);
    drawcube(55,55,55);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(11.2, 3, -12.8);
    glScalef(3,3,7.1);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(13.2, 6.3, -10.9);
    glScalef(1,.3,9.1);
    drawcube(155,155,155);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(13.2, 6.9, -10.9);
    glScalef(1,.3,9.1);
    drawcube(55,55,55);
    glPopMatrix();

    ///sofa
    glPushMatrix();
    glTranslatef(-19.2, 3.1, 12.2);
    glRotatef(90, 0,1,0);
    glScalef(1.2,1.2,1.2);
    sofa();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    ///computer
    glPushMatrix();
    glTranslatef(7.4, 8.4, -3);
    glRotatef(200,0,1,0);
    glScalef(.8,.8,.8);
    computer();
    glPopMatrix();


    ///frames


     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-7, 17.4, -19.9);
    glScalef(1,1.4,.05);
glBindTexture(GL_TEXTURE_2D,36);
    drawcube(235, 177, 61);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-3, 17.4, -19.9);
    glScalef(1,1.4,.05);
    glBindTexture(GL_TEXTURE_2D,36);
    drawcube(235, 177, 61);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0, 17.4, -19.9);
    glScalef(1,1.4,.05);
    glBindTexture(GL_TEXTURE_2D,36);
    drawcube(235, 177, 61);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(3.2, 17.4, -19.9);
    glScalef(1,1.4,.05);
    glBindTexture(GL_TEXTURE_2D,36);
    drawcube(235, 177, 61);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(6.2, 17.4, -19.9);
    glScalef(1,1.4,.05);
    drawcube(235, 177, 61);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);



    ///keyholder
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(10.8, 13.7, -19.9);
    glScalef(2.5,1.8,.05);
    glBindTexture(GL_TEXTURE_2D,34);
    drawcube(255, 255, 255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    ///clock

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(17, 16, -19.9);
    glRotatef(90,1,0,0);
    glScalef(5,.2,5);
    glBindTexture(GL_TEXTURE_2D,33);
    cylinder(200,200,200);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);


    ///front
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,17.3,20);
    glScalef(20,3,.2);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-14.1, 2.9,20);
    glScalef(6,3,.2);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(14.1, 2.9,20);
    glScalef(6,3,.2);
    glBindTexture(GL_TEXTURE_2D,32);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(-9.1,10.1, 20);
    glScalef(1,4.2,.2);
    drawcube(155,0,155);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(9.1,10.1, 20);
    glScalef(1,4.2,.2);
    drawcube(155,0,155);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-19.1,10.1, 20);
    glScalef(1,4.2,.2);
    drawcube(155,0,155);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(19.1,10.1, 20);
    glScalef(1,4.2,.2);
    drawcube(155,0,155);
    glPopMatrix();


    //counter window frame
    glPushMatrix();
    glTranslatef(-14.1, 5.7,20.2);
    glScalef(4.5,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.1, 5.7,20.2);
    glScalef(4.5,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.1, 14.5,20.2);
    glScalef(4.5,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-14.1, 14.5,20.2);
    glScalef(4.5,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-18.4,10.1,20.2);
    glScalef(.2,4.2,.2);
    drawcube(75,87,87);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(18.4,10.1,20.2);
    glScalef(.2,4.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.8,10.1,20.2);
    glScalef(.2,4.2,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.8,10.1,20.2);
    glScalef(.2,4.2,.2);
    drawcube(75,87,87);
    glPopMatrix();


    //window
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(14.1, 10.1, 20.1);
    glScalef(4.3,4.3,.2);
    glBindTexture(GL_TEXTURE_2D,28);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-14.1, 10.1, 20.1);
    glScalef(4.3,4.3,.2);
    glBindTexture(GL_TEXTURE_2D,28);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //door part left
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(doorDistx1, 0, doorDistz);
    glScalef(1.01,1.005,1);
    glBindTexture(GL_TEXTURE_2D,29);
    slidingDoor();
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //door part right
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(doorDistx2, 0, doorDistz);
    glTranslatef(8.1,0,0);
    glScalef(1.01,1.005,1);
    glBindTexture(GL_TEXTURE_2D,30);
    slidingDoor();
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

    //door frame
    glPushMatrix();
    glTranslatef(-8.5, 7.3, 20.2);
    glScalef(.2,7.4,.2);
    drawcube(75,87,87);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8.5, 7.3, 20.2);
    glScalef(.2,7.4,.2);
    drawcube(75,87,87);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 14.7, 20.2);
    glScalef(8.7,.2,.2);
    drawcube(75,87,87);
    glPopMatrix();



}

void platform()
{
    glPushMatrix();
    glTranslatef(-5,0,5);
    glScalef(66,.5,30);
    //drawcube(255,255,255);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-5,-3.5,5);
    glScalef(70,3,33);
    glBindTexture(GL_TEXTURE_2D,26);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //ground stairs
    glPushMatrix();
    glTranslatef(0,0,2);


     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-0,-5.5,45);
    glScalef(10,1,3);
    glBindTexture(GL_TEXTURE_2D,27);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-0,-3.5,42);
    glScalef(10,1,3);
    glBindTexture(GL_TEXTURE_2D,27);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-0,-1.5,39);
    glScalef(10,1,3);
    glBindTexture(GL_TEXTURE_2D,27);
    drawcube(255,255,255);
    glPopMatrix();
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);



}
void sky(){
    glPushMatrix();
    glTranslatef(0,150,0);
    glScalef(200000,0,200000);
    drawcube(135,206,235);
    glPopMatrix();
}

void Bigground(){

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(200000,0,200000);
    drawcube(4, 204, 57);
    glPopMatrix();

}




void gasMchine()
{
        //gasMachineBase
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8,2,0);
    glScalef(5,.3,4);
    glBindTexture(GL_TEXTURE_2D,17);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8,0,0);
    glScalef(3.5,14,2.8);
    glBindTexture(GL_TEXTURE_2D,21);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8,14,0);
    glScalef(3.2,2,2.4);
    glBindTexture(GL_TEXTURE_2D,21);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8,11.6,2.6);
    glScalef(2,2.1,.4);
    glBindTexture(GL_TEXTURE_2D,20);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8,8,2.6);
    glScalef(2,.4,.4);
    glBindTexture(GL_TEXTURE_2D,19);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8.5,17,0);
    glScalef(1,2,1);
    glBindTexture(GL_TEXTURE_2D,16);
    cylinder(255,255,255);
    glTranslatef(1,0,0);
    cylinder(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslatef(-8.2,0,-19.2);
    glScalef(7,1.5,5);
    glBindTexture(GL_TEXTURE_2D,18);
    cylinder(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void PetrolPump()
{
    //top
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,25,0);
    glScalef(20,2,13);
    glBindTexture(GL_TEXTURE_2D,14);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //bottom
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(20,2,7);
    glBindTexture(GL_TEXTURE_2D,15);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //piller
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-16,0,0);
    glScalef(1,50,2);
    glBindTexture(GL_TEXTURE_2D,16);
    cylinder(255,255,255);
    glTranslatef(32,0,0);
    glBindTexture(GL_TEXTURE_2D,16);
    cylinder(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
     gasMchine();
     glTranslatef(16,0,0);
    gasMchine();
    glPopMatrix();

}
void rain()
{
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0.8,19,48.4);
    glScalef(20,1,17);
    glBindTexture(GL_TEXTURE_2D,37);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glTranslatef(19.8,6.2,61.8);
    glScalef(.6,13,.6);
    drawcube(126, 102, 138);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-18,6.2,61.8);
    glScalef(.6,13,.6);
    drawcube(126, 102, 138);
    glPopMatrix();



}
int i = 1;
GLuint ID_[100];
void LoadTexture(const char*filename)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}



void LoadTexture1(const char*filename)
{
    glGenTextures(1, &ID_[i]);
    glBindTexture(GL_TEXTURE_2D, ID_[i]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID_[i++]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}
void shiri()
{
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-137.2,30.1,-25.3);
    glRotatef(180,0,1,0);
    glPushMatrix();

    glTranslatef(-69.4,-29.2,-7.2);
    glScalef(6,1,2);
    glBindTexture(GL_TEXTURE_2D,17);
    drawcube(244,201,105);
    glTranslatef(0,2,-2);
    drawcube(244,201,105);
        glTranslatef(0,2,-2);
    drawcube(244,201,105);
        glTranslatef(0,2,-2);
    drawcube(244,201,105);
        glTranslatef(0,2,-2);
    drawcube(244,201,105);
        glTranslatef(0,2,-2);
    drawcube(244,201,105);
        glTranslatef(0,2,-2);
    drawcube(244,201,105);
            glTranslatef(0,2,-2);
    drawcube(244,201,105);
            glTranslatef(0,2,-2);
    drawcube(244,201,105);
                glTranslatef(0,2,-2);
    drawcube(244,201,105);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}





void draw_Sphere(GLint c1, GLint c2, GLint c3,GLboolean emission = false)
{
    GLfloat r = c1/255.0;
    GLfloat g = c2/255.0;
    GLfloat b = c3/255.0;
    glPushMatrix();

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    GLfloat mat_em[] = {r,g,b,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);


    glutSolidSphere(2,100,100);
    glPopMatrix();


}


void light(double x, double y, double z, GLenum L, bool light_on, bool spot, GLfloat r=1.0, GLfloat g=1.0, GLfloat b=1.0)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {r*0.3, g*0.3, b*0.3, 1.0};
    GLfloat light_diffuse[]  = { r*0.6, g*0.6, b*0.6, 1.0 };
    GLfloat light_specular[] = { r*0.6, g*0.6, b*0.6, 1.0 };
    GLfloat light_position[] = { x, y, z, 1.0 };

    glEnable(L);

    if(light_on)
    {

        if(L==GL_LIGHT0)
        {
            if(amb_light_0) glLightfv( L, GL_AMBIENT, light_ambient);
            else glLightfv( L, GL_AMBIENT, no_light);

            if(dif_light_0) glLightfv( L, GL_DIFFUSE, light_diffuse);
            else glLightfv( L, GL_DIFFUSE, no_light);

            if(spec_light_0) glLightfv( L, GL_SPECULAR, light_specular);
            else glLightfv( L, GL_SPECULAR, no_light);

        }
        else if(L==GL_LIGHT1)
        {
            if(amb_light_1) glLightfv( L, GL_AMBIENT, light_ambient);
            else glLightfv( L, GL_AMBIENT, no_light);

            if(dif_light_1) glLightfv( L, GL_DIFFUSE, light_diffuse);
            else glLightfv( L, GL_DIFFUSE, no_light);

            if(spec_light_1) glLightfv( L, GL_SPECULAR, light_specular);
            else glLightfv( L, GL_SPECULAR, no_light);

        }
        else if(L==GL_LIGHT2)
        {
            if(amb_light_2) glLightfv( L, GL_AMBIENT, light_ambient);
            else glLightfv( L, GL_AMBIENT, no_light);

            if(dif_light_2) glLightfv( L, GL_DIFFUSE, light_diffuse);
            else glLightfv( L, GL_DIFFUSE, no_light);

            if(spec_light_2) glLightfv( L, GL_SPECULAR, light_specular);
            else glLightfv( L, GL_SPECULAR, no_light);

        }



        glLightfv( L, GL_POSITION, light_position);
    }

    else
    {
        glLightfv( L, GL_AMBIENT, no_light);
        glLightfv( L, GL_DIFFUSE, no_light);
        glLightfv( L, GL_SPECULAR, no_light);
        glLightfv( L, GL_POSITION, no_light);
    }
//    glPushMatrix();
//    glTranslatef(x,y,z);
//    drawcube(0,0,0);
//    glPopMatrix();

    if(spot)
    {
        GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
        glLightfv(L, GL_SPOT_DIRECTION, spot_direction);
        glLightf( L, GL_SPOT_CUTOFF, 70);
    }

}
void trashLid(){

    glPushMatrix();
    glTranslatef(0,2.8,0);
    glRotatef(14.036,1,0,0);
    glScalef(3.1,.2,3.1);
    drawcube(68,76,81);
    glPopMatrix();
}

void trash(){

    glPushMatrix();
    glTranslatef(-3,0,0);
    glScalef(.2,2,3);
    drawcube2(30,85,41);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3,0,0);
    glScalef(.2,2,3);
    drawcube2(30,85,41);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,2.8);
    glScalef(2.8,2,.2);
    drawcube(26,72,34);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,.75,-2.8);
    glScalef(2.8,2.75,.2);
    drawcube(26,72,34);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-1.8,0);
    glScalef(2.8,.2,2.8);
    drawcube(147,159,159);
    glPopMatrix();


    //trash lid
    glPushMatrix();
    glTranslatef(0,2.8,-3.1);
    glRotatef(lidTheta, 1,0,0);
    glTranslatef(0,-2.8,3.1);
    trashLid();
    glPopMatrix();


    //pivot

    glPushMatrix();
    glTranslatef(-2.2, 3.4,-3.25);
    glRotatef(90,0,0,1);
    glScalef(.5,1,.5);
    cylinder(209,217,216);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2.2, 3.4,-3.25);
    glRotatef(90,0,0,1);
    glScalef(.5,1,.5);
    cylinder(209,217,216);
    glPopMatrix();



}
void drawSphere(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine=90)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidSphere (1.0, 16, 16);
}
static void getNormal3p
        (GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
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

static GLfloat v_cube[8][3] =
        {
                {0.0, 0.0, 0.0}, //0
                {0.0, 0.0, 3.0}, //1
                {3.0, 0.0, 3.0}, //2
                {3.0, 0.0, 0.0}, //3
                {0.0, 3.0, 0.0}, //4
                {0.0, 3.0, 3.0}, //5
                {3.0, 3.0, 3.0}, //6
                {3.0, 3.0, 0.0}  //7
        };
void drawCube1(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX=0, GLfloat ambY=0, GLfloat ambZ=0, GLfloat shine=50)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glBegin(GL_QUADS);

    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}
void chair()
{
    //seat part
    glPushMatrix();
    glScalef(0.5, 0.05, 0.5);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat left back
    glPushMatrix();
    glTranslatef(0, -1.5, 0);
    glScalef(0.05, 1.4, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat right back
    glPushMatrix();
    glTranslatef(1.35, -1.5, 0);
    glScalef(0.05, 1.4, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(0.5, 0.05, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 1.5 , 0);
    glScalef(0.5, 0.05, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScalef(0.5, 0.05, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat left front leg
    glPushMatrix();
    glTranslatef(0, -1.5, 1.3);
    glScalef(0.05, .55, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

    //seat right front leg
    glPushMatrix();
    glTranslatef(1.35, -1.5, 1.3);
    glScalef(0.05, .55, 0.05);
    drawCube1(0.8,0.2,0.4,  0.4,0.1,0.2);
    glPopMatrix();

}
void table()
{
    //table
    glPushMatrix();
    glScalef(4, 0.3, 4);
    drawSphere(0.8,0.4,0.00,  0.4,0.2,0);
    glPopMatrix();

    //stand
    glPushMatrix();
    glScalef(0.1, -1, -0.1);
    drawCube1(0,0,0, 0,0,0.5);
    glPopMatrix();

    //stand bottom
    glPushMatrix();
    glTranslatef(0, -2.8, 0);
    glScalef(1, 0.2, 1);
    drawSphere(1,0.549,0.00,  0.5,0.2745,0);
    glPopMatrix();
}
void diningSet()
{
    glPushMatrix();
    glTranslatef(0, -16, 0);
    table();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-8.8,0);
    glRotatef(90,-1,0,0);
    glutWireCone(7,3,10,1000);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-11,0);
    glScalef(.3,10,.3);
    cylinder(255,255,255);
    glPopMatrix();

    for(int i = 0; i <= 360; i+=72)
    {
        glPushMatrix();
        glRotatef(i, 0, 1, 0);
        glTranslatef(0, -17, -4);
        chair();
        glPopMatrix();
    }
}

void quad1()
{
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(10,4,3);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0,4,3);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0,3);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(10,0,3);
    glEnd();
}
void quad2()
{
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0,8,5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0,8,0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0,0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0,0,5);
    glEnd();
}
void materialProperty()
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}


void icecreamParlor()
{
    materialProperty();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    quad1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.5, 1);
    quad1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,3);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quad1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,4);

    glPushMatrix();
    glTranslatef(0, 0, -2);
    quad2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -2);
    quad2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, -2);
    glRotatef(90, 1, 0, 0);
    quad1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(0, 6, 1);
    glScalef(1, 0.5, 1);
    quad1();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


}

void pizzaHut()
{
    materialProperty();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,5);
    glPushMatrix();
    quad1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.5, 1);
    quad1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,6);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quad1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,7);
    glPushMatrix();
    glTranslatef(0, 0, -2);
    quad2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -2);
    quad2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, -2);
    glRotatef(90, 1, 0, 0);
    quad1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,8);
    glPushMatrix();
    glTranslatef(0, 6, 1);
    glScalef(1, 0.5, 1);
    quad1();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(5,4,3.4);
    glScalef(5,.2,1.8);
    glBindTexture(GL_TEXTURE_2D,9);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(2.5,4.4,3.7);
    glScalef(3,.2,3);
    glBindTexture(GL_TEXTURE_2D,10);
    cylinder(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(6.9,4.4,3.7);
    glScalef(3,.2,3);
    glBindTexture(GL_TEXTURE_2D,10);
    cylinder(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawCylinder(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine=90)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);

    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, 1.5, 1.5, 19, 32, 32);

}

void ground()
{
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture( GL_TEXTURE_2D, ID2[14]);

    glPushMatrix();
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(150,-20,150);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3f(150,-20,-150);
    glTexCoord2f(5.0f, 5.0f);
    glVertex3f(-100,-20,-100);
    glTexCoord2f(0.0f, 5.0f);
    glVertex3f(-100,-20,100);
    glEnd();
    glPopMatrix();

    //glDisable(GL_TEXTURE_2D);
}

void ground2()
{
   // glEnable(GL_TEXTURE_2D);
    // glBindTexture( GL_TEXTURE_2D, ID2[2]); //2

    glPushMatrix();
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(10,-19.8,10);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10,-19.8,-10);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-10,-19.8,-10);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-10,-19.8,10);
    glEnd();
    glPopMatrix();

    //glDisable(GL_TEXTURE_2D);
}
void boatBody()
{
    glPushMatrix();
    glTranslatef(-1.3, 0, 0);
    glScalef(1.5, 0.1, 1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.9, 0.9, 0.9,  0.0,0.0,0.0);
    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0, 1.5, 1.5);
//    glScalef(1.5, 1, 0.1);
//    glRotatef(180, 0, 0, 1);
//    glTranslatef(-1.25, -1.5, -1.25);
//    drawTrapezoid(0.412, 0.412, 0.412,  0.0,0.0,0.0);
//    //drawTrapezoid(0.4,0.4,0.4, 0.0,0.0,0.0);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0, 1.5, -1.5);
//    glScalef(5.5, 1, 0.1);
//    glRotatef(180, 0, 0, 1);
//    glTranslatef(-1.25, -1.5, -1.25);
//    drawTrapezoid(0.412, 0.412, 0.412,  0.0,0.0,0.0);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(5.5, 1.5, 0);
//    glRotatef(-42, 0, 0, 1);
//    glScalef(0.1, 1.3, 1);
//    glTranslatef(-1.5, -1.5, -1.5);
//    drawCube1(0.412, 0.412, 0.412,  0.0,0.0,0.0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-8.1, 1.5, 0);
//    glRotatef(42, 0, 0, 1);
//    glScalef(0.1, 1.3, 1);
//    glTranslatef(-1.5, -1.5, -1.5);
//    drawCube1(0.412, 0.412, 0.412,  0.0,0.0,0.0);
//    glPopMatrix();
//
//    for(float i=-6; i<=2; i+=2)
//    {
//        glPushMatrix();
//        glTranslatef(i, 0, -1.5);
//        glScalef(0.1, 1, 1);
//        drawCube1(0.412, 0.412, 0.412,  0.0,0.0,0.0);
//        glPopMatrix();
//    }

    // glEnable(GL_TEXTURE_2D);
    //glBindTexture( GL_TEXTURE_2D, ID2[3] );

//    glPushMatrix();
//    glTranslatef(-6.9, 0, 1.7);
//    glScalef(3.7, 1, 0.01);
//    drawBox();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-6.9, 0, -1.7);
//    glScalef(3.7, 1, 0.01);
//    drawBox();
//    glPopMatrix();
    //glDisable(GL_TEXTURE_2D);
}


void pirateBoat()
{
    glPushMatrix();
    glTranslatef(1, 0, 0);
    glScalef(1.3, 1, 1.3);
    ground2();
    glPopMatrix();
    //base
    //base stand
//    glPushMatrix();
//    glTranslatef(0.5, -19.5, 0);
//    //glRotatef(-105, 0, 0, 1);
//    glScalef(6,0.5,4);
//    glTranslatef(-1.5, -1.5, -1.5);
//    drawCube1(0.545,0.271,0.075,  0.2725,0.1355,0.0375);
//    glPopMatrix();

    //translate down
    glPushMatrix();
    glTranslatef(0, -5.5, 0);

    glPushMatrix();
    glTranslatef(0, 0, -4);
    glScalef(0.2, 0.2, 0.5);
    drawCylinder(1,0,0, 0.5,0,0.5);
    glPopMatrix();

    //boat body
    glPushMatrix();
    glRotatef(pirateBoatTheta, 0, 0, 1);
    glTranslatef( 1.8,-12,0);
    boatBody();
    glPopMatrix();

    //stand on the front
    glPushMatrix();
    glTranslatef(0, 0, 1.4);
    glRotatef(pirateBoatTheta, 0, 0, 1);
    drawSphere(0, 0, 1, 0, 0, 0.5);
    //left stand
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glScalef(4,0.28,0.1);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //right stand
//    glPushMatrix();
//    glRotatef(-125, 0, 0, 1);
//    glScalef(4,0.28,0.1);
//    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
//    glPopMatrix();
    glPopMatrix();

    //stand on the back
    glPushMatrix();
    glTranslatef(0, 0, -1.6);
    glRotatef(pirateBoatTheta, 0, 0, 1);
    drawSphere(0, 0, 1, 0, 0, 0.5);
    //left stand
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glScalef(4,0.28,0.1);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //right stand
//    glPushMatrix();
//    glRotatef(-125, 0, 0, 1);
//    glScalef(4,0.28,0.1);
//    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
//    glPopMatrix();
    glPopMatrix();

    //base stand at the front
    glPushMatrix();
    glTranslatef(0, 0, 5);
    drawSphere(0, 0, 1, 0, 0, 0.5);
    //left stand
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glScalef(6,0.28,0.1);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //right stand
//    glPushMatrix();
//    glRotatef(-120, 0, 0, 1);
//    glScalef(6,0.28,0.1);
//    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.055);
//    glPopMatrix();
    glPopMatrix();

    //base stand at the back
    glPushMatrix();
    glTranslatef(0, 0, -5);
    drawSphere(0, 0, 1, 0, 0, 0.5);
    //left stand
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glScalef(6,0.28,0.1);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //right stand
//    glPushMatrix();
//    glRotatef(-120, 0, 0, 1);
//    glScalef(6,0.28,0.1);
//    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
//    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}
void Varanda()
{
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-8,19,26.8);
    glScalef(78,1,7);
    glBindTexture(GL_TEXTURE_2D,37);
    drawcube(255,255,255);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
    //extraShiri


     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-81,20.7,20.8);
    glScalef(6,1,2);
    glBindTexture(GL_TEXTURE_2D,17);
    drawcube(244,201,105);
    glPopMatrix();
     glDisable(GL_TEXTURE_2D);
}

void motel()
{
    glPushMatrix();
   // glTranslatef(0,-30,-25);
    firstFloor();
    Varanda();
    roof();
    firstFloorFence();
    groundFence();
    rain();
    platform();




    secondFloor();
    glPopMatrix();

    glPushMatrix();
    shiri();
    glRotatef(180,0,1,0);
    glTranslatef(148.8,21.7,1.3);
    shiri();
    glPopMatrix();

    //trashcan
    glPushMatrix();
    glTranslatef(21,2.6,-24.2);
    glRotatef(180,0,1,0);
    trash();
    glTranslatef(45,0,0);
    trash();
    glPopMatrix();

}
void roads(){

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    for(int i =0;i<100;i++){
        glPushMatrix();
    glTranslatef(0,.5,i*20);
    glScalef(1,.2,7);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.5,-i*20);
    glScalef(1,.2,7);
    drawcube(255,255,255);
    glPopMatrix();
    }





    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,200);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-200);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,400);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-400);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);




    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,600);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-600);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,800);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-800);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,1000);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-1000);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,1200);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-1200);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,1400);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-1400);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);




    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,1600);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-1600);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,1800);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,-1800);
    glScalef(20,.5,100);
    glBindTexture(GL_TEXTURE_2D,12);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}

void sideRoad()
{



    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-251.901+18.7, -9.6, 223.3);
    glRotatef(90,0,1,0);
    glScalef(20,.5,90);
    glBindTexture(GL_TEXTURE_2D, 11);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-163.1, -9.6,273);
//    glRotatef(90,0,1,0);
    glScalef(20,.5,30);
    glBindTexture(GL_TEXTURE_2D, 11);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-251.901+18.7, -9.6, 223.3+99.7);
    glRotatef(90,0,1,0);
    glScalef(20,.5,90);
    glBindTexture(GL_TEXTURE_2D, 11);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void roundPilar()
{

    glPushMatrix();
//    glTranslatef(ttx,tty,ttz);
    glScalef(1.5,20,1.5);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,20,0) ;
    glScalef(2.5,2,2.5);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,20,0) ;
    glScalef(3,.2,3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,21,0) ;
    glScalef(3,.2,3);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,19,0) ;
    glScalef(3,.2,3);
    drawcube(255,255,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,23,0);
    glScalef(2,4,2);
    cylinder(255,255,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,26.4,0);

    glutSolidSphere(3,100,100);
    glPopMatrix();

}

void boundaryWalls()
{
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(20,12,1);
    glBindTexture(GL_TEXTURE_2D,13);
    drawcube(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}
void pointyPilar()
{
    glPushMatrix();
//    glTranslatef(ttx,tty,ttz);
    glScalef(1.5,20,1.5);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,20,0) ;
    glScalef(2.5,2,2.5);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,20,0) ;
    glScalef(3,.2,3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,21,0) ;
    glScalef(3,.2,3);
    drawcube(255,255,255);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,19,0) ;
    glScalef(3,.2,3);
    drawcube(255,255,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,23,0);
    glScalef(2,4,2);
    cylinder(255,255,255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,24.2,0);
    glRotatef(-90,1,0,0);
    glutWireCone(3,4,4,100);
    glPopMatrix();


}
void boundaryLeft()
{

    glPushMatrix();
    glTranslatef(+20,0,0);
    glScalef(1,.8,1);
    pointyPilar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-3.3,0);
    boundaryWalls();
    glPopMatrix();


    for (int i=0; i<4; i++)
    {
        glPushMatrix();
        glTranslatef(-40*i-20,0,0);
        glScalef(1,.8,1);
        roundPilar();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-40*i-40,-3.3,0);
        boundaryWalls();
        glPopMatrix();
    }


    glPushMatrix();
    glTranslatef(-180,0,0);
    glScalef(1,.8,1);
    pointyPilar();
    glPopMatrix();


}
void boundaryLeft1()
{

    glPushMatrix();
    glTranslatef(+20,0,0);
    glScalef(1,.8,1);
    pointyPilar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-3.3,0);
    boundaryWalls();
    glPopMatrix();


    for (int i=0; i<14; i++)
    {
        glPushMatrix();
        glTranslatef(-40*i-20,0,0);
        glScalef(1,.8,1);
        roundPilar();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-40*i-40,-3.3,0);
        boundaryWalls();
        glPopMatrix();
    }


    glPushMatrix();
    glTranslatef(-580,0,0);
    glScalef(1,.8,1);
    pointyPilar();
    glPopMatrix();


}

void drawTorus(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings, GLfloat shine=90)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glutSolidTorus(innerRadius, outerRadius, nsides, rings);

    //glutSolidTorus(0.5, 10.0, 16, 12);
}
void materialProperty_car(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX=0, GLfloat ambY=0, GLfloat ambZ=0, GLfloat shine=50)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {70};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}

void car(double pri_x, double pri_y, double pri_z, double sec_x, double sec_y, double sec_z)
{
    glPushMatrix();
    glRotatef(0, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 1.0f, 0.0f);

    materialProperty_car( pri_x, pri_y, pri_z, pri_x, pri_y, pri_z);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0f,0.0f,15.0f);
    glVertex3f(40.0f,0.0f,15.0f);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40.0f,-15.0f,15.0f);
    glVertex3f(-40.0f,-15.0f,15.0f);
    glEnd();


    materialProperty_car( pri_x, pri_y, pri_z, pri_x, pri_y, pri_z);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40.0f,0.0f,-15.0f);
    glVertex3f(40.0f,0.0f,15.0f);
    glVertex3f(40.0f,-15.0f,15.0f);
    glVertex3f(40.0f,-15.0f,-15.0f);
    glEnd();

    materialProperty_car( pri_x, pri_y, pri_z, pri_x, pri_y, pri_z);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0f,0.0f,-15.0f);
    glVertex3f(-40.0f,0.0f,15.0f);
    glVertex3f(-40.0f,-15.0f,15.0f);
    glVertex3f(-40.0f,-15.0f,-15.0f);
    glEnd();

    materialProperty_car( pri_x, pri_y, pri_z, pri_x, pri_y, pri_z);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0f,0.0f,-15.0f);
    glVertex3f(40.0f,0.0f,-15.0f);
//    glColor3f(1, 1.0, 1.0);
    glVertex3f(40.0f,-15.0f,-15.0f);
    glVertex3f(-40.0f,-15.0f,-15.0f);
    glEnd();

    materialProperty_car( sec_x, sec_y, sec_z, sec_x, sec_y, sec_z);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0f,0.0f,15.0f);
    glVertex3f(-40.0f,0.0f,-15.0f);
    glVertex3f(40.0f,0.0f,-15.0f);
    glVertex3f(40.0f,0.0f,15.0f);
    glEnd();

    materialProperty_car(0, 0, 0, 0, 0, 0);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0f,-15.0f,15.0f);
    glVertex3f(-40.0f,-15.0f,-15.0f);
    glVertex3f(40.0f,-15.0f,-15.0f);
    glVertex3f(40.0f,-15.0f,15.0f);
    glEnd();

    materialProperty_car(0, 0, 0, 0, 0, 0);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0f,0.0f,15.0f);
    glVertex3f(-10.0f,10.0f,15.0f);
    glVertex3f(20.0f,10.0f,15.0f);
    glVertex3f(25.0f,0.0f,15.0f);
    glEnd();

    materialProperty_car(0, 0, 0, 0, 0, 0);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0f,0.0f,-15.0f);
    glVertex3f(-10.0f,10.0f,-15.0f);
    glVertex3f(20.0f,10.0f,-15.0f);
    glVertex3f(25.0f,0.0f,-15.0f);
    glEnd();

    materialProperty_car( pri_x, pri_y, pri_z, pri_x, pri_y, pri_z);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-10.0f,10.0f,15.0f);
    glVertex3f(-10.0f,10.0f,-15.0f);
    glVertex3f(20.0f,10.0f,-15.0f);
    glVertex3f(20.0f,10.0f,15.0f);
    glEnd();

    materialProperty_car(0, 0, 0, 0, 0, 0);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-10.0f,10.0f,15.0f);
    glVertex3f(-20.0f,0.0f,15.0f);
    glVertex3f(-20.0f,0.0f,-15.0f);
    glVertex3f(-10.0f,10.0f,-15.0f);
    glEnd();

    materialProperty_car(0, 0, 0, 0, 0, 0);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.0f,10.0f,15.0f);
    glVertex3f(20.0f,10.0f,-15.0f);
    glVertex3f(25.0f,0.0f,-15.0f);
    glVertex3f(25.0f,0.0f,15.0f);
    glEnd();

    materialProperty_car(0, 0, 0, 0, 0, 0);
    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-30.0f,-15.0f,15.0f);
    glVertex3f(-30.0f,-15.0f,-15.0f);
    glVertex3f(30.0f,-15.0f,-15.0f);
    glVertex3f(30.0f,-15.0f,15.0f);
    glEnd();


    glBegin(GL_3D);
//    glColor3f(1, 0, 0);
    glTranslated(-20.0f,-15.0f,15.0f);
    drawTorus(0, 0, 0, 0, 0, 0, 2,5,5,100);


//    glColor3f(1, 0, 0);
    glTranslated(0.0f,0.0f,-30.0f);
    drawTorus(0, 0, 0, 0, 0, 0, 2,5,5,100);
//    glColor3f(1, 0, 0);
    glTranslated(45.0f,0.0f,0.0f);
    drawTorus(0, 0, 0, 0, 0, 0, 2,5,5,100);
//    glColor3f(1, 0, 0);
    glTranslated(0.0f,0.0f,30.0f);
    drawTorus(0, 0, 0, 0, 0, 0, 2,5,5,100);
    glEnd();




    glPushMatrix();
    glColor3f(3.0,4.0,5.0);
    //glRotatef(45,0,0,1);
    glScalef(10,0.3,3);

//    glutWireCube(-20);


    glPopMatrix();


    glPopMatrix();
}

void parkingLot(){

    glPushMatrix();

    glScalef(180,.4,40);
    drawcube(143,155,154);
    glPopMatrix();

    for(int i = 0;i<6;i++){
        glPushMatrix();
        glTranslatef(i*30,.3,19.8);
        glScalef(1,.3,20);
        drawcube(255,255,255);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-i*30,.3,19.8);
        glScalef(1,.3,20);
        drawcube(255,255,255);
        glPopMatrix();
    }


    //cars in parking lot

    for(int i =0;i<3;i++){
    glPushMatrix();
    glTranslatef(-18.7+i*60, 11, 12.1);
    glRotatef(-90,0,1,0);
    glScalef(.5,.5,.5);
    car(255,0,255,0,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-18.7-i*60, 11, 12.1);
    glRotatef(-90,0,1,0);
    glScalef(.5,.5,.5);
    car(0,0,255,255,255,0);
    glPopMatrix();
    }





}



void parkingLot2(){

    glPushMatrix();

    glScalef(180,.4,40);
    drawcube(143,155,154);
    glPopMatrix();

    for(int i = 0;i<6;i++){
        glPushMatrix();
        glTranslatef(i*30,.3,19.8);
        glScalef(1,.3,20);
        drawcube(255,255,255);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-i*30,.3,19.8);
        glScalef(1,.3,20);
        drawcube(255,255,255);
        glPopMatrix();
    }


    //cars in parking lot

    for(int i =0;i<2;i++){

    glPushMatrix();
    glTranslatef(-18.7-i*60, 11, 12.1);
    glRotatef(-90,0,1,0);
    glScalef(.5,.5,.5);
    car(0,0,255,255,255,0);
    glPopMatrix();
    }





}


static GLfloat v_box[8][3] =
        {
                {0.0, 0.0, 0.0}, //0
                {3.0, 0.0, 0.0}, //1
                {0.0, 0.0, 3.0}, //2
                {3.0, 0.0, 3.0}, //3
                {0.0, 3.0, 0.0}, //4
                {3.0, 3.0, 0.0}, //5
                {0.0, 3.0, 3.0}, //6
                {3.0, 3.0, 3.0}, //7

        };
static GLubyte BoxquadIndices[6][4] =
        {
                {0,2,3,1},
                {0,2,6,4},
                {2,3,7,6},
                {1,3,7,5},
                {1,5,4,0},
                {6,7,5,4}
        };
void drawBox()
{
    materialProperty();
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        //glColor3f(colors[4][0],colors[4][1],colors[4][2]);
        getNormal3p(v_box[BoxquadIndices[i][0]][0], v_box[BoxquadIndices[i][0]][1], v_box[BoxquadIndices[i][0]][2],
                    v_box[BoxquadIndices[i][1]][0], v_box[BoxquadIndices[i][1]][1], v_box[BoxquadIndices[i][1]][2],
                    v_box[BoxquadIndices[i][2]][0], v_box[BoxquadIndices[i][2]][1], v_box[BoxquadIndices[i][2]][2]);

        glVertex3fv(&v_box[BoxquadIndices[i][0]][0]);glTexCoord2f(1,1);
        glVertex3fv(&v_box[BoxquadIndices[i][1]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_box[BoxquadIndices[i][2]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_box[BoxquadIndices[i][3]][0]);glTexCoord2f(0,1);
    }
    glEnd();
    //glutSolidSphere (3.0, 20, 16);

}
void ferrisWheelSeat()
{
    //seat
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glScalef(0.5, 0.2, 1.5);
    drawCube1(0.804, 0.361, 0.361, 0.403,0.1805,0.1805);
    glPopMatrix();

    //seat belt rod
    glPushMatrix();
    glTranslatef(1.3, 0.7, 0);
    glScalef(0.02, 0.02, 1.5);
    drawCube1(0,0,0, 0,0,0.0);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);

    //back
    glPushMatrix();
    glScalef(0.2, 0.5, 1.5);
    drawBox();
    glPopMatrix();

    //seat right side
    glPushMatrix();
    glScalef(0.5, 0.5, 0.02);
    drawBox();
    glPopMatrix();

    //seat left side
    glPushMatrix();
    glTranslatef(0, 0, 4.445);
    glScalef(0.5, 0.5, 0.02);
    drawBox();
    glPopMatrix();

    //bottom bent part
    glPushMatrix();
    glTranslatef(1.48, -0.5, 0);
    glRotatef(-45, 0, 0, 1);
    glScalef(0.15, 0.02, 1.5);
    drawBox();
    glPopMatrix();

    //bottom straight part
    glPushMatrix();
    glTranslatef(1.8, -0.8, 0);
    //glRotatef(-20, 0, 0, 1);
    glScalef(0.16, 0.02, 1.5);
    drawBox();
    glPopMatrix();

    //bottom farthest part
    glPushMatrix();
    glTranslatef(2.25, -0.8, 0);
    glScalef(0.02, 0.1, 1.5);
    drawBox();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void wheel()
{
    glPushMatrix();
    glScalef(1, 1, 2);
    drawSphere(1,0,0, 0.5,0,0);
    glPopMatrix();


    glPushMatrix();
    drawTorus(1,1,0.3, 0.5,0.5,0.15,  0.5,10.0,32,64); //0.859,0.439,0.576, 0.4295,0.2195,0.288
    glPopMatrix();


    //the big lines
    for(int i = 0; i < 180; i+=30)
    {
        glPushMatrix();
        glRotatef(i, 0,0, 1 );
        glScalef(6.6,0.1,0.5);
        glTranslatef(-1.5, -1.5, -1.5);
        drawCube1(0.867, 0.627, 0.867, 0.4335, 0.3135, 0.4335, 100);
        glPopMatrix();
    }

}

void ferrisWheel()
{
    //right stand on the back
    glPushMatrix();
    glTranslatef(-.2, 0, -1);
    glRotatef(-75, 0, 0, 1);
    glScalef(7,0.28,0.1);
    //glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.545,0.000,0.545, 0.2725,0.0,0.2725);
    glPopMatrix();

    //left stand on the back
    glPushMatrix();
    glTranslatef(-0.6, 0, -1);
    glRotatef(-105, 0, 0, 1);
    glScalef(7,0.28,0.1);
    //glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.545,0.000,0.545, 0.2725,0.0,0.2725);
    glPopMatrix();

    //right stand on the front
    glPushMatrix();
    glTranslatef(-.2, 0, 6);
    glRotatef(-75, 0, 0, 1);
    glScalef(7,0.28,0.1);
    drawCube1(0.545,0.000,0.545, 0.2725,0.0,0.2725);
    glPopMatrix();

    //left stand on the front
    glPushMatrix();
    glTranslatef(-0.6, 0, 6);
    glRotatef(-105, 0, 0, 1);
    glScalef(7,0.28,0.1);
    //glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.545,0.000,0.545, 0.2725,0.0,0.2725);
    glPopMatrix();

    //base stand
    glPushMatrix();
    glTranslatef(0, -19.5, 2.5);
    //glRotatef(-105, 0, 0, 1);
    glScalef(4,0.5,3);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.545,0.271,0.075,  0.2725,0.1355,0.0375);
    glPopMatrix();

    //fence in the front
    for(float j = -9; j <= 19; j+=2)
    {
        glPushMatrix();
        glTranslatef(j, -19.5, 11);
        glScalef(0.1,2.5,0.1);
        glTranslatef(-1.5, -1.5, -1.5);
        drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
        glPopMatrix();

//        glPushMatrix();
//        glTranslatef(j, -16.1, 11);
//        glScalef(.4, .4, .4);
//        drawSphere(0.855,0.439, 0.839, 0.4275, 0.2195, 0.4195);
//        glPopMatrix();
    }

    ///the horizontal lines of the front fence
    glPushMatrix();
    glTranslatef(4, -17, 11);
    glScalef(10,0.05,0.1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -18, 11);
    glScalef(10,0.05,0.1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -19, 11);
    glScalef(10,0.05,0.1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //gate
    glPushMatrix();
    glTranslatef(-15, -20, 11);
    glRotatef(-alpha, 0, 1, 0);
    for(float j = 0; j <= 4; j+=2)
    {
        glPushMatrix();
        glTranslatef(j, 0, 0);
        glScalef(0.1,1.5,0.1);
        drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
        glPopMatrix();

//        glPushMatrix();
//        glTranslatef(j, 4.4, 0.2);
//        glScalef(.4, .4, .4);
//        drawSphere(0.855,0.439, 0.839, 0.4275, 0.2195, 0.4195);
//        glPopMatrix();
    }

    for(float j = 1; j <=3; j+=1)
    {
        glPushMatrix();
        glTranslatef(0, j, 0);
        glScalef(1.5,0.05,0.1);
        drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
        glPopMatrix();
    }
    glPopMatrix();

    //fence in the back

    for(float j = -15; j <= 19; j+=2)
    {
        glPushMatrix();
        glTranslatef(j, -19.5, -5);
        glScalef(0.1,2.5,0.1);
        glTranslatef(-1.5, -1.5, -1.5);
        drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
        glPopMatrix();

//        glPushMatrix();
//        glTranslatef(j, -16.1, -5);
//        glScalef(.4, .4, .4);
//        drawSphere(0.855,0.439, 0.839, 0.4275, 0.2195, 0.4195);
//        glPopMatrix();
    }


    glPushMatrix();
    glTranslatef(2, -17, -5);
    glScalef(11.5,0.05,0.1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, -18, -5);
    glScalef(11.5,0.05,0.1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, -19, -5);
    glScalef(11.5,0.05,0.1);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //fence in the left
    for(float j = -3 ; j <= 9; j+=2)
    {
        glPushMatrix();
        glTranslatef(-15, -19.5, j);
        glScalef(0.1,2.5,0.1);
        glTranslatef(-1.5, -1.5, -1.5);
        drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
        glPopMatrix();

//        glPushMatrix();
//        glTranslatef(-15, -16.1, j);
//        glScalef(.4, .4, .4);
//        drawSphere(0.855,0.439, 0.839, 0.4275, 0.2195, 0.4195);
//        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(-15, -17, 3);
    glScalef(.1,0.05,5.5);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, -18, 3);
    glScalef(.1,0.05,5.5);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, -19, 3);
    glScalef(.1,0.05,5.5);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();



    //fence in the right
    for(float j = -3 ; j <= 9; j+=2)
    {
        glPushMatrix();
        glTranslatef(19, -19.5, j);
        glScalef(0.1,2.5,0.1);
        glTranslatef(-1.5, -1.5, -1.5);
        drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
        glPopMatrix();

//        glPushMatrix();
//        glTranslatef(19, -16.1, j);
//        glScalef(.4, .4, .4);
//        drawSphere(0.855,0.439, 0.839, 0.4275, 0.2195, 0.4195);
//        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(19, -17, 3);
    glScalef(.1,0.05,5.5);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19, -18, 3);
    glScalef(.1,0.05,5.5);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19, -19, 3);
    glScalef(.1,0.05,5.5);
    glTranslatef(-1.5, -1.5, -1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();


    //rotating part
    glPushMatrix();
    glRotatef(-thetaa, 0,0, 1);
    glScalef(1.5, 1.5,1);
    wheel();
    glPushMatrix();
    glTranslatef(0, 0, 5);
    wheel();
    glPopMatrix();

    //bulbs
    glPushMatrix();
    glTranslatef(0, 0, 5.5);
//    bulbsOnFerrisWheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -0.5);
//    bulbsOnFerrisWheel();
    glPopMatrix();


    //the middle line between two spheres
    glPushMatrix();
    glScalef(0.1,0.05,1.5);
    drawCube1(0.2,0.1,0.1,  0.1,0.05,0.05);
    glPopMatrix();

    //the smaller lines in between
    for(int j = 0; j <= 360; j+=30)
    {
        glPushMatrix();
        glRotatef(j, 0, 0, 1);
        for(int i = 1; i <= 7; i++)
        {
            glPushMatrix();
            glTranslatef(i, 0, 0);
            glScalef(0.1,0.05,1.5);
            drawCube1(0.780,0.082,0.522, 0.39, 0.041, 0.261);
            glPopMatrix();
        }
        glPopMatrix();
    }

    //the seats
    for(int i = 0; i <360; i+=30)
    {
        glPushMatrix();
        glRotatef(i, 0,0, 1);
        glTranslatef(10, 0, 0.9);
        glRotatef(-i, 0,0, 1);
        glRotatef(thetaa, 0,0, 1);
        glScalef(1, 1, 0.8);
        ferrisWheelSeat();
        glPopMatrix();
    }

    glPopMatrix();

    //ground
    glPushMatrix();
    glTranslatef(2, 0, 4);
    glScalef(2, 1, 1.2);
    ground2();
    glPopMatrix();

}


void circle_3D(GLdouble radius)
{
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, radius, 20, 20);
    gluDeleteQuadric(qobj);

}
void cylinder_3D(GLdouble height , GLdouble rad , GLdouble radd)
{
        GLUquadric* qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);
		glRotatef(90, 1, 0, 0);

		gluCylinder(qobj, rad, radd, height, 20, 20);
		gluDeleteQuadric(qobj);
}


void sub_tree()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 23);
    glPushMatrix();
    glTranslatef(0,40,0);
    cylinder_3D(25,1,1);//base
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 22);
    glPushMatrix();
    glTranslatef(0,40,0);
    circle_3D(10); //leaf
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void sub_tree_upper()
{
    glPushMatrix();
    glTranslatef(0,90,0);
    glRotatef(90,0,1,0);
    glScalef(2,1,2);
    sub_tree();  //1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,88,0);
    glRotatef(10,1,0,0);
    glScalef(2,1,2);
    sub_tree();  //1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,88,0);
    glRotatef(-10,1,0,0);
    glScalef(2,1,2);
    sub_tree();  //1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,90,0);
    glRotatef(10,0,0,1);
    glScalef(2,1,2);
    sub_tree();  //1
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,90,0);
    glRotatef(-10,0,0,1);
    glScalef(2,1,2);
    sub_tree();  //1
    glPopMatrix();
}
void tree()
{

//11111111111111111111111111111111111111


    glPushMatrix();
    glTranslatef(0,95,-8);
    glRotatef(55,1,0,0);
    glScalef(0.7,0.7,0.7);
    sub_tree();  //1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,95,8);
    glRotatef(-55,1,0,0);
    glScalef(0.7,0.7,0.7);
    sub_tree();  //1
    glPopMatrix();


//3333333333333333333333333

    glPushMatrix();
    sub_tree_upper();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,10,0);
    glScalef(0.8,1,0.8);
    sub_tree_upper();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,120,0);
    glBindTexture(GL_TEXTURE_2D,23);
    cylinder_3D(80,4,8);  //tree base
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}
void sphere2(GLfloat r,GLfloat g,GLfloat b,GLboolean emission=false)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);

    GLUquadric* qobj;
    qobj = gluNewQuadric();
    gluQuadricTexture(qobj,1);
    gluSphere(qobj,10,25,25);
}







void draw_all()
{
//        glPushMatrix();
        glTranslatef(288,6.5,0);
        motel();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(282,6.5,369.8);
        glRotatef(180,0,1,0);

        motel();
        glPopMatrix();




        glPushMatrix();

        glTranslatef(-150,0,194);

        glScalef(1.25,1.25,1.25);
        PetrolPump();
        //atm();
        glPopMatrix();

        glPushMatrix();
        //sky();
        Bigground();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(356,28,155);
        glScalef(1.5,1.5,1.5);
        diningSet();
        glTranslatef(0,0,17);
        diningSet();
        glTranslatef(0,0,17);
        diningSet();
        glTranslatef(0,0,17);
        diningSet();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(382,0,162);
        glScalef(2,2,2);
        glRotatef(90,0,-1,0);

        pizzaHut();

        glPushMatrix();
        glTranslatef(14,0,0);
        //glScalef(2,2,2);
        //glRotatef(90,0,1,0);
        icecreamParlor();

        glPopMatrix();
        //sun.texture = get_texture("D:\\codeblocks\\Project\\3DExample1\\textures\\hood.tga");
        //drawObj(sun.model, sun.texture, color);

        glPopMatrix();
        //dolna
        glPushMatrix();
        glTranslatef(226,20,294);
        glRotatef(90,0,1,0);
        pirateBoat();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(210,20.2,74);
        glRotatef(90,0,1,0);
        pirateBoat();
        glPopMatrix();



        glPushMatrix();

        glTranslatef(40,0.2,194);
        glRotatef(-90,0,1,0);
        draw_counter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-218,0,140);
        roads();
        glPopMatrix();

        glPushMatrix();
        glTranslatef( 84,9.4,-76);
        sideRoad();
        glPopMatrix();

        //boundary
        glPushMatrix();
        glTranslatef(-190,15.8,-84);
        glRotatef(90,0,1,0);
        boundaryLeft();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-190,15.8,316);
        glRotatef(90,0,1,0);
        boundaryLeft();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(390,15.8,-104);
        boundaryLeft1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(390,15.8,496);
        boundaryLeft1();
        glPopMatrix();

        glPushMatrix();

        glTranslatef( 410,15.8,-84);
        glRotatef(90,0,1,0);
        boundaryLeft1();
        glPopMatrix();

        //PARKING
        glPushMatrix();
        parkingLot();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,0,372);
        parkingLot2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(374,29.8,92);
        glRotatef(90,0,1,0);
        glScalef(1.5,1.5,1.5);
        ferrisWheel();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-164,-21,76);
        glScalef(.75,.5,.75);
        tree();
        glTranslatef(0,0,310);
        tree();
        glTranslatef(218,0,212);
        tree();
        glTranslatef(0,0,-720);
        tree();
        glTranslatef(498,0,4);
        tree();
        glTranslatef(0,0,696);
        tree();
        glPopMatrix();










    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(300+sunx,suny,-800);
    glScalef(4,4,4);
    glBindTexture(GL_TEXTURE_2D,t);
    sphere2(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glRotatef(nightTheta,0,0,1);
    glRotatef(skyTheta, 0,1,0);
    glRotatef(90,0,0,1);
    glScalef(100,100,100);
    glBindTexture(GL_TEXTURE_2D,t2);
    sphere2(255,255,255);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}
int state = 1;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
//    glFrustum(-10, 10, -10, 10, 4, 200);
    gluPerspective(60,1,5,200000);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, upx, upy, upz);
    glViewport(0,0, windowHeight, windowWidth);
    glScalef(scale_x, scale_y, scale_z);
    glRotatef( alpha,axis_x, axis_y, axis_z );
    glRotatef( theta,axis_x, axis_y, axis_z );
    glRotatef( beta,axis_x, axis_y, axis_z );



    glPushMatrix();

    draw_all();
    glPopMatrix();


//    glPushMatrix();
//    drawcube(50,50,50);
//    glPopMatrix();
//
//    glPushMatrix();
//    glScalef(0.1,60,0.1);
//    drawcube(50,50,50);
//    glPopMatrix();
//
//    glPushMatrix();
//    glScalef(60,0.1,0.1);
//    drawcube(50,50,50);
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glScalef(0.1,0.1,60);
//    drawcube(50,50,50);
//    glPopMatrix();

    light(300+sunx,suny,-800,GL_LIGHT0, light_0_on, true,1,1,1);
    light(0.0,30,0, GL_LIGHT1,light_1_on, false);
   // light(-19.7,18,2, GL_LIGHT2,light_2_on, false);

    glFlush();
    glutSwapBuffers();
}



void init(int d)
{
    if(d!=f)
    {
        angleYaw = 90.0;
        anglePitch = 90.0;
        angleRoll = 90.0;
        eyeX = 0;
        eyeY = 3;
        eyeZ = 80;
        lookX = 0;
        lookY = 0;
        lookZ = 50;
        upx = 0;
        upy = 1;
        upz = 0;
        f=d;
        scale_x=1;
        scale_y=1;
        scale_z=1;
    }
//     b_swap();



}


void setCameraEye_Yaw()
{

//    init(1);
//    f = 1;
//    std::cout<<"before-----------"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<lookX<<" "<<lookY<<" "<<lookZ<<" "<<upx<<" "<<upy<<" "<<upz<<std::endl;
    lookX = 50.0*(cos(anglePitch*3.1416/180.0))*(cos(angleYaw*3.1416/180.0));
    lookZ = 50.0*(cos(anglePitch*3.1416/180.0))*(sin(angleYaw*3.1416/180.0));
//    std::cout<<"after============="<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<lookX<<" "<<lookY<<" "<<lookZ<<" "<<upx<<" "<<upy<<" "<<upz<<std::endl;
//    std::cout<<angleYaw<<std::endl;
//    (cos(anglePitch*3.1416/180.0))
}

void setCameraEye_Roll()
{

    upx = (cos(angleRoll*3.1416/180.0));
    upy = (sin(angleRoll*3.1416/180.0));

}

void setCameraEye_Pitch()
{
//    init(3);
//    f=3;
//    std::cout<<"before-----------"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<lookX<<" "<<lookY<<" "<<lookZ<<" "<<upx<<" "<<upy<<" "<<upz<<std::endl;
    lookX = 50.0*(cos(anglePitch*3.1416/180.0))*(cos(angleYaw*3.1416/180.0));
    lookY = 50.0*(sin(anglePitch*3.1416/180.0));
    lookZ = 50.0*(cos(anglePitch*3.1416/180.0))*(sin(angleYaw*3.1416/180.0));
//    std::cout<<"after============="<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<lookX<<" "<<lookY<<" "<<lookZ<<" "<<upx<<" "<<upy<<" "<<upz<<std::endl;

}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

    case 'l':
        if(anglePitch<anglePitchLimit1)
        {
            anglePitch += roll_value;
            setCameraEye_Pitch();
        }


        glutPostRedisplay();

        break;
    case 'j':
        if(anglePitch>anglePitchLimit2)
        {
            anglePitch -= roll_value;
            setCameraEye_Pitch();
        }

        glutPostRedisplay();
        break;
    case 'i':
        if(angleYaw<angleYawLimit1)
        {
            angleYaw += roll_value;
            setCameraEye_Yaw();
        }

        glutPostRedisplay();

        break;
    case 'k':
        if(angleYaw>angleYawLimit2)
        {
            angleYaw -= roll_value;
            setCameraEye_Yaw();
        }

        glutPostRedisplay();
        break;
    case 'o':
        if(angleRoll<angleRollLimit1)
        {
            angleRoll += roll_value;
            setCameraEye_Roll();
        }



        glutPostRedisplay();


        break;
    case 'u':

        if(angleRoll>angleRollLimit2)
        {
            angleRoll -= roll_value;
            setCameraEye_Roll();
        }



        glutPostRedisplay();


        break;






    case 'q':
    case 'Q':
        bRotate = !bRotate;
        uRotate = false;
        tRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        axis_z=0.0;
        glutPostRedisplay();
        break;

    case 'r':
    case 'R':
        uRotate = !uRotate;
        bRotate = false;
        tRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        axis_z=0.0;
        glutPostRedisplay();
        break;

    case 't':
    case 'T':
        tRotate = !tRotate;
        uRotate = false;
        bRotate = false;
        axis_x=0.0;
        axis_y=0.0;
        axis_z=1.0;
        glutPostRedisplay();
        break;

    case '[':
        eyeY++;
        lookY++;
        glutPostRedisplay();
        break;

    case ']':
        eyeY--;
        lookY--;
        glutPostRedisplay();
        break;
    case 's':


        if(activate_roll)
        {
            if(angleRoll>angleRollLimit2)
            {
                eyeZ++;
                angleRoll -= roll_value;
                setCameraEye_Roll();
            }


        }
        if(activate_pitch)
        {
            if(anglePitch>anglePitchLimit2)
            {
                eyeZ++;
                anglePitch -= roll_value;
                setCameraEye_Pitch();
            }

        }
        if(activate_yaw)
        {
            if(angleYaw>angleYawLimit2)
            {
                eyeZ++;
                angleYaw -= roll_value;
                setCameraEye_Yaw();
            }

        }
        if(!activate_roll && !activate_pitch && !activate_yaw)
        {
            eyeZ=eyeZ + 5;
            lookZ = lookZ +5;
        }
        glutPostRedisplay();
        break;
    case 'w':


        if(activate_roll)
        {
            if(angleRoll<angleRollLimit1)
            {
                eyeZ--;
                angleRoll += roll_value;
                setCameraEye_Roll();
            }

        }
        if (activate_pitch)
        {
            if(anglePitch<anglePitchLimit1)
            {
                eyeZ--;
                anglePitch += roll_value;
                setCameraEye_Pitch();
            }
        }
        if(activate_yaw)
        {
            if(angleYaw<angleYawLimit1)
            {
                eyeZ--;
                angleYaw += roll_value;
                setCameraEye_Yaw();
            }
        }



        if(!activate_roll && !activate_pitch && !activate_yaw)
        {
            eyeZ=eyeZ-8;
            lookZ = lookZ-8;
        }
        glutPostRedisplay();
        break;

    case 'd':
        eyeX =eyeX+8;
        lookX=lookX+8;
        glutPostRedisplay();
        break;
    case 'a':
        eyeX = eyeX-8;
        lookX=lookX-8;
        glutPostRedisplay();
        break;
    case '%':
        activate_roll = !activate_roll;
        break;
    case 'z':
        skyRotate = !skyRotate;
        break;
    case '^':
        activate_pitch = !activate_pitch;
        break;
    case '&':
        activate_yaw = !activate_yaw;

    //case 'z':
    case 'Z':
        //eyez-=2;
        //init(4);
        f=4;
        scale_x+=0.05;
        scale_y+=0.05;
        scale_z+=0.05;
        glutPostRedisplay();
        break;
    case 'c':
    case 'C':
        //eyez-=2;
        //init(4);
        f=4;
        if(scale_x==0.05)break;
        scale_x-=0.05;
        scale_y-=0.05;
        scale_z-=0.05;
        glutPostRedisplay();
        break;
    //light 1 toggle
    case '1':
        light_0_on = !light_0_on;
        break;
    case '2':
        light_1_on = !light_1_on;
        break;
    case '3':
        light_2_on = !light_2_on;
        break;
    case '8':
        if (light_toggle)
        {
            amb_light_1 = !amb_light_1;
            break;
        }
        else
        {
            amb_light_0 = !amb_light_0;
            break;
        }

    //diffusion light toggle
    case '9':
        if (light_toggle)
        {
            dif_light_1 = !dif_light_1;
            break;
        }
        else
        {
            dif_light_0 = !dif_light_0;
            break;
        }
    //specular light toggle
    case '0':
        if (light_toggle)
        {
            spec_light_1 = !spec_light_1;
            break;
        }
        else
        {
            spec_light_0 = !spec_light_0;
            break;
        }
    case '5':
        amb_light_2 = !amb_light_2;
        break;
    //diffusion light toggle
    case '6':
        dif_light_2 = !dif_light_2;
        break;
    //specular light toggle
    case '7':
        spec_light_2 = !spec_light_2;
        break;

    case '.':
        light_toggle = !light_toggle;
        break;



    case '4':
        fan_Rotate = !fan_Rotate;
        break;
    case ';':
        nag_Rotate = !nag_Rotate;
        PlaySound(TEXT("D:\\codeblocks\\Project\\melay.wav"), NULL, SND_FILENAME | SND_ASYNC  );
        break;
    case 'n':
        doorOpen = true;
        doorClose = false;
        break;
    case 'N':
        doorOpen = false;
        doorClose = true;
        break;
    case 'v':
        tty -= 2;
        break;
    case 'b':
        tty += 2;
        break;
    case 'h':
        dRotate1 = !dRotate1;
        dRotate2 =false;
        break;

    case 'H':
        dRotate2 = !dRotate2;
        dRotate1 =false;
        break;
        break;

    case '=': //pirate boat
        if(pirateBoatFlag == false)
            {
            pirateBoatFlag = true;
            break;
            }
        else if( pirateBoatFlag == true)
            {
            pirateBoatFlag = false;
            break;
            }

        break;


    case 'F':
        doorOpen = true;
        doorClose = false;
        break;
    case 'f':
        doorOpen = false;
        doorClose = true;
        break;

    case 'm':
        dRotate1 = !dRotate1;
        dRotate2 = false;
        break;
    case 'M':
        dRotate2 = !dRotate2;
        dRotate1 = false;
        break;
    case 'g':
        lidOpen = true;
        lidClose = false;
        break;
    case 'G':
        lidOpen = false;
        lidClose = true;
        break;
    case '-':
        fan_Rotate = !fan_Rotate;
        break;
    case 27:	// Escape key
        exit(1);
    }
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        ttz -= 2;
        break;
    case GLUT_KEY_DOWN:
//do something here
        ttz += 2;
        break;
    case GLUT_KEY_LEFT:
//do something here
        ttx -= 2;
        break;
    case GLUT_KEY_RIGHT:
//do something here
        ttx += 2;
        break;
    }


    std::cout<<"Starting Point "<<ttx<<","<<tty<<","<<ttz<<" \n";

    glutPostRedisplay();
}


void animate()
{
    if (bRotate == true)
    {
        theta += 1;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);

    }
    if (nag_Rotate == true)
    {
        thetaa += 1;
        if(thetaa > 360.0)
            thetaa -= 360.0*floor(thetaa/360.0);

    }

    if (fan_Rotate == true)
    {
        theta_fan_rotate += 2.0;
        if(theta_fan_rotate >= 360) theta_fan_rotate = 0.0;
    }

    if(doorOpen == true)
    {
        if(doorDistz>-.7) doorDistz-=.05;

        if(doorDistz<-.69)
        {

            if(doorDistx1>-8.2) doorDistx1-=.05;

            if(doorDistx2<8.2) doorDistx2+=.05;
        }
    }

    if(doorClose == true)
    {


        if(doorDistx1<0) doorDistx1+=.05;

        if(doorDistx2>0) doorDistx2-=.05;
        if(doorDistx1>-.01)
        {
            if(doorDistz<0) doorDistz+=.05;
        }

    }
    if(lidOpen == true){
        if(lidTheta>-90){
            lidTheta-=1.0;
        }
    }
    if(lidClose == true){
        if(lidTheta<0){
            lidTheta+=1.0;
        }
    }




    if (uRotate == true)
    {
        alpha += 1;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);

    }

    if (tRotate == true)
    {
        beta += 1;
        if(beta > 360.0)
            beta -= 360.0*floor(beta/360.0);

    }

    if (fan_Rotate == true)
    {
        theta_fan_rotate += 5.0;
        if(theta_fan_rotate >= 360) theta_fan_rotate = 0.0;
    }

    if(tap_open == true)
    {
        tap_dis1 -= .01;
        tap_dis2-=.01;
        if(tap_dis1<=4) tap_dis1=4.5;
        if(tap_dis2<=4) tap_dis2=4.5;
    }
    if(dRotate1 == true)
    {

            if(door_theta>-120)
            {
                door_theta-=0.5;

            }

    }
    if(dRotate2==true){
        if(door_theta<0){
            door_theta+=0.5;
        }
    }


    if(pirateBoatFlag == true)
    {
        if(pirateBoatCheck == true)
        {
            pirateBoatTheta += 2;
            if(pirateBoatTheta == 60)
            {
                pirateBoatCheck = false;
            }
        }
        else
        {
            pirateBoatTheta -= 2;
            if(pirateBoatTheta == -70)
            {
                pirateBoatCheck = true;
            }
        }
    }
    else
    {
        if(pirateBoatTheta < 0)
        {
            pirateBoatTheta += 1;
            if(pirateBoatTheta == 0)
            {
                pirateBoatTheta = 0;
            }
        }
        else if(pirateBoatTheta > 0)
        {
            pirateBoatTheta -= 1;
            if(pirateBoatTheta == 0)
            {
                pirateBoatTheta = 0;
            }
        }
    }



    if(skyRotate == true)
    {

        if(night==false)
        {
            if(sunx>-500)
            {
                if(suny<500)
                {
                    sunx--;
                    suny++;
                }
            }
            else if(suny>0)
            {
                sunx--;
                if(sunx==-750) t2=46;
                suny--;
            }
            if(suny==0)
            {
                night = true;
                t = 43;
                t2 = 45;
                sunx=0;
                suny=0;
            }
//
        }
        if(night==true){
             if(sunx>-500)
            {
                if(suny<500)
                {
                    sunx--;
                    suny++;
                }
            }
            else if(suny>0)
            {
                sunx--;
                suny--;
            }
            if(suny==0)
            {
                night = false;
                t = 42;
                t2 = 44;
                sunx=0;
                suny=0;
            }
        }

        if(skyTheta<360)
        {
            skyTheta++;
        }
        else
        {
            skyTheta=0.0;
        }
    }

    glutPostRedisplay();

}


int main (int argc, char **argv)
{
   // glPushMatrix();

    //sun.model = load_obj("D:\\codeblocks\\Project\\3DExample1\\objects\\car1.obj");
    //sun.position.x = 10;
    //sun.position.y = 10;
   // sun.position.z = 10;
   // glPopMatrix();


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("kitchen");

    std::cout << glGetString(GL_RENDERER) << std::endl;

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    LoadTexture("D:\\codeblocks\\Project\\red-metal.bmp"); // 5         1
    LoadTexture("D:\\codeblocks\\Project\\blackred.bmp"); // 16         2
    LoadTexture("D:\\codeblocks\\Project\\pinkblue.bmp"); // 17         3
    LoadTexture("D:\\codeblocks\\Project\\baskin-robin-ad.bmp"); // 17  4

    LoadTexture("D:\\codeblocks\\Project\\menu.bmp");//15    5
    LoadTexture("D:\\codeblocks\\Project\\backpizza1.bmp");//22         6
    LoadTexture("D:\\codeblocks\\Project\\sidepizza.bmp");//4     7
    LoadTexture("D:\\codeblocks\\Project\\offer1.bmp");//6     8
    LoadTexture("D:\\codeblocks\\Project\\pizzawood.bmp");   //9
    LoadTexture("D:\\codeblocks\\Project\\piz.bmp");       //10
    LoadTexture("D:\\codeblocks\\Project\\road.bmp");       //11
    LoadTexture("D:\\codeblocks\\Project\\road2.bmp");       //12
    LoadTexture("D:\\codeblocks\\Project\\wall1.bmp");       //13
    LoadTexture("D:\\codeblocks\\Project\\pp_hood.bmp");       //14
    LoadTexture("D:\\codeblocks\\Project\\brick.bmp");       //15
    LoadTexture("D:\\codeblocks\\Project\\steel.bmp");       //16
    LoadTexture("D:\\codeblocks\\Project\\steel1.bmp");       //17
    LoadTexture("D:\\codeblocks\\Project\\gas.bmp");       //18
    LoadTexture("D:\\codeblocks\\Project\\premium.bmp");       //19
    LoadTexture("D:\\codeblocks\\Project\\amount.bmp");       //20
    LoadTexture("D:\\codeblocks\\Project\\red.bmp");       //21
    LoadTexture("D:\\codeblocks\\Project\\leaf2.bmp");       //22
    LoadTexture("D:\\codeblocks\\Project\\tree_base2.bmp");       //23
    LoadTexture("D:\\codeblocks\\Project\\door.bmp");       //24
    LoadTexture("D:\\codeblocks\\Project\\bwall.bmp");       //25
    LoadTexture("D:\\codeblocks\\Project\\platform.bmp");       //26
    LoadTexture("D:\\codeblocks\\Project\\pstair.bmp");       //27
    LoadTexture("D:\\codeblocks\\Project\\Nwindow.bmp");       //28
    LoadTexture("D:\\codeblocks\\Project\\mdoorl.bmp");       //29
    LoadTexture("D:\\codeblocks\\Project\\mdoorr.bmp");       //30
    LoadTexture("D:\\codeblocks\\Project\\cfloor.bmp");       //31
    LoadTexture("D:\\codeblocks\\Project\\cwall.bmp");       //32
    LoadTexture("D:\\codeblocks\\Project\\clock.bmp");       //33
    LoadTexture("D:\\codeblocks\\Project\\keyholder.bmp");       //34
    LoadTexture("D:\\codeblocks\\Project\\keyholder.bmp");       //35
    LoadTexture("D:\\codeblocks\\Project\\cmenu.bmp");       //36
    LoadTexture("D:\\codeblocks\\Project\\varanda.bmp");       //37
    LoadTexture("D:\\codeblocks\\Project\\motel.bmp");       //38
    LoadTexture("D:\\codeblocks\\Project\\grass.bmp");       //39
    LoadTexture("D:\\codeblocks\\Project\\bed.bmp");       //40
    LoadTexture("D:\\codeblocks\\Project\\mat.bmp");       //41
    LoadTexture("D:\\codeblocks\\Project\\sun.bmp");       //42
    LoadTexture("D:\\codeblocks\\Project\\moon.bmp");       //43
        LoadTexture("D:\\codeblocks\\Project\\sky1.bmp");       //44
            LoadTexture("D:\\codeblocks\\Project\\nightsky.bmp");       //45
                LoadTexture("D:\\codeblocks\\Project\\eveningsky.bmp");       //46


    //    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/red-metal.sgi",5);
    //    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/blackred.sgi", 16);
//    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/pinkblue.sgi", 17);
//    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/baskin-robin-ad.sgi", 18);


//    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/grass.sgi", 15);
//    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/dd.sgi", 22);
//    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/pirate-copy.sgi",4);
//    LoadTexture2("/home/towsif/CLionProjects/gl_project_s/sgi_images/baskinrobbinslogo.sgi",6);



    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}

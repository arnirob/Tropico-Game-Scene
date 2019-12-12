#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;


#include<GL/gl.h>
#include <GL/glut.h>

//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

float rtX=0,rtY=0,clx=0;

//Called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _moveC1 = -8;
float _moveC2 = -14.0;
float _moveC3= 8.0;
float _zoomX = 0;
float _zoomY = -0.0;
int isOn = 0;
float _zoomZ = -10.0;


void khamba()
{
    /* Sada khamba */
    glPushMatrix();
    glPushMatrix();
    glColor3f((140/255.0),(71/255.0),(52/255.0));
    glScalef(0.8,12,0.8);
    glutSolidCube(0.1);
    glPopMatrix();

    /* Khambar matha */
    glPushMatrix();
    glColor3f((112/255.0),(59/255.0),(48/255.0));
    glTranslatef(0, 0.55, 0);
    glScalef(1.2,1,1.2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPopMatrix();

}

void choto_sobuj_khamba(){
    glPushMatrix();
    glColor3f((161/255.0),(85/255.0),(55/255.0));
    glScalef(0.3,5,0.3);
    glutSolidCube(0.1);
    glPopMatrix();


}

void choto_sobuj_khamba_koushol(){
    for( float x=0.0; x<=1; x += 0.1 ) {
        glPushMatrix();
        glTranslatef(x, -0.4, 0.0);
        choto_sobuj_khamba();
        glPopMatrix();
    }
}

void khamba_helper( float barX, float barY, float barZ ){
    glPushMatrix();
    glTranslatef( barX, barY, barZ );
    choto_sobuj_khamba_koushol();
    glPopMatrix();

}

void khambar_uporer_bar(){
// baranda bar
    glPushMatrix();
    glColor3f((89/255.0),(71/255.0),(52/255.0));
    glTranslatef(-0.5,-0.15,0);
    glScalef(30,0.7,0.7);
    glutSolidCube(0.1);

    glPopMatrix();
}

void khamba_koushol(){
    glPushMatrix();
    glTranslatef(-2,0,0);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    khamba_helper(-2,0,0);

    glPushMatrix();
    glTranslatef(-1,0,0);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    khamba_helper(-1,0,0);

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    khamba_helper(0,0,0);

    glPushMatrix();
    glTranslatef(1,0,0);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(2,0,-1);
    glPushMatrix();
    khamba_helper(-2,0,-1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,0,-1);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(3,0,-1);
    glPushMatrix();
    khamba_helper(-2,0,-1);
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-2,0,-2);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,0,-3);
    glScalef(1.1,1.1,1.1);
    khamba();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(5,0,-1);
    glPushMatrix();
    khamba_helper(-2,0,-1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,0,-4);
    glScalef(1.1,1.1,1.1);
    khamba(); // prothom khamba
    glPopMatrix();

    khamba_helper(-2,0,-4);


    glPushMatrix();
    glTranslatef(-1,0,-4);
    glScalef(1.1,1.1,1.1);
    khamba(); // prothom khamba
    glPopMatrix();

    khamba_helper(-1,0,-4);


    glPushMatrix();
    glTranslatef(0,0,-4);
    glScalef(1.1,1.1,1.1);
    khamba(); // prothom khamba
    glPopMatrix();

    khamba_helper(0,0,-4);

    glPushMatrix();
    glTranslatef(1,0,-4);
    glScalef(1.1,1.1,1.1);
    khamba(); // prothom khamba
    glPopMatrix();

    glPushMatrix();
    khambar_uporer_bar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.48,0);
    khambar_uporer_bar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-4);
    khambar_uporer_bar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.48,-4);
    khambar_uporer_bar();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(2,0,-1);
    glScalef(0.7,1,1);
    glPushMatrix();
    glTranslatef(-0.9,0,-1);
    khambar_uporer_bar();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(2,-0.48,-1);
    glScalef(0.7,1,1);
    glPushMatrix();
    glTranslatef(-0.9,0,-1);
    khambar_uporer_bar();
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(2,0,-1);
    glScalef(0.35,1,1);
    glPushMatrix();
    glTranslatef(4.6,0,-1);
    khambar_uporer_bar();
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(2,-0.48,-1);
    glScalef(0.35,1,1);
    glPushMatrix();
    glTranslatef(4.6,0,-1);
    khambar_uporer_bar();
    glPopMatrix();
    glPopMatrix();

}

void halaSiri(){
    glPushMatrix();
    glColor3f(0.38,0.231,0.231);
    glScalef(3,0.2,3);
    glutSolidCube(0.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.521,0.368,0.258);
    glScalef(3,0.2,2);
    glTranslatef(0,0.22,0);
    glutSolidCube(0.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.705,0.415,0.415);
    glScalef(3,0.2,1);
    glTranslatef(0,0.44,0);
    glutSolidCube(0.2);
    glPopMatrix();
}

void window(){
    glPushMatrix();
    glPushMatrix();
    glPushMatrix();
    glColor3f(68/255.0,49/255.0,51/255.0);
    glBegin(GL_QUADS);
    glVertex3f(-.3,-.3,0);
    glVertex3f(.3,-.3,0);
    glVertex3f(.3,.5,0);
    glVertex3f(-.3,.5,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();



    glPushMatrix();
    glTranslatef(0,0.34,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(-.25,-.1,.01);
    glVertex3f(-.02,-.1,.01);
    glVertex3f(-0.02,.1,.01);
    glVertex3f(-.25,.1,.01);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(.02,-.1,.01);
    glVertex3f(.25,-.1,.01);
    glVertex3f(.25,.1,.01);
    glVertex3f(.02,.1,.01);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.1,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(-.25,-.1,.01);
    glVertex3f(-.02,-.1,.01);
    glVertex3f(-0.02,.1,.01);
    glVertex3f(-.25,.1,.01);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(.02,-.1,.01);
    glVertex3f(.25,-.1,.01);
    glVertex3f(.25,.1,.01);
    glVertex3f(.02,.1,.01);
    glEnd();



    glPushMatrix();
    glTranslatef(0,-0.24,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(-.25,-.1,.01);
    glVertex3f(-.02,-.1,.01);
    glVertex3f(-0.02,.1,.01);
    glVertex3f(-.25,.1,.01);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(.02,-.1,.01);
    glVertex3f(.25,-.1,.01);
    glVertex3f(.25,.1,.01);
    glVertex3f(.02,.1,.01);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void doroja(){

    glPushMatrix();
    glColor3f((139/255.0),(69/255.0),(19/255.0));
    glScalef(1.5,3,0.2);
    glutSolidCube(1);

    glPushMatrix();
    glColor3f((160/255.0),(82/255.0),(45/255.0));
    glScalef(0.5,1,0.2);
    glTranslatef(-0.5,0,2.6);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,0,0.1);
    glColor3f(1,(218/255.0),(185/255.0));
    glutSolidSphere(.1,100,100);
    glPopMatrix();


}

void basha(){
    glPushMatrix();
    glColor3f(152/255.0,100/255.0,60/255.0);
    glScalef(2,1,1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glColor3f(90/255.0,61/255.0,48/255.0);
    glScalef(1.4,1,1);
    glRotatef(45,0,0,1);
    glTranslatef(0.35,.35,0);
    glutSolidCube(0.9999);
    glPopMatrix();
}

void pura_ghor(){
     /// window

    glPushMatrix();
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(1.2,0,2.0001);
    window();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(-1.2,0,2.0001);
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,01,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(0,0,0.51);
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,01,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(1.8,0,0.51);
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,01,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(-1.8,0,0.51);
    window();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,01,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(-1.6,0,1.0001);
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(1.6,0,1.0001);
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(0.0,0,1.801);
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,01,0);
    glColor3f(0.1,.9,0.1);
    glScalef(0.6,0.6,1);
    glTranslatef(0.0,0,1.8001);
    window();
    glPopMatrix();




    /// Doroja

    glPushMatrix();
    glScalef(0.5,0.33,0.5);
    glTranslatef(0,0,3.99);
    doroja();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.33,0.5);
    glTranslatef(3.4,0,1);
    doroja();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.33,0.5);
    glTranslatef(-3.4,0,1);
    doroja();
    glPopMatrix();


    /// ordhek ghor
    glPushMatrix();
    glScalef(1.8,1,1);
    basha();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,1,2);
    glTranslatef(0,0,0.5);
    basha();
    glPopMatrix();


}

void light(){
        glPushMatrix();
        glColor3f(.5,.5,.5);
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(.1,0,0);
        glVertex3f(.1,1.5,0);
        glVertex3f(0,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(.1,0,0);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,1.5,-.1);
        glVertex3f(.1,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,-.1);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,1.5,-.1);
        glVertex3f(0,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-.1);
        glVertex3f(0,1.5,-.1);
        glVertex3f(0,1.5,0);
        glEnd();

        glPopMatrix();
        glPushMatrix();
        glColor3f(.5,.5,.5);
        glBegin(GL_POLYGON);
        glVertex3f(0,1.5,0);
        glVertex3f(1,1.5,0);
        glVertex3f(1,1.6,0);
        glVertex3f(0,1.6,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex3f(0,1.5,-0.1);
        glVertex3f(1,1.5,-0.1);
        glVertex3f(1,1.6,-0.1);
        glVertex3f(0,1.6,-0.1);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex3f(0,1.6,0);
        glVertex3f(1,1.6,0);
        glVertex3f(1,1.6,-0.1);
        glVertex3f(0,1.6,-0.1);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glColor4f(1,1,0,.5);
        glRotatef(-90,1,0,0);
        glTranslatef(.95,0.05,0.05);
        if(isOn)
            glutSolidCone(.6,1.5,10,10);
        glPopMatrix();
}

void tree(){
        glPushMatrix();
        glColor3f(.8,.3,0);
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(.1,0,0);
        glVertex3f(.1,.4,0);
        glVertex3f(0,.4,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(.1,0,0);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,.4,-.1);
        glVertex3f(.1,.4,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,-.1);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,.4,-.1);
        glVertex3f(0,.4,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-.1);
        glVertex3f(0,.4,-.1);
        glVertex3f(0,.4,0);
        glEnd();
        glPushMatrix();
        glTranslatef(0.05,.35,-.05);
        glColor3f(0,.8,0);
        glRotatef(90,-1,0,0);
        glutSolidCone(.18,.5,10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.05,.50,-.05);
        glColor3f(0,1,0);
        glRotatef(90,-1,0,0);
        glutSolidCone(.2,.5,10,10);
        glPopMatrix();
    glPopMatrix();
}

void baganergastas(){
    glPushMatrix();
    glPushMatrix();
    glScalef(.8,.8,.8);
    glTranslatef(3.5,-0.63,.5);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.6,.8,.6);
    glTranslatef(4.2,-0.63,.5);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(10.7,-0.76,.9);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(8.7,-0.76,.9);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(9.7,-0.76,.4);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(11.7,-0.76,.4);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(9.7,-0.76,.5);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(9.7,-0.76,1.5);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(9.7,-0.76,2.8);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(8.7,-0.76,-2.8);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(7.7,-0.76,-2.4);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(7.1,-0.76,2.4);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(6.4,-0.76,2.4);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(6.4,-0.76,2.4);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(6.8,-0.76,-2.6);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(6.8,-0.76,-1.9);
    tree();
    glPopMatrix();


    ///

     glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(7.1,-0.76,-1.4);
    tree();
    glPopMatrix();

     glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(7.3,-0.76,-1.6);
    tree();
    glPopMatrix();


     glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(8.2,-0.76,-1.8);
    tree();
    glPopMatrix();

     glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(7.71,-0.76,-1.9);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(.4,.6,.4);
    glTranslatef(7.1,-0.76,-1.4);
    tree();
    glPopMatrix();

    glPopMatrix();


}

void baganerChotoBera(){
    // Boro beragula
    glPushMatrix();
    glColor3f(.66,.66,.66);
    glScalef(2.4,0.1,0.04);
    glTranslatef(1.36,0,33);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glColor3f(.66,.66,.06);
    glScalef(2.4,0.1,0.04);
    glTranslatef(1.46,-3,33);
    glutSolidCube(1);
    glPopMatrix();


    // Choto beragula
    glPushMatrix();
    glPushMatrix();
    glColor3f(.33,.33,.33);
    glScaled(0.2,0.6,0.04);
    glTranslatef(12.6,-0.4,33);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.33,.33,.33);
    glScaled(0.2,0.6,0.04);
    glTranslatef(18.6,-0.4,33);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();


}

void bagan(){
    glPushMatrix();
        glColor3f((111/255.0),(206/255.0),(112/255.0));
        glScalef(2.7,0.01,3.2);
        glTranslatef(1.3,-50.2, -0.1);
        glutSolidCube(1);
        glPopMatrix();


        /// Baganer gas
        baganergastas();

        /// Baganer bera



        /// Baganer Choto bera
        glPushMatrix();
        baganerChotoBera();
        glPopMatrix();

        glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(-3.1,0,0.8);
        baganerChotoBera();
        glPopMatrix();


        glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(-3.1,0,3.5);
        baganerChotoBera();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(.2,0,-3.2);
        baganerChotoBera();
        glPopMatrix();

}

void chad(){
    /// dan pasher barti chad
    glPushMatrix();
    glColor3f((143/255.0),(111/255.0),(90/255.0));
    glScalef(1.222,0.03,3.00);
    glTranslatef(0.97,17.1,0.05);
    glutSolidCube(1);
    glPopMatrix();


    /// bam pasher barti chad
    glPushMatrix();
    glColor3f((143/255.0),(111/255.0),(90/255.0));
    glScalef(1.2,0.03,3);
    glTranslatef(-1,17.1,0.1);
    glutSolidCube(1);
    glPopMatrix();

     /// shamner barti chad
    glPushMatrix();
    glColor3f((143/255.0),(111/255.0),(90/255.0));
    glRotatef(90,0,1,0);
    glScalef(1.4,0.03,3);
    glTranslatef(-0.788,17.1,0.1);
    glutSolidCube(1);
    glPopMatrix();

}

void megh(){

    if( _moveC1 == 10 ) _moveC1 = -8;
    else _moveC1 += 0.18;
    glutPostRedisplay();

    glPushMatrix();//cloud_1
    glTranslatef(_moveC1, 1, -20.0);
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-24.4,9.5,0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-24.3,7.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-22.0,9.5,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.35,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-26,8.5,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-22.9,7.8,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
    glPopMatrix();


    if( _moveC2 == 10 ) _moveC2 = -10;
    else _moveC2 += 0.15;
    glutPostRedisplay();


    glPushMatrix();//cloud_1
    glTranslatef(_moveC2,1,-20.0);
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-24.4,9.5,0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-24.3,7.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-22.0,9.5,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.35,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-26,8.5,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-22.9,7.8,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
    glPopMatrix();


}


void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    //glRotatef(rtX, 0.0, 0.0, 0.0); //Rotate the camera
    glTranslatef(_zoomX, _zoomY, _zoomZ);//Move forward 5 units

//    rtY += .6;
//    if(rtY >= 360)
//        rtY = 0.0;
//    glutPostRedisplay();

    glPushMatrix();
    glRotatef(rtX,1,0,0);
    glRotatef(rtY,0,1,0);

    /// khamba
    glPushMatrix();
    glRotatef(90,0,1,0);
    glScalef(.89,.688,.866);
    glTranslatef(0.18,0.07,2.02);
    khamba_koushol();
    glPopMatrix();



    /// choto khamba optional
//    glPushMatrix();
//    glTranslatef(0.41,0,1.35);
//    choto_sobuj_khamba_koushol();
//    glPopMatrix();

   ///Siri
    glPushMatrix();
    //glScalef(1,1,1);
    glTranslatef(-.4,-0.49,1.65);
    halaSiri();
    glPopMatrix();

    /// Pura ghor
    glPushMatrix();
    glTranslatef(0,0,-1.511);
    pura_ghor();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(7,0,-1.511);
    pura_ghor();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(8,0,4);
    pura_ghor();
    glPopMatrix();


    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(8,0,-6);
    pura_ghor();
    glPopMatrix();


    glPushMatrix();
    glRotatef(180,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(8,0,-15);
    pura_ghor();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(4,0,-15);
    pura_ghor();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(4,0,15);
    pura_ghor();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(-10,0,15);
    pura_ghor();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(-10,0,-11);
    pura_ghor();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(-13,0,-2);
    pura_ghor();
    glPopMatrix();


    glPushMatrix();
    //glRotatef(180,0,1,0);
    glScalef(.7,.7,.7);
    glTranslatef(-2,0,-9);
    pura_ghor();
    glPopMatrix();


    glPushMatrix();
    glRotatef(180,0,1,0);
    glScalef(.8,.8,.8);
    glTranslatef(-1,0,-12);
    pura_ghor();
    glPopMatrix();


    /// floor
    glPushMatrix();
    glColor3f((210/255.0),(180/255.0),(140/255.0));
    glScalef(3.9,.11,4);
    glTranslatef(0,-4.11,-0.071);
    glutSolidCube(1);
    glPopMatrix();


    /// chad
    glPushMatrix();
    chad();
    glPopMatrix();


    /// Light jalaisi

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,1.8);
    light();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,-1.8);
    light();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,-4.6);
    light();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,-8.6);
    light();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,-12.6);
    light();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,5.8);
    light();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(1.8,-0.60,9.8);
    light();
    glPopMatrix();

    /// Rasta
    glPushMatrix();
    glColor4f(.2,.2,.2,.9);
//    glColor3f(.99,.99,0.99);
    glScalef(30,.02,1.5);
    glTranslatef(0,-26,1.8);
    glutSolidCube(1);
    glPopMatrix();


    /// Bagan

    glPushMatrix();
    bagan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,0);
    bagan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,0,8);
    bagan();
    glPopMatrix();


    /// Floor bishal
    glPushMatrix();
    glColor3f(129/255.0,221/255.0,115/255.0);
    glScalef(30,.01,30);
    glTranslatef(0,-53,0.1);
    glutSolidCube(1);
    glPopMatrix();


    /// meghs
    glPushMatrix();
    megh();
    glPopMatrix();



    /// ENDING
    glPopMatrix();
    glutSwapBuffers();// exchange for glFlash()

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'o':
        if(isOn == 0)
            isOn = 1;
        else
            isOn = 0;
        glutPostRedisplay();
        break;
    case '+':
        _zoomX += .1;
        _zoomY += .1;
        _zoomZ += .1;
        break;
    case '-':
        _zoomX -= .1;
        _zoomY -= .1;
        _zoomZ -= .1;
        break;
    default:
        break;
    }

}


void specialKey(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_DOWN:
        rtX -= 1;
        if(rtX <= 0)
            rtX = 360.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
         rtX += 1;
        if(rtX>=360)
            rtX = 0.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        if( rtY >= 360 ) rtY = 0.0; // come to center point again
        rtY += 1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        if(rtY <= 0) rtY = 360.0; // come to center point again
        rtY -= 1;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void init(void)
{
    //glColor4f(1,1,0,.5);
    glClearColor(173/255.0,245/255.0,255/255.0,0.2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);

    gluOrtho2D(0.0,1500,0.0,800);
}

int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1500, 800);
    glutInitWindowPosition(100, 100);

    //Create the window
    glutCreateWindow("Baler Project");
    initRendering();
    init();

    //Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutTimerFunc(30, 0, 0); //Add a timer

    glutMainLoop();
    return 0;
}

#include<cstring>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
GLfloat a=0,b=0,c=0,a2=0,crash1x=0,crash1y=0,smoke1x=0,p=0,smoke2x=0,crash2x=0,by=0,ty=0,bs=1,bsoutx=0;
void update(int value)
{
  a+=20.0; //scene 1 plane
  b-=10.0; //scene 1 road strips
  c+=15; // timer
  if(b<=-78.0)// moving of run way
     b=0.0;
  if(c>360) a2+=20;//scene 2 plane
  if(c>800 && crash1x<200) crash1x+=20;//scene 2 till the crash
  if(c>1200&& p<50) p+=5;//scene 4 people
  if(c>1700 && crash2x>-160) crash2x-=10;// scene 5 crash
  if(c<3120) //end of animation
  {
    if(c>2600 && ty>-200) ty-=5;//scene 6 tower going down
    if(c>2600 && bs<1.5) by-=7.5*bs; // scene 6 outer y
    if(c>2600&& bs<1.5)  bs+=0.01;// scaling of outer explosion
    if(c>2600 &&bs<1.5) bsoutx-=3*bs;//scene 6 outer x
  }

  glutPostRedisplay();
  glutTimerFunc(120,update,0);//delay
}
void welcomeDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0,1,2);

    glVertex2f(0,0);
    glColor3f(0,0,1);
    glVertex2f(0,499);
    glColor3f(0,1,2);
    glVertex2f(499,499);
    glColor3f(0,0,1);
    glVertex2f(499,0);
    glEnd();
    glColor3f(.0,0.0,0.0);

    glRasterPos2f(230,350);
    char msg1[]="9/11 Attack";
    for(int i=0;i<strlen(msg1);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);

    glBegin(GL_QUADS);   //left wing
    glColor3f(.4,.4,.4);
    glVertex2f(60,395);
    glVertex2f(70,395);
    glVertex2f(80,377);
    glVertex2f(70,377);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);//body
    glVertex2f(30,360);
    glVertex2f(40,385);
    glVertex2f(110,385);
    glVertex2f(110,360);
    glEnd();
    glBegin(GL_TRIANGLES);//tail
    glColor3f(.4,.4,.4);
    glVertex2f(35,373);
    glVertex2f(20,410);
    glVertex2f(30,360);
    glColor3f(1,1,1);
    glVertex2f(35,373);
    glVertex2f(20,410);
    glVertex2f(40,385);
    glEnd();
    glBegin(GL_QUADS);   //right wing
    glColor3f(.4,.4,.4);
    glVertex2f(60,350);
    glVertex2f(70,350);
    glVertex2f(80,368);
    glVertex2f(70,368);
    glEnd();

    glBegin(GL_TRIANGLES);//nose
    glColor3f(.4,.4,.4);
    glVertex2f(110,385);
    glVertex2f(110,372);
    glVertex2f(125,372);
    glColor3f(1,1,1);
    glVertex2f(110,372);
    glVertex2f(125,372);
    glVertex2f(110,360);
    glEnd();
    glBegin(GL_POINTS);
    glPointSize(0.5);
    glColor3f(0,0,0);
    glVertex2f(44,372);
    glVertex2f(54,372);
    glVertex2f(64,372);
    glVertex2f(84,372);
    glVertex2f(94,372);
    glVertex2f(104,372);
    glEnd();

     glBegin(GL_QUADS);   //left wing
    glColor3f(0,0,0.8);
    glVertex2f(460,392);
    glVertex2f(470,392);
    glVertex2f(460,377);
    glVertex2f(450,377);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);//body
    glVertex2f(430,360);
    glVertex2f(430,382);
    glVertex2f(490,382);
    glVertex2f(480,360);
    glEnd();
    glBegin(GL_TRIANGLES);//tail
    glColor3f(0,0,0.8);
    glVertex2f(480,360);
    glVertex2f(495,400);
    glVertex2f(495,360);

    glEnd();
    glBegin(GL_QUADS);   //right wing
    glColor3f(0,0,0.8);
    glVertex2f(460,345);
    glVertex2f(470,345);
    glVertex2f(460,360);
    glVertex2f(450,360);
    glEnd();

    glBegin(GL_TRIANGLES);//nose
    glColor3f(0,0,0.8);
    glVertex2f(430,382);
    glVertex2f(430,371);
    glVertex2f(415,371);
    glColor3f(1,1,1);
    glVertex2f(430,360);
    glVertex2f(430,371);
    glVertex2f(415,371);
    glEnd();
    glBegin(GL_POINTS);
    glPointSize(5);
    glColor3f(0,0,0.5);
    glVertex2f(435,372);
    glVertex2f(445,372);
    glVertex2f(455,372);
    glVertex2f(465,372);
    glVertex2f(475,372);
    glEnd();

      glColor3f(0,0,0);
    glRasterPos2f(170,480);
    char msg6[]="ST. JOSEPH'S ENGINEERING COLLEGE";
    for(int i=0;i<strlen(msg6);i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg6[i]);



    glColor3f(0,0,0);
    glRasterPos2f(210,430);
    char msg7[]="WELCOME PAGE";
    for(int i=0;i<strlen(msg7);i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg7[i]);

    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(150,410);
    char msg8[]="A miniproject for Computer Graphics & Visualization Laboratory(18CSL68)";
    for(int i=0;i<strlen(msg8);i++)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, msg8[i]);

    glColor3f(0.6,.2,.3);
    glRasterPos2f(220,270);
    char msg9[]="Press X to Start";
    for(int i=0;i<strlen(msg9);i++)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, msg9[i]);


glColor3f(0,0,0);
    glRasterPos2f(50,180);
    char msg2[]="Submitted By:";
    for(int i=0;i<strlen(msg2);i++)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, msg2[i]);

glColor3f(0,0,0);
    glRasterPos2f(100,160);
   
    char msg3[]="4SO20CS087 Merlyn Gudinho";
    for(int i=0;i<strlen(msg3);i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msg3[i]);
glColor3f(0,0,0);

    glRasterPos2f(100,140);
    char msg4[]="4SO20CS092 Natasha Correia";
    for(int i=0;i<strlen(msg4);i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msg4[i]);
    glutSwapBuffers();
}
void circle(int r,int x,int y,float h)//r is radius, xy is center and h is a factor that makes it into an ellipse
{
    float theta;
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
       theta=i*3.142/180;
       glVertex2f(x+r*cos(theta)/h,y+r*sin(theta));
     }
     glEnd();

}
void bigsmoke()
{
    //circle(70,285,380,1);
    glColor3f(1,.75,0);
    circle(60,280,370,1.);//border
    circle(60,300,400,1.);
    circle(60,330,400,1.);
    circle(60,350,370,1.);
    circle(60,300,340,1.);
    circle(60,330,340,1.);
    glColor3f(1,0,0);
    circle(55,280,370,1.);//inner
    circle(55,300,400,1.);
    circle(55,330,400,1.);
    circle(55,350,370,1.);
    circle(55,300,340,1.);
    circle(55,330,340,1.);

}
void background_3_5_6()
{
    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_QUADS);//grass
glVertex2f(0,0);
glVertex2f(499,0);
glVertex2f(499,30);
glVertex2f(0,30);
glEnd();

    glBegin(GL_QUADS);//water
    glColor3f(0,0.2,0.8);
glVertex2f(0,30);
glVertex2f(499,30);
glVertex2f(499,90);
glVertex2f(0,90);
glEnd();
glEnable(GL_LINE_STIPPLE);

glLineStipple(8,0xAAAA);
glBegin(GL_LINES);
glColor3f(0,1,1);
glVertex2f(0,40);
glVertex2f(499,40);
glVertex2f(0,50);
glVertex2f(499,50);
    glVertex2f(0,60);
glVertex2f(499,60);
glVertex2f(0,70);
glVertex2f(499,70);
glVertex2f(0,80);
glVertex2f(499,80);
glEnd();
glDisable(GL_LINE_STIPPLE);


glBegin(GL_QUADS);//land
glColor3f(0.6,0.25,0.1);
glVertex2f(120,80);
glVertex2f(120,120);
glVertex2f(499,120);
glVertex2f(499,80);
glEnd();



}
void smoke2()
{
    //circle(40,285,380,1);
    glColor3f(1,0,0);
    circle(30,325,380,1.5);
    circle(30,345,400,1.5);
    circle(30,375,400,1.5);
    circle(30,395,380,1.5);
    circle(30,345,360,1.5);
    circle(30,375,360,1.5);
    glColor3f(1,.75,0);
    circle(24,325,380,1.5);//borders
    circle(24,345,400,1.5);
    circle(24,375,400,1.5);
    circle(24,395,380,1.5);
    circle(24,345,360,1.5);
    circle(24,375,360,1.5);
    glColor3f(1,1,0);
    circle(38,360,380,1);

}
void smoke1()
{
    circle(40,285,380,1);
    glColor3f(1,0,0);
    circle(30,245,380,1.5);
    circle(30,265,400,1.5);
    circle(30,295,400,1.5);
    circle(30,315,380,1.5);
    circle(30,265,360,1.5);
    circle(30,295,360,1.5);
    glColor3f(1,.75,0);
    circle(24,245,380,1.5);//borders
    circle(24,265,400,1.5);
    circle(24,295,400,1.5);
    circle(24,315,380,1.5);
    circle(24,265,360,1.5);
    circle(24,295,360,1.5);
    glColor3f(1,1,0);
    circle(38,280,380,1);

}
void aeroplane1()
{

    glBegin(GL_QUADS);   //left wing
    glColor3f(.4,.4,.4);
    glVertex2f(60,395);
    glVertex2f(70,395);
    glVertex2f(80,377);
    glVertex2f(70,377);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);//body
    glVertex2f(30,360);
    glVertex2f(40,385);
    glVertex2f(110,385);
    glVertex2f(110,360);
    glEnd();
    glBegin(GL_TRIANGLES);//tail
    glColor3f(.4,.4,.4);
    glVertex2f(35,373);
    glVertex2f(20,410);
    glVertex2f(30,360);
    glColor3f(1,1,1);
    glVertex2f(35,373);
    glVertex2f(20,410);
    glVertex2f(40,385);
    glEnd();
    glBegin(GL_QUADS);   //right wing
    glColor3f(.4,.4,.4);
    glVertex2f(60,350);
    glVertex2f(70,350);
    glVertex2f(80,368);
    glVertex2f(70,368);
    glEnd();

    glBegin(GL_TRIANGLES);//nose
    glColor3f(.4,.4,.4);
    glVertex2f(110,385);
    glVertex2f(110,372);
    glVertex2f(125,372);
    glColor3f(1,1,1);
    glVertex2f(110,372);
    glVertex2f(125,372);
    glVertex2f(110,360);
    glEnd();
    glBegin(GL_POINTS);
    glPointSize(0.5);
    glColor3f(0,0,0);
    glVertex2f(44,372);
    glVertex2f(54,372);
    glVertex2f(64,372);
    glVertex2f(84,372);
    glVertex2f(94,372);
    glVertex2f(104,372);
    glEnd();



}
void aeroplane2()
{
    glBegin(GL_QUADS);   //left wing
    glColor3f(0,0,0.8);
    glVertex2f(460,392);
    glVertex2f(470,392);
    glVertex2f(460,377);
    glVertex2f(450,377);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);//body
    glVertex2f(430,360);
    glVertex2f(430,382);
    glVertex2f(490,382);
    glVertex2f(480,360);
    glEnd();
    glBegin(GL_TRIANGLES);//tail
    glColor3f(0,0,0.8);
    glVertex2f(480,360);
    glVertex2f(495,400);
    glVertex2f(495,360);

    glEnd();
    glBegin(GL_QUADS);   //right wing
    glColor3f(0,0,0.8);
    glVertex2f(460,345);
    glVertex2f(470,345);
    glVertex2f(460,360);
    glVertex2f(450,360);
    glEnd();

    glBegin(GL_TRIANGLES);//nose
    glColor3f(0,0,0.8);
    glVertex2f(430,382);
    glVertex2f(430,371);
    glVertex2f(415,371);
    glColor3f(1,1,1);
    glVertex2f(430,360);
    glVertex2f(430,371);
    glVertex2f(415,371);
    glEnd();
    glBegin(GL_POINTS);
    glPointSize(5);
    glColor3f(0,0,0.5);
    glVertex2f(435,372);
    glVertex2f(445,372);
    glVertex2f(455,372);
    glVertex2f(465,372);
    glVertex2f(475,372);
    glEnd();



}
void twintower1()
{
    glBegin(GL_QUADS);//front face
    glColor3f(0.5,0.5,0.5);
glVertex2f(280,110);
glVertex2f(310,110);
glVertex2f(310,400);
glVertex2f(280,400);
glEnd();
    glBegin(GL_QUADS);//side face
    glColor3f(0.5,0.0,0.5);
glVertex2f(280,110);
glVertex2f(265,120);
glVertex2f(265,415);
glVertex2f(280,400);
glEnd();
    glBegin(GL_QUADS);//top face
    glColor3f(1,0.8,1);
glVertex2f(265,415);
glVertex2f(295,415);
glVertex2f(310,400);
glVertex2f(280,400);
glEnd();
if(c<2400)
    {
glBegin(GL_TRIANGLES);//pole
glColor3f(1,1,1);
glVertex2f(290,407);
glVertex2f(286,407);
glVertex2f(288,480);
glEnd();
    }

glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,110);
glVertex2f(280,110);
glVertex2f(265,120);
glVertex2f(265,140);
glVertex2f(280,130);
glVertex2f(310,130);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,150);
glVertex2f(280,150);
glVertex2f(265,160);
glVertex2f(265,180);
glVertex2f(280,170);
glVertex2f(310,170);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,190);
glVertex2f(280,190);
glVertex2f(265,200);
glVertex2f(265,220);
glVertex2f(280,210);
glVertex2f(310,210);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,230);
glVertex2f(280,230);
glVertex2f(265,240);
glVertex2f(265,260);
glVertex2f(280,250);
glVertex2f(310,250);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,270);
glVertex2f(280,270);
glVertex2f(265,280);
glVertex2f(265,300);
glVertex2f(280,290);
glVertex2f(310,290);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,310);
glVertex2f(280,310);
glVertex2f(265,320);
glVertex2f(265,340);
glVertex2f(280,330);
glVertex2f(310,330);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(310,350);
glVertex2f(280,350);
glVertex2f(265,360);
glVertex2f(265,380);
glVertex2f(280,370);
glVertex2f(310,370);
glEnd();
    glBegin(GL_LINE_LOOP);//front face outline

glVertex2f(280,110);
glVertex2f(310,110);
glVertex2f(310,400);
glVertex2f(280,400);
glEnd();
    glBegin(GL_LINE_LOOP);//side face outline
glVertex2f(280,110);
glVertex2f(265,120);
glVertex2f(265,415);
glVertex2f(280,400);
glEnd();
}
void twintower2()
{
    glBegin(GL_QUADS);//front face
    glColor3f(0.5,0.5,0.5);
glVertex2f(350,110);
glVertex2f(380,110);
glVertex2f(380,400);
glVertex2f(350,400);
glEnd();
    glBegin(GL_QUADS);//side face
    glColor3f(0.5,0.0,0.5);
glVertex2f(350,110);
glVertex2f(335,120);
glVertex2f(335,415);
glVertex2f(350,400);
glEnd();
    glBegin(GL_QUADS);//top face
    glColor3f(1,0.8,1);
glVertex2f(335,415);
glVertex2f(365,415);
glVertex2f(380,400);
glVertex2f(350,400);
glEnd();
if(c<2400)
    {
glBegin(GL_TRIANGLES);//pole
glColor3f(1,1,1);
glVertex2f(360,407);
glVertex2f(356,407);
glVertex2f(358,480);
glEnd();
    }

glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,110);
glVertex2f(350,110);
glVertex2f(335,120);
glVertex2f(335,140);
glVertex2f(350,130);
glVertex2f(380,130);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,150);
glVertex2f(350,150);
glVertex2f(335,160);
glVertex2f(335,180);
glVertex2f(350,170);
glVertex2f(380,170);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,190);
glVertex2f(350,190);
glVertex2f(335,200);
glVertex2f(335,220);
glVertex2f(350,210);
glVertex2f(380,210);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,230);
glVertex2f(350,230);
glVertex2f(335,240);
glVertex2f(335,260);
glVertex2f(350,250);
glVertex2f(380,250);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,270);
glVertex2f(350,270);
glVertex2f(335,280);
glVertex2f(335,300);
glVertex2f(350,290);
glVertex2f(380,290);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,310);
glVertex2f(350,310);
glVertex2f(335,320);
glVertex2f(335,340);
glVertex2f(350,330);
glVertex2f(380,330);
glEnd();
glBegin(GL_LINE_LOOP);//outline
glVertex2f(380,350);
glVertex2f(350,350);
glVertex2f(335,360);
glVertex2f(335,380);
glVertex2f(350,370);
glVertex2f(380,370);
glEnd();
    glBegin(GL_LINE_LOOP);//front face outline

glVertex2f(350,110);
glVertex2f(380,110);
glVertex2f(380,400);
glVertex2f(350,400);
glEnd();
    glBegin(GL_LINE_LOOP);//side face outline
glVertex2f(350,110);
glVertex2f(335,120);
glVertex2f(335,415);
glVertex2f(350,400);
glEnd();
}
void statueofliberty()
{
    glPushMatrix();
    glScalef(1.2,1.2,1);
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);//base bottom
glVertex2f(50,60);
glVertex2f(75,60);
glVertex2f(75,65);
glVertex2f(50,65);

glVertex2f(55,65);//base height
glVertex2f(70,65);
glVertex2f(70,75);
glVertex2f(55,75);

glVertex2f(50,75);//base top
glVertex2f(75,75);
glVertex2f(75,80);
glVertex2f(50,80);
glEnd();

glColor3f(.6,.95,0.8);
    glBegin(GL_QUADS);//body
    glVertex2f(52,80);
    glVertex2f(74,80);
    glVertex2f(66,150);
    glVertex2f(60,150);
    glEnd();
    glBegin(GL_QUADS);//head
    glVertex2f(66,150);
    glVertex2f(60,150);
    glVertex2f(57,168);
    glVertex2f(69,168);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);//crown
    glVertex2f(57,168);
    glVertex2f(59,185);
    glVertex2f(61,168);
    glVertex2f(63,185);
    glVertex2f(65,168);
    glVertex2f(67,185);
    glVertex2f(69,168);
glEnd();

glLineWidth(1);
    glBegin(GL_QUADS);//book
    glVertex2f(65,135);
    glVertex2f(65,115);
    glVertex2f(80,125);
    glVertex2f(80,145);
    glEnd();
    glBegin(GL_QUADS);//hand
    glVertex2f(60,145);
    glVertex2f(60,130);
    glVertex2f(40,180);
    glVertex2f(40,195);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP);//crown outline
    glColor3f(1,1,1);
    glVertex2f(57,168);
    glVertex2f(59,185);
    glVertex2f(61,168);
    glVertex2f(63,185);
    glVertex2f(65,168);
    glVertex2f(67,185);
    glVertex2f(69,168);
glEnd();
    glBegin(GL_LINE_LOOP);//body
    glVertex2f(52,80);
    glVertex2f(74,80);
    glVertex2f(66,150);
    glVertex2f(60,150);
    //glBegin(GL_QUADS);//head outline
    glVertex2f(57,168);
    glVertex2f(69,168);
    glVertex2f(66,150);
    glVertex2f(60,150);

    glEnd();
    glBegin(GL_LINE_LOOP);//book outline
    glVertex2f(65,135);
    glVertex2f(65,115);
    glVertex2f(80,125);
    glVertex2f(80,145);
    glEnd();
        glBegin(GL_LINE_LOOP);//hand
    glVertex2f(60,145);
    glVertex2f(58,134);
    glVertex2f(40,180);
    glVertex2f(40,195);
    glEnd();
    glColor3f(.6,.95,0.8);
    glBegin(GL_QUADS);//body
    glVertex2f(52,80);
    glVertex2f(74,80);
    glVertex2f(66,150);
    glVertex2f(60,150);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINES);//body lines

    glVertex2f(70,110);
    glVertex2f(54,100);
    glVertex2f(56,120);
    glVertex2f(68,128);
    glVertex2f(52,80);
    glVertex2f(72,92);
    glEnd();
    glPopMatrix();

}
void scene1()
{
glBegin(GL_POLYGON);//hills
glColor3f(0.8,0.8,0.8);
glVertex2i(-60,310);
glVertex2i(110,325);
glVertex2i(30,366);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
glVertex2i(40,310);
glVertex2i(230,325);
glVertex2i(150,366);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
glVertex2i(140,310);
glVertex2i(350,325);
glVertex2i(270,366);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.9,0.9,0.9);
glVertex2i(240,313);
glVertex2i(470,325);
    glVertex2i(390,366);
glEnd();

glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,110.0);
glVertex2f(500.0,110.0);
glVertex2f(500.0,320.0);
glVertex2f(0.0,320.0);
glEnd();

  glBegin(GL_POLYGON);
   glColor3f(1.0,0.3,0.0);
glVertex2i(312,310);
glVertex2i(312,333);
glVertex2i(309,333);
glVertex2i(309,310);
   glEnd();

glBegin(GL_POLYGON);//trees
   glColor3f(0.0,1.0,0.0);
glVertex2i(290,330);
glVertex2i(330,330);
    glVertex2i(310,380);
glEnd();

glBegin(GL_POLYGON);
   glColor3f(1.0,0.3,0.0);
glVertex2i(212,310);
glVertex2i(212,333);
glVertex2i(209,333);
glVertex2i(209,310);
   glEnd();

glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
glVertex2i(190,330);
glVertex2i(230,330);
    glVertex2i(210,380);
glEnd();

glBegin(GL_POLYGON);
   glColor3f(1.0,0.3,0.0);
glVertex2i(112,310);
glVertex2i(112,333);
glVertex2i(109,333);
glVertex2i(109,310);
   glEnd();

glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
glVertex2i(90,330);
glVertex2i(130,330);
    glVertex2i(110,380);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);//black road
glVertex2f(0.0,0.0);
glVertex2f(0.0,110.0);
glVertex2f(500.0,110.0);
glVertex2f(500.0,0.0);
glEnd();
glPushMatrix();
glTranslated(b,0,0);
glColor3f(0.9,0.7,0.0);
glBegin(GL_POLYGON);// strips on road
glVertex2f(0.0,40.0);
glVertex2f(8.0,60.0);
glVertex2f(58.0,60.0);
glVertex2f(50.0,40.0);
glEnd();

glColor3f(0.9,0.7,0.0);
glBegin(GL_POLYGON);// strips on road
glVertex2f(100.0,40.0);
glVertex2f(108.0,60.0);
glVertex2f(158.0,60.0);
glVertex2f(150.0,40.0);
glEnd();

glColor3f(0.9,0.7,0.0);
glBegin(GL_POLYGON);// strips on road
glVertex2f(200.0,40.0);
glVertex2f(208.0,60.0);
glVertex2f(258.0,60.0);
glVertex2f(250.0,40.0);
glEnd();

glColor3f(0.9,0.7,0.0);
glBegin(GL_POLYGON);//strips on road
glVertex2f(300.0,40.0);
glVertex2f(308.0,60.0);
glVertex2f(358.0,60.0);
glVertex2f(350.0,40.0);
glEnd();

glColor3f(0.9,0.7,0.0);
glBegin(GL_POLYGON);// strips on road
glVertex2f(400.0,40.0);
glVertex2f(408.0,60.0);
glVertex2f(458.0,60.0);
glVertex2f(450.0,40.0);
glEnd();

glColor3f(0.9,0.7,0.0);
glBegin(GL_POLYGON);// strips on road
glVertex2f(500.0,40.0);
glVertex2f(508.0,60.0);
glVertex2f(558.0,60.0);
glVertex2f(550.0,40.0);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a,c,0);

glColor3f(1.0,1.0,1.0);//aeroplane
  glBegin(GL_POLYGON);//rectangle
glVertex2f(70.0,60.0);
glVertex2f(210.0,60.0);
glVertex2f(210.0,100);
glVertex2f(70.0,100);
glEnd();

    glBegin(GL_TRIANGLES);
  glVertex2f(210.0,80.0);
  glVertex2f(250.0,80.0);
  glVertex2f(210.0,100.0);
  glEnd();
  glColor3f(0.5,0.5,0.5);
  glBegin(GL_TRIANGLES);
  glVertex2f(210.0,60.0);
  glVertex2f(250.0,80.0);
  glVertex2f(210.0,80.0);
  glEnd();

glColor3f(0.5,0.5,0.5);
  glBegin(GL_POLYGON);//upside wing
glVertex2f(120.0,100.0);
glVertex2f(160.0,100.0);
glVertex2f(120.0,140.0);
glVertex2f(80.0,140.0);
glEnd();
glColor3f(0.5,0.5,0.5);

 glBegin(GL_TRIANGLES);
  glVertex2f(70.0,80.0);
  glVertex2f(70.0,100.0);
  glVertex2f(30.0,150.0);
  glEnd();
  glColor3f(1.0,1.0,1.0);

   glBegin(GL_TRIANGLES);
  glVertex2f(70.0,80.0);
  glVertex2f(70.0,60.0);
  glVertex2f(30.0,150.0);
  glEnd();

glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);//down side wing
glVertex2f(120.0,65.0);
glVertex2f(160.0,65.0);
glVertex2f(120.0,20.0);
glVertex2f(80.0,20.0);
glEnd();
glColor3f(0,0,0);
glPointSize(10);
glBegin(GL_POINTS);
glVertex2f(90,80);
glVertex2f(110,80);
glVertex2f(130,80);
glVertex2f(160,80);
glVertex2f(180,80);
glVertex2f(200,80);
glEnd();
glPopMatrix();
}
void scene2()
{
glPushMatrix();
glTranslated(a2,0,0);
glColor3f(1,1,1);
glBegin(GL_POLYGON);//rectangle
glVertex2f(-10,320.0);
glVertex2f(130.0,320.0);
glVertex2f(130.0,360);
glVertex2f(-10,360);
glEnd();

//glColor3f(0.0,0.0,1.0);
  glBegin(GL_TRIANGLES);
  glVertex2f(130.0,340.0);
  glVertex2f(180.0,340.0);
  glVertex2f(130.0,360.0);
  glEnd();
  glColor3f(0.5,0.5,0.5);
  glBegin(GL_TRIANGLES);
  glVertex2f(130.0,340.0);
  glVertex2f(180.0,340.0);
  glVertex2f(130.0,320.0);
  glEnd();


//glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);//upside wing
glVertex2f(40.0,360.0);
glVertex2f(80.0,360.0);
glVertex2f(40.0,400.0);
glVertex2f(0.0,400.0);
glEnd();
glBegin(GL_TRIANGLES);
  glVertex2f(-10,340.0);
  glVertex2f(-10,360.0);
  glVertex2f(-70.0,400.0);
  glEnd();
  glColor3f(1,1,1);
 glBegin(GL_TRIANGLES);
  glVertex2f(-10.0,340.0);
  glVertex2f(-10.0,320.0);
  glVertex2f(-70.0,400.0);
  glEnd();

glColor3f(.5,.5,.5);
glBegin(GL_POLYGON);//down side wing
glVertex2f(00.0,280.0);
glVertex2f(40.0,280.0);
glVertex2f(80.0,330.0);
glVertex2f(40.0,330.0);
glEnd();
glColor3f(0,0,0);
glPointSize(10);
glBegin(GL_POINTS);
glVertex2f(10,345);
glVertex2f(30,345);
glVertex2f(50,345);
glVertex2f(80,345);
glVertex2f(100,345);
glVertex2f(120,345);
glEnd();
glPopMatrix();



    //clouds
    glColor3f(1,1,1);
    circle(30,225,250,1.5);//cloud 2
    circle(30,245,270,1.5);
    circle(30,275,270,1.5);
    circle(30,295,250,1.5);
    circle(30,245,230,1.5);
    circle(30,275,230,1.5);
    glColor3f(1,1,1);
    circle(30,55,250,1.5);//cloud 1
    circle(30,75,270,1.5);
    circle(30,105,270,1.5);
    circle(30,125,250,1.5);
    circle(30,75,230,1.5);
    circle(30,105,230,1.5);
    glColor3f(1,1,1);
    circle(30,385,250,1.5);//cloud 3
    circle(30,405,270,1.5);
    circle(30,435,270,1.5);
    circle(30,455,250,1.5);
    circle(30,405,230,1.5);
    circle(30,435,230,1.5);

}
void scene3()
{
    background_3_5_6();
twintower1();

    glPushMatrix();
    glScalef(1.3,1.1,1);
    glTranslated(-100,-50,0);
    glTranslated(crash1x,0,0);

    aeroplane1();
    glPopMatrix();

    if(crash1x==200)smoke1();
twintower2();
statueofliberty();

}
void scene4()
{
    glBegin(GL_QUADS);//room
    glColor3f(1,1,1);
    glVertex2f(480,480);
    glVertex2f(480,0);
    glVertex2f(10,0);
    glVertex2f(10,480);
    glEnd();
    glBegin(GL_QUADS);//walls
    glColor3f(1,1,.5);
    glVertex2f(60,120);
    glVertex2f(60,420);
    glVertex2f(430,420);
    glVertex2f(430,120);
    glEnd();

    glBegin(GL_QUADS);//cupboard
    glColor3f(0.6,.2,.3);
    glVertex2f(350,120);
    glVertex2f(350,310);
    glVertex2f(410,310);
    glVertex2f(410,120);
    glEnd();
    glBegin(GL_QUADS);//ground
    glColor3f(1,1,1);
    glVertex2f(60,120);
    glVertex2f(60,50);
    glVertex2f(430,50);
    glVertex2f(430,120);

    glColor3f(.4,.4,.4);//bottom of floor
    glVertex2f(10,0);
    glVertex2f(10,50);
    glVertex2f(480,50);
    glVertex2f(480,0);

    glVertex2f(60,50);//side of building
    glVertex2f(60,480);
    glVertex2f(10,480);
    glVertex2f(10,50);
    glVertex2f(430,50);//
    glVertex2f(430,480);
    glVertex2f(480,480);
    glVertex2f(480,50);
    glEnd();

    glBegin(GL_QUADS);//windows
    glColor3f(.7,1,1);
    glVertex2f(60,480);
    glVertex2f(60,420);
    glVertex2f(430,420);
    glVertex2f(430,480);
    glEnd();

    glBegin(GL_POINTS);
    glPointSize(5);
    glVertex2f(100,50);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5,0.25,1);
    glLineWidth(2);
    glEnd();

    glBegin(GL_LINES);//office outline
    glVertex2f(10,50);
    glVertex2f(480,50);
    glVertex2f(10,50);
    glVertex2f(10,480);
    glVertex2f(480,50);
    glVertex2f(480,480);
    glVertex2f(480,480);
    glVertex2f(10,480);
    glVertex2f(60,50);
    glVertex2f(60,480);
    glVertex2f(430,50);
    glVertex2f(430,480);
    glVertex2f(60,120);
    glVertex2f(430,120);
    glVertex2f(60,420);
    glVertex2f(430,420);
    glVertex2f(120,420);
    glVertex2f(120,480);
    glVertex2f(125,420);
    glVertex2f(125,480);
    glVertex2f(180,420);
    glVertex2f(180,480);
    glVertex2f(185,420);
    glVertex2f(185,480);
    glVertex2f(240,420);
    glVertex2f(240,480);
    glVertex2f(245,420);
    glVertex2f(245,480);
    glVertex2f(300,420);
    glVertex2f(300,480);
    glVertex2f(305,420);
    glVertex2f(305,480);
    glVertex2f(360,420);
    glVertex2f(360,480);
    glVertex2f(365,420);
    glVertex2f(365,480);
    glVertex2f(410,420);
    glVertex2f(410,480);
    glVertex2f(415,420);
    glVertex2f(415,480);
    glVertex2f(350,120);
    glVertex2f(350,310);
    glVertex2f(350,310);
    glVertex2f(410,310);
    glVertex2f(410,310);
    glVertex2f(410,120);
    glVertex2f(380,120);
    glVertex2f(380,310);
    glVertex2f(350,200);
    glVertex2f(410,200);
    glEnd();

    glColor3f(1,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);//cupboard
    glVertex2f(375,190);
    glVertex2f(385,190);
    glEnd();

    glColor3f(0.58,0.3,0.2);
    glBegin(GL_QUADS);//table
    glVertex2f(90,120);
    glVertex2f(150,120);
    glVertex2f(150,200);
    glVertex2f(90,200);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.25,1);
    glLineWidth(4);
    glEnd();

    glBegin(GL_LINES);//drawer
    glVertex2f(90,140);
    glVertex2f(150,140);
    glVertex2f(90,160);
    glVertex2f(150,160);
    glVertex2f(90,180);
    glVertex2f(150,180);
    glEnd();


    glPushMatrix();
    glTranslated(p,0,0);
    glBegin(GL_LINES);
    glVertex2f(178,180);//hands
    glVertex2f(170,220);
    glVertex2f(188,180);
    glVertex2f(194,220);
    glVertex2f(230,200); //people 2 hand
    glVertex2f(240,230);
    glVertex2f(220,190);
    glVertex2f(200,230);
    glVertex2f(260,140);//people 3 leg
    glVertex2f(265,190);
    glVertex2f(255,210);//people 3 hands
    glVertex2f(250,245);
    glVertex2f(270,210);
    glVertex2f(275,245);
    glColor3f(0,1,0);
    glLineWidth(8);
    glEnd();
    glPopMatrix();

    glColor3f(1,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);//drawer
    glVertex2f(120,130);
    glVertex2f(120,150);
    glVertex2f(120,170);
    glVertex2f(120,190);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(110,200);
    glVertex2f(130,200);
    glVertex2f(120,220);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);//computer
    glVertex2f(100,220);
    glVertex2f(140,220);
    glVertex2f(140,260);
    glVertex2f(100,260);
    glColor3f(.5,.5,.5);
    glVertex2f(105,225);
    glVertex2f(135,225);
    glVertex2f(135,255);
    glVertex2f(105,255);
    glEnd();

    glPushMatrix();
    glTranslated(p,0,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);//people 1
    glVertex2f(170,120);
    glVertex2f(180,120);
    glVertex2f(180,130);
    glVertex2f(170,130);

    glVertex2f(185,120);
    glVertex2f(195,120);
    glVertex2f(195,130);
    glVertex2f(185,130);



    glColor3f(.95,.9,.8);//legs
    glVertex2f(174,130);
    glVertex2f(177,130);
    glVertex2f(177,160);
    glVertex2f(174,160);

    glVertex2f(189,130);
    glVertex2f(192,130);
    glVertex2f(192,160);
    glVertex2f(189,160);
    glEnd();
    glBegin(GL_TRIANGLES);//skirt
    glColor3f(1,0,1);
    glVertex2f(172,160);
    glVertex2f(194,160);
    glVertex2f(183,240);
    glEnd();
    glColor3f(0,0,0);
    circle(15,182,240,1.5);//face
    glColor3f(.95,.9,.8);
    circle(15,182,235,2);//face

    glColor3f(0,.2,0);
    glBegin(GL_QUADS);
    glVertex2f(210,120);//people 2
    glVertex2f(220,120);//shoes
    glVertex2f(220,130);
    glVertex2f(210,130);
    glVertex2f(225,120);
    glVertex2f(235,120);
    glVertex2f(235,130);
    glVertex2f(225,130);
    glVertex2f(215,130);//legs
    glVertex2f(215,170);
    glVertex2f(230,130);
    glVertex2f(230,170);
     glColor3f(1,0,0);
     glEnd();

    glBegin(GL_QUADS);
    glVertex2f(215,170);//body
    glVertex2f(230,170);
    glVertex2f(230,220);
    glVertex2f(215,220);
    glEnd();
    glColor3f(.95,.9,.8);
    circle(15,223,235,2);//face

    glColor3f(0,0,0);//hair

    glBegin(GL_QUADS);
    glVertex2f(217,245);
    glVertex2f(230,245);
    glVertex2f(230,255);
    glVertex2f(217,255);

    glColor3f(1,0,0);
    glVertex2f(255,140);// people 3 pant
    glVertex2f(270,140);
    glVertex2f(270,190);
    glVertex2f(255,190);
    glColor3f(0,1,0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(255,190);//people 3 body
    glVertex2f(270,190);
    glVertex2f(270,220);
    glVertex2f(255,220);
    glEnd();
    glColor3f(0,0,0);//people 3 head
    glBegin(GL_QUADS);
    glVertex2f(255,220);
    glVertex2f(272,220);
    glVertex2f(272,255);
    glVertex2f(255,255);

    glEnd();
    glColor3f(.95,.9,.8);
    circle(15,263,235,2);//face

    glColor3f(0.65,0.19,0.65);
    glBegin(GL_TRIANGLES);

    glVertex2f(257,120);// people 3 shoes
    glVertex2f(264,120);
    glVertex2f(260,140);
    glVertex2f(262,120);
    glVertex2f(269,120);
    glVertex2f(265,140);

    glEnd();
    glPopMatrix();
    glPushMatrix();
    if(p>30){ glScalef(1.5,1.5,1);
    glTranslated(-100,-100,0);}
    glColor3f(.7,.7,.7);
    circle(30,185,350,1.5);//cloud 3
    circle(30,205,370,1.5);
    circle(30,235,370,1.5);
    circle(30,255,350,1.5);
    circle(30,205,330,1.5);
    circle(30,235,330,1.5);
    glPopMatrix();
}
void scene5()
{
    background_3_5_6();
    statueofliberty();
    twintower1();
    smoke1();
    if(crash2x==-160)smoke2();
    glPushMatrix();
    glTranslated(100,0,0);
    glTranslated(crash2x,0,0);
    aeroplane2();
    glPopMatrix();

twintower2();

}
void scene6()
{

     glPushMatrix();
     glTranslatef(0,ty,0);
     twintower1();
     twintower2();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(bsoutx,by,0);
     glScalef(bs,bs,1);
     bigsmoke();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0,ty,0);
     bigsmoke();
     glPopMatrix();

background_3_5_6();
statueofliberty();

}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
if(c<360)
        scene1();
    else if(c<800)
        scene2();
    else if(c<1200)
        scene3();
    else if(c<1700)
        scene4();
    else if(c<2400)
        scene5();
    else
        scene6();
glFlush();
}

void myinit() {
glClearColor(0.3, 1.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glPointSize(10.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void menu(unsigned char key)
{
    if(key=='1'){
        c=0;
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
    else if(key=='2'){
        c=360;
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
    else if(key=='3'){
        c=800;
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
    else if(key=='4'){
        c=1200;
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
     else  if(key=='5'){
        c=1700;
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
     else if(key=='6'){
        c=2400;
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
}
void keys(unsigned char key,int x,int y)
{

    if(key=='x')
    {
        glutDisplayFunc(display);
        glutTimerFunc(100,update,0);
    }
    menu(key);
    glutPostRedisplay();

}

 main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(1000, 600);
glutInitWindowPosition(200, 0);
glutCreateWindow("9/11 aeroplane crash");
glutDisplayFunc(welcomeDisplay);
glutKeyboardFunc(keys);
myinit();
glutMainLoop();
 }


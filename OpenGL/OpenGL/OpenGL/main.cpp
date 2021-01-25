#include <windows.h>
#include "GL/glut.h"
#include <iostream>

float r1,r2,r3;

float xr = 0, zr = 0;


class Coordinates{
public:
    float x,y,z;
    
};
class Cube {
public:
    Coordinates origin;
    Coordinates rotation;
    Coordinates size;
    char* color1,*color2,*color3,*color4,*color5,*color6;
    
    Cube(){
        color1 = "FFFFFF";
        color2 = "FFFFFF";
        color3 = "FFFFFF";
        color4 = "FFFFFF";
        color5 = "FFFFFF";
        color6 = "FFFFFF";
    }
};

class Pyramid{
public: 
    Coordinates origin;
    Coordinates rotation;
    Coordinates size;
    char* color1,*color2,*color3,*color4;

    Pyramid(){
        color1 = "FFFFFF";
        color2 = "FFFFFF";
        color3 = "FFFFFF";
        color4 = "FFFFFF";
    }
};




void init(void)
{
    glClearColor(0,0,0,0);
    
}


void hexToRGB(float& rf, float& gf, float& bf, char * hex){
    int r,g,b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    rf = r / 255.0;
    gf = g / 255.0;
    bf = b / 255.0;
}

void DrawCube(Cube cube)
{
    float xRotated,yRotated,zRotated,oX,oY,oZ,xSize,ySize,zSize;
    char* color,*color2,*color3,*color4,*color5,*color6;
    float r,g,b;
    xRotated = cube.rotation.x;
    yRotated = cube.rotation.y;
    zRotated = cube.rotation.z;
    oX = cube.origin.x;
    oY = cube.origin.y;
    oZ = cube.origin.z;
    xSize = cube.size.x;
    ySize = cube.size.y;
    zSize = cube.size.z;
    color = cube.color1;
    color2 = cube.color2;
    color3 = cube.color3;
    color4 = cube.color4;
    color5 = cube.color5;
    color6 = cube.color6;
    
    
    hexToRGB(r,g,b, color);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glBegin(GL_QUADS);        // Draw The Cube Using quads
    
    glColor3f(r,g,b);    // Color Blue
    glVertex3f( 1.0f*xSize + oX, 1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f*xSize+ oX, 1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f*xSize+ oX, 1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f*xSize+ oX, 1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Right Of The Quad (Top)
    
    hexToRGB(r,g,b, color2);
    glColor3f(r,g,b);    // Color Orange//
    glVertex3f( 1.0f*xSize+ oX ,-1.0f*ySize+ oY, 1.0f*zSize+ oZ );    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f*xSize+ oX ,-1.0f*ySize+ oY, 1.0f*zSize+ oZ );    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f*xSize+ oX ,-1.0f*ySize+ oY,-1.0f*zSize+ oZ );    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f*xSize+ oX ,-1.0f*ySize+ oY,-1.0f*zSize+ oZ );    // Bottom Right Of The Quad (Bottom)
    
    hexToRGB(r,g,b, color3);
    glColor3f(r,g,b);     // Color Red
    glVertex3f( 1.0f*xSize+ oX , 1.0f*ySize+ oY, 1.0f*zSize+ oZ );    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f*xSize+ oX , 1.0f*ySize+ oY, 1.0f*zSize+ oZ );    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f*xSize+ oX ,-1.0f*ySize+ oY, 1.0f*zSize+ oZ );    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f*xSize+ oX ,-1.0f*ySize+ oY, 1.0f*zSize+ oZ );    // Bottom Right Of The Quad (Front)
    
    hexToRGB(r,g,b, color4);
    glColor3f(r,g,b);   // Color Yellow
    glVertex3f( 1.0f*xSize+ oX ,-1.0f*ySize+ oY,-1.0f*zSize+ oZ );    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f*xSize+ oX ,-1.0f*ySize+ oY,-1.0f*zSize+ oZ );    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f*xSize+ oX , 1.0f*ySize+ oY,-1.0f*zSize+ oZ );    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f*xSize+ oX , 1.0f*ySize+ oY,-1.0f*zSize+ oZ );    // Bottom Right Of The Quad (Back)
    
    hexToRGB(r,g,b, color5);
    glColor3f(r,g,b);
    glVertex3f(-1.0f*xSize+ oX, 1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f*xSize+ oX, 1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Right Of The Quad (Left)+ oX
    
    hexToRGB(r,g,b, color6);
    glColor3f(r,g,b);     // Color Violet
    glVertex3f( 1.0f*xSize+ oX, 1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f*xSize+ oX, 1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Left Of The Quad (Right)
    glVertex3f( 1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Bottom Right Of The Quad (Right)
    glEnd();            // End Drawing The Cube
    
}

void DrawPyramid(Pyramid pyramid){
    float xRotated,yRotated,zRotated,oX,oY,oZ,xSize,ySize,zSize;
    char* color,*color2,*color3,*color4;
    float r,g,b;
    xRotated = pyramid.rotation.x;
    yRotated = pyramid.rotation.y;
    zRotated = pyramid.rotation.z;
    oX = pyramid.origin.x;
    oY = pyramid.origin.y;
    oZ = pyramid.origin.z;
    xSize = pyramid.size.x;
    ySize = pyramid.size.y;
    zSize = pyramid.size.z;
    color = pyramid.color1;
    color2 = pyramid.color2;
    color3 = pyramid.color3;
    color4 = pyramid.color4;
    
    
    hexToRGB(r,g,b, color);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);        // Draw The Cube Using quads
    
    glColor3f(r,g,b);    // Color Blue
    glVertex3f( 0.0f*xSize + oX, 1.0f*ySize+ oY,0.0f*zSize+ oZ);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f*xSize+ oX, -1.0f*ySize+ oY,1.0f*zSize+ oZ);    // Top Left Of The Quad (Top)
    glVertex3f(1.0f*xSize+ oX, -1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Top)
    
    hexToRGB(r,g,b, color2);
    glColor3f(r,g,b);    // Color Orange//
    glVertex3f( 0.0f*xSize+ oX,1.0f*ySize+ oY, 0.0f*zSize+ oZ);    // Top Right Of The Quad (Bottom)
    glVertex3f(1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Left Of The Quad (Bottom)
    glVertex3f(1.0f*xSize+ oX,-1.0f*ySize+ oY, -1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Bottom)
    
    hexToRGB(r,g,b, color3);
    glColor3f(r,g,b);     // Color Red
    glVertex3f( 0.0f*xSize+ oX, 1.0f*ySize+ oY, 0.0f*zSize+ oZ);    // Top Right Of The Quad (Front)
    glVertex3f(1.0f*xSize+ oX, -1.0f*ySize+ oY, -1.0f*zSize+ oZ);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY, -1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Front)
    
    hexToRGB(r,g,b, color4);
    glColor3f(r,g,b);   // Color Yellow
    glVertex3f( 0.0f*xSize+ oX,1.0f*ySize+ oY,0.0f*zSize+ oZ);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY,1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Back)
    
    glEnd();            // End Drawing The Cube
    
}



void animation(void)
{
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //r1 += 0.5; //derecha izquierda
    //r2 += 0.5; //Hacia a mi
    // DrawCube(3, 0, 0,1, 0.5,1, "C0E0A7","A5C88E","A5C88E","6F915D","537046","1C2F17",r1,r2,0);
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.1,50.0);
    glViewport(0,0,x,y);  //Use the whole window for rendering
    glutPostRedisplay();
}

void generateHouse(){
    Cube c1,r1,r2,r3,d1,d2;
    c1.origin.x = -1.2;
    c1.origin.y = 1;
    c1.origin.z = 0;
    c1.rotation.x = 45;
    c1.rotation.y = 45;
    c1.rotation.z = 0;
    c1.size.x = 0.20;
    c1.size.y = 0.15;
    c1.size.z = 0.2;
    c1.color1 = "813405"; //Cara principal
    c1.color3 = "722A04"; //Cara medio oscura
    c1.color5 = "631F03";// Cara oscura
    
    r1.origin.x = -1.2;
    r1.origin.y = 1.2;
    r1.origin.z = 0;
    r1.rotation.x = 45;
    r1.rotation.y = 45;
    r1.rotation.z = 0;
    r1.size.x = 0.25;
    r1.size.y = 0.05;
    r1.size.z = 0.25;
    r1.color1 = "813405"; //Cara principal
    r1.color3 = "722A04"; //Cara medio oscura
    r1.color5 = "631F03";// Cara oscura
    
    r2.origin.x = -1.2;
    r2.origin.y = 1.28;
    r2.origin.z = 0;
    r2.rotation.x = 45;
    r2.rotation.y = 45;
    r2.rotation.z = 0;
    r2.size.x = 0.2;
    r2.size.y = 0.05;
    r2.size.z = 0.2;
    r2.color1 = "813405"; //Cara principal
    r2.color3 = "722A04"; //Cara medio oscura
    r2.color5 = "631F03";// Cara oscura
    
    r3.origin.x = -1.2;
    r3.origin.y = 1.35;
    r3.origin.z = 0;
    r3.rotation.x = 45;
    r3.rotation.y = 45;
    r3.rotation.z = 0;
    r3.size.x = 0.15;
    r3.size.y = 0.05;
    r3.size.z = 0.15;
    r3.color1 = "813405"; //Cara principal
    r3.color3 = "722A04"; //Cara medio oscura
    r3.color5 = "631F03";// Cara oscura

    d1.origin.x = -1.2;
    d1.origin.y = 1;
    d1.origin.z = 1;
    d1.rotation.x = 45;
    d1.rotation.y = 45;
    d1.rotation.z = 0;
    d1.size.x = 0.20;
    d1.size.y = 0.05;
    d1.size.z = 0.5;
    d1.color1 = "813405"; //Cara principal
    d1.color3 = "722A04"; //Cara medio oscura
    d1.color5 = "631F03";// Cara oscura
    
    d2.origin.x = -0.9;
    d2.origin.y = 1;
    d2.origin.z = 0.75;
    d2.rotation.x = 45;
    d2.rotation.y = 45;
    d2.rotation.z = 0;
    d2.size.x = 0.05;
    d2.size.y = 0.05;
    d2.size.z = 0.05;
    d2.color1 = "813405"; //Cara principal
    d2.color3 = "722A04"; //Cara medio oscura
    d2.color5 = "631F03";// Cara oscura
    
    DrawCube(c1);
    DrawCube(r1);
    DrawCube(r2);
    DrawCube(r3);
    DrawCube(d1);
    DrawCube(d2);
    
    d2.origin.z = 1.25;
    DrawCube(d2);
    
    d2.origin.x = -1.55;
    DrawCube(d2);
    
    d2.origin.z = 0.75;
    DrawCube(d2);

}


void generateTree(float x, float y){
    Cube t1;
    t1.origin.x = x;
    t1.origin.y = 1;
    t1.origin.z = y;
    t1.rotation.x = 45;
    t1.rotation.y = 45;
    t1.rotation.z = 0;
    t1.size.x = 0.15;
    t1.size.y = 0.05;
    t1.size.z =0.15;
    t1.color1 = "366822"; //Cara principal
    t1.color3 = "275019"; //Cara medio
    t1.color5 = "17380F";// Cara oscura
    DrawCube(t1);
    
    t1.size.x = 0.10;
    t1.size.z = 0.10;
    t1.origin.y = 1.08;
    DrawCube(t1);
    
    t1.size.x = 0.05;
    t1.size.z = 0.05;
    t1.origin.y = 1.15;
    DrawCube(t1);


}

void generateTerrain() {
    
    Cube plane;
    plane.origin.x = 0;
    plane.origin.y = 0;
    plane.origin.z = 0;
    plane.rotation.x = 45;
    plane.rotation.y = 45;
    plane.rotation.z = 0;
    plane.size.x = 3;
    plane.size.y = 0.24;
    plane.size.z = 3;
    plane.color1 = "0080FF"; //Cara principal
    plane.color2 = "FFFFFF";
    plane.color3 = "62BEFF"; //Cara medio oscura
    plane.color4 = "FFFFFF";
    plane.color5 = "001C85";// Cara oscura
    plane.color6 = "1C2F17";
    
    Cube earth1;
    earth1.origin.x = 0.2;
    earth1.origin.y = 0.20;
    earth1.origin.z = -1;
    earth1.rotation.x = 45;
    earth1.rotation.y = 45;
    earth1.rotation.z = 0;
    earth1.size.x = 2;
    earth1.size.y = 0.1;
    earth1.size.z = 1;
    earth1.color1 = "2E9900";
    earth1.color2 = "FFFFFF";
    earth1.color3 = "64C237";
    earth1.color4 = "FFFFFF";
    earth1.color5 = "1C6700";
    earth1.color6 = "1C2F17";
    
    Cube earth2;
    earth2.origin.x = 0.2;
    earth2.origin.y = 0.20;
    earth2.origin.z = -1;
    earth2.rotation.x = 45;
    earth2.rotation.y = 0;
    earth2.rotation.z = 0;
    earth2.size.x = 2;
    earth2.size.y = 0.1;
    earth2.size.z = 1;
    earth2.color1 = "2E9900";
    earth2.color2 = "FFFFFF";
    earth2.color3 = "64C237";
    earth2.color4 = "FFFFFF";
    earth2.color5 = "1C6700";
    earth2.color6 = "1C2F17";
    
    DrawCube(plane);
    DrawCube(earth1);
    DrawCube(earth2);
    generateTree(0,0.2);
    generateTree(1,0);
    generateTree(0.5,0.5);
    generateTree(-0.5,-1.5);
    generateTree(-1.8,0);
    generateTree(-1.2,-1.1);
    
}

void generateLightHouse(){
    Cube basement;
    basement.origin.x = 0.8;
    basement.origin.y = 1;
    basement.origin.z = 1;
    basement.rotation.x = 45;
    basement.rotation.y = 45;
    basement.rotation.z = 0;
    basement.size.x = 0.2;
    basement.size.y = 0.3;
    basement.size.z =0.2;
    basement.color1 = "6d6d6d"; //Cara principal
    basement.color3 = "424242"; //Cara medio
    basement.color5 = "373737";// Cara oscura
    DrawCube(basement);

    Cube pillar;
    pillar.origin.x = 1.2;
    pillar.origin.y = 1.2;
    pillar.origin.z = 1;
    pillar.rotation.x = 45;
    pillar.rotation.y = 45;
    pillar.rotation.z = 0;
    pillar.size.x = 0.2;
    pillar.size.y = 0.5;
    pillar.size.z =0.2;
    pillar.color1 = "ff5f52"; //Cara principal
    pillar.color3 = "c62828"; //Cara medio
    pillar.color5 = "8e0000";// Cara oscura
    DrawCube(pillar);

    Cube roof;
    roof.origin.x = 0.7;
    roof.origin.y = 1.3;
    roof.origin.z = 1;
    roof.rotation.x = 45;
    roof.rotation.y = 45;
    roof.rotation.z = 0;
    roof.size.x = 0.3;
    roof.size.y = 0.05;
    roof.size.z =0.2;
    roof.color1 = "813405"; //Cara principal
    roof.color3 = "722A04"; //Cara medio oscura
    roof.color5 = "631F03";// Cara oscura
    DrawCube(roof);

    Cube door;
    door.origin.x = 0.5;
    door.origin.y = 1;
    door.origin.z = 1.05;
    door.rotation.x = 45;
    door.rotation.y = 45;
    door.rotation.z = 0;
    door.size.x = 0.01;
    door.size.y = 0.2;
    door.size.z =0.1;
    door.color1 = "813405"; //Cara principal
    door.color3 = "722A04"; //Cara medio oscura
    door.color5 = "631F03";// Cara oscura
    DrawCube(door);


    Cube light;
    light.origin.x = 1.2;
    light.origin.y = 1.8;
    light.origin.z = 1;
    light.rotation.x = 45 + xr;
    light.rotation.y = 45;
    light.rotation.z = 0 + zr;
    light.size.x = 0.1;
    light.size.y = 0.1;
    light.size.z =0.1;
    light.color1 = "fff263"; //Cara principal
    light.color3 = "fbc02d"; //Cara medio
    light.color5 = "c49000";// Cara oscura
    DrawCube(light);

    Pyramid topRoof;
    topRoof.origin.x = 1.2;
    topRoof.origin.y = 2;
    topRoof.origin.z = 1;
    topRoof.rotation.x = 45;
    topRoof.rotation.y = 45;
    topRoof.rotation.z = 0;
    topRoof.size.x = 0.25;
    topRoof.size.y = 0.1;
    topRoof.size.z =0.25;
    topRoof.color1 = "c62828"; //Cara frente iluminada
    topRoof.color2 = "c62828"; //Cara atras
    topRoof.color3 = "631F03"; //Cara atrás
    topRoof.color4 = "8e0000"; //cara frente no iluminada
    DrawPyramid(topRoof); 
}

void generateMontain(){
    Pyramid mont;
    mont.origin.x = 1.3;
    mont.origin.y = 1;
    mont.origin.z = -1.2;
    mont.rotation.x = 45;
    mont.rotation.y = 45;
    mont.rotation.z = 0;
    mont.size.x = 0.5;
    mont.size.y = 1;
    mont.size.z =0.5;
    mont.color1 = "757575"; //Cara frente iluminada
    mont.color2 = "757575"; //Cara atras
    mont.color3 = "757575"; //Cara atrás
    mont.color4 = "494949"; //cara frente no iluminada
    DrawPyramid(mont); 

    Pyramid mont1;
    mont1.origin.x = -0.3;
    mont1.origin.y = 1;
    mont1.origin.z = -1;
    mont1.rotation.x = 45;
    mont1.rotation.y = 45;
    mont1.rotation.z = 0;
    mont1.size.x = 0.2;
    mont1.size.y = 0.5;
    mont1.size.z =0.2;
    mont1.color1 = "757575"; //Cara frente iluminada
    mont1.color2 = "757575"; //Cara atras
    mont1.color3 = "757575"; //Cara atrás
    mont1.color4 = "494949"; //cara frente no iluminada
    DrawPyramid(mont1); 

    Pyramid mont2;
    mont2.origin.x = 0.2;
    mont2.origin.y = 1;
    mont2.origin.z = -1;
    mont2.rotation.x = 45;
    mont2.rotation.y = 45;
    mont2.rotation.z = 0;
    mont2.size.x = 0.2;
    mont2.size.y = 0.7;
    mont2.size.z =0.2;
    mont2.color1 = "757575"; //Cara frente iluminada
    mont2.color2 = "757575"; //Cara atras
    mont2.color3 = "757575"; //Cara atrás
    mont2.color4 = "494949"; //cara frente no iluminada
    DrawPyramid(mont2); 

    Pyramid mont3;
    mont3.origin.x = 0.7;
    mont3.origin.y = 1;
    mont3.origin.z = -0.9;
    mont3.rotation.x = 45;
    mont3.rotation.y = 45;
    mont3.rotation.z = 0;
    mont3.size.x = 0.3;
    mont3.size.y = 0.9;
    mont3.size.z =0.3;
    mont3.color1 = "757575"; //Cara frente iluminada
    mont3.color2 = "757575"; //Cara atras
    mont3.color3 = "757575"; //Cara atrás
    mont3.color4 = "494949"; //cara frente no iluminada
    DrawPyramid(mont3); 
}

void  loadModels (){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    generateMontain();
    generateHouse();
    generateTerrain();
    generateLightHouse();
    glFlush(); //Imoprtante que este al final de todo los drawings
}

void specialkey(int key, int x, int z){
    switch(key){
        case GLUT_KEY_UP:
        zr++;
        glutPostRedisplay();
        break;

        case GLUT_KEY_DOWN:
        zr--;
        glutPostRedisplay();
        break;
        
        case GLUT_KEY_LEFT:
        xr--;
        glutPostRedisplay();
        break;
        
        case GLUT_KEY_RIGHT:
        xr++;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    //we initizlilze the glut. functions
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(500, 500);
    glutCreateWindow(argv[0]);
    glEnable(GL_DEPTH_TEST);
    
    init();
    // glEnable( GL_BLEND );
    glutDisplayFunc(loadModels);
    glutReshapeFunc(reshape);
    //Set the function for the animation.
    //glutIdleFunc(animation);
    glutSpecialFunc(specialkey);
    glutMainLoop();
    return 0;
}

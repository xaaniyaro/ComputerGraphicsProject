#include <windows.h>
#include "GL/glut.h"
#include <iostream>
#include <math.h>

#define PI 3.1415927

float r1,r2,r3;


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
};

/************************** draw_cylinder() **************************
 * This function will draw the cylinder
 *
 *   @parameter1: radius = The radius of cylinder
 *   @parameter2: height = Height of the cylinder
 *   @parameter3: R = Red value of the cylinder's color
 *   @parameter4: G = Green value of the cylinder's color
 *   @parameter5: B = Blue value of the cylinder's color
 *
 *   @return: Nothing
 */
void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}



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
    glVertex3f( 1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Bottom Right Of The Quad (Bottom)
    
    hexToRGB(r,g,b, color3);
    glColor3f(r,g,b);     // Color Red
    glVertex3f( 1.0f*xSize+ oX, 1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f*xSize+ oX, 1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f*xSize+ oX,-1.0f*ySize+ oY, 1.0f*zSize+ oZ);    // Bottom Right Of The Quad (Front)
    
    hexToRGB(r,g,b, color4);
    glColor3f(r,g,b);   // Color Yellow
    glVertex3f( 1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f*xSize+ oX,-1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f*xSize+ oX, 1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f*xSize+ oX, 1.0f*ySize+ oY,-1.0f*zSize+ oZ);    // Bottom Right Of The Quad (Back)
    
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
    glFlush();
}

void  loadModels (){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

    draw_cylinder(0.3, 1.0, 255, 160, 100);

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
    
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
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
    glutIdleFunc(animation);
    glutMainLoop();
    return 0;
}

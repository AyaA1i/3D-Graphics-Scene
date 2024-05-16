#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include<cmath>
#include <vector>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

GLfloat doorAngle = 0.0f;
GLfloat windowAngle = 0.0f;
GLfloat BycAngle = 0.0f;
GLfloat translateByc = 0.0f;
GLfloat wheelLeftAngle = 0.0f;
GLfloat wheelRightAngle = 0.0f;
GLfloat wheelAngle = 0.0f;
float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f;
const float PI = 3.14159265358979323846;


void DrawByc() {
    glTranslatef(translateByc, 0, 0);
    glRotatef(wheelAngle, 0.0, 1.0, 0.0);

    glPushMatrix();
    // horizontal down
    //back
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.65, 3.0); // Top-left
    glVertex3f(0.3, -0.65, 3.0);  // Top-right
    glVertex3f(0.3, -0.55, 3.0);   // Bottom-right
    glVertex3f(-0.3, -0.55, 3.0);  // Bottom-left
    glEnd();

    //front
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.65, 3.01); // Top-left
    glVertex3f(0.3, -0.65, 3.05);  // Top-right
    glVertex3f(0.3, -0.55, 3.05);   // Bottom-right
    glVertex3f(-0.3, -0.55, 3.05);  // Bottom-left
    glEnd();


    // left
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.65, 3.0); // Top-left
    glVertex3f(-0.3, -0.55, 3.0);  // Bottom-left
    glVertex3f(-0.3, -0.55, 3.05);  // Bottom-right
    glVertex3f(-0.3, -0.65, 3.05); // Top-right
    glEnd();


    //right
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.65, 3.0);  // Top-right
    glVertex3f(0.3, -0.55, 3.0);   // Bottom-right
    glVertex3f(0.3, -0.55, 3.05);  // Top-right
    glVertex3f(0.3, -0.65, 3.05);   // Bottom-right
    glEnd();

    //top
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.55, 3.0);  // Top-right
    glVertex3f(-0.3, -0.55, 3.05);   // Bottom-right
    glVertex3f(0.3, -0.55, 3.05);  // Top-right
    glVertex3f(0.3, -0.55, 3.0);   // Bottom-right
    glEnd();

    //Bottom
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.65, 3.0);  // Top-right
    glVertex3f(-0.3, -0.65, 3.05);   // Bottom-right
    glVertex3f(0.3, -0.65, 3.05);  // Top-right
    glVertex3f(0.3, -0.65, 3.0);   // Bottom-right
    glEnd();

    //////////////////////////////////////////////////////////////////////

    //  vertical left 
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.65, 3.0);  // Top-right
    glVertex3f(-0.1, -0.65, 3.0);  // Top-right
    glVertex3f(-0.1, -0.65, 3.05);   // Bottom-right
    glVertex3f(-0.2, -0.65, 3.05);   // Bottom-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.20, 3.0);  // Top-right
    glVertex3f(-0.1, -0.20, 3.0);  // Top-right
    glVertex3f(-0.1, -0.20, 3.05);   // Bottom-right
    glVertex3f(-0.2, -0.20, 3.05);   // Bottom-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.65, 3.0);  // Top-right
    glVertex3f(-0.2, -0.65, 3.05);   // Bottom-right
    glVertex3f(-0.2, -0.2, 3.05);   // Bottom-right
    glVertex3f(-0.2, -0.2, 3.0);  // Top-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1, -0.20, 3.05);   // Bottom-right
    glVertex3f(-0.2, -0.20, 3.05);   // Bottom-right
    glVertex3f(-0.2, -0.65, 3.05);
    glVertex3f(-0.1, -0.65, 3.05);   // Bottom-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1, -0.20, 3.0);
    glVertex3f(-0.2, -0.20, 3.0);
    glVertex3f(-0.2, -0.65, 3.0);
    glVertex3f(-0.1, -0.65, 3.0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1, -0.20, 3.0);
    glVertex3f(-0.1, -0.20, 3.05);
    glVertex3f(-0.1, -0.65, 3.05);
    glVertex3f(-0.1, -0.65, 3.0);
    glEnd();

    //////////////////////////////////////////////////
    // horizontal up
        //back
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.4, 3.0); // Top-left
    glVertex3f(0.3, -0.4, 3.0);  // Top-right
    glVertex3f(0.3, -0.3, 3.0);   // Bottom-right
    glVertex3f(-0.3, -0.3, 3.0);  // Bottom-left
    glEnd();

    //front
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.4, 3.1); // Top-left
    glVertex3f(0.3, -0.4, 3.1);  // Top-right
    glVertex3f(0.3, -0.3, 3.1);   // Bottom-right
    glVertex3f(-0.3, -0.3, 3.1);  // Bottom-left
    glEnd();

    // left
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.4, 3.0); // Top-left
    glVertex3f(-0.3, -0.3, 3.0);  // Bottom-left
    glVertex3f(-0.3, -0.3, 3.1);  // Bottom-right
    glVertex3f(-0.3, -0.4, 3.1); // Top-right
    glEnd();


    //right
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.4, 3.0);  // Top-right
    glVertex3f(0.3, -0.3, 3.0);   // Bottom-right
    glVertex3f(0.3, -0.3, 3.1);  // Top-right
    glVertex3f(0.3, -0.4, 3.1);   // Bottom-right
    glEnd();

    //top
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.3, 3.0);  // Top-right
    glVertex3f(-0.3, -0.3, 3.1);   // Bottom-right
    glVertex3f(0.3, -0.3, 3.1);  // Top-right
    glVertex3f(0.3, -0.3, 3.0);   // Bottom-right
    glEnd();

    //Bottom
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.4, 3.0);  // Top-right
    glVertex3f(-0.3, -0.4, 3.1);   // Bottom-right
    glVertex3f(0.3, -0.4, 3.1);  // Top-right
    glVertex3f(0.3, -0.4, 3.0);   // Bottom-right
    glEnd();

    /////////////////////////////////////////////////

    // vertical right
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, -0.65, 3.0);  // Top-right
    glVertex3f(0.18, -0.65, 3.0);  // Top-right
    glVertex3f(0.18, -0.65, 3.05);   // Bottom-right
    glVertex3f(0.25, -0.65, 3.05);   // Bottom-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, -0.15, 3.0);  // Top-right
    glVertex3f(0.18, -0.15, 3.0);  // Top-right
    glVertex3f(0.18, -0.15, 3.05);   // Bottom-right
    glVertex3f(0.25, -0.15, 3.05);   // Bottom-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, -0.65, 3.0);  // Top-right
    glVertex3f(0.25, -0.65, 3.05);   // Bottom-right
    glVertex3f(0.25, -0.15, 3.05);   // Bottom-right
    glVertex3f(0.25, -0.15, 3.0);  // Top-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.18, -0.15, 3.05);   // Bottom-right
    glVertex3f(0.25, -0.15, 3.05);   // Bottom-right
    glVertex3f(0.25, -0.65, 3.05);
    glVertex3f(0.18, -0.65, 3.05);   // Bottom-right
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.18, -0.15, 3.0);
    glVertex3f(0.25, -0.15, 3.0);
    glVertex3f(0.25, -0.65, 3.0);
    glVertex3f(0.18, -0.65, 3.0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.18, -0.15, 3.0);
    glVertex3f(0.18, -0.15, 3.05);
    glVertex3f(0.18, -0.65, 3.05);
    glVertex3f(0.18, -0.65, 3.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    //////////////////////////////////////////////////////
    // Define constants
    float circleRadius = 0.1; // Radius of the circle
    float circleThickness = 0.06; // Thickness of the circle
    float centerX = -0.15; // X-coordinate of the center
    float centerY = -0.75; // Y-coordinate of the center
    float centerZ = 3.03; // Z-coordinate of the center

    glColor3f(1.0, 0.0, 0.0);

    // Translate to the center position
    glTranslatef(centerX, centerY, centerZ); // Move the hinge back to its original position
    glRotatef(wheelLeftAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(BycAngle, 0.0f, 0.0f, 1.0f);

    // Draw the wheel rim as a 3D circle
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 36; ++i) {
        float theta = 2.0f * PI * float(i) / float(36);
        float x = circleRadius * cos(theta);
        float y = circleRadius * sin(theta);
        // Vertices on the top face of the circle
        glVertex3f(x, y, -circleThickness / 2.0);
        glVertex3f(x, y, circleThickness / 2.0);
    }
    glEnd();
    glBegin(GL_LINES);
    for (int i = 0; i <= 12; ++i) {
        float theta = 2.0f * PI * float(i) / float(12);
        float x = circleRadius * cos(theta);
        float y = circleRadius * sin(theta);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    glPopMatrix();

    ////////////////////////////////////////////////
    glPushMatrix();
    centerX = 0.15; // X-coordinate of the center

    glColor3f(1.0, 0.0, 0.0);
    // Translate to the center position
    glTranslatef(centerX, centerY, centerZ); // Move the hinge back to its original position
    glRotatef(wheelRightAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(BycAngle, 0.0f, 0.0f, 1.0f);


    // Draw the wheel rim as a 3D circle
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 36; ++i) {
        float theta = 2.0f * PI * float(i) / float(36);
        float x = circleRadius * cos(theta);
        float y = circleRadius * sin(theta);
        // Vertices on the top face of the circle
        glVertex3f(x, y, -circleThickness / 2.0);
        glVertex3f(x, y, circleThickness / 2.0);
    }
    glEnd();
    glBegin(GL_LINES);
    for (int i = 0; i <= 12; ++i) {
        float theta = 2.0f * PI * float(i) / float(12);
        float x = circleRadius * cos(theta);
        float y = circleRadius * sin(theta);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    glPopMatrix();
}

void DrawHome()
{
    // Back face
    glColor3f(1, 0, 1); // Green
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, -0.5); // Top-left
    glVertex3f(0.5, 0.8, -0.5);  // Top-right
    glVertex3f(0.5, -0.8, -0.5);   // Bottom-right
    glVertex3f(-0.5, -0.8, -0.5);  // Bottom-left
    glEnd();

    // Front face
    glColor3f(1, 0, 0); // Red
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, 0.5); // Top-left
    glVertex3f(0.5, 0.8, 0.5);  // Top-right
    glVertex3f(0.5, -0.8, 0.5); // Bottom-right
    glVertex3f(-0.5, -0.8, 0.5);  // Bottom-left
    glEnd();

    // Right face
    glColor3f(0, 0, 1); // Blue
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.8, -0.5);   // Top-front
    glVertex3f(0.5, -0.8, -0.5);  // Bottom-front
    glVertex3f(0.5, -0.8, 0.5);   // Bottom-back
    glVertex3f(0.5, 0.8, 0.5);    // Top-back
    glEnd();

    // Left face
    glColor3f(1, 1, 0); // Yellow
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, -0.5);  // Top-front
    glVertex3f(-0.5, -0.8, -0.5); // Bottom-front
    glVertex3f(-0.5, -0.8, 0.5);  // Bottom-back
    glVertex3f(-0.5, 0.8, 0.5);   // Top-back
    glEnd();

    // Top face
    glColor3f(1, 0, 1); // Magenta
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, 0.5);   // Front-left
    glVertex3f(0.5, 0.8, 0.5);    // Front-right
    glVertex3f(0.5, 0.8, -0.5);   // Back-right
    glVertex3f(-0.5, 0.8, -0.5);  // Back-left
    glEnd();
}
void DrawDoor()
{
    glTranslatef(0.2f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(doorAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(-0.2f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 1, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(-0.20, -0.1, 0); // Top-left
    glVertex3f(0.20, -0.1, 0);  // Top-right
    glVertex3f(0.20, -0.8, 0); // Bottom-right
    glVertex3f(-0.20, -0.8, 0);  // Bottom-left
    glEnd();

}
void DrawDoorShade() {
    // Draw shade behind the door
    glColor4f(0.1f, 0.1f, 0.1f, 0.5f); // Semi-transparent black
    glBegin(GL_POLYGON);
    glVertex3f(-0.20, -0.1, 0.50); // Top-left
    glVertex3f(0.20, -0.1, 0.50);  // Top-right
    glVertex3f(0.20, -0.8, 0.50); // Bottom-right
    glVertex3f(-0.20, -0.8, 0.50);  // Bottom-left
    glEnd();
}
void DrawBackground(double x, double y) {
    glPushMatrix();
    glColor4f(0.1f, 0.1f, 0.1f, 0.5f); // gray background color
    glBegin(GL_POLYGON);
    glVertex3f(0.2f * x, 0.1f + y, 0.5f); // Bottom-left
    glVertex3f(0.4f * x, 0.1f + y, 0.5f); // Bottom-right
    glVertex3f(0.4f * x, 0.3f + y, 0.5f); // Top-right
    glVertex3f(0.2f * x, 0.3f + y, 0.5f); // Top-left
    glEnd();
    glPopMatrix();
}
void DrawFirstWindowFirstPart() {
    glPushMatrix();
    glTranslatef(0.4f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(-0.4f, 0, 0); // Move the hinge back to its original position
    glColor3f(1, 1, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 0.1, 0); // Top-left
    glVertex3f(0.3, 0.1, 0);  // Top-right
    glVertex3f(0.3, 0.3, 0); // Bottom-right
    glVertex3f(0.4, 0.3, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawFirstWindowSecondPart() {

    glPushMatrix();
    glTranslatef(0.2f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(-0.2f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 0, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.1, 0); // Top-left
    glVertex3f(0.3, 0.1, 0);  // Top-right
    glVertex3f(0.3, 0.3, 0); // Bottom-right
    glVertex3f(0.2, 0.3, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawSecondWindowFirstPart() {
    glPushMatrix();
    glTranslatef(-0.4f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(0.4f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 1, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.1, 0); // Top-left
    glVertex3f(-0.3, 0.1, 0);  // Top-right
    glVertex3f(-0.3, 0.3, 0); // Bottom-right
    glVertex3f(-0.4, 0.3, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawSecondWindowSecondPart() {
    glPushMatrix();
    glTranslatef(-0.2f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(0.2f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 0, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, 0.1, 0); // Top-left
    glVertex3f(-0.3, 0.1, 0);  // Top-right
    glVertex3f(-0.3, 0.3, 0); // Bottom-right
    glVertex3f(-0.2, 0.3, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawThirdWindowFirstPart() {
    glPushMatrix();
    glTranslatef(0.4f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(-0.4f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 1, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 0.4, 0); // Top-left
    glVertex3f(0.3, 0.4, 0);  // Top-right
    glVertex3f(0.3, 0.6, 0); // Bottom-right
    glVertex3f(0.4, 0.6, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawThirdWindowSecondPart() {
    glPushMatrix();
    glTranslatef(0.2f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(-0.2f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 0, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.4, 0); // Top-left
    glVertex3f(0.3, 0.4, 0);  // Top-right
    glVertex3f(0.3, 0.6, 0); // Bottom-right
    glVertex3f(0.2, 0.6, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawFourthWindowFirstPart() {
    glPushMatrix();
    glTranslatef(-0.4f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(0.4f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 1, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.4, 0); // Top-left
    glVertex3f(-0.3, 0.4, 0);  // Top-right
    glVertex3f(-0.3, 0.6, 0); // Bottom-right
    glVertex3f(-0.4, 0.6, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawFourthWindowSecondPart() {
    glPushMatrix();
    glTranslatef(-0.2f, 0, 0.51f); // Move the hinge to the origin
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(0.2f, 0, 0); // Move the hinge back to its original position
    // Door
    glColor3f(1, 0, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, 0.4, 0); // Top-left
    glVertex3f(-0.3, 0.4, 0);  // Top-right
    glVertex3f(-0.3, 0.6, 0); // Bottom-right
    glVertex3f(-0.2, 0.6, 0);  // Bottom-left
    glEnd();
    glPopMatrix();
}
void DrawWindow() {
    // first window
    DrawBackground(1, 0);
    DrawFirstWindowFirstPart();
    DrawFirstWindowSecondPart();

    // second window
    DrawBackground(-1, 0);
    DrawSecondWindowFirstPart();
    DrawSecondWindowSecondPart();

    // third window
    DrawBackground(1, 0.3);
    DrawThirdWindowFirstPart();
    DrawThirdWindowSecondPart();

    // fourth window
    DrawBackground(-1, 0.3);
    DrawFourthWindowFirstPart();
    DrawFourthWindowSecondPart();
}



void DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
    glTranslated(0, 0, -3);
    // Draw the ground
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for the ground
    glBegin(GL_QUADS);
    glVertex3f(-5, -0.9, 5);
    glVertex3f(5, -0.9, 5);
    glVertex3f(5, -0.9, -5);
    glVertex3f(-5, -0.9, -5);
    glEnd();
    DrawHome();
    glPushMatrix();
    DrawWindow();
    glPopMatrix();
    glPushMatrix();
    DrawDoorShade();
    DrawDoor();
    glPopMatrix();
    glPushMatrix();
    DrawByc();
    glPopMatrix();
    glFlush();
}

UINT_PTR timerId1;
LRESULT WINAPI  WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
    static PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd  
        1,                     // version number  
        PFD_DRAW_TO_WINDOW |   // support window  
        PFD_SUPPORT_OPENGL |   // support OpenGL  
        PFD_DOUBLEBUFFER,      // double buffered  
        PFD_TYPE_RGBA,         // RGBA type  
        24,                    // 24-bit color depth  
        0, 0, 0, 0, 0, 0,      // color bits ignored  
        0,                     // no alpha buffer  
        0,                     // shift bit ignored  
        0,                     // no accumulation buffer  
        0, 0, 0, 0,            // accum bits ignored  
        32,                    // 32-bit z-buffer  
        0,                     // no stencil buffer  
        0,                     // no auxiliary buffer  
        PFD_MAIN_PLANE,        // main layer  
        0,                     // reserved  
        0, 0, 0                // layer masks ignored  
    };
    static HDC hdc;
    static HGLRC hgl;
    static int w, h;
    int  iPixelFormat;
    bool Animation = true;
    
    switch (m)
    {
    
    case WM_CREATE:
        hdc = GetDC(hwnd);
        iPixelFormat = ChoosePixelFormat(hdc, &pfd);
        SetPixelFormat(hdc, iPixelFormat, &pfd);
        hgl = wglCreateContext(hdc);
        wglMakeCurrent(hdc, hgl);
        glClearColor(0, 1, 0, 0);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        break;
    case WM_SIZE:
        w = LOWORD(lp);
        h = HIWORD(lp);
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f); // Adjust perspective
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glFlush();
        SwapBuffers(hdc);
        break;

    case WM_KEYDOWN:
        switch (wp) {
        case 'F':
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CAPITAL) & 0x0001)) // Move camera forward (zoom in)
            {
                cameraZ -= 0.1f;
            }
            else {
                translateByc += 0.2;
                BycAngle += 60.0;
            }
            break;
        case 'B':
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CAPITAL) & 0x0001)) // Move camera backward (zoom out)
            {
               cameraZ += 0.1f;
            }
            else {
                translateByc -= 0.2;
                BycAngle -= 60.0;
            }
            break;
        case 'L':
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CAPITAL) & 0x0001)) // Move camera left
            {
                cameraX -= 0.1f;
            }
            else { // rotate left wheel
                wheelLeftAngle = 30.0;
            }
            break;
        case 'R':
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CAPITAL) & 0x0001)) // Move camera right
            {
                cameraX += 0.1f;
            }
            else { // rotate right wheel
                wheelRightAngle = 30.0;
            }
            break;

        case 'U': // Move camera up
            cameraY += 0.1f;
            break;
        case 'D': // Move camera down
            cameraY -= 0.1f;
            break;
        case 'O':
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CAPITAL) & 0x0001)) // open window
            {
                windowAngle = 120.0f;
            }
            else { // open door
                doorAngle = 120.0f;
            }
            break;
        case 'C':
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CAPITAL) & 0x0001)) // close window
            {
                windowAngle = 0.0f;
            }
            else { // close door
                doorAngle = 0.0f;
            }
            break;

        }
        DrawScene();
        SwapBuffers(hdc);
        break;
    case WM_TIMER:
        if (timerId1) {
            wheelAngle += 10.0;
            if (wheelAngle >= 360.0)
                wheelAngle -= 360.0;
        }
        DrawScene();
        SwapBuffers(hdc);
        break;
    case WM_LBUTTONDOWN:
        timerId1 = SetTimer(hwnd, 1, 60, NULL);
        break;

    case WM_RBUTTONDOWN:
        KillTimer(hwnd ,1);
        timerId1 = NULL;
        break;
    case WM_DESTROY:
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(hgl);
        ReleaseDC(hwnd, hdc);
        KillTimer(hwnd, 2);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, m, wp, lp);
    }
    return 0;
}


int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR c, int ns)
{
    WNDCLASS wc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hInstance = hi;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = L"MyClass";
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(L"MyClass", L"3D Graphics Scene", WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hi, 0);
    ShowWindow(hwnd, ns);
    UpdateWindow(hwnd);
    SetTimer(hwnd, 2, 60, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

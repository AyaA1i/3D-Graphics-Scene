#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

GLfloat doorAngle = 0.0f;
GLfloat windowAngle = 0.0f;
float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f;
void DrawByc() {

    // first part (المكعب الاول النايم )
    //back
    glColor3f(1, 0, 1); 
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.8, 3.0); // Top-left
    glVertex3f(0.2, -0.8, 3.0);  // Top-right
    glVertex3f(0.2, -0.7 ,3.0 );   // Bottom-right
    glVertex3f(-0.2, -0.7,3.0);  // Bottom-left
    glEnd();

    //front
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.8, 3.1); // Top-left
    glVertex3f(0.2, -0.8, 3.1);  // Top-right
    glVertex3f(0.2, -0.7, 3.1);   // Bottom-right
    glVertex3f(-0.2, -0.7,3.1);  // Bottom-left
    glEnd();


    // left
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.8, 3.0); // Top-left
    glVertex3f(-0.2, -0.7, 3.0);  // Bottom-left
    glVertex3f(-0.2, -0.7, 3.1);  // Bottom-right
    glVertex3f(-0.2, -0.8, 3.1); // Top-right
    glEnd();


    //right
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.2, -0.8, 3.0);  // Top-right
    glVertex3f(0.2, -0.7, 3.0);   // Bottom-right
    glVertex3f(0.2, -0.7, 3.1);  // Top-right
    glVertex3f(0.2, -0.8, 3.1);   // Bottom-right
    glEnd();

    //top
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.7, 3.0);  // Top-right
    glVertex3f(-0.2, -0.7, 3.1);   // Bottom-right
    glVertex3f(0.2, -0.7, 3.1);  // Top-right
    glVertex3f(0.2, -0.7, 3.0);   // Bottom-right
    glEnd();

    //Bottom
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.8, 3.0);  // Top-right
    glVertex3f(-0.2, -0.8, 3.1);   // Bottom-right
    glVertex3f(0.2, -0.8, 3.1);  // Top-right
    glVertex3f(0.2, -0.8, 3.0);   // Bottom-right
    glEnd();



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
void DrawBackground(double x , double y) {
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
    DrawBackground(1, 0 ); 
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

LRESULT WINAPI WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
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
        case 'C': // Move camera left
            cameraX -= 0.1f;
            break;
        case 'D': // Move camera right
            cameraX += 0.1f;
            break;
        case 'W': // Move camera up
            cameraY += 0.1f;
            break;
        case 'S': // Move camera down
            cameraY -= 0.1f;
        break;        
        case 'Q': // Move camera backward (zoom out)
            cameraZ -= 0.1f;
            break;
        case 'E': // Move camera forward (zoom in)
            cameraZ += 0.1f;
            break;
        }
        break;
    case WM_PAINT:

        if (GetAsyncKeyState('X') & 0x8000) {
            doorAngle = 120.0f;
        }
        else if (GetAsyncKeyState('Y') & 0x8000) {
            doorAngle = 0.0f;
        }
        else if (GetAsyncKeyState('A') & 0x8000) {
            windowAngle = 120.0f;
        }
        else if (GetAsyncKeyState('B') & 0x8000) {
            windowAngle = 0.0f;
        }
        DrawScene();
        SwapBuffers(hdc);
        break;
    case WM_DESTROY:
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(hgl);
        ReleaseDC(hwnd, hdc);
        PostQuitMessage(0);
        break;
    

    default:
        return DefWindowProc(hwnd, m, wp, lp);
    }

    // Fix 


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
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

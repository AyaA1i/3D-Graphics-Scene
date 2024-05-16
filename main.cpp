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
void DrawCuboid(float width, float height, float depth, float r, float g, float b, float a);
void DrawWheel(float centerX , float wheelAngle) {
    glPushMatrix();
    float circleRadius = 0.1; 
    float circleThickness = 0.04; 
    float centerY = -0.75;
    float centerZ = 3.05; 

    glColor3f(0,0,0);
    glTranslatef(centerX, centerY, centerZ); 
    glRotatef(wheelAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(BycAngle, 0.0f, 0.0f, 1.0f);
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
void DrawByc() {
    glTranslatef(translateByc, 0, 0);
    glRotatef(wheelAngle, 0.0, 1.0, 0.0);

    glPushMatrix();
    // horizontal down
    glPushMatrix();
    glTranslatef(0.0f, -0.75f, 3.05f);
    DrawCuboid(0.6, 0.02, 0.05, 0, 0, 0, 0);
    glPopMatrix();
    //  vertical left 
    glPushMatrix();
    glTranslatef(-0.1f, -0.6f, 3.05f);
    DrawCuboid(0.02, 0.3, 0.05, 0, 0, 0, 0);
    glPopMatrix();

    // horizontal up
    glPushMatrix();
    glTranslatef(0.0f, -0.54f, 3.05f);
    DrawCuboid(0.5, 0.05, 0.05, 0, 0, 0, 0);
    glPopMatrix();

    // vertical right
    glPushMatrix();
    glTranslatef(0.2f, -0.53f, 3.05f);
    DrawCuboid(0.05, 0.45, 0.05, 0, 0, 0, 0);
    glPopMatrix();

    //wheels
    DrawWheel(-0.4 , wheelLeftAngle);
    DrawWheel(0.4 , wheelRightAngle);

    // hand
    glPushMatrix();
    glTranslatef(0.2f, -0.33f, 3.05f);
    DrawCuboid(0.05, 0.05, 0.2, 0.5, 0.4, 0.3, 0.5);
    glPopMatrix();

   
}
void DrawCuboid(float width, float height, float depth, float r, float g, float b, float a);
void DrawHome()
{
    glColor3f(1, 1, 1); 
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, -0.5); 
    glVertex3f(0.5, 0.8, -0.5);  
    glVertex3f(0.5, -0.8, -0.5);   
    glVertex3f(-0.5, -0.8, -0.5); 
    glEnd();

    
    glColor3f(1, 1, 1); 
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, 0.5); 
    glVertex3f(0.5, 0.8, 0.5);  
    glVertex3f(0.5, -0.8, 0.5); 
    glVertex3f(-0.5, -0.8, 0.5); 
    glEnd();

    
    glColor3f(1, 1, 1); 
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.8, -0.5);   
    glVertex3f(0.5, -0.8, -0.5);  
    glVertex3f(0.5, -0.8, 0.5);   
    glVertex3f(0.5, 0.8, 0.5);    
    glEnd();

   
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.8, -0.5);  
    glVertex3f(-0.5, -0.8, -0.5);
    glVertex3f(-0.5, -0.8, 0.5);  
    glVertex3f(-0.5, 0.8, 0.5);   
    glEnd();

   
    glColor4f(0.8f, 0.6f, 0.4f, 0.5f); 
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.7, 0.5);   
    glVertex3f(0.5, 0.7, 0.5);    
    glVertex3f(0.5, 0.7, -0.5);   
    glVertex3f(-0.5, 0.7, -0.5);  
    glEnd();
}
void DrawDoor()
{
    glTranslatef((0.4f / 2), -0.45, 0.5f); 
    glRotatef(doorAngle, 0.0f, 1.0f, 0.0f); 
    glTranslatef(-(0.4f / 2), 0, 0);
    DrawCuboid(0.4, 0.7, 0.05, 0.3f, 0.2f, 0.1f, 0.5f);

}
void DrawDoorShade() {
    glPushMatrix();
    glTranslatef(0, -0.45,0.26);
    DrawCuboid(0.4, 0.7, 0.5, 0, 0, 0, 0);
    glPopMatrix();
}


void DrawCuboid(float width, float height, float depth , float r , float g , float b , float a)
{
    float w = width / 2.0f;
    float h = height / 2.0f;
    float d = depth / 2.0f;

    glPushMatrix();
    glBegin(GL_QUADS);
    // Front face
    glColor4f(r, g, b, a);
    glVertex3f(-w, -h, d);
    glVertex3f(w, -h, d);
    glVertex3f(w, h, d);
    glVertex3f(-w, h, d);

    // Back face
    // 
    glColor4f(r + 0.5f,g + 0.4f, b + 0.3f, 0.5f);
    glVertex3f(-w, -h, -d);
    glVertex3f(-w, h, -d);
    glVertex3f(w, h, -d);
    glVertex3f(w, -h, -d);

    // Left face
    glColor4f(r, g, b, a);
    glVertex3f(-w, -h, -d);
    glVertex3f(-w, -h, d);
    glVertex3f(-w, h, d);
    glVertex3f(-w, h, -d);

    // Right face
    glColor4f(r, g, b, a);
    glVertex3f(w, -h, -d);
    glVertex3f(w, h, -d);
    glVertex3f(w, h, d);
    glVertex3f(w, -h, d);

    // Top face
    glColor4f(r, g, b, a);
    glVertex3f(-w, h, -d);
    glVertex3f(-w, h, d);
    glVertex3f(w, h, d);
    glVertex3f(w, h, -d);

    // Bottom face
    glColor4f(r, g, b, a);
    glVertex3f(-w, -h, -d);
    glVertex3f(w, -h, -d);
    glVertex3f(w, -h, d);
    glVertex3f(-w, -h, d);

    glEnd();
    glPopMatrix();
}


void DrawBackground(float tx, float ty, float tz){
    glPushMatrix();
    glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
    glTranslated(tx, ty, tz-0.11);
    DrawCuboid(0.1, 0.2, 0.02, 0, 0, 0, 0);
    glPopMatrix();
}

void DrawWindow() {
    glPushMatrix();
    glTranslated(-0.35, 0.5, 0.51);
    glRotatef(windowAngle * -1, 0.0f, 1.0f, 0.0f);
    glTranslated((0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    DrawBackground( -0.3, 0.5, 0.61);
    glPushMatrix();
    glTranslated(-0.15, 0.5, 0.51);
    glRotatef(windowAngle , 0.0f, 1.0f, 0.0f);
    glTranslated(-(0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    DrawBackground( -0.2, 0.5, 0.61);
    glPushMatrix();
    glTranslated(0.35, 0.5, 0.51);
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);
    glTranslated(-(0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    DrawBackground( 0.3, 0.5, 0.61);
    DrawBackground( 0.2, 0.5, 0.61);
    glPushMatrix();
    glTranslated(0.15, 0.5, 0.51);
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f);
    glTranslated((0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.35, 0.2, 0.51);
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);
    glTranslated(-(0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    DrawBackground(0.3, 0.2, 0.61);
    glPushMatrix();
    glTranslated(0.15, 0.2, 0.51);
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f);
    glTranslated((0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    DrawBackground( 0.2, 0.2, 0.61);
    glPushMatrix();
    glTranslated(-0.35, 0.2, 0.51);
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f);
    glTranslated((0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
    DrawBackground(-0.3, 0.2, 0.61);
    DrawBackground( -0.2, 0.2, 0.61);
    glPushMatrix();
    glTranslated(-0.15, 0.2, 0.51);
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);
    glTranslated(-(0.1 / 2), 0, 0);
    DrawCuboid(0.1, 0.2, 0.02, 0.3f, 0.2f, 0.1f, 0.5f);
    glPopMatrix();
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
    glColor3f(0.5f, 0.5f, 0.5f);
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
        gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f); 
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
            wheelAngle += 5.0;
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



#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

GLfloat doorAngle = 0.0f; // Initial angle of the door

void DrawHome()
{
    glMatrixMode(GL_MODELVIEW);
    glTranslated(0, 0, -3);

    // Back face
    glColor3f(0, 1, 0); // Green
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
    // Rotate the door around its hinge
    glTranslatef(0.0f, -0.45f, 0.51f); // Move the hinge to the origin
    glRotated(doorAngle, 0.0f, 1.0f, 0.0f); // Rotate the door around the y-axis (hinge)
    glTranslatef(0.0f, 0.45f, -0.51f); // Move the hinge back to its original position
    // Door
    glColor3f(1, 1, 1); // white
    glBegin(GL_POLYGON);
    glVertex3f(-0.20, -0.1, 0.51); // Top-left
    glVertex3f(0.20, -0.1, 0.51);  // Top-right
    glVertex3f(0.20, -0.8, 0.51); // Bottom-right
    glVertex3f(-0.20, -0.8, 0.51);  // Bottom-left
    glEnd();

}

void DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DrawHome();
    glPushMatrix();
    DrawDoor();
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
        glClearColor(0, 0, 0, 0);
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        break;
    case WM_SIZE:
        w = LOWORD(lp);
        h = HIWORD(lp);
        glViewport(0, 0, w, h);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glFlush();
        SwapBuffers(hdc);
        break;
    case WM_PAINT:
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
        if (msg.message == WM_KEYDOWN) {
            if (msg.wParam == 'o') {
                doorAngle += 10.0f;
                DrawScene();
            }
            else if (msg.wParam == 'O') {
                doorAngle -= 10.0f;
                DrawScene();
            }
        }
    }
    return 0;
}

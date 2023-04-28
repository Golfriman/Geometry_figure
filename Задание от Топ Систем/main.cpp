// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <windowsx.h>
#include "Scene.h"
#include "ButtonHandler.h"
#include "LineEditHandler.h"
#include "Factory/ClearFactory.h"
#include "Mediator.h"

static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("Тестовое задание от Топ систем");

HINSTANCE hInst;
HWND hWndRed;
HWND hWndGreen;
HWND hWndBlue;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


void             CreateButtons(HWND);



int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_PARENTDC;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

 
    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    CreateButtons(hWnd);

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    static Scene* scene;
    static Factory* factory;
    static Mediator mediator;
    static LineEditHandler lineEditHandler;
    
   
    switch (message)
    {
    case WM_COMMAND:
    {
        int idCommand = LOWORD(wParam);

        ButtonHandler buttonHandler;
        Command* command = buttonHandler.handleInput(idCommand);

        if (command!= nullptr)
        {
            if (factory != nullptr)
            {
                delete factory;
                factory = nullptr;
            }
            factory = command->execute();
            if (ClearFactory* f = dynamic_cast<ClearFactory*>(factory); f != nullptr)
            {
                scene->clear();
                delete factory;
                factory = nullptr;
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
            }
            delete command;
            break;
        }

        
        int color = lineEditHandler.execute(idCommand);
        if (color == -1)
            break;
        mediator.changeColor(static_cast<sh::Shape::Color>(color));
        

        break;
    }
    case WM_LBUTTONDOWN:
    {
        if (factory == nullptr)
            break;
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        if (factory->buildShape(x, y))
        {
            auto build = factory->endBuild();
            build->setHPEN(mediator.buildPen());
            scene->addShape(build);
            delete factory;
            factory = nullptr;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }
    case WM_MOUSEMOVE:
    {
        if (factory == nullptr)
            break;
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        auto build = factory->tempBuild(x, y);
        if (build == nullptr)
            break;
        build->setHPEN(mediator.buildPen());
        scene->addTempShape(build);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    case WM_CREATE:
        scene = new Scene();
        lineEditHandler.init(hWnd, hInst, 100, 0);
        break;
    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        HDC memDC = CreateCompatibleDC(hdc);

        RECT rcClientRectangle;
        GetClientRect(hWnd, &rcClientRectangle);

        HBITMAP bmp = CreateCompatibleBitmap(hdc,
            rcClientRectangle.right - rcClientRectangle.left,
            rcClientRectangle.bottom - rcClientRectangle.top);
        HBITMAP oldBmp = (HBITMAP)SelectObject(memDC, bmp);
        FillRect(memDC, &rcClientRectangle, CreateSolidBrush(sh::Shape::White));
        scene->draw(memDC);
        scene->drawTempShape(memDC);
        BitBlt(hdc, 0, 0, rcClientRectangle.right - rcClientRectangle.left,
            rcClientRectangle.bottom - rcClientRectangle.top, memDC, 0, 0, SRCCOPY);
        SelectObject(memDC, oldBmp);
        DeleteObject(bmp);
        DeleteObject(memDC);

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_ERASEBKGND:
        return true;
    case WM_DESTROY:
        PostQuitMessage(0);
        delete scene;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}

void CreateButtons(HWND hWndParent)
{
    //CIRCLE
    CreateWindow(
        L"BUTTON",
        L"○",
        WS_VISIBLE|WS_CHILD,
        0, 0, 20, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ButtonHandler::ID_Figure_Button::IDM_BUTTON1),
        hInst,
        NULL
        );
    //LINE
    CreateWindow(
        L"BUTTON",
        L"\\",
        WS_VISIBLE | WS_CHILD,
        20, 0, 20, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ButtonHandler::ID_Figure_Button::IDM_BUTTON2),
        hInst,
        NULL
    );
    //BOX
    CreateWindow(
        L"BUTTON",
        L"□", 
        WS_VISIBLE | WS_CHILD,
        40, 0, 20, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ButtonHandler::ID_Figure_Button::IDM_BUTTON3),
        hInst,
        NULL
    );
    CreateWindow(
        L"BUTTON",
        L"⎔",
        WS_VISIBLE | WS_CHILD,
        60, 0, 20, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ButtonHandler::ID_Figure_Button::IDM_BUTTON4),
        hInst,
        NULL
    ); 
    CreateWindow(
        L"BUTTON",
        L"◧",
        WS_VISIBLE | WS_CHILD,
        80, 0, 20, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ButtonHandler::ID_Figure_Button::IDM_BUTTON5),
        hInst,
        NULL
    );
    
}

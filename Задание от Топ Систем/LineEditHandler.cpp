#include "LineEditHandler.h"

void LineEditHandler::init(HWND hWndParent, HINSTANCE hInst, int x, int y)
{
    auto hWndLabel = CreateWindow(
        L"static",
        L"Color: ",
        WS_CHILD | WS_VISIBLE,
        x, 0, 50, 20,
        hWndParent,
        NULL,
        hInst,
        NULL
    );
    hWndRed = CreateWindow(
        L"Edit",
        L"0",
        ES_NUMBER | WS_VISIBLE | WS_CHILD | WS_BORDER,
        x+50, 0, 30, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ID_RED),
        hInst,
        NULL);
    hWndGreen = CreateWindow(
        L"Edit",
        L"0",
        ES_NUMBER | WS_VISIBLE | WS_CHILD | WS_BORDER,
        x+80, 0, 30, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ID_GREEN),
        hInst,
        NULL);
    hWndBlue = CreateWindow(
        L"Edit",
        L"0",
        ES_NUMBER | WS_VISIBLE | WS_CHILD | WS_BORDER,
        x+110, 0, 30, 20,
        hWndParent,
        reinterpret_cast<HMENU>(ID_BLUE),
        hInst,
        NULL);
}

int LineEditHandler::execute(int idCommand)
{
    const int SIZE_BUFFER = 4;
    char red[SIZE_BUFFER];
    char green[SIZE_BUFFER];
    char blue[SIZE_BUFFER];
    switch (idCommand)
    {
    case ID_RED:
    {
        GetWindowTextA(hWndRed, red, SIZE_BUFFER);
        GetWindowTextA(hWndGreen, green, SIZE_BUFFER);
        GetWindowTextA(hWndBlue, blue, SIZE_BUFFER);
        break;
    }
    case ID_GREEN:
    {
        GetWindowTextA(hWndRed, red, SIZE_BUFFER);
        GetWindowTextA(hWndGreen, green, SIZE_BUFFER);
        GetWindowTextA(hWndBlue, blue, SIZE_BUFFER);
        break;
    }
    case ID_BLUE:
    {

        GetWindowTextA(hWndRed, red, SIZE_BUFFER);
        GetWindowTextA(hWndGreen, green, SIZE_BUFFER);
        GetWindowTextA(hWndBlue, blue, SIZE_BUFFER);
        break;
    }
    default:
        return -1;
    }
    return RGB(atoi(red), atoi(green), atoi(blue));
}

﻿#include "WinApi_DefenseWall.h"
#include "stdfx.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;                         
HWND g_hWnd;
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];            

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

/* GDI 관련 */
#include <objidl.h>
#include <gdiplus.h>
#pragma comment(lib,"Gdiplus.lib")
using namespace Gdiplus;
ULONG_PTR g_GdiToken;
void Gdi_Init();
void Gdi_Draw(HDC hdc);
void Gdi_End();


/* Console 출력 */
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

/* Main */
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, /* 프로세스의 메모리 시작 주소 (프로그램을 메모리 공간에 올림) */ 
                     _In_opt_ HINSTANCE hPrevInstance, /* 무시 (창을 2개 이상 띄우지 않는 이상 중요 X) */
                     _In_ LPWSTR    lpCmdLine, /* 무시 (cmd관련) */
                     _In_ int       nCmdShow) /* 무시 (cmd관련) */
{   
    /* 무시 */
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    /* 프로젝트 기본 세팅(창에 띄울 제목, 코드에서 사용할 창의 제목, 창 등록 등) */
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); /* IDS_APP_TITLE에 해당하는 문자열을(Resource.h - String Table)에서 가지고 와서 배열에 szTitle 배열에 저장*/
    LoadStringW(hInstance, IDC_WINAPIDEFENSEWALL, szWindowClass, MAX_LOADSTRING);

    CObjectManager::Get_Instance()->Init(); 
    /* 이 위치가 맞나 ? 근데 일단  MyRegisterClass(hInstance); 이거는 바로 Paint 함수로 넘어가서.. */

    /* 윈도우(창) 정보 등록 */
    MyRegisterClass(hInstance); 

    /* 윈도우(창) 생성 */
    /*
    주의! Window(창)를 Process라고 생각하면 안 됨 Process는 Window를 가질 수도 안 가질 수도 있음 (Process와 User사이의 매개체로 Window를 사용할지는 선택)
    */
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    
    /* 무시 */
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIDEFENSEWALL));


    MSG msg;
    ///* 발생한 메시지(이벤트)가 있다면 가져온다, 즉 발생한 메시지가 없다면 무한 대기 */    
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) /* 메시지가 발생한 윈도우(창), 무시. 메시지 구조체*/
    //    {
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
    //    }
    //}

    //return (int) msg.wParam;

    Gdi_Init();
    while (true) // 메시지 발생 유무에 관계없이 돌리겠다
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // 메시지가 발생하지 않았다면
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* 더블 버퍼링 구현시 false로 세팅 */
            InvalidateRect(g_hWnd, nullptr, false);
        }
    }
    Gdi_End();

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    /* 구조체 선언 후, 구조체 멤버들을 채움 */

    WNDCLASSEXW wcex; 

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIDEFENSEWALL));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPIDEFENSEWALL);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex); /* 구조체를 윈도우 내장 함수(함수 내부는 볼 수 없음)로 보내 리턴 받은 값을 리턴 */
}

/* 이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고 주 프로그램창을 만든 다음 표시*/
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   g_hWnd = hWnd;

   return TRUE;
}

/* 이벤트가 발생된다면 호출 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {

        SetTimer(hWnd, 1, 50, NULL);
    }
        break;
    case WM_TIMER:
        if (wParam == 1)
        {

            CObjectManager::Get_Instance()->Update(); // 포지션 업데이트
        }

        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            /* Double Buffering */
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps); // 도구를 쓰는 손
            HDC hdc2 = CreateCompatibleDC(hdc); // 왼손

            HBITMAP Buffer = CreateBitmap(WINDOW_WIDTH,WINDOW_HEIGHT, 1, 32, NULL); // 도화지 버퍼 생성
            
            SelectObject(hdc2, Buffer); // hdc2로 buffer에 그림 (렌더 함수에 반영)
            ExtFloodFill(hdc2, 0, 0, RGB(0, 0, 0), FLOODFILLSURFACE);

            CObjectManager::Get_Instance()->Render(hdc2);

            BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc2, 0, 0, SRCCOPY);

            DeleteObject(Buffer);
            DeleteDC(hdc2);
 
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        KillTimer(hWnd, 1);

        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void Gdi_Init()
{
    GdiplusStartupInput gpsi;
    GdiplusStartup(&g_GdiToken, &gpsi, NULL);
}

void Gdi_End()
{
    GdiplusShutdown(g_GdiToken);
}
#include "WinApi_DefenseWall.h"
#include "stdfx.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];            

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIDEFENSEWALL));

    MSG msg;

    CObjectManager::Get_Instance()->Init();

    // 프로그램 내내 여기가 계속 반복됨
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
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

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
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
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            CObjectManager::Get_Instance()->Render(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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

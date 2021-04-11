#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#define STRICT
#include <windows.h>
#include <windowsx.h> //"message crackers"
#include <commctrl.h> //for InitCommonControls()
#include <stdlib.h>
#include <time.h> //for srand()

#define ID_BTSTART 101
#define ID_BTSTOP 102

HINSTANCE hInstance;
HWND hForm, hFocus, hBtStart, hBtStop;

//external functions
//void (*ComplexFillArray)(DWORD *Colors, int nColors, DWORD *ColorArray, int *nColorArray);
typedef void (*ComplexFillArrayFunc)(DWORD *Colors, int nColors, DWORD *ColorArray, int *nColorArray);
ComplexFillArrayFunc ComplexFillArray;
//void (*demo)(HWND hwnd, DWORD *ColorArray, int nColorArray);
typedef void (*DemoFunc)(HWND hwnd, DWORD *ColorArray, int nColorArray);
DemoFunc demo;
//int (*stop)(void);
typedef int (*StopFunc)(void);
StopFunc stop;

//forward declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Cls_OnCommand(HWND, int, HWND, UINT);
BOOL Cls_OnCreate(HWND, LPCREATESTRUCT);
void Cls_OnDestroy(HWND);
void BtStart_OnClick(HWND);
void BtStop_OnClick(HWND);
void DynLoad(void);
void DrawElls(void);

/*** GUI implementation ***/

void werror(LPCTSTR Title)
{
	LPTSTR Buf;
	if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL, GetLastError(), 0, (LPTSTR) &Buf, 0, NULL)) return;
	MessageBox(NULL, Buf, Title, MB_ICONERROR);
	LocalFree(Buf);
}

//program entry-point
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG Msg; WNDCLASS WndClass;
	hInstance = hInst;
	//register class of main window
	WndClass.style = 0;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(hInstance, "MAINICON");//(char *) 101);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 11);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = "ells";
	RegisterClass(&WndClass);

	//create main window (Cls_OnCreate executes during CreateWindow)
	hForm = CreateWindow(WndClass.lpszClassName, "Ellipses", WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
						NULL, NULL, hInstance, NULL);
	ShowWindow(hForm, nCmdShow);
	UpdateWindow(hForm);

	//message loop
	while (GetMessage(&Msg, NULL, 0, 0))
	if (!IsDialogMessage(hForm, &Msg))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

//window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) { //process messages
		HANDLE_MSG(hwnd, WM_CREATE, Cls_OnCreate);
		HANDLE_MSG(hwnd, WM_DESTROY, Cls_OnDestroy);
		HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
	default: //all other messages processed by default function
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}

//button click events
void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id) {
	case ID_BTSTART: if (codeNotify == BN_CLICKED)
		BtStart_OnClick(hwnd);
		break;
	case ID_BTSTOP: if (codeNotify == BN_CLICKED)
		BtStop_OnClick(hwnd);
		break;
	}
}

BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
	HFONT hFont = (HFONT)GetStockObject(ANSI_VAR_FONT); hFocus = 0;
	InitCommonControls(); //for Windows XP theme
	//create controls
	hBtStart = CreateWindowEx(WS_EX_WINDOWEDGE, "Button", "Start", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
							10, 10, 75, 25, hwnd, (HMENU)ID_BTSTART, hInstance, NULL);
	SendMessage(hBtStart, WM_SETFONT, (WPARAM)hFont, 0); SetFocus(hBtStart);
	hBtStop = CreateWindowEx(WS_EX_WINDOWEDGE, "Button", "Stop", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
							90, 10, 75, 25, hwnd, (HMENU)ID_BTSTOP, hInstance, NULL);
	SendMessage(hBtStop, WM_SETFONT, (WPARAM)hFont, 0);
	srand((unsigned)time(NULL));
	return TRUE;
}

void Cls_OnDestroy(HWND hWnd)
{
	PostQuitMessage(0);
}

void BtStart_OnClick(HWND hwnd)
{
	DynLoad();
}

void BtStop_OnClick(HWND hwnd)
{
	if (stop) //if library loaded and function found
		stop();
}

/*** DLL support ***/

//dynamically load external dynamically library with drawing functions
void DynLoad(void)
{
	HMODULE hModule = LoadLibrary("ells.dll");
	if (hModule)
	{
		ComplexFillArray = (ComplexFillArrayFunc)GetProcAddress(hModule, "ComplexFillArray");
		if (!ComplexFillArray)
			werror("GetProcAddress(ComplexFillArray)");
		demo = (DemoFunc)GetProcAddress(hModule, "demo");
		if (!demo)
			werror("GetProcAddress(demo)");
		stop = (StopFunc)GetProcAddress(hModule, "stop");
		if (!stop)
			werror("GetProcAddress(stop)");
		if (ComplexFillArray && demo && stop)
			DrawElls();
		ComplexFillArray = NULL; demo = NULL; stop = NULL;
		FreeLibrary(hModule);
	} else
		werror("LoadLibrary(ells.dll)");
	return 0;
}

/*** Graphic ***/

void DrawElls(void)
{
	DWORD *ColorArray = NULL;
	int nColorArray = 0;
//	DWORD Colors[] = {clRed,    clOrange, clYellow, clGreen,  clAqua,   clBlue,   clFuchsia};
	DWORD Colors[] = {0x0000FF, 0x0080FF, 0x00FFFF, 0x008000, 0xFFFF00, 0xFF0000, 0xFF00FF};
	if (demo) //if library loaded and function found
	{
		//create array of colors - spectrum
		if (ComplexFillArray)
		{
			nColorArray = 1000;
			ColorArray = (DWORD *) malloc(nColorArray * sizeof(DWORD));
			ComplexFillArray(Colors, sizeof Colors / sizeof Colors[0], ColorArray, &nColorArray);
		}
		demo(hForm, ColorArray, nColorArray);
		if (ColorArray)
			free(ColorArray);
	}
}

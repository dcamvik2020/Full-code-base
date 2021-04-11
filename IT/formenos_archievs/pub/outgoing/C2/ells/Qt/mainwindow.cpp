#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#define STRICT
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

HWND hForm;
QThread *thread2;

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand((unsigned)time(NULL));
    hForm = (HWND)this->winId();
    thread2 = NULL;
}

MainWindow::~MainWindow()
{
    if (thread2)
    {
        thread2->wait();
        delete thread2;
    }
    delete ui;
}

class Thread : public QThread
{
protected:
    void run()
    {
        DynLoad();
    }
};

void MainWindow::on_startButton_clicked()
{
    thread2 = new Thread;
    thread2->start();
}

void MainWindow::on_stopButton_clicked()
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

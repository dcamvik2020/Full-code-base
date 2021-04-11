#include <windows.h>

HANDLE hOutput;
DWORD nWritten;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//BOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
	WriteFile(hOutput, "Hell, Word!\r\n", 13, &nWritten, NULL);
	return 0;
}

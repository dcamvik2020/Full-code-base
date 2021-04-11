#include <windows.h>

char buf[10];
DWORD len;
HANDLE hInput, hOutput;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//BOOL WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
	ReadFile(hInput, buf, sizeof buf, &len, NULL);
	//BOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
	WriteFile(hOutput, buf, len, &len, NULL);
	return 0;
}

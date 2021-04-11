#include <stdio.h>
#include <windows.h>

//unsigned long __stdcall ThreadProc(void *arg) {
DWORD WINAPI ThreadProc(LPVOID arg) {
	int i;
	for (i = 0; i < 200000; i++)
		printf("%s", (char *) arg);
	return 0;
}

int main(void) {
	int i;
	HANDLE hThread;
	DWORD TID;
//	HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
//						LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
	if ((hThread = CreateThread(NULL, 0, ThreadProc, "T", 0, &TID)) == NULL) {
		fprintf(stderr, "CreateThread failed\n");
		return -1;
	}
	for (i = 0; i < 100000; i++)
		printf("M");
//	DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
	WaitForSingleObject(hThread, INFINITE);
//	BOOL CloseHandle(HANDLE hObject);
	CloseHandle(hThread);
	return 0;
}

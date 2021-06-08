#include <stdio.h>
#include <windows.h>


//unsigned long __stdcall ThreadProc(void *arg) {
DWORD WINAPI ThreadProc(LPVOID arg) {
    //int i;
    //for (i = 0; i < 20; i++)
    //    printf("%s", (char *) arg);
    char F =  (char) arg;
    printf("F = %c\n", F);
    return 0;
}

int main(void) {
    int i;
    HANDLE hThread, hThread2;
    DWORD TID;
//	HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
//						LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
    if ((hThread = CreateThread(NULL, 0, ThreadProc, "T", 0, &TID)) == NULL) {
        fprintf(stderr, "CreateThread failed\n");
        return -1;
    }
    //for (i = 0; i < 10; i++)
    //    printf("M");
//	DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
    WaitForSingleObject(hThread, INFINITE);
    ///_______________________________________________________________________
    //	HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
//						LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
    if ((hThread2 = CreateThread(NULL, 0, ThreadProc, "F", 0, &TID)) == NULL) {
        fprintf(stderr, "CreateThread2 failed\n");
        return -1;
    }
    //for (i = 0; i < 10; i++)
    //    printf("M");
//	DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
    WaitForSingleObject(hThread2, INFINITE);


//	BOOL CloseHandle(HANDLE hObject);
    CloseHandle(hThread);
    CloseHandle(hThread2);
    return 0;
}

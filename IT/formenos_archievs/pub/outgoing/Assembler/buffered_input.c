//#include <unistd.h>
//#include <io.h>
#include <windows.h>

#define MAXBUF 1023

static char buffer[MAXBUF+1] = "";
static int index = 0;
static HANDLE std_in = NULL;

int fillbuf(void) {
//	/*ssize_t*/ long n;
//	n = read(0, buffer, MAXBUF);
	DWORD n;
	if (std_in == NULL)
		std_in = GetStdHandle(STD_INPUT_HANDLE);
	ReadFile(std_in, buffer, MAXBUF, &n, NULL);
	buffer[n] = '\0';
	index = 0;
	return n;
}

char getchr(void) {
	if (buffer[index] == '\0')
		if (fillbuf() == 0)
			return '\0';
	return buffer[index++];
}

char *getstr(char s[], int n) {
	char c = '\0';
	int i;
	for (i = 0; i < n - 1 && (c = getchr()) != '\n' && c != '\0'; i++)
		s[i] = c;
	if (i > 0 && s[i-1] == '\r') {
//		if (c == '\n')
			i--;
/*		else
			if (i == n - 1) {
				if ((c = getchr()) == '\n')
					i--;
				else
					index--;
			}*/
	}
	s[i] = '\0';
	if (i == 0 && c == '\0')
		return NULL;
	return s;
}

int getnum(void) {
	char c;
	int a = 0, sg = 1;
	while ((c = getchr()) == ' ' || c == '\t' || c == '\r' || c == '\n');
	if (c == '\0')
		return 0;
	if (c == '-')
		sg = -1;
	else
		index--;
	while ((c = getchr()) >= '0' && c <= '9')
		a = a * 10 + c - '0';
	index--;
	return sg * a;
}

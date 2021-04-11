#include <stdio.h>
#include <string.h>

int FAKI(char *buf) {
	strcpy(buf, "Halyava, pridi!");
	return strlen(buf);
}

int FMBF(char *buf) {
	strcpy(buf, "Pridi, halyava!");
	return strlen(buf);
}

int FUPM(char *buf) {
	strcpy(buf, "Botat! Halyavy ne budet.");
	return strlen(buf);
}

int main(void) {
	int (*listeners[])(char *) = {FAKI, FMBF, FUPM};
	int i;
	//Action!
	for (i = 0; i < sizeof listeners / sizeof listeners[0]; i++) {
		char buff[1024];
		int n = listeners[i](buff);
		printf("%s (%d)\n", buff, n);
	}
	return 0;
}

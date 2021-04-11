#include <string.h>

#define PASS "ffffff"

int check(char *pass) {
	return !strcmp(pass, PASS);
}

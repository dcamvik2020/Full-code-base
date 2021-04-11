#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double CalcRec(char *s) {
	char *p;
	if ((p = strrchr(s, '+')) != NULL) {
		*p = '\0';
		return CalcRec(s) + CalcRec(++p);
	}
	//now "s" doesn't contain '+'s
	if ((p = strrchr(s, '-')) != NULL) { //search for last '-'
		*p = '\0';
		return CalcRec(s) - CalcRec(++p); //if "s" was "-X" (and now is ""), then CalcRec(s) returns 0
	}
	//now "s" doesn't contains '+'s nor '-'s
	if ((p = strrchr(s, '*')) != NULL) {
		*p = '\0';
		return CalcRec(s) * CalcRec(++p);
	}
	//now "s" doesn't contains '+'s, '-'s, '*'s
	if ((p = strrchr(s, '/')) != NULL) {
		*p = '\0';
		return CalcRec(s) / CalcRec(++p); //// ODZ !!!
	}
	//now "s" doesn't contains '+'s, '-'s, '*'s, '/'s
	if ((p = strrchr(s, '^')) != NULL) {
		*p = '\0';
		return pow(CalcRec(s), CalcRec(++p)); //// ODZ !!!
	}
	//now "s" doesn't contains '+'s, '-'s, '*'s, '/'s, '^'s
	if ((p = strrchr(s, '#')) != NULL) {
		*p = '\0';
		return sqrt(CalcRec(++p)); //// ODZ !!!
	}
	//after this "s" must be correct floating-point number
	return atof(s);
}

int main(void) {
	char s[1024];
	gets(s);
	printf("%lg\n", CalcRec(s));
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#ifdef _DEBUG

#define QUOTEME(x) #x
#define _QUOTEME(x) QUOTEME(x)

#define IF(func)         \
	if (!(func))         \
		perror(__FILE__", "_QUOTEME(__LINE__)": "#func); \
	else                 \

#else

#define IF(func)         \
	if (!(func))         \
		errorlog(""); \
	else                 \

#endif

void errorlog(const char *s) {
	//perror(s);
	time_t t = time(NULL);
	struct tm *tt;
	int er;
	FILE *log;
	//to stderr
	if ((tt = localtime(&t)) != NULL)
		fprintf(stderr, "%02d.%02d.%04d %02d:%02d:%02d: ",
				tt->tm_mday, tt->tm_mon + 1, tt->tm_year + 1900,
				tt->tm_hour, tt->tm_min, tt->tm_sec);
	if (s && s[0])
		fprintf(stderr, "%s:\n", s);
	fprintf(stderr, "Error %03d: %s\n", errno, strerror(errno));
	//to file
	er = errno;
	if ((log = fopen("errors.log", "a")) != NULL) {
		if ((tt = localtime(&t)) != NULL)
			fprintf(log, "%02d.%02d.%04d %02d:%02d:%02d: ",
					tt->tm_mday, tt->tm_mon + 1, tt->tm_year + 1900,
					tt->tm_hour, tt->tm_min, tt->tm_sec);
		if (s && s[0])
			fprintf(log, "%s:\n", s);
		fprintf(log, "Error %03d: %s\n", er, strerror(er));
		fclose(log);
	}
}

int main(void) {
	FILE *input, * output;
	char s[4096];
	IF ((input = fopen("input.txt", "rt")) != NULL) {
		IF ((output = fopen("output.txt", "wt")) != NULL) {
			while (fgets(s, sizeof s, input))
				fputs(s, output);
			IF (fclose(output) != EOF);
		}
		IF (fclose(input) != EOF);
	}
	return 0;
}

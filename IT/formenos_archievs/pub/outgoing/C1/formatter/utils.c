/*
 * utils.c
 *
 *  Created on: 05.08.2014
 *  Updated on: 01.10.2015
 *      Author: Andrey Tretyakov (MIPT)
 *      Copyright © All Rights Reserved
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <dirent.h>

#ifndef WIN32
#define SLASH "/"
#else
#define SLASH "\\"
#endif*/


//Strings

//delete "count" characters from string "s" starting "idx" position
void strdel(char *s, unsigned int idx, unsigned int count) {
	unsigned int i, n;
	if (!s)
		return;
	for (n = 0; s[n]; n++); //n = strlen(s);
	//fool checks
	if (idx >= n)
		return;
	if (count > n - idx)
		count = n - idx;
	//shift
	for (i = idx + count; i <= n; i++)
		s[i-count] = s[i];
}

//insert string "s" into string "t" starting "idx" position
int strins(char *t, unsigned int size, const char *s, unsigned int idx) {
	unsigned int i, m, n;
	if (!s || !t)
		return -1;
	for (m = 0; s[m]; m++); //m = strlen(s);
	for (n = 0; t[n]; n++); //n = strlen(t);
	//fool checks
	if (m + n >= size)
		return -2;
	if (idx > n)
		return -3;
	//shift
	for (i = n; i > idx; i--)
		t[i+m] = t[i];
	t[i+m] = t[i]; //fix for signed overflow: i == 0 >= idx == 0; i--;
	//copy
	for (i = 0; i < m; i++)
		t[idx+i] = s[i];
//	for (i = idx; i < idx + m; i++)
//		t[i] = s[i-idx];
	return 0;
}


//Files

//returns dynamic two-dimension array of chars - array of string
//the length of array (the number of lines) is returned by pointer in num_lines
char **read_file(FILE *fInput, int *num_lines) {
	char **Data = NULL;
	char buf[1024];
	int idx = 0, len;
	*num_lines = 0;
	while (fgets(buf, sizeof buf, fInput)) {
		len = strlen(buf);
		if (len > 0 && buf[len-1] == '\n')
			buf[--len] = '\0';
		while (len > 0 && buf[len-1] == '\r') //for "rb" mode in Windows
			buf[--len] = '\0';
		if (idx >= *num_lines) {
			if (*num_lines == 0)
				*num_lines = 2048;
			*num_lines *= 2;
			Data = (char **) realloc(Data, *num_lines * sizeof(char *));
		}
		Data[idx++] = strdup(buf);
	}
	*num_lines = idx;
	Data = (char **) realloc(Data, *num_lines * sizeof(char *));
	return Data;
}

void write_file(FILE *fOutput, char *Data[], int num_lines) {
	int i;
	for (i = 0; i < num_lines; i++) {
		fputs(Data[i], fOutput);
		fputs("\n", fOutput);
	}
}

void free_data(char *Data[], int n) {
	int i;
	for (i = 0; i < n; i++)
		free(Data[i]);
	free(Data);

}

void print_file(const char *file) {
	FILE *fInput;
	if ((fInput = fopen(file, "rt")) != NULL) {
		char buf[4096];
		while (fgets(buf, sizeof buf, fInput))
			printf("%s", buf);
		fclose(fInput);
	}
}

int fexists(const char *filename) {
	int result = 0;
	FILE *file;
	if ((file = fopen(filename, "rt")) != NULL) {
		result = -1;
		fclose(file);
	}
/*	char *file_name, *file, *s;
	const char *dir = NULL;
	DIR *pDir;
	struct dirent *pEntry;
	//copy "filename" to temporary writable buffer
	if ((file_name = strdup(filename)) == NULL)
		return 0;
	file = file_name;
	//find last slash and divide string into 2 parts
	if ((s = strrchr(file_name, SLASH[0])) != NULL) {
		*s = '\0';
		file = s + 1 + (filename - file_name); //hack to append "\" after "C:"
		if (file_name[0] != '\0')
			dir = file_name;
		else //case root dir
			dir = SLASH;
		//case root dir (hack)
		if (strlen(dir) == 2 &&
			((dir[0] >= 'a' && dir[0] <= 'z') || (dir[0] >= 'A' && dir[0] <= 'Z')) &&
			dir[1] == ':')
			strcat((char *)dir, SLASH);
	}
	//case relative path
	if (dir == NULL)
		dir = ".";
	//search directory for file
	if ((pDir = opendir(dir)) != NULL) {
		while ((pEntry = readdir(pDir)) != NULL)
			if (strcmp(pEntry->d_name, file) == 0) { //Win: stricmp
				result = 1;
				break;
			}
		closedir(pDir);
	} else {
		fprintf(stderr, "opendir(\"%s\"", dir), perror(")");
		result = -1;
	}
	free(file_name);*/
	return result;
}

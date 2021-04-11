#include <stddef.h>

char *my_strstr(const char *str, const char *substr) {
	int i, j;
	for (i = 0; str[i]; i++) {
		for (j = 0; substr[j] && str[i+j] == substr[j]; j++);
		if (!substr[j])
			return (char *)str + i;
	}
	return NULL;
}

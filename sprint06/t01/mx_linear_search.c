#include <stdio.h>

int mx_strcmp(const char*, const char*);

int mx_linear_search(char **arr, const char *s) {
	for (int i = 0; arr[i] != 0 && s != NULL; i++)
		if (mx_strcmp(arr[i], s) == 0)
			return i;
	return -1;
}

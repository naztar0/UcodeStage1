#include <stdbool.h>
#include <stdlib.h>

unsigned long mx_strlen(const char*);
bool mx_isspace(char);
void mx_strdel(char**);
char *mx_strncpy(char*, const char*, int);
char *mx_strnew(const int);

char *mx_strtrim(const char *str) {
	if (*str == NULL)
		return NULL;
	int front = 0, back = 0;
	bool not_yet = true;
	for (int i = 0; str[i]; i++) {
		if (mx_isspace(str[i]) && not_yet)
			front++;
		else if (!mx_isspace(str[i]) && not_yet)
			not_yet = false;
		else if (mx_isspace(str[i]) && !not_yet)
			back++;
		else if (!mx_isspace(str[i]) && back)
			back = 0;
	}
	char *result = mx_strnew(mx_strlen(str) - front - back);
	for (int i = 0, j = front; j < (int)mx_strlen(str) - back; i++, j++)
		result[i] = str[j];

	return result;
}

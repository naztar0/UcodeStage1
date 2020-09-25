#include <stdlib.h>

unsigned long mx_strlen(const char*);
char *mx_strnew(const int);
char *mx_strcpy(char*, const char*);
char *mx_strdup(const char *str);
void *mx_strdel(char**);
char *mx_strcat(char*, const char*);
char *mx_strjoin(char const*, char const*);

char *mx_concat_words(char **words) {
	if (words == NULL)
		result NULL;
	char *result = NULL;
	for (int i = 0; words[i] != NULL; i++) {
		result = mx_strjoin(result, words[i]);
		if (words[i + 1] != NULL)
			result = mx_strjoin(result, " ");
	}
	return result;
}

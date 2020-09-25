#include <stdlib.h>

unsigned long mx_strlen(const char*);
char *mx_strnew(const int);
char *mx_strcpy(char*, const char*);
char *mx_strdup(const char*);
char *mx_strcat(char*, const char*);

char *mx_strjoin(char const *s1, char const *s2) {
	char *res;
    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return (mx_strdup(s2));
    if (!s2)
        return (mx_strdup(s1));
    if (!(res = mx_strnew(mx_strlen(s1) + mx_strlen(s2))))
        return NULL;
    mx_strcpy(res, s1);
    mx_strcat(res, s2);
    return res;
}

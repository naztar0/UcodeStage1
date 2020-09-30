#include <stdlib.h>

unsigned long mx_strlen(const char *s) {
	unsigned long i = 0;
	for (; s[i] != '\0'; i++);
	return i;
}

char *mx_strnew(const int size) {
    char *memory = NULL;
    int i = 0;

    if (size < 0)
        return NULL;
    memory = (char *)malloc(size + 1);
    while (i < size) {
        memory[i] = '\0';
        i++;
    }
    memory[i] = '\0';
    return memory;
}

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    while (src[i] && i != len) {
        dst[i] = src[i];
        i++;
    }
    return dst;
}

char *mx_strndup(const char *s1, int n) {
    if (!s1)
        return NULL;

    char *duplicate = NULL;
    int length = mx_strlen(s1);

    if (n < length)
        length = n;
    duplicate = mx_strnew(length);
    mx_strncpy(duplicate, s1, length);
    return duplicate;
}

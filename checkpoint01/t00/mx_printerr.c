#include <unistd.h>

unsigned long mx_strlen(const char *s) {
	unsigned long i = 0;
	for (; s[i] != '\0'; i++);
	return i;
}

void mx_printerr(const char *s) {
	write(2, s, mx_strlen(s));
}

#include "create_agent.h"

char *mx_strcpy(char *dst, const char *src) {
	char *tmp = dst;
	while ((*dst++ = *src++) != '\0');
	return tmp;
}

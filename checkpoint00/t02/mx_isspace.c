#include <stdbool.h>

bool mx_isspace(char c) {
	return (int)(c == '\t' || c == '\n' ||
	    c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

#include <stdbool.h>

bool mx_isspace(char c) {
	return (c >= 8 && c <= 13) || (c >= 31 && c <= 32);
}

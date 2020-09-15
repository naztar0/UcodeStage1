#include "mx_printchar.c"

void mx_only_printable(void) {
	for (short i = 126; i > 31; i--) {
		char c = i;
		mx_printchar(c);
	}
}

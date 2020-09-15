#include "mx_printchar.c"

void mx_hexadecimal(void) {
	for (short i = 0; i < 16; i++) {
		char c;
		if (i < 10) c = (char)i + 48;
		else c = (char)i + 55;
		mx_printchar(c);
	}
	mx_printchar('\n');
}

#include <unistd.h>

void mx_only_printable(void) {
	for (short i = 126; i > 31; i--) {
		char c = i;
		write(1, &c, 1);
	}
}

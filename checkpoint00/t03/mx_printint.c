#include <unistd.h>

void mx_printint(int n) {
	if (n < 0) {
		n = -n;
		write(1, "-", 1);
	}
	char arr[11];
	short i = 0;
	for (; n != 0; n /= 10, i++)
		arr[i] = (char)(n % 10) + 48;
	for (; i >= 0; i--)
		write(1, &arr[i], 1);
}

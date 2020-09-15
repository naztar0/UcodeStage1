#include <stdbool.h>

double mx_pow(double, unsigned int);

bool mx_is_narcissistic(int num) {
	int pow = 0, res = 0, tmp1 = 0, tmp2 = 0;
	num >= 0 ? (tmp1 = tmp2 = num) : (tmp1 = tmp2 = -num);
	for (; tmp1 != 0; tmp1 /= 10, pow++);
	for (; tmp2 != 0; tmp2 /= 10)
		res += (int)mx_pow(tmp2 % 10, pow);
	if (res == num)
		return true;
	return false;
}

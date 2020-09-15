int mx_sum_digits(int num) {
	int res = 0;
	if (num < 0) num = -num;
	for (; num != 0; num /= 10) res += (num % 10);
	return res;
}

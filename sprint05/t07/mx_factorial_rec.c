int mx_factorial_rec(int n) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	long test = (long)n * (long)n - 1;
	if (test > 2147483647)
		n = 0;
	if (n == 1)
		return 1;
	return n * mx_factorial_rec(n - 1);
}

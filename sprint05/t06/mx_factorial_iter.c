int mx_factorial_iter(int n) {
	if (n < 0)
		return 0;
	int res = 1;
	for (int i = 1; i <= n; i++) {
		long test = (long)res * (long)i;
		if (test > 2147483647)
			i = 0;
		res *= i;
	}
	return res;
}

int mx_sqrt(int x) {
	if (x <= 0)
		return 0;
	int i = 1, res = 1;
	for(; res <= x; i++) {
		res = i * i;
	}
	return i - 2;
}

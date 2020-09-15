int mx_max(int a, int b, int c) {
	return a > b && a > c ? a : b > a && b > c ? b : c > a && c > b ? c : 0;
}

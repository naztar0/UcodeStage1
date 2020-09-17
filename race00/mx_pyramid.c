void mx_printchar(char);

void mx_pyramid(int n) {
	if (n < 2 || n % 2 == 1)
		return;
	int front = n;
	int back = n / 2;
	int inner_space = 0;

	for (int i = 0; i < front; i++) {
		for (int j = 0; j < front - i - 1; j++)
			mx_printchar(' ');
		mx_printchar('/');
		for (int j = 0; j < inner_space; j++) {
			if (i < front - 1)
				mx_printchar(' ');
			else
				mx_printchar('_');
		}
		mx_printchar('\\');

		if (inner_space > 0) {
			if (back > i) {
				for (int j = 0; j < i; j++)
					mx_printchar(' ');
				mx_printchar('\\');
			}
			else {
				for (int j = 0; j < front - i - 1; j++)
					mx_printchar(' ');
				mx_printchar('|');
			}
		}
		mx_printchar('\n');

		if (inner_space == 0)
			inner_space++;
		else
			inner_space += 2;
	}
}

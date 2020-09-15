void mx_printchar(char);

void mx_str_separate(const char *str, char delim) {
	int prev = 0;
	while (*str) {
		if (*str != delim) {
			mx_printchar(*str);
			prev = 0;
		}
		else if (prev == 0) {
			mx_printchar('\n');
			prev = 1;
		}
		str++;
	}
}

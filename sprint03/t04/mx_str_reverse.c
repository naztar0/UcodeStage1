void mx_swap_char(char*, char*);
unsigned long mx_strlen(const char*);

void mx_str_reverse(char *s) {
	int len = mx_strlen(s);
	for (int i = 0; i < len / 2; i++) {
		mx_swap_char(&s[i], &s[len - i - 1]);
	}
	printf("%s", s);
}

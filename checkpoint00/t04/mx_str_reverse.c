void mx_str_reverse(char *s) {
	int len = 0;
	for (; s[len] != '\0'; len++);
	for (int i = 0; i < len / 2; i++) {
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}

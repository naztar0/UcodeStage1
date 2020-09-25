unsigned long mx_strlen(const char*);

char *mx_strcat(char *s1, const char *s2) {
	char *p = s1 + mx_strlen(s1);
	while ((*p++ = *s2++) != '\0');
	return s1;
}

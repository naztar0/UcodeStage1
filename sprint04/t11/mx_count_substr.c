char *mx_strchr(const char*, int);

int mx_strncmp(const char*, const char*, int);

unsigned long mx_strlen(const char*);

char *mx_strstr(const char*, const char*);

int mx_count_substr(const char *str, const char *sub) {
	int len = mx_strlen(sub);
	int res = 0;
	const char *p = str;
	for (int i = 0; i < len; i++) {
		if (p[i] != sub[i])
			break;
		else if (p[i] == sub[i] && i == len - 1)
			res++;
	}
	for (; *p; ) {
		p = mx_strstr(p, sub);
		if (p == '\0')
			break;
		res++;
	}
	return res;
}

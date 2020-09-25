#include <stdbool.h>
#include <stdlib.h>

void mx_strdel(char**);
unsigned long mx_strlen(const char *);
char *mx_strncpy(char*, const char*, int);
char *mx_strnew(const int);
bool mx_isspace(int);
char *mx_strtrim(const char*);
char *mx_del_extra_whitespaces(const char*);

char *mx_del_extra_whitespaces(const char *str) {
	if(str == NULL)
		return NULL;

	int size_of_new = 0;

	bool wasspace = false;
	for(int i = 0; i < (int)mx_strlen(str); i++) {
		if(!mx_isspace(str[i])) {
			size_of_new++;
			wasspace = false;
		}
		else if(mx_isspace(str[i]) && wasspace == false) {
			size_of_new++;
			wasspace = true;
		}
	}

	if(size_of_new < 1)
		return NULL;

	char *str_new = mx_strnew(size_of_new);

	if((int)mx_strlen(str_new) == 1 && mx_isspace(str_new[0])) {
		mx_strdel(&str_new);
		return NULL;
	}

	wasspace = false;
	int index_of_new = 0;
	for(int i = 0; i < (int)mx_strlen(str); i++) {
		if(!mx_isspace(str[i])) {
			str_new[index_of_new] = str[i];
			index_of_new++;
			wasspace = false;
		}
		else if(mx_isspace(str[i]) && wasspace == false) {
			str_new[index_of_new] = ' ';
			index_of_new++;
			wasspace = true;
		}
	}

	str_new = mx_strtrim(str_new);
	return str_new;
}

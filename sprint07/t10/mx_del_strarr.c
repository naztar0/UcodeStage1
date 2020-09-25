#include <stdlib.h>

void mx_strdel(char**);

void mx_del_strarr(char ***arr) {
    for (int i = 0; (*arr)[i] != NULL; i++)
        mx_strdel(&((*arr)[i]));
    free(*arr);
    *arr = NULL;
}

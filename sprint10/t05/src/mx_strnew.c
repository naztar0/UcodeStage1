#include "minilibmx.h"

char *mx_strnew(const int size) {
    char *str = NULL;

    str = (char*) malloc(8 * size + 1);
    if(!str)
        return NULL;
    for (int i = 0; i < size + 1; i++)
        str[i] = '\0';
    return str;
}



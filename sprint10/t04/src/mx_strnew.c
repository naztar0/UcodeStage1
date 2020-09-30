#include "header.h"

char *mx_strnew(const int size) {
    char *arr = NULL;
    if (size < 0)
        return NULL;
    arr = (char *)malloc(8 * size + 1);
    for (int i = 0; i <= size; i++)
        arr[i] = '\0';
    return arr;
}

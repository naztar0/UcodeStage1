#pragma once

#include <stdlib.h>
#include <stdbool.h>
#define P_SIZE 8
#define ERROR "ERROR\n"
#define USAGE "usage: ./playlist [file] [command] [args]\n"
typedef struct s_list {
    char *artist;
    char *name;
    struct s_list *next;
}              t_list;

enum e_operation {
    NONE,
    ADD,
    REMOVE,
    SORT,
    PRINT
};

enum e_sort {
    ARTIST,
    NAME
};

int mx_strncmp(const char*, const char*, int);
unsigned long mx_strlen(const char*);
void mx_printerr(char*);

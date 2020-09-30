#pragma once

#include <stdlib.h>
#define P_SIZE 8

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

void mx_foreach(t_list*, void (*)(t_list*));

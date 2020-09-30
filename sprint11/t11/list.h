#pragma once

#include <stdlib.h>
#include <stdbool.h>
#define P_SIZE 8

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

void mx_del_node_if(t_list**, void*, bool (*)(void*, void*));

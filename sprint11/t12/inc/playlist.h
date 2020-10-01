#pragma once

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#define P_SIZE 8
#define ERROR "ERROR\n"
#define USAGE "usage: ./playlist [file] [command] [args]\n"
#define NOT_INT -65535

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

void mx_printerr(const char*);
void mx_write_list_to_file(char*, t_list*);
void mx_printchar(char);
void mx_printint(int);
void mx_error();
bool mx_isspace(int);
bool mx_isdigit(int);
char *mx_file_to_str(const char*);
char *mx_strnew(const int);
char *mx_strstr(const char*, const char*);
char *mx_strncpy(char*, const char*, int);
int mx_strcmp(const  char*, const char*);
int mx_strncmp(const char*, const char*, int);
int mx_strlen(const char*);
int mx_atoi(const char*);

int mx_count_songs(char*);
void mx_print_list(t_list*);
t_list *mx_parse_songs(char*, int);
t_list *mx_create_node();
//void mx_push_front(t_list**, void*);
void mx_push_back(t_list*, char*, char*);
//void mx_push_index(t_list**, void*, int);
t_list *mx_pop_back(t_list*);
t_list *mx_pop_front(t_list*);
t_list *mx_pop_index(t_list*, int);
void mx_clear_list(t_list*);
//int mx_list_size(t_list*);
//void mx_foreach_list(t_list*, void(*)(t_list*));
t_list *mx_sort_list_name(t_list*);
t_list *mx_sort_list_artist(t_list*);
//void mx_del_node_if(t_list**, void*, bool(*cmp)(void*, void*));

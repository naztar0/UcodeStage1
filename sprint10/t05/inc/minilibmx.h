#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_agent {
    char *name;
    int power;
    int strength;
}              t_agent;

void mx_printerr(const char*);
int mx_strlen(const char*);
void mx_printstr(const char*);
void mx_printchar(char);
void mx_printint(int);
bool mx_isspace(char);
bool mx_isdigit(int);
int mx_atoi(const char*);
int mx_strcmp(const char*, const char*);
char *mx_file_to_str(const char*);
char *mx_strcat(char*, const char*);
char *mx_strcpy(char*, const char*);
char *mx_strncpy(char*, const char*, int);
char *mx_strnew(const int);
char *mx_strdup(const char*);
char *mx_strjoin(char const*, char const*);
int mx_strncmp(const char*, const char*, int);
char *mx_strchr(const char*, int);
char *mx_strstr(const char*, const char*);
t_agent *mx_create_agent(char*, int, int);
t_agent **mx_create_new_agents(char**, int*, int*, int);
void mx_exterminate_agents(t_agent***);

#endif

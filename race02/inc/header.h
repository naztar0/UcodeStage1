#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int mx_strlen(const char*);
void mx_printchar(char);
void mx_printint(int);
bool mx_isdigit(int);
bool mx_isspace(char);
void mx_printstr(const char*);
void mx_printerr(const char*);
int mx_atoi(const char*);
char **cmatrix (char*, int*, int*);
int **matrix (char*, int*, int*);
char *mx_file_to_str(const char*);
int max(int**, int, int, int, int, char**);
bool path(int**, int, int, int, int, int, int, int*, int*, int*);

#endif

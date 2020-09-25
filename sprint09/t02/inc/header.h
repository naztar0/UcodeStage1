#ifndef HEADER
#define HEADER

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int mx_strcmp(const char*, const char*);
unsigned long mx_strlen(const char*);
char *mx_strcpy(char*, const char*);
void mx_printstr(const char*);
void mx_printchar(char);
void mx_printint(int);
bool mx_isspace(char);
bool mx_isdigit(int);
int mx_atoi(const char*);

#endif

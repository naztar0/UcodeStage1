#include "../inc/header.h"

void mx_printerr(char *err) {
    write(2, err, mx_strlen(err));
    exit(-1);
}
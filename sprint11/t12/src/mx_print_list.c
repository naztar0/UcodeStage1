#include "playlist.h"

void mx_print_list(t_list *list) {
    t_list *p = list;
    if (!p)
        mx_error();
    for (int i = 0; p; i++) {
        mx_printint(i);
        write(1, ". ", 2);
        write(1, p->artist, mx_strlen(p->artist));
        write(1, " - ", 3);
        write(1, p->name, mx_strlen(p->name));
        write(1, "\n", 1);
        p = p->next;
    }
}

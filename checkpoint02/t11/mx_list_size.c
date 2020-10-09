#include "list.h"

int mx_list_size(t_list *list) {
    if (list == NULL)
        return 0;
    t_list *p = list;
    int size = 0;
    while (p) {
        p = p->next;
        size++;
    }
    return size;
}

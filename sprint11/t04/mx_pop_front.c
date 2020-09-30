#include "list.h"

void mx_pop_front(t_list **list) {
    t_list *p = NULL;
    if (*list == NULL)
        return;
    else {
        p = (*list)->next;
        free(*list);
        *list = p;
    }
}

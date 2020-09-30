#include "list.h"

void mx_pop_back(t_list **list) {
    t_list *p = *list;
    if (p->next == NULL) {
        free(*list);
        *list = NULL;
    }
    else {
        while (p->next->next)
            p = p->next;
        free(p->next);
        p->next = NULL;
    }
}

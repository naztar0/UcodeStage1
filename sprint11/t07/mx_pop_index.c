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

void mx_pop_index(t_list **list, int index) {
    t_list *p = *list;
    int size = mx_list_size(p);

    if (index <= 0)
        mx_pop_front(list);
    else if (index > size)
        mx_pop_back(list);
    else {
        for (int i = 0; p; i++) {
            if (i == index - 1) {
                free(p->next);
                p->next = p->next->next;
            }
            p = p->next;
        }
    }
}

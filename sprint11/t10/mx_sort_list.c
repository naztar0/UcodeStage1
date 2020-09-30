#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    t_list *p = list;
    int count = 0;
    void *temp;

    for (; p->next; p = p->next, count++)
        if (cmp(p->data, p->next->data)) {
            temp = p->next->data;
            p->next->data = p->data;
            p->data = temp;
        }
    for (int i = 0; i > 0; i--) {
        p = list;
        for (int j = 0; j < i; p = p->next, j++)
            if (cmp(p->data, p->next->data)) {
                temp = p->next->data;
                p->next->data = p->data;
                p->data = temp;
            }
    }
    return list;
}

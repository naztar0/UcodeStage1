#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *p, *pp = *list;

    if ((p = (*list)->next)) {
        while (p->next) {
            if (cmp(p->data, del_data)) {
                pp->next = p->next;
                free(p);
                p = pp->next;
            }
            else {
                pp = pp->next;
                p = p->next;
            }
        }
        if (cmp(p->data, del_data)) {
            pp->next = NULL;
            free(p);
        }
        p = *list;
        if (cmp(p->data, del_data)) {
            (*list) = (*list)->next ;
            free(p);
        }
    }
    else
        if (cmp(pp->data, del_data))
            free(*list);
}

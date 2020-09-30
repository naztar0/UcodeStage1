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

void mx_push_index(t_list **list, void *data, int index) {
    t_list *p = *list;
    t_list *new_node = mx_create_node(data);
    int size = mx_list_size(p);

    if (index <= 0)
        mx_push_front(list, data);
    else if (index > size)
        mx_push_back(list, data);
    else {
        for (int i = 0; p; i++) {
            if (i == index - 1) {
                new_node->next = p->next;
                p->next = new_node;
            }
            p = p->next;
        }
    }
}

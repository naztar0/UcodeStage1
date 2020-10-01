#include "playlist.h"

t_list *mx_pop_back(t_list *list) {
    t_list *current = list;

    if (current->next == NULL) {
        //free(list);
        list = NULL;
    }
    else {
        while (current->next->next != NULL)
            current = current->next;
        free(current->next);
        current->next = NULL;
    }
    return list;
}

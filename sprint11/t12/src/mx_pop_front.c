#include "playlist.h"

t_list *mx_pop_front(t_list *list) {
    if(list != NULL) {
        t_list *temp = list->next;
        list = temp;
        return list;
    }
    return NULL;
}

#include "playlist.h"

void mx_clear_list(t_list *list) {
    t_list *temp = list;
    while(list != NULL)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}

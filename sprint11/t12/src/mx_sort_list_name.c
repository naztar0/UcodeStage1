#include "playlist.h"

t_list *mx_sort_list_name(t_list *list) {
    t_list *buff = list;
    void *temp;
    int count = 0;

    while (buff->next) {
        if (mx_strcmp(buff->name, buff->next->name) > 0) {
            temp = buff->next->artist;
            buff->next->artist = buff->artist;
            buff->artist = temp;
            temp = buff->next->name;
            buff->next->name = buff->name;
            buff->name = temp;
        }
        buff = buff->next;
        count++;
    }
    for (int i = count; i > 0; i--) {
        buff = list;
        for (int j = 0; j < i; j++) {
            if (mx_strcmp(buff->name, buff->next->name) > 0) {
                temp = buff->next->artist;
                buff->next->artist = buff->artist;
                buff->artist = temp;
                temp = buff->next->name;
                buff->next->name = buff->name;
                buff->name = temp;
            }
            buff = buff->next;
        }
    }
    return list;
}

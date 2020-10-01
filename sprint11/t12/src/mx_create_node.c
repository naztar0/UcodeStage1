#include "playlist.h"

t_list *mx_create_node() {
    t_list *new_node = (t_list*)malloc(8 * 3);
    new_node->artist = NULL;
    new_node->name = NULL;
    new_node->next = NULL;
    return new_node;
}

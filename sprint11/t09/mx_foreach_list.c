#include "list.h"

void mx_foreach(t_list *list, void (*f)(t_list *node)) {
    t_list *p = list;
    if (!p || !f)
        return;
    while (p) {
        f(p);
        p = p->next;
    }
}

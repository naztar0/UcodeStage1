#include "duplicate.h"

t_intarr mx_del_dup_sarr(t_intarr *src) {
    for (int i = 0; i < src->size; i++) {
        for (int j = i + 1; j < src->size; j++) {
            if (src->arr[i] == src->arr[j] ) {
                for (int a = j; a < src->size - 1; a++)
                    src->arr[a] = src->arr[a + 1];
                src->size--;
                if (src->arr[i] == src->arr[j])
                    j--;
            }
        }
    }
    t_intarr dst;
    dst.size = src->size;
    dst.arr = (int*)malloc(dst.size * 4);
    dst.arr = mx_copy_int_arr(src->arr, dst.size);
    t_intarr *pointer = &dst;
    src = NULL;
    return *pointer;
}

#include <stdbool.h>

void mx_sort(int *arr, int size, bool(*f)(int, int)) {
    if (!arr || !f || size < 1)
        return;
    int i, j, min_idx;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < size; j++)
            if ((*f)(arr[min_idx] , arr[j]))
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

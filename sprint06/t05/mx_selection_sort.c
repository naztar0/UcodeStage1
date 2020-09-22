unsigned long mx_strlen(const char*);

int mx_strcmp(const char*, const char*);

int mx_selection_sort(char** arr, int size) {
    int i, j, min_idx, counter = 0;

    char *minStr;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        minStr = arr[i];
        for (j = i + 1; j < size; j++) {
            if (mx_strcmp(minStr, arr[j]) > 0) {
                minStr = arr[j];
                min_idx = j;
            }
        }

        if (min_idx != i) {
            char *temp;
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            counter++;
        }
    }
    for (i = 0; i < size; i++)
        printf("%d: %s \n", i, arr[i]);
    return counter;
}

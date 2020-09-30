#include "../inc/header.h"

int main(int argc, char *argv[]) {
    enum e_operation operation = NONE;

    if (argc < 3)
        mx_printerr(USAGE);

    char *operation_str = argv[2];

    if (mx_strncmp(operation_str, "add", 3) == 0)
        if (argc == 5)
            operation = ADD;
    else if (mx_strncmp(operation_str, "remove", 6) == 0)
        if (argc == 4)
            operation = REMOVE;
    else if (mx_strncmp(operation_str, "sort", 4) == 0)
        if (argc == 4)
            operation = SORT;
    else if (mx_strncmp(operation_str, "print", 5) == 0)
        if (argc == 3)
            operation = PRINT;
    if (operation == NONE)
        mx_printerr(USAGE);

    char *filename = argv[1];

    switch (operation) {
        case ADD:
            char *artist = argv[3];
            char *name = argv[4];
            ;
            break;
        case REMOVE:
            char *index = argv[3];
            ;
            break;
        case SORT:
            enum e_sort sort_by;
            if (mx_strncmp(argv[3], "artist", 6) == 0)
                sort_by = ARTIST;
            else if (mx_strncmp(argv[3], "name", 6) == 0)
                sort_by = NAME;
            else
                mx_printerr(ERROR);
            ;
            break;
        case PRINT:
            ;
            break;
    }
    
    return 0;
}

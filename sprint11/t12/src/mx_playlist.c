#include "playlist.h"

int main(int argc, char *argv[]) {
    enum e_operation operation = NONE;

    if (argc < 3)
    {
        mx_printerr(USAGE);
        return 1;
    }

    if (mx_strncmp(argv[2], "add", 3) == 0)
    {
        if (argc == 5)
            operation = ADD;
        else
            mx_error();
    }
    else if (mx_strncmp(argv[2], "remove", 6) == 0)
    {
        if (argc == 4)
            operation = REMOVE;
        else
            mx_error();
    }
    else if (mx_strncmp(argv[2], "sort", 4) == 0)
    {
        if (argc == 4)
            operation = SORT;
        else
            mx_error();
    }
    else if (mx_strncmp(argv[2], "print", 5) == 0)
    {
        if (argc == 3)
            operation = PRINT;
        else
            mx_error();
    }
    if (operation == NONE)
        mx_error();

    char *artist;
    char *name;
    char *index;
    char *src_text = mx_file_to_str(argv[1]);

    if(src_text != NULL)
    {   
        int songs_count = mx_count_songs(src_text);
        if(songs_count < 0)
            mx_error();
        t_list *songs_list = mx_parse_songs(src_text, songs_count);
        if(songs_list == NULL)
            mx_error();

        switch (operation) {
            case ADD: //++++++++++++++++++++++++++++++++++++++++++++++++++
                artist = argv[3];
                name = argv[4];
                mx_push_back(songs_list, artist, name);
                mx_write_list_to_file(argv[1], songs_list);
                mx_clear_list(songs_list);
                break;
            case REMOVE:
                index = argv[3];
                songs_list = mx_pop_index(songs_list, mx_atoi(index));
                mx_write_list_to_file(argv[1], songs_list);
                mx_clear_list(songs_list);
                break;
            case SORT:
                if (mx_strncmp(argv[3], "artist", 7) == 0) {
                    songs_list = mx_sort_list_artist(songs_list);
                    mx_write_list_to_file(argv[1], songs_list);
                    mx_clear_list(songs_list);
                }
                else if (mx_strncmp(argv[3], "name", 5) == 0) {
                    songs_list = mx_sort_list_name(songs_list);
                    mx_write_list_to_file(argv[1], songs_list);
                    mx_clear_list(songs_list);
                }
                else
                    mx_error();
                break;
            case PRINT: //++++++++++++++++++++++++++++++++++++++++++++++++++
                mx_print_list(songs_list);
                mx_clear_list(songs_list);
                break;
            case NONE: //++++++++++++++++++++++++++++++++++++++++++++++++++
                mx_clear_list(songs_list);
                mx_error();
                break;
        }
        return 0;
    }
    mx_error();
    return 0;
}

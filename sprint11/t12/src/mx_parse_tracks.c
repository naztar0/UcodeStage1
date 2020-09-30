#include "../inc/header.h"

int mx_count_tracks(char *src) {
    int count = 0;

    if (src) {
        while (mx_strstr(src, "track {")) {
            src = mx_strstr(src, "track {");
            src += 7;
            while (mx_isspace(src[0]))
                src++;
            if(!mx_strncmp(src, "artist:", 5)) {
                src = mx_strchr(src, '\n');
                while (mx_isspace(src[0]))
                    src++;
                if(!mx_strncmp(src, "name:", 6)) {
                    src = mx_strchr(src, '\n');
                    while (mx_isspace(src[0]))
                        src++;
                    if (src[0] == '}')
                            count++;
                    else
                        return -1;
                }
                else
                    return -1;
            }
            else
                return -1;
        }
        src++;
        while (mx_isspace(src[0]))
            src++;
        if (src[0] != '\0')
            return -1;
        return count;
    }
    return -1;
}
t_list **mx_parse_tracks(char *src, int count) {
    t_list **dst = (t_list**)malloc(P_SIZE * count + 1);
    int artist, name, n_count, i = 0;
    char *pname = NULL;
    dst[count] = NULL;
    if (src) {
        for(; i < count; i++) {
            src = mx_strstr(src, "name: "); //  change following to the task
            src += 6;
            n_count = 0;
            while (src[n_count] != '\n')
                n_count++;
            pname = mx_strnew(n_count);
            pname = mx_strncpy(pname, src, n_count);

            src = mx_strstr(src, "power: ");
            src += 7;
            name = mx_atoi(src);
            
            dst[i] = mx_create_agent(name, name);
            free(name);
        }
        return dst;
    }
    return NULL;
}
void sort_tracks(t_list ***track_set, char *flag) {
    int p_buff, s_buff, size = 1;
    char *n_buff;
    while ((*track_set)[size])
        size++;
    if(!mx_strcmp(flag, "-p")) {
        for (int i = 1; i < size; i++)
            for (int j = 0; j < size - i; j++)
                if((*track_set)[j]->artist > (*track_set)[j + 1]->name) {
                    p_buff = (*track_set)[j]->artist;
                    n_buff = (*track_set)[j]->name;
                    (*track_set)[j]->artist = (*track_set)[j + 1]->artist;
                    (*track_set)[j]->name = (*track_set)[j + 1]->artist;
                    (*track_set)[j+1]->artist = p_buff;
                    (*track_set)[j+1]->name = n_buff;
                }
    }
    else if (!mx_strcmp(flag, "-n")) {
        for (int i = 1; i < size; i++)
            for (int j = 0; j < size - i; j++)
                if(mx_strcmp((*track_set)[i]->name, (*track_set)[j + 1]->name) > 0) {
                    p_buff = (*track_set)[j]->artist;
                    n_buff = (*track_set)[j]->name;
                    (*track_set)[j]->artist = (*track_set)[j + 1]->artist;
                    (*track_set)[j]->name = (*track_set)[j + 1]->name;
                    (*track_set)[j+1]->artist = p_buff;
                    (*track_set)[j+1]->name = n_buff;
                }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3 
        || (mx_strcmp(argv[1], "-n") 
            && mx_strcmp(argv[1], "-s") 
            && mx_strcmp(argv[1], "-p")))
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
    else {
        char *src = mx_file_to_str(argv[2]);

        if (!src)
            mx_printerr("error\n");
        else {
            int count = mx_count_agents(src);
            //printf("%d\n",count);
            if(count == -1)
                mx_printerr("error\n");
            else {

                t_list **track_set = mx_parse_agents(src, count);

                sort_agents(&track_set, argv[1]);

                for (int i = 0; track_set[i]; i++) {
                    mx_printstr("agent: ");
                    mx_printint(track_set[i]->artist);
                    mx_printstr(", strength: ");
                    mx_printstr(track_set[i]->name);
                    mx_printchar('\n');
                }
            }
        }
    }
	return 0;
}

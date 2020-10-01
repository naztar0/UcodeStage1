#include "playlist.h"

bool mx_isspace(int c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == 'r')
        return true;
    return false;
}

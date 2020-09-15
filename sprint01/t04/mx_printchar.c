#include <unistd.h>

void mx_voice(char c) {
    write(1, &c, 1);
}

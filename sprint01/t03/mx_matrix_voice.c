#include <unistd.h>

void mx_voice(void) {
    write(1, "^G", 2);
}

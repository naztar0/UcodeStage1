#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define JAPANESE {"ア", "イ", "ウ", "エ", "オ", "カ", "キ", "ク", "ケ", "コ", "サ", "シ", "ス", "セ", "ソ", "ガ", "ギ", "グ", "ゲ", "ゴ", "パ", "ピ", "プ", "ペ", "ポ"}

unsigned long mx_strlen(const char*);
char mx_display_char(int, int, int, int, char);
char *mx_display_jp(int, int, int, int, char*);
void mx_flags_handler(int, char**, char*);

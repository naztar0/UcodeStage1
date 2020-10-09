/***** УПРАВЛЕНИЕ *****
 * 
 * 	=== СКОРОСТЬ ===
 * "+" - быстрее
 * "-" - медленнее
 * 
 * 	===== ЦВЕТ =====
 * "f" - изменить цвет символов
 * "b" - изменить цвет фона
 * ----------------------------
 * "0" - изменить цвет хвоста
 * "." - изменить цвет головы
 * ----------------------------
 * "1..8" - сами цвета
 */

#include "../inc/header.h"
#include <locale.h>


void mx_intro(void) {
    char *text1 = "Wake up , Neo..";
    char *text2 = "The Matrix has you..";
    char *text3 = "Follow the white rabbit";
    char *text4 = "Knock, knock, Neo";
    refresh();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    for(unsigned int i = 0; i < mx_strlen(text1); i++) {
        mvaddch(5, i + 4, text1[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
    for(unsigned int i = 0; i < mx_strlen(text2); i++){
        mvaddch(5, i + 4, text2[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
    for(unsigned int i = 0; i < mx_strlen(text3); i++){      
        mvaddch(5, i + 4, text3[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
    for(unsigned int i = 0; i < mx_strlen(text4); i++){      
        mvaddch(5, i + 4, text4[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

void mx_chrrain(bool jap) {
	curs_set(0);
	time_t  d;
	srand((unsigned) time(&d));
   	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	int max_x;
	int max_y;
	
	getmaxyx(stdscr, max_y, max_x);
	int start[max_x];
	for (int i = 0; i < max_x; i++)
		start[i] = -max_y + rand() % max_y;
	int delat[max_x];
	for (int i = 0; i < max_x; i++)
		delat[i] = rand() % max_y;
	int end[max_x];
	int tail[max_x];
	int pisY[max_x];
	int flag[max_x];
	for (int i = 0; i < max_x; i++)
		 pisY[i] = 0;
	int speed = 100;

	int color_pos = 2;
	int color_type = 1;
	int color_fg = COLOR_GREEN;
	int color_bg = COLOR_BLACK;

	char chr[max_x];
	char *jp[max_x];
	while (true) {
		int i = 0;
		while (i < max_x) {
			if (i % 5 == 0) {
				end[i] = start[i] - delat[i];
				if (flag[i] == 1) {
					if (tail[i] == max_y+1)
						flag[i] = 0;
					move(tail[i], i);
					printw(" ");
					tail[i]++;
				}
				if (start[i] == max_y) {
					pisY[i] = 0;
					start[i] = 0;
					flag[i] = 1;
					tail[i] = max_y - delat[i];
					delat[i] = rand() % max_y;
				}
				if(end[i] >= 0) {
					printw(" ");
					move(end[i], i);
					printw(" ");
				}
				if (start[i] >= 0) {
					if (!jap)
						chr[i] = mx_display_char(pisY[i], i, start[i], max_y, chr[i]);
					else
						jp[i] = mx_display_jp(pisY[i], i, start[i], max_y, jp[i]);
				}
			}
			i++;
		}
		for(int i = 0; i < max_x; i++) {
			if (start[i] >= 0)
				pisY[i]++;
		}
		usleep(1000 * speed);
		refresh();
		for(int i = 0; i < max_x; i++)
			start[i]++;
		char ch = getch();
		switch (ch) {
			case 'q':
				clear();
				return;
			case '+':
				if (speed > 1) {
					if (speed <= 11)
						speed--;
					else
						speed -= 10;
				}
				break;
			case '-':
				if (speed < 300) {
					if (speed <= 10)
							speed++;
						else
							speed += 10;
				}
				break;
			case 'f':
				color_type = 1;
				break;
			case 'b':
				color_type = 2;
				break;
			case '1':
				if (color_type == 1)
					color_fg = COLOR_GREEN;
				else
					color_bg = COLOR_GREEN;
				break;
			case '2':
				if (color_type == 1)
					color_fg = COLOR_BLUE;
				else
					color_bg = COLOR_BLUE;
				break;
			case '3':
				if (color_type == 1)
					color_fg = COLOR_CYAN;
				else
					color_bg = COLOR_CYAN;
				break;
			case '4':
				if (color_type == 1)
					color_fg = COLOR_MAGENTA;
				else
					color_bg = COLOR_MAGENTA;
				break;
			case '5':
				if (color_type == 1)
					color_fg = COLOR_RED;
				else
					color_bg = COLOR_RED;
				break;
			case '6':
				if (color_type == 1)
					color_fg = COLOR_YELLOW;
				else
					color_bg = COLOR_YELLOW;
				break;
			case '7':
				if (color_type == 1)
					color_fg = COLOR_WHITE;
				else
					color_bg = COLOR_WHITE;
				break;
			case '8':
				if (color_type == 1)
					color_fg = COLOR_BLACK;
				else
					color_bg = COLOR_BLACK;
				break;
			case '0':
				color_pos = 2;
				break;
			case '.':
				color_pos = 1;
				break;
		}
		init_pair(color_pos, color_fg, color_bg);
	}
}

int main(int argc, char *argv[]) {
	char p[] = "00";
    char *flags = p;
	mx_flags_handler(argc, argv, flags);
	setlocale(LC_CTYPE, "");
	initscr();
	nodelay(stdscr, 1);
	noecho();
	start_color();
	if (flags[0] == '1')
		mx_intro();
	mx_chrrain(flags[1] == '1');
  	endwin();
	return 0;
}

#include "header.h"

void mx_flags_handler(int argc, char *argv[], char *flags) {
    bool intro = true;
	bool jap = false;
	bool error = false;
    if (argc == 2) {
		if (mx_strlen(argv[1]) == 2) {
			if (argv[1][0] == '-' && argv[1][1] == 's')
				intro = false;
			else if (argv[1][0] == '-' && argv[1][1] == 'j')
				jap = true;
			else
				error = true;
		}
		else if (mx_strlen(argv[1]) == 3) {
			if (argv[1][0] == '-' && ((argv[1][1] == 's' && argv[1][2] == 'j') || (argv[1][1] == 'j' && argv[1][2] == 's'))) {
				intro = false;
				jap = true;
			}
			else
				error = true;
		}
		else
			error = true;
	}
	else if (argc == 3) {
		if (mx_strlen(argv[1]) == 2 && mx_strlen(argv[2]) == 2) {
			if (((argv[1][0] == '-' && argv[1][1] == 's') && (argv[2][0] == '-' && argv[2][1] == 'j')) || ((argv[1][0] == '-' && argv[1][1] == 'j') && (argv[2][0] == '-' && argv[2][1] == 's'))) {
				intro = false;
				jap = true;
			}
			else
				error = true;
		}
    }
	else if (argc > 3)
		error = true;
	if (error) {
		write(1, "usage: ./matrix_rain [-s] [-j] (s - screensaver mode; j - japanese)\n", 68);
		exit(0);
	}
    if (intro)
        flags[0] = '1';
    if (jap)
        flags[1] = '1';
}

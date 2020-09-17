void mx_printchar(char);

void mx_cube(int n) {
	if (n < 2)
		return;
	int vertical = n;
	int horizontal = n * 2;
	int diagonal = n / 2;
	for (int i = 0; i < diagonal + 1; i++)
		mx_printchar(' ');
	mx_printchar('+');
	for (int i = 0; i < horizontal; i++)
		mx_printchar('-');
	mx_printchar('+');
	mx_printchar('\n');
	int space = diagonal;
	for (int i = 0; i < diagonal; i++, space--) {
		for (int j = 0; j < space; j++)
			mx_printchar(' ');
		mx_printchar('/');
		for (int j = 0; j < horizontal; j++)
			mx_printchar(' ');
		mx_printchar('/');
		for (int j = 0; j < diagonal - space; j++)
			mx_printchar(' ');
		mx_printchar('|');
		mx_printchar('\n');
	}
	mx_printchar('+');
	for (int i = 0; i < horizontal; i++)
		mx_printchar('-');
	mx_printchar('+');
	for (int i = 0; i < diagonal; i++)
		mx_printchar(' ');
	mx_printchar('|');
	mx_printchar('\n');
	space = diagonal;
	for (int i = 0; i < vertical; i++)
	{
		if ((vertical / 2 < i + 1 && vertical % 2 == 0) ||
			(vertical / 2 < i && vertical % 2 == 1))
			space--;
		mx_printchar('|');
		for (int i = 0; i < horizontal; i++)
			mx_printchar(' ');
		mx_printchar('|');
		for (int j = 0; j < space; j++)
			mx_printchar(' ');
		if ((vertical / 2 == i + 1 && vertical % 2 == 0) ||
			(vertical / 2 == i && vertical % 2 == 1))
			mx_printchar('+');
		else if (space < vertical / 2)
			mx_printchar('/');
		else
			mx_printchar('|');
		mx_printchar('\n');
	}
	mx_printchar('+');
	for (int i = 0; i < horizontal; i++)
		mx_printchar('-');
	mx_printchar('+');
	mx_printchar('\n');
}

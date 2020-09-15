#include <stdio.h>
#include <stdbool.h>
#include "t11/mx_is_mersenne.c"

int main() {
	bool a = mx_is_mersenne(1);
	printf("%d\n", a);
	return 0;
}

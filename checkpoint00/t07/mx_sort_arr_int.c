void mx_sort_arr_int(int *arr, int size) {
	int p, i = 0;
	do {
		p = 0;
		for (; i < size - 1; i++)
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				p = 1;
			}
		i = 0;
	} while (p == 1);
}

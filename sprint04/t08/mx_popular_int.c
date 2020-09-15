int mx_popular_int(const int *arr, int size) {
	int pop = 0, num = 0;
	for (int i = 0; i < size; i++) {
		int current_num = arr[i], current_pop = 0;
		for (int j = 0; j < size; j++) {
			if (arr[j] == current_num)
				current_pop++;
		}
		if (current_pop > pop) {
			pop = current_pop;
			num = current_num;
		}
	}
	return num;
}

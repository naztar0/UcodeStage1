void mx_arr_rotate(int *arr, int size, int shift) {
	if (shift < 0) {
		shift = -shift;
		for (int i = 0; i < shift; i++) {
			int temp = arr[0], j;
			for (j = 0; j < size - 1; j++)
				arr[j] = arr[j + 1];
			arr[j] = temp;
		}
	}
	else
        for(int i = 0; i < shift; i++) {    
            int temp = arr[size - 1], j;
            for(j = size - 1; j > 0; j--)
                arr[j] = arr[j - 1];   
            arr[0] = temp;
        }
}

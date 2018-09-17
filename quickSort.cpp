#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int l, int r) {
	int i = l;
	int j = r;
	while (i <= j) {
		for (; i < r; i++) {
			if (arr[i] > arr[r]) break;
		}
		for (; j > l; j--) {
			if (arr[j] < arr[r]) break;
		}
		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
	}
	if (i > j & i < r) {
		swap(&arr[i], &arr[r];
		quickSort(arr, l, i - 1);
		quickSort(arr, i + 1, r);
	}
}

int main() {
	int arr[] = {10, 80, 30, 90, 40, 50, 70};
	int n = sizeof(arr)/sizeof(arr[0];
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		count << arr[i] << endl;
	system ("pause");
	return 0;
}
	
	
			
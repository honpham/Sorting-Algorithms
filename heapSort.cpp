// C++ program to implement Quick Sort
#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// This function takes last element as pivot, places the pivot element at its correct position in sorted array
// And places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
int partition(int arr[], int l, int r) {
	int i = l; // Index of smaller element
	int pivot = arr[r]; // pivot value
	for (int j = l; j < r; j++) {
		// If current element is smaller than of equal to pivot
		if (arr[j] <= pivot) {
			swap(&arr[j], &arr[i]);
			i++; // increment index of smaller element
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

// The main function that implements quick sort
// arr[] --> Array to be sorted
// l --> Starting index
// r --> Ending index
void quickSort(int arr[], int l, int r) {
	if (l < r) {
		// pivot is partitioning index, arr[pivot] is now at right place
		int pivot = partition(arr, l, r);
		// Separately sort elements before and after partition
		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, r);
	}
}

// Driver program to test above functions
int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	system("pause");
	return 0;
}
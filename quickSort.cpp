// C++ implementation Quick Sort

#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// This function takes last element as pivot, places the pivot element at its correct position in sorted array
// and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot

int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // pivot element
	int i = low - 1; // Index of smaller element than pivot
	for (int j = low; j < high-1; j++) {
		if (arr[j] <= arr[pivot]) {
			i++; // Increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap (arr[i+1], arr[pivot]);
	return (i+1);
}
// The main function that implements quick sort
// arr[] --> Array to be sorted
// low --> Starting index
// high --> Ending index
void quickSort(int arr[], int l, int r) {
	if (low < high) {
		// pi is partitioning index, arr[pi] is now at right place
		int pi = partition(arr, low, high);
		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
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
	
	
			

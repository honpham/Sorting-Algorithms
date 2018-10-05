/*
C++ implementation of Radix Sort
*/
#include <iostream>
using namespace std;
#define K 9

// A utinity function to find the maximum value in arr[]
int maxElementInArray(int arr[], int n) {
	int max_element = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max_element) {
			max_element = arr[i];
		}
	}
	return max_element;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp
void countingSort(int arr[], int n, int exp) {
	// Auxiliary array
	int aux[n];
	// Create a count array to store count of inidividual
	// characters and initialize count array as 0
	int count[10] = {0};

	// Store count of occurrences in count[]
	for (int j = 0;  j < n; j++) {
		count[ (arr[j] / exp) % 10]++;
	}

	// Change count[j] so that count[j] now contains actual
	// position ofthis digit in aux[]
	for (int j = 1; j <= 9; j++) {
		count[j] = count[j] + count[j-1];
	}

	// Build the auxiliary array
	// if use int j = 0; j < n; j++ then it not stable
	for (int j = n - 1; j >= 0; j--) {
		aux[count[(arr[j] / exp) % 10] - 1] = arr[j];
		count[(arr[j] / exp) % 10]--;
	}

	// Copy the auxiliary array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (int j = 0; j < n; j++) {
		arr[j] = aux[j];
	}

}

// The main funciton to that sorts arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
	int max_element = maxElementInArray(arr, n);
	for (int exp = 10; max_element/exp > 0; exp = exp*10) {
		countingSort(arr, n, exp);
	}
}

// The driver function te test above function
int main() {
	int arr[] = {170, 90, 802, 2, 24, 45, 75, 66};
	int n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	system("pause");
	return 0;
}


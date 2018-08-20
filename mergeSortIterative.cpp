// Hon Pham: C++ program for implementation of Merge sort
/*
1. What it is?
- The selection sort algorithm sorts an array by repeatedly finding the minimum/maximum element from unsorted part and putting it at the beginning.
2. Why do we need this algorithm?
- The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is costly operation
3. How do we implement it and what are special things to know? 
- It is very easy to implement but it is not stable so if you need stability then instead of swapping,
  the minimum element is palced in its position without swapping by pushing every element one step forward (code in comment bellow)
4. What are the real problems that can be applied this algorithm to it and How?
- It is useful when the number of elements are small and memory write is a costly operation
*/
#include <iostream>
using namespace std;

// Merges two subarrays of arr[]
// First subarray is arr[1..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	// Create temp arrays
	int L[n1], R[n2];
	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l+i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m+1+j];
	// Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for large l and harderr
		int m = l + (r-l)/2;
		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

// Driver program to test above functons
int main() {
	int a[] = {23, 13, 15, 43, 19};
	int n = sizeof(a)/sizeof(a[0]);
	mergeSort(a, 0, n);
	// Print an array
	for (int k = 0; k < n; k++)
		cout << a[k] << endl;
	// Stop screen console to watch results
	system("pause");
	return 0;
}
// Hon Pham: C++ program for implementation of Selection Sort 
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

// A utility function to swap two elements of an array
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// A function to implement selection sort
void selectionSort(int a[], int n) {
	int i, j, h, min_element;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++) {
		min_element = a[i]; // Variable to save value of minimum element in an array
		h = 0; // Variable to save the index of minimum element in unsorted array
		// Find the minimum element in unsorted array
		for (j = i+1; j < n; j++) {
			if (a[j] < min_element) {
				min_element = a[j];
				h = j;
			}
		}
		// Swap the found minimun element with the first element
		if (h != 0) {
			swap(&a[i], &a[h]);
		}
		// Stable selection sort by pushing every element one step forward instead of swapping
		/*
		while (h > i) {
			a[h] = a[h - 1];
			h--;
		}
		a[i] = min_element;
		*/
	}
}

// Driver program to test above functons
int main() {
	int a[] = {23, 13, 15, 43, 19};
	int n = sizeof(a)/sizeof(a[0]);
	selectionSort(a, n);
	// Print an array
	for (int k = 0; k < n; k++)
		cout << a[k] << endl;
	// Stop screen console to watch results
	system("pause");
	return 0;
}
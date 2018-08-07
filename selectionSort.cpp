// Hon Pham: C++ program for implementation of Selection Sort 
/*
1. What it is?
The simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order
2. Why do we need this algorithm?
- It has capability to detect a very small error (like swap of just two elements and fix it with just linear complexity (2n))
3. How do we implement it and what are special things to know? 
- Pay attention to situations that we can stop the algorithm. (checkswap)
- Pay attention to the indexs of loops that we can reduce number of loop( i < n-1, j < n-i-1) 
4. What are the real problems that can be applied this algorithm to it and How?

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
	}
}

// Driver program to test above functons
int main() {
	int a[] = {23, 13, 15, 43, 19};
	int n = sizeof(a)/sizeof(a[0]);
	SelectionSort(a, n);
	// Print an array
	for (int k = 0; k < n; k++)
		cout << a[k] << endl;
	// Stop screen console to watch results
	system("pause");
	return 0;
}
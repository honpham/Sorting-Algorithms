// Hon Pham: C++ program for implementation of Bubble Sort 
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
void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// A function to implement bubble sort
void bubbleSort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		// Variable to check if two elements were swapped by inner loop or not
		bool checkswap = false;
		// j < n-i-1 because last element are already in place after each loop
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j+1] < a[j]) {
				swap(*a[j], *a[j+1]);
				checkswap = true;
			}
		}
		// If no two elements were swapped by inner loop, then break
		if (checkswap == false) break;
	}
}

// Driver program to test above functons
int main() {
	int a[] = {23, 13, 15, 43, 19};
	int n = sizeof(a)/sizeof(a[0]);
	bubbleSort(a, n);
	// Print an array
	for (int k = 0; k < n; k++)
		cout << a[k] << endl;
	// Stop screen console to watch results
	system("pause");
	return 0;
}
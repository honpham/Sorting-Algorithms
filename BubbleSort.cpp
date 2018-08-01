// Hon Pham: C++ program for implementation of Bubble Sort 
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
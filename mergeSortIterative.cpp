/*
1. What it is?
- Merge sort is a Divide and Conquer algorithm
2. Why do we need this algorithm?(compare with another sorting algorithms)
- Merge sort is useful for sorting linked lists
3. How do we implement it and what are special things to know? 
4. What are the real problems that can be applied this algorithm to it and How?
- Used in External Sorting
*/
// Iterative C++ program for merge sort
#include <iostream>
using namespace std;

// Function to merge the two halves arr[lt..mid] and arr[mid+1..rt] of array arr[lt..rt]
void merge(int a[], int lt, int mid, int rt) {
	int i, j;
	int n1 = mid - lt + 1;
	int n2 = rt - mid;
	// Create temp arrays
	int L[n1], R[n2];
	// Copy data to temp arrays L[] and R[]
	for (i = 0; i <= n1; i++)
		L[i] = a[lt + i];
	for (j = 0; j < n2; j++)
		R[j] = a[mid+1+j];
	
	// Merge the temp arrays back into arr[lt..rt]
	i = 0;
	j = 0;
	
	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			a[lt] = L[i];
			i++;
		}
		else {
			a[lt] = R[j];
			j++;
		}
		lt++;
	}
	
	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		a[lt] = L[i];
		i++;
		lt++;
	}
	
	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		a[lt] = R[j];
		j++;
		lt++;
	}
}

// Iterative Merge Sort function to sort arr[0..n-1]
void mergeSortIterative(int a[], int n) {
	int current_size = 1; // For current size of subarrays to be merged
	int lt, mid, rt; // Index of subarrays to be merged
	int pt; // Point for picking starting index of left subarray to me merged
	for (; current_size < n; current_size = 2*current_size) {
		for (pt = 0; pt < n; pt += 2*current_size) {
			// Pick starting point of different subarrays of current size
			lt = pt;
			// Find ending point of left subarray: mid + 1 is starting point of right subarray
			mid = pt + current_size - 1;
			rt = (mid + current_size < n) ? (mid + current_size) : (n - 1);
			// Merge subarrays arr[lt..mid] and arr[mid+1..rt]
			merge(a, lt, mid, rt);
		}
	}
}

// Driver program to test above functions
int main() {
	int a[] = {2, 3, 1, 6, 5, 4};
	int n = sizeof(a)/sizeof(a[0]);
	mergeSortIterative(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	system("pause");
	return 0;
}
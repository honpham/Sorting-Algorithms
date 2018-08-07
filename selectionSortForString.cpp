// Hon Pham: C++ program to implement selection sort for array of strings
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
#include <cstring>
#define MAX_LEN 200
using namespace std;

//Sorts an array of strings where length of every string should be smaller than MAX_LEN
void selectionSortForString(char arr[][MAX_LEN], int n) {
	int i, j, min_idx;
	// One by one move boundary of unsorted subarray
	char minStr[MAX_LEN];
	for (i = 0; i < n-1; i++) {
		// Find the minimum element in unsorted array
		int min_idx = i;
		strcpy(minStr, arr[i]);
		for (j = i+1; j < n; j++) {
			// If min is greater than arr[j]
			if (strcmp(minStr, arr[j]) > 0) {
				// Make arr[j] as minStr and update min_idx
				strcpy(minStr, arr[j]);
				min_idx = j;
			}
		}
		// Swap the found minimum element with the first element
		if (min_idx != i) {
			char temp[MAX_LEN];
			strcpy(temp, arr[i]);
			strcpy(arr[i], arr[min_idx]);
			strcpy(arr[min_idx], temp);
		}
		// Stable selection sort by pushing every element one step forward instead of swapping
		/*
		while (min_idx > i) {
			a[min_idx] = a[min_idx - 1];
			min_idx--;
		}
		strcpy(arr[i], minStr);
		*/
	}
}
// Driver program to test above functons
int main() {
	char a[][MAX_LEN] = {"hon", "cong", "minh", "phong"};
	int n = sizeof(a)/sizeof(a[0]);
	selectionSortForString(a, n);
	// Print an array
	for (int k = 0; k < n; k++)
		cout << a[k] << endl;
	// Stop screen console to watch results
	system("pause");
	return 0;
}
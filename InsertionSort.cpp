// Hon Pham: C++ program for implementation of Insertion Sort 
/*
1. What it is?
- This is a simple sorting algorithm that works the way we sort playing cards in our hands
2. Why do we need this algorithm?(compare with another sorting algorithms)
- It is useful when combine with Linked list: Reduce the number of movements in array (Only need one shift)
- It is useful when combine with Binary search: Reduce the number of comparisons in normal insertion sort from O(i) to O(log(i))
- Is is stable: Doesn't change the relative order of elements with equal keys
3. How do we implement it and what are special things to know? 
- Need to understand the nature of algorithm otherwise the time complexity will be much larger
  Instead of finding the proper postion of the key and then moving the element, we should move the elements in array at each loop :it will take O(n3)
4. What are the real problems that can be applied this algorithm to it and How?
- Insertion sort is used when number of elements is small, when input array is almost sorted
- Sort playing cards in our hands
*/
#include <iostream>
using namespace std;

// A function to sort an array using insertion sort
void insertionSort(int a[], int n) {
	int i, j, key;
	for (i = 1; i < n-1; i++) {
		key = a[i];
		// Move elements of arr[0..i-1] that are greater than key, to one position ahead of their current position
		for (j = i-1; j >= 0; j--) {
			if (a[j] > key)
				a[j+1] = a[j];
			else break;
		}
		// If there are noe elements of arr[0..j] that are greater than key then stop the loop and assign a[j+1] equal key
		a[j+1] = key;
	}
}
// Driver program to test above functons
int main() {
	int a[] = {23, 13, 15, 43, 19};
	int n = sizeof(a)/sizeof(a[0]);
	insertionSort(a, n);
	// Print an array
	for (int k = 0; k < n; k++)
		cout << a[k] << endl;
	// Stop screen console to watch results
	system("pause");
	return 0;
}
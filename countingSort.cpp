/*
C++ program for Counting Sort
*/
#include <iostream>
#include <cstring>
using namespace std;
#define K 255

// The main function that sort the given string arr[] in alphabatical order
void countingSort(char arr[]) {

	// The output character array that will have sorted arr
	char aux[strlen(arr)];

	// Create a count array to store count of inidividual
	// characters and initialize count array as 0
	int count_arr[K+1];
	for (int i = 0; i <= K; i++)
		count_arr[i] = 0;
	/*
	memset(count_arr, 0, sizeof(count_arr));
	int count_arr[K+1] = {0};
	*/
	// Store count of each character
	for (int i = 0; i < strlen(arr); i++)
		count_arr[arr[i]] = count_arr[arr[i]] + 1;

	// Change count_arr[i] so that count_arr[i] now contains actual
	// position of this character in output array
	for (int i = 1; i <= K; i++)
		count_arr[i] = count_arr[i-1] + count_arr[i];

	// Build the auxiliary character array
	// If want counting sort stable then reverse the value ò x
	// int i = n - 1; i >= 0; i--
	for (int i = 0; i < strlen(arr); i++) {
		aux[count_arr[arr[i]] - 1] = arr[i];
		count_arr[arr[i]] = count_arr[arr[i]] - 1;
	}
	// Copy the auxiliary array to arr, so that arr now contains sorted characters
	for (int i = 0; i < strlen(arr); i++)
		arr[i] = aux[i];
}

// Driver program to test above function
int main() {
	char arr[] = "ifhafiajeeifhwafenfsdvnuvb";
	countingSort(arr);
	cout << arr << endl;
	return 0;
	system("pause");
}
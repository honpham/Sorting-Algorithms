#include <iostream>
using namespace std;

void merge(int a[], int lt, int mid, int rt) {
	int i, j, k;
	int n1 = mid - lt + 1;
	int n2 = rt - mid;
	
	int L[n1], R[n2];
	
	for (i = 0; i <= n1; i++)
		L[i] = a[lt + i];
	for (j = 0; j < n2; j++)
		R[j] = a[mid+1+j];
	
	i = 0;
	j = 0;
	k = lt;
	
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
	while (i < n1) {
		a[lt] = L[i];
		i++;
		lt++;
	}
	while (j < n2) {
		a[lt] = R[j];
		j++;
		lt++;
	}
}
void mergeSortIterative(int a[], int n) {
	int current_size = 1;
	int lt, mid, rt; // position of subarray to merge
	int pt; // pointer
	for (; current_size < n; current_size = 2*current_size) {
		for (pt = 0; pt < n; pt += 2*current_size) {
			lt = pt;
			mid = pt + current_size - 1;
			rt = (mid + current_size < n) ? (mid + current_size) : (n - 1);
			merge(a, lt, mid, rt);
		}
	}
int main() {
	int a[] = {2, 3, 1, 6, 5, 4};
	int n = sizeof(a)/sizeof(a[0]);
	mergeSortIterative(a, n);
	for (int i = 0; i < n; i++)
		count << a[i] << endl;
	system("pause");
	return 0;
}
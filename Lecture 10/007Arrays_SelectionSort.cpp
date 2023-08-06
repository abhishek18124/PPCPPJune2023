#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n - 1; i++) {

		// in the ith pass, place the smallest element in the unsorted
		// part of the arr[] to its correct position

		int cpos = i;
		int min_idx = i;

		for (int j = i + 1; j <= n - 1; j++) {

			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}

		}

		swap(arr[cpos], arr[min_idx]);

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
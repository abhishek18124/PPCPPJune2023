#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int numComparisions = 0;

	for (int i = 1; i <= n - 1; i++) {

		// for the ith pass, place the largest element in the unsorted part
		// of the arr[] to its correct position

		bool flag = false; // assume no swaps will be done in the ith pass

		for (int j = 0; j < n - i; j++) {

			numComparisions++;

			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = true;
			}

		}

		if (flag == false) {
			// no swaps were done in the ith pass therefore we can stop
			break;
		}

	}

	cout << numComparisions << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// iterate over all the possible starting indices
	for (int i = 0; i <= n - 1; i++) {

		// for given starting index 'i', iterate over all the possible ending indices

		for (int j = i; j <= n - 1; j++) {

			// print the subarray arr[i...j]

			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;

		}

		cout << endl;

	}

	return 0;
}
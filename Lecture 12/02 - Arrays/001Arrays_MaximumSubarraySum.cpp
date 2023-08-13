#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	int maxSum = INT_MIN;

	// iterate over all the possible starting indices

	for (int i = 0; i < n; i++) {

		// for the given starting index i, iterate over all the possible ending indices

		for (int j = i; j < n; j++) {

			// compute the sum of arr[i..j]

			int sum = 0;

			for (int k = i; k <= j; k++) {

				sum += arr[k];

			}

			maxSum = max(maxSum, sum);

		}

	}

	cout << maxSum << endl;

	return 0;
}
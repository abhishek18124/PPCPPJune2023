// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	int csum[101];
	csum[0] = 0;

	// time : O(n)

	// space : n+1 due to csum[] ~ O(n)

	for (int i = 1; i <= n; i++) {
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	// time : O(n^2)

	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// compute the sum of arr[i...j]

			int sum = csum[j + 1] - csum[i];

			maxSum = max(maxSum, sum);

		}

	}

	cout << maxSum << endl;

	return 0;
}
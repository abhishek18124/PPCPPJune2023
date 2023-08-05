#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	int i;

	// in the worst case (t not found), our algorithm will take n-steps

	// time : O(n)

	for (i = 0; i <= n - 1; i++) {

		if (arr[i] == t) {

			// you've found the 1st occurrence of the 't' at the ith index

			cout << i << endl;
			break;

		}

	}

	if (i == n) {

		// 't' was not found in the arr[]

		cout << -1 << endl;
	}

	return 0;
}
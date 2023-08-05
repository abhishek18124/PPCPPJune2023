#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 30;

	int i;

	// time : O(n)

	for (i = n - 1; i >= 0; i--) {

		if (arr[i] == t) {

			// you've found the last occurrence of the 't' at the ith index

			cout << i << endl;
			break;

		}

	}

	if (i == -1) {

		// 't' was not found in the arr[]

		cout << -1 << endl;
	}

	return 0;
}
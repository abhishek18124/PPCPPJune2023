#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 40;

	int i;

	// time : O(n)

	bool flag = false; // assume 't' is not present

	for (i = 0; i <= n - 1; i++) {

		if (arr[i] == t) {

			// you've found the occurrence of the 't' at the ith index
			flag = true;
			cout << i << endl;

		}

	}

	// if (flag == false) {

	// 	// 't' was not found in the arr[]

	// 	cout << -1 << endl;
	// }

	if (!flag) {

		// 't' was not found

		cout << -1 << endl;

	}

	return 0;
}
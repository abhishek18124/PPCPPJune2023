#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		// int m = (s + e) / 2;

		int m = s + (e - s) / 2;

		if (arr[m] == t) {
			cout << m << endl;
			break;
		} else {
			if (t > arr[m]) {
				// reduce the search space from [s, e] to [m+1, e]
				s = m + 1;
			} else { // t < arr[m]
				// reduce the search space from [s, e] to [s, m-1]
				e = m - 1;
			}
		}
	}

	if (s > e) {
		// 't' was not found
		cout << -1 << endl;
	}

	return 0;
}
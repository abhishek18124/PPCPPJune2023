#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	int count = 0;

	// // time : O(n^2)

	// for (int i = 0; i <= n - 2; i++) {
	// 	for (int j = i + 1; j <= n - 1; j++) {
	// 		int pair_sum = arr[i] + arr[j];
	// 		if (pair_sum == t) {
	// 			count++;
	// 		}
	// 	}
	// }

	// time : O(n)
	// space : O(1)

	int i = 0;
	int j = n - 1;

	while (i < j) {

		int pairSum = arr[i] + arr[j];

		if (pairSum == t) {

			count++;
			i++;
			j--;

		} else if (pairSum > t) {

			j--;

		} else { // pairSum < t

			i++;

		}

	}

	cout << count << endl;

	return 0;
}
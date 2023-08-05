#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 15;

	int cnt = 0;

	// while (n > 0) {

	// 	// check if the 0th bit of n is set or not

	// 	if ((n & 1) == 1) {

	// 		// 0th bit of n is set

	// 		cnt++;

	// 	}

	// 	n = n >> 1;

	// }

	// for (int k = 0; k <= 31; k++) {

	// 	// check if the kth bit of n is set

	// 	if (n & (1 << k)) {
	// 		// kth bit is set

	// 		cnt++;
	// 	}

	// }

	for (int k = 0; k <= ceil(log2(n + 1)); k++) {

		// check if the kth bit of n is set

		if (n & (1 << k)) {
			// kth bit is set

			cnt++;
		}

	}

	cout << cnt << endl;

	return 0;
}
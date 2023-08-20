// n <= 100

#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// n-steps

	int l[100];
	l[0] = h[0];
	for (int i = 1; i < n; i++) {
		l[i] = max(l[i - 1], h[i]);
	}

	// n-steps

	int r[100];
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int totalWater = 0;

	// n-steps

	for (int i = 0; i < n; i++) {

		// compute the amount of water trapped on top of the ith building

		int w_i = min(l[i], r[i]) - h[i];
		totalWater += w_i;

	}

	// time : 3n steps ~ O(n)

	// space : 2n (due to l[] and r[]) ~ O(n)

	cout << totalWater << endl;

	return 0;
}
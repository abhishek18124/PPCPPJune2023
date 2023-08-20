// n <= 100

#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// n-steps

	int r[100];
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int totalWater = 0;
	int l_i = 0;

	// n-steps

	for (int i = 0; i < n; i++) {

		// compute the amount of water trapped on top of the ith building

		l_i = max(l_i, h[i]);

		int w_i = min(l_i, r[i]) - h[i];
		totalWater += w_i;

	}

	// time : 2n steps ~ O(n)

	// space : n (due to l[]) ~ O(n)

	cout << totalWater << endl;

	return 0;
}
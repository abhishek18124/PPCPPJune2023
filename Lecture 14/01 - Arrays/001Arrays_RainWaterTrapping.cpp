#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int totalWater = 0;

	// time : O(n^2)
	// space : O(1)

	for (int i = 0; i < n; i++) {

		// compute the amount of water trapped on top of the ith building

		int l_i = h[i];
		for (int j = i - 1; j >= 0; j--) {
			l_i = max(l_i, h[j]);
		}

		int r_i = h[i];
		for (int j = i + 1; j <= n - 1; j++) {
			r_i = max(r_i, h[j]);
		}

		int w_i = min(l_i, r_i) - h[i];
		totalWater += w_i;

	}

	cout << totalWater << endl;

	return 0;
}
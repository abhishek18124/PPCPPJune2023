#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int i = 0;
	int j = n - 1;

	int l = 0; // or INT_MIN or h[0]   : max(0 to i)
	int r = 0; // or INT_MIN or h[n-1] : max(j to n-1)

	int totalWater = 0;

	// time : O(n)
	// space : O(1)

	while (i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if (l < r) {

			int w_i = l - h[i];
			totalWater += w_i;
			i++;

		} else {

			int w_j = r - h[j];
			totalWater += w_j;
			j--;

		}

	}

	cout << totalWater << endl;

	return 0;
}
#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int h[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(h) / sizeof(int);

	int maxArea = 0; // or INT_MIN

	// // time : O(n^2) // space : O(1)

	// for (int i = 0; i <= n - 2; i++) {

	// 	for (int j = i + 1; j <= n - 1; j++) {

	// 		int height_ij = min(h[i], h[j]);
	// 		int width_ij = j - i;
	// 		int area_ij = height_ij * width_ij;

	// 		maxArea = max(maxArea, area_ij);

	// 	}

	// }

	// time : O(n)
	// space : O(1)

	int i = 0;
	int j = n - 1;

	while (i < j) {

		int area_ij = min(h[i], h[j]) * (j - i);
		maxArea = max(maxArea, area_ij);

		if (h[i] < h[j]) {
			i++;
		} else {
			j--;
		}

	}

	cout << maxArea << endl;

	return 0;
}
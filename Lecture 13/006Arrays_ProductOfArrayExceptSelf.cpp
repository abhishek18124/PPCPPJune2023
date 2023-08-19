// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	int answer[100];

	// time : O(n^2)

	// space : O(1) excluding answer[]

	for (int i = 0; i < n; i++) {

		int l_i = 1; // product of elements nums[0...i-1]
		for (int j = i - 1; j >= 0; j--) {
			l_i *= nums[j];
		}

		int r_i = 1; // product of elements nums[i+1...n-1]
		for (int j = i + 1; j < n; j++) {
			r_i *= nums[j];
		}


		answer[i] = l_i * r_i;

	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;

	return 0;
}
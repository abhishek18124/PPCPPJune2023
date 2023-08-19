// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	int l[100];
	l[0] = 1;
	for (int i = 1; i < n; i++) {
		l[i] = l[i - 1] * nums[i - 1];
	}

	int r[100];
	r[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		r[i] = r[i + 1] * nums[i + 1];
	}

	int answer[100];

	for (int i = 0; i < n; i++) {

		answer[i] = l[i] * r[i];

	}

	// time : n + n + n = 3.n ~ O(n)

	// space : n (due to l[]) + n (due to r[]) = 2.n ~ O(n)

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;

	return 0;
}
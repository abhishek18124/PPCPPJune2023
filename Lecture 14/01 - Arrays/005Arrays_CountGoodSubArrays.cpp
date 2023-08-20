// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	// time : O(n)
	// space : O(n) due to freq[]

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	int freq[100] = {};
	freq[0] = 1;

	// memset(freq, 0, sizeof(freq));

	int csum = 0;

	for (int i = 0; i < n; i++) {
		csum += arr[i];

		// freq[csum % n]++;

		freq[((csum % n) + n) % n]++;
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		int x_i = freq[i];
		if (x_i >= 2) {
			count += (x_i * (x_i - 1)) / 2;
		}
	}

	cout << count << endl;

	// cout << (-17 % 3) << endl;

	return 0;
}
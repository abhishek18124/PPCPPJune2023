#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	// num of steps = n/2 ~ O(n)
	// no extra space ~ O(1)

	int i = 0;
	int j = n - 1;

	while (i < j) {

		swap(arr[i], arr[j]);
		i++;
		j--;

	}

	for (int k = 0; k < n; k++) {
		cout << arr[k] << " ";
	}

	cout << endl;

	return 0;
}
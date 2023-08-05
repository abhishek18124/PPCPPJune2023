#include<iostream>

using namespace std;

int main() {

	int arr[5];

	cout << "sizeof(arr) = " << sizeof(arr) << "B" << endl;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	// cout << "arr[0] = " << arr[0] << endl;
	// cout << "arr[1] = " << arr[1] << endl;
	// cout << "arr[2] = " << arr[2] << endl;
	// cout << "arr[3] = " << arr[3] << endl;
	// cout << "arr[4] = " << arr[4] << endl;

	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i <= n - 1; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// double brr[10];

	// cout << "sizeof(brr) = " << sizeof(brr) << "B" << endl;

	// char str[10];

	// cout << "sizeof(str) = " << sizeof(str) << "B" << endl;

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	int B[5] = {100, 200, 300, 400, 500};
	for (int i = 0; i < 5; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	int C[5];

	memset(C, 0, sizeof(C));

	for (int i = 0; i < 5; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	int D[5] = {};

	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	return 0;
}
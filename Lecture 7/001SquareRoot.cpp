#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	float square_root = 0;

	while (square_root * square_root <= n) {
		square_root = square_root + 1;
	}

	square_root = square_root - 1;

	cout << square_root << endl;

	while (square_root * square_root <= n) {
		square_root = square_root + 0.1;
	}

	square_root = square_root - 0.1;

	cout << square_root << endl;

	while (square_root * square_root <= n) {
		square_root = square_root + 0.01;
	}

	square_root = square_root - 0.01;

	cout << square_root << endl;

	while (square_root * square_root <= n) {
		square_root = square_root + 0.001;
	}

	square_root = square_root - 0.001;

	cout << square_root << endl;


	return 0;
}
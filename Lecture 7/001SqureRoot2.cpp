#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cout << "Enter a positive integer";
	cin >> p;

	float square_root = 0;

	int i = 0;

	float inc = 1;

	while (i <= p) {

		while (square_root * square_root <= n) {
			square_root = square_root + inc;
		}

		square_root = square_root - inc;
		inc = inc / 10;

		i = i + 1;

	}

	cout << square_root << endl;


	return 0;
}
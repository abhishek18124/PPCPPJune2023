#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	if (n == 0 || n == 1) {

		cout << n << endl;

	} else {

		// (n-1).c = nc - c ~ nc

		// time : O(n)

		int a = 0; // to store the 0th fib. no.
		int b = 1; // to store the 1st fib. no.

		int i = 2;
		while (i <= n) {

			int c = a + b;
			a = b;
			b = c;

			i = i + 1;

		}

		// cout << c << endl; // error : since 'c' is out of scope
		cout << b << endl;

	}

	return 0;
}
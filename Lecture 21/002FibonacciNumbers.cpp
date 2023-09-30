#include<iostream>

using namespace std;

int f(int n) {

	// base case

	// if(n == 0) {

	// 	// compute 0th fibonacci number
	// 	return 0;

	// }

	// if(n == 1) {

	// 	// compute 1st fibonacci number
	// 	return 1;

	// }

	if (n == 0 || n == 1) {
		return n;
	}

	// recursive case

	// compute the nth fibonacci number

	// 1. ask your friend to compute n-1th fibonacci number
	int A = f(n - 1);

	// 2. ask your friend to compute n-2th fibonacci number
	int B = f(n - 2);

	return A + B;

}

int main() {

	int n = 8`;

	cout << f(n) << endl;

	return 0;
}
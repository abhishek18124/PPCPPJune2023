#include<iostream>

using namespace std;

// time : O(y)

int f1(int x, int y) {

	// base case

	if (y == 0) {

		// compute x^0

		return 1;

	}

	// recursive case

	// 1. ask your friend to compute x^(y-1)

	int A = f1(x, y - 1);

	return x * A;

}

// time : O(logy)

int f2(int x, int y) {

	// base case

	if (y == 0) {

		// compute x^0

		return 1;

	}

	// recursive case

	// 1. ask your friend to compute x^(y/2)

	int A = f2(x, y / 2);

	if (y % 2 == 0) {
		return A * A;
	}

	// y is odd

	return A * A * x;


}

int main() {

	int x = 2;
	int y = 3;

	cout << f1(x, y) << endl;

	cout << f2(x, y) << endl;

	return 0;
}
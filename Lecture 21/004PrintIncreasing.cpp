#include<iostream>

using namespace std;

void f(int n) {

	// base case

	// if (n == 1) {
	// 	cout << 1 << " ";
	// 	return;
	// }

	if (n == 0) {
		return;
	}

	// recursive case

	// print numbers from 1 to n in the increasing order

	// 1. ask your friend to print numbers from 1 to n-1 in the increasing order

	f(n - 1);

	cout << n << " ";

}

int main() {

	int n = 0;

	f(n);

	return 0;
}
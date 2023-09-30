#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	// print numbers from n to 1

	cout << n << " ";

	// 1. ask your friend to print numbers from n-1 to 1 in the increasing order

	f(n - 1);


}

int main() {

	int n = 5;

	f(n);

	return 0;
}
#include<iostream>

using namespace std;

void f(int n, char source, char helper, char destination) {

	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to move n-1 disks from A(source) to B(helper) using C(destination)
	f(n - 1, source, destination, helper);

	// 2. move the largest disk from A(source) to C(desintation)
	cout << "move disk from " << source << " to " << destination << endl;

	// 3. ask your friend to move n-1 disks from B(helper) to C(destination) using A(source)
	f(n - 1, helper, source, destination);

}

int main() {

	int n = 3;

	f(n, 'A', 'B', 'C');

	return 0;
}
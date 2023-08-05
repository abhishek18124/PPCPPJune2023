#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 3;

	// if ((n & (1 << k)) > 0) {
	// 	cout << k << "th bit is set" << endl;
	// } else {
	// 	cout << k << "th bit is not set" << endl;
	// }

	if ((n & (1 << k))) {
		cout << k << "th bit is set" << endl;
	} else {
		cout << k << "th bit is not set" << endl;
	}

	// if (((n >> k) & 1) == 1) {
	// 	cout << k << "th bit is set" << endl;
	// } else { // == 0
	// 	cout << k << "th bit is not set" << endl;
	// }

	if (((n >> k) & 1)) {
		cout << k << "th bit is set" << endl;
	} else { // == 0
		cout << k << "th bit is not set" << endl;
	}

	return 0;
}
#include<iostream>

using namespace std;

bool isEven(int n) {

	return n % 2 == 0;

}

int main() {

	// bool answer = isEven(7);

	// if (answer == true) {
	// 	cout << "even" << endl;
	// } else {
	// 	cout << "odd" << endl;
	// }

	if (isEven(11)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(12) ? cout << "even" << endl : cout << "odd" << endl;

	cout << isEven(5) << endl;

	cout << isEven(6) << endl;

	return 0;
}
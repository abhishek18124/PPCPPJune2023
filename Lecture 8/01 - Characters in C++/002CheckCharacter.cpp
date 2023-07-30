#include<iostream>

using namespace std;

int main() {

	char ch;
	cout << "enter a character : ";
	cin >> ch;

	if (ch >= 'a' and ch <= 'z') {

		cout << ch << " is lowercase" << endl;

	} else if (ch >= 'A' and ch <= 'Z') {

		cout << ch << " is uppercase" << endl;

	} else if (ch >= '0' and ch <= '9') {

		cout << ch << " is a digit" << endl;

	} else {

		cout << ch <<  " is a special character" << endl;

	}

	if (ch >= 97 and ch <= 122) {

		cout << ch << " is lowercase" << endl;

	} else if (ch >= 65 and ch <= 90) {

		cout << ch << " is uppercase" << endl;

	} else if (ch >= 48 and ch <= 57) {

		cout << ch << " is a digit" << endl;

	} else {

		cout << ch <<  " is a special character" << endl;

	}


	if ((int)ch >= 97 and (int)ch <= 122) {

		cout << ch << " is lowercase" << endl;

	} else if ((int)ch >= 65 and (int)ch <= 90) {

		cout << ch << " is uppercase" << endl;

	} else if ((int)ch >= 48 and (int)ch <= 57) {

		cout << ch << " is a digit" << endl;

	} else {

		cout << ch <<  " is a special character" << endl;

	}


	return 0;
}
#include<iostream>

using namespace std;

int main() {

	// int a = 25;
	// int b = 19;

	// cout << "a&b : " << (a & b) << endl;
	// cout << "a|b : " << (a | b) << endl;
	// cout << "a^b : " << (a ^ b) << endl;
	// cout << "~a  : " << (~a)  << endl;

	int a = 1;

	cout << (a << 1) << endl;
	cout << (a << 2) << endl;
	cout << (a << 3) << endl;

	a = 8;

	cout << (a >> 1) << endl;
	cout << (a >> 2) << endl;
	cout << (a >> 3) << endl;

	return 0;
}
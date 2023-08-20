#include<iostream>

using namespace std;

int main() {

	int x = 10;
	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << "B" << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;

	cout << endl;

	float y = 3.14;
	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << "B" << endl;
	cout << "&y = " << &y  << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;

	cout << endl;

	double z = 19.27;
	cout << "z = " << z << endl;
	cout << "sizeof(z) = " << sizeof(z) << "B" << endl;
	cout << "&z = " << &z  << endl;
	cout << "sizeof(&z) = " << sizeof(&z) << "B" << endl;

	cout << endl;

	char ch = 'A';
	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << "B" << endl;
	cout << "&ch = " << &ch  << endl;
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;


	return 0;
}
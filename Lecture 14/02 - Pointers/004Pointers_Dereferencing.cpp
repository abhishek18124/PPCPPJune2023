#include<iostream>

using namespace std;

int main() {

	// int x = 10;
	// int *xptr = &x;

	// cout << "x = " << x << endl;
	// cout << "sizeof(x) = " << sizeof(x) << endl;
	// cout << "xptr = " << xptr << endl;
	// cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	// cout << "*xptr = " << *xptr << endl;

	// cout << endl;

	// float y = 3.14;
	// float *yptr = &y;

	// cout << "y = " << y << endl;
	// cout << "sizeof(y) = " << sizeof(y) << endl;
	// cout << "yptr = " << yptr << endl;
	// cout << "sizeof(yptr) = " << sizeof(yptr) << endl;
	// cout << "*yptr = " << *yptr << endl;

	int x = 516;
	char* ptr = (char*)&x;
	cout << (int)*ptr << endl;


	return 0;
}
#include<iostream>

using namespace std;

void mySwap(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;

}

int main() {

	int a = 10;
	int b = 20;

	cout << "inside main() : before mySwap() a = " << a  << " b = " << b << endl;

	mySwap(a, b);

	cout << "inside main() : after mySwap() a = " << a  << " b = " << b << endl;

	return 0;
}
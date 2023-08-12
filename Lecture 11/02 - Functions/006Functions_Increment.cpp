#include<iostream>

using namespace std;

void incr(int a) {

	cout << "inside incr() : before ++ a = " << a << endl;

	a++;

	cout << "inside incr() : after ++ a = " << a << endl;

}

int main() {

	int a = 10;

	cout << "inside main() : before incr() a = " << a << endl;

	incr(a);

	cout << "inside main() : after incr() a = " << a << endl;


	return 0;
}
#include<iostream>

using namespace std;

int multiply(int a, int b) {

	int c = a * b;
	return c;

}

int main() {

	cout << multiply(2, 3) << endl;

	int answer = multiply(4, 5);

	cout << answer << endl;

	int sum = multiply(1, 2) + multiply(3, 4);

	cout << sum << endl;

	return 0;
}
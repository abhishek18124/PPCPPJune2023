#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;

	while (i <= n) {

		// in the ith row, print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}

		// followed by i stars

		for (int j = 1; j <= i; j++) {
			cout << "*";
		}

		cout << endl;

		i++;

	}

	return 0;
}
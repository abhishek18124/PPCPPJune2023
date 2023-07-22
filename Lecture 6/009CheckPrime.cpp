#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int rn = sqrt(n);

	int i = 2;

	while (i <= rn) {

		if (n % i == 0) {

			cout << n << " is not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i > rn) {
		cout << n << " is prime " << endl;
	}

	return 0;
}
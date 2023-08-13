#include<iostream>
#include<cmath>

using namespace std;


bool isPrime(int n) {

	for (int i = 2; i <= sqrt(n); i++) {

		if (n % i == 0) {

			return false;

		}

	}

	return true;

}

void printPrimes(int m) {

	for (int num = 2; num <= m; num++) {

		// check if 'num' is prime or not

		if (isPrime(num)) {
			cout << num << " ";
		}

	}

	cout << endl;

}

int main() {

	int m;
	cout << "Enter the value of m : ";
	cin >> m;

	printPrimes(m);

	return 0;
}
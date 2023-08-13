#include<iostream>
#include<cmath>

using namespace std;

// bool isPrime(int n) {

// 	for (int i = 2; i <= n - 1; i++) {

// 		if (n % i == 0) {

// 			return false;

// 		}

// 	}

// 	return true;

// }

bool isPrime(int n) {

	for (int i = 2; i <= sqrt(n); i++) {

		if (n % i == 0) {

			return false;

		}

	}

	return true;

}

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl : cout << n << " is not prime" << endl;

	// if(isPrime(n)) {
	// 	cout << n << " is prime" << endl;
	// } else {
	// 	cout << n << " is not prime" << endl;
	// }

	return 0;
}
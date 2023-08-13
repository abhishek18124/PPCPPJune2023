// m <= 100

#include<iostream>

using namespace std;

int main() {

	int sieve[101]; // based on the constraints

	int m;
	cin >> m;

	for (int i = 0; i <= m; i++) {
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;

	// for (int i = 2; i <= m; i++) {

	// 	if (sieve[i] == 1) {

	// 		// 'i' is a prime number

	// 		// therefore, none of its multiples can be prime

	// 		for (int j = 2 * i; j <= m; j += i) {

	// 			sieve[j] = 0;

	// 		}

	// 	}

	// }

	// for (int i = 2; i <= m; i++) {

	// 	if (sieve[i] == 1) {

	// 		// 'i' is a prime number

	// 		// therefore, none of its multiples can be prime

	// 		for (int j = i * i; j <= m; j += i) {

	// 			sieve[j] = 0;

	// 		}

	// 	}

	// }

	for (int i = 2; i * i <= m; i++) {

		if (sieve[i] == 1) {

			// 'i' is a prime number

			// therefore, none of its multiples can be prime

			for (int j = i * i; j <= m; j += i) {

				sieve[j] = 0;

			}

		}

	}

	for (int i = 2; i <= m ; i++) {
		if (sieve[i] == 1) {
			// i is a prime number
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}
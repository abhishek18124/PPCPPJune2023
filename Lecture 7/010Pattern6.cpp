#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;

	while (i <= n) {

		// for the ith row, print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << "  ";
		}

		// followed by i nos. starting from i in the incresing order

		// for (int j = 1, num = i; j <= i; j++, num++) {
		// 	cout << num << " ";
		// }

		int j = 1;
		int num = i;

		while (j <= i) {
			cout << num << " ";
			num++;
			j++;
		}

		cout << endl;

		i++;

	}

	return 0;
}
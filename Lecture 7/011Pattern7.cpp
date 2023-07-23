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


		int j = 1;
		int num = i;

		while (j <= i) {
			cout << num << " ";
			num++;
			j++;
		}

		// // print i-1 more nos. in the decreasing order starting from num-2

		// num = num - 2;

		// for (int j = 1; j <= i - 1; j++, num--) {
		// 	cout << num << " ";
		// 	// num--;
		// }

		// print i-1 more nos. in the dec. order starting from 2i-2

		for (int j = 1, num = 2 * i - 2; j <= i - 1; j++, num--) {
			cout << num << " ";
		}

		cout << endl;

		i++;

	}

	return 0;
}
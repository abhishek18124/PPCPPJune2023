#include<iostream>

using namespace std;

int main() {

	int xCount = 0; // to track the net movement along the x-axis
	int yCount = 0; // to track the net movement along the y-axis

	char ch;

	while (true) {

		ch = cin.get();

		if (ch == '\n') {
			break;
		}

		if (ch == 'N') {
			yCount++;
		} else if (ch == 'S') {
			yCount--;
		} else if (ch == 'E') {
			xCount++;
		} else { // ch == 'W'
			xCount--;
		}

	}

	cout << xCount << " " << yCount << endl;

	if (xCount > 0) {

		// move in the 'E' direction by xCount steps

		for (int i = 1; i <= xCount; i++) {
			cout << 'E';
		}

	}

	if (yCount > 0) {

		// move in the 'N' direction by yCount steps

		for (int i = 1; i <= yCount; i++) {
			cout << 'N';
		}

	}

	if (yCount < 0) {

		// move in the 'S' direction by -yCount steps

		for (int i = 1; i <= -yCount; i++) {
			cout << 'S';
		}

	}

	if (xCount < 0) {

		// move in the 'W' direction by -xCount steps

		for (int i = 1; i <= -xCount; i++) {
			cout << 'W';
		}

	}


	return 0;
}



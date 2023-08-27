#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	// for (int i = 0; i < str.size(); i++) {

	// 	char ch = str[i];

	// 	if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
	// 		// str is not a good string
	// 		return false;
	// 	}

	// }

	// // str is a good string
	// return true;

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// str is not a good string
			return false;
		}

	}

	// str is a good string
	return true;

}

int main() {

	string str = "uoiea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;
}
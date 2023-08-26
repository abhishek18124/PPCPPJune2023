// n <= 100

#include<iostream>

using namespace std;

void readString(char* str, char delimiter = '\n') {

	char ch;
	int i = 0;

	while (true) {
		ch = cin.get();
		if (ch == delimiter) {
			break;
		}
		str[i] = ch;
		i++;
	}

	str[i] = '\0';

}

int main() {

	char str[101];

	cout << "Enter a string : ";

	// cin >> str;

	// readString(str, '$');

	cin.getline(str, 5, '$'); // '\n' is default delimiter

	cout << "You've entered : " << str << endl;

	return 0;
}
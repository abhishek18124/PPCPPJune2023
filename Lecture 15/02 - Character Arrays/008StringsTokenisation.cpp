#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = "abc.de$..f.gh$i";
	char dlim[] = ".$";

	char* token = strtok(str, dlim);

	// cout << token << endl;

	// token = strtok(NULL, dlim);

	// cout << token << endl;

	// token = strtok(NULL, dlim);

	// cout << token << endl;

	while (token != NULL) {
		cout << token << endl;
		token = strtok(NULL, dlim);
	}

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	char grade;

	cout << "enter your grade : ";
	cin >> grade;

	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "poor" << endl;
	// } else if (grade == 'D') {
	// 	cout << "very poor" << endl;
	// } else if(grade == 'F') {
	// 	cout << "fail" << endl;
	// }


	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "poor" << endl;
	// } else if (grade == 'D') {
	// 	cout << "very poor" << endl;
	// } else {
	// 	cout << "fail" << endl;
	// }

	// if (grade == 'A') cout << "very good" << endl;
	// else if (grade == 'B') cout << "good" << endl;
	// else if (grade == 'C') cout << "poor" << endl;
	// else if (grade == 'D') cout << "very poor" << endl;
	// else cout << "fail" << endl;

	switch (grade) {

	case 'A' : cout << "very good" << endl; break;
	case 'B' : cout << "good" << endl; break;
	case 'C' : cout << "poor" << endl; break;
	case 'D' : cout << "very poor" << endl; break;
	default : cout << "fail" << endl; break;


	}


	return 0;
}
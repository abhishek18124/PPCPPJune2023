#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	// computing the size or length of a string

	string str = "coding blocks";

	cout << str.length() << endl;
	cout << str.size() << endl;

	// appending / concatnating str2 to str1

	string str1 = "new";
	string str2 = "delhi";

	// // 1. using append()

	// str1.append(str2);
	// cout << str1 << endl;

	// 2. using '+' operator

	str1 = str1 + " " + str2;
	cout << str1 << endl;

	// comparing two strings

	string str3 = "abc";
	string str4 = "adc";

	// 1. using compare
	cout << str3.compare(str4) << endl;

	// 2. using relational operators
	if (str3 > str4) {
		cout << str3 << " is greater" << endl;
	} else {
		cout << str4 << " is greater" << endl;
	}

	// searching for a substring in a string using find()

	string str5 = "mississippi";

	cout << str5.find("si") << endl;
	cout << str5.rfind("si") << endl;
	cout << str5.find("hello") << endl;
	cout << string::npos << endl;

	string key = "hello";
	if (str5.find(key) != string::npos) {
		cout << key << " is present" << endl;
	} else {
		cout << key << " is not present" << endl;
	}

	// extracting a substring from a string using substr()

	string str6 = "helloworld";
	string subString = str6.substr(4);
	cout << subString << endl;

	subString = str6.substr(4, 2);
	cout << subString << endl;

	// converting a string into char array

	string str7 = "new delhi";
	char* arr = (char*)str7.c_str();
	cout << arr << endl;

	// converting a char array into a string

	char a[] = "hello world";
	string str11(a);
	cout << str11 << endl;

	string st(1, 'z');
	cout << st << endl;

	// reversing a string using reverse()

	string str9 = "coding blocks";

	reverse(str9.begin(), str9.end()); // [start, end)

	cout << str9 << endl;

	string str10 = "coding";

	// reverse(str10.begin(), str10.end());

	// reverse(str10.begin() + 1, str10.begin() + 5); // [1, 5)

	reverse(str10.begin() + 1, str10.end() - 1);

	cout << str10 << endl;



	return 0;
}
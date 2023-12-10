/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap; // type of key = string ; type of value = vector<string>

	phoneMap["Parth"].push_back("1234");
	phoneMap["Parth"].push_back("3510");
	phoneMap["Parth"].push_back("0000");

	phoneMap["Tejasav"].push_back("1230");
	phoneMap["Tejasav"].push_back("1234");

	for (pair<string, vector<string>> contact : phoneMap) {
		string name = contact.first;
		vector<string> phoneNums = contact.second;
		cout << name << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}


	return 0;
}
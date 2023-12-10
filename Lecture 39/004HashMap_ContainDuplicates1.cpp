#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main() {

	vector<int> v = {1, 2, 1, 3, 4};

	unordered_map<int, int> freqMap;

	bool flag = false; // assume no duplicates are present

	for (int i = 0; i < v.size(); i++) {

		freqMap[v[i]]++;

		if (freqMap[v[i]] > 1) {

			// v[i] is repeating i.e. you've found duplicates

			flag = true;

			// break;

		}

	}

	// for (pair<int, int> p : freqMap) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	flag = false;

	for (pair<int, int> p : freqMap) {
		if (p.second > 1) {
			// p.first is repeating
			flag = true;
			break;
		}
	}

	cout << flag << endl;

	flag = false;

	unordered_set<int> hashSet;

	for (int i = 0; i < v.size(); i++) {

		if (hashSet.find(v[i]) != hashSet.end()) {

			// v[i] is repeating i.e. you've found duplicates

			flag = true;

			break;

		}

		hashSet.insert(v[i]);

	}

	cout << flag << endl;

	return 0;
}
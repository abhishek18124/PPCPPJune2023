#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {

	string str = "abccccdd";

	// time : O(n) and space : O(n) due to hashSet (when str contains uniqueChars)

	unordered_set<char> hashSet;

	int cnt = 0;

	for (char ch : str) {

		if (hashSet.find(ch) != hashSet.end()) {

			cnt += 2;
			hashSet.erase(ch);

		} else {

			hashSet.insert(ch);

		}

	}

	if (hashSet.size() > 0) cnt++;

	cout << cnt << endl;

	return 0;
}
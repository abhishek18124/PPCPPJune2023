#include<iostream>

using namespace std;

// total steps = n (to build freqMap1) + n (to build freqMap2) + 26 (to compare freqMaps)

// total extra space = 26 (for freqMap1) + 26 (for freqMap2)

bool isAnagram(char* s1, char* s2) {

	int freqMap1[26];

	memset(freqMap1, 0, sizeof(freqMap1));

	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		int idx = ch - 'a';
		freqMap1[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << freqMap1[i] << " ";
	}

	cout << endl;

	int freqMap2[26];

	memset(freqMap2, 0, sizeof(freqMap2));

	for (int i = 0; s2[i] != '\0'; i++) {
		freqMap2[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << freqMap2[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 26; i++) {
		if (freqMap1[i] != freqMap2[i]) {
			return false;
		}
	}

	return true;


}

int main() {

	char s1[] = "taste";
	char s2[] = "state";

	isAnagram(s1, s2) ? cout << "anagrams" << endl : cout << "not anagrams" << endl;

	return 0;
}
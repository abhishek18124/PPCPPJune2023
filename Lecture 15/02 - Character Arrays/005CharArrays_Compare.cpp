#include<iostream>
#include<cstring>

using namespace std;

// len(s1) = m
// len(s2) = n

// min(m, n)

int stringCompare(char* s1, char* s2) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {
			// s1 > s2
			return 1;
		} else if (s1[i] < s2[j]) {
			// s1 < s2
			return -1;
		}

		i++;
		j++;

	}

	if (s1[i] == '\0' and s2[j] != '\0') {
		// len(s1) < len(s2) therefore s1 < s2
		return -1;
	}

	if (s1[i] != '\0' and s2[j] == '\0') {
		// len(s1) > len(s2) therefore s1 > s2
		return 1;
	}

	// len(s1) == len(s2) therefore s1 is equal s2

	return 0;

}

int main() {

	char s1[] = "azbcdef";
	char s2[] = "zzbcdef";

	// int ans = stringCompare(s1, s2);

	int ans = strcmp(s1, s2);

	if (ans == 0) {
		cout << "equal" << endl;
	} else if (ans > 0) {
		cout << s1 << " > " << s2 << endl;
	} else {
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}
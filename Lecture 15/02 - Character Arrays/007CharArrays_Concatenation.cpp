// n <= 50 and m <= 50

#include<iostream>
#include<cstring>

using namespace std;

void stringConcat(char* s1, char* s2) {

	int i = strlen(s1); // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	// n times

	while (s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';

}


int main() {

	char s1[101] = "hello";
	char s2[] = "world";

	cout << "Before concat : " << s1 << endl;

	// stringConcat(s1, s2);

	strcat(s1, s2);

	cout << "After concat : " << s1 << endl;

	return 0;
}
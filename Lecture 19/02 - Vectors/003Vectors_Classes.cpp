#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

/*
	return 'true' when a swap isn't required.

*/

bool myAgeComparator(customer c1, customer c2) {
	if (c1.age < c2.age) {
		// you don't need a swap to sort the v[] in inc. order based on age
		return true;
	}
	// you need a swap to sort the v[] in inc. order based on age
	return false;
}


bool myCreditCompator(customer c1, customer c2) {
	if (c1.credits > c2.credits) {
		// you don't need a swap to sort the v[] in dec. order based on credits
		return true;
	}
	// you need a swap to sort the v[] in dec. order based on credits
	return false;
}

int main() {

	vector<customer> v;

	v.push_back(customer("krishna", 18, 'M', 1000));
	v.push_back(customer("parth", 19, 'M', 500));
	v.push_back(customer("garima", 20, 'F', 1500));
	v.push_back(customer("anamika", 17, 'F', 1200));

	sort(v.begin(), v.end(), myAgeComparator);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), myCreditCompator);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	return 0;
}
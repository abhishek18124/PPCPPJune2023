#include<iostream>

using namespace std;

class customer {
public :
	char name[100];
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\nI am inside the default constructor of the customer class\n" << endl;
	}

	customer(char* n, int a, char g, double c) {
		cout << "\nI am inside the parameterised constructor of the customer class\n" << endl;
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	void printCustomerInfo() {
		cout << "\nCustomer Information\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

};

int main() {

	customer c1("Krishna", 19, 'M', 1000);

	c1.printCustomerInfo();

	customer c2("Parth", 20, 'M', 500);

	c2.printCustomerInfo();

	customer c3;

	return 0;
}
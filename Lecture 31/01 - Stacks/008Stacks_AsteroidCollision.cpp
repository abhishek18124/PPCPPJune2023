#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;
	for (int ast : asteroids) {

		if (!s.empty() and s.top() > 0 and ast < 0) {
			// collision
			bool flag = false; // assume 'ast' is not yet destroyed
			while (!s.empty() and s.top() > 0) {
				if (s.top() < abs(ast)) {
					s.pop();
				} else if (s.top() == abs(ast)) {
					s.pop();
					flag = true;
					break;
				} else { // s.top() > abs(ast)
					flag = true;
					break;
				}
			}
			if (flag == false) {
				// 'ast' has survived after all the collisions, so track it
				s.push(ast);
			}
		} else {
			// no collistion
			s.push(ast);
		}

	}

	vector<int> v;

	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}

	reverse(v.begin(), v.end());

	return v;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	return 0;
}
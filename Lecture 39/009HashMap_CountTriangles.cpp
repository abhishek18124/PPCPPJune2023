/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {Point(1, 2),
	                        Point(2, 0),
	                        Point(2, 2),
	                        Point(2, 3),
	                        Point(4, 2)
	                       };


	// time : O(n^2)

	// int cnt = 0;

	// for (Point pivot : points) {

	// 	// count the no. of axis parallel right angled triangles around the pivot

	// 	int a = 0; // to store the count of points in the 2D plane whose x-coor matches pivot.x
	// 	int b = 0; // to store the count of points in the 2D plane whose y-coor matches pivot.y

	// 	for (Point p : points) {

	// 		if (p.x == pivot.x) {

	// 			// you've found a point in the 2D plane whose x-coor matches pivot.x

	// 			a++;

	// 		}

	// 		if (p.y == pivot.y) {

	// 			// you've found a point in the 2D plane whose y-coor matches pivot.y

	// 			b++;

	// 		}

	// 	}

	// 	a--; // to exclude pivot
	// 	b--; // to exclude pivot

	// 	cnt += a * b;

	// }

	// cout << cnt << endl;

	// time : O(n)

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for (Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	int cnt = 0;

	for (Point pivot : points)  {
		// consider the 'point' as pivot and compute the no. of
		// axis parallel rightAngledTriangles around it

		int a = xFreqMap[pivot.x];
		int b = yFreqMap[pivot.y];

		cnt += (a - 1) * (b - 1);
	}

	cout << "count : " << cnt << endl;


	return 0;
}
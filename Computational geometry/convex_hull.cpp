#include <bits/stdc++.h>
using namespace std;
#define dbg(x) std::cout << #x "=" << x << "\n"
#define ll long long

 
struct Point {
	ll x, y, cost;
	Point() : x(0), y(0) {}
	Point(ll X, ll Y) : x(X), y(Y) {}
};
 
bool operator==(const Point &left, const Point &right) { return (left.x == right.x) && (left.y == right.y); }
bool operator!=(const Point &left, const Point &right) { return (left.x != right.x) || (left.y != right.y); }
 
Point operator-(const Point &right) { return Point(-right.x, -right.y); }
Point operator+(const Point &left, const Point &right) { return Point(left.x + right.x, left.y + right.y); }
Point operator-(const Point &left, const Point &right) { return Point(left.x - right.x, left.y - right.y); }
 
ll cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}
 
bool isLeftTurn(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - b) > 0;
}
bool isRightTurn(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - b) < 0;
}
bool isCollinear(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - b) == 0;
}
ll dissq(const Point &a, const Point &b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
 
std::vector<Point> getConvexHull(std::vector<Point> &points) {
	int pivotIndex = 0;
	for (int i = 0; i < points.size(); ++i) {
		if (points[pivotIndex].y > points[i].y)
			pivotIndex = i;
		else if (points[pivotIndex].y == points[i].y && points[pivotIndex].x == points[i].x)
			pivotIndex = i;
	}
 
	std::swap(points[0], points[pivotIndex]);
 
	Point pivot = points[0];
 
	std::sort(points.begin() + 1,
			  points.end(),
			  [pivot](const Point &a, const Point &b) -> bool { 
				  if(isRightTurn(a,pivot,b))
				  return true;
				  if(isCollinear(a,pivot,b) && dissq(a,pivot)<dissq(b,pivot))
				  return true;
				  return false; });
	std::vector<Point> hull;
 
	hull.push_back(pivot);
	hull.push_back(points[1]);
	for (int i = 2; i < points.size(); ++i) {
		while (hull.size() > 1) {
			Point A = hull[hull.size() - 2], B = hull[hull.size() - 1];
			if (isRightTurn(A, B, points[i]) || isCollinear(A, B, points[i]))
				hull.pop_back();
			else
				break;
		}
		hull.push_back(points[i]);
	}
 
	return hull;
}
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin >> N;
	std::vector<Point> points(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> points[i].x >> points[i].y >> points[i].cost;
	}
	ll sum = 0;
	for (Point p : getConvexHull(points))
		sum += p.cost;
	// std::cout << p.x << " " << p.y << " " << p.cost << " -> ";
	std::cout << sum << "\n";
	return 0;
} 

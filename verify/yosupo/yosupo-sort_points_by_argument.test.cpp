#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/geometry/geometry-2d.hpp"

using P = Point<long long>;

using namespace Geometry2D;

int half(P x) {
	return x.y != 0 ? sign(x.y) : -sign(x.x); 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<Point<long long>> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	sort(p.begin(), p.end(), [&](P a, P b) {
		int A = half(a), B = half(b);
		return A == B ? cross(a, b) > 0 : A < B;
	});
	for (int i = 0; i < n; ++i) {
		cout << p[i].x << ' ' << p[i].y << '\n';
	}
	return 0;
}
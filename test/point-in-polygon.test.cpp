#define PROBLEM "https://open.kattis.com/problems/pointinpolygon"

#include "../library/contest/template-minimal.hpp"
#include "../library/geometry/geometry-2d.hpp"

//  kattis 
int main() {
	using namespace std;
	using namespace Geometry2D;
	typedef long double ld;
	typedef Point<long double> P;
	cout << setprecision(1) << fixed;
	while (true) {
		int n; cin >> n;
		if (n == 0)
			return 0;
		vector<Point<int>> v(n);
		for (int i = 0; i < n; i++) 
			cin >> v[i].x >> v[i].y;
		int m; cin >> m;
		while (m--) {
			Point<int> p;
			cin >> p.x >> p.y;
			int res = polygon_point(v, p);
			if (res == -1)
				cout << "out\n";
			else if (res == 0)
				cout << "on\n";
			else 
				cout << "in\n";
		}
	}
	return 0;
}
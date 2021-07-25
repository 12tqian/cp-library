#define IGNORE

#include "../../library/contest/template-minimal.hpp"
#include "../../library/geometry/convex-hull.hpp"

// kattis verified
int main() {
	using namespace std;
	using namespace ConvexHull;
	ios_base::sync_with_stdio(0);
	while (true) {
		int n; cin >> n;
		if (n == 0) 
			return 0;
		vector<Point<int>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y;
		auto hull = convex_hull(v);
		cout << (int)hull.size() << '\n';       
		for (auto &p : hull)
			cout << p.x << " " << p.y << '\n';
	}
	return 0;
}
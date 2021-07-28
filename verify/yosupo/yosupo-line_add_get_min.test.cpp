#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/dynamic-programming/dynamic-convex-hull-trick.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	ConvexHullTrick cht;	
	while (n--) {
		int a, b;
		cin >> a >> b;
		cht.add_line(a, b);
	} 
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int a, b;
			cin >> a >> b;
			cht.add_line(a, b);
		} else {
			int p;
			cin >> p;
			cout << cht.query(p) << '\n';
		}
	}
	return 0;
}
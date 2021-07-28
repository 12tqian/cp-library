#define PROBLEM "https://www.spoj.com/problems/QTREE2/"

#include "../../library/contest/template-full.hpp"
#include "../../library/graphs/lca-jump-distance.hpp"

void solve_case(int tc = 0) {
	int n;
	re(n);
	LCAJumpDistance<long long> lca;
	lca.init(n);
	f0r(i, n - 1) {
		int u, v, w;
		re(u, v, w);
		--u, --v;
		lca.ae(u, v, w);
	}
	lca.gen(0);
	while (true) {
		string s;
		re(s);
		if (s == "DIST") {
			int u, v;
			re(u, v);
			--u, --v;
			ps(lca.distance(u, v));
		} else if (s == "KTH") {
			int u, v, w;
			re(u, v, w);
			--u, --v, --w;
			int up = lca.lca(u, v);						
			int d1 = lca.depth[u] - lca.depth[up];
			int d2 = lca.depth[v] - lca.depth[up];
			if (d1 >= w) {
				ps(lca.jump(u, w) + 1);
			} else {
				w -= d1;
				w = d2 - w;
				ps(lca.jump(v, w) + 1);
			}
		} else {
			break;
		}
	}
}

int main() {
	setIO("");
	int tt = 1;
	re(tt);
	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}
#define PROBLEM "https://www.spoj.com/problems/QTREE2/"

#include "../../library/contest/template-short.hpp"
#include "../../library/graphs/lca-jump-distance.hpp"

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	LCAJumpDistance<long long> lca;
	lca.init(n);
	f0r(i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		lca.ae(u, v, w);
	}
	lca.gen(0);
	while (true) {
		string s;
		cin >> s;
		if (s == "DIST") {
			int u, v;
			cin >> u >> v;
			--u, --v;
			cout << (lca.distance(u, v)) << '\n';
		} else if (s == "KTH") {
			int u, v, w;
			cin >> u >> v >> w;
			--u, --v, --w;
			int up = lca.lca(u, v);						
			int d1 = lca.depth[u] - lca.depth[up];
			int d2 = lca.depth[v] - lca.depth[up];
			if (d1 >= w) {
				cout << (lca.jump(u, w) + 1) << '\n';
			} else {
				w -= d1;
				w = d2 - w;
				cout << (lca.jump(v, w) + 1) << '\n';
			}
		} else {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}
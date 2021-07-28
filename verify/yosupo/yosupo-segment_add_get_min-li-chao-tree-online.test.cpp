#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/li-chao-tree-online.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	const int INF = 1e9;
	int n, q; cin >> n >> q;
	Node L; 
	for (int i = 0; i < n; i++) {
		int l, r, a; long long b;
		cin >> l >> r >> a >> b;
		L.upd({-a, -b}, l, r - 1, -INF, INF);
	}
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 0) {
			int l, r, a; long long b; 
			cin >> l >> r >> a >> b;
			L.upd({-a, -b}, l, r - 1, -INF, INF);
		} else {
			int p; cin >> p;
			long long ans = L.query(p, -INF, INF);
			if (ans == numeric_limits<long long>::min()) {
				cout << "INFINITY" << '\n';
			} else {
				cout << -ans << '\n';
			}
		}
	}
	return 0;
}
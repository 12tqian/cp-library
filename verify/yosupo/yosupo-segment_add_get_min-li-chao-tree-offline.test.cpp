#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/data-structures/1d-range-queries/li-chao-tree-offline.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<long long> a(n), b(n), l(n), r(n);	
	for (int i = 0; i < n; i++) 
		cin >> l[i] >> r[i] >> a[i] >> b[i];
	vector<long long> c(q), d(q), e(q), f(q), g(q);
	vector<long long> xs;
	for (int i = 0; i < q; i++) {
		cin >> c[i];
		if (c[i]) {
			cin >> d[i];
			xs.push_back(d[i]);
		} else {
			cin >> d[i] >> e[i] >> f[i] >> g[i];
		}
	}
	xs.push_back(numeric_limits<long long>::min());
	xs.push_back(numeric_limits<long long>::max());
	LiChaoTree<long long> L(xs);
	for (int i = 0; i < n; i++) {
		L.update_segment(a[i], b[i], l[i], r[i] - 1);
	}
	for (int i = 0; i < q; i++) {
		if (c[i]) {
			long long ans = L.query(d[i]);
			if (ans == numeric_limits<long long>::max()) 
				cout << "INFINITY\n";
			else 
				cout << ans << '\n';
		} else {
			L.update_segment(f[i], g[i], d[i], e[i] - 1);
		}
	}
	return 0;
}
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/dsu.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	DSU dsu;
	dsu.init(n);
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
			dsu.unite(u, v);
		} else {
			cout << dsu.same_set(u, v) << '\n';
		}
	}
	return 0;
}
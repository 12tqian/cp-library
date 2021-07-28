#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/lca-rmq.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	LCARMQ L;
	L.init(n);
	for (int i = 1; i < n; i++) {
		int p; cin >> p;
		L.ae(i, p);
	}
	L.gen(0);
	while (q--) {
		int u, v; cin >> u >> v;
		cout << L.lca(u, v) << '\n';
	}
}
#define PROBLEM "https://yukicoder.me/problems/no/1326"

#include <bits/stdc++.h>

#include "../../library/graphs/block-cut-tree.hpp"
#include "../../library/graphs/lca-jump.hpp"

int main() {
	using namespace std;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	BlockCutTree bct(g);
	g = bct.aux;
	LCAJump lca;
	int sz = (int)g.size();
	lca.init(sz);
	for (int u = 0; u < sz; ++u) {
		for (int v : g[u]) {
			if (u < v) {
				lca.ae(u, v);
			}
		}
	}
	lca.gen(0);
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u == v) {
			cout << 0 << '\n';
			continue;	
		}
		int ans = lca.depth[bct.id(u)];
		ans += lca.depth[bct.id(v)];
		ans -= lca.depth[lca.lca(bct.id(u), bct.id(v))] * 2;
		ans -= bct.is_arti(u);
		ans -= bct.is_arti(v);
		ans /= 2;
		cout << ans << '\n';
	}
	return 0;
}
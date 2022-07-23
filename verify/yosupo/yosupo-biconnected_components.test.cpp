#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <bits/stdc++.h>
#include "../../library/graphs/biconnected-components.hpp"

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	BiConnectedComponents bc(g);
	vector<vector<int>> ans;
	vector<int> used(n);
	for (auto& v : bc.bc) {
		vector<int> z;
		for (auto p : v) {
			z.push_back(p.first);
			z.push_back(p.second);
		}
		sort(z.begin(), z.end());
		z.erase(unique(z.begin(), z.end()), z.end());
		ans.push_back(z);
		for (int x : z) {
			used[x] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ans.push_back({i});
		}
	}
	cout << ans.size() << '\n';
	for (auto& z : ans) {
		cout << z.size() << ' ';
		for (int x : z) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include "../library/contest/template-minimal.hpp"
#include "../library/graphs/topological-sort.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	auto res = topo_sort(g);
	for (int x : res) {
		cout << x << '\n';
	}
	return 0;
}
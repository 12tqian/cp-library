#define PROBLEM "https://www.spoj.com/problems/TOPOSORT/"

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
		--u, --v;
		g[u].push_back(v);
	}
	auto res = topo_sort(g);
	if (res.empty()) {
		cout << "Sandro fails." << '\n';
	} else {
		for (int x : res) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
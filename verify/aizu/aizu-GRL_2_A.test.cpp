#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/kruskal.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> edges;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}
	cout << kruskal(edges) << '\n';
	return 0;
}
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/heavy-light-decomposition2.hpp"

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(false);
	HeavyLight<long long> H;
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	H.init(graph);
	for (int i = 0; i < n; i++) H.modify_path(i, i, a[i]);
	while (q--) {
		int t; cin >> t;
		if (t == 0) {
			int p, x; cin >> p >> x;
			H.modify_path(p, p, x);
		} else {
			int u, v;
			cin >> u >> v;
			cout << H.query_path(u, v) << '\n';
		}
	}
	return 0;
}

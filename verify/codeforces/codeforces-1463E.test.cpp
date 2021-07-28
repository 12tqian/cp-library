#define PROBLEM "https://codeforces.com/contest/1463/problem/E"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/dsu.hpp"
#include "../../library/graphs/topological-sort.hpp"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ed, con;
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		if (p != -1) {
			ed.emplace_back(p, i);
		}
	}
	vector<int> go(n, -1);
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		con.emplace_back(x, y);
		go[x] = y;
		dsu.unite(x, y);
	}
	vector<vector<int>> comps(n), ord(n);
	for (int i = 0; i < n; ++i) {
		comps[dsu.get(i)].push_back(i);
	}
	map<int, int> conv;
	for (int i = 0; i < n; ++i) {
		if (comps[i].empty()) {
			continue;
		}
		int sz = comps[i].size();
		conv.clear();
		vector<vector<int>> g(sz);
		for (int j = 0; j < sz; ++j) {
			conv[comps[i][j]] = j;
		}
		for (int x : comps[i]) {
			if (go[x] == -1) {
				continue;
			}
			if (conv.find(go[x]) == conv.end()) {
				cout << -1 << '\n';
				return 0;
			}
			g[conv[x]].push_back(conv[go[x]]);
		}
		auto res = topo_sort(g);
		if (res.size() != sz) {
			cout << 0 << '\n';
			return 0;
		}
		for (int x : res) {
			ord[i].push_back(comps[i][x]);
		}
	}
	vector<vector<int>> g(n);
	for (auto [u, v] : ed) {
		u = dsu.get(u);
		v = dsu.get(v);
		if (u != v) {
			g[u].push_back(v);
		}
	}
	auto res = topo_sort(g);
	if (res.size() < n) {
		cout << 0 << '\n';
		return 0;
	}
	vector<int> ans;
	for (int x : res) {
		for (int y : ord[x]) {
			ans.push_back(y);
		}
	}
	vector<int> rev(n);
	for (int i = 0; i < n; ++i) {
		rev[ans[i]] = i;
	}
	for (auto [u, v] : ed) {
		if (rev[u] > rev[v]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
	return 0;
}
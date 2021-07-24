#pragma once

struct SCC {
	int n; 
	std::vector<std::vector<int>> g, rg, scc_graph, comps;
	std::vector<int> id, ord, roots, topo_ord;
	std::vector<bool> vis;

	void init(int n_) {
		n = n_;
		g.assign(n, std::vector<int>());
		rg.assign(n, std::vector<int>());
		scc_graph.assign(n, std::vector<int>());
		comps.assign(n, std::vector<int>());
		vis.assign(n, false);
		id.assign(n, -1);
		ord.clear();
		roots.clear();     
		topo_ord.clear();  
	}

	void ae(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	void dfs_order(int u) {
		vis[u] = true;
		for (auto &v : g[u]) {
			if (vis[v]) 
				continue;
			dfs_order(v);
		}
		ord.push_back(u);
	}

	void dfs_color(int u, int c) {
		id[u] = c;
		for (int &v : rg[u]) 
			if (id[v] == -1) 
				dfs_color(v, c);
	}

	void topological_sort() {
		std::vector<int> in(n);
		std::list<int> todo;
		for (int i = 0; i < n; ++i) 
			for (auto &j : scc_graph[i])
				++in[j];
		for (int i = 0; i < n; ++i)
			if (!in[i] && id[i] == i)
				todo.push_back(i);
		while (!todo.empty()) {
			int u = todo.front();
			todo.pop_front();
			topo_ord.push_back(u);
			for (auto &v : scc_graph[u]) 
				if (!(--in[v])) 
					todo.push_back(v);
		}
	}

	void build_scc_graph() {
		for (int i = 0; i < n; ++i) {
			comps[id[i]].push_back(i);
			for (auto &j : g[i]) {
				if (id[i] == id[j]) 
					continue;
				scc_graph[id[i]].push_back(id[j]);
			}
		}
		topological_sort();
	}

	void gen() {
		for (int i = 0; i < n; ++i) {
			if (!vis[i])
				dfs_order(i);
		}
		reverse(ord.begin(), ord.end());
		for (auto &x : ord) 
			if (id[x] == -1) 
				dfs_color(x, x), roots.push_back(x);
	}
};

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, m; 
	cin >> n >> m;
	SCC S; S.init(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		S.ae(u, v);
	}
	S.gen();
	S.build_scc_graph();
	cout << S.roots.size() << '\n';
	for (auto &c : S.topo_ord) {
		cout << S.comps[c].size() << " ";
		for (auto &x : S.comps[c]) 
			cout << x << " ";
		cout << '\n';
	}
	return 0;
}
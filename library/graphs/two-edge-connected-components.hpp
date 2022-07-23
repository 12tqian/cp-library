#pragma once

struct TwoEdgeCC {
	int n, time, num_comps; 
	std::vector<int> ord, low, id; 
	// order encountered, earliest time in subtree, component id
	std::vector<std::vector<int>> adj, comps, tree;
	// adj, comps storage, bridge block tree
	std::vector<std::pair<int, int>> bridge;
	// bridges
	
	void init(int n_) {
		num_comps = time = 0;
		n = n_;
		ord.assign(n, -1);
		low.assign(n, 0);
		id.assign(n, -1);
		adj.assign(n, std::vector<int>());
		comps.clear();
		tree.clear();
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool is_bridge(int u, int v) {
		if (ord[u] > ord[v])
			std::swap(u, v);
		return ord[u] < low[v];
	}

	void dfs(int src, int par) {
		ord[src] = low[src] = time++;
		bool bic = false; // accounts for double edges
		for (int nxt : adj[src]) { 
			if (nxt == par && !bic) {
				bic = true;
				continue;
			}
			if (ord[nxt] != -1) {
				low[src] = std::min(low[src], ord[nxt]);
				continue;
			}
			dfs(nxt, src);
			low[src] = std::min(low[src], low[nxt]);
			if (is_bridge(src, nxt))
				bridge.emplace_back(src, nxt);
		}
	}

	void fill_component(int src) {
		comps[id[src]].push_back(src);
		for (int nxt : adj[src]) {
			if (id[nxt] != -1 || is_bridge(nxt, src))
				continue;
			id[nxt] = id[src];
			fill_component(nxt);
		}
	}

	void add_component(int src) {
		if (id[src] != -1)
			return;
		id[src] = num_comps++;
		comps.emplace_back();
		fill_component(src);
	}
	
	int build() {
		for (int i = 0; i < n; i++) 
			if (ord[i] == -1)
				dfs(i, -1);
		for (int i = 0; i < n; i++) 
			add_component(i);
		tree.resize(num_comps);
		for (auto& b : bridge) {
			int u = id[b.first];
			int v = id[b.second];
			tree[u].push_back(v);
			tree[v].push_back(u);            
		}
		return num_comps;
	}
};
#pragma once

struct SCC {
	int n, time, num_comps;
	std::vector<std::vector<int>> adj;
	std::vector<int> disc, id, stk;
	std::vector<std::vector<int>> comps;

	void init(int n_) {
		n = n_;
		time = 0;
		num_comps = 0;
		adj.assign(n, std::vector<int>());
		id.assign(n, -1);
		disc.assign(n, 0);
		comps.clear();
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
	}

	int dfs(int src) {
		int low = disc[src] = ++time;
		stk.push_back(src);
		for (int nxt : adj[src]) 
			if (id[nxt] == -1)
				low = std::min(low, disc[nxt] ? : dfs(nxt));
		if (low == disc[src]) {
			for (int nxt = -1; nxt != src;)
				id[nxt = stk.back()] = num_comps, stk.pop_back();
			num_comps++;
		}
		return low;
	}
	
	void build() {
		// builds in topological order
		for (int i = 0; i < n; i++) 
			if (!disc[i])
				dfs(i);
		for (auto& x : id) 
			x = num_comps - 1 - x;
		comps.resize(num_comps);
		for (int i = 0; i < n; i++)
			comps[id[i]].push_back(i);
	}
};
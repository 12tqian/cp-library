#pragma once

template <class F> struct Dinic {
	struct Edge { int to; F flow, cap; };
	int n;
	std::vector<Edge> edges;
	std::vector<std::vector<int>> adj;
	std::vector<int> level;
	std::vector<std::vector<int>::iterator> cur;

	void init(int n_) {
		n = n_;
		adj.assign(n, std::vector<int>());
		cur.assign(n, std::vector<int>::iterator());
		edges.clear();
		level.clear();
	}

	void ae(int u, int v, F cap, F rcap = 0) {
		assert(std::min(cap, rcap) >= 0);
		adj[u].push_back((int)edges.size());
		edges.push_back({v, 0, cap});
		adj[v].push_back((int)edges.size());
		edges.push_back({u, 0, rcap});
	}

	bool bfs(int s, int t) {
		level = std::vector<int>(n, -1);
		for (int i = 0; i < n; i++)
			cur[i] = adj[i].begin();
		std::queue<int> q({s});
		level[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto& eid : adj[u]) {
				const Edge& e = edges[eid];
				int v = e.to;
				if (level[v] < 0 && e.flow < e.cap) 
					q.push(v), level[v] = level[u] + 1;
			}
		}
		return level[t] >= 0;
	}

	F dfs(int v, int t, F flow) {
		if (v == t)
			return flow;
		for (; cur[v] != adj[v].end(); cur[v]++) {
			Edge& e = edges[*cur[v]];
			if (level[e.to] != level[v] + 1 || e.flow == e.cap)
				continue;
			F df = dfs(e.to, t, std::min(flow, e.cap - e.flow));
			if (df) {
				e.flow += df;
				edges[*cur[v] ^ 1].flow -= df;
				return df;
			}
		}
		return 0;
	}
	
	F max_flow(int s, int t) {
		F tot = 0;
		while (bfs(s, t)) 
			while (F df = dfs(s, t, std::numeric_limits<F>::max())) 
				tot += df;
		return tot;
	}
};
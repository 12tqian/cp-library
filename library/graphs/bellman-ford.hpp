#pragma once

template <class T> struct BellmanFord {
	const T INF = std::numeric_limits<T>::max();
	int n; 
	std::vector<std::vector<int>> adj;
	std::vector<std::pair<std::pair<int, int>, T>> edges;
	std::vector<T> dist;

	void init(int n_) {
		n = n_;
		adj.assign(n, std::vector<int>());
		edges.clear();
		dist.assign(n, 0);
	}

	void ae(int u, int v, T w) {
		adj[u].push_back(v);
		edges.push_back({{u, v}, w});
	}   

	void gen_bad(int x) {
		if (dist[x] == -INF)
			return;
		dist[x] = -INF;
		for (auto& nxt : adj[x])
			gen_bad(nxt);
	}

	void gen(int src) {
		for (int i = 0; i < n; i++) 
			dist[i] = INF;
		dist[src] = 0;
		for (int i = 0; i < n; i++)
			for (auto& e : edges) 
				if (dist[e.first.first] < INF)
					dist[e.first.second] = std::min(dist[e.first.second], dist[e.first.first] + e.second);
		for (auto& e : edges) 
			if (dist[e.first.first] < INF && dist[e.first.second] > dist[e.first.first] + e.second)
				gen_bad(e.first.second);
	}
	
	std::vector<int> negative_cycle(int src = 0) {
		for (int i = 0; i < n; i++)
			dist[src] = INF;
		dist[src] = 0;
		std::vector<int> pre(n);
		for (auto& e : edges) 
			if (e.first.first == e.first.second && e.second < 0) 
				return {e.first.first};
		for (int i = 0; i < n; i++) 
			for (auto& e : edges) 
				if (dist[e.first.first] < INF)
					if (dist[e.first.second] > dist[e.first.first] + e.second) {
						dist[e.first.second] = dist[e.first.first] + e.second;
						pre[e.first.second] = e.first.first;
					}
		for (auto& e : edges) 
			if (dist[e.first.first] < INF)
				if (dist[e.first.second] > dist[e.first.first] + e.second) {
					int x = e.first.second;
					for (int i = 0; i < n; i++)
						x = pre[x];
					std::vector<int> cycle;
					for (int v = x; v != x || cycle.empty(); v = pre[v])
						cycle.push_back(v);
					reverse(cycle.begin(), cycle.end());
					return cycle;
				}
		return {};
	}
};
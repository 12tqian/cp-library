#include <bits/stdc++.h>
/**
 * to get back the original edges, assign ID's in ae
 */

template <class F, class C> struct MCMF {
	struct Edge { int to; F flow, cap; C cost; };

	int n;
	std::vector<C> p, dist;
	std::vector<int> pre;
	std::vector<Edge> edges;
	std::vector<std::vector<int>> adj;

	const C INF  = std::numeric_limits<C>::max();

	void init(int n_) {
		n = n_;
		p.assign(n, 0);
		dist.assign(n, 0);
		pre.assign(n, 0);
		adj.clear(); adj.resize(n);
		edges.clear();
	}

	void ae(int u, int v, F cap, C cost) {
		assert(cap >= 0);
		adj[u].push_back((int)edges.size());
		edges.push_back({v, 0, cap, cost});
		adj[v].push_back((int)edges.size());
		edges.push_back({u, 0, 0, -cost});
	}

	bool path(int s, int t) {
		for (int i = 0; i < n; i++) 
			dist[i] = INF;
		using T = std::pair<C, int>;
		std::priority_queue<T, std::vector<T>, std::greater<T>> todo;
		todo.push({dist[s] = 0, s});
		while (!todo.empty()) {
			T x = todo.top();
			todo.pop();
			if (x.first > dist[x.second])
				continue;
			for (auto& eid : adj[x.second]) {
				const Edge& e = edges[eid];
				if (e.flow < e.cap && dist[e.to] > x.first + e.cost + p[x.second] - p[e.to]) {
					dist[e.to] = x.first + e.cost + p[x.second] - p[e.to];
					pre[e.to] = eid;
					todo.push({dist[e.to], e.to});
				}
			}
		}
		return dist[t] != INF;
	}

	std::pair<F, C> calc(int s, int t) {
		assert(s != t);
		for (int unused = 0; unused < n; unused++)
			for (int eid = 0; eid < (int)edges.size(); eid++) {
				const Edge& e = edges[eid];
				if (e.cap)
					p[e.to] = std::min(p[e.to], p[edges[eid ^ 1].to] + e.cost);
			}
		F total_flow = 0;
		C total_cost = 0;
		while (path(s, t)) {
			for (int i = 0; i < n; i++)
				p[i] += dist[i];
			F df = std::numeric_limits<F>::max();
			for (int x = t; x != s; x = edges[pre[x] ^ 1].to) {
				const Edge& e = edges[pre[x]];
				df = std::min(df, e.cap - e.flow);
			}
			total_flow += df;
			total_cost += (p[t] - p[s]) * df;
			for (int x = t; x != s; x = edges[pre[x] ^ 1].to) 
				edges[pre[x]].flow += df, edges[pre[x] ^ 1].flow -= df;
		}
		return {total_flow, total_cost};
	}
};

int main() {
	using namespace std;
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	MCMF<int, int> M;
	M.init(n);
	for (int i = 0; i < m; i++) {
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		M.ae(u, v, c, w);
	}
	auto res = M.calc(s, t);
	cout << res.first << " " << res.second << '\n';
	return 0;
}
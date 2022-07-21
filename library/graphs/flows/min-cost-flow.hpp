#pragma once

template <class C, class D> struct MinCostFlow {
	struct E {
		int to, rev;
		C cap;
		D dist;
	};

	static constexpr D INF = std::numeric_limits<D>::max();
	
	int n;
	int s, t;

	std::vector<std::vector<E>> g;
	
	C nc, cap_flow = 0;
	D nd, dist_flow = 0;

	std::vector<D> dual;
	std::vector<int> pv, pe;

	void init(int _n) {
		n = _n;
		s = t = -1;
		nc = cap_flow = 0;
		nd = dist_flow = 0;
		g.assign(n, std::vector<E>());
		dual.clear();
		pv.clear();
		pe.clear();
	}

	void ae(int from, int to, C cap, D dist) {
		g[from].push_back(E{to, int(g[to].size()), cap, dist});
		g[to].push_back(E{from, int(g[from].size()) - 1, 0, -dist});
	}

	void gen(int _s, int _t, bool neg = false) {
		s = _s;
		t = _t;
		assert(s != t);
		dual = std::vector<D>(n);
		pv = pe = std::vector<int>(n);
		if (neg) {
			std::vector<D> dist(n, D(INF));
			dist[s] = 0;
			for (int ph = 0; ph < n; ph++) {
				bool update = false;
				for (int i = 0; i < n; i++) {
					if (dist[i] == INF) continue;
					for (auto e : g[i]) {
						if (!e.cap) continue;
						if (dist[i] + e.dist < dist[e.to]) {
							dist[e.to] = dist[i] + e.dist;
							update = true;
						}
					}
				}
				if (!update) break;
			}
			for (int v = 0; v < n; v++) {
				dual[v] += dist[v];
			}
		}
		dual_ref();
	}

	C single_flow(C c) {
		if (nd == INF) return nc;
		c = std::min(c, nc);
		for (int v = t; v != s; v = pv[v]) {
			E& e = g[pv[v]][pe[v]];
			e.cap -= c;
			g[v][e.rev].cap += c;
		}
		cap_flow += c;
		dist_flow += nd * c;
		nc -= c;
		if (!nc) dual_ref();
		return c;
	}

	void max_flow(C c) {
		while (c) {
			C f = single_flow(c);
			if (!f) break;
			c -= f;
		}
	}

	void dual_ref() {
		std::vector<D> dist(g.size(), D(INF));
		pv = pe = std::vector<int>(n, -1);
		struct Q {
			D key;
			int to;
			bool operator<(Q r) const { return key > r.key; }
		};
		std::priority_queue<Q> que;
		dist[s] = 0;
		que.push(Q{D(0), s});
		std::vector<char> vis(n);
		while (!que.empty()) {
			int v = que.top().to; que.pop();
			if (v == t) break;
			if (vis[v]) continue;
			vis[v] = true;
			for (int i = 0; i < int(g[v].size()); i++) {
				E e = g[v][i];
				if (vis[e.to] || !e.cap) continue;
				D cost = dist[v] + e.dist + dual[v] - dual[e.to];
				if (dist[e.to] > cost) {
					dist[e.to] = cost;
					pv[e.to] = v; pe[e.to] = i;
					que.push(Q{dist[e.to], e.to});
				}
			}
		}
		if (dist[t] == INF) {
			nd = INF; nc = 0;
			return;
		}
		for (int v = 0; v < n; v++) {
			if (!vis[v]) continue;
			dual[v] += dist[v] - dist[t];
		}
		nd = dual[t] - dual[s];
		nc = std::numeric_limits<C>::max();
		for (int v = t; v != s; v = pv[v]) {
			nc = std::min(nc, g[pv[v]][pe[v]].cap);
		}
	}
};
#include <bits/stdc++.h>

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

int main() {
    using namespace std;
    ios_base::sync_with_stdio(0);
    int L, R; cin >> L >> R;
    int M; cin >> M;
    Dinic<int> D;
    D.init(L + R + 2);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        int x = u + 1;
        int y = L + v + 1;
        D.ae(x, y, 1);
    }
    for (int i = 1; i <= L; i++) 
        D.ae(0, i, 1);
    for (int i = L + 1; i <= L + R; i++) 
        D.ae(i, L + R + 1, 1);
    cout << D.max_flow(0, L + R + 1) << '\n';
    for (int i = 1; i <= L; i++) {
        for (auto& eid : D.adj[i]) {
            if (eid & 1)
                continue;
            auto& e = D.edges[eid];
            if (e.cap == e.flow) {
                int u = i - 1;
                int v = e.to - L - 1;
                cout << u << " " << v << '\n';
            }
        }
    }
    return 0;
}
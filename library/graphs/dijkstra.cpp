#include<bits/stdc++.h>

template <class C, bool directed> struct Dijkstra {
    int SZ; std::vector<C> dist;
    std::vector<std::vector<std::pair<int, C>>> adj;

    void init(int _SZ) {
        SZ = _SZ;
        adj.clear();
        adj.resize(SZ);
    }

    void ae(int u, int v, C cost) {
        adj[u].emplace_back(v, cost);
        if (!directed) adj[v].emplace_back(u, cost);
    }

    void gen(int st) {
        dist = std::vector<C>(SZ, std::numeric_limits<C>::max());
        typedef std::pair<C, int> T;
        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
        auto ad = [&](int a, C b) {
            if (dist[a] <= b) return;
            pq.push({dist[a] = b, a});
        };
        ad(st, 0);
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            if (dist[x.second] < x.first) continue;
            for (auto& y: adj[x.second]) {
                ad(y.first, x.first + y.second);
            }
        }
    }
};

int main() {
    return 0;
}

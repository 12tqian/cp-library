#include<bits/stdc++.h>
template<class T> struct LCAJumpDistance {
    int n;
    std::vector<std::vector<int>> par;
    std::vector<std::vector<std::pair<int, T>>> adj;
    std::vector<int> depth;
    std::vector<T> depth_dist;
    void init(int _n) {
        n = _n;
        int d = 1;
        while ((1 << d) < n) d++;
        par.assign(d, std::vector<int>(n));
        adj.resize(n);
        depth.resize(n);
        depth_dist.resize(n);
    }
    void ae(int x, int y, T c = 1) {
        adj[x].emplace_back(y, c);
        adj[y].emplace_back(x, c);
    }
    void gen(int root = 0) {
        par[0][root] = root;
        dfs(root);
    }
    void dfs(int src = 0) {
        for (int i = 1; i < par.size(); i++) {
            par[i][src] = par[i - 1][par[i - 1][src]];
        }
        for (auto nxt: adj[src]) {
            if (nxt.first == par[0][src]) continue;
            depth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src] + nxt.second;
            depth[nxt.first] = depth[par[0][nxt.first] = src] + 1;
            dfs(nxt.first);
        }
    }
    int jump(int x, int d) {
        for (int i = 0; i < par.size(); i++) {
            if ((d >> i) & 1) {
                x = par[i][x];
            }
        }
        return x;
    }
    int lca(int x, int y) {
        if (depth[x] < depth[y]) std::swap(x, y);
        x = jump(x, depth[x] - depth[y]);
        if (x == y) return x;
        for (int i = par.size() - 1; i >= 0; i--) {
            int nx = par[i][x];
            int ny = par[i][y];
            if (nx != ny) x = nx, y = ny;
        }
        return par[0][x];
    }
    T distance(int x, int y) {
        int l = lca(x, y);
        return depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];
    }
};
int main() {
    return 0;
}

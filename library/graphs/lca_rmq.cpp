#include <bits/stdc++.h>

/**
 * O(n log n) preprocessing with O(1) query
 * Compress compute sthe minimal subtree containing
 * all node LCAs and comrpesses edges
 * O(S log S) compression
 * Returns list of (parent, original index)
 * Parent is the parent of node in compressed tree
 * Original index is the node it represents
 * get_child also returns the subtree child of node and -1 if it doesn't exist in O(1)
 */

template <class T> struct SparseTable {
    std::vector<T> v;
    std::vector<std::vector<int>> jump;

    int level(int x) {
        return 31 - __builtin_clz(x);
    }

    int comb(int a, int b) {
        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
    }

    void init(const std::vector<T>& _v) {
        v = _v;
        jump = {std::vector<int>((int) v.size())};
        iota(jump[0].begin(), jump[0].end(), 0);
        for (int j = 1; (1 << j) <= (int) v.size(); j++) {
            jump.push_back(std::vector<int>((int) v.size() - (1 << j) + 1));
            for (int i = 0; i < (int) jump[j].size(); i++) {
                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int index(int l, int r) {
        assert(l <= r);
        int d = level(r - l + 1);
        return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
    }

    T query(int l, int r) {
        return v[index(l, r)];
    }
};

struct LCARMQ {
    int n; 
    std::vector<std::vector<int>> adj;
    std::vector<int> dep, in, par, rev, out, pos;
    std::vector<std::pair<int, int>> tmp;
    SparseTable<std::pair<int, int>> S;
    std::vector<std::vector<int>> sparse;
    int ti = 0;

    void init(int _n) {
        n = _n;
        adj.resize(n);
        dep = in = out = par = rev = pos = std::vector<int>(n);
        sparse = {std::vector<int>(n)};
        for (int j = 1; (1 << j) <= n; j++) {
            sparse.push_back(std::vector<int>(n - (1 << j) + 1));
        }
    }

    void ae(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int src) {
        in[src] = ti++;
        sparse[0][in[src]] = src;
        pos[src] = (int) tmp.size();
        tmp.emplace_back(dep[src], src);
        for (auto& nxt : adj[src]) {
            if (nxt == par[src]) continue;
            dep[nxt] = dep[par[nxt] = src] + 1;
            dfs(nxt);
            tmp.emplace_back(dep[src], src);
        }
        out[src] = ti;
    }

    inline int mini(int u, int v) {
        return (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;
    }

    void gen(int root = 0) {
        par[root] = root;
        dfs(root);
        S.init(tmp); 
        for (int j = 1; j < (int) sparse.size(); j++) {
            for (int i = 0; i < (int) sparse[j].size(); i++) {
                sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int lca(int u, int v) {
        u = pos[u];
        v = pos[v];
        if (u > v) std::swap(u, v);
        return S.query(u, v).second;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    bool is_ancestor(int anc, int src) {
        return in[anc] <= in[src] && out[anc] >= out[src];
    }

    int get_child(int anc, int src) {
        if (!is_ancestor(anc, src)) return -1;
        int l = in[anc] + 1;
        int r = in[src];
        int d = 31 - __builtin_clz(r - l + 1);
        return mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);
    }
    
    std::vector<std::pair<int, int>> compress(std::vector<int> nodes) {
        auto cmp = [&](int a, int b) {
            return pos[a] < pos[b];
        };
        sort(nodes.begin(), nodes.end(), cmp);
        for (int i = int(nodes.size()) - 2; i >= 0; i--) {
            nodes.push_back(lca(nodes[i], nodes[i + 1]));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        std::vector<std::pair<int, int>> ret{{0, nodes[0]}};
        for (int i = 0; i < int(nodes.size()); i++) {
            rev[nodes[i]] = i;
        }
        for (int i = 1; i < int(nodes.size()); i++) {
            ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);
        }
        return ret;
    }
};

int main() {
    using namespace std;
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    LCARMQ L;
    L.init(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        L.ae(i, p);
    }
    L.gen(0);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << L.lca(u, v) << '\n';
    }
}
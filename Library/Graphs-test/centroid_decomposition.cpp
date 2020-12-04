#include <bits/stdc++.h>
struct CentroidDecomposition {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<bool> vis;
    std::vector<int> size;
    std::vector<int> parent;
    void init(int n_) {
        n = n_;
        adj.assign(n, std::vector<int>());
        vis.assign(n, false);
        parent.assign(n, 0);
    }
    void ae(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs_size(int src, int par = -1) {
        size[src] = 1;
        for (int nxt : adj[src]) {
            if (nxt == par || vis[nxt]) 
                continue;
            dfs_size(nxt, src);
            size[src] += size[nxt];
        }
    }
    int get_centroid(int src) {
        dfs_size(src);
        int num = size[src];
        int par = -1;
        do {    
            int go = -1;
            for (int nxt : adj[src]) {
                if (nxt == par || vis[nxt])
                    continue;
                if (2 * size[nxt] > num) 
                    go = nxt;
            }
            par = src;
            src = go;
        } while (src != -1);
        return par;
    }
    void centroid_decomposition(int src, int par = -1) {
        int c = get_centroid(src);
        vis[c] = true;
        parent[c] = par;
        for (int nxt : adj[c]) {
            if (vis[nxt]) 
                continue;
            centroid_decomposition(nxt, c);
        }
    }
};  
int main() {
    return 0;
}
---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/lca_rmq.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * O(n log n) preprocessing with O(1) query\n * Compress compute sthe minimal\
    \ subtree containing\n * all node LCAs and comrpesses edges\n * O(S log S) compression\n\
    \ * Returns list of (parent, original index)\n * Parent is the parent of node\
    \ in compressed tree\n * Original index is the node it represents\n * get_child\
    \ also returns the subtree child of node and -1 if it doesn't exist in O(1)\n\
    \ */\n\ntemplate <class T> struct SparseTable {\n    std::vector<T> v;\n    std::vector<std::vector<int>>\
    \ jump;\n\n    int level(int x) {\n        return 31 - __builtin_clz(x);\n   \
    \ }\n\n    int comb(int a, int b) {\n        return v[a] == v[b] ? std::min(a,\
    \ b) : (v[a] < v[b] ? a : b);\n    }\n\n    void init(const std::vector<T>& _v)\
    \ {\n        v = _v;\n        jump = {std::vector<int>((int) v.size())};\n   \
    \     iota(jump[0].begin(), jump[0].end(), 0);\n        for (int j = 1; (1 <<\
    \ j) <= (int) v.size(); j++) {\n            jump.push_back(std::vector<int>((int)\
    \ v.size() - (1 << j) + 1));\n            for (int i = 0; i < (int) jump[j].size();\
    \ i++) {\n                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1\
    \ << (j - 1))]);\n            }\n        }\n    }\n\n    int index(int l, int\
    \ r) {\n        assert(l <= r);\n        int d = level(r - l + 1);\n        return\
    \ comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n    }\n\n    T query(int l, int\
    \ r) {\n        return v[index(l, r)];\n    }\n};\n\nstruct LCARMQ {\n    int\
    \ n; \n    std::vector<std::vector<int>> adj;\n    std::vector<int> dep, in, par,\
    \ rev, out, pos;\n    std::vector<std::pair<int, int>> tmp;\n    SparseTable<std::pair<int,\
    \ int>> S;\n    std::vector<std::vector<int>> sparse;\n    int ti = 0;\n\n   \
    \ void init(int _n) {\n        n = _n;\n        adj.resize(n);\n        dep =\
    \ in = out = par = rev = pos = std::vector<int>(n);\n        sparse = {std::vector<int>(n)};\n\
    \        for (int j = 1; (1 << j) <= n; j++) {\n            sparse.push_back(std::vector<int>(n\
    \ - (1 << j) + 1));\n        }\n    }\n\n    void ae(int u, int v) {\n       \
    \ adj[u].push_back(v);\n        adj[v].push_back(u);\n    }\n\n    void dfs(int\
    \ src) {\n        in[src] = ti++;\n        sparse[0][in[src]] = src;\n       \
    \ pos[src] = (int) tmp.size();\n        tmp.emplace_back(dep[src], src);\n   \
    \     for (auto& nxt : adj[src]) {\n            if (nxt == par[src]) continue;\n\
    \            dep[nxt] = dep[par[nxt] = src] + 1;\n            dfs(nxt);\n    \
    \        tmp.emplace_back(dep[src], src);\n        }\n        out[src] = ti;\n\
    \    }\n\n    inline int mini(int u, int v) {\n        return (dep[u] < dep[v]\
    \ || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;\n    }\n\n    void gen(int\
    \ root = 0) {\n        par[root] = root;\n        dfs(root);\n        S.init(tmp);\
    \ \n        for (int j = 1; j < (int) sparse.size(); j++) {\n            for (int\
    \ i = 0; i < (int) sparse[j].size(); i++) {\n                sparse[j][i] = mini(sparse[j\
    \ - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\n            }\n        }\n   \
    \ }\n\n    int lca(int u, int v) {\n        u = pos[u];\n        v = pos[v];\n\
    \        if (u > v) std::swap(u, v);\n        return S.query(u, v).second;\n \
    \   }\n\n    int dist(int u, int v) {\n        return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n    }\n\n    bool is_ancestor(int anc, int src) {\n        return in[anc]\
    \ <= in[src] && out[anc] >= out[src];\n    }\n\n    int get_child(int anc, int\
    \ src) {\n        if (!is_ancestor(anc, src)) return -1;\n        int l = in[anc]\
    \ + 1;\n        int r = in[src];\n        int d = 31 - __builtin_clz(r - l + 1);\n\
    \        return mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\n    }\n    \n\
    \    std::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\n   \
    \     auto cmp = [&](int a, int b) {\n            return pos[a] < pos[b];\n  \
    \      };\n        sort(nodes.begin(), nodes.end(), cmp);\n        for (int i\
    \ = int(nodes.size()) - 2; i >= 0; i--) {\n            nodes.push_back(lca(nodes[i],\
    \ nodes[i + 1]));\n        }\n        sort(nodes.begin(), nodes.end(), cmp);\n\
    \        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());\n     \
    \   std::vector<std::pair<int, int>> ret{{0, nodes[0]}};\n        for (int i =\
    \ 0; i < int(nodes.size()); i++) {\n            rev[nodes[i]] = i;\n        }\n\
    \        for (int i = 1; i < int(nodes.size()); i++) {\n            ret.emplace_back(rev[lca(nodes[i\
    \ - 1], nodes[i])], nodes[i]);\n        }\n        return ret;\n    }\n};\n\n\
    int main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, q; cin >> n >> q;\n    LCARMQ L;\n    L.init(n);\n    for (int i =\
    \ 1; i < n; i++) {\n        int p; cin >> p;\n        L.ae(i, p);\n    }\n   \
    \ L.gen(0);\n    while (q--) {\n        int u, v; cin >> u >> v;\n        cout\
    \ << L.lca(u, v) << '\\n';\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * O(n log n) preprocessing with O(1) query\n\
    \ * Compress compute sthe minimal subtree containing\n * all node LCAs and comrpesses\
    \ edges\n * O(S log S) compression\n * Returns list of (parent, original index)\n\
    \ * Parent is the parent of node in compressed tree\n * Original index is the\
    \ node it represents\n * get_child also returns the subtree child of node and\
    \ -1 if it doesn't exist in O(1)\n */\n\ntemplate <class T> struct SparseTable\
    \ {\n    std::vector<T> v;\n    std::vector<std::vector<int>> jump;\n\n    int\
    \ level(int x) {\n        return 31 - __builtin_clz(x);\n    }\n\n    int comb(int\
    \ a, int b) {\n        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a\
    \ : b);\n    }\n\n    void init(const std::vector<T>& _v) {\n        v = _v;\n\
    \        jump = {std::vector<int>((int) v.size())};\n        iota(jump[0].begin(),\
    \ jump[0].end(), 0);\n        for (int j = 1; (1 << j) <= (int) v.size(); j++)\
    \ {\n            jump.push_back(std::vector<int>((int) v.size() - (1 << j) + 1));\n\
    \            for (int i = 0; i < (int) jump[j].size(); i++) {\n              \
    \  jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n     \
    \       }\n        }\n    }\n\n    int index(int l, int r) {\n        assert(l\
    \ <= r);\n        int d = level(r - l + 1);\n        return comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\n    }\n\n    T query(int l, int r) {\n        return v[index(l,\
    \ r)];\n    }\n};\n\nstruct LCARMQ {\n    int n; \n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> dep, in, par, rev, out, pos;\n    std::vector<std::pair<int,\
    \ int>> tmp;\n    SparseTable<std::pair<int, int>> S;\n    std::vector<std::vector<int>>\
    \ sparse;\n    int ti = 0;\n\n    void init(int _n) {\n        n = _n;\n     \
    \   adj.resize(n);\n        dep = in = out = par = rev = pos = std::vector<int>(n);\n\
    \        sparse = {std::vector<int>(n)};\n        for (int j = 1; (1 << j) <=\
    \ n; j++) {\n            sparse.push_back(std::vector<int>(n - (1 << j) + 1));\n\
    \        }\n    }\n\n    void ae(int u, int v) {\n        adj[u].push_back(v);\n\
    \        adj[v].push_back(u);\n    }\n\n    void dfs(int src) {\n        in[src]\
    \ = ti++;\n        sparse[0][in[src]] = src;\n        pos[src] = (int) tmp.size();\n\
    \        tmp.emplace_back(dep[src], src);\n        for (auto& nxt : adj[src])\
    \ {\n            if (nxt == par[src]) continue;\n            dep[nxt] = dep[par[nxt]\
    \ = src] + 1;\n            dfs(nxt);\n            tmp.emplace_back(dep[src], src);\n\
    \        }\n        out[src] = ti;\n    }\n\n    inline int mini(int u, int v)\
    \ {\n        return (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ?\
    \ u : v;\n    }\n\n    void gen(int root = 0) {\n        par[root] = root;\n \
    \       dfs(root);\n        S.init(tmp); \n        for (int j = 1; j < (int) sparse.size();\
    \ j++) {\n            for (int i = 0; i < (int) sparse[j].size(); i++) {\n   \
    \             sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j\
    \ - 1))]);\n            }\n        }\n    }\n\n    int lca(int u, int v) {\n \
    \       u = pos[u];\n        v = pos[v];\n        if (u > v) std::swap(u, v);\n\
    \        return S.query(u, v).second;\n    }\n\n    int dist(int u, int v) {\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    bool is_ancestor(int\
    \ anc, int src) {\n        return in[anc] <= in[src] && out[anc] >= out[src];\n\
    \    }\n\n    int get_child(int anc, int src) {\n        if (!is_ancestor(anc,\
    \ src)) return -1;\n        int l = in[anc] + 1;\n        int r = in[src];\n \
    \       int d = 31 - __builtin_clz(r - l + 1);\n        return mini(sparse[d][l],\
    \ sparse[d][r - (1 << d) + 1]);\n    }\n    \n    std::vector<std::pair<int, int>>\
    \ compress(std::vector<int> nodes) {\n        auto cmp = [&](int a, int b) {\n\
    \            return pos[a] < pos[b];\n        };\n        sort(nodes.begin(),\
    \ nodes.end(), cmp);\n        for (int i = int(nodes.size()) - 2; i >= 0; i--)\
    \ {\n            nodes.push_back(lca(nodes[i], nodes[i + 1]));\n        }\n  \
    \      sort(nodes.begin(), nodes.end(), cmp);\n        nodes.erase(unique(nodes.begin(),\
    \ nodes.end()), nodes.end());\n        std::vector<std::pair<int, int>> ret{{0,\
    \ nodes[0]}};\n        for (int i = 0; i < int(nodes.size()); i++) {\n       \
    \     rev[nodes[i]] = i;\n        }\n        for (int i = 1; i < int(nodes.size());\
    \ i++) {\n            ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);\n\
    \        }\n        return ret;\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q; cin >> n >> q;\n  \
    \  LCARMQ L;\n    L.init(n);\n    for (int i = 1; i < n; i++) {\n        int p;\
    \ cin >> p;\n        L.ae(i, p);\n    }\n    L.gen(0);\n    while (q--) {\n  \
    \      int u, v; cin >> u >> v;\n        cout << L.lca(u, v) << '\\n';\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca_rmq.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/lca_rmq.cpp
layout: document
redirect_from:
- /library/library/graphs/lca_rmq.cpp
- /library/library/graphs/lca_rmq.cpp.html
title: library/graphs/lca_rmq.cpp
---

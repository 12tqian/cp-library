---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/tree_path_queries.cpp\"\n#include<bits/stdc++.h>\r\
    \n\r\ntemplate <class T> struct LCAJumpSparse {\r\n    int n;\r\n    std::vector<std::vector<int>>\
    \ par;\r\n    std::vector<std::vector<T>> sparse;\r\n    std::vector<T> vals;\r\
    \n    std::vector<std::vector<int>> adj;\r\n    std::vector<int> depth;\r\n\r\n\
    \    T comb(T a, T b) {\r\n        return min(a, b);\r\n    }\r\n\r\n    void\
    \ init(int _n) {\r\n        n = _n;\r\n        int d = 1;\r\n        while ((1\
    \ << d) < n) d++;\r\n        par.assign(d, std::vector<int>(n));\r\n        adj.resize(n);\r\
    \n        depth.resize(n);\r\n        vals.resize(n);\r\n    }\r\n\r\n    void\
    \ set_val(int x, T v) {\r\n        vals[x] = v;\r\n    }\r\n\r\n    void ae(int\
    \ x, int y) {\r\n        adj[x].push_back(y);\r\n        adj[y].push_back(x);\r\
    \n    }\r\n\r\n    void gen(int root = 0) {\r\n        par[0][root] = root;\r\n\
    \        sparse[0][root] = vals[root];\r\n        dfs(root);\r\n    }\r\n\r\n\
    \    void dfs(int src = 0) {\r\n        for (int i = 1; i < par.size(); i++) {\r\
    \n            par[i][src] = par[i - 1][par[i - 1][src]];\r\n            sparse[i][src]\
    \ = comb(sparse[i - 1][src], sparse[i - 1][par[i - 1][src]]);\r\n        }\r\n\
    \        for (int nxt: adj[src]) {\r\n            if (nxt == par[0][src]) continue;\r\
    \n            depth[nxt] = depth[par[0][nxt] = src] + 1;\r\n            dfs(nxt);\r\
    \n        }\r\n    }\r\n\r\n    int jump(int x, int d) {\r\n        for (int i\
    \ = 0; i < par.size(); i++) {\r\n            if ((d >> i) & 1) {\r\n         \
    \       x = par[i][x];\r\n            }\r\n        }\r\n        return x;\r\n\
    \    }\r\n\r\n    int lca(int x, int y) {\r\n        if (depth[x] < depth[y])\
    \ std::swap(x, y);\r\n        x = jump(x, depth[x] - depth[y]);\r\n        if\
    \ (x == y) return x;\r\n        for (int i = par.size() - 1; i >= 0; i--) {\r\n\
    \            int nx = par[i][x];\r\n            int ny = par[i][y];\r\n      \
    \      if (nx != ny) x = nx, y = ny;\r\n        }\r\n        return par[0][x];\r\
    \n    }\r\n\r\n    T query(int x, int y) {\r\n        int anc = lca(x, y);\r\n\
    \        int d = 31 - __builtin_clz(depth[x] - depth[anc]);\r\n        T res1\
    \ = comb(sparse[d][x], sparse[d][jump(x, depth[x] - depth[anc] - (1 << d) + 1)]);\r\
    \n        d = 31 - __builtin_clz(depth[y] - depth[anc]);\r\n        T res2 = comb(sparse[d][y],\
    \ sparse[d][jump(y, depth[y] - depth[anc] - (1 << d) + 1)]);\r\n        return\
    \ comb(res1, res2);\r\n    }\r\n};\r\n\r\nint main() {\r\n    LCAJumpSparse<int>\
    \ L;\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\ntemplate <class T> struct LCAJumpSparse {\r\
    \n    int n;\r\n    std::vector<std::vector<int>> par;\r\n    std::vector<std::vector<T>>\
    \ sparse;\r\n    std::vector<T> vals;\r\n    std::vector<std::vector<int>> adj;\r\
    \n    std::vector<int> depth;\r\n\r\n    T comb(T a, T b) {\r\n        return\
    \ min(a, b);\r\n    }\r\n\r\n    void init(int _n) {\r\n        n = _n;\r\n  \
    \      int d = 1;\r\n        while ((1 << d) < n) d++;\r\n        par.assign(d,\
    \ std::vector<int>(n));\r\n        adj.resize(n);\r\n        depth.resize(n);\r\
    \n        vals.resize(n);\r\n    }\r\n\r\n    void set_val(int x, T v) {\r\n \
    \       vals[x] = v;\r\n    }\r\n\r\n    void ae(int x, int y) {\r\n        adj[x].push_back(y);\r\
    \n        adj[y].push_back(x);\r\n    }\r\n\r\n    void gen(int root = 0) {\r\n\
    \        par[0][root] = root;\r\n        sparse[0][root] = vals[root];\r\n   \
    \     dfs(root);\r\n    }\r\n\r\n    void dfs(int src = 0) {\r\n        for (int\
    \ i = 1; i < par.size(); i++) {\r\n            par[i][src] = par[i - 1][par[i\
    \ - 1][src]];\r\n            sparse[i][src] = comb(sparse[i - 1][src], sparse[i\
    \ - 1][par[i - 1][src]]);\r\n        }\r\n        for (int nxt: adj[src]) {\r\n\
    \            if (nxt == par[0][src]) continue;\r\n            depth[nxt] = depth[par[0][nxt]\
    \ = src] + 1;\r\n            dfs(nxt);\r\n        }\r\n    }\r\n\r\n    int jump(int\
    \ x, int d) {\r\n        for (int i = 0; i < par.size(); i++) {\r\n          \
    \  if ((d >> i) & 1) {\r\n                x = par[i][x];\r\n            }\r\n\
    \        }\r\n        return x;\r\n    }\r\n\r\n    int lca(int x, int y) {\r\n\
    \        if (depth[x] < depth[y]) std::swap(x, y);\r\n        x = jump(x, depth[x]\
    \ - depth[y]);\r\n        if (x == y) return x;\r\n        for (int i = par.size()\
    \ - 1; i >= 0; i--) {\r\n            int nx = par[i][x];\r\n            int ny\
    \ = par[i][y];\r\n            if (nx != ny) x = nx, y = ny;\r\n        }\r\n \
    \       return par[0][x];\r\n    }\r\n\r\n    T query(int x, int y) {\r\n    \
    \    int anc = lca(x, y);\r\n        int d = 31 - __builtin_clz(depth[x] - depth[anc]);\r\
    \n        T res1 = comb(sparse[d][x], sparse[d][jump(x, depth[x] - depth[anc]\
    \ - (1 << d) + 1)]);\r\n        d = 31 - __builtin_clz(depth[y] - depth[anc]);\r\
    \n        T res2 = comb(sparse[d][y], sparse[d][jump(y, depth[y] - depth[anc]\
    \ - (1 << d) + 1)]);\r\n        return comb(res1, res2);\r\n    }\r\n};\r\n\r\n\
    int main() {\r\n    LCAJumpSparse<int> L;\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/tree_path_queries.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:56:50-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/tree_path_queries.cpp
layout: document
redirect_from:
- /library/library/graphs/tree_path_queries.cpp
- /library/library/graphs/tree_path_queries.cpp.html
title: library/graphs/tree_path_queries.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/lca_jump_distance.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate<class T> struct LCAJumpDistance {\n    int n;\n    std::vector<std::vector<int>>\
    \ par;\n    std::vector<std::vector<std::pair<int, T>>> adj;\n    std::vector<int>\
    \ depth;\n    std::vector<T> depth_dist;\n\n    void init(int _n) {\n        n\
    \ = _n;\n        int d = 1;\n        while ((1 << d) < n) d++;\n        par.assign(d,\
    \ std::vector<int>(n));\n        adj.resize(n);\n        depth.resize(n);\n  \
    \      depth_dist.resize(n);\n    }\n\n    void ae(int x, int y, T c = 1) {\n\
    \        adj[x].emplace_back(y, c);\n        adj[y].emplace_back(x, c);\n    }\n\
    \n    void gen(int root = 0) {\n        par[0][root] = root;\n        dfs(root);\n\
    \    }\n\n    void dfs(int src = 0) {\n        for (int i = 1; i < (int) par.size();\
    \ i++) {\n            par[i][src] = par[i - 1][par[i - 1][src]];\n        }\n\
    \        for (auto nxt: adj[src]) {\n            if (nxt.first == par[0][src])\
    \ continue;\n            depth_dist[nxt.first] = depth_dist[par[0][nxt.first]\
    \ = src] + nxt.second;\n            depth[nxt.first] = depth[par[0][nxt.first]\
    \ = src] + 1;\n            dfs(nxt.first);\n        }\n    }\n\n    int jump(int\
    \ x, int d) {\n        for (int i = 0; i < (int) par.size(); i++) {\n        \
    \    if ((d >> i) & 1) {\n                x = par[i][x];\n            }\n    \
    \    }\n        return x;\n    }\n\n    int lca(int x, int y) {\n        if (depth[x]\
    \ < depth[y]) std::swap(x, y);\n        x = jump(x, depth[x] - depth[y]);\n  \
    \      if (x == y) return x;\n        for (int i = (int) par.size() - 1; i >=\
    \ 0; i--) {\n            int nx = par[i][x];\n            int ny = par[i][y];\n\
    \            if (nx != ny) x = nx, y = ny;\n        }\n        return par[0][x];\n\
    \    }\n\n    T distance(int x, int y) {\n        int l = lca(x, y);\n       \
    \ return depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\n    }\n};\n\nint\
    \ main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate<class T> struct LCAJumpDistance {\n \
    \   int n;\n    std::vector<std::vector<int>> par;\n    std::vector<std::vector<std::pair<int,\
    \ T>>> adj;\n    std::vector<int> depth;\n    std::vector<T> depth_dist;\n\n \
    \   void init(int _n) {\n        n = _n;\n        int d = 1;\n        while ((1\
    \ << d) < n) d++;\n        par.assign(d, std::vector<int>(n));\n        adj.resize(n);\n\
    \        depth.resize(n);\n        depth_dist.resize(n);\n    }\n\n    void ae(int\
    \ x, int y, T c = 1) {\n        adj[x].emplace_back(y, c);\n        adj[y].emplace_back(x,\
    \ c);\n    }\n\n    void gen(int root = 0) {\n        par[0][root] = root;\n \
    \       dfs(root);\n    }\n\n    void dfs(int src = 0) {\n        for (int i =\
    \ 1; i < (int) par.size(); i++) {\n            par[i][src] = par[i - 1][par[i\
    \ - 1][src]];\n        }\n        for (auto nxt: adj[src]) {\n            if (nxt.first\
    \ == par[0][src]) continue;\n            depth_dist[nxt.first] = depth_dist[par[0][nxt.first]\
    \ = src] + nxt.second;\n            depth[nxt.first] = depth[par[0][nxt.first]\
    \ = src] + 1;\n            dfs(nxt.first);\n        }\n    }\n\n    int jump(int\
    \ x, int d) {\n        for (int i = 0; i < (int) par.size(); i++) {\n        \
    \    if ((d >> i) & 1) {\n                x = par[i][x];\n            }\n    \
    \    }\n        return x;\n    }\n\n    int lca(int x, int y) {\n        if (depth[x]\
    \ < depth[y]) std::swap(x, y);\n        x = jump(x, depth[x] - depth[y]);\n  \
    \      if (x == y) return x;\n        for (int i = (int) par.size() - 1; i >=\
    \ 0; i--) {\n            int nx = par[i][x];\n            int ny = par[i][y];\n\
    \            if (nx != ny) x = nx, y = ny;\n        }\n        return par[0][x];\n\
    \    }\n\n    T distance(int x, int y) {\n        int l = lca(x, y);\n       \
    \ return depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\n    }\n};\n\nint\
    \ main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca_jump_distance.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/lca_jump_distance.cpp
layout: document
redirect_from:
- /library/library/graphs/lca_jump_distance.cpp
- /library/library/graphs/lca_jump_distance.cpp.html
title: library/graphs/lca_jump_distance.cpp
---

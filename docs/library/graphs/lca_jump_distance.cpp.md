---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\graphs\\\\lca_jump_distance.cpp\"\n#include<bits/stdc++.h>\r\
    \ntemplate<class T> struct LCAJumpDistance {\r\n    int n;\r\n    std::vector<std::vector<int>>\
    \ par;\r\n    std::vector<std::vector<std::pair<int, T>>> adj;\r\n    std::vector<int>\
    \ depth;\r\n    std::vector<T> depth_dist;\r\n    void init(int _n) {\r\n    \
    \    n = _n;\r\n        int d = 1;\r\n        while ((1 << d) < n) d++;\r\n  \
    \      par.assign(d, std::vector<int>(n));\r\n        adj.resize(n);\r\n     \
    \   depth.resize(n);\r\n        depth_dist.resize(n);\r\n    }\r\n    void ae(int\
    \ x, int y, T c = 1) {\r\n        adj[x].emplace_back(y, c);\r\n        adj[y].emplace_back(x,\
    \ c);\r\n    }\r\n    void gen(int root = 0) {\r\n        par[0][root] = root;\r\
    \n        dfs(root);\r\n    }\r\n    void dfs(int src = 0) {\r\n        for (int\
    \ i = 1; i < par.size(); i++) {\r\n            par[i][src] = par[i - 1][par[i\
    \ - 1][src]];\r\n        }\r\n        for (auto nxt: adj[src]) {\r\n         \
    \   if (nxt.first == par[0][src]) continue;\r\n            depth_dist[nxt.first]\
    \ = depth_dist[par[0][nxt.first] = src] + nxt.second;\r\n            depth[nxt.first]\
    \ = depth[par[0][nxt.first] = src] + 1;\r\n            dfs(nxt.first);\r\n   \
    \     }\r\n    }\r\n    int jump(int x, int d) {\r\n        for (int i = 0; i\
    \ < par.size(); i++) {\r\n            if ((d >> i) & 1) {\r\n                x\
    \ = par[i][x];\r\n            }\r\n        }\r\n        return x;\r\n    }\r\n\
    \    int lca(int x, int y) {\r\n        if (depth[x] < depth[y]) std::swap(x,\
    \ y);\r\n        x = jump(x, depth[x] - depth[y]);\r\n        if (x == y) return\
    \ x;\r\n        for (int i = par.size() - 1; i >= 0; i--) {\r\n            int\
    \ nx = par[i][x];\r\n            int ny = par[i][y];\r\n            if (nx !=\
    \ ny) x = nx, y = ny;\r\n        }\r\n        return par[0][x];\r\n    }\r\n \
    \   T distance(int x, int y) {\r\n        int l = lca(x, y);\r\n        return\
    \ depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\r\n    }\r\n};\r\nint main()\
    \ {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\ntemplate<class T> struct LCAJumpDistance {\r\n\
    \    int n;\r\n    std::vector<std::vector<int>> par;\r\n    std::vector<std::vector<std::pair<int,\
    \ T>>> adj;\r\n    std::vector<int> depth;\r\n    std::vector<T> depth_dist;\r\
    \n    void init(int _n) {\r\n        n = _n;\r\n        int d = 1;\r\n       \
    \ while ((1 << d) < n) d++;\r\n        par.assign(d, std::vector<int>(n));\r\n\
    \        adj.resize(n);\r\n        depth.resize(n);\r\n        depth_dist.resize(n);\r\
    \n    }\r\n    void ae(int x, int y, T c = 1) {\r\n        adj[x].emplace_back(y,\
    \ c);\r\n        adj[y].emplace_back(x, c);\r\n    }\r\n    void gen(int root\
    \ = 0) {\r\n        par[0][root] = root;\r\n        dfs(root);\r\n    }\r\n  \
    \  void dfs(int src = 0) {\r\n        for (int i = 1; i < par.size(); i++) {\r\
    \n            par[i][src] = par[i - 1][par[i - 1][src]];\r\n        }\r\n    \
    \    for (auto nxt: adj[src]) {\r\n            if (nxt.first == par[0][src]) continue;\r\
    \n            depth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src] + nxt.second;\r\
    \n            depth[nxt.first] = depth[par[0][nxt.first] = src] + 1;\r\n     \
    \       dfs(nxt.first);\r\n        }\r\n    }\r\n    int jump(int x, int d) {\r\
    \n        for (int i = 0; i < par.size(); i++) {\r\n            if ((d >> i) &\
    \ 1) {\r\n                x = par[i][x];\r\n            }\r\n        }\r\n   \
    \     return x;\r\n    }\r\n    int lca(int x, int y) {\r\n        if (depth[x]\
    \ < depth[y]) std::swap(x, y);\r\n        x = jump(x, depth[x] - depth[y]);\r\n\
    \        if (x == y) return x;\r\n        for (int i = par.size() - 1; i >= 0;\
    \ i--) {\r\n            int nx = par[i][x];\r\n            int ny = par[i][y];\r\
    \n            if (nx != ny) x = nx, y = ny;\r\n        }\r\n        return par[0][x];\r\
    \n    }\r\n    T distance(int x, int y) {\r\n        int l = lca(x, y);\r\n  \
    \      return depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\r\n    }\r\n\
    };\r\nint main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\graphs\lca_jump_distance.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:15:26-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\graphs\lca_jump_distance.cpp
layout: document
redirect_from:
- /library\library\graphs\lca_jump_distance.cpp
- /library\library\graphs\lca_jump_distance.cpp.html
title: library\graphs\lca_jump_distance.cpp
---

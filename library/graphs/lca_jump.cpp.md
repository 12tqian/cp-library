---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/lca_jump.cpp\"\n#include<bits/stdc++.h>\n\
    \n/**\n * To support forest, call gen for each roots\n */\nstruct LCAJump {\n\
    \    int n;\n    std::vector<std::vector<int>> par;\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> depth;\n\n    void init(int _n) {\n        n = _n;\n\
    \        int d = 1;\n        while ((1 << d) < n) d++;\n        par.assign(d,\
    \ std::vector<int>(n));\n        adj.resize(n);\n        depth.resize(n);\n  \
    \  }\n\n    void ae(int x, int y) {\n        adj[x].push_back(y);\n        adj[y].push_back(x);\n\
    \    }\n\n    void gen(int root = 0) {\n        par[0][root] = root;\n       \
    \ dfs(root);\n    }\n\n    void dfs(int src = 0) {\n        for (int i = 1; i\
    \ < (int)par.size(); i++) {\n            par[i][src] = par[i - 1][par[i - 1][src]];\n\
    \        }\n        for (int nxt: adj[src]) {\n            if (nxt == par[0][src])\
    \ continue;\n            depth[nxt] = depth[par[0][nxt] = src] + 1;\n        \
    \    dfs(nxt);\n        }\n    }\n\n    int jump(int x, int d) {\n        for\
    \ (int i = 0; i < (int)par.size(); i++) {\n            if ((d >> i) & 1) {\n \
    \               x = par[i][x];\n            }\n        }\n        return x;\n\
    \    }\n    \n    int lca(int x, int y) {\n        if (depth[x] < depth[y]) std::swap(x,\
    \ y);\n        x = jump(x, depth[x] - depth[y]);\n        if (x == y) return x;\n\
    \        for (int i = (int)par.size() - 1; i >= 0; i--) {\n            int nx\
    \ = par[i][x];\n            int ny = par[i][y];\n            if (nx != ny) x =\
    \ nx, y = ny;\n        }\n        return par[0][x];\n    }\n};\n\nint main() {\n\
    \    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\
    \ cin >> n >> q;\n    LCAJump L;\n    L.init(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p; cin >> p;\n        L.ae(i, p);\n    }\n    L.gen(0);\n   \
    \ while (q--) {\n        int u, v; cin >> u >> v;\n        cout << L.lca(u, v)\
    \ << '\\n';\n    }\n}\n"
  code: "#include<bits/stdc++.h>\n\n/**\n * To support forest, call gen for each roots\n\
    \ */\nstruct LCAJump {\n    int n;\n    std::vector<std::vector<int>> par;\n \
    \   std::vector<std::vector<int>> adj;\n    std::vector<int> depth;\n\n    void\
    \ init(int _n) {\n        n = _n;\n        int d = 1;\n        while ((1 << d)\
    \ < n) d++;\n        par.assign(d, std::vector<int>(n));\n        adj.resize(n);\n\
    \        depth.resize(n);\n    }\n\n    void ae(int x, int y) {\n        adj[x].push_back(y);\n\
    \        adj[y].push_back(x);\n    }\n\n    void gen(int root = 0) {\n       \
    \ par[0][root] = root;\n        dfs(root);\n    }\n\n    void dfs(int src = 0)\
    \ {\n        for (int i = 1; i < (int)par.size(); i++) {\n            par[i][src]\
    \ = par[i - 1][par[i - 1][src]];\n        }\n        for (int nxt: adj[src]) {\n\
    \            if (nxt == par[0][src]) continue;\n            depth[nxt] = depth[par[0][nxt]\
    \ = src] + 1;\n            dfs(nxt);\n        }\n    }\n\n    int jump(int x,\
    \ int d) {\n        for (int i = 0; i < (int)par.size(); i++) {\n            if\
    \ ((d >> i) & 1) {\n                x = par[i][x];\n            }\n        }\n\
    \        return x;\n    }\n    \n    int lca(int x, int y) {\n        if (depth[x]\
    \ < depth[y]) std::swap(x, y);\n        x = jump(x, depth[x] - depth[y]);\n  \
    \      if (x == y) return x;\n        for (int i = (int)par.size() - 1; i >= 0;\
    \ i--) {\n            int nx = par[i][x];\n            int ny = par[i][y];\n \
    \           if (nx != ny) x = nx, y = ny;\n        }\n        return par[0][x];\n\
    \    }\n};\n\nint main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, q; cin >> n >> q;\n    LCAJump L;\n    L.init(n);\n    for (int i\
    \ = 1; i < n; i++) {\n        int p; cin >> p;\n        L.ae(i, p);\n    }\n \
    \   L.gen(0);\n    while (q--) {\n        int u, v; cin >> u >> v;\n        cout\
    \ << L.lca(u, v) << '\\n';\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca_jump.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/lca_jump.cpp
layout: document
redirect_from:
- /library/library/graphs/lca_jump.cpp
- /library/library/graphs/lca_jump.cpp.html
title: library/graphs/lca_jump.cpp
---

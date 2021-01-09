---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/centroid_decomposition.cpp\"\n#include <bits/stdc++.h>\n\
    \nstruct CentroidDecomposition {\n    int n;\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<bool> vis;\n    std::vector<int> size;\n    std::vector<int>\
    \ parent;\n\n    void init(int n_) {\n        n = n_;\n        adj.assign(n, std::vector<int>());\n\
    \        vis.assign(n, false);\n        parent.assign(n, 0);\n    }\n\n    void\
    \ ae(int u, int v) {\n        adj[u].push_back(v);\n        adj[v].push_back(u);\n\
    \    }\n\n    void dfs_size(int src, int par = -1) {\n        size[src] = 1;\n\
    \        for (int nxt : adj[src]) {\n            if (nxt == par || vis[nxt]) \n\
    \                continue;\n            dfs_size(nxt, src);\n            size[src]\
    \ += size[nxt];\n        }\n    }\n\n    int get_centroid(int src) {\n       \
    \ dfs_size(src);\n        int num = size[src];\n        int par = -1;\n      \
    \  do {    \n            int go = -1;\n            for (int nxt : adj[src]) {\n\
    \                if (nxt == par || vis[nxt])\n                    continue;\n\
    \                if (2 * size[nxt] > num) \n                    go = nxt;\n  \
    \          }\n            par = src;\n            src = go;\n        } while (src\
    \ != -1);\n        return par;\n    }\n\n    void centroid_decomposition(int src,\
    \ int par = -1) {\n        int c = get_centroid(src);\n        vis[c] = true;\n\
    \        parent[c] = par;\n        for (int nxt : adj[c]) {\n            if (vis[nxt])\
    \ \n                continue;\n            centroid_decomposition(nxt, c);\n \
    \       }\n    }\n};  \n\nint main() {\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct CentroidDecomposition {\n    int n;\n\
    \    std::vector<std::vector<int>> adj;\n    std::vector<bool> vis;\n    std::vector<int>\
    \ size;\n    std::vector<int> parent;\n\n    void init(int n_) {\n        n =\
    \ n_;\n        adj.assign(n, std::vector<int>());\n        vis.assign(n, false);\n\
    \        parent.assign(n, 0);\n    }\n\n    void ae(int u, int v) {\n        adj[u].push_back(v);\n\
    \        adj[v].push_back(u);\n    }\n\n    void dfs_size(int src, int par = -1)\
    \ {\n        size[src] = 1;\n        for (int nxt : adj[src]) {\n            if\
    \ (nxt == par || vis[nxt]) \n                continue;\n            dfs_size(nxt,\
    \ src);\n            size[src] += size[nxt];\n        }\n    }\n\n    int get_centroid(int\
    \ src) {\n        dfs_size(src);\n        int num = size[src];\n        int par\
    \ = -1;\n        do {    \n            int go = -1;\n            for (int nxt\
    \ : adj[src]) {\n                if (nxt == par || vis[nxt])\n               \
    \     continue;\n                if (2 * size[nxt] > num) \n                 \
    \   go = nxt;\n            }\n            par = src;\n            src = go;\n\
    \        } while (src != -1);\n        return par;\n    }\n\n    void centroid_decomposition(int\
    \ src, int par = -1) {\n        int c = get_centroid(src);\n        vis[c] = true;\n\
    \        parent[c] = par;\n        for (int nxt : adj[c]) {\n            if (vis[nxt])\
    \ \n                continue;\n            centroid_decomposition(nxt, c);\n \
    \       }\n    }\n};  \n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/library/graphs/centroid_decomposition.cpp
- /library/library/graphs/centroid_decomposition.cpp.html
title: library/graphs/centroid_decomposition.cpp
---

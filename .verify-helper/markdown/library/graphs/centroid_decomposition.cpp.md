---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/centroid_decomposition.cpp\"\n#include <bits/stdc++.h>\r\
    \nstruct CentroidDecomposition {\r\n    int n;\r\n    std::vector<std::vector<int>>\
    \ adj;\r\n    std::vector<bool> vis;\r\n    std::vector<int> size;\r\n    std::vector<int>\
    \ parent;\r\n    void init(int n_) {\r\n        n = n_;\r\n        adj.assign(n,\
    \ std::vector<int>());\r\n        vis.assign(n, false);\r\n        parent.assign(n,\
    \ 0);\r\n    }\r\n    void ae(int u, int v) {\r\n        adj[u].push_back(v);\r\
    \n        adj[v].push_back(u);\r\n    }\r\n    void dfs_size(int src, int par\
    \ = -1) {\r\n        size[src] = 1;\r\n        for (int nxt : adj[src]) {\r\n\
    \            if (nxt == par || vis[nxt]) \r\n                continue;\r\n   \
    \         dfs_size(nxt, src);\r\n            size[src] += size[nxt];\r\n     \
    \   }\r\n    }\r\n    int get_centroid(int src) {\r\n        dfs_size(src);\r\n\
    \        int num = size[src];\r\n        int par = -1;\r\n        do {    \r\n\
    \            int go = -1;\r\n            for (int nxt : adj[src]) {\r\n      \
    \          if (nxt == par || vis[nxt])\r\n                    continue;\r\n  \
    \              if (2 * size[nxt] > num) \r\n                    go = nxt;\r\n\
    \            }\r\n            par = src;\r\n            src = go;\r\n        }\
    \ while (src != -1);\r\n        return par;\r\n    }\r\n    void centroid_decomposition(int\
    \ src, int par = -1) {\r\n        int c = get_centroid(src);\r\n        vis[c]\
    \ = true;\r\n        parent[c] = par;\r\n        for (int nxt : adj[c]) {\r\n\
    \            if (vis[nxt]) \r\n                continue;\r\n            centroid_decomposition(nxt,\
    \ c);\r\n        }\r\n    }\r\n};  \r\nint main() {\r\n    return 0;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nstruct CentroidDecomposition {\r\n    int n;\r\
    \n    std::vector<std::vector<int>> adj;\r\n    std::vector<bool> vis;\r\n   \
    \ std::vector<int> size;\r\n    std::vector<int> parent;\r\n    void init(int\
    \ n_) {\r\n        n = n_;\r\n        adj.assign(n, std::vector<int>());\r\n \
    \       vis.assign(n, false);\r\n        parent.assign(n, 0);\r\n    }\r\n   \
    \ void ae(int u, int v) {\r\n        adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\
    \n    }\r\n    void dfs_size(int src, int par = -1) {\r\n        size[src] = 1;\r\
    \n        for (int nxt : adj[src]) {\r\n            if (nxt == par || vis[nxt])\
    \ \r\n                continue;\r\n            dfs_size(nxt, src);\r\n       \
    \     size[src] += size[nxt];\r\n        }\r\n    }\r\n    int get_centroid(int\
    \ src) {\r\n        dfs_size(src);\r\n        int num = size[src];\r\n       \
    \ int par = -1;\r\n        do {    \r\n            int go = -1;\r\n          \
    \  for (int nxt : adj[src]) {\r\n                if (nxt == par || vis[nxt])\r\
    \n                    continue;\r\n                if (2 * size[nxt] > num) \r\
    \n                    go = nxt;\r\n            }\r\n            par = src;\r\n\
    \            src = go;\r\n        } while (src != -1);\r\n        return par;\r\
    \n    }\r\n    void centroid_decomposition(int src, int par = -1) {\r\n      \
    \  int c = get_centroid(src);\r\n        vis[c] = true;\r\n        parent[c] =\
    \ par;\r\n        for (int nxt : adj[c]) {\r\n            if (vis[nxt]) \r\n \
    \               continue;\r\n            centroid_decomposition(nxt, c);\r\n \
    \       }\r\n    }\r\n};  \r\nint main() {\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2020-12-02 18:35:52-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/library/graphs/centroid_decomposition.cpp
- /library/library/graphs/centroid_decomposition.cpp.html
title: library/graphs/centroid_decomposition.cpp
---

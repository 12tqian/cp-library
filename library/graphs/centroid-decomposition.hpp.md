---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\nstruct CentroidDecomposition {\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ g, cg; // cg is directed tree for centroids\r\n\tstd::vector<bool> vis;\r\n\t\
    std::vector<int> size;\r\n\tstd::vector<int> parent;\r\n\tint root;\r\n\r\n\t\
    void init(int n_) {\r\n\t\tn = n_;\r\n\t\tg.assign(n, std::vector<int>());\r\n\
    \t\tcg.assign(n, std::vector<int>());\r\n\t\tvis.assign(n, false);\r\n\t\tparent.assign(n,\
    \ 0);\r\n\t\tsize.assign(n, 0);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\t\
    g[u].push_back(v);\r\n\t\tg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid dfs_size(int\
    \ src, int par = -1) {\r\n\t\tsize[src] = 1;\r\n\t\tfor (int nxt : g[src]) {\r\
    \n\t\t\tif (nxt == par || vis[nxt]) \r\n\t\t\t\tcontinue;\r\n\t\t\tdfs_size(nxt,\
    \ src);\r\n\t\t\tsize[src] += size[nxt];\r\n\t\t}\r\n\t}\r\n\r\n\tint get_centroid(int\
    \ src) {\r\n\t\tdfs_size(src);\r\n\t\tint num = size[src];\r\n\t\tint par = -1;\r\
    \n\t\tdo {    \t\r\n\t\t\tint go = -1;\r\n\t\t\tfor (int nxt : g[src]) {\r\n\t\
    \t\t\tif (nxt == par || vis[nxt])\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\tif (2 * size[nxt]\
    \ > num) \r\n\t\t\t\t\tgo = nxt;\r\n\t\t\t}\r\n\t\t\tpar = src;\r\n\t\t\tsrc =\
    \ go;\r\n\t\t} while (src != -1);\r\n\t\treturn par;\r\n\t}\r\n\r\n\tint build_dfs(int\
    \ src, int par = -1) {\r\n\t\tint c = get_centroid(src);\r\n\t\tvis[c] = true;\r\
    \n\t\tparent[c] = par;\r\n\t\tif (par != -1) {\r\n\t\t\tcg[par].push_back(c);\r\
    \n\t\t}\r\n\t\tfor (int nxt : g[c]) {\r\n\t\t\tif (vis[nxt]) \r\n\t\t\t\tcontinue;\r\
    \n\t\t\tbuild_dfs(nxt, c);\r\n\t\t}\r\n\t\treturn c;\r\n\t}\r\n\r\n\tvoid build()\
    \ {\r\n\t\troot = build_dfs(0);\r\n\t}\r\n};  \r\n"
  code: "#pragma once\r\n\r\nstruct CentroidDecomposition {\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ g, cg; // cg is directed tree for centroids\r\n\tstd::vector<bool> vis;\r\n\t\
    std::vector<int> size;\r\n\tstd::vector<int> parent;\r\n\tint root;\r\n\r\n\t\
    void init(int n_) {\r\n\t\tn = n_;\r\n\t\tg.assign(n, std::vector<int>());\r\n\
    \t\tcg.assign(n, std::vector<int>());\r\n\t\tvis.assign(n, false);\r\n\t\tparent.assign(n,\
    \ 0);\r\n\t\tsize.assign(n, 0);\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\t\
    g[u].push_back(v);\r\n\t\tg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid dfs_size(int\
    \ src, int par = -1) {\r\n\t\tsize[src] = 1;\r\n\t\tfor (int nxt : g[src]) {\r\
    \n\t\t\tif (nxt == par || vis[nxt]) \r\n\t\t\t\tcontinue;\r\n\t\t\tdfs_size(nxt,\
    \ src);\r\n\t\t\tsize[src] += size[nxt];\r\n\t\t}\r\n\t}\r\n\r\n\tint get_centroid(int\
    \ src) {\r\n\t\tdfs_size(src);\r\n\t\tint num = size[src];\r\n\t\tint par = -1;\r\
    \n\t\tdo {    \t\r\n\t\t\tint go = -1;\r\n\t\t\tfor (int nxt : g[src]) {\r\n\t\
    \t\t\tif (nxt == par || vis[nxt])\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\tif (2 * size[nxt]\
    \ > num) \r\n\t\t\t\t\tgo = nxt;\r\n\t\t\t}\r\n\t\t\tpar = src;\r\n\t\t\tsrc =\
    \ go;\r\n\t\t} while (src != -1);\r\n\t\treturn par;\r\n\t}\r\n\r\n\tint build_dfs(int\
    \ src, int par = -1) {\r\n\t\tint c = get_centroid(src);\r\n\t\tvis[c] = true;\r\
    \n\t\tparent[c] = par;\r\n\t\tif (par != -1) {\r\n\t\t\tcg[par].push_back(c);\r\
    \n\t\t}\r\n\t\tfor (int nxt : g[c]) {\r\n\t\t\tif (vis[nxt]) \r\n\t\t\t\tcontinue;\r\
    \n\t\t\tbuild_dfs(nxt, c);\r\n\t\t}\r\n\t\treturn c;\r\n\t}\r\n\r\n\tvoid build()\
    \ {\r\n\t\troot = build_dfs(0);\r\n\t}\r\n};  \r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/centroid-decomposition.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
documentation_of: library/graphs/centroid-decomposition.hpp
layout: document
redirect_from:
- /library/library/graphs/centroid-decomposition.hpp
- /library/library/graphs/centroid-decomposition.hpp.html
title: library/graphs/centroid-decomposition.hpp
---

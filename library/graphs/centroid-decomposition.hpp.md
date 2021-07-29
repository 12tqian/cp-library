---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nstruct CentroidDecomposition {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ g, cg; // cg is directed tree for centroids\n\tstd::vector<bool> vis;\n\tstd::vector<int>\
    \ size;\n\tstd::vector<int> parent;\n\tint root;\n\n\tvoid init(int n_) {\n\t\t\
    n = n_;\n\t\tg.assign(n, std::vector<int>());\n\t\tcg.assign(n, std::vector<int>());\n\
    \t\tvis.assign(n, false);\n\t\tparent.assign(n, 0);\n\t\tsize.assign(n, 0);\n\t\
    }\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\
    \t}\n\n\tvoid dfs_size(int src, int par = -1) {\n\t\tsize[src] = 1;\n\t\tfor (int\
    \ nxt : g[src]) {\n\t\t\tif (nxt == par || vis[nxt]) \n\t\t\t\tcontinue;\n\t\t\
    \tdfs_size(nxt, src);\n\t\t\tsize[src] += size[nxt];\n\t\t}\n\t}\n\n\tint get_centroid(int\
    \ src) {\n\t\tdfs_size(src);\n\t\tint num = size[src];\n\t\tint par = -1;\n\t\t\
    do {    \t\n\t\t\tint go = -1;\n\t\t\tfor (int nxt : g[src]) {\n\t\t\t\tif (nxt\
    \ == par || vis[nxt])\n\t\t\t\t\tcontinue;\n\t\t\t\tif (2 * size[nxt] > num) \n\
    \t\t\t\t\tgo = nxt;\n\t\t\t}\n\t\t\tpar = src;\n\t\t\tsrc = go;\n\t\t} while (src\
    \ != -1);\n\t\treturn par;\n\t}\n\n\tint build_dfs(int src, int par = -1) {\n\t\
    \tint c = get_centroid(src);\n\t\tvis[c] = true;\n\t\tparent[c] = par;\n\t\tif\
    \ (par != -1) {\n\t\t\tcg[par].push_back(c);\n\t\t}\n\t\tfor (int nxt : g[c])\
    \ {\n\t\t\tif (vis[nxt]) \n\t\t\t\tcontinue;\n\t\t\tbuild_dfs(nxt, c);\n\t\t}\n\
    \t\treturn c;\n\t}\n\n\tvoid build() {\n\t\troot = build_dfs(0);\n\t}\n};  \n"
  code: "#pragma once\n\nstruct CentroidDecomposition {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ g, cg; // cg is directed tree for centroids\n\tstd::vector<bool> vis;\n\tstd::vector<int>\
    \ size;\n\tstd::vector<int> parent;\n\tint root;\n\n\tvoid init(int n_) {\n\t\t\
    n = n_;\n\t\tg.assign(n, std::vector<int>());\n\t\tcg.assign(n, std::vector<int>());\n\
    \t\tvis.assign(n, false);\n\t\tparent.assign(n, 0);\n\t\tsize.assign(n, 0);\n\t\
    }\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\
    \t}\n\n\tvoid dfs_size(int src, int par = -1) {\n\t\tsize[src] = 1;\n\t\tfor (int\
    \ nxt : g[src]) {\n\t\t\tif (nxt == par || vis[nxt]) \n\t\t\t\tcontinue;\n\t\t\
    \tdfs_size(nxt, src);\n\t\t\tsize[src] += size[nxt];\n\t\t}\n\t}\n\n\tint get_centroid(int\
    \ src) {\n\t\tdfs_size(src);\n\t\tint num = size[src];\n\t\tint par = -1;\n\t\t\
    do {    \t\n\t\t\tint go = -1;\n\t\t\tfor (int nxt : g[src]) {\n\t\t\t\tif (nxt\
    \ == par || vis[nxt])\n\t\t\t\t\tcontinue;\n\t\t\t\tif (2 * size[nxt] > num) \n\
    \t\t\t\t\tgo = nxt;\n\t\t\t}\n\t\t\tpar = src;\n\t\t\tsrc = go;\n\t\t} while (src\
    \ != -1);\n\t\treturn par;\n\t}\n\n\tint build_dfs(int src, int par = -1) {\n\t\
    \tint c = get_centroid(src);\n\t\tvis[c] = true;\n\t\tparent[c] = par;\n\t\tif\
    \ (par != -1) {\n\t\t\tcg[par].push_back(c);\n\t\t}\n\t\tfor (int nxt : g[c])\
    \ {\n\t\t\tif (vis[nxt]) \n\t\t\t\tcontinue;\n\t\t\tbuild_dfs(nxt, c);\n\t\t}\n\
    \t\treturn c;\n\t}\n\n\tvoid build() {\n\t\troot = build_dfs(0);\n\t}\n};  \n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/centroid-decomposition.hpp
  requiredBy: []
  timestamp: '2021-07-29 00:53:10-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
documentation_of: library/graphs/centroid-decomposition.hpp
layout: document
redirect_from:
- /library/library/graphs/centroid-decomposition.hpp
- /library/library/graphs/centroid-decomposition.hpp.html
title: library/graphs/centroid-decomposition.hpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "library/graphs/centroid_decomposition.cpp"

    '
  code: "#include <bits/stdc++.h>\n\nstruct CentroidDecomposition {\n\tint n;\n\t\
    std::vector<std::vector<int>> adj;\n\tstd::vector<bool> vis;\n\tstd::vector<int>\
    \ size;\n\tstd::vector<int> parent;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\t\
    adj.assign(n, std::vector<int>());\n\t\tvis.assign(n, false);\n\t\tparent.assign(n,\
    \ 0);\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\t\tadj[v].push_back(u);\n\
    \t}\n\n\tvoid dfs_size(int src, int par = -1) {\n\t\tsize[src] = 1;\n\t\tfor (int\
    \ nxt : adj[src]) {\n\t\t\tif (nxt == par || vis[nxt]) \n\t\t\t\tcontinue;\n\t\
    \t\tdfs_size(nxt, src);\n\t\t\tsize[src] += size[nxt];\n\t\t}\n\t}\n\n\tint get_centroid(int\
    \ src) {\n\t\tdfs_size(src);\n\t\tint num = size[src];\n\t\tint par = -1;\n\t\t\
    do {    \n\t\t\tint go = -1;\n\t\t\tfor (int nxt : adj[src]) {\n\t\t\t\tif (nxt\
    \ == par || vis[nxt])\n\t\t\t\t\tcontinue;\n\t\t\t\tif (2 * size[nxt] > num) \n\
    \t\t\t\t\tgo = nxt;\n\t\t\t}\n\t\t\tpar = src;\n\t\t\tsrc = go;\n\t\t} while (src\
    \ != -1);\n\t\treturn par;\n\t}\n\n\tvoid centroid_decomposition(int src, int\
    \ par = -1) {\n\t\tint c = get_centroid(src);\n\t\tvis[c] = true;\n\t\tparent[c]\
    \ = par;\n\t\tfor (int nxt : adj[c]) {\n\t\t\tif (vis[nxt]) \n\t\t\t\tcontinue;\n\
    \t\t\tcentroid_decomposition(nxt, c);\n\t\t}\n\t}\n};  \n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/library/graphs/centroid_decomposition.cpp
- /library/library/graphs/centroid_decomposition.cpp.html
title: library/graphs/centroid_decomposition.cpp
---

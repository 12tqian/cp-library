---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/strongly-connected-components-tarjan.test.cpp
    title: test/strongly-connected-components-tarjan.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nstruct SCC {\n\tint n, time, num_comps;\n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> disc, id, stk;\n\tstd::vector<std::vector<int>> comps;\n\
    \n\tvoid init(int n_) {\n\t\tn = n_;\n\t\ttime = 0;\n\t\tnum_comps = 0;\n\t\t\
    adj.assign(n, std::vector<int>());\n\t\tid.assign(n, -1);\n\t\tdisc.assign(n,\
    \ 0);\n\t\tcomps.clear();\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\
    \t}\n\n\tint dfs(int src) {\n\t\tint low = disc[src] = ++time;\n\t\tstk.push_back(src);\n\
    \t\tfor (int nxt : adj[src]) \n\t\t\tif (id[nxt] == -1)\n\t\t\t\tlow = std::min(low,\
    \ disc[nxt] ? : dfs(nxt));\n\t\tif (low == disc[src]) {\n\t\t\tfor (int nxt =\
    \ -1; nxt != src;)\n\t\t\t\tid[nxt = stk.back()] = num_comps, stk.pop_back();\n\
    \t\t\tnum_comps++;\n\t\t}\n\t\treturn low;\n\t}\n\t\n\tvoid build() {\n\t\t//\
    \ builds in topological order\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tif (!disc[i])\n\
    \t\t\t\tdfs(i);\n\t\tfor (auto &x : id) \n\t\t\tx = num_comps - 1 - x;\n\t\tcomps.resize(num_comps);\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tcomps[id[i]].push_back(i);\n\t}\n};\n"
  code: "#pragma once\n\nstruct SCC {\n\tint n, time, num_comps;\n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> disc, id, stk;\n\tstd::vector<std::vector<int>> comps;\n\
    \n\tvoid init(int n_) {\n\t\tn = n_;\n\t\ttime = 0;\n\t\tnum_comps = 0;\n\t\t\
    adj.assign(n, std::vector<int>());\n\t\tid.assign(n, -1);\n\t\tdisc.assign(n,\
    \ 0);\n\t\tcomps.clear();\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\
    \t}\n\n\tint dfs(int src) {\n\t\tint low = disc[src] = ++time;\n\t\tstk.push_back(src);\n\
    \t\tfor (int nxt : adj[src]) \n\t\t\tif (id[nxt] == -1)\n\t\t\t\tlow = std::min(low,\
    \ disc[nxt] ? : dfs(nxt));\n\t\tif (low == disc[src]) {\n\t\t\tfor (int nxt =\
    \ -1; nxt != src;)\n\t\t\t\tid[nxt = stk.back()] = num_comps, stk.pop_back();\n\
    \t\t\tnum_comps++;\n\t\t}\n\t\treturn low;\n\t}\n\t\n\tvoid build() {\n\t\t//\
    \ builds in topological order\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tif (!disc[i])\n\
    \t\t\t\tdfs(i);\n\t\tfor (auto &x : id) \n\t\t\tx = num_comps - 1 - x;\n\t\tcomps.resize(num_comps);\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tcomps[id[i]].push_back(i);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly-connected-components-tarjan.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:29:57-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/strongly-connected-components-tarjan.test.cpp
documentation_of: library/graphs/strongly-connected-components-tarjan.hpp
layout: document
redirect_from:
- /library/library/graphs/strongly-connected-components-tarjan.hpp
- /library/library/graphs/strongly-connected-components-tarjan.hpp.html
title: library/graphs/strongly-connected-components-tarjan.hpp
---

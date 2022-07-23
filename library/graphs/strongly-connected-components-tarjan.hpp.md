---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-scc-tarjan.test.cpp
    title: verify/yosupo/yosupo-scc-tarjan.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct SCC {\r\n\tint n, time, num_comps;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> disc, id, stk;\r\n\tstd::vector<std::vector<int>>\
    \ comps;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\ttime = 0;\r\n\t\t\
    num_comps = 0;\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tid.assign(n, -1);\r\
    \n\t\tdisc.assign(n, 0);\r\n\t\tcomps.clear();\r\n\t}\r\n\r\n\tvoid ae(int u,\
    \ int v) {\r\n\t\tadj[u].push_back(v);\r\n\t}\r\n\r\n\tint dfs(int src) {\r\n\t\
    \tint low = disc[src] = ++time;\r\n\t\tstk.push_back(src);\r\n\t\tfor (int nxt\
    \ : adj[src]) \r\n\t\t\tif (id[nxt] == -1)\r\n\t\t\t\tlow = std::min(low, disc[nxt]\
    \ ? : dfs(nxt));\r\n\t\tif (low == disc[src]) {\r\n\t\t\tfor (int nxt = -1; nxt\
    \ != src;)\r\n\t\t\t\tid[nxt = stk.back()] = num_comps, stk.pop_back();\r\n\t\t\
    \tnum_comps++;\r\n\t\t}\r\n\t\treturn low;\r\n\t}\r\n\t\r\n\tvoid build() {\r\n\
    \t\t// builds in topological order\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\
    \tif (!disc[i])\r\n\t\t\t\tdfs(i);\r\n\t\tfor (auto& x : id) \r\n\t\t\tx = num_comps\
    \ - 1 - x;\r\n\t\tcomps.resize(num_comps);\r\n\t\tfor (int i = 0; i < n; i++)\r\
    \n\t\t\tcomps[id[i]].push_back(i);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nstruct SCC {\r\n\tint n, time, num_comps;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> disc, id, stk;\r\n\tstd::vector<std::vector<int>>\
    \ comps;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\ttime = 0;\r\n\t\t\
    num_comps = 0;\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tid.assign(n, -1);\r\
    \n\t\tdisc.assign(n, 0);\r\n\t\tcomps.clear();\r\n\t}\r\n\r\n\tvoid ae(int u,\
    \ int v) {\r\n\t\tadj[u].push_back(v);\r\n\t}\r\n\r\n\tint dfs(int src) {\r\n\t\
    \tint low = disc[src] = ++time;\r\n\t\tstk.push_back(src);\r\n\t\tfor (int nxt\
    \ : adj[src]) \r\n\t\t\tif (id[nxt] == -1)\r\n\t\t\t\tlow = std::min(low, disc[nxt]\
    \ ? : dfs(nxt));\r\n\t\tif (low == disc[src]) {\r\n\t\t\tfor (int nxt = -1; nxt\
    \ != src;)\r\n\t\t\t\tid[nxt = stk.back()] = num_comps, stk.pop_back();\r\n\t\t\
    \tnum_comps++;\r\n\t\t}\r\n\t\treturn low;\r\n\t}\r\n\t\r\n\tvoid build() {\r\n\
    \t\t// builds in topological order\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\
    \tif (!disc[i])\r\n\t\t\t\tdfs(i);\r\n\t\tfor (auto& x : id) \r\n\t\t\tx = num_comps\
    \ - 1 - x;\r\n\t\tcomps.resize(num_comps);\r\n\t\tfor (int i = 0; i < n; i++)\r\
    \n\t\t\tcomps[id[i]].push_back(i);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly-connected-components-tarjan.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-scc-tarjan.test.cpp
documentation_of: library/graphs/strongly-connected-components-tarjan.hpp
layout: document
redirect_from:
- /library/library/graphs/strongly-connected-components-tarjan.hpp
- /library/library/graphs/strongly-connected-components-tarjan.hpp.html
title: library/graphs/strongly-connected-components-tarjan.hpp
---

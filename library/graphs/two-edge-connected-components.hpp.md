---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-two_edge_connected_components.test.cpp
    title: verify/yosupo/yosupo-two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct TwoEdgeCC {\r\n\tint n, time, num_comps; \r\n\tstd::vector<int>\
    \ ord, low, id; \r\n\t// order encountered, earliest time in subtree, component\
    \ id\r\n\tstd::vector<std::vector<int>> adj, comps, tree;\r\n\t// adj, comps storage,\
    \ bridge block tree\r\n\tstd::vector<std::pair<int, int>> bridge;\r\n\t// bridges\r\
    \n\t\r\n\tvoid init(int n_) {\r\n\t\tnum_comps = time = 0;\r\n\t\tn = n_;\r\n\t\
    \tord.assign(n, -1);\r\n\t\tlow.assign(n, 0);\r\n\t\tid.assign(n, -1);\r\n\t\t\
    adj.assign(n, std::vector<int>());\r\n\t\tcomps.clear();\r\n\t\ttree.clear();\r\
    \n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\n\t\tadj[v].push_back(u);\r\
    \n\t}\r\n\r\n\tbool is_bridge(int u, int v) {\r\n\t\tif (ord[u] > ord[v])\r\n\t\
    \t\tstd::swap(u, v);\r\n\t\treturn ord[u] < low[v];\r\n\t}\r\n\r\n\tvoid dfs(int\
    \ src, int par) {\r\n\t\tord[src] = low[src] = time++;\r\n\t\tbool bic = false;\
    \ // accounts for double edges\r\n\t\tfor (int nxt : adj[src]) { \r\n\t\t\tif\
    \ (nxt == par && !bic) {\r\n\t\t\t\tbic = true;\r\n\t\t\t\tcontinue;\r\n\t\t\t\
    }\r\n\t\t\tif (ord[nxt] != -1) {\r\n\t\t\t\tlow[src] = std::min(low[src], ord[nxt]);\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs(nxt, src);\r\n\t\t\tlow[src] = std::min(low[src],\
    \ low[nxt]);\r\n\t\t\tif (is_bridge(src, nxt))\r\n\t\t\t\tbridge.emplace_back(src,\
    \ nxt);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid fill_component(int src) {\r\n\t\tcomps[id[src]].push_back(src);\r\
    \n\t\tfor (int nxt : adj[src]) {\r\n\t\t\tif (id[nxt] != -1 || is_bridge(nxt,\
    \ src))\r\n\t\t\t\tcontinue;\r\n\t\t\tid[nxt] = id[src];\r\n\t\t\tfill_component(nxt);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid add_component(int src) {\r\n\t\tif (id[src] != -1)\r\
    \n\t\t\treturn;\r\n\t\tid[src] = num_comps++;\r\n\t\tcomps.emplace_back();\r\n\
    \t\tfill_component(src);\r\n\t}\r\n\t\r\n\tint build() {\r\n\t\tfor (int i = 0;\
    \ i < n; i++) \r\n\t\t\tif (ord[i] == -1)\r\n\t\t\t\tdfs(i, -1);\r\n\t\tfor (int\
    \ i = 0; i < n; i++) \r\n\t\t\tadd_component(i);\r\n\t\ttree.resize(num_comps);\r\
    \n\t\tfor (auto& b : bridge) {\r\n\t\t\tint u = id[b.first];\r\n\t\t\tint v =\
    \ id[b.second];\r\n\t\t\ttree[u].push_back(v);\r\n\t\t\ttree[v].push_back(u);\
    \            \r\n\t\t}\r\n\t\treturn num_comps;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nstruct TwoEdgeCC {\r\n\tint n, time, num_comps; \r\n\t\
    std::vector<int> ord, low, id; \r\n\t// order encountered, earliest time in subtree,\
    \ component id\r\n\tstd::vector<std::vector<int>> adj, comps, tree;\r\n\t// adj,\
    \ comps storage, bridge block tree\r\n\tstd::vector<std::pair<int, int>> bridge;\r\
    \n\t// bridges\r\n\t\r\n\tvoid init(int n_) {\r\n\t\tnum_comps = time = 0;\r\n\
    \t\tn = n_;\r\n\t\tord.assign(n, -1);\r\n\t\tlow.assign(n, 0);\r\n\t\tid.assign(n,\
    \ -1);\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tcomps.clear();\r\n\t\t\
    tree.clear();\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\
    \n\t\tadj[v].push_back(u);\r\n\t}\r\n\r\n\tbool is_bridge(int u, int v) {\r\n\t\
    \tif (ord[u] > ord[v])\r\n\t\t\tstd::swap(u, v);\r\n\t\treturn ord[u] < low[v];\r\
    \n\t}\r\n\r\n\tvoid dfs(int src, int par) {\r\n\t\tord[src] = low[src] = time++;\r\
    \n\t\tbool bic = false; // accounts for double edges\r\n\t\tfor (int nxt : adj[src])\
    \ { \r\n\t\t\tif (nxt == par && !bic) {\r\n\t\t\t\tbic = true;\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tif (ord[nxt] != -1) {\r\n\t\t\t\tlow[src] = std::min(low[src],\
    \ ord[nxt]);\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs(nxt, src);\r\n\t\t\t\
    low[src] = std::min(low[src], low[nxt]);\r\n\t\t\tif (is_bridge(src, nxt))\r\n\
    \t\t\t\tbridge.emplace_back(src, nxt);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid fill_component(int\
    \ src) {\r\n\t\tcomps[id[src]].push_back(src);\r\n\t\tfor (int nxt : adj[src])\
    \ {\r\n\t\t\tif (id[nxt] != -1 || is_bridge(nxt, src))\r\n\t\t\t\tcontinue;\r\n\
    \t\t\tid[nxt] = id[src];\r\n\t\t\tfill_component(nxt);\r\n\t\t}\r\n\t}\r\n\r\n\
    \tvoid add_component(int src) {\r\n\t\tif (id[src] != -1)\r\n\t\t\treturn;\r\n\
    \t\tid[src] = num_comps++;\r\n\t\tcomps.emplace_back();\r\n\t\tfill_component(src);\r\
    \n\t}\r\n\t\r\n\tint build() {\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tif\
    \ (ord[i] == -1)\r\n\t\t\t\tdfs(i, -1);\r\n\t\tfor (int i = 0; i < n; i++) \r\n\
    \t\t\tadd_component(i);\r\n\t\ttree.resize(num_comps);\r\n\t\tfor (auto& b : bridge)\
    \ {\r\n\t\t\tint u = id[b.first];\r\n\t\t\tint v = id[b.second];\r\n\t\t\ttree[u].push_back(v);\r\
    \n\t\t\ttree[v].push_back(u);            \r\n\t\t}\r\n\t\treturn num_comps;\r\n\
    \t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/two-edge-connected-components.hpp
  requiredBy: []
  timestamp: '2022-07-23 17:38:00-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-two_edge_connected_components.test.cpp
documentation_of: library/graphs/two-edge-connected-components.hpp
layout: document
redirect_from:
- /library/library/graphs/two-edge-connected-components.hpp
- /library/library/graphs/two-edge-connected-components.hpp.html
title: library/graphs/two-edge-connected-components.hpp
---

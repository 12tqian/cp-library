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
  bundledCode: "\nstruct BCC {\n\tint n, time, num_comps; \n\tstd::vector<int> ord,\
    \ low, id; \n\t// order encountered, earliest time in subtree, component id\n\t\
    std::vector<std::vector<int>> adj, comps, tree;\n\t// adj, comps storage, bridge\
    \ block tree\n\tstd::vector<std::pair<int, int>> bridge;\n\t// bridges\n\t\n\t\
    void init(int n_) {\n\t\tnum_comps = time = 0;\n\t\tn = n_;\n\t\tord.assign(n,\
    \ -1);\n\t\tlow.assign(n, 0);\n\t\tid.assign(n, -1);\n\t\tadj.assign(n, std::vector<int>());\n\
    \t\tcomps.clear();\n\t\ttree.clear();\n\t}\n\n\tvoid ae(int u, int v) {\n\t\t\
    adj[u].push_back(v);\n\t\tadj[v].push_back(u);\n\t}\n\n\tbool is_bridge(int u,\
    \ int v) {\n\t\tif (ord[u] > ord[v])\n\t\t\tstd::swap(u, v);\n\t\treturn ord[u]\
    \ < low[v];\n\t}\n\n\tvoid dfs(int src, int par) {\n\t\tord[src] = low[src] =\
    \ time++;\n\t\tbool bic = false; // accounts for double edges\n\t\tfor (int nxt\
    \ : adj[src]) { \n\t\t\tif (nxt == par && !bic) {\n\t\t\t\tbic = true;\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tif (ord[nxt] != -1) {\n\t\t\t\tlow[src] = std::min(low[src],\
    \ ord[nxt]);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tdfs(nxt, src);\n\t\t\tlow[src]\
    \ = std::min(low[src], low[nxt]);\n\t\t\tif (is_bridge(src, nxt))\n\t\t\t\tbridge.emplace_back(src,\
    \ nxt);\n\t\t}\n\t}\n\n\tvoid fill_component(int src) {\n\t\tcomps[id[src]].push_back(src);\n\
    \t\tfor (int nxt : adj[src]) {\n\t\t\tif (id[nxt] != -1 || is_bridge(nxt, src))\n\
    \t\t\t\tcontinue;\n\t\t\tid[nxt] = id[src];\n\t\t\tfill_component(nxt);\n\t\t\
    }\n\t}\n\n\tvoid add_component(int src) {\n\t\tif (id[src] != -1)\n\t\t\treturn;\n\
    \t\tid[src] = num_comps++;\n\t\tcomps.emplace_back();\n\t\tfill_component(src);\n\
    \t}\n\t\n\tint build() {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tif (ord[i] ==\
    \ -1)\n\t\t\t\tdfs(i, -1);\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tadd_component(i);\n\
    \t\ttree.resize(num_comps);\n\t\tfor (auto &b : bridge) {\n\t\t\tint u = id[b.first];\n\
    \t\t\tint v = id[b.second];\n\t\t\ttree[u].push_back(v);\n\t\t\ttree[v].push_back(u);\
    \            \n\t\t}\n\t\treturn num_comps;\n\t}\n};\n"
  code: "#pragma once\n\nstruct BCC {\n\tint n, time, num_comps; \n\tstd::vector<int>\
    \ ord, low, id; \n\t// order encountered, earliest time in subtree, component\
    \ id\n\tstd::vector<std::vector<int>> adj, comps, tree;\n\t// adj, comps storage,\
    \ bridge block tree\n\tstd::vector<std::pair<int, int>> bridge;\n\t// bridges\n\
    \t\n\tvoid init(int n_) {\n\t\tnum_comps = time = 0;\n\t\tn = n_;\n\t\tord.assign(n,\
    \ -1);\n\t\tlow.assign(n, 0);\n\t\tid.assign(n, -1);\n\t\tadj.assign(n, std::vector<int>());\n\
    \t\tcomps.clear();\n\t\ttree.clear();\n\t}\n\n\tvoid ae(int u, int v) {\n\t\t\
    adj[u].push_back(v);\n\t\tadj[v].push_back(u);\n\t}\n\n\tbool is_bridge(int u,\
    \ int v) {\n\t\tif (ord[u] > ord[v])\n\t\t\tstd::swap(u, v);\n\t\treturn ord[u]\
    \ < low[v];\n\t}\n\n\tvoid dfs(int src, int par) {\n\t\tord[src] = low[src] =\
    \ time++;\n\t\tbool bic = false; // accounts for double edges\n\t\tfor (int nxt\
    \ : adj[src]) { \n\t\t\tif (nxt == par && !bic) {\n\t\t\t\tbic = true;\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tif (ord[nxt] != -1) {\n\t\t\t\tlow[src] = std::min(low[src],\
    \ ord[nxt]);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tdfs(nxt, src);\n\t\t\tlow[src]\
    \ = std::min(low[src], low[nxt]);\n\t\t\tif (is_bridge(src, nxt))\n\t\t\t\tbridge.emplace_back(src,\
    \ nxt);\n\t\t}\n\t}\n\n\tvoid fill_component(int src) {\n\t\tcomps[id[src]].push_back(src);\n\
    \t\tfor (int nxt : adj[src]) {\n\t\t\tif (id[nxt] != -1 || is_bridge(nxt, src))\n\
    \t\t\t\tcontinue;\n\t\t\tid[nxt] = id[src];\n\t\t\tfill_component(nxt);\n\t\t\
    }\n\t}\n\n\tvoid add_component(int src) {\n\t\tif (id[src] != -1)\n\t\t\treturn;\n\
    \t\tid[src] = num_comps++;\n\t\tcomps.emplace_back();\n\t\tfill_component(src);\n\
    \t}\n\t\n\tint build() {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tif (ord[i] ==\
    \ -1)\n\t\t\t\tdfs(i, -1);\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tadd_component(i);\n\
    \t\ttree.resize(num_comps);\n\t\tfor (auto &b : bridge) {\n\t\t\tint u = id[b.first];\n\
    \t\t\tint v = id[b.second];\n\t\t\ttree[u].push_back(v);\n\t\t\ttree[v].push_back(u);\
    \            \n\t\t}\n\t\treturn num_comps;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/biconnected-components.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:57:36-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-two_edge_connected_components.test.cpp
documentation_of: library/graphs/biconnected-components.hpp
layout: document
redirect_from:
- /library/library/graphs/biconnected-components.hpp
- /library/library/graphs/biconnected-components.hpp.html
title: library/graphs/biconnected-components.hpp
---

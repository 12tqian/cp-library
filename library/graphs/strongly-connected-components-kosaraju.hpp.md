---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-scc-kosaraju.test.cpp
    title: verify/yosupo/yosupo-scc-kosaraju.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\nstruct SCC {\r\n\tint n; \r\n\tstd::vector<std::vector<int>> g,\
    \ rg, scc_graph, comps;\r\n\tstd::vector<int> id, ord, roots, topo_ord;\r\n\t\
    std::vector<bool> vis;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tg.assign(n,\
    \ std::vector<int>());\r\n\t\trg.assign(n, std::vector<int>());\r\n\t\tscc_graph.assign(n,\
    \ std::vector<int>());\r\n\t\tcomps.assign(n, std::vector<int>());\r\n\t\tvis.assign(n,\
    \ false);\r\n\t\tid.assign(n, -1);\r\n\t\tord.clear();\r\n\t\troots.clear(); \
    \    \r\n\t\ttopo_ord.clear();  \r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\
    \tg[u].push_back(v);\r\n\t\trg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid dfs_order(int\
    \ u) {\r\n\t\tvis[u] = true;\r\n\t\tfor (auto& v : g[u]) {\r\n\t\t\tif (vis[v])\
    \ \r\n\t\t\t\tcontinue;\r\n\t\t\tdfs_order(v);\r\n\t\t}\r\n\t\tord.push_back(u);\r\
    \n\t}\r\n\r\n\tvoid dfs_color(int u, int c) {\r\n\t\tid[u] = c;\r\n\t\tfor (int&\
    \ v : rg[u]) \r\n\t\t\tif (id[v] == -1) \r\n\t\t\t\tdfs_color(v, c);\r\n\t}\r\n\
    \r\n\tvoid topological_sort() {\r\n\t\tstd::vector<int> in(n);\r\n\t\tstd::list<int>\
    \ todo;\r\n\t\tfor (int i = 0; i < n; ++i) \r\n\t\t\tfor (auto& j : scc_graph[i])\r\
    \n\t\t\t\t++in[j];\r\n\t\tfor (int i = 0; i < n; ++i)\r\n\t\t\tif (!in[i] && id[i]\
    \ == i)\r\n\t\t\t\ttodo.push_back(i);\r\n\t\twhile (!todo.empty()) {\r\n\t\t\t\
    int u = todo.front();\r\n\t\t\ttodo.pop_front();\r\n\t\t\ttopo_ord.push_back(u);\r\
    \n\t\t\tfor (auto& v : scc_graph[u]) \r\n\t\t\t\tif (!(--in[v])) \r\n\t\t\t\t\t\
    todo.push_back(v);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build_scc_graph() {\r\n\t\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\t\tcomps[id[i]].push_back(i);\r\n\t\t\tfor (auto&\
    \ j : g[i]) {\r\n\t\t\t\tif (id[i] == id[j]) \r\n\t\t\t\t\tcontinue;\r\n\t\t\t\
    \tscc_graph[id[i]].push_back(id[j]);\r\n\t\t\t}\r\n\t\t}\r\n\t\ttopological_sort();\r\
    \n\t}\r\n\r\n\tvoid gen() {\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tif (!vis[i])\r\
    \n\t\t\t\tdfs_order(i);\r\n\t\t}\r\n\t\treverse(ord.begin(), ord.end());\r\n\t\
    \tfor (auto& x : ord) \r\n\t\t\tif (id[x] == -1) \r\n\t\t\t\tdfs_color(x, x),\
    \ roots.push_back(x);\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct SCC {\r\n\tint n; \r\n\tstd::vector<std::vector<int>>\
    \ g, rg, scc_graph, comps;\r\n\tstd::vector<int> id, ord, roots, topo_ord;\r\n\
    \tstd::vector<bool> vis;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tg.assign(n,\
    \ std::vector<int>());\r\n\t\trg.assign(n, std::vector<int>());\r\n\t\tscc_graph.assign(n,\
    \ std::vector<int>());\r\n\t\tcomps.assign(n, std::vector<int>());\r\n\t\tvis.assign(n,\
    \ false);\r\n\t\tid.assign(n, -1);\r\n\t\tord.clear();\r\n\t\troots.clear(); \
    \    \r\n\t\ttopo_ord.clear();  \r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\
    \tg[u].push_back(v);\r\n\t\trg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid dfs_order(int\
    \ u) {\r\n\t\tvis[u] = true;\r\n\t\tfor (auto& v : g[u]) {\r\n\t\t\tif (vis[v])\
    \ \r\n\t\t\t\tcontinue;\r\n\t\t\tdfs_order(v);\r\n\t\t}\r\n\t\tord.push_back(u);\r\
    \n\t}\r\n\r\n\tvoid dfs_color(int u, int c) {\r\n\t\tid[u] = c;\r\n\t\tfor (int&\
    \ v : rg[u]) \r\n\t\t\tif (id[v] == -1) \r\n\t\t\t\tdfs_color(v, c);\r\n\t}\r\n\
    \r\n\tvoid topological_sort() {\r\n\t\tstd::vector<int> in(n);\r\n\t\tstd::list<int>\
    \ todo;\r\n\t\tfor (int i = 0; i < n; ++i) \r\n\t\t\tfor (auto& j : scc_graph[i])\r\
    \n\t\t\t\t++in[j];\r\n\t\tfor (int i = 0; i < n; ++i)\r\n\t\t\tif (!in[i] && id[i]\
    \ == i)\r\n\t\t\t\ttodo.push_back(i);\r\n\t\twhile (!todo.empty()) {\r\n\t\t\t\
    int u = todo.front();\r\n\t\t\ttodo.pop_front();\r\n\t\t\ttopo_ord.push_back(u);\r\
    \n\t\t\tfor (auto& v : scc_graph[u]) \r\n\t\t\t\tif (!(--in[v])) \r\n\t\t\t\t\t\
    todo.push_back(v);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build_scc_graph() {\r\n\t\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\t\tcomps[id[i]].push_back(i);\r\n\t\t\tfor (auto&\
    \ j : g[i]) {\r\n\t\t\t\tif (id[i] == id[j]) \r\n\t\t\t\t\tcontinue;\r\n\t\t\t\
    \tscc_graph[id[i]].push_back(id[j]);\r\n\t\t\t}\r\n\t\t}\r\n\t\ttopological_sort();\r\
    \n\t}\r\n\r\n\tvoid gen() {\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tif (!vis[i])\r\
    \n\t\t\t\tdfs_order(i);\r\n\t\t}\r\n\t\treverse(ord.begin(), ord.end());\r\n\t\
    \tfor (auto& x : ord) \r\n\t\t\tif (id[x] == -1) \r\n\t\t\t\tdfs_color(x, x),\
    \ roots.push_back(x);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly-connected-components-kosaraju.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-scc-kosaraju.test.cpp
documentation_of: library/graphs/strongly-connected-components-kosaraju.hpp
layout: document
redirect_from:
- /library/library/graphs/strongly-connected-components-kosaraju.hpp
- /library/library/graphs/strongly-connected-components-kosaraju.hpp.html
title: library/graphs/strongly-connected-components-kosaraju.hpp
---

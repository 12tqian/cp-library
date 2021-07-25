---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/strongly-connected-components-kosaraju.test.cpp
    title: test/strongly-connected-components-kosaraju.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\nstruct SCC {\n\tint n; \n\tstd::vector<std::vector<int>> g, rg,\
    \ scc_graph, comps;\n\tstd::vector<int> id, ord, roots, topo_ord;\n\tstd::vector<bool>\
    \ vis;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tg.assign(n, std::vector<int>());\n\
    \t\trg.assign(n, std::vector<int>());\n\t\tscc_graph.assign(n, std::vector<int>());\n\
    \t\tcomps.assign(n, std::vector<int>());\n\t\tvis.assign(n, false);\n\t\tid.assign(n,\
    \ -1);\n\t\tord.clear();\n\t\troots.clear();     \n\t\ttopo_ord.clear();  \n\t\
    }\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t\trg[v].push_back(u);\n\
    \t}\n\n\tvoid dfs_order(int u) {\n\t\tvis[u] = true;\n\t\tfor (auto &v : g[u])\
    \ {\n\t\t\tif (vis[v]) \n\t\t\t\tcontinue;\n\t\t\tdfs_order(v);\n\t\t}\n\t\tord.push_back(u);\n\
    \t}\n\n\tvoid dfs_color(int u, int c) {\n\t\tid[u] = c;\n\t\tfor (int &v : rg[u])\
    \ \n\t\t\tif (id[v] == -1) \n\t\t\t\tdfs_color(v, c);\n\t}\n\n\tvoid topological_sort()\
    \ {\n\t\tstd::vector<int> in(n);\n\t\tstd::list<int> todo;\n\t\tfor (int i = 0;\
    \ i < n; ++i) \n\t\t\tfor (auto &j : scc_graph[i])\n\t\t\t\t++in[j];\n\t\tfor\
    \ (int i = 0; i < n; ++i)\n\t\t\tif (!in[i] && id[i] == i)\n\t\t\t\ttodo.push_back(i);\n\
    \t\twhile (!todo.empty()) {\n\t\t\tint u = todo.front();\n\t\t\ttodo.pop_front();\n\
    \t\t\ttopo_ord.push_back(u);\n\t\t\tfor (auto &v : scc_graph[u]) \n\t\t\t\tif\
    \ (!(--in[v])) \n\t\t\t\t\ttodo.push_back(v);\n\t\t}\n\t}\n\n\tvoid build_scc_graph()\
    \ {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tcomps[id[i]].push_back(i);\n\t\t\
    \tfor (auto &j : g[i]) {\n\t\t\t\tif (id[i] == id[j]) \n\t\t\t\t\tcontinue;\n\t\
    \t\t\tscc_graph[id[i]].push_back(id[j]);\n\t\t\t}\n\t\t}\n\t\ttopological_sort();\n\
    \t}\n\n\tvoid gen() {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (!vis[i])\n\
    \t\t\t\tdfs_order(i);\n\t\t}\n\t\treverse(ord.begin(), ord.end());\n\t\tfor (auto\
    \ &x : ord) \n\t\t\tif (id[x] == -1) \n\t\t\t\tdfs_color(x, x), roots.push_back(x);\n\
    \t}\n};\n"
  code: "#pragma once\n\nstruct SCC {\n\tint n; \n\tstd::vector<std::vector<int>>\
    \ g, rg, scc_graph, comps;\n\tstd::vector<int> id, ord, roots, topo_ord;\n\tstd::vector<bool>\
    \ vis;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tg.assign(n, std::vector<int>());\n\
    \t\trg.assign(n, std::vector<int>());\n\t\tscc_graph.assign(n, std::vector<int>());\n\
    \t\tcomps.assign(n, std::vector<int>());\n\t\tvis.assign(n, false);\n\t\tid.assign(n,\
    \ -1);\n\t\tord.clear();\n\t\troots.clear();     \n\t\ttopo_ord.clear();  \n\t\
    }\n\n\tvoid ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t\trg[v].push_back(u);\n\
    \t}\n\n\tvoid dfs_order(int u) {\n\t\tvis[u] = true;\n\t\tfor (auto &v : g[u])\
    \ {\n\t\t\tif (vis[v]) \n\t\t\t\tcontinue;\n\t\t\tdfs_order(v);\n\t\t}\n\t\tord.push_back(u);\n\
    \t}\n\n\tvoid dfs_color(int u, int c) {\n\t\tid[u] = c;\n\t\tfor (int &v : rg[u])\
    \ \n\t\t\tif (id[v] == -1) \n\t\t\t\tdfs_color(v, c);\n\t}\n\n\tvoid topological_sort()\
    \ {\n\t\tstd::vector<int> in(n);\n\t\tstd::list<int> todo;\n\t\tfor (int i = 0;\
    \ i < n; ++i) \n\t\t\tfor (auto &j : scc_graph[i])\n\t\t\t\t++in[j];\n\t\tfor\
    \ (int i = 0; i < n; ++i)\n\t\t\tif (!in[i] && id[i] == i)\n\t\t\t\ttodo.push_back(i);\n\
    \t\twhile (!todo.empty()) {\n\t\t\tint u = todo.front();\n\t\t\ttodo.pop_front();\n\
    \t\t\ttopo_ord.push_back(u);\n\t\t\tfor (auto &v : scc_graph[u]) \n\t\t\t\tif\
    \ (!(--in[v])) \n\t\t\t\t\ttodo.push_back(v);\n\t\t}\n\t}\n\n\tvoid build_scc_graph()\
    \ {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tcomps[id[i]].push_back(i);\n\t\t\
    \tfor (auto &j : g[i]) {\n\t\t\t\tif (id[i] == id[j]) \n\t\t\t\t\tcontinue;\n\t\
    \t\t\tscc_graph[id[i]].push_back(id[j]);\n\t\t\t}\n\t\t}\n\t\ttopological_sort();\n\
    \t}\n\n\tvoid gen() {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (!vis[i])\n\
    \t\t\t\tdfs_order(i);\n\t\t}\n\t\treverse(ord.begin(), ord.end());\n\t\tfor (auto\
    \ &x : ord) \n\t\t\tif (id[x] == -1) \n\t\t\t\tdfs_color(x, x), roots.push_back(x);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly-connected-components-kosaraju.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:29:57-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/strongly-connected-components-kosaraju.test.cpp
documentation_of: library/graphs/strongly-connected-components-kosaraju.hpp
layout: document
redirect_from:
- /library/library/graphs/strongly-connected-components-kosaraju.hpp
- /library/library/graphs/strongly-connected-components-kosaraju.hpp.html
title: library/graphs/strongly-connected-components-kosaraju.hpp
---

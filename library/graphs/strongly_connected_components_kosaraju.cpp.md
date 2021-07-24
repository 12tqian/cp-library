---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/strongly_connected_components_kosaraju.cpp\"\
    \n#include <bits/stdc++.h>\n\nstruct SCC {\n\tint n; \n\tstd::vector<std::vector<int>>\
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
    \t}\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, m; \n\tcin >> n >> m;\n\tSCC S; S.init(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tS.ae(u, v);\n\t}\n\tS.gen();\n\
    \tS.build_scc_graph();\n\tcout << S.roots.size() << '\\n';\n\tfor (auto &c : S.topo_ord)\
    \ {\n\t\tcout << S.comps[c].size() << \" \";\n\t\tfor (auto &x : S.comps[c]) \n\
    \t\t\tcout << x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct SCC {\n\tint n; \n\tstd::vector<std::vector<int>>\
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
    \t}\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, m; \n\tcin >> n >> m;\n\tSCC S; S.init(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tS.ae(u, v);\n\t}\n\tS.gen();\n\
    \tS.build_scc_graph();\n\tcout << S.roots.size() << '\\n';\n\tfor (auto &c : S.topo_ord)\
    \ {\n\t\tcout << S.comps[c].size() << \" \";\n\t\tfor (auto &x : S.comps[c]) \n\
    \t\t\tcout << x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly_connected_components_kosaraju.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/strongly_connected_components_kosaraju.cpp
layout: document
redirect_from:
- /library/library/graphs/strongly_connected_components_kosaraju.cpp
- /library/library/graphs/strongly_connected_components_kosaraju.cpp.html
title: library/graphs/strongly_connected_components_kosaraju.cpp
---

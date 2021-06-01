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
    \n#include <bits/stdc++.h>\n\nstruct SCC {\n    int n; \n    std::vector<std::vector<int>>\
    \ g, rg, scc_graph, comps;\n    std::vector<int> id, ord, roots, topo_ord;\n \
    \   std::vector<bool> vis;\n\n    void init(int n_) {\n        n = n_;\n     \
    \   g.assign(n, std::vector<int>());\n        rg.assign(n, std::vector<int>());\n\
    \        scc_graph.assign(n, std::vector<int>());\n        comps.assign(n, std::vector<int>());\n\
    \        vis.assign(n, false);\n        id.assign(n, -1);\n        ord.clear();\n\
    \        roots.clear();     \n        topo_ord.clear();  \n    }\n\n    void ae(int\
    \ u, int v) {\n        g[u].push_back(v);\n        rg[v].push_back(u);\n    }\n\
    \n    void dfs_order(int u) {\n        vis[u] = true;\n        for (auto& v :\
    \ g[u]) {\n            if (vis[v]) \n                continue;\n            dfs_order(v);\n\
    \        }\n        ord.push_back(u);\n    }\n\n    void dfs_color(int u, int\
    \ c) {\n        id[u] = c;\n        for (int& v : rg[u]) \n            if (id[v]\
    \ == -1) \n                dfs_color(v, c);\n    }\n\n    void topological_sort()\
    \ {\n        std::vector<int> in(n);\n        std::list<int> todo;\n        for\
    \ (int i = 0; i < n; ++i) \n            for (auto& j : scc_graph[i])\n       \
    \         ++in[j];\n        for (int i = 0; i < n; ++i)\n            if (!in[i]\
    \ && id[i] == i)\n                todo.push_back(i);\n        while (!todo.empty())\
    \ {\n            int u = todo.front();\n            todo.pop_front();\n      \
    \      topo_ord.push_back(u);\n            for (auto& v : scc_graph[u]) \n   \
    \             if (!(--in[v])) \n                    todo.push_back(v);\n     \
    \   }\n    }\n\n    void build_scc_graph() {\n        for (int i = 0; i < n; ++i)\
    \ {\n            comps[id[i]].push_back(i);\n            for (auto& j : g[i])\
    \ {\n                if (id[i] == id[j]) \n                    continue;\n   \
    \             scc_graph[id[i]].push_back(id[j]);\n            }\n        }\n \
    \       topological_sort();\n    }\n\n    void gen() {\n        for (int i = 0;\
    \ i < n; ++i) {\n            if (!vis[i])\n                dfs_order(i);\n   \
    \     }\n        reverse(ord.begin(), ord.end());\n        for (auto& x : ord)\
    \ \n            if (id[x] == -1) \n                dfs_color(x, x), roots.push_back(x);\n\
    \    }\n};\n\nint main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, m; \n    cin >> n >> m;\n    SCC S; S.init(n);\n    for (int i = 0;\
    \ i < m; ++i) {\n        int u, v;\n        cin >> u >> v;\n        S.ae(u, v);\n\
    \    }\n    S.gen();\n    S.build_scc_graph();\n    cout << S.roots.size() <<\
    \ '\\n';\n    for (auto& c : S.topo_ord) {\n        cout << S.comps[c].size()\
    \ << \" \";\n        for (auto& x : S.comps[c]) \n            cout << x << \"\
    \ \";\n        cout << '\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct SCC {\n    int n; \n    std::vector<std::vector<int>>\
    \ g, rg, scc_graph, comps;\n    std::vector<int> id, ord, roots, topo_ord;\n \
    \   std::vector<bool> vis;\n\n    void init(int n_) {\n        n = n_;\n     \
    \   g.assign(n, std::vector<int>());\n        rg.assign(n, std::vector<int>());\n\
    \        scc_graph.assign(n, std::vector<int>());\n        comps.assign(n, std::vector<int>());\n\
    \        vis.assign(n, false);\n        id.assign(n, -1);\n        ord.clear();\n\
    \        roots.clear();     \n        topo_ord.clear();  \n    }\n\n    void ae(int\
    \ u, int v) {\n        g[u].push_back(v);\n        rg[v].push_back(u);\n    }\n\
    \n    void dfs_order(int u) {\n        vis[u] = true;\n        for (auto& v :\
    \ g[u]) {\n            if (vis[v]) \n                continue;\n            dfs_order(v);\n\
    \        }\n        ord.push_back(u);\n    }\n\n    void dfs_color(int u, int\
    \ c) {\n        id[u] = c;\n        for (int& v : rg[u]) \n            if (id[v]\
    \ == -1) \n                dfs_color(v, c);\n    }\n\n    void topological_sort()\
    \ {\n        std::vector<int> in(n);\n        std::list<int> todo;\n        for\
    \ (int i = 0; i < n; ++i) \n            for (auto& j : scc_graph[i])\n       \
    \         ++in[j];\n        for (int i = 0; i < n; ++i)\n            if (!in[i]\
    \ && id[i] == i)\n                todo.push_back(i);\n        while (!todo.empty())\
    \ {\n            int u = todo.front();\n            todo.pop_front();\n      \
    \      topo_ord.push_back(u);\n            for (auto& v : scc_graph[u]) \n   \
    \             if (!(--in[v])) \n                    todo.push_back(v);\n     \
    \   }\n    }\n\n    void build_scc_graph() {\n        for (int i = 0; i < n; ++i)\
    \ {\n            comps[id[i]].push_back(i);\n            for (auto& j : g[i])\
    \ {\n                if (id[i] == id[j]) \n                    continue;\n   \
    \             scc_graph[id[i]].push_back(id[j]);\n            }\n        }\n \
    \       topological_sort();\n    }\n\n    void gen() {\n        for (int i = 0;\
    \ i < n; ++i) {\n            if (!vis[i])\n                dfs_order(i);\n   \
    \     }\n        reverse(ord.begin(), ord.end());\n        for (auto& x : ord)\
    \ \n            if (id[x] == -1) \n                dfs_color(x, x), roots.push_back(x);\n\
    \    }\n};\n\nint main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, m; \n    cin >> n >> m;\n    SCC S; S.init(n);\n    for (int i = 0;\
    \ i < m; ++i) {\n        int u, v;\n        cin >> u >> v;\n        S.ae(u, v);\n\
    \    }\n    S.gen();\n    S.build_scc_graph();\n    cout << S.roots.size() <<\
    \ '\\n';\n    for (auto& c : S.topo_ord) {\n        cout << S.comps[c].size()\
    \ << \" \";\n        for (auto& x : S.comps[c]) \n            cout << x << \"\
    \ \";\n        cout << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly_connected_components_kosaraju.cpp
  requiredBy: []
  timestamp: '2021-06-01 11:33:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/strongly_connected_components_kosaraju.cpp
layout: document
redirect_from:
- /library/library/graphs/strongly_connected_components_kosaraju.cpp
- /library/library/graphs/strongly_connected_components_kosaraju.cpp.html
title: library/graphs/strongly_connected_components_kosaraju.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/biconnected_components.cpp\"\n#include <bits/stdc++.h>\n\
    \nstruct BCC {\n    int n, time, num_comps; \n    std::vector<int> ord, low, id;\
    \ \n    // order encountered, earliest time in subtree, component id\n    std::vector<std::vector<int>>\
    \ adj, comps, tree;\n    // adj, comps storage, bridge block tree\n    std::vector<std::pair<int,\
    \ int>> bridge;\n    // bridges\n    \n    void init(int n_) {\n        num_comps\
    \ = time = 0;\n        n = n_;\n        ord.assign(n, -1);\n        low.assign(n,\
    \ 0);\n        id.assign(n, -1);\n        adj.assign(n, std::vector<int>());\n\
    \        comps.clear();\n        tree.clear();\n    }\n\n    void ae(int u, int\
    \ v) {\n        adj[u].push_back(v);\n        adj[v].push_back(u);\n    }\n\n\
    \    bool is_bridge(int u, int v) {\n        if (ord[u] > ord[v])\n          \
    \  std::swap(u, v);\n        return ord[u] < low[v];\n    }\n\n    void dfs(int\
    \ src, int par) {\n        ord[src] = low[src] = time++;\n        bool bic = false;\
    \ // accounts for double edges\n        for (int nxt : adj[src]) { \n        \
    \    if (nxt == par && !bic) {\n                bic = true;\n                continue;\n\
    \            }\n            if (ord[nxt] != -1) {\n                low[src] =\
    \ std::min(low[src], ord[nxt]);\n                continue;\n            }\n  \
    \          dfs(nxt, src);\n            low[src] = std::min(low[src], low[nxt]);\n\
    \            if (is_bridge(src, nxt))\n                bridge.emplace_back(src,\
    \ nxt);\n        }\n    }\n\n    void fill_component(int src) {\n        comps[id[src]].push_back(src);\n\
    \        for (int nxt : adj[src]) {\n            if (id[nxt] != -1 || is_bridge(nxt,\
    \ src))\n                continue;\n            id[nxt] = id[src];\n         \
    \   fill_component(nxt);\n        }\n    }\n\n    void add_component(int src)\
    \ {\n        if (id[src] != -1)\n            return;\n        id[src] = num_comps++;\n\
    \        comps.emplace_back();\n        fill_component(src);\n    }\n    \n  \
    \  int build() {\n        for (int i = 0; i < n; i++) \n            if (ord[i]\
    \ == -1)\n                dfs(i, -1);\n        for (int i = 0; i < n; i++) \n\
    \            add_component(i);\n        tree.resize(num_comps);\n        for (auto&\
    \ b : bridge) {\n            int u = id[b.first];\n            int v = id[b.second];\n\
    \            tree[u].push_back(v);\n            tree[v].push_back(u);        \
    \    \n        }\n        return num_comps;\n    }\n};\n\nint main() {\n    using\
    \ namespace std;\n    ios_base::sync_with_stdio(0);\n    int n, m; \n    cin >>\
    \ n >> m;\n    BCC B; B.init(n);\n    for (int i = 0; i < m ;i++) {\n        int\
    \ u, v; cin >> u >> v;\n        B.ae(u, v);\n    }\n    B.build();\n    cout <<\
    \ B.num_comps << '\\n';\n    for (int i = 0; i < B.num_comps; i++) {\n       \
    \ cout << (int) B.comps[i].size() << \" \";\n        for (int v : B.comps[i])\
    \ \n            cout << v << \" \";\n        cout << '\\n';\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct BCC {\n    int n, time, num_comps; \n\
    \    std::vector<int> ord, low, id; \n    // order encountered, earliest time\
    \ in subtree, component id\n    std::vector<std::vector<int>> adj, comps, tree;\n\
    \    // adj, comps storage, bridge block tree\n    std::vector<std::pair<int,\
    \ int>> bridge;\n    // bridges\n    \n    void init(int n_) {\n        num_comps\
    \ = time = 0;\n        n = n_;\n        ord.assign(n, -1);\n        low.assign(n,\
    \ 0);\n        id.assign(n, -1);\n        adj.assign(n, std::vector<int>());\n\
    \        comps.clear();\n        tree.clear();\n    }\n\n    void ae(int u, int\
    \ v) {\n        adj[u].push_back(v);\n        adj[v].push_back(u);\n    }\n\n\
    \    bool is_bridge(int u, int v) {\n        if (ord[u] > ord[v])\n          \
    \  std::swap(u, v);\n        return ord[u] < low[v];\n    }\n\n    void dfs(int\
    \ src, int par) {\n        ord[src] = low[src] = time++;\n        bool bic = false;\
    \ // accounts for double edges\n        for (int nxt : adj[src]) { \n        \
    \    if (nxt == par && !bic) {\n                bic = true;\n                continue;\n\
    \            }\n            if (ord[nxt] != -1) {\n                low[src] =\
    \ std::min(low[src], ord[nxt]);\n                continue;\n            }\n  \
    \          dfs(nxt, src);\n            low[src] = std::min(low[src], low[nxt]);\n\
    \            if (is_bridge(src, nxt))\n                bridge.emplace_back(src,\
    \ nxt);\n        }\n    }\n\n    void fill_component(int src) {\n        comps[id[src]].push_back(src);\n\
    \        for (int nxt : adj[src]) {\n            if (id[nxt] != -1 || is_bridge(nxt,\
    \ src))\n                continue;\n            id[nxt] = id[src];\n         \
    \   fill_component(nxt);\n        }\n    }\n\n    void add_component(int src)\
    \ {\n        if (id[src] != -1)\n            return;\n        id[src] = num_comps++;\n\
    \        comps.emplace_back();\n        fill_component(src);\n    }\n    \n  \
    \  int build() {\n        for (int i = 0; i < n; i++) \n            if (ord[i]\
    \ == -1)\n                dfs(i, -1);\n        for (int i = 0; i < n; i++) \n\
    \            add_component(i);\n        tree.resize(num_comps);\n        for (auto&\
    \ b : bridge) {\n            int u = id[b.first];\n            int v = id[b.second];\n\
    \            tree[u].push_back(v);\n            tree[v].push_back(u);        \
    \    \n        }\n        return num_comps;\n    }\n};\n\nint main() {\n    using\
    \ namespace std;\n    ios_base::sync_with_stdio(0);\n    int n, m; \n    cin >>\
    \ n >> m;\n    BCC B; B.init(n);\n    for (int i = 0; i < m ;i++) {\n        int\
    \ u, v; cin >> u >> v;\n        B.ae(u, v);\n    }\n    B.build();\n    cout <<\
    \ B.num_comps << '\\n';\n    for (int i = 0; i < B.num_comps; i++) {\n       \
    \ cout << (int) B.comps[i].size() << \" \";\n        for (int v : B.comps[i])\
    \ \n            cout << v << \" \";\n        cout << '\\n';\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/biconnected_components.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/biconnected_components.cpp
layout: document
redirect_from:
- /library/library/graphs/biconnected_components.cpp
- /library/library/graphs/biconnected_components.cpp.html
title: library/graphs/biconnected_components.cpp
---

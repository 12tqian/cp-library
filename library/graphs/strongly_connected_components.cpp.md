---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/strongly_connected_components.cpp\"\n#include\
    \ <bits/stdc++.h>\n\nstruct SCC {\n    int n, time, num_comps;\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> disc, id, stk;\n    std::vector<std::vector<int>>\
    \ comps;\n    void init(int n_) {\n        n = n_;\n        time = 0;\n      \
    \  num_comps = 0;\n        adj.assign(n, std::vector<int>());\n        id.assign(n,\
    \ -1);\n        disc.assign(n, 0);\n        comps.clear();\n    }\n    void ae(int\
    \ u, int v) {\n        adj[u].push_back(v);\n    }\n    int dfs(int src) {\n \
    \       int low = disc[src] = ++time;\n        stk.push_back(src);\n        for\
    \ (int nxt : adj[src]) \n            if (id[nxt] == -1)\n                low =\
    \ std::min(low, disc[nxt] ? : dfs(nxt));\n        if (low == disc[src]) {\n  \
    \          for (int nxt = -1; nxt != src;)\n                id[nxt = stk.back()]\
    \ = num_comps, stk.pop_back();\n            num_comps++;\n        }\n        return\
    \ low;\n    }\n    void build() {\n        // buils in topological order\n   \
    \     for (int i = 0; i < n; i++) \n            if (!disc[i])\n              \
    \  dfs(i);\n        for (auto& x : id) \n            x = num_comps - 1 - x;\n\
    \        comps.resize(num_comps);\n        for (int i = 0; i < n; i++)\n     \
    \       comps[id[i]].push_back(i);\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    int n, m; cin >> n >> m;\n    SCC S;\n    S.init(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int u, v;\n        cin >> u >> v;\n        S.ae(u,\
    \ v);\n    }\n    S.build();\n    cout << S.num_comps << '\\n';\n    for (auto&\
    \ comp : S.comps) {\n        cout << (int) comp.size() << \" \";\n        for\
    \ (int& x : comp)\n            cout << x << \" \";\n        cout << '\\n';\n \
    \   }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct SCC {\n    int n, time, num_comps;\n \
    \   std::vector<std::vector<int>> adj;\n    std::vector<int> disc, id, stk;\n\
    \    std::vector<std::vector<int>> comps;\n    void init(int n_) {\n        n\
    \ = n_;\n        time = 0;\n        num_comps = 0;\n        adj.assign(n, std::vector<int>());\n\
    \        id.assign(n, -1);\n        disc.assign(n, 0);\n        comps.clear();\n\
    \    }\n    void ae(int u, int v) {\n        adj[u].push_back(v);\n    }\n   \
    \ int dfs(int src) {\n        int low = disc[src] = ++time;\n        stk.push_back(src);\n\
    \        for (int nxt : adj[src]) \n            if (id[nxt] == -1)\n         \
    \       low = std::min(low, disc[nxt] ? : dfs(nxt));\n        if (low == disc[src])\
    \ {\n            for (int nxt = -1; nxt != src;)\n                id[nxt = stk.back()]\
    \ = num_comps, stk.pop_back();\n            num_comps++;\n        }\n        return\
    \ low;\n    }\n    void build() {\n        // buils in topological order\n   \
    \     for (int i = 0; i < n; i++) \n            if (!disc[i])\n              \
    \  dfs(i);\n        for (auto& x : id) \n            x = num_comps - 1 - x;\n\
    \        comps.resize(num_comps);\n        for (int i = 0; i < n; i++)\n     \
    \       comps[id[i]].push_back(i);\n    }\n};\n\nint main() {\n    using namespace\
    \ std;\n    int n, m; cin >> n >> m;\n    SCC S;\n    S.init(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int u, v;\n        cin >> u >> v;\n        S.ae(u,\
    \ v);\n    }\n    S.build();\n    cout << S.num_comps << '\\n';\n    for (auto&\
    \ comp : S.comps) {\n        cout << (int) comp.size() << \" \";\n        for\
    \ (int& x : comp)\n            cout << x << \" \";\n        cout << '\\n';\n \
    \   }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/strongly_connected_components.cpp
  requiredBy: []
  timestamp: '2020-12-04 19:48:55-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/strongly_connected_components.cpp
layout: document
redirect_from:
- /library/library/graphs/strongly_connected_components.cpp
- /library/library/graphs/strongly_connected_components.cpp.html
title: library/graphs/strongly_connected_components.cpp
---

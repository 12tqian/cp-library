---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/flows/dinic.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class F> struct Dinic {\n    struct Edge { int to; F flow, cap; };\n\
    \    int n;\n    std::vector<Edge> edges;\n    std::vector<std::vector<int>> adj;\n\
    \    std::vector<int> level;\n    std::vector<std::vector<int>::iterator> cur;\n\
    \n    void init(int n_) {\n        n = n_;\n        adj.assign(n, std::vector<int>());\n\
    \        cur.assign(n, std::vector<int>::iterator());\n        edges.clear();\n\
    \        level.clear();\n    }\n\n    void ae(int u, int v, F cap, F rcap = 0)\
    \ {\n        assert(std::min(cap, rcap) >= 0);\n        adj[u].push_back((int)edges.size());\n\
    \        edges.push_back({v, 0, cap});\n        adj[v].push_back((int)edges.size());\n\
    \        edges.push_back({u, 0, rcap});\n    }\n\n    bool bfs(int s, int t) {\n\
    \        level = std::vector<int>(n, -1);\n        for (int i = 0; i < n; i++)\n\
    \            cur[i] = adj[i].begin();\n        std::queue<int> q({s});\n     \
    \   level[s] = 0;\n        while (!q.empty()) {\n            int u = q.front();\n\
    \            q.pop();\n            for (auto& eid : adj[u]) {\n              \
    \  const Edge& e = edges[eid];\n                int v = e.to;\n              \
    \  if (level[v] < 0 && e.flow < e.cap) \n                    q.push(v), level[v]\
    \ = level[u] + 1;\n            }\n        }\n        return level[t] >= 0;\n \
    \   }\n\n    F dfs(int v, int t, F flow) {\n        if (v == t)\n            return\
    \ flow;\n        for (; cur[v] != adj[v].end(); cur[v]++) {\n            Edge&\
    \ e = edges[*cur[v]];\n            if (level[e.to] != level[v] + 1 || e.flow ==\
    \ e.cap)\n                continue;\n            F df = dfs(e.to, t, std::min(flow,\
    \ e.cap - e.flow));\n            if (df) {\n                e.flow += df;\n  \
    \              edges[*cur[v] ^ 1].flow -= df;\n                return df;\n  \
    \          }\n        }\n        return 0;\n    }\n    \n    F max_flow(int s,\
    \ int t) {\n        F tot = 0;\n        while (bfs(s, t)) \n            while\
    \ (F df = dfs(s, t, std::numeric_limits<F>::max())) \n                tot += df;\n\
    \        return tot;\n    }\n};\n\nint main() {\n    using namespace std;\n  \
    \  ios_base::sync_with_stdio(0);\n    int L, R; cin >> L >> R;\n    int M; cin\
    \ >> M;\n    Dinic<int> D;\n    D.init(L + R + 2);\n    for (int i = 0; i < M;\
    \ i++) {\n        int u, v; cin >> u >> v;\n        u--, v--;\n        int x =\
    \ u + 1;\n        int y = L + v + 1;\n        D.ae(x, y, 1);\n    }\n    for (int\
    \ i = 1; i <= L; i++) \n        D.ae(0, i, 1);\n    for (int i = L + 1; i <= L\
    \ + R; i++) \n        D.ae(i, L + R + 1, 1);\n    cout << D.max_flow(0, L + R\
    \ + 1) << '\\n';\n    for (int i = 1; i <= L; i++) {\n        for (auto& eid :\
    \ D.adj[i]) {\n            if (eid & 1)\n                continue;\n         \
    \   auto& e = D.edges[eid];\n            if (e.cap == e.flow) {\n            \
    \    int u = i - 1;\n                int v = e.to - L - 1;\n                cout\
    \ << u << \" \" << v << '\\n';\n            }\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class F> struct Dinic {\n    struct\
    \ Edge { int to; F flow, cap; };\n    int n;\n    std::vector<Edge> edges;\n \
    \   std::vector<std::vector<int>> adj;\n    std::vector<int> level;\n    std::vector<std::vector<int>::iterator>\
    \ cur;\n\n    void init(int n_) {\n        n = n_;\n        adj.assign(n, std::vector<int>());\n\
    \        cur.assign(n, std::vector<int>::iterator());\n        edges.clear();\n\
    \        level.clear();\n    }\n\n    void ae(int u, int v, F cap, F rcap = 0)\
    \ {\n        assert(std::min(cap, rcap) >= 0);\n        adj[u].push_back((int)edges.size());\n\
    \        edges.push_back({v, 0, cap});\n        adj[v].push_back((int)edges.size());\n\
    \        edges.push_back({u, 0, rcap});\n    }\n\n    bool bfs(int s, int t) {\n\
    \        level = std::vector<int>(n, -1);\n        for (int i = 0; i < n; i++)\n\
    \            cur[i] = adj[i].begin();\n        std::queue<int> q({s});\n     \
    \   level[s] = 0;\n        while (!q.empty()) {\n            int u = q.front();\n\
    \            q.pop();\n            for (auto& eid : adj[u]) {\n              \
    \  const Edge& e = edges[eid];\n                int v = e.to;\n              \
    \  if (level[v] < 0 && e.flow < e.cap) \n                    q.push(v), level[v]\
    \ = level[u] + 1;\n            }\n        }\n        return level[t] >= 0;\n \
    \   }\n\n    F dfs(int v, int t, F flow) {\n        if (v == t)\n            return\
    \ flow;\n        for (; cur[v] != adj[v].end(); cur[v]++) {\n            Edge&\
    \ e = edges[*cur[v]];\n            if (level[e.to] != level[v] + 1 || e.flow ==\
    \ e.cap)\n                continue;\n            F df = dfs(e.to, t, std::min(flow,\
    \ e.cap - e.flow));\n            if (df) {\n                e.flow += df;\n  \
    \              edges[*cur[v] ^ 1].flow -= df;\n                return df;\n  \
    \          }\n        }\n        return 0;\n    }\n    \n    F max_flow(int s,\
    \ int t) {\n        F tot = 0;\n        while (bfs(s, t)) \n            while\
    \ (F df = dfs(s, t, std::numeric_limits<F>::max())) \n                tot += df;\n\
    \        return tot;\n    }\n};\n\nint main() {\n    using namespace std;\n  \
    \  ios_base::sync_with_stdio(0);\n    int L, R; cin >> L >> R;\n    int M; cin\
    \ >> M;\n    Dinic<int> D;\n    D.init(L + R + 2);\n    for (int i = 0; i < M;\
    \ i++) {\n        int u, v; cin >> u >> v;\n        u--, v--;\n        int x =\
    \ u + 1;\n        int y = L + v + 1;\n        D.ae(x, y, 1);\n    }\n    for (int\
    \ i = 1; i <= L; i++) \n        D.ae(0, i, 1);\n    for (int i = L + 1; i <= L\
    \ + R; i++) \n        D.ae(i, L + R + 1, 1);\n    cout << D.max_flow(0, L + R\
    \ + 1) << '\\n';\n    for (int i = 1; i <= L; i++) {\n        for (auto& eid :\
    \ D.adj[i]) {\n            if (eid & 1)\n                continue;\n         \
    \   auto& e = D.edges[eid];\n            if (e.cap == e.flow) {\n            \
    \    int u = i - 1;\n                int v = e.to - L - 1;\n                cout\
    \ << u << \" \" << v << '\\n';\n            }\n        }\n    }\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/dinic.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/dinic.cpp
layout: document
redirect_from:
- /library/library/graphs/flows/dinic.cpp
- /library/library/graphs/flows/dinic.cpp.html
title: library/graphs/flows/dinic.cpp
---

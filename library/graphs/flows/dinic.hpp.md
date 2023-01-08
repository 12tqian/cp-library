---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_6_A.test.cpp
    title: verify/aizu/aizu-GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-bipartitematching.test.cpp
    title: verify/yosupo/yosupo-bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class F>\r\nstruct Dinic {\r\n  struct Edge {\r\n  \
    \  int to;\r\n    F flow, cap;\r\n  };\r\n\r\n  int n;\r\n  std::vector<Edge>\
    \ edges;\r\n  std::vector<std::vector<int>> adj;\r\n  std::vector<int> level;\r\
    \n  std::vector<std::vector<int>::iterator> cur;\r\n\r\n  void init(int n_) {\r\
    \n    n = n_;\r\n    adj.assign(n, std::vector<int>());\r\n    cur.assign(n, std::vector<int>::iterator());\r\
    \n    edges.clear();\r\n    level.clear();\r\n  }\r\n\r\n  int ae(int u, int v,\
    \ F cap, F rcap = 0) {\r\n    assert(std::min(cap, rcap) >= 0);\r\n    adj[u].push_back((int)edges.size());\r\
    \n    edges.push_back({v, 0, cap});\r\n    adj[v].push_back((int)edges.size());\r\
    \n    edges.push_back({u, 0, rcap});\r\n    return (int)edges.size() - 2;\r\n\
    \  }\r\n\r\n  bool bfs(int s, int t) {\r\n    level = std::vector<int>(n, -1);\r\
    \n    for (int i = 0; i < n; i++) cur[i] = adj[i].begin();\r\n    std::queue<int>\
    \ q({s});\r\n    level[s] = 0;\r\n    while (!q.empty()) {\r\n      int u = q.front();\r\
    \n      q.pop();\r\n      for (auto& eid : adj[u]) {\r\n        const Edge& e\
    \ = edges[eid];\r\n        int v = e.to;\r\n        if (level[v] < 0 && e.flow\
    \ < e.cap) q.push(v), level[v] = level[u] + 1;\r\n      }\r\n    }\r\n    return\
    \ level[t] >= 0;\r\n  }\r\n\r\n  F dfs(int v, int t, F flow) {\r\n    if (v ==\
    \ t) return flow;\r\n    for (; cur[v] != adj[v].end(); cur[v]++) {\r\n      Edge&\
    \ e = edges[*cur[v]];\r\n      if (level[e.to] != level[v] + 1 || e.flow == e.cap)\
    \ continue;\r\n      F df = dfs(e.to, t, std::min(flow, e.cap - e.flow));\r\n\
    \      if (df) {\r\n        e.flow += df;\r\n        edges[*cur[v] ^ 1].flow -=\
    \ df;\r\n        return df;\r\n      }\r\n    }\r\n    return 0;\r\n  }\r\n\r\n\
    \  F max_flow(int s, int t) {\r\n    F tot = 0;\r\n    while (bfs(s, t))\r\n \
    \     while (F df = dfs(s, t, std::numeric_limits<F>::max())) tot += df;\r\n \
    \   return tot;\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class F>\r\nstruct Dinic {\r\n  struct Edge\
    \ {\r\n    int to;\r\n    F flow, cap;\r\n  };\r\n\r\n  int n;\r\n  std::vector<Edge>\
    \ edges;\r\n  std::vector<std::vector<int>> adj;\r\n  std::vector<int> level;\r\
    \n  std::vector<std::vector<int>::iterator> cur;\r\n\r\n  void init(int n_) {\r\
    \n    n = n_;\r\n    adj.assign(n, std::vector<int>());\r\n    cur.assign(n, std::vector<int>::iterator());\r\
    \n    edges.clear();\r\n    level.clear();\r\n  }\r\n\r\n  int ae(int u, int v,\
    \ F cap, F rcap = 0) {\r\n    assert(std::min(cap, rcap) >= 0);\r\n    adj[u].push_back((int)edges.size());\r\
    \n    edges.push_back({v, 0, cap});\r\n    adj[v].push_back((int)edges.size());\r\
    \n    edges.push_back({u, 0, rcap});\r\n    return (int)edges.size() - 2;\r\n\
    \  }\r\n\r\n  bool bfs(int s, int t) {\r\n    level = std::vector<int>(n, -1);\r\
    \n    for (int i = 0; i < n; i++) cur[i] = adj[i].begin();\r\n    std::queue<int>\
    \ q({s});\r\n    level[s] = 0;\r\n    while (!q.empty()) {\r\n      int u = q.front();\r\
    \n      q.pop();\r\n      for (auto& eid : adj[u]) {\r\n        const Edge& e\
    \ = edges[eid];\r\n        int v = e.to;\r\n        if (level[v] < 0 && e.flow\
    \ < e.cap) q.push(v), level[v] = level[u] + 1;\r\n      }\r\n    }\r\n    return\
    \ level[t] >= 0;\r\n  }\r\n\r\n  F dfs(int v, int t, F flow) {\r\n    if (v ==\
    \ t) return flow;\r\n    for (; cur[v] != adj[v].end(); cur[v]++) {\r\n      Edge&\
    \ e = edges[*cur[v]];\r\n      if (level[e.to] != level[v] + 1 || e.flow == e.cap)\
    \ continue;\r\n      F df = dfs(e.to, t, std::min(flow, e.cap - e.flow));\r\n\
    \      if (df) {\r\n        e.flow += df;\r\n        edges[*cur[v] ^ 1].flow -=\
    \ df;\r\n        return df;\r\n      }\r\n    }\r\n    return 0;\r\n  }\r\n\r\n\
    \  F max_flow(int s, int t) {\r\n    F tot = 0;\r\n    while (bfs(s, t))\r\n \
    \     while (F df = dfs(s, t, std::numeric_limits<F>::max())) tot += df;\r\n \
    \   return tot;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/dinic.hpp
  requiredBy: []
  timestamp: '2023-01-08 14:07:45-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_6_A.test.cpp
  - verify/yosupo/yosupo-bipartitematching.test.cpp
documentation_of: library/graphs/flows/dinic.hpp
layout: document
redirect_from:
- /library/library/graphs/flows/dinic.hpp
- /library/library/graphs/flows/dinic.hpp.html
title: library/graphs/flows/dinic.hpp
---

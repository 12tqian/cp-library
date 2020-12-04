---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\graphs\\\\dijkstra.cpp\"\n#include<bits/stdc++.h>\r\
    \ntemplate <class C, bool directed> struct Dijkstra {\r\n    int SZ; std::vector<C>\
    \ dist;\r\n    std::vector<std::vector<std::pair<int, C>>> adj;\r\n    void init(int\
    \ _SZ) {\r\n        SZ = _SZ;\r\n        adj.clear();\r\n        adj.resize(SZ);\r\
    \n    }\r\n    void ae(int u, int v, C cost) {\r\n        adj[u].emplace_back(v,\
    \ cost);\r\n        if (!directed) adj[v].emplace_back(u, cost);\r\n    }\r\n\
    \    void gen(int st) {\r\n        dist = std::vector<C>(SZ, std::numeric_limits<C>::max());\r\
    \n        typedef std::pair<C, int> T;\r\n        std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> pq;\r\n        auto ad = [&](int a, C b) {\r\n            if\
    \ (dist[a] <= b) return;\r\n            pq.push({dist[a] = b, a});\r\n       \
    \ };\r\n        ad(st, 0);\r\n        while (!pq.empty()) {\r\n            auto\
    \ x = pq.top();\r\n            pq.pop();\r\n            if (dist[x.second] < x.first)\
    \ continue;\r\n            for (auto& y: adj[x.second]) {\r\n                ad(y.first,\
    \ x.first + y.second);\r\n            }\r\n        }\r\n    }\r\n};\r\nint main()\
    \ {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\ntemplate <class C, bool directed> struct Dijkstra\
    \ {\r\n    int SZ; std::vector<C> dist;\r\n    std::vector<std::vector<std::pair<int,\
    \ C>>> adj;\r\n    void init(int _SZ) {\r\n        SZ = _SZ;\r\n        adj.clear();\r\
    \n        adj.resize(SZ);\r\n    }\r\n    void ae(int u, int v, C cost) {\r\n\
    \        adj[u].emplace_back(v, cost);\r\n        if (!directed) adj[v].emplace_back(u,\
    \ cost);\r\n    }\r\n    void gen(int st) {\r\n        dist = std::vector<C>(SZ,\
    \ std::numeric_limits<C>::max());\r\n        typedef std::pair<C, int> T;\r\n\
    \        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;\r\n     \
    \   auto ad = [&](int a, C b) {\r\n            if (dist[a] <= b) return;\r\n \
    \           pq.push({dist[a] = b, a});\r\n        };\r\n        ad(st, 0);\r\n\
    \        while (!pq.empty()) {\r\n            auto x = pq.top();\r\n         \
    \   pq.pop();\r\n            if (dist[x.second] < x.first) continue;\r\n     \
    \       for (auto& y: adj[x.second]) {\r\n                ad(y.first, x.first\
    \ + y.second);\r\n            }\r\n        }\r\n    }\r\n};\r\nint main() {\r\n\
    \    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\graphs\dijkstra.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:55:15-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\graphs\dijkstra.cpp
layout: document
redirect_from:
- /library\library\graphs\dijkstra.cpp
- /library\library\graphs\dijkstra.cpp.html
title: library\graphs\dijkstra.cpp
---

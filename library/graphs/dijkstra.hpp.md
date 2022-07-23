---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_1_A.test.cpp
    title: verify/aizu/aizu-GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class C, bool directed> struct Dijkstra {\r\n\tint SZ;\
    \ std::vector<C> dist;\r\n\tstd::vector<std::vector<std::pair<int, C>>> adj;\r\
    \n\r\n\tvoid init(int _SZ) {\r\n\t\tSZ = _SZ;\r\n\t\tadj.clear();\r\n\t\tadj.resize(SZ);\r\
    \n\t}\r\n\r\n\tvoid ae(int u, int v, C cost) {\r\n\t\tadj[u].emplace_back(v, cost);\r\
    \n\t\tif (!directed) adj[v].emplace_back(u, cost);\r\n\t}\r\n\r\n\tvoid gen(int\
    \ st) {\r\n\t\tdist = std::vector<C>(SZ, std::numeric_limits<C>::max());\r\n\t\
    \ttypedef std::pair<C, int> T;\r\n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ pq;\r\n\t\tauto ad = [&](int a, C b) {\r\n\t\t\tif (dist[a] <= b) return;\r\n\
    \t\t\tpq.push({dist[a] = b, a});\r\n\t\t};\r\n\t\tad(st, 0);\r\n\t\twhile (!pq.empty())\
    \ {\r\n\t\t\tauto x = pq.top();\r\n\t\t\tpq.pop();\r\n\t\t\tif (dist[x.second]\
    \ < x.first) continue;\r\n\t\t\tfor (auto& y: adj[x.second]) {\r\n\t\t\t\tad(y.first,\
    \ x.first + y.second);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class C, bool directed> struct Dijkstra {\r\
    \n\tint SZ; std::vector<C> dist;\r\n\tstd::vector<std::vector<std::pair<int, C>>>\
    \ adj;\r\n\r\n\tvoid init(int _SZ) {\r\n\t\tSZ = _SZ;\r\n\t\tadj.clear();\r\n\t\
    \tadj.resize(SZ);\r\n\t}\r\n\r\n\tvoid ae(int u, int v, C cost) {\r\n\t\tadj[u].emplace_back(v,\
    \ cost);\r\n\t\tif (!directed) adj[v].emplace_back(u, cost);\r\n\t}\r\n\r\n\t\
    void gen(int st) {\r\n\t\tdist = std::vector<C>(SZ, std::numeric_limits<C>::max());\r\
    \n\t\ttypedef std::pair<C, int> T;\r\n\t\tstd::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> pq;\r\n\t\tauto ad = [&](int a, C b) {\r\n\t\t\tif (dist[a]\
    \ <= b) return;\r\n\t\t\tpq.push({dist[a] = b, a});\r\n\t\t};\r\n\t\tad(st, 0);\r\
    \n\t\twhile (!pq.empty()) {\r\n\t\t\tauto x = pq.top();\r\n\t\t\tpq.pop();\r\n\
    \t\t\tif (dist[x.second] < x.first) continue;\r\n\t\t\tfor (auto& y: adj[x.second])\
    \ {\r\n\t\t\t\tad(y.first, x.first + y.second);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_1_A.test.cpp
documentation_of: library/graphs/dijkstra.hpp
layout: document
redirect_from:
- /library/library/graphs/dijkstra.hpp
- /library/library/graphs/dijkstra.hpp.html
title: library/graphs/dijkstra.hpp
---

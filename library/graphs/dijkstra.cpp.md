---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dijkstra.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate <class C, bool directed> struct Dijkstra {\n\tint SZ; std::vector<C>\
    \ dist;\n\tstd::vector<std::vector<std::pair<int, C>>> adj;\n\n\tvoid init(int\
    \ _SZ) {\n\t\tSZ = _SZ;\n\t\tadj.clear();\n\t\tadj.resize(SZ);\n\t}\n\n\tvoid\
    \ ae(int u, int v, C cost) {\n\t\tadj[u].emplace_back(v, cost);\n\t\tif (!directed)\
    \ adj[v].emplace_back(u, cost);\n\t}\n\n\tvoid gen(int st) {\n\t\tdist = std::vector<C>(SZ,\
    \ std::numeric_limits<C>::max());\n\t\ttypedef std::pair<C, int> T;\n\t\tstd::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> pq;\n\t\tauto ad = [&](int a, C b) {\n\t\t\t\
    if (dist[a] <= b) return;\n\t\t\tpq.push({dist[a] = b, a});\n\t\t};\n\t\tad(st,\
    \ 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto x = pq.top();\n\t\t\tpq.pop();\n\t\
    \t\tif (dist[x.second] < x.first) continue;\n\t\t\tfor (auto& y: adj[x.second])\
    \ {\n\t\t\t\tad(y.first, x.first + y.second);\n\t\t\t}\n\t\t}\n\t}\n};\n\nint\
    \ main() {\n\treturn 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class C, bool directed> struct Dijkstra\
    \ {\n\tint SZ; std::vector<C> dist;\n\tstd::vector<std::vector<std::pair<int,\
    \ C>>> adj;\n\n\tvoid init(int _SZ) {\n\t\tSZ = _SZ;\n\t\tadj.clear();\n\t\tadj.resize(SZ);\n\
    \t}\n\n\tvoid ae(int u, int v, C cost) {\n\t\tadj[u].emplace_back(v, cost);\n\t\
    \tif (!directed) adj[v].emplace_back(u, cost);\n\t}\n\n\tvoid gen(int st) {\n\t\
    \tdist = std::vector<C>(SZ, std::numeric_limits<C>::max());\n\t\ttypedef std::pair<C,\
    \ int> T;\n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>> pq;\n\t\
    \tauto ad = [&](int a, C b) {\n\t\t\tif (dist[a] <= b) return;\n\t\t\tpq.push({dist[a]\
    \ = b, a});\n\t\t};\n\t\tad(st, 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto x =\
    \ pq.top();\n\t\t\tpq.pop();\n\t\t\tif (dist[x.second] < x.first) continue;\n\t\
    \t\tfor (auto& y: adj[x.second]) {\n\t\t\t\tad(y.first, x.first + y.second);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n\nint main() {\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dijkstra.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dijkstra.cpp
layout: document
redirect_from:
- /library/library/graphs/dijkstra.cpp
- /library/library/graphs/dijkstra.cpp.html
title: library/graphs/dijkstra.cpp
---

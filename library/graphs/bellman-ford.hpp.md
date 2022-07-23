---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_1_B.test.cpp
    title: verify/aizu/aizu-GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct BellmanFord {\r\n\tconst T INF = std::numeric_limits<T>::max();\r\
    \n\tint n; \r\n\tstd::vector<std::vector<int>> adj;\r\n\tstd::vector<std::pair<std::pair<int,\
    \ int>, T>> edges;\r\n\tstd::vector<T> dist;\r\n\r\n\tvoid init(int n_) {\r\n\t\
    \tn = n_;\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tedges.clear();\r\n\t\
    \tdist.assign(n, 0);\r\n\t}\r\n\r\n\tvoid ae(int u, int v, T w) {\r\n\t\tadj[u].push_back(v);\r\
    \n\t\tedges.push_back({{u, v}, w});\r\n\t}   \r\n\r\n\tvoid gen_bad(int x) {\r\
    \n\t\tif (dist[x] == -INF)\r\n\t\t\treturn;\r\n\t\tdist[x] = -INF;\r\n\t\tfor\
    \ (auto& nxt : adj[x])\r\n\t\t\tgen_bad(nxt);\r\n\t}\r\n\r\n\tvoid gen(int src)\
    \ {\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tdist[i] = INF;\r\n\t\tdist[src]\
    \ = 0;\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tfor (auto& e : edges) \r\n\t\
    \t\t\tif (dist[e.first.first] < INF)\r\n\t\t\t\t\tdist[e.first.second] = std::min(dist[e.first.second],\
    \ dist[e.first.first] + e.second);\r\n\t\tfor (auto& e : edges) \r\n\t\t\tif (dist[e.first.first]\
    \ < INF && dist[e.first.second] > dist[e.first.first] + e.second)\r\n\t\t\t\t\
    gen_bad(e.first.second);\r\n\t}\r\n\t\r\n\tstd::vector<int> negative_cycle(int\
    \ src = 0) {\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tdist[src] = INF;\r\n\t\
    \tdist[src] = 0;\r\n\t\tstd::vector<int> pre(n);\r\n\t\tfor (auto& e : edges)\
    \ \r\n\t\t\tif (e.first.first == e.first.second && e.second < 0) \r\n\t\t\t\t\
    return {e.first.first};\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tfor (auto&\
    \ e : edges) \r\n\t\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\t\t\tif (dist[e.first.second]\
    \ > dist[e.first.first] + e.second) {\r\n\t\t\t\t\t\tdist[e.first.second] = dist[e.first.first]\
    \ + e.second;\r\n\t\t\t\t\t\tpre[e.first.second] = e.first.first;\r\n\t\t\t\t\t\
    }\r\n\t\tfor (auto& e : edges) \r\n\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\
    \t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\r\n\t\t\t\t\t\
    int x = e.first.second;\r\n\t\t\t\t\tfor (int i = 0; i < n; i++)\r\n\t\t\t\t\t\
    \tx = pre[x];\r\n\t\t\t\t\tstd::vector<int> cycle;\r\n\t\t\t\t\tfor (int v = x;\
    \ v != x || cycle.empty(); v = pre[v])\r\n\t\t\t\t\t\tcycle.push_back(v);\r\n\t\
    \t\t\t\treverse(cycle.begin(), cycle.end());\r\n\t\t\t\t\treturn cycle;\r\n\t\t\
    \t\t}\r\n\t\treturn {};\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct BellmanFord {\r\n\tconst T\
    \ INF = std::numeric_limits<T>::max();\r\n\tint n; \r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<std::pair<std::pair<int, int>, T>> edges;\r\n\tstd::vector<T>\
    \ dist;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tadj.assign(n, std::vector<int>());\r\
    \n\t\tedges.clear();\r\n\t\tdist.assign(n, 0);\r\n\t}\r\n\r\n\tvoid ae(int u,\
    \ int v, T w) {\r\n\t\tadj[u].push_back(v);\r\n\t\tedges.push_back({{u, v}, w});\r\
    \n\t}   \r\n\r\n\tvoid gen_bad(int x) {\r\n\t\tif (dist[x] == -INF)\r\n\t\t\t\
    return;\r\n\t\tdist[x] = -INF;\r\n\t\tfor (auto& nxt : adj[x])\r\n\t\t\tgen_bad(nxt);\r\
    \n\t}\r\n\r\n\tvoid gen(int src) {\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\
    \tdist[i] = INF;\r\n\t\tdist[src] = 0;\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\
    \t\tfor (auto& e : edges) \r\n\t\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\t\
    \t\tdist[e.first.second] = std::min(dist[e.first.second], dist[e.first.first]\
    \ + e.second);\r\n\t\tfor (auto& e : edges) \r\n\t\t\tif (dist[e.first.first]\
    \ < INF && dist[e.first.second] > dist[e.first.first] + e.second)\r\n\t\t\t\t\
    gen_bad(e.first.second);\r\n\t}\r\n\t\r\n\tstd::vector<int> negative_cycle(int\
    \ src = 0) {\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tdist[src] = INF;\r\n\t\
    \tdist[src] = 0;\r\n\t\tstd::vector<int> pre(n);\r\n\t\tfor (auto& e : edges)\
    \ \r\n\t\t\tif (e.first.first == e.first.second && e.second < 0) \r\n\t\t\t\t\
    return {e.first.first};\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tfor (auto&\
    \ e : edges) \r\n\t\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\t\t\tif (dist[e.first.second]\
    \ > dist[e.first.first] + e.second) {\r\n\t\t\t\t\t\tdist[e.first.second] = dist[e.first.first]\
    \ + e.second;\r\n\t\t\t\t\t\tpre[e.first.second] = e.first.first;\r\n\t\t\t\t\t\
    }\r\n\t\tfor (auto& e : edges) \r\n\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\
    \t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\r\n\t\t\t\t\t\
    int x = e.first.second;\r\n\t\t\t\t\tfor (int i = 0; i < n; i++)\r\n\t\t\t\t\t\
    \tx = pre[x];\r\n\t\t\t\t\tstd::vector<int> cycle;\r\n\t\t\t\t\tfor (int v = x;\
    \ v != x || cycle.empty(); v = pre[v])\r\n\t\t\t\t\t\tcycle.push_back(v);\r\n\t\
    \t\t\t\treverse(cycle.begin(), cycle.end());\r\n\t\t\t\t\treturn cycle;\r\n\t\t\
    \t\t}\r\n\t\treturn {};\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/bellman-ford.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_1_B.test.cpp
documentation_of: library/graphs/bellman-ford.hpp
layout: document
title: Bellman Ford
---

## Bellman Ford 
 
Works in $\mathcal O(VE)$ for $V$ vertices and $E$ edges. Note that `negative_cycle` is the same as `gen`, but it doesn't call `gen_bad`$. 

### Functions
- `init(n)`: Initializes the variables. 
- `gen(src)`: Generates distances from `src`. 
- `negative_cycle(src)`$: Finds a negative cycle if it exists. If it doesn't, this returns an empty list. 

### Variables
- `dist`: Stores distances to each vertex. It's infinity if you can't reach it and negative infinity if you have a negative cycle. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Basics/BellmanFord%20(7.3).h)


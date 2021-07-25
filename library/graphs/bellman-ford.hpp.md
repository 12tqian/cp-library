---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/bellman-ford.test.cpp
    title: test/bellman-ford.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "/**\n * dist is INF if you can't reach and -INF if it is in a negative\
    \ cycle\n * negative cycle is same thing as gen, it just doesn't do gen_bad\n\
    \ * also it returns a negative cycle :D\n */\n\ntemplate <class T> struct BellmanFord\
    \ {\n\tconst T INF = std::numeric_limits<T>::max();\n\tint n; \n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<std::pair<std::pair<int, int>, T>> edges;\n\tstd::vector<T>\
    \ dist;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tadj.assign(n, std::vector<int>());\n\
    \t\tedges.clear();\n\t\tdist.assign(n, 0);\n\t}\n\n\tvoid ae(int u, int v, T w)\
    \ {\n\t\tadj[u].push_back(v);\n\t\tedges.push_back({{u, v}, w});\n\t}   \n\n\t\
    void gen_bad(int x) {\n\t\tif (dist[x] == -INF)\n\t\t\treturn;\n\t\tdist[x] =\
    \ -INF;\n\t\tfor (auto &nxt : adj[x])\n\t\t\tgen_bad(nxt);\n\t}\n\n\tvoid gen(int\
    \ src) {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tdist[i] = INF;\n\t\tdist[src]\
    \ = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (auto &e : edges) \n\t\t\t\t\
    if (dist[e.first.first] < INF)\n\t\t\t\t\tdist[e.first.second] = std::min(dist[e.first.second],\
    \ dist[e.first.first] + e.second);\n\t\tfor (auto &e : edges) \n\t\t\tif (dist[e.first.first]\
    \ < INF && dist[e.first.second] > dist[e.first.first] + e.second)\n\t\t\tgen_bad(e.first.second);\n\
    \t}\n\t\n\tstd::vector<int> negative_cycle(int src = 0) {\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tdist[src] = INF;\n\t\tdist[src] = 0;\n\t\tstd::vector<int>\
    \ pre(n);\n\t\tfor (auto &e : edges) \n\t\t\tif (e.first.first == e.first.second\
    \ && e.second < 0) \n\t\t\t\treturn {e.first.first};\n\t\tfor (int i = 0; i <\
    \ n; i++) \n\t\t\tfor (auto &e : edges) \n\t\t\t\tif (dist[e.first.first] < INF)\n\
    \t\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\t\t\t\
    \t\t\tdist[e.first.second] = dist[e.first.first] + e.second;\n\t\t\t\t\t\tpre[e.first.second]\
    \ = e.first.first;\n\t\t\t\t\t}\n\t\tfor (auto &e : edges) \n\t\t\tif (dist[e.first.first]\
    \ < INF)\n\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\
    \t\t\t\t\tint x = e.first.second;\n\t\t\t\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \t\t\t\tx = pre[x];\n\t\t\t\t\tstd::vector<int> cycle;\n\t\t\t\t\tfor (int v =\
    \ x; v != x || cycle.empty(); v = pre[v])\n\t\t\t\t\t\tcycle.push_back(v);\n\t\
    \t\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\t\t\treturn cycle;\n\t\t\t\t\
    }\n\t\treturn {};\n\t}\n};\n"
  code: "#pragma once\n/**\n * dist is INF if you can't reach and -INF if it is in\
    \ a negative cycle\n * negative cycle is same thing as gen, it just doesn't do\
    \ gen_bad\n * also it returns a negative cycle :D\n */\n\ntemplate <class T> struct\
    \ BellmanFord {\n\tconst T INF = std::numeric_limits<T>::max();\n\tint n; \n\t\
    std::vector<std::vector<int>> adj;\n\tstd::vector<std::pair<std::pair<int, int>,\
    \ T>> edges;\n\tstd::vector<T> dist;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\
    \tadj.assign(n, std::vector<int>());\n\t\tedges.clear();\n\t\tdist.assign(n, 0);\n\
    \t}\n\n\tvoid ae(int u, int v, T w) {\n\t\tadj[u].push_back(v);\n\t\tedges.push_back({{u,\
    \ v}, w});\n\t}   \n\n\tvoid gen_bad(int x) {\n\t\tif (dist[x] == -INF)\n\t\t\t\
    return;\n\t\tdist[x] = -INF;\n\t\tfor (auto &nxt : adj[x])\n\t\t\tgen_bad(nxt);\n\
    \t}\n\n\tvoid gen(int src) {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tdist[i]\
    \ = INF;\n\t\tdist[src] = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (auto\
    \ &e : edges) \n\t\t\t\tif (dist[e.first.first] < INF)\n\t\t\t\t\tdist[e.first.second]\
    \ = std::min(dist[e.first.second], dist[e.first.first] + e.second);\n\t\tfor (auto\
    \ &e : edges) \n\t\t\tif (dist[e.first.first] < INF && dist[e.first.second] >\
    \ dist[e.first.first] + e.second)\n\t\t\tgen_bad(e.first.second);\n\t}\n\t\n\t\
    std::vector<int> negative_cycle(int src = 0) {\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\tdist[src] = INF;\n\t\tdist[src] = 0;\n\t\tstd::vector<int> pre(n);\n\t\t\
    for (auto &e : edges) \n\t\t\tif (e.first.first == e.first.second && e.second\
    \ < 0) \n\t\t\t\treturn {e.first.first};\n\t\tfor (int i = 0; i < n; i++) \n\t\
    \t\tfor (auto &e : edges) \n\t\t\t\tif (dist[e.first.first] < INF)\n\t\t\t\t\t\
    if (dist[e.first.second] > dist[e.first.first] + e.second) {\n\t\t\t\t\t\tdist[e.first.second]\
    \ = dist[e.first.first] + e.second;\n\t\t\t\t\t\tpre[e.first.second] = e.first.first;\n\
    \t\t\t\t\t}\n\t\tfor (auto &e : edges) \n\t\t\tif (dist[e.first.first] < INF)\n\
    \t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\t\t\t\t\
    \tint x = e.first.second;\n\t\t\t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\t\t\t\
    x = pre[x];\n\t\t\t\t\tstd::vector<int> cycle;\n\t\t\t\t\tfor (int v = x; v !=\
    \ x || cycle.empty(); v = pre[v])\n\t\t\t\t\t\tcycle.push_back(v);\n\t\t\t\t\t\
    reverse(cycle.begin(), cycle.end());\n\t\t\t\t\treturn cycle;\n\t\t\t\t}\n\t\t\
    return {};\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/bellman-ford.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:57:36-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/bellman-ford.test.cpp
documentation_of: library/graphs/bellman-ford.hpp
layout: document
redirect_from:
- /library/library/graphs/bellman-ford.hpp
- /library/library/graphs/bellman-ford.hpp.html
title: library/graphs/bellman-ford.hpp
---

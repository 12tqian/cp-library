---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kattis/kattis-mincostmaxflow.test.cpp
    title: verify/kattis/kattis-mincostmaxflow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class F, class C> struct MCMF {\r\n\tstruct Edge { int\
    \ to; F flow, cap; C cost; };\r\n\r\n\tint n;\r\n\tstd::vector<C> p, dist;\r\n\
    \tstd::vector<int> pre;\r\n\tstd::vector<Edge> edges;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\r\n\tconst C INF  = std::numeric_limits<C>::max();\r\n\r\n\tvoid init(int\
    \ n_) {\r\n\t\tn = n_;\r\n\t\tp.assign(n, 0);\r\n\t\tdist.assign(n, 0);\r\n\t\t\
    pre.assign(n, 0);\r\n\t\tadj.clear(); adj.resize(n);\r\n\t\tedges.clear();\r\n\
    \t}\r\n\r\n\tvoid ae(int u, int v, F cap, C cost) {\r\n\t\tassert(cap >= 0);\r\
    \n\t\tadj[u].push_back((int)edges.size());\r\n\t\tedges.push_back({v, 0, cap,\
    \ cost});\r\n\t\tadj[v].push_back((int)edges.size());\r\n\t\tedges.push_back({u,\
    \ 0, 0, -cost});\r\n\t}\r\n\r\n\tbool path(int s, int t) {\r\n\t\tfor (int i =\
    \ 0; i < n; i++) \r\n\t\t\tdist[i] = INF;\r\n\t\tusing T = std::pair<C, int>;\r\
    \n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>> todo;\r\n\t\ttodo.push({dist[s]\
    \ = 0, s});\r\n\t\twhile (!todo.empty()) {\r\n\t\t\tT x = todo.top();\r\n\t\t\t\
    todo.pop();\r\n\t\t\tif (x.first > dist[x.second])\r\n\t\t\t\tcontinue;\r\n\t\t\
    \tfor (auto& eid : adj[x.second]) {\r\n\t\t\t\tconst Edge& e = edges[eid];\r\n\
    \t\t\t\tif (e.flow < e.cap && dist[e.to] > x.first + e.cost + p[x.second] - p[e.to])\
    \ {\r\n\t\t\t\t\tdist[e.to] = x.first + e.cost + p[x.second] - p[e.to];\r\n\t\t\
    \t\t\tpre[e.to] = eid;\r\n\t\t\t\t\ttodo.push({dist[e.to], e.to});\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn dist[t] != INF;\r\n\t}\r\n\r\n\tstd::pair<F,\
    \ C> calc(int s, int t) {\r\n\t\tassert(s != t);\r\n\t\tfor (int unused = 0; unused\
    \ < n; unused++)\r\n\t\t\tfor (int eid = 0; eid < (int)edges.size(); eid++) {\r\
    \n\t\t\t\tconst Edge& e = edges[eid];\r\n\t\t\t\tif (e.cap)\r\n\t\t\t\t\tp[e.to]\
    \ = std::min(p[e.to], p[edges[eid ^ 1].to] + e.cost);\r\n\t\t\t}\r\n\t\tF total_flow\
    \ = 0;\r\n\t\tC total_cost = 0;\r\n\t\twhile (path(s, t)) {\r\n\t\t\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\t\t\tp[i] += dist[i];\r\n\t\t\tF df = std::numeric_limits<F>::max();\r\
    \n\t\t\tfor (int x = t; x != s; x = edges[pre[x] ^ 1].to) {\r\n\t\t\t\tconst Edge&\
    \ e = edges[pre[x]];\r\n\t\t\t\tdf = std::min(df, e.cap - e.flow);\r\n\t\t\t}\r\
    \n\t\t\ttotal_flow += df;\r\n\t\t\ttotal_cost += (p[t] - p[s]) * df;\r\n\t\t\t\
    for (int x = t; x != s; x = edges[pre[x] ^ 1].to) \r\n\t\t\t\tedges[pre[x]].flow\
    \ += df, edges[pre[x] ^ 1].flow -= df;\r\n\t\t}\r\n\t\treturn {total_flow, total_cost};\r\
    \n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class F, class C> struct MCMF {\r\n\tstruct\
    \ Edge { int to; F flow, cap; C cost; };\r\n\r\n\tint n;\r\n\tstd::vector<C> p,\
    \ dist;\r\n\tstd::vector<int> pre;\r\n\tstd::vector<Edge> edges;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\r\n\tconst C INF  = std::numeric_limits<C>::max();\r\n\r\n\tvoid init(int\
    \ n_) {\r\n\t\tn = n_;\r\n\t\tp.assign(n, 0);\r\n\t\tdist.assign(n, 0);\r\n\t\t\
    pre.assign(n, 0);\r\n\t\tadj.clear(); adj.resize(n);\r\n\t\tedges.clear();\r\n\
    \t}\r\n\r\n\tvoid ae(int u, int v, F cap, C cost) {\r\n\t\tassert(cap >= 0);\r\
    \n\t\tadj[u].push_back((int)edges.size());\r\n\t\tedges.push_back({v, 0, cap,\
    \ cost});\r\n\t\tadj[v].push_back((int)edges.size());\r\n\t\tedges.push_back({u,\
    \ 0, 0, -cost});\r\n\t}\r\n\r\n\tbool path(int s, int t) {\r\n\t\tfor (int i =\
    \ 0; i < n; i++) \r\n\t\t\tdist[i] = INF;\r\n\t\tusing T = std::pair<C, int>;\r\
    \n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>> todo;\r\n\t\ttodo.push({dist[s]\
    \ = 0, s});\r\n\t\twhile (!todo.empty()) {\r\n\t\t\tT x = todo.top();\r\n\t\t\t\
    todo.pop();\r\n\t\t\tif (x.first > dist[x.second])\r\n\t\t\t\tcontinue;\r\n\t\t\
    \tfor (auto& eid : adj[x.second]) {\r\n\t\t\t\tconst Edge& e = edges[eid];\r\n\
    \t\t\t\tif (e.flow < e.cap && dist[e.to] > x.first + e.cost + p[x.second] - p[e.to])\
    \ {\r\n\t\t\t\t\tdist[e.to] = x.first + e.cost + p[x.second] - p[e.to];\r\n\t\t\
    \t\t\tpre[e.to] = eid;\r\n\t\t\t\t\ttodo.push({dist[e.to], e.to});\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn dist[t] != INF;\r\n\t}\r\n\r\n\tstd::pair<F,\
    \ C> calc(int s, int t) {\r\n\t\tassert(s != t);\r\n\t\tfor (int unused = 0; unused\
    \ < n; unused++)\r\n\t\t\tfor (int eid = 0; eid < (int)edges.size(); eid++) {\r\
    \n\t\t\t\tconst Edge& e = edges[eid];\r\n\t\t\t\tif (e.cap)\r\n\t\t\t\t\tp[e.to]\
    \ = std::min(p[e.to], p[edges[eid ^ 1].to] + e.cost);\r\n\t\t\t}\r\n\t\tF total_flow\
    \ = 0;\r\n\t\tC total_cost = 0;\r\n\t\twhile (path(s, t)) {\r\n\t\t\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\t\t\tp[i] += dist[i];\r\n\t\t\tF df = std::numeric_limits<F>::max();\r\
    \n\t\t\tfor (int x = t; x != s; x = edges[pre[x] ^ 1].to) {\r\n\t\t\t\tconst Edge&\
    \ e = edges[pre[x]];\r\n\t\t\t\tdf = std::min(df, e.cap - e.flow);\r\n\t\t\t}\r\
    \n\t\t\ttotal_flow += df;\r\n\t\t\ttotal_cost += (p[t] - p[s]) * df;\r\n\t\t\t\
    for (int x = t; x != s; x = edges[pre[x] ^ 1].to) \r\n\t\t\t\tedges[pre[x]].flow\
    \ += df, edges[pre[x] ^ 1].flow -= df;\r\n\t\t}\r\n\t\treturn {total_flow, total_cost};\r\
    \n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/min-cost-max-flow.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kattis/kattis-mincostmaxflow.test.cpp
documentation_of: library/graphs/flows/min-cost-max-flow.hpp
layout: document
title: Minimum Cost Maximum Flow
---

## Minimum Cost Maximum Flow

### Functions
- `calc(s, t)`: Calculates maximum flow from `s` to `t`, returning a pair of the flow and the cost. 

### Variables
- `edges`: After calling `calc`, this holds the amount of flow through each edge, which lets us recover stuff. To obtain original edges, assign ID's in `ae`. 
	
### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Flows%20(12.3)/MCMF.h)


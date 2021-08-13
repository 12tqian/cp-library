---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_6_A-2.test.cpp
    title: verify/aizu/aizu-GRL_6_A-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class F> struct PushRelabel {\n\n\tstruct Edge { int to,\
    \ rev; F flow; };\n\n\tconst F INF = std::numeric_limits<F>::max();  \n\n\tint\
    \ n, s, t, highest, work;\n\tstd::vector<std::vector<Edge>> adj;\n\tstd::vector<std::vector<int>>\
    \ lst, gap;\n\tstd::vector<int> height, cnt;\n\tstd::vector<F> excess;\n\n\tvoid\
    \ init(int n_) {\n\t\tn = n_;\n\t\tadj.clear(); adj.resize(2 * n);\n\t\tlst.clear();\
    \ lst.resize(2 * n);\n\t\tgap.clear(); gap.resize(2 * n);\n\t\theight.assign(2\
    \ * n, 0);\n\t\tcnt.assign(2 * n, 0);\n\t\texcess.assign(2 * n, 0);\n\t\twork\
    \ = highest = 0;\n\t\ts = 0;\n\t\tt = n - 1;\n\t}\n\n\tvoid ae(int u, int v, F\
    \ cap) {\n\t\tassert(cap >= 0);\n\t\tEdge a{v, (int)adj[v].size(), cap};\n\t\t\
    Edge b{u, (int)adj[u].size(), 0};\n\t\tadj[u].push_back(a);\n\t\tadj[v].push_back(b);\n\
    \t}\n\n\tvoid update_height(int v, int nh) {\n\t\twork++;\n\t\tif (height[v] !=\
    \ n)\n\t\t\tcnt[height[v]]--;\n\t\theight[v] = nh;\n\t\tif (nh == n)\n\t\t\treturn;\n\
    \t\tcnt[nh]++;\n\t\thighest = nh;\n\t\tgap[nh].push_back(v);\n\t\tif (excess[v]\
    \ > 0)\n\t\t\tlst[nh].push_back(v);\n\t}\n\n\tvoid global_relabel() {\n\t\twork\
    \ = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\theight[i] = n, cnt[i] = 0;\n\t\t\
    for (int i = 0; i < highest; i++) \n\t\t\tlst[i].clear(), gap[i].clear();\n\t\t\
    height[t] = 0;\n\t\tstd::queue<int> q({t});\n\t\twhile (!q.empty()) {\n\t\t\t\
    int v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : adj[v]) \n\t\t\t\tif\
    \ (height[e.to] == n && adj[e.to][e.rev].flow > 0)\n\t\t\t\t\tq.push(e.to), update_height(e.to,\
    \ height[v] + 1);\n\t\t\thighest = height[v];\n\t\t}\n\t}\n\n\tvoid push(int v,\
    \ Edge& e) {\n\t\tif (excess[e.to] == 0)\n\t\t\tlst[height[e.to]].push_back(e.to);\n\
    \t\tF df = std::min(excess[v], e.flow);\n\t\te.flow -= df, adj[e.to][e.rev].flow\
    \ += df;\n\t\texcess[v] -= df, excess[e.to] += df;\n\t}\n\n\tvoid discharge(int\
    \ v) {\n\t\tint nh = n;\n\t\tfor (auto& e : adj[v]) \n\t\t\tif (e.flow > 0)\n\t\
    \t\t\tif (height[v] == height[e.to] + 1) {\n\t\t\t\t\tpush(v, e);\n\t\t\t\t\t\
    if (excess[v] <= 0)\n\t\t\t\t\t\treturn;\n\t\t\t\t} else {\n\t\t\t\t\tnh = std::min(nh,\
    \ height[e.to] + 1);\n\t\t\t\t}\n\t\tif (cnt[height[v]] > 1) \n\t\t\tupdate_height(v,\
    \ nh);\n\t\telse {\n\t\t\tfor (int i = height[v]; i <= highest; i++) {\n\t\t\t\
    \tfor (auto& j : gap[i])\n\t\t\t\t\tupdate_height(j, n);\n\t\t\t\tgap[i].clear();\n\
    \t\t\t}\n\t\t}\n\t}\n\t\n\tF max_flow(int s_, int t_) {\n\t\ts = s_, t = t_;\n\
    \t\tif (s == t)\n\t\t\treturn -1;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\texcess[i]\
    \ = 0;\n\t\texcess[s] = INF, excess[t] = -INF;\n\t\tglobal_relabel();\n\t\tfor\
    \ (auto& e : adj[s]) \n\t\t\tpush(s, e);\n\t\tfor (; highest >= 0; highest--)\n\
    \t\t\twhile (!lst[highest].empty()) {\n\t\t\t\tint v = lst[highest].back();\n\t\
    \t\t\tlst[highest].pop_back();\n\t\t\t\tdischarge(v);\n\t\t\t\tif (work > 4 *\
    \ n)\n\t\t\t\t\tglobal_relabel();\n\t\t\t}\n\t\treturn excess[t] + INF;\n\t}\n\
    };\n"
  code: "#pragma once\n\ntemplate <class F> struct PushRelabel {\n\n\tstruct Edge\
    \ { int to, rev; F flow; };\n\n\tconst F INF = std::numeric_limits<F>::max();\
    \  \n\n\tint n, s, t, highest, work;\n\tstd::vector<std::vector<Edge>> adj;\n\t\
    std::vector<std::vector<int>> lst, gap;\n\tstd::vector<int> height, cnt;\n\tstd::vector<F>\
    \ excess;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tadj.clear(); adj.resize(2\
    \ * n);\n\t\tlst.clear(); lst.resize(2 * n);\n\t\tgap.clear(); gap.resize(2 *\
    \ n);\n\t\theight.assign(2 * n, 0);\n\t\tcnt.assign(2 * n, 0);\n\t\texcess.assign(2\
    \ * n, 0);\n\t\twork = highest = 0;\n\t\ts = 0;\n\t\tt = n - 1;\n\t}\n\n\tvoid\
    \ ae(int u, int v, F cap) {\n\t\tassert(cap >= 0);\n\t\tEdge a{v, (int)adj[v].size(),\
    \ cap};\n\t\tEdge b{u, (int)adj[u].size(), 0};\n\t\tadj[u].push_back(a);\n\t\t\
    adj[v].push_back(b);\n\t}\n\n\tvoid update_height(int v, int nh) {\n\t\twork++;\n\
    \t\tif (height[v] != n)\n\t\t\tcnt[height[v]]--;\n\t\theight[v] = nh;\n\t\tif\
    \ (nh == n)\n\t\t\treturn;\n\t\tcnt[nh]++;\n\t\thighest = nh;\n\t\tgap[nh].push_back(v);\n\
    \t\tif (excess[v] > 0)\n\t\t\tlst[nh].push_back(v);\n\t}\n\n\tvoid global_relabel()\
    \ {\n\t\twork = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\theight[i] = n, cnt[i]\
    \ = 0;\n\t\tfor (int i = 0; i < highest; i++) \n\t\t\tlst[i].clear(), gap[i].clear();\n\
    \t\theight[t] = 0;\n\t\tstd::queue<int> q({t});\n\t\twhile (!q.empty()) {\n\t\t\
    \tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : adj[v]) \n\t\t\t\t\
    if (height[e.to] == n && adj[e.to][e.rev].flow > 0)\n\t\t\t\t\tq.push(e.to), update_height(e.to,\
    \ height[v] + 1);\n\t\t\thighest = height[v];\n\t\t}\n\t}\n\n\tvoid push(int v,\
    \ Edge& e) {\n\t\tif (excess[e.to] == 0)\n\t\t\tlst[height[e.to]].push_back(e.to);\n\
    \t\tF df = std::min(excess[v], e.flow);\n\t\te.flow -= df, adj[e.to][e.rev].flow\
    \ += df;\n\t\texcess[v] -= df, excess[e.to] += df;\n\t}\n\n\tvoid discharge(int\
    \ v) {\n\t\tint nh = n;\n\t\tfor (auto& e : adj[v]) \n\t\t\tif (e.flow > 0)\n\t\
    \t\t\tif (height[v] == height[e.to] + 1) {\n\t\t\t\t\tpush(v, e);\n\t\t\t\t\t\
    if (excess[v] <= 0)\n\t\t\t\t\t\treturn;\n\t\t\t\t} else {\n\t\t\t\t\tnh = std::min(nh,\
    \ height[e.to] + 1);\n\t\t\t\t}\n\t\tif (cnt[height[v]] > 1) \n\t\t\tupdate_height(v,\
    \ nh);\n\t\telse {\n\t\t\tfor (int i = height[v]; i <= highest; i++) {\n\t\t\t\
    \tfor (auto& j : gap[i])\n\t\t\t\t\tupdate_height(j, n);\n\t\t\t\tgap[i].clear();\n\
    \t\t\t}\n\t\t}\n\t}\n\t\n\tF max_flow(int s_, int t_) {\n\t\ts = s_, t = t_;\n\
    \t\tif (s == t)\n\t\t\treturn -1;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\texcess[i]\
    \ = 0;\n\t\texcess[s] = INF, excess[t] = -INF;\n\t\tglobal_relabel();\n\t\tfor\
    \ (auto& e : adj[s]) \n\t\t\tpush(s, e);\n\t\tfor (; highest >= 0; highest--)\n\
    \t\t\twhile (!lst[highest].empty()) {\n\t\t\t\tint v = lst[highest].back();\n\t\
    \t\t\tlst[highest].pop_back();\n\t\t\t\tdischarge(v);\n\t\t\t\tif (work > 4 *\
    \ n)\n\t\t\t\t\tglobal_relabel();\n\t\t\t}\n\t\treturn excess[t] + INF;\n\t}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/push-relabel.hpp
  requiredBy: []
  timestamp: '2021-08-13 01:40:26-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_6_A-2.test.cpp
documentation_of: library/graphs/flows/push-relabel.hpp
layout: document
title: Push Relabel
---

## Push Relabel

### Functions
- `max_flow(s, t)`: Calculates maximum flow form $s$ to $t$. 

### Variables
- `adj`: Stores amount of flow through each edge after calling `max_flow`. 
	
### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Flows%20(12.3)/HLPP.h)


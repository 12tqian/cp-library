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
  bundledCode: "\r\ntemplate <class F> struct PushRelabel {\r\n\r\n\tstruct Edge {\
    \ int to, rev; F flow; };\r\n\r\n\tconst F INF = std::numeric_limits<F>::max();\
    \  \r\n\r\n\tint n, s, t, highest, work;\r\n\tstd::vector<std::vector<Edge>> adj;\r\
    \n\tstd::vector<std::vector<int>> lst, gap;\r\n\tstd::vector<int> height, cnt;\r\
    \n\tstd::vector<F> excess;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\t\
    adj.clear(); adj.resize(2 * n);\r\n\t\tlst.clear(); lst.resize(2 * n);\r\n\t\t\
    gap.clear(); gap.resize(2 * n);\r\n\t\theight.assign(2 * n, 0);\r\n\t\tcnt.assign(2\
    \ * n, 0);\r\n\t\texcess.assign(2 * n, 0);\r\n\t\twork = highest = 0;\r\n\t\t\
    s = 0;\r\n\t\tt = n - 1;\r\n\t}\r\n\r\n\tvoid ae(int u, int v, F cap) {\r\n\t\t\
    assert(cap >= 0);\r\n\t\tEdge a{v, (int)adj[v].size(), cap};\r\n\t\tEdge b{u,\
    \ (int)adj[u].size(), 0};\r\n\t\tadj[u].push_back(a);\r\n\t\tadj[v].push_back(b);\r\
    \n\t}\r\n\r\n\tvoid update_height(int v, int nh) {\r\n\t\twork++;\r\n\t\tif (height[v]\
    \ != n)\r\n\t\t\tcnt[height[v]]--;\r\n\t\theight[v] = nh;\r\n\t\tif (nh == n)\r\
    \n\t\t\treturn;\r\n\t\tcnt[nh]++;\r\n\t\thighest = nh;\r\n\t\tgap[nh].push_back(v);\r\
    \n\t\tif (excess[v] > 0)\r\n\t\t\tlst[nh].push_back(v);\r\n\t}\r\n\r\n\tvoid global_relabel()\
    \ {\r\n\t\twork = 0;\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\theight[i] = n,\
    \ cnt[i] = 0;\r\n\t\tfor (int i = 0; i < highest; i++) \r\n\t\t\tlst[i].clear(),\
    \ gap[i].clear();\r\n\t\theight[t] = 0;\r\n\t\tstd::queue<int> q({t});\r\n\t\t\
    while (!q.empty()) {\r\n\t\t\tint v = q.front();\r\n\t\t\tq.pop();\r\n\t\t\tfor\
    \ (auto& e : adj[v]) \r\n\t\t\t\tif (height[e.to] == n && adj[e.to][e.rev].flow\
    \ > 0)\r\n\t\t\t\t\tq.push(e.to), update_height(e.to, height[v] + 1);\r\n\t\t\t\
    highest = height[v];\r\n\t\t}\r\n\t}\r\n\r\n\tvoid push(int v, Edge& e) {\r\n\t\
    \tif (excess[e.to] == 0)\r\n\t\t\tlst[height[e.to]].push_back(e.to);\r\n\t\tF\
    \ df = std::min(excess[v], e.flow);\r\n\t\te.flow -= df, adj[e.to][e.rev].flow\
    \ += df;\r\n\t\texcess[v] -= df, excess[e.to] += df;\r\n\t}\r\n\r\n\tvoid discharge(int\
    \ v) {\r\n\t\tint nh = n;\r\n\t\tfor (auto& e : adj[v]) \r\n\t\t\tif (e.flow >\
    \ 0)\r\n\t\t\t\tif (height[v] == height[e.to] + 1) {\r\n\t\t\t\t\tpush(v, e);\r\
    \n\t\t\t\t\tif (excess[v] <= 0)\r\n\t\t\t\t\t\treturn;\r\n\t\t\t\t} else {\r\n\
    \t\t\t\t\tnh = std::min(nh, height[e.to] + 1);\r\n\t\t\t\t}\r\n\t\tif (cnt[height[v]]\
    \ > 1) \r\n\t\t\tupdate_height(v, nh);\r\n\t\telse {\r\n\t\t\tfor (int i = height[v];\
    \ i <= highest; i++) {\r\n\t\t\t\tfor (auto& j : gap[i])\r\n\t\t\t\t\tupdate_height(j,\
    \ n);\r\n\t\t\t\tgap[i].clear();\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tF max_flow(int\
    \ s_, int t_) {\r\n\t\ts = s_, t = t_;\r\n\t\tif (s == t)\r\n\t\t\treturn -1;\r\
    \n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\texcess[i] = 0;\r\n\t\texcess[s] = INF,\
    \ excess[t] = -INF;\r\n\t\tglobal_relabel();\r\n\t\tfor (auto& e : adj[s]) \r\n\
    \t\t\tpush(s, e);\r\n\t\tfor (; highest >= 0; highest--)\r\n\t\t\twhile (!lst[highest].empty())\
    \ {\r\n\t\t\t\tint v = lst[highest].back();\r\n\t\t\t\tlst[highest].pop_back();\r\
    \n\t\t\t\tdischarge(v);\r\n\t\t\t\tif (work > 4 * n)\r\n\t\t\t\t\tglobal_relabel();\r\
    \n\t\t\t}\r\n\t\treturn excess[t] + INF;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class F> struct PushRelabel {\r\n\r\n\tstruct\
    \ Edge { int to, rev; F flow; };\r\n\r\n\tconst F INF = std::numeric_limits<F>::max();\
    \  \r\n\r\n\tint n, s, t, highest, work;\r\n\tstd::vector<std::vector<Edge>> adj;\r\
    \n\tstd::vector<std::vector<int>> lst, gap;\r\n\tstd::vector<int> height, cnt;\r\
    \n\tstd::vector<F> excess;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\t\
    adj.clear(); adj.resize(2 * n);\r\n\t\tlst.clear(); lst.resize(2 * n);\r\n\t\t\
    gap.clear(); gap.resize(2 * n);\r\n\t\theight.assign(2 * n, 0);\r\n\t\tcnt.assign(2\
    \ * n, 0);\r\n\t\texcess.assign(2 * n, 0);\r\n\t\twork = highest = 0;\r\n\t\t\
    s = 0;\r\n\t\tt = n - 1;\r\n\t}\r\n\r\n\tvoid ae(int u, int v, F cap) {\r\n\t\t\
    assert(cap >= 0);\r\n\t\tEdge a{v, (int)adj[v].size(), cap};\r\n\t\tEdge b{u,\
    \ (int)adj[u].size(), 0};\r\n\t\tadj[u].push_back(a);\r\n\t\tadj[v].push_back(b);\r\
    \n\t}\r\n\r\n\tvoid update_height(int v, int nh) {\r\n\t\twork++;\r\n\t\tif (height[v]\
    \ != n)\r\n\t\t\tcnt[height[v]]--;\r\n\t\theight[v] = nh;\r\n\t\tif (nh == n)\r\
    \n\t\t\treturn;\r\n\t\tcnt[nh]++;\r\n\t\thighest = nh;\r\n\t\tgap[nh].push_back(v);\r\
    \n\t\tif (excess[v] > 0)\r\n\t\t\tlst[nh].push_back(v);\r\n\t}\r\n\r\n\tvoid global_relabel()\
    \ {\r\n\t\twork = 0;\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\theight[i] = n,\
    \ cnt[i] = 0;\r\n\t\tfor (int i = 0; i < highest; i++) \r\n\t\t\tlst[i].clear(),\
    \ gap[i].clear();\r\n\t\theight[t] = 0;\r\n\t\tstd::queue<int> q({t});\r\n\t\t\
    while (!q.empty()) {\r\n\t\t\tint v = q.front();\r\n\t\t\tq.pop();\r\n\t\t\tfor\
    \ (auto& e : adj[v]) \r\n\t\t\t\tif (height[e.to] == n && adj[e.to][e.rev].flow\
    \ > 0)\r\n\t\t\t\t\tq.push(e.to), update_height(e.to, height[v] + 1);\r\n\t\t\t\
    highest = height[v];\r\n\t\t}\r\n\t}\r\n\r\n\tvoid push(int v, Edge& e) {\r\n\t\
    \tif (excess[e.to] == 0)\r\n\t\t\tlst[height[e.to]].push_back(e.to);\r\n\t\tF\
    \ df = std::min(excess[v], e.flow);\r\n\t\te.flow -= df, adj[e.to][e.rev].flow\
    \ += df;\r\n\t\texcess[v] -= df, excess[e.to] += df;\r\n\t}\r\n\r\n\tvoid discharge(int\
    \ v) {\r\n\t\tint nh = n;\r\n\t\tfor (auto& e : adj[v]) \r\n\t\t\tif (e.flow >\
    \ 0)\r\n\t\t\t\tif (height[v] == height[e.to] + 1) {\r\n\t\t\t\t\tpush(v, e);\r\
    \n\t\t\t\t\tif (excess[v] <= 0)\r\n\t\t\t\t\t\treturn;\r\n\t\t\t\t} else {\r\n\
    \t\t\t\t\tnh = std::min(nh, height[e.to] + 1);\r\n\t\t\t\t}\r\n\t\tif (cnt[height[v]]\
    \ > 1) \r\n\t\t\tupdate_height(v, nh);\r\n\t\telse {\r\n\t\t\tfor (int i = height[v];\
    \ i <= highest; i++) {\r\n\t\t\t\tfor (auto& j : gap[i])\r\n\t\t\t\t\tupdate_height(j,\
    \ n);\r\n\t\t\t\tgap[i].clear();\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tF max_flow(int\
    \ s_, int t_) {\r\n\t\ts = s_, t = t_;\r\n\t\tif (s == t)\r\n\t\t\treturn -1;\r\
    \n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\texcess[i] = 0;\r\n\t\texcess[s] = INF,\
    \ excess[t] = -INF;\r\n\t\tglobal_relabel();\r\n\t\tfor (auto& e : adj[s]) \r\n\
    \t\t\tpush(s, e);\r\n\t\tfor (; highest >= 0; highest--)\r\n\t\t\twhile (!lst[highest].empty())\
    \ {\r\n\t\t\t\tint v = lst[highest].back();\r\n\t\t\t\tlst[highest].pop_back();\r\
    \n\t\t\t\tdischarge(v);\r\n\t\t\t\tif (work > 4 * n)\r\n\t\t\t\t\tglobal_relabel();\r\
    \n\t\t\t}\r\n\t\treturn excess[t] + INF;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/push-relabel.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_6_A-2.test.cpp
documentation_of: library/graphs/flows/push-relabel.hpp
layout: document
title: Push Relabel
---

## Push Relabel

### Functions
- `max_flow(s, t)`: Calculates maximum flow form `s` to `t`. 

### Variables
- `adj`: Stores amount of flow through each edge after calling `max_flow`. 
	
### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Flows%20(12.3)/HLPP.h)


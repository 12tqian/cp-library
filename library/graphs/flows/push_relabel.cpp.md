---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/flows/push_relabel.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Treat this as a black box xD\n * Calculates max flow\n * You can probably\
    \ add stuff to recover it\n * Most cases, Dinic is better since you understand\
    \ it\n */\n\ntemplate <class F> struct PushRelabel {\n\n\tstruct Edge { int to,\
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
    };\n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    int n, m;\n\tcin >> n >> m;\n\tPushRelabel<long long> P;\n\tP.init(n);\n\tfor\
    \ (int i = 0; i < m; i++) {\n\t\tint u, v, w; cin >> u >> v >> w;\n\t\tu--, v--;\n\
    \t\tP.ae(u, v, w);\n\t\tP.ae(v, u, w);\n\t}\n\tcout << P.max_flow(0, n - 1) <<\
    \ '\\n';\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Treat this as a black box xD\n * Calculates\
    \ max flow\n * You can probably add stuff to recover it\n * Most cases, Dinic\
    \ is better since you understand it\n */\n\ntemplate <class F> struct PushRelabel\
    \ {\n\n\tstruct Edge { int to, rev; F flow; };\n\n\tconst F INF = std::numeric_limits<F>::max();\
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
    };\n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    int n, m;\n\tcin >> n >> m;\n\tPushRelabel<long long> P;\n\tP.init(n);\n\tfor\
    \ (int i = 0; i < m; i++) {\n\t\tint u, v, w; cin >> u >> v >> w;\n\t\tu--, v--;\n\
    \t\tP.ae(u, v, w);\n\t\tP.ae(v, u, w);\n\t}\n\tcout << P.max_flow(0, n - 1) <<\
    \ '\\n';\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/push_relabel.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/push_relabel.cpp
layout: document
redirect_from:
- /library/library/graphs/flows/push_relabel.cpp
- /library/library/graphs/flows/push_relabel.cpp.html
title: library/graphs/flows/push_relabel.cpp
---

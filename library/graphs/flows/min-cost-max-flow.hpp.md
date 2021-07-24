---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "/**\n * to get back the original edges, assign ID's in ae\n */\n\n\
    template <class F, class C> struct MCMF {\n\tstruct Edge { int to; F flow, cap;\
    \ C cost; };\n\n\tint n;\n\tstd::vector<C> p, dist;\n\tstd::vector<int> pre;\n\
    \tstd::vector<Edge> edges;\n\tstd::vector<std::vector<int>> adj;\n\n\tconst C\
    \ INF  = std::numeric_limits<C>::max();\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\
    \t\tp.assign(n, 0);\n\t\tdist.assign(n, 0);\n\t\tpre.assign(n, 0);\n\t\tadj.clear();\
    \ adj.resize(n);\n\t\tedges.clear();\n\t}\n\n\tvoid ae(int u, int v, F cap, C\
    \ cost) {\n\t\tassert(cap >= 0);\n\t\tadj[u].push_back((int)edges.size());\n\t\
    \tedges.push_back({v, 0, cap, cost});\n\t\tadj[v].push_back((int)edges.size());\n\
    \t\tedges.push_back({u, 0, 0, -cost});\n\t}\n\n\tbool path(int s, int t) {\n\t\
    \tfor (int i = 0; i < n; i++) \n\t\t\tdist[i] = INF;\n\t\tusing T = std::pair<C,\
    \ int>;\n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>> todo;\n\t\
    \ttodo.push({dist[s] = 0, s});\n\t\twhile (!todo.empty()) {\n\t\t\tT x = todo.top();\n\
    \t\t\ttodo.pop();\n\t\t\tif (x.first > dist[x.second])\n\t\t\t\tcontinue;\n\t\t\
    \tfor (auto& eid : adj[x.second]) {\n\t\t\t\tconst Edge& e = edges[eid];\n\t\t\
    \t\tif (e.flow < e.cap && dist[e.to] > x.first + e.cost + p[x.second] - p[e.to])\
    \ {\n\t\t\t\t\tdist[e.to] = x.first + e.cost + p[x.second] - p[e.to];\n\t\t\t\t\
    \tpre[e.to] = eid;\n\t\t\t\t\ttodo.push({dist[e.to], e.to});\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn dist[t] != INF;\n\t}\n\n\tstd::pair<F, C> calc(int s, int\
    \ t) {\n\t\tassert(s != t);\n\t\tfor (int unused = 0; unused < n; unused++)\n\t\
    \t\tfor (int eid = 0; eid < (int)edges.size(); eid++) {\n\t\t\t\tconst Edge& e\
    \ = edges[eid];\n\t\t\t\tif (e.cap)\n\t\t\t\t\tp[e.to] = std::min(p[e.to], p[edges[eid\
    \ ^ 1].to] + e.cost);\n\t\t\t}\n\t\tF total_flow = 0;\n\t\tC total_cost = 0;\n\
    \t\twhile (path(s, t)) {\n\t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tp[i] += dist[i];\n\
    \t\t\tF df = std::numeric_limits<F>::max();\n\t\t\tfor (int x = t; x != s; x =\
    \ edges[pre[x] ^ 1].to) {\n\t\t\t\tconst Edge& e = edges[pre[x]];\n\t\t\t\tdf\
    \ = std::min(df, e.cap - e.flow);\n\t\t\t}\n\t\t\ttotal_flow += df;\n\t\t\ttotal_cost\
    \ += (p[t] - p[s]) * df;\n\t\t\tfor (int x = t; x != s; x = edges[pre[x] ^ 1].to)\
    \ \n\t\t\t\tedges[pre[x]].flow += df, edges[pre[x] ^ 1].flow -= df;\n\t\t}\n\t\
    \treturn {total_flow, total_cost};\n\t}\n};\n\nint main() {\n\tusing namespace\
    \ std;\n\tint n, m, s, t;\n\tcin >> n >> m >> s >> t;\n\tMCMF<int, int> M;\n\t\
    M.init(n);\n\tfor (int i = 0; i < m; i++) {\n\t\tint u, v, c, w;\n\t\tcin >> u\
    \ >> v >> c >> w;\n\t\tM.ae(u, v, c, w);\n\t}\n\tauto res = M.calc(s, t);\n\t\
    cout << res.first << \" \" << res.second << '\\n';\n\treturn 0;\n}\n"
  code: "#pragma once\n/**\n * to get back the original edges, assign ID's in ae\n\
    \ */\n\ntemplate <class F, class C> struct MCMF {\n\tstruct Edge { int to; F flow,\
    \ cap; C cost; };\n\n\tint n;\n\tstd::vector<C> p, dist;\n\tstd::vector<int> pre;\n\
    \tstd::vector<Edge> edges;\n\tstd::vector<std::vector<int>> adj;\n\n\tconst C\
    \ INF  = std::numeric_limits<C>::max();\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\
    \t\tp.assign(n, 0);\n\t\tdist.assign(n, 0);\n\t\tpre.assign(n, 0);\n\t\tadj.clear();\
    \ adj.resize(n);\n\t\tedges.clear();\n\t}\n\n\tvoid ae(int u, int v, F cap, C\
    \ cost) {\n\t\tassert(cap >= 0);\n\t\tadj[u].push_back((int)edges.size());\n\t\
    \tedges.push_back({v, 0, cap, cost});\n\t\tadj[v].push_back((int)edges.size());\n\
    \t\tedges.push_back({u, 0, 0, -cost});\n\t}\n\n\tbool path(int s, int t) {\n\t\
    \tfor (int i = 0; i < n; i++) \n\t\t\tdist[i] = INF;\n\t\tusing T = std::pair<C,\
    \ int>;\n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>> todo;\n\t\
    \ttodo.push({dist[s] = 0, s});\n\t\twhile (!todo.empty()) {\n\t\t\tT x = todo.top();\n\
    \t\t\ttodo.pop();\n\t\t\tif (x.first > dist[x.second])\n\t\t\t\tcontinue;\n\t\t\
    \tfor (auto& eid : adj[x.second]) {\n\t\t\t\tconst Edge& e = edges[eid];\n\t\t\
    \t\tif (e.flow < e.cap && dist[e.to] > x.first + e.cost + p[x.second] - p[e.to])\
    \ {\n\t\t\t\t\tdist[e.to] = x.first + e.cost + p[x.second] - p[e.to];\n\t\t\t\t\
    \tpre[e.to] = eid;\n\t\t\t\t\ttodo.push({dist[e.to], e.to});\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn dist[t] != INF;\n\t}\n\n\tstd::pair<F, C> calc(int s, int\
    \ t) {\n\t\tassert(s != t);\n\t\tfor (int unused = 0; unused < n; unused++)\n\t\
    \t\tfor (int eid = 0; eid < (int)edges.size(); eid++) {\n\t\t\t\tconst Edge& e\
    \ = edges[eid];\n\t\t\t\tif (e.cap)\n\t\t\t\t\tp[e.to] = std::min(p[e.to], p[edges[eid\
    \ ^ 1].to] + e.cost);\n\t\t\t}\n\t\tF total_flow = 0;\n\t\tC total_cost = 0;\n\
    \t\twhile (path(s, t)) {\n\t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tp[i] += dist[i];\n\
    \t\t\tF df = std::numeric_limits<F>::max();\n\t\t\tfor (int x = t; x != s; x =\
    \ edges[pre[x] ^ 1].to) {\n\t\t\t\tconst Edge& e = edges[pre[x]];\n\t\t\t\tdf\
    \ = std::min(df, e.cap - e.flow);\n\t\t\t}\n\t\t\ttotal_flow += df;\n\t\t\ttotal_cost\
    \ += (p[t] - p[s]) * df;\n\t\t\tfor (int x = t; x != s; x = edges[pre[x] ^ 1].to)\
    \ \n\t\t\t\tedges[pre[x]].flow += df, edges[pre[x] ^ 1].flow -= df;\n\t\t}\n\t\
    \treturn {total_flow, total_cost};\n\t}\n};\n\nint main() {\n\tusing namespace\
    \ std;\n\tint n, m, s, t;\n\tcin >> n >> m >> s >> t;\n\tMCMF<int, int> M;\n\t\
    M.init(n);\n\tfor (int i = 0; i < m; i++) {\n\t\tint u, v, c, w;\n\t\tcin >> u\
    \ >> v >> c >> w;\n\t\tM.ae(u, v, c, w);\n\t}\n\tauto res = M.calc(s, t);\n\t\
    cout << res.first << \" \" << res.second << '\\n';\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/min-cost-max-flow.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/flows/min-cost-max-flow.hpp
layout: document
redirect_from:
- /library/library/graphs/flows/min-cost-max-flow.hpp
- /library/library/graphs/flows/min-cost-max-flow.hpp.html
title: library/graphs/flows/min-cost-max-flow.hpp
---

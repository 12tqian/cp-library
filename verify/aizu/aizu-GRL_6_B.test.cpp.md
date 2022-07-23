---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/min-cost-flow.hpp
    title: library/graphs/flows/min-cost-flow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n\r\ntemplate <class C, class D> struct MinCostFlow\
    \ {\r\n\tstruct E {\r\n\t\tint to, rev;\r\n\t\tC cap;\r\n\t\tD dist;\r\n\t};\r\
    \n\r\n\tstatic constexpr D INF = std::numeric_limits<D>::max();\r\n\t\r\n\tint\
    \ n;\r\n\tint s, t;\r\n\r\n\tstd::vector<std::vector<E>> g;\r\n\t\r\n\tC nc, cap_flow\
    \ = 0;\r\n\tD nd, dist_flow = 0;\r\n\r\n\tstd::vector<D> dual;\r\n\tstd::vector<int>\
    \ pv, pe;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\ts = t = -1;\r\n\t\
    \tnc = cap_flow = 0;\r\n\t\tnd = dist_flow = 0;\r\n\t\tg.assign(n, std::vector<E>());\r\
    \n\t\tdual.clear();\r\n\t\tpv.clear();\r\n\t\tpe.clear();\r\n\t}\r\n\r\n\tvoid\
    \ ae(int from, int to, C cap, D dist) {\r\n\t\tg[from].push_back(E{to, int(g[to].size()),\
    \ cap, dist});\r\n\t\tg[to].push_back(E{from, int(g[from].size()) - 1, 0, -dist});\r\
    \n\t}\r\n\r\n\tvoid gen(int _s, int _t, bool neg = false) {\r\n\t\ts = _s;\r\n\
    \t\tt = _t;\r\n\t\tassert(s != t);\r\n\t\tdual = std::vector<D>(n);\r\n\t\tpv\
    \ = pe = std::vector<int>(n);\r\n\t\tif (neg) {\r\n\t\t\tstd::vector<D> dist(n,\
    \ D(INF));\r\n\t\t\tdist[s] = 0;\r\n\t\t\tfor (int ph = 0; ph < n; ph++) {\r\n\
    \t\t\t\tbool update = false;\r\n\t\t\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\t\
    \t\tif (dist[i] == INF) continue;\r\n\t\t\t\t\tfor (auto e : g[i]) {\r\n\t\t\t\
    \t\t\tif (!e.cap) continue;\r\n\t\t\t\t\t\tif (dist[i] + e.dist < dist[e.to])\
    \ {\r\n\t\t\t\t\t\t\tdist[e.to] = dist[i] + e.dist;\r\n\t\t\t\t\t\t\tupdate =\
    \ true;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif (!update) break;\r\
    \n\t\t\t}\r\n\t\t\tfor (int v = 0; v < n; v++) {\r\n\t\t\t\tdual[v] += dist[v];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tdual_ref();\r\n\t}\r\n\r\n\tC single_flow(C c) {\r\n\
    \t\tif (nd == INF) return nc;\r\n\t\tc = std::min(c, nc);\r\n\t\tfor (int v =\
    \ t; v != s; v = pv[v]) {\r\n\t\t\tE& e = g[pv[v]][pe[v]];\r\n\t\t\te.cap -= c;\r\
    \n\t\t\tg[v][e.rev].cap += c;\r\n\t\t}\r\n\t\tcap_flow += c;\r\n\t\tdist_flow\
    \ += nd * c;\r\n\t\tnc -= c;\r\n\t\tif (!nc) dual_ref();\r\n\t\treturn c;\r\n\t\
    }\r\n\r\n\tvoid max_flow(C c) {\r\n\t\twhile (c) {\r\n\t\t\tC f = single_flow(c);\r\
    \n\t\t\tif (!f) break;\r\n\t\t\tc -= f;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dual_ref()\
    \ {\r\n\t\tstd::vector<D> dist(g.size(), D(INF));\r\n\t\tpv = pe = std::vector<int>(n,\
    \ -1);\r\n\t\tstruct Q {\r\n\t\t\tD key;\r\n\t\t\tint to;\r\n\t\t\tbool operator<(Q\
    \ r) const { return key > r.key; }\r\n\t\t};\r\n\t\tstd::priority_queue<Q> que;\r\
    \n\t\tdist[s] = 0;\r\n\t\tque.push(Q{D(0), s});\r\n\t\tstd::vector<char> vis(n);\r\
    \n\t\twhile (!que.empty()) {\r\n\t\t\tint v = que.top().to; que.pop();\r\n\t\t\
    \tif (v == t) break;\r\n\t\t\tif (vis[v]) continue;\r\n\t\t\tvis[v] = true;\r\n\
    \t\t\tfor (int i = 0; i < int(g[v].size()); i++) {\r\n\t\t\t\tE e = g[v][i];\r\
    \n\t\t\t\tif (vis[e.to] || !e.cap) continue;\r\n\t\t\t\tD cost = dist[v] + e.dist\
    \ + dual[v] - dual[e.to];\r\n\t\t\t\tif (dist[e.to] > cost) {\r\n\t\t\t\t\tdist[e.to]\
    \ = cost;\r\n\t\t\t\t\tpv[e.to] = v; pe[e.to] = i;\r\n\t\t\t\t\tque.push(Q{dist[e.to],\
    \ e.to});\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (dist[t] == INF) {\r\n\t\t\
    \tnd = INF; nc = 0;\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tfor (int v = 0; v < n; v++)\
    \ {\r\n\t\t\tif (!vis[v]) continue;\r\n\t\t\tdual[v] += dist[v] - dist[t];\r\n\
    \t\t}\r\n\t\tnd = dual[t] - dual[s];\r\n\t\tnc = std::numeric_limits<C>::max();\r\
    \n\t\tfor (int v = t; v != s; v = pv[v]) {\r\n\t\t\tnc = std::min(nc, g[pv[v]][pe[v]].cap);\r\
    \n\t\t}\r\n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint v, e, f;\r\n\tcin >> v >> e >> f;\r\n\tMinCostFlow<long\
    \ long, long long> mcf;\r\n\tmcf.init(v);\r\n\twhile (e--) {\r\n\t\tint u, v,\
    \ c, d;\r\n\t\tcin >> u >> v >> c >> d;\r\n\t\tmcf.ae(u, v, c, d);\r\n\t}\r\n\t\
    mcf.gen(0, v - 1);\r\n\tmcf.max_flow(f);\r\n\tif (mcf.cap_flow != f) {\r\n\t\t\
    cout << -1 << '\\n';\r\n\t} else {\r\n\t\tcout << mcf.dist_flow << '\\n';\r\n\t\
    }\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"../../library/graphs/flows/min-cost-flow.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint v, e, f;\r\n\tcin >> v >> e >> f;\r\n\tMinCostFlow<long\
    \ long, long long> mcf;\r\n\tmcf.init(v);\r\n\twhile (e--) {\r\n\t\tint u, v,\
    \ c, d;\r\n\t\tcin >> u >> v >> c >> d;\r\n\t\tmcf.ae(u, v, c, d);\r\n\t}\r\n\t\
    mcf.gen(0, v - 1);\r\n\tmcf.max_flow(f);\r\n\tif (mcf.cap_flow != f) {\r\n\t\t\
    cout << -1 << '\\n';\r\n\t} else {\r\n\t\tcout << mcf.dist_flow << '\\n';\r\n\t\
    }\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/graphs/flows/min-cost-flow.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_6_B.test.cpp
- /verify/verify/aizu/aizu-GRL_6_B.test.cpp.html
title: verify/aizu/aizu-GRL_6_B.test.cpp
---

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
    \n\n#include <bits/stdc++.h>\n\ntemplate <class C, class D> struct MinCostFlow\
    \ {\n\tstruct E {\n\t\tint to, rev;\n\t\tC cap;\n\t\tD dist;\n\t};\n\n\tstatic\
    \ constexpr D INF = std::numeric_limits<D>::max();\n\t\n\tint n;\n\tint s, t;\n\
    \n\tstd::vector<std::vector<E>> g;\n\t\n\tC nc, cap_flow = 0;\n\tD nd, dist_flow\
    \ = 0;\n\n\tstd::vector<D> dual;\n\tstd::vector<int> pv, pe;\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\ts = t = -1;\n\t\tnc = cap_flow = 0;\n\t\tnd = dist_flow\
    \ = 0;\n\t\tg.assign(n, std::vector<E>());\n\t\tdual.clear();\n\t\tpv.clear();\n\
    \t\tpe.clear();\n\t}\n\n\tvoid ae(int from, int to, C cap, D dist) {\n\t\tg[from].push_back(E{to,\
    \ int(g[to].size()), cap, dist});\n\t\tg[to].push_back(E{from, int(g[from].size())\
    \ - 1, 0, -dist});\n\t}\n\n\tvoid gen(int _s, int _t, bool neg = false) {\n\t\t\
    s = _s;\n\t\tt = _t;\n\t\tassert(s != t);\n\t\tdual = std::vector<D>(n);\n\t\t\
    pv = pe = std::vector<int>(n);\n\t\tif (neg) {\n\t\t\tstd::vector<D> dist(n, D(INF));\n\
    \t\t\tdist[s] = 0;\n\t\t\tfor (int ph = 0; ph < n; ph++) {\n\t\t\t\tbool update\
    \ = false;\n\t\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\t\tif (dist[i] == INF)\
    \ continue;\n\t\t\t\t\tfor (auto e : g[i]) {\n\t\t\t\t\t\tif (!e.cap) continue;\n\
    \t\t\t\t\t\tif (dist[i] + e.dist < dist[e.to]) {\n\t\t\t\t\t\t\tdist[e.to] = dist[i]\
    \ + e.dist;\n\t\t\t\t\t\t\tupdate = true;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\
    }\n\t\t\t\tif (!update) break;\n\t\t\t}\n\t\t\tfor (int v = 0; v < n; v++) {\n\
    \t\t\t\tdual[v] += dist[v];\n\t\t\t}\n\t\t}\n\t\tdual_ref();\n\t}\n\n\tC single_flow(C\
    \ c) {\n\t\tif (nd == INF) return nc;\n\t\tc = std::min(c, nc);\n\t\tfor (int\
    \ v = t; v != s; v = pv[v]) {\n\t\t\tE& e = g[pv[v]][pe[v]];\n\t\t\te.cap -= c;\n\
    \t\t\tg[v][e.rev].cap += c;\n\t\t}\n\t\tcap_flow += c;\n\t\tdist_flow += nd *\
    \ c;\n\t\tnc -= c;\n\t\tif (!nc) dual_ref();\n\t\treturn c;\n\t}\n\n\tvoid max_flow(C\
    \ c) {\n\t\twhile (c) {\n\t\t\tC f = single_flow(c);\n\t\t\tif (!f) break;\n\t\
    \t\tc -= f;\n\t\t}\n\t}\n\n\tvoid dual_ref() {\n\t\tstd::vector<D> dist(g.size(),\
    \ D(INF));\n\t\tpv = pe = std::vector<int>(n, -1);\n\t\tstruct Q {\n\t\t\tD key;\n\
    \t\t\tint to;\n\t\t\tbool operator<(Q r) const { return key > r.key; }\n\t\t};\n\
    \t\tstd::priority_queue<Q> que;\n\t\tdist[s] = 0;\n\t\tque.push(Q{D(0), s});\n\
    \t\tstd::vector<char> vis(n);\n\t\twhile (!que.empty()) {\n\t\t\tint v = que.top().to;\
    \ que.pop();\n\t\t\tif (v == t) break;\n\t\t\tif (vis[v]) continue;\n\t\t\tvis[v]\
    \ = true;\n\t\t\tfor (int i = 0; i < int(g[v].size()); i++) {\n\t\t\t\tE e = g[v][i];\n\
    \t\t\t\tif (vis[e.to] || !e.cap) continue;\n\t\t\t\tD cost = dist[v] + e.dist\
    \ + dual[v] - dual[e.to];\n\t\t\t\tif (dist[e.to] > cost) {\n\t\t\t\t\tdist[e.to]\
    \ = cost;\n\t\t\t\t\tpv[e.to] = v; pe[e.to] = i;\n\t\t\t\t\tque.push(Q{dist[e.to],\
    \ e.to});\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (dist[t] == INF) {\n\t\t\tnd = INF;\
    \ nc = 0;\n\t\t\treturn;\n\t\t}\n\t\tfor (int v = 0; v < n; v++) {\n\t\t\tif (!vis[v])\
    \ continue;\n\t\t\tdual[v] += dist[v] - dist[t];\n\t\t}\n\t\tnd = dual[t] - dual[s];\n\
    \t\tnc = std::numeric_limits<C>::max();\n\t\tfor (int v = t; v != s; v = pv[v])\
    \ {\n\t\t\tnc = std::min(nc, g[pv[v]][pe[v]].cap);\n\t\t}\n\t}\n};\n\nint main()\
    \ {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint v, e, f;\n\tcin >> v >> e >> f;\n\tMinCostFlow<long long, long long> mcf;\n\
    \tmcf.init(v);\n\twhile (e--) {\n\t\tint u, v, c, d;\n\t\tcin >> u >> v >> c >>\
    \ d;\n\t\tmcf.ae(u, v, c, d);\n\t}\n\tmcf.gen(0, v - 1);\n\tmcf.max_flow(f);\n\
    \tif (mcf.cap_flow != f) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tcout <<\
    \ mcf.dist_flow << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <bits/stdc++.h>\n#include \"../../library/graphs/flows/min-cost-flow.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint v, e, f;\n\tcin >> v >> e >> f;\n\tMinCostFlow<long long, long long> mcf;\n\
    \tmcf.init(v);\n\twhile (e--) {\n\t\tint u, v, c, d;\n\t\tcin >> u >> v >> c >>\
    \ d;\n\t\tmcf.ae(u, v, c, d);\n\t}\n\tmcf.gen(0, v - 1);\n\tmcf.max_flow(f);\n\
    \tif (mcf.cap_flow != f) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tcout <<\
    \ mcf.dist_flow << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/graphs/flows/min-cost-flow.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2021-08-20 12:24:28-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_6_B.test.cpp
- /verify/verify/aizu/aizu-GRL_6_B.test.cpp.html
title: verify/aizu/aizu-GRL_6_B.test.cpp
---

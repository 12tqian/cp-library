---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/min-cost-max-flow.hpp
    title: Minimum Cost Maximum Flow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://open.kattis.com/problems/mincostmaxflow
    links:
    - https://open.kattis.com/problems/mincostmaxflow
  bundledCode: "#define PROBLEM \"https://open.kattis.com/problems/mincostmaxflow\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class F, class\
    \ C> struct MCMF {\r\n\tstruct Edge { int to; F flow, cap; C cost; };\r\n\r\n\t\
    int n;\r\n\tstd::vector<C> p, dist;\r\n\tstd::vector<int> pre;\r\n\tstd::vector<Edge>\
    \ edges;\r\n\tstd::vector<std::vector<int>> adj;\r\n\r\n\tconst C INF  = std::numeric_limits<C>::max();\r\
    \n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tp.assign(n, 0);\r\n\t\tdist.assign(n,\
    \ 0);\r\n\t\tpre.assign(n, 0);\r\n\t\tadj.clear(); adj.resize(n);\r\n\t\tedges.clear();\r\
    \n\t}\r\n\r\n\tvoid ae(int u, int v, F cap, C cost) {\r\n\t\tassert(cap >= 0);\r\
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
    \n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\tint n, m, s, t;\r\
    \n\tcin >> n >> m >> s >> t;\r\n\tMCMF<int, int> M;\r\n\tM.init(n);\r\n\tfor (int\
    \ i = 0; i < m; i++) {\r\n\t\tint u, v, c, w;\r\n\t\tcin >> u >> v >> c >> w;\r\
    \n\t\tM.ae(u, v, c, w);\r\n\t}\r\n\tauto res = M.calc(s, t);\r\n\tcout << res.first\
    \ << \" \" << res.second << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://open.kattis.com/problems/mincostmaxflow\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/flows/min-cost-max-flow.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tint n, m, s, t;\r\n\tcin >>\
    \ n >> m >> s >> t;\r\n\tMCMF<int, int> M;\r\n\tM.init(n);\r\n\tfor (int i = 0;\
    \ i < m; i++) {\r\n\t\tint u, v, c, w;\r\n\t\tcin >> u >> v >> c >> w;\r\n\t\t\
    M.ae(u, v, c, w);\r\n\t}\r\n\tauto res = M.calc(s, t);\r\n\tcout << res.first\
    \ << \" \" << res.second << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/flows/min-cost-max-flow.hpp
  isVerificationFile: true
  path: verify/kattis/kattis-mincostmaxflow.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kattis/kattis-mincostmaxflow.test.cpp
layout: document
redirect_from:
- /verify/verify/kattis/kattis-mincostmaxflow.test.cpp
- /verify/verify/kattis/kattis-mincostmaxflow.test.cpp.html
title: verify/kattis/kattis-mincostmaxflow.test.cpp
---

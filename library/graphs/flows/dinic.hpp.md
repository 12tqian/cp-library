---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_6_A.test.cpp
    title: verify/aizu/aizu-GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-bipartitematching.test.cpp
    title: verify/yosupo/yosupo-bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class F> struct Dinic {\r\n\tstruct Edge { int to; F\
    \ flow, cap; };\r\n\tint n;\r\n\tstd::vector<Edge> edges;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> level;\r\n\tstd::vector<std::vector<int>::iterator>\
    \ cur;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tadj.assign(n, std::vector<int>());\r\
    \n\t\tcur.assign(n, std::vector<int>::iterator());\r\n\t\tedges.clear();\r\n\t\
    \tlevel.clear();\r\n\t}\r\n\r\n\tvoid ae(int u, int v, F cap, F rcap = 0) {\r\n\
    \t\tassert(std::min(cap, rcap) >= 0);\r\n\t\tadj[u].push_back((int)edges.size());\r\
    \n\t\tedges.push_back({v, 0, cap});\r\n\t\tadj[v].push_back((int)edges.size());\r\
    \n\t\tedges.push_back({u, 0, rcap});\r\n\t}\r\n\r\n\tbool bfs(int s, int t) {\r\
    \n\t\tlevel = std::vector<int>(n, -1);\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\
    \t\tcur[i] = adj[i].begin();\r\n\t\tstd::queue<int> q({s});\r\n\t\tlevel[s] =\
    \ 0;\r\n\t\twhile (!q.empty()) {\r\n\t\t\tint u = q.front();\r\n\t\t\tq.pop();\r\
    \n\t\t\tfor (auto& eid : adj[u]) {\r\n\t\t\t\tconst Edge& e = edges[eid];\r\n\t\
    \t\t\tint v = e.to;\r\n\t\t\t\tif (level[v] < 0 && e.flow < e.cap) \r\n\t\t\t\t\
    \tq.push(v), level[v] = level[u] + 1;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn level[t]\
    \ >= 0;\r\n\t}\r\n\r\n\tF dfs(int v, int t, F flow) {\r\n\t\tif (v == t)\r\n\t\
    \t\treturn flow;\r\n\t\tfor (; cur[v] != adj[v].end(); cur[v]++) {\r\n\t\t\tEdge&\
    \ e = edges[*cur[v]];\r\n\t\t\tif (level[e.to] != level[v] + 1 || e.flow == e.cap)\r\
    \n\t\t\t\tcontinue;\r\n\t\t\tF df = dfs(e.to, t, std::min(flow, e.cap - e.flow));\r\
    \n\t\t\tif (df) {\r\n\t\t\t\te.flow += df;\r\n\t\t\t\tedges[*cur[v] ^ 1].flow\
    \ -= df;\r\n\t\t\t\treturn df;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn 0;\r\n\t}\r\n\
    \t\r\n\tF max_flow(int s, int t) {\r\n\t\tF tot = 0;\r\n\t\twhile (bfs(s, t))\
    \ \r\n\t\t\twhile (F df = dfs(s, t, std::numeric_limits<F>::max())) \r\n\t\t\t\
    \ttot += df;\r\n\t\treturn tot;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class F> struct Dinic {\r\n\tstruct Edge {\
    \ int to; F flow, cap; };\r\n\tint n;\r\n\tstd::vector<Edge> edges;\r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> level;\r\n\tstd::vector<std::vector<int>::iterator>\
    \ cur;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tadj.assign(n, std::vector<int>());\r\
    \n\t\tcur.assign(n, std::vector<int>::iterator());\r\n\t\tedges.clear();\r\n\t\
    \tlevel.clear();\r\n\t}\r\n\r\n\tvoid ae(int u, int v, F cap, F rcap = 0) {\r\n\
    \t\tassert(std::min(cap, rcap) >= 0);\r\n\t\tadj[u].push_back((int)edges.size());\r\
    \n\t\tedges.push_back({v, 0, cap});\r\n\t\tadj[v].push_back((int)edges.size());\r\
    \n\t\tedges.push_back({u, 0, rcap});\r\n\t}\r\n\r\n\tbool bfs(int s, int t) {\r\
    \n\t\tlevel = std::vector<int>(n, -1);\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\
    \t\tcur[i] = adj[i].begin();\r\n\t\tstd::queue<int> q({s});\r\n\t\tlevel[s] =\
    \ 0;\r\n\t\twhile (!q.empty()) {\r\n\t\t\tint u = q.front();\r\n\t\t\tq.pop();\r\
    \n\t\t\tfor (auto& eid : adj[u]) {\r\n\t\t\t\tconst Edge& e = edges[eid];\r\n\t\
    \t\t\tint v = e.to;\r\n\t\t\t\tif (level[v] < 0 && e.flow < e.cap) \r\n\t\t\t\t\
    \tq.push(v), level[v] = level[u] + 1;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn level[t]\
    \ >= 0;\r\n\t}\r\n\r\n\tF dfs(int v, int t, F flow) {\r\n\t\tif (v == t)\r\n\t\
    \t\treturn flow;\r\n\t\tfor (; cur[v] != adj[v].end(); cur[v]++) {\r\n\t\t\tEdge&\
    \ e = edges[*cur[v]];\r\n\t\t\tif (level[e.to] != level[v] + 1 || e.flow == e.cap)\r\
    \n\t\t\t\tcontinue;\r\n\t\t\tF df = dfs(e.to, t, std::min(flow, e.cap - e.flow));\r\
    \n\t\t\tif (df) {\r\n\t\t\t\te.flow += df;\r\n\t\t\t\tedges[*cur[v] ^ 1].flow\
    \ -= df;\r\n\t\t\t\treturn df;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn 0;\r\n\t}\r\n\
    \t\r\n\tF max_flow(int s, int t) {\r\n\t\tF tot = 0;\r\n\t\twhile (bfs(s, t))\
    \ \r\n\t\t\twhile (F df = dfs(s, t, std::numeric_limits<F>::max())) \r\n\t\t\t\
    \ttot += df;\r\n\t\treturn tot;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/flows/dinic.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_6_A.test.cpp
  - verify/yosupo/yosupo-bipartitematching.test.cpp
documentation_of: library/graphs/flows/dinic.hpp
layout: document
redirect_from:
- /library/library/graphs/flows/dinic.hpp
- /library/library/graphs/flows/dinic.hpp.html
title: library/graphs/flows/dinic.hpp
---

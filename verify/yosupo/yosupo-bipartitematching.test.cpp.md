---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/dinic.hpp
    title: library/graphs/flows/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#define IGNORE\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class F> struct\
    \ Dinic {\r\n\tstruct Edge { int to; F flow, cap; };\r\n\tint n;\r\n\tstd::vector<Edge>\
    \ edges;\r\n\tstd::vector<std::vector<int>> adj;\r\n\tstd::vector<int> level;\r\
    \n\tstd::vector<std::vector<int>::iterator> cur;\r\n\r\n\tvoid init(int n_) {\r\
    \n\t\tn = n_;\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tcur.assign(n, std::vector<int>::iterator());\r\
    \n\t\tedges.clear();\r\n\t\tlevel.clear();\r\n\t}\r\n\r\n\tvoid ae(int u, int\
    \ v, F cap, F rcap = 0) {\r\n\t\tassert(std::min(cap, rcap) >= 0);\r\n\t\tadj[u].push_back((int)edges.size());\r\
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
    \ttot += df;\r\n\t\treturn tot;\r\n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tios_base::sync_with_stdio(0);\r\n\tint L, R; cin >> L >> R;\r\n\t\
    int M; cin >> M;\r\n\tDinic<int> D;\r\n\tD.init(L + R + 2);\r\n\tfor (int i =\
    \ 0; i < M; i++) {\r\n\t\tint u, v; \r\n\t\tcin >> u >> v;\r\n\t\tint x = u +\
    \ 1;\r\n\t\tint y = L + v + 1;\r\n\t\tD.ae(x, y, 1);\r\n\t}\r\n\tfor (int i =\
    \ 1; i <= L; i++) \r\n\t\tD.ae(0, i, 1);\r\n\tfor (int i = L + 1; i <= L + R;\
    \ i++) \r\n\t\tD.ae(i, L + R + 1, 1);\r\n\tcout << D.max_flow(0, L + R + 1) <<\
    \ '\\n';\r\n\tfor (int i = 1; i <= L; i++) {\r\n\t\tfor (auto& eid : D.adj[i])\
    \ {\r\n\t\t\tif (eid & 1)\r\n\t\t\t\tcontinue;\r\n\t\t\tauto& e = D.edges[eid];\r\
    \n\t\t\tif (e.cap == e.flow) {\r\n\t\t\t\tint u = i - 1;\r\n\t\t\t\tint v = e.to\
    \ - L - 1;\r\n\t\t\t\tcout << u << \" \" << v << '\\n';\r\n\t\t\t}\r\n\t\t}\r\n\
    \t}\r\n\treturn 0;\r\n}\n"
  code: "#define IGNORE\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/graphs/flows/dinic.hpp\"\r\n\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tios_base::sync_with_stdio(0);\r\n\tint L, R; cin >> L >> R;\r\n\t\
    int M; cin >> M;\r\n\tDinic<int> D;\r\n\tD.init(L + R + 2);\r\n\tfor (int i =\
    \ 0; i < M; i++) {\r\n\t\tint u, v; \r\n\t\tcin >> u >> v;\r\n\t\tint x = u +\
    \ 1;\r\n\t\tint y = L + v + 1;\r\n\t\tD.ae(x, y, 1);\r\n\t}\r\n\tfor (int i =\
    \ 1; i <= L; i++) \r\n\t\tD.ae(0, i, 1);\r\n\tfor (int i = L + 1; i <= L + R;\
    \ i++) \r\n\t\tD.ae(i, L + R + 1, 1);\r\n\tcout << D.max_flow(0, L + R + 1) <<\
    \ '\\n';\r\n\tfor (int i = 1; i <= L; i++) {\r\n\t\tfor (auto& eid : D.adj[i])\
    \ {\r\n\t\t\tif (eid & 1)\r\n\t\t\t\tcontinue;\r\n\t\t\tauto& e = D.edges[eid];\r\
    \n\t\t\tif (e.cap == e.flow) {\r\n\t\t\t\tint u = i - 1;\r\n\t\t\t\tint v = e.to\
    \ - L - 1;\r\n\t\t\t\tcout << u << \" \" << v << '\\n';\r\n\t\t\t}\r\n\t\t}\r\n\
    \t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/flows/dinic.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-bipartitematching.test.cpp
- /verify/verify/yosupo/yosupo-bipartitematching.test.cpp.html
title: verify/yosupo/yosupo-bipartitematching.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/dijkstra.hpp
    title: library/graphs/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class C, bool directed>\
    \ struct Dijkstra {\r\n\tint SZ; std::vector<C> dist;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ C>>> adj;\r\n\r\n\tvoid init(int _SZ) {\r\n\t\tSZ = _SZ;\r\n\t\tadj.clear();\r\
    \n\t\tadj.resize(SZ);\r\n\t}\r\n\r\n\tvoid ae(int u, int v, C cost) {\r\n\t\t\
    adj[u].emplace_back(v, cost);\r\n\t\tif (!directed) adj[v].emplace_back(u, cost);\r\
    \n\t}\r\n\r\n\tvoid gen(int st) {\r\n\t\tdist = std::vector<C>(SZ, std::numeric_limits<C>::max());\r\
    \n\t\ttypedef std::pair<C, int> T;\r\n\t\tstd::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> pq;\r\n\t\tauto ad = [&](int a, C b) {\r\n\t\t\tif (dist[a]\
    \ <= b) return;\r\n\t\t\tpq.push({dist[a] = b, a});\r\n\t\t};\r\n\t\tad(st, 0);\r\
    \n\t\twhile (!pq.empty()) {\r\n\t\t\tauto x = pq.top();\r\n\t\t\tpq.pop();\r\n\
    \t\t\tif (dist[x.second] < x.first) continue;\r\n\t\t\tfor (auto& y: adj[x.second])\
    \ {\r\n\t\t\t\tad(y.first, x.first + y.second);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    };\r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, m, r;\r\n\tcin >> n >> m >> r;\r\n\tDijkstra<long long, true> D;\r\n\
    \tD.init(n);\r\n\twhile (m--) {\r\n\t\tint u, v, w;\r\n\t\tcin >> u >> v >> w;\r\
    \n\t\tD.ae(u, v, w);\r\n\t}\r\n\tD.gen(r);\r\n\tfor (int i = 0; i < n; ++i) {\r\
    \n\t\tauto dist = D.dist[i];\r\n\t\tif (dist == numeric_limits<long long>::max())\
    \ {\r\n\t\t\tcout << \"INF\" << '\\n';\r\n\t\t} else {\r\n\t\t\tcout << dist <<\
    \ '\\n';\r\n\t\t}\r\n\t}\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/graphs/dijkstra.hpp\"\r\n\r\nint main() {\r\n\tusing namespace std;\r\
    \n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, m, r;\r\n\tcin >> n >> m >> r;\r\
    \n\tDijkstra<long long, true> D;\r\n\tD.init(n);\r\n\twhile (m--) {\r\n\t\tint\
    \ u, v, w;\r\n\t\tcin >> u >> v >> w;\r\n\t\tD.ae(u, v, w);\r\n\t}\r\n\tD.gen(r);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tauto dist = D.dist[i];\r\n\t\tif (dist\
    \ == numeric_limits<long long>::max()) {\r\n\t\t\tcout << \"INF\" << '\\n';\r\n\
    \t\t} else {\r\n\t\t\tcout << dist << '\\n';\r\n\t\t}\r\n\t}\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/dijkstra.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_1_A.test.cpp
- /verify/verify/aizu/aizu-GRL_1_A.test.cpp.html
title: verify/aizu/aizu-GRL_1_A.test.cpp
---

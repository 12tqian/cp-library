---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class C, bool directed> struct Dijkstra {\n\tint SZ; std::vector<C>\
    \ dist;\n\tstd::vector<std::vector<std::pair<int, C>>> adj;\n\n\tvoid init(int\
    \ _SZ) {\n\t\tSZ = _SZ;\n\t\tadj.clear();\n\t\tadj.resize(SZ);\n\t}\n\n\tvoid\
    \ ae(int u, int v, C cost) {\n\t\tadj[u].emplace_back(v, cost);\n\t\tif (!directed)\
    \ adj[v].emplace_back(u, cost);\n\t}\n\n\tvoid gen(int st) {\n\t\tdist = std::vector<C>(SZ,\
    \ std::numeric_limits<C>::max());\n\t\ttypedef std::pair<C, int> T;\n\t\tstd::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> pq;\n\t\tauto ad = [&](int a, C b) {\n\t\t\t\
    if (dist[a] <= b) return;\n\t\t\tpq.push({dist[a] = b, a});\n\t\t};\n\t\tad(st,\
    \ 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto x = pq.top();\n\t\t\tpq.pop();\n\t\
    \t\tif (dist[x.second] < x.first) continue;\n\t\t\tfor (auto &y: adj[x.second])\
    \ {\n\t\t\t\tad(y.first, x.first + y.second);\n\t\t\t}\n\t\t}\n\t}\n};\n\nint\
    \ main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n,\
    \ m, r;\n\tcin >> n >> m >> r;\n\tDijkstra<long long, true> D;\n\tD.init(n);\n\
    \twhile (m--) {\n\t\tint u, v, w;\n\t\tcin >> u >> v >> w;\n\t\tD.ae(u, v, w);\n\
    \t}\n\tD.gen(r);\n\tfor (int i = 0; i < n; ++i) {\n\t\tauto dist = D.dist[i];\n\
    \t\tif (dist == numeric_limits<long long>::max()) {\n\t\t\tcout << \"INF\" <<\
    \ '\\n';\n\t\t} else {\n\t\t\tcout << dist << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/dijkstra.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, m, r;\n\tcin >> n >> m >> r;\n\tDijkstra<long long, true> D;\n\tD.init(n);\n\
    \twhile (m--) {\n\t\tint u, v, w;\n\t\tcin >> u >> v >> w;\n\t\tD.ae(u, v, w);\n\
    \t}\n\tD.gen(r);\n\tfor (int i = 0; i < n; ++i) {\n\t\tauto dist = D.dist[i];\n\
    \t\tif (dist == numeric_limits<long long>::max()) {\n\t\t\tcout << \"INF\" <<\
    \ '\\n';\n\t\t} else {\n\t\t\tcout << dist << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/dijkstra.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_1_A.test.cpp
- /verify/verify/aizu/aizu-GRL_1_A.test.cpp.html
title: verify/aizu/aizu-GRL_1_A.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/bellman-ford.hpp
    title: Bellman Ford
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ BellmanFord {\r\n\tconst T INF = std::numeric_limits<T>::max();\r\n\tint n;\
    \ \r\n\tstd::vector<std::vector<int>> adj;\r\n\tstd::vector<std::pair<std::pair<int,\
    \ int>, T>> edges;\r\n\tstd::vector<T> dist;\r\n\r\n\tvoid init(int n_) {\r\n\t\
    \tn = n_;\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tedges.clear();\r\n\t\
    \tdist.assign(n, 0);\r\n\t}\r\n\r\n\tvoid ae(int u, int v, T w) {\r\n\t\tadj[u].push_back(v);\r\
    \n\t\tedges.push_back({{u, v}, w});\r\n\t}   \r\n\r\n\tvoid gen_bad(int x) {\r\
    \n\t\tif (dist[x] == -INF)\r\n\t\t\treturn;\r\n\t\tdist[x] = -INF;\r\n\t\tfor\
    \ (auto& nxt : adj[x])\r\n\t\t\tgen_bad(nxt);\r\n\t}\r\n\r\n\tvoid gen(int src)\
    \ {\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tdist[i] = INF;\r\n\t\tdist[src]\
    \ = 0;\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tfor (auto& e : edges) \r\n\t\
    \t\t\tif (dist[e.first.first] < INF)\r\n\t\t\t\t\tdist[e.first.second] = std::min(dist[e.first.second],\
    \ dist[e.first.first] + e.second);\r\n\t\tfor (auto& e : edges) \r\n\t\t\tif (dist[e.first.first]\
    \ < INF && dist[e.first.second] > dist[e.first.first] + e.second)\r\n\t\t\t\t\
    gen_bad(e.first.second);\r\n\t}\r\n\t\r\n\tstd::vector<int> negative_cycle(int\
    \ src = 0) {\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tdist[src] = INF;\r\n\t\
    \tdist[src] = 0;\r\n\t\tstd::vector<int> pre(n);\r\n\t\tfor (auto& e : edges)\
    \ \r\n\t\t\tif (e.first.first == e.first.second && e.second < 0) \r\n\t\t\t\t\
    return {e.first.first};\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tfor (auto&\
    \ e : edges) \r\n\t\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\t\t\tif (dist[e.first.second]\
    \ > dist[e.first.first] + e.second) {\r\n\t\t\t\t\t\tdist[e.first.second] = dist[e.first.first]\
    \ + e.second;\r\n\t\t\t\t\t\tpre[e.first.second] = e.first.first;\r\n\t\t\t\t\t\
    }\r\n\t\tfor (auto& e : edges) \r\n\t\t\tif (dist[e.first.first] < INF)\r\n\t\t\
    \t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\r\n\t\t\t\t\t\
    int x = e.first.second;\r\n\t\t\t\t\tfor (int i = 0; i < n; i++)\r\n\t\t\t\t\t\
    \tx = pre[x];\r\n\t\t\t\t\tstd::vector<int> cycle;\r\n\t\t\t\t\tfor (int v = x;\
    \ v != x || cycle.empty(); v = pre[v])\r\n\t\t\t\t\t\tcycle.push_back(v);\r\n\t\
    \t\t\t\treverse(cycle.begin(), cycle.end());\r\n\t\t\t\t\treturn cycle;\r\n\t\t\
    \t\t}\r\n\t\treturn {};\r\n\t}\r\n};\n\r\n// kattis\r\nint main() {\r\n\tusing\
    \ namespace std;\r\n\tint n, m, r;\r\n\tcin >> n >> m >> r;\r\n\tBellmanFord<long\
    \ long> B;\r\n\tB.init(n);\r\n\tfor (int i = 0; i < m; i++) {\r\n\t\tint u, v,\
    \ w; \r\n\t\tcin >> u >> v >> w;\r\n\t\tB.ae(u, v, w);\r\n\t}\r\n\tB.gen(r);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tif (B.dist[i] == -B.INF) {\r\n\t\t\t\
    cout << \"NEGATIVE CYCLE\" << '\\n';\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\t\
    for (int i = 0; i < n; ++i) {\r\n\t\tlong long dist = B.dist[i];\r\n\t\tif (dist\
    \ == B.INF) \r\n\t\t\tcout << \"INF\\n\";\r\n\t\telse if (dist == -B.INF)\r\n\t\
    \t\tassert(false);\r\n\t\telse \r\n\t\t\tcout << dist << '\\n';\r\n\t}\r\n\treturn\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/graphs/bellman-ford.hpp\"\r\n\r\n// kattis\r\nint main() {\r\n\t\
    using namespace std;\r\n\tint n, m, r;\r\n\tcin >> n >> m >> r;\r\n\tBellmanFord<long\
    \ long> B;\r\n\tB.init(n);\r\n\tfor (int i = 0; i < m; i++) {\r\n\t\tint u, v,\
    \ w; \r\n\t\tcin >> u >> v >> w;\r\n\t\tB.ae(u, v, w);\r\n\t}\r\n\tB.gen(r);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tif (B.dist[i] == -B.INF) {\r\n\t\t\t\
    cout << \"NEGATIVE CYCLE\" << '\\n';\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\t\
    for (int i = 0; i < n; ++i) {\r\n\t\tlong long dist = B.dist[i];\r\n\t\tif (dist\
    \ == B.INF) \r\n\t\t\tcout << \"INF\\n\";\r\n\t\telse if (dist == -B.INF)\r\n\t\
    \t\tassert(false);\r\n\t\telse \r\n\t\t\tcout << dist << '\\n';\r\n\t}\r\n\treturn\
    \ 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/bellman-ford.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_1_B.test.cpp
- /verify/verify/aizu/aizu-GRL_1_B.test.cpp.html
title: verify/aizu/aizu-GRL_1_B.test.cpp
---

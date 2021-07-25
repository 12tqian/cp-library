---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/bellman-ford.hpp
    title: library/graphs/bellman-ford.hpp
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
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    /**\n * dist is INF if you can't reach and -INF if it is in a negative cycle\n\
    \ * negative cycle is same thing as gen, it just doesn't do gen_bad\n * also it\
    \ returns a negative cycle :D\n */\n\ntemplate <class T> struct BellmanFord {\n\
    \tconst T INF = std::numeric_limits<T>::max();\n\tint n; \n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<std::pair<std::pair<int, int>, T>> edges;\n\tstd::vector<T>\
    \ dist;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tadj.assign(n, std::vector<int>());\n\
    \t\tedges.clear();\n\t\tdist.assign(n, 0);\n\t}\n\n\tvoid ae(int u, int v, T w)\
    \ {\n\t\tadj[u].push_back(v);\n\t\tedges.push_back({{u, v}, w});\n\t}   \n\n\t\
    void gen_bad(int x) {\n\t\tif (dist[x] == -INF)\n\t\t\treturn;\n\t\tdist[x] =\
    \ -INF;\n\t\tfor (auto &nxt : adj[x])\n\t\t\tgen_bad(nxt);\n\t}\n\n\tvoid gen(int\
    \ src) {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tdist[i] = INF;\n\t\tdist[src]\
    \ = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (auto &e : edges) \n\t\t\t\t\
    if (dist[e.first.first] < INF)\n\t\t\t\t\tdist[e.first.second] = std::min(dist[e.first.second],\
    \ dist[e.first.first] + e.second);\n\t\tfor (auto &e : edges) \n\t\t\tif (dist[e.first.first]\
    \ < INF && dist[e.first.second] > dist[e.first.first] + e.second)\n\t\t\tgen_bad(e.first.second);\n\
    \t}\n\t\n\tstd::vector<int> negative_cycle(int src = 0) {\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tdist[src] = INF;\n\t\tdist[src] = 0;\n\t\tstd::vector<int>\
    \ pre(n);\n\t\tfor (auto &e : edges) \n\t\t\tif (e.first.first == e.first.second\
    \ && e.second < 0) \n\t\t\t\treturn {e.first.first};\n\t\tfor (int i = 0; i <\
    \ n; i++) \n\t\t\tfor (auto &e : edges) \n\t\t\t\tif (dist[e.first.first] < INF)\n\
    \t\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\t\t\t\
    \t\t\tdist[e.first.second] = dist[e.first.first] + e.second;\n\t\t\t\t\t\tpre[e.first.second]\
    \ = e.first.first;\n\t\t\t\t\t}\n\t\tfor (auto &e : edges) \n\t\t\tif (dist[e.first.first]\
    \ < INF)\n\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\
    \t\t\t\t\tint x = e.first.second;\n\t\t\t\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \t\t\t\tx = pre[x];\n\t\t\t\t\tstd::vector<int> cycle;\n\t\t\t\t\tfor (int v =\
    \ x; v != x || cycle.empty(); v = pre[v])\n\t\t\t\t\t\tcycle.push_back(v);\n\t\
    \t\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\t\t\treturn cycle;\n\t\t\t\t\
    }\n\t\treturn {};\n\t}\n};\n\n// kattis\nint main() {\n\tusing namespace std;\n\
    \tint n, m, r;\n\tcin >> n >> m >> r;\n\tBellmanFord<long long> B;\n\tB.init(n);\n\
    \tfor (int i = 0; i < m; i++) {\n\t\tint u, v, w; \n\t\tcin >> u >> v >> w;\n\t\
    \tB.ae(u, v, w);\n\t}\n\tB.gen(r);\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (B.dist[i]\
    \ == -B.INF) {\n\t\t\tcout << \"NEGATIVE CYCLE\" << '\\n';\n\t\t\treturn 0;\n\t\
    \t}\n\t}\n\tfor (int i = 0; i < n; ++i) {\n\t\tlong long dist = B.dist[i];\n\t\
    \tif (dist == B.INF) \n\t\t\tcout << \"INF\\n\";\n\t\telse if (dist == -B.INF)\n\
    \t\t\tassert(false);\n\t\telse \n\t\t\tcout << dist << '\\n';\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/bellman-ford.hpp\"\
    \n\n// kattis\nint main() {\n\tusing namespace std;\n\tint n, m, r;\n\tcin >>\
    \ n >> m >> r;\n\tBellmanFord<long long> B;\n\tB.init(n);\n\tfor (int i = 0; i\
    \ < m; i++) {\n\t\tint u, v, w; \n\t\tcin >> u >> v >> w;\n\t\tB.ae(u, v, w);\n\
    \t}\n\tB.gen(r);\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (B.dist[i] == -B.INF)\
    \ {\n\t\t\tcout << \"NEGATIVE CYCLE\" << '\\n';\n\t\t\treturn 0;\n\t\t}\n\t}\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tlong long dist = B.dist[i];\n\t\tif (dist\
    \ == B.INF) \n\t\t\tcout << \"INF\\n\";\n\t\telse if (dist == -B.INF)\n\t\t\t\
    assert(false);\n\t\telse \n\t\t\tcout << dist << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/bellman-ford.hpp
  isVerificationFile: true
  path: test/bellman-ford.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 01:16:14-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bellman-ford.test.cpp
layout: document
redirect_from:
- /verify/test/bellman-ford.test.cpp
- /verify/test/bellman-ford.test.cpp.html
title: test/bellman-ford.test.cpp
---

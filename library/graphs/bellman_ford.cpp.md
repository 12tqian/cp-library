---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/bellman_ford.cpp\"\n#include <bits/stdc++.h>\n\
    /**\n * dist is INF if you can't reach and -INF if it is in a negative cycle\n\
    \ * negative cycle is same thing as gen, it just doesn't do gen_bad\n * also it\
    \ returns a negative cycle :D\n */\n\ntemplate <class T> struct BellmanFord {\n\
    \tconst T INF = std::numeric_limits<T>::max();\n\tint n; \n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<std::pair<std::pair<int, int>, T>> edges;\n\tstd::vector<T>\
    \ dist;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tadj.assign(n, std::vector<int>());\n\
    \t\tedges.clear();\n\t\tdist.assign(n, 0);\n\t}\n\n\tvoid ae(int u, int v, T w)\
    \ {\n\t\tadj[u].push_back(v);\n\t\tedges.push_back({{u, v}, w});\n\t}   \n\n\t\
    void gen_bad(int x) {\n\t\tif (dist[x] == -INF)\n\t\t\treturn;\n\t\tdist[x] =\
    \ -INF;\n\t\tfor (auto& nxt : adj[x])\n\t\t\tgen_bad(nxt);\n\t}\n\n\tvoid gen(int\
    \ src) {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tdist[i] = INF;\n\t\tdist[src]\
    \ = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (auto& e : edges) \n\t\t\t\t\
    if (dist[e.first.first] < INF)\n\t\t\t\t\tdist[e.first.second] = std::min(dist[e.first.second],\
    \ dist[e.first.first] + e.second);\n\t\tfor (auto& e : edges) \n\t\t\tif (dist[e.first.first]\
    \ < INF && dist[e.first.second] > dist[e.first.first] + e.second)\n\t\t\tgen_bad(e.first.second);\n\
    \t}\n\t\n\tstd::vector<int> negative_cycle(int src = 0) {\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tdist[src] = INF;\n\t\tdist[src] = 0;\n\t\tstd::vector<int>\
    \ pre(n);\n\t\tfor (auto& e : edges) \n\t\t\tif (e.first.first == e.first.second\
    \ && e.second < 0) \n\t\t\t\treturn {e.first.first};\n\t\tfor (int i = 0; i <\
    \ n; i++) \n\t\t\tfor (auto& e : edges) \n\t\t\t\tif (dist[e.first.first] < INF)\n\
    \t\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\t\t\t\
    \t\t\tdist[e.first.second] = dist[e.first.first] + e.second;\n\t\t\t\t\t\tpre[e.first.second]\
    \ = e.first.first;\n\t\t\t\t\t}\n\t\tfor (auto& e : edges) \n\t\t\tif (dist[e.first.first]\
    \ < INF)\n\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second) {\n\
    \t\t\t\t\tint x = e.first.second;\n\t\t\t\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \t\t\t\tx = pre[x];\n\t\t\t\t\tstd::vector<int> cycle;\n\t\t\t\t\tfor (int v =\
    \ x; v != x || cycle.empty(); v = pre[v])\n\t\t\t\t\t\tcycle.push_back(v);\n\t\
    \t\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\t\t\treturn cycle;\n\t\t\t\t\
    }\n\t\treturn {};\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\twhile (true)\
    \ {\n\t\tint n, m, q, s; cin >> n >> m >> q >> s;\n\t\tif (n == 0)\n\t\t\texit(0);\n\
    \t\tBellmanFord<long long> B;\n\t\tB.init(n);\n\t\tfor (int i = 0; i < m; i++)\
    \ {\n\t\t\tint u, v, w; cin >> u >> v >> w;\n\t\t\tB.ae(u, v, w);\n\t\t}\n\t\t\
    B.gen(s);\n\t\twhile (q--) {\n\t\t\tint x; cin >> x;\n\t\t\tlong long dist = B.dist[x];\n\
    \t\t\tif (dist == B.INF) \n\t\t\t\tcout << \"Impossible\\n\";\n\t\t\telse if (dist\
    \ == -B.INF)\n\t\t\t\tcout << \"-Infinity\\n\";\n\t\t\telse \n\t\t\t\tcout <<\
    \ B.dist[x] << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n/**\n * dist is INF if you can't reach and -INF\
    \ if it is in a negative cycle\n * negative cycle is same thing as gen, it just\
    \ doesn't do gen_bad\n * also it returns a negative cycle :D\n */\n\ntemplate\
    \ <class T> struct BellmanFord {\n\tconst T INF = std::numeric_limits<T>::max();\n\
    \tint n; \n\tstd::vector<std::vector<int>> adj;\n\tstd::vector<std::pair<std::pair<int,\
    \ int>, T>> edges;\n\tstd::vector<T> dist;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\
    \t\tadj.assign(n, std::vector<int>());\n\t\tedges.clear();\n\t\tdist.assign(n,\
    \ 0);\n\t}\n\n\tvoid ae(int u, int v, T w) {\n\t\tadj[u].push_back(v);\n\t\tedges.push_back({{u,\
    \ v}, w});\n\t}   \n\n\tvoid gen_bad(int x) {\n\t\tif (dist[x] == -INF)\n\t\t\t\
    return;\n\t\tdist[x] = -INF;\n\t\tfor (auto& nxt : adj[x])\n\t\t\tgen_bad(nxt);\n\
    \t}\n\n\tvoid gen(int src) {\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tdist[i]\
    \ = INF;\n\t\tdist[src] = 0;\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (auto&\
    \ e : edges) \n\t\t\t\tif (dist[e.first.first] < INF)\n\t\t\t\t\tdist[e.first.second]\
    \ = std::min(dist[e.first.second], dist[e.first.first] + e.second);\n\t\tfor (auto&\
    \ e : edges) \n\t\t\tif (dist[e.first.first] < INF && dist[e.first.second] > dist[e.first.first]\
    \ + e.second)\n\t\t\tgen_bad(e.first.second);\n\t}\n\t\n\tstd::vector<int> negative_cycle(int\
    \ src = 0) {\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tdist[src] = INF;\n\t\tdist[src]\
    \ = 0;\n\t\tstd::vector<int> pre(n);\n\t\tfor (auto& e : edges) \n\t\t\tif (e.first.first\
    \ == e.first.second && e.second < 0) \n\t\t\t\treturn {e.first.first};\n\t\tfor\
    \ (int i = 0; i < n; i++) \n\t\t\tfor (auto& e : edges) \n\t\t\t\tif (dist[e.first.first]\
    \ < INF)\n\t\t\t\t\tif (dist[e.first.second] > dist[e.first.first] + e.second)\
    \ {\n\t\t\t\t\t\tdist[e.first.second] = dist[e.first.first] + e.second;\n\t\t\t\
    \t\t\tpre[e.first.second] = e.first.first;\n\t\t\t\t\t}\n\t\tfor (auto& e : edges)\
    \ \n\t\t\tif (dist[e.first.first] < INF)\n\t\t\t\tif (dist[e.first.second] > dist[e.first.first]\
    \ + e.second) {\n\t\t\t\t\tint x = e.first.second;\n\t\t\t\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\t\t\t\tx = pre[x];\n\t\t\t\t\tstd::vector<int> cycle;\n\t\t\
    \t\t\tfor (int v = x; v != x || cycle.empty(); v = pre[v])\n\t\t\t\t\t\tcycle.push_back(v);\n\
    \t\t\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\t\t\treturn cycle;\n\t\t\t\
    \t}\n\t\treturn {};\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\twhile\
    \ (true) {\n\t\tint n, m, q, s; cin >> n >> m >> q >> s;\n\t\tif (n == 0)\n\t\t\
    \texit(0);\n\t\tBellmanFord<long long> B;\n\t\tB.init(n);\n\t\tfor (int i = 0;\
    \ i < m; i++) {\n\t\t\tint u, v, w; cin >> u >> v >> w;\n\t\t\tB.ae(u, v, w);\n\
    \t\t}\n\t\tB.gen(s);\n\t\twhile (q--) {\n\t\t\tint x; cin >> x;\n\t\t\tlong long\
    \ dist = B.dist[x];\n\t\t\tif (dist == B.INF) \n\t\t\t\tcout << \"Impossible\\\
    n\";\n\t\t\telse if (dist == -B.INF)\n\t\t\t\tcout << \"-Infinity\\n\";\n\t\t\t\
    else \n\t\t\t\tcout << B.dist[x] << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/bellman_ford.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/bellman_ford.cpp
layout: document
redirect_from:
- /library/library/graphs/bellman_ford.cpp
- /library/library/graphs/bellman_ford.cpp.html
title: library/graphs/bellman_ford.cpp
---

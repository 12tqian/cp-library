---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/dinic.hpp
    title: library/graphs/flows/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class F> struct Dinic {\n\tstruct Edge { int to; F flow, cap; };\n\
    \tint n;\n\tstd::vector<Edge> edges;\n\tstd::vector<std::vector<int>> adj;\n\t\
    std::vector<int> level;\n\tstd::vector<std::vector<int>::iterator> cur;\n\n\t\
    void init(int n_) {\n\t\tn = n_;\n\t\tadj.assign(n, std::vector<int>());\n\t\t\
    cur.assign(n, std::vector<int>::iterator());\n\t\tedges.clear();\n\t\tlevel.clear();\n\
    \t}\n\n\tvoid ae(int u, int v, F cap, F rcap = 0) {\n\t\tassert(std::min(cap,\
    \ rcap) >= 0);\n\t\tadj[u].push_back((int)edges.size());\n\t\tedges.push_back({v,\
    \ 0, cap});\n\t\tadj[v].push_back((int)edges.size());\n\t\tedges.push_back({u,\
    \ 0, rcap});\n\t}\n\n\tbool bfs(int s, int t) {\n\t\tlevel = std::vector<int>(n,\
    \ -1);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tcur[i] = adj[i].begin();\n\t\t\
    std::queue<int> q({s});\n\t\tlevel[s] = 0;\n\t\twhile (!q.empty()) {\n\t\t\tint\
    \ u = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& eid : adj[u]) {\n\t\t\t\tconst\
    \ Edge& e = edges[eid];\n\t\t\t\tint v = e.to;\n\t\t\t\tif (level[v] < 0 && e.flow\
    \ < e.cap) \n\t\t\t\t\tq.push(v), level[v] = level[u] + 1;\n\t\t\t}\n\t\t}\n\t\
    \treturn level[t] >= 0;\n\t}\n\n\tF dfs(int v, int t, F flow) {\n\t\tif (v ==\
    \ t)\n\t\t\treturn flow;\n\t\tfor (; cur[v] != adj[v].end(); cur[v]++) {\n\t\t\
    \tEdge& e = edges[*cur[v]];\n\t\t\tif (level[e.to] != level[v] + 1 || e.flow ==\
    \ e.cap)\n\t\t\t\tcontinue;\n\t\t\tF df = dfs(e.to, t, std::min(flow, e.cap -\
    \ e.flow));\n\t\t\tif (df) {\n\t\t\t\te.flow += df;\n\t\t\t\tedges[*cur[v] ^ 1].flow\
    \ -= df;\n\t\t\t\treturn df;\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\t\n\tF max_flow(int\
    \ s, int t) {\n\t\tF tot = 0;\n\t\twhile (bfs(s, t)) \n\t\t\twhile (F df = dfs(s,\
    \ t, std::numeric_limits<F>::max())) \n\t\t\t\ttot += df;\n\t\treturn tot;\n\t\
    }\n};\n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\
    \tint L, R; cin >> L >> R;\n\tint M; cin >> M;\n\tDinic<int> D;\n\tD.init(L +\
    \ R + 2);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; cin >> u >> v;\n\t\t\
    u--, v--;\n\t\tint x = u + 1;\n\t\tint y = L + v + 1;\n\t\tD.ae(x, y, 1);\n\t\
    }\n\tfor (int i = 1; i <= L; i++) \n\t\tD.ae(0, i, 1);\n\tfor (int i = L + 1;\
    \ i <= L + R; i++) \n\t\tD.ae(i, L + R + 1, 1);\n\tcout << D.max_flow(0, L + R\
    \ + 1) << '\\n';\n\tfor (int i = 1; i <= L; i++) {\n\t\tfor (auto& eid : D.adj[i])\
    \ {\n\t\t\tif (eid & 1)\n\t\t\t\tcontinue;\n\t\t\tauto& e = D.edges[eid];\n\t\t\
    \tif (e.cap == e.flow) {\n\t\t\t\tint u = i - 1;\n\t\t\t\tint v = e.to - L - 1;\n\
    \t\t\t\tcout << u << \" \" << v << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/flows/dinic.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    int L, R; cin >> L >> R;\n\tint M; cin >> M;\n\tDinic<int> D;\n\tD.init(L + R\
    \ + 2);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; cin >> u >> v;\n\t\tu--,\
    \ v--;\n\t\tint x = u + 1;\n\t\tint y = L + v + 1;\n\t\tD.ae(x, y, 1);\n\t}\n\t\
    for (int i = 1; i <= L; i++) \n\t\tD.ae(0, i, 1);\n\tfor (int i = L + 1; i <=\
    \ L + R; i++) \n\t\tD.ae(i, L + R + 1, 1);\n\tcout << D.max_flow(0, L + R + 1)\
    \ << '\\n';\n\tfor (int i = 1; i <= L; i++) {\n\t\tfor (auto& eid : D.adj[i])\
    \ {\n\t\t\tif (eid & 1)\n\t\t\t\tcontinue;\n\t\t\tauto& e = D.edges[eid];\n\t\t\
    \tif (e.cap == e.flow) {\n\t\t\t\tint u = i - 1;\n\t\t\t\tint v = e.to - L - 1;\n\
    \t\t\t\tcout << u << \" \" << v << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/flows/dinic.hpp
  isVerificationFile: false
  path: test/dinic-bipartite.cpp
  requiredBy: []
  timestamp: '2021-07-25 01:16:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/dinic-bipartite.cpp
layout: document
redirect_from:
- /library/test/dinic-bipartite.cpp
- /library/test/dinic-bipartite.cpp.html
title: test/dinic-bipartite.cpp
---

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
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class F>\r\nstruct\
    \ Dinic {\r\n  struct Edge {\r\n    int to;\r\n    F flow, cap;\r\n  };\r\n\r\n\
    \  int n;\r\n  std::vector<Edge> edges;\r\n  std::vector<std::vector<int>> adj;\r\
    \n  std::vector<int> level;\r\n  std::vector<std::vector<int>::iterator> cur;\r\
    \n\r\n  void init(int n_) {\r\n    n = n_;\r\n    adj.assign(n, std::vector<int>());\r\
    \n    cur.assign(n, std::vector<int>::iterator());\r\n    edges.clear();\r\n \
    \   level.clear();\r\n  }\r\n\r\n  int ae(int u, int v, F cap, F rcap = 0) {\r\
    \n    assert(std::min(cap, rcap) >= 0);\r\n    adj[u].push_back((int)edges.size());\r\
    \n    edges.push_back({v, 0, cap});\r\n    adj[v].push_back((int)edges.size());\r\
    \n    edges.push_back({u, 0, rcap});\r\n    return (int)edges.size() - 2;\r\n\
    \  }\r\n\r\n  bool bfs(int s, int t) {\r\n    level = std::vector<int>(n, -1);\r\
    \n    for (int i = 0; i < n; i++) cur[i] = adj[i].begin();\r\n    std::queue<int>\
    \ q({s});\r\n    level[s] = 0;\r\n    while (!q.empty()) {\r\n      int u = q.front();\r\
    \n      q.pop();\r\n      for (auto& eid : adj[u]) {\r\n        const Edge& e\
    \ = edges[eid];\r\n        int v = e.to;\r\n        if (level[v] < 0 && e.flow\
    \ < e.cap) q.push(v), level[v] = level[u] + 1;\r\n      }\r\n    }\r\n    return\
    \ level[t] >= 0;\r\n  }\r\n\r\n  F dfs(int v, int t, F flow) {\r\n    if (v ==\
    \ t) return flow;\r\n    for (; cur[v] != adj[v].end(); cur[v]++) {\r\n      Edge&\
    \ e = edges[*cur[v]];\r\n      if (level[e.to] != level[v] + 1 || e.flow == e.cap)\
    \ continue;\r\n      F df = dfs(e.to, t, std::min(flow, e.cap - e.flow));\r\n\
    \      if (df) {\r\n        e.flow += df;\r\n        edges[*cur[v] ^ 1].flow -=\
    \ df;\r\n        return df;\r\n      }\r\n    }\r\n    return 0;\r\n  }\r\n\r\n\
    \  F max_flow(int s, int t) {\r\n    F tot = 0;\r\n    while (bfs(s, t))\r\n \
    \     while (F df = dfs(s, t, std::numeric_limits<F>::max())) tot += df;\r\n \
    \   return tot;\r\n  }\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\t\
    ios_base::sync_with_stdio(0);\r\n\tint L, R; cin >> L >> R;\r\n\tint M; cin >>\
    \ M;\r\n\tDinic<int> D;\r\n\tD.init(L + R + 2);\r\n\tfor (int i = 0; i < M; i++)\
    \ {\r\n\t\tint u, v; \r\n\t\tcin >> u >> v;\r\n\t\tint x = u + 1;\r\n\t\tint y\
    \ = L + v + 1;\r\n\t\tD.ae(x, y, 1);\r\n\t}\r\n\tfor (int i = 1; i <= L; i++)\
    \ \r\n\t\tD.ae(0, i, 1);\r\n\tfor (int i = L + 1; i <= L + R; i++) \r\n\t\tD.ae(i,\
    \ L + R + 1, 1);\r\n\tcout << D.max_flow(0, L + R + 1) << '\\n';\r\n\tfor (int\
    \ i = 1; i <= L; i++) {\r\n\t\tfor (auto& eid : D.adj[i]) {\r\n\t\t\tif (eid &\
    \ 1)\r\n\t\t\t\tcontinue;\r\n\t\t\tauto& e = D.edges[eid];\r\n\t\t\tif (e.cap\
    \ == e.flow) {\r\n\t\t\t\tint u = i - 1;\r\n\t\t\t\tint v = e.to - L - 1;\r\n\t\
    \t\t\tcout << u << \" \" << v << '\\n';\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\n"
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
  timestamp: '2023-01-08 14:07:45-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-bipartitematching.test.cpp
- /verify/verify/yosupo/yosupo-bipartitematching.test.cpp.html
title: verify/yosupo/yosupo-bipartitematching.test.cpp
---

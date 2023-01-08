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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
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
    ios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n, m;\r\n\t\
    cin >> n >> m;\r\n\tDinic<long long> P;\r\n\tP.init(n);\r\n\tfor (int i = 0; i\
    \ < m; i++) {\r\n\t\tint u, v, w; \r\n\t\tcin >> u >> v >> w;\r\n\t\tP.ae(u, v,\
    \ w);\r\n\t}\r\n\tcout << P.max_flow(0, n - 1) << '\\n';\r\n\treturn 0;\r\n}\r\
    \n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/graphs/flows/dinic.hpp\"\r\n\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint\
    \ n, m;\r\n\tcin >> n >> m;\r\n\tDinic<long long> P;\r\n\tP.init(n);\r\n\tfor\
    \ (int i = 0; i < m; i++) {\r\n\t\tint u, v, w; \r\n\t\tcin >> u >> v >> w;\r\n\
    \t\tP.ae(u, v, w);\r\n\t}\r\n\tcout << P.max_flow(0, n - 1) << '\\n';\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/flows/dinic.hpp
  isVerificationFile: true
  path: verify/aizu/aizu-GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 14:07:45-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/aizu-GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/aizu-GRL_6_A.test.cpp
- /verify/verify/aizu/aizu-GRL_6_A.test.cpp.html
title: verify/aizu/aizu-GRL_6_A.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/graphs/strongly-connected-components-kosaraju.hpp
    title: library/graphs/strongly-connected-components-kosaraju.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n\r\n\
    #include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\
    \n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\
    \n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\
    \n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <set>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nusing namespace std;\n\r\nstruct SCC {\r\n\tint n; \r\n\tstd::vector<std::vector<int>>\
    \ g, rg, scc_graph, comps;\r\n\tstd::vector<int> id, ord, roots, topo_ord;\r\n\
    \tstd::vector<bool> vis;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tg.assign(n,\
    \ std::vector<int>());\r\n\t\trg.assign(n, std::vector<int>());\r\n\t\tscc_graph.assign(n,\
    \ std::vector<int>());\r\n\t\tcomps.assign(n, std::vector<int>());\r\n\t\tvis.assign(n,\
    \ false);\r\n\t\tid.assign(n, -1);\r\n\t\tord.clear();\r\n\t\troots.clear(); \
    \    \r\n\t\ttopo_ord.clear();  \r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\
    \tg[u].push_back(v);\r\n\t\trg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid dfs_order(int\
    \ u) {\r\n\t\tvis[u] = true;\r\n\t\tfor (auto& v : g[u]) {\r\n\t\t\tif (vis[v])\
    \ \r\n\t\t\t\tcontinue;\r\n\t\t\tdfs_order(v);\r\n\t\t}\r\n\t\tord.push_back(u);\r\
    \n\t}\r\n\r\n\tvoid dfs_color(int u, int c) {\r\n\t\tid[u] = c;\r\n\t\tfor (int&\
    \ v : rg[u]) \r\n\t\t\tif (id[v] == -1) \r\n\t\t\t\tdfs_color(v, c);\r\n\t}\r\n\
    \r\n\tvoid topological_sort() {\r\n\t\tstd::vector<int> in(n);\r\n\t\tstd::list<int>\
    \ todo;\r\n\t\tfor (int i = 0; i < n; ++i) \r\n\t\t\tfor (auto& j : scc_graph[i])\r\
    \n\t\t\t\t++in[j];\r\n\t\tfor (int i = 0; i < n; ++i)\r\n\t\t\tif (!in[i] && id[i]\
    \ == i)\r\n\t\t\t\ttodo.push_back(i);\r\n\t\twhile (!todo.empty()) {\r\n\t\t\t\
    int u = todo.front();\r\n\t\t\ttodo.pop_front();\r\n\t\t\ttopo_ord.push_back(u);\r\
    \n\t\t\tfor (auto& v : scc_graph[u]) \r\n\t\t\t\tif (!(--in[v])) \r\n\t\t\t\t\t\
    todo.push_back(v);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build_scc_graph() {\r\n\t\tfor\
    \ (int i = 0; i < n; ++i) {\r\n\t\t\tcomps[id[i]].push_back(i);\r\n\t\t\tfor (auto&\
    \ j : g[i]) {\r\n\t\t\t\tif (id[i] == id[j]) \r\n\t\t\t\t\tcontinue;\r\n\t\t\t\
    \tscc_graph[id[i]].push_back(id[j]);\r\n\t\t\t}\r\n\t\t}\r\n\t\ttopological_sort();\r\
    \n\t}\r\n\r\n\tvoid gen() {\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tif (!vis[i])\r\
    \n\t\t\t\tdfs_order(i);\r\n\t\t}\r\n\t\treverse(ord.begin(), ord.end());\r\n\t\
    \tfor (auto& x : ord) \r\n\t\t\tif (id[x] == -1) \r\n\t\t\t\tdfs_color(x, x),\
    \ roots.push_back(x);\r\n\t}\r\n};\r\n\r\nint main() {\r\n\tusing namespace std;\r\
    \n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, m; \r\n\tcin >> n >> m;\r\n\t\
    SCC S; S.init(n);\r\n\tfor (int i = 0; i < m; ++i) {\r\n\t\tint u, v;\r\n\t\t\
    cin >> u >> v;\r\n\t\tS.ae(u, v);\r\n\t}\r\n\tS.gen();\r\n\tS.build_scc_graph();\r\
    \n\tcout << S.roots.size() << '\\n';\r\n\tfor (auto &c : S.topo_ord) {\r\n\t\t\
    cout << S.comps[c].size() << \" \";\r\n\t\tfor (auto &x : S.comps[c]) \r\n\t\t\
    \tcout << x << \" \";\r\n\t\tcout << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include \"\
    ../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/strongly-connected-components-kosaraju.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, m; \r\n\tcin >> n >> m;\r\n\tSCC S; S.init(n);\r\n\tfor (int i = 0;\
    \ i < m; ++i) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tS.ae(u, v);\r\n\t\
    }\r\n\tS.gen();\r\n\tS.build_scc_graph();\r\n\tcout << S.roots.size() << '\\n';\r\
    \n\tfor (auto &c : S.topo_ord) {\r\n\t\tcout << S.comps[c].size() << \" \";\r\n\
    \t\tfor (auto &x : S.comps[c]) \r\n\t\t\tcout << x << \" \";\r\n\t\tcout << '\\\
    n';\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/strongly-connected-components-kosaraju.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-scc-kosaraju.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-scc-kosaraju.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-scc-kosaraju.test.cpp
- /verify/verify/yosupo/yosupo-scc-kosaraju.test.cpp.html
title: verify/yosupo/yosupo-scc-kosaraju.test.cpp
---

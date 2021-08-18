---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/strongly-connected-components-kosaraju.hpp
    title: library/graphs/strongly-connected-components-kosaraju.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nstruct SCC {\n\tint n; \n\tstd::vector<std::vector<int>> g, rg, scc_graph, comps;\n\
    \tstd::vector<int> id, ord, roots, topo_ord;\n\tstd::vector<bool> vis;\n\n\tvoid\
    \ init(int n_) {\n\t\tn = n_;\n\t\tg.assign(n, std::vector<int>());\n\t\trg.assign(n,\
    \ std::vector<int>());\n\t\tscc_graph.assign(n, std::vector<int>());\n\t\tcomps.assign(n,\
    \ std::vector<int>());\n\t\tvis.assign(n, false);\n\t\tid.assign(n, -1);\n\t\t\
    ord.clear();\n\t\troots.clear();     \n\t\ttopo_ord.clear();  \n\t}\n\n\tvoid\
    \ ae(int u, int v) {\n\t\tg[u].push_back(v);\n\t\trg[v].push_back(u);\n\t}\n\n\
    \tvoid dfs_order(int u) {\n\t\tvis[u] = true;\n\t\tfor (auto& v : g[u]) {\n\t\t\
    \tif (vis[v]) \n\t\t\t\tcontinue;\n\t\t\tdfs_order(v);\n\t\t}\n\t\tord.push_back(u);\n\
    \t}\n\n\tvoid dfs_color(int u, int c) {\n\t\tid[u] = c;\n\t\tfor (int& v : rg[u])\
    \ \n\t\t\tif (id[v] == -1) \n\t\t\t\tdfs_color(v, c);\n\t}\n\n\tvoid topological_sort()\
    \ {\n\t\tstd::vector<int> in(n);\n\t\tstd::list<int> todo;\n\t\tfor (int i = 0;\
    \ i < n; ++i) \n\t\t\tfor (auto& j : scc_graph[i])\n\t\t\t\t++in[j];\n\t\tfor\
    \ (int i = 0; i < n; ++i)\n\t\t\tif (!in[i] && id[i] == i)\n\t\t\t\ttodo.push_back(i);\n\
    \t\twhile (!todo.empty()) {\n\t\t\tint u = todo.front();\n\t\t\ttodo.pop_front();\n\
    \t\t\ttopo_ord.push_back(u);\n\t\t\tfor (auto& v : scc_graph[u]) \n\t\t\t\tif\
    \ (!(--in[v])) \n\t\t\t\t\ttodo.push_back(v);\n\t\t}\n\t}\n\n\tvoid build_scc_graph()\
    \ {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tcomps[id[i]].push_back(i);\n\t\t\
    \tfor (auto& j : g[i]) {\n\t\t\t\tif (id[i] == id[j]) \n\t\t\t\t\tcontinue;\n\t\
    \t\t\tscc_graph[id[i]].push_back(id[j]);\n\t\t\t}\n\t\t}\n\t\ttopological_sort();\n\
    \t}\n\n\tvoid gen() {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (!vis[i])\n\
    \t\t\t\tdfs_order(i);\n\t\t}\n\t\treverse(ord.begin(), ord.end());\n\t\tfor (auto&\
    \ x : ord) \n\t\t\tif (id[x] == -1) \n\t\t\t\tdfs_color(x, x), roots.push_back(x);\n\
    \t}\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, m; \n\tcin >> n >> m;\n\tSCC S; S.init(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tS.ae(u, v);\n\t}\n\tS.gen();\n\
    \tS.build_scc_graph();\n\tcout << S.roots.size() << '\\n';\n\tfor (auto &c : S.topo_ord)\
    \ {\n\t\tcout << S.comps[c].size() << \" \";\n\t\tfor (auto &x : S.comps[c]) \n\
    \t\t\tcout << x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/graphs/strongly-connected-components-kosaraju.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, m; \n\tcin >> n >> m;\n\tSCC S; S.init(n);\n\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tS.ae(u, v);\n\t}\n\tS.gen();\n\tS.build_scc_graph();\n\
    \tcout << S.roots.size() << '\\n';\n\tfor (auto &c : S.topo_ord) {\n\t\tcout <<\
    \ S.comps[c].size() << \" \";\n\t\tfor (auto &x : S.comps[c]) \n\t\t\tcout <<\
    \ x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/strongly-connected-components-kosaraju.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-scc-kosaraju.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-scc-kosaraju.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-scc-kosaraju.test.cpp
- /verify/verify/yosupo/yosupo-scc-kosaraju.test.cpp.html
title: verify/yosupo/yosupo-scc-kosaraju.test.cpp
---

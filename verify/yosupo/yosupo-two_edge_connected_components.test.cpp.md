---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/biconnected-components.hpp
    title: library/graphs/biconnected-components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nstruct BCC {\r\n\tint n,\
    \ time, num_comps; \r\n\tstd::vector<int> ord, low, id; \r\n\t// order encountered,\
    \ earliest time in subtree, component id\r\n\tstd::vector<std::vector<int>> adj,\
    \ comps, tree;\r\n\t// adj, comps storage, bridge block tree\r\n\tstd::vector<std::pair<int,\
    \ int>> bridge;\r\n\t// bridges\r\n\t\r\n\tvoid init(int n_) {\r\n\t\tnum_comps\
    \ = time = 0;\r\n\t\tn = n_;\r\n\t\tord.assign(n, -1);\r\n\t\tlow.assign(n, 0);\r\
    \n\t\tid.assign(n, -1);\r\n\t\tadj.assign(n, std::vector<int>());\r\n\t\tcomps.clear();\r\
    \n\t\ttree.clear();\r\n\t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\
    \n\t\tadj[v].push_back(u);\r\n\t}\r\n\r\n\tbool is_bridge(int u, int v) {\r\n\t\
    \tif (ord[u] > ord[v])\r\n\t\t\tstd::swap(u, v);\r\n\t\treturn ord[u] < low[v];\r\
    \n\t}\r\n\r\n\tvoid dfs(int src, int par) {\r\n\t\tord[src] = low[src] = time++;\r\
    \n\t\tbool bic = false; // accounts for double edges\r\n\t\tfor (int nxt : adj[src])\
    \ { \r\n\t\t\tif (nxt == par && !bic) {\r\n\t\t\t\tbic = true;\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tif (ord[nxt] != -1) {\r\n\t\t\t\tlow[src] = std::min(low[src],\
    \ ord[nxt]);\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs(nxt, src);\r\n\t\t\t\
    low[src] = std::min(low[src], low[nxt]);\r\n\t\t\tif (is_bridge(src, nxt))\r\n\
    \t\t\t\tbridge.emplace_back(src, nxt);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid fill_component(int\
    \ src) {\r\n\t\tcomps[id[src]].push_back(src);\r\n\t\tfor (int nxt : adj[src])\
    \ {\r\n\t\t\tif (id[nxt] != -1 || is_bridge(nxt, src))\r\n\t\t\t\tcontinue;\r\n\
    \t\t\tid[nxt] = id[src];\r\n\t\t\tfill_component(nxt);\r\n\t\t}\r\n\t}\r\n\r\n\
    \tvoid add_component(int src) {\r\n\t\tif (id[src] != -1)\r\n\t\t\treturn;\r\n\
    \t\tid[src] = num_comps++;\r\n\t\tcomps.emplace_back();\r\n\t\tfill_component(src);\r\
    \n\t}\r\n\t\r\n\tint build() {\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tif\
    \ (ord[i] == -1)\r\n\t\t\t\tdfs(i, -1);\r\n\t\tfor (int i = 0; i < n; i++) \r\n\
    \t\t\tadd_component(i);\r\n\t\ttree.resize(num_comps);\r\n\t\tfor (auto& b : bridge)\
    \ {\r\n\t\t\tint u = id[b.first];\r\n\t\t\tint v = id[b.second];\r\n\t\t\ttree[u].push_back(v);\r\
    \n\t\t\ttree[v].push_back(u);            \r\n\t\t}\r\n\t\treturn num_comps;\r\n\
    \t}\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\tios_base::sync_with_stdio(0);\r\
    \n\tint n, m; \r\n\tcin >> n >> m;\r\n\tBCC B; B.init(n);\r\n\tfor (int i = 0;\
    \ i < m ;i++) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\tB.ae(u, v);\r\n\t}\r\n\t\
    B.build();\r\n\tcout << B.num_comps << '\\n';\r\n\tfor (int i = 0; i < B.num_comps;\
    \ i++) {\r\n\t\tcout << (int)B.comps[i].size() << \" \";\r\n\t\tfor (int v : B.comps[i])\
    \ \r\n\t\t\tcout << v << \" \";\r\n\t\tcout << '\\n';\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/graphs/biconnected-components.hpp\"\r\n\r\nint main() {\r\n\tusing\
    \ namespace std;\r\n\tios_base::sync_with_stdio(0);\r\n\tint n, m; \r\n\tcin >>\
    \ n >> m;\r\n\tBCC B; B.init(n);\r\n\tfor (int i = 0; i < m ;i++) {\r\n\t\tint\
    \ u, v; cin >> u >> v;\r\n\t\tB.ae(u, v);\r\n\t}\r\n\tB.build();\r\n\tcout <<\
    \ B.num_comps << '\\n';\r\n\tfor (int i = 0; i < B.num_comps; i++) {\r\n\t\tcout\
    \ << (int)B.comps[i].size() << \" \";\r\n\t\tfor (int v : B.comps[i]) \r\n\t\t\
    \tcout << v << \" \";\r\n\t\tcout << '\\n';\r\n\t}\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/biconnected-components.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-two_edge_connected_components.test.cpp
- /verify/verify/yosupo/yosupo-two_edge_connected_components.test.cpp.html
title: verify/yosupo/yosupo-two_edge_connected_components.test.cpp
---

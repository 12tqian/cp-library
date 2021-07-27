---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nstruct BCC {\n\tint n, time, num_comps; \n\tstd::vector<int> ord, low, id; \n\
    \t// order encountered, earliest time in subtree, component id\n\tstd::vector<std::vector<int>>\
    \ adj, comps, tree;\n\t// adj, comps storage, bridge block tree\n\tstd::vector<std::pair<int,\
    \ int>> bridge;\n\t// bridges\n\t\n\tvoid init(int n_) {\n\t\tnum_comps = time\
    \ = 0;\n\t\tn = n_;\n\t\tord.assign(n, -1);\n\t\tlow.assign(n, 0);\n\t\tid.assign(n,\
    \ -1);\n\t\tadj.assign(n, std::vector<int>());\n\t\tcomps.clear();\n\t\ttree.clear();\n\
    \t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\t\tadj[v].push_back(u);\n\
    \t}\n\n\tbool is_bridge(int u, int v) {\n\t\tif (ord[u] > ord[v])\n\t\t\tstd::swap(u,\
    \ v);\n\t\treturn ord[u] < low[v];\n\t}\n\n\tvoid dfs(int src, int par) {\n\t\t\
    ord[src] = low[src] = time++;\n\t\tbool bic = false; // accounts for double edges\n\
    \t\tfor (int nxt : adj[src]) { \n\t\t\tif (nxt == par && !bic) {\n\t\t\t\tbic\
    \ = true;\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (ord[nxt] != -1) {\n\t\t\t\tlow[src]\
    \ = std::min(low[src], ord[nxt]);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tdfs(nxt,\
    \ src);\n\t\t\tlow[src] = std::min(low[src], low[nxt]);\n\t\t\tif (is_bridge(src,\
    \ nxt))\n\t\t\t\tbridge.emplace_back(src, nxt);\n\t\t}\n\t}\n\n\tvoid fill_component(int\
    \ src) {\n\t\tcomps[id[src]].push_back(src);\n\t\tfor (int nxt : adj[src]) {\n\
    \t\t\tif (id[nxt] != -1 || is_bridge(nxt, src))\n\t\t\t\tcontinue;\n\t\t\tid[nxt]\
    \ = id[src];\n\t\t\tfill_component(nxt);\n\t\t}\n\t}\n\n\tvoid add_component(int\
    \ src) {\n\t\tif (id[src] != -1)\n\t\t\treturn;\n\t\tid[src] = num_comps++;\n\t\
    \tcomps.emplace_back();\n\t\tfill_component(src);\n\t}\n\t\n\tint build() {\n\t\
    \tfor (int i = 0; i < n; i++) \n\t\t\tif (ord[i] == -1)\n\t\t\t\tdfs(i, -1);\n\
    \t\tfor (int i = 0; i < n; i++) \n\t\t\tadd_component(i);\n\t\ttree.resize(num_comps);\n\
    \t\tfor (auto &b : bridge) {\n\t\t\tint u = id[b.first];\n\t\t\tint v = id[b.second];\n\
    \t\t\ttree[u].push_back(v);\n\t\t\ttree[v].push_back(u);            \n\t\t}\n\t\
    \treturn num_comps;\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\
    \tint n, m; \n\tcin >> n >> m;\n\tBCC B; B.init(n);\n\tfor (int i = 0; i < m ;i++)\
    \ {\n\t\tint u, v; cin >> u >> v;\n\t\tB.ae(u, v);\n\t}\n\tB.build();\n\tcout\
    \ << B.num_comps << '\\n';\n\tfor (int i = 0; i < B.num_comps; i++) {\n\t\tcout\
    \ << (int)B.comps[i].size() << \" \";\n\t\tfor (int v : B.comps[i]) \n\t\t\tcout\
    \ << v << \" \";\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/biconnected-components.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios_base::sync_with_stdio(0);\n\t\
    int n, m; \n\tcin >> n >> m;\n\tBCC B; B.init(n);\n\tfor (int i = 0; i < m ;i++)\
    \ {\n\t\tint u, v; cin >> u >> v;\n\t\tB.ae(u, v);\n\t}\n\tB.build();\n\tcout\
    \ << B.num_comps << '\\n';\n\tfor (int i = 0; i < B.num_comps; i++) {\n\t\tcout\
    \ << (int)B.comps[i].size() << \" \";\n\t\tfor (int v : B.comps[i]) \n\t\t\tcout\
    \ << v << \" \";\n\t\tcout << '\\n';\n\t}\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/biconnected-components.hpp
  isVerificationFile: true
  path: test/biconnected-components.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 23:00:09-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/biconnected-components.test.cpp
layout: document
redirect_from:
- /verify/test/biconnected-components.test.cpp
- /verify/test/biconnected-components.test.cpp.html
title: test/biconnected-components.test.cpp
---
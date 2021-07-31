---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/strongly-connected-components-tarjan.hpp
    title: library/graphs/strongly-connected-components-tarjan.hpp
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
    \nstruct SCC {\n\tint n, time, num_comps;\n\tstd::vector<std::vector<int>> adj;\n\
    \tstd::vector<int> disc, id, stk;\n\tstd::vector<std::vector<int>> comps;\n\n\t\
    void init(int n_) {\n\t\tn = n_;\n\t\ttime = 0;\n\t\tnum_comps = 0;\n\t\tadj.assign(n,\
    \ std::vector<int>());\n\t\tid.assign(n, -1);\n\t\tdisc.assign(n, 0);\n\t\tcomps.clear();\n\
    \t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\t}\n\n\tint dfs(int\
    \ src) {\n\t\tint low = disc[src] = ++time;\n\t\tstk.push_back(src);\n\t\tfor\
    \ (int nxt : adj[src]) \n\t\t\tif (id[nxt] == -1)\n\t\t\t\tlow = std::min(low,\
    \ disc[nxt] ? : dfs(nxt));\n\t\tif (low == disc[src]) {\n\t\t\tfor (int nxt =\
    \ -1; nxt != src;)\n\t\t\t\tid[nxt = stk.back()] = num_comps, stk.pop_back();\n\
    \t\t\tnum_comps++;\n\t\t}\n\t\treturn low;\n\t}\n\t\n\tvoid build() {\n\t\t//\
    \ builds in topological order\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tif (!disc[i])\n\
    \t\t\t\tdfs(i);\n\t\tfor (auto &x : id) \n\t\t\tx = num_comps - 1 - x;\n\t\tcomps.resize(num_comps);\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tcomps[id[i]].push_back(i);\n\t}\n};\n\n\
    int main() {\n\tusing namespace std;\n\tint n, m; cin >> n >> m;\n\tSCC S;\n\t\
    S.init(n);\n\tfor (int i = 0; i < m; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\
    \t\tS.ae(u, v);\n\t}\n\tS.build();\n\tcout << S.num_comps << '\\n';\n\tfor (auto\
    \ &comp : S.comps) {\n\t\tcout << (int)comp.size() << \" \";\n\t\tfor (int &x\
    \ : comp)\n\t\t\tcout << x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/graphs/strongly-connected-components-tarjan.hpp\"\n\
    \nint main() {\n\tusing namespace std;\n\tint n, m; cin >> n >> m;\n\tSCC S;\n\
    \tS.init(n);\n\tfor (int i = 0; i < m; i++) {\n\t\tint u, v;\n\t\tcin >> u >>\
    \ v;\n\t\tS.ae(u, v);\n\t}\n\tS.build();\n\tcout << S.num_comps << '\\n';\n\t\
    for (auto &comp : S.comps) {\n\t\tcout << (int)comp.size() << \" \";\n\t\tfor\
    \ (int &x : comp)\n\t\t\tcout << x << \" \";\n\t\tcout << '\\n';\n\t}\n\treturn\
    \ 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/strongly-connected-components-tarjan.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-scc-tarjan.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-scc-tarjan.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-scc-tarjan.test.cpp
- /verify/verify/yosupo/yosupo-scc-tarjan.test.cpp.html
title: verify/yosupo/yosupo-scc-tarjan.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/graphs/strongly-connected-components-tarjan.hpp
    title: library/graphs/strongly-connected-components-tarjan.hpp
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
    \ <vector>\r\n\r\nusing namespace std;\n\r\nstruct SCC {\r\n\tint n, time, num_comps;\r\
    \n\tstd::vector<std::vector<int>> adj;\r\n\tstd::vector<int> disc, id, stk;\r\n\
    \tstd::vector<std::vector<int>> comps;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn =\
    \ n_;\r\n\t\ttime = 0;\r\n\t\tnum_comps = 0;\r\n\t\tadj.assign(n, std::vector<int>());\r\
    \n\t\tid.assign(n, -1);\r\n\t\tdisc.assign(n, 0);\r\n\t\tcomps.clear();\r\n\t\
    }\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\n\t}\r\n\r\n\t\
    int dfs(int src) {\r\n\t\tint low = disc[src] = ++time;\r\n\t\tstk.push_back(src);\r\
    \n\t\tfor (int nxt : adj[src]) \r\n\t\t\tif (id[nxt] == -1)\r\n\t\t\t\tlow = std::min(low,\
    \ disc[nxt] ? : dfs(nxt));\r\n\t\tif (low == disc[src]) {\r\n\t\t\tfor (int nxt\
    \ = -1; nxt != src;)\r\n\t\t\t\tid[nxt = stk.back()] = num_comps, stk.pop_back();\r\
    \n\t\t\tnum_comps++;\r\n\t\t}\r\n\t\treturn low;\r\n\t}\r\n\t\r\n\tvoid build()\
    \ {\r\n\t\t// builds in topological order\r\n\t\tfor (int i = 0; i < n; i++) \r\
    \n\t\t\tif (!disc[i])\r\n\t\t\t\tdfs(i);\r\n\t\tfor (auto& x : id) \r\n\t\t\t\
    x = num_comps - 1 - x;\r\n\t\tcomps.resize(num_comps);\r\n\t\tfor (int i = 0;\
    \ i < n; i++)\r\n\t\t\tcomps[id[i]].push_back(i);\r\n\t}\r\n};\n\r\nint main()\
    \ {\r\n\tusing namespace std;\r\n\tint n, m; cin >> n >> m;\r\n\tSCC S;\r\n\t\
    S.init(n);\r\n\tfor (int i = 0; i < m; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u\
    \ >> v;\r\n\t\tS.ae(u, v);\r\n\t}\r\n\tS.build();\r\n\tcout << S.num_comps <<\
    \ '\\n';\r\n\tfor (auto &comp : S.comps) {\r\n\t\tcout << (int)comp.size() <<\
    \ \" \";\r\n\t\tfor (int &x : comp)\r\n\t\t\tcout << x << \" \";\r\n\t\tcout <<\
    \ '\\n';\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include \"\
    ../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/strongly-connected-components-tarjan.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tint n, m; cin >> n >> m;\r\
    \n\tSCC S;\r\n\tS.init(n);\r\n\tfor (int i = 0; i < m; i++) {\r\n\t\tint u, v;\r\
    \n\t\tcin >> u >> v;\r\n\t\tS.ae(u, v);\r\n\t}\r\n\tS.build();\r\n\tcout << S.num_comps\
    \ << '\\n';\r\n\tfor (auto &comp : S.comps) {\r\n\t\tcout << (int)comp.size()\
    \ << \" \";\r\n\t\tfor (int &x : comp)\r\n\t\t\tcout << x << \" \";\r\n\t\tcout\
    \ << '\\n';\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/strongly-connected-components-tarjan.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-scc-tarjan.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-scc-tarjan.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-scc-tarjan.test.cpp
- /verify/verify/yosupo/yosupo-scc-tarjan.test.cpp.html
title: verify/yosupo/yosupo-scc-tarjan.test.cpp
---

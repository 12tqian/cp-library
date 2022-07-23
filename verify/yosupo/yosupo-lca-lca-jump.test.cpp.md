---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/graphs/lca-jump.hpp
    title: LCA Jump
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n\r\n\
    #include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\
    \n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\
    \n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\
    \n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <set>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nusing namespace std;\n\r\nstruct LCAJump {\r\n\tint n;\r\n\t\
    std::vector<std::vector<int>> par;\r\n\tstd::vector<std::vector<int>> adj;\r\n\
    \tstd::vector<int> depth;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    int d = 1;\r\n\t\twhile ((1 << d) < n) d++;\r\n\t\tpar.assign(d, std::vector<int>(n));\r\
    \n\t\tadj.resize(n);\r\n\t\tdepth.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int x, int\
    \ y) {\r\n\t\tadj[x].push_back(y);\r\n\t\tadj[y].push_back(x);\r\n\t}\r\n\r\n\t\
    void gen(int root = 0) {\r\n\t\tpar[0][root] = root;\r\n\t\tdfs(root);\r\n\t}\r\
    \n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor (int i = 1; i < (int)par.size(); i++)\
    \ {\r\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\r\n\t\t}\r\n\t\tfor (int\
    \ nxt : adj[src]) {\r\n\t\t\tif (nxt == par[0][src]) continue;\r\n\t\t\tdepth[nxt]\
    \ = depth[par[0][nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    int jump(int x, int d) {\r\n\t\tfor (int i = 0; i < (int)par.size(); i++) {\r\n\
    \t\t\tif ((d >> i) & 1) {\r\n\t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    return x;\r\n\t}\r\n\t\r\n\tint lca(int x, int y) {\r\n\t\tif (depth[x] < depth[y])\
    \ std::swap(x, y);\r\n\t\tx = jump(x, depth[x] - depth[y]);\r\n\t\tif (x == y)\
    \ return x;\r\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\r\n\t\t\t\
    int nx = par[i][x];\r\n\t\t\tint ny = par[i][y];\r\n\t\t\tif (nx != ny) x = nx,\
    \ y = ny;\r\n\t\t}\r\n\t\treturn par[0][x];\r\n\t}\r\n};\n\r\nint main() {\r\n\
    \tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, q; cin\
    \ >> n >> q;\r\n\tLCAJump L;\r\n\tL.init(n);\r\n\tfor (int i = 1; i < n; i++)\
    \ {\r\n\t\tint p; cin >> p;\r\n\t\tL.ae(i, p);\r\n\t}\r\n\tL.gen(0);\r\n\twhile\
    \ (q--) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\tcout << L.lca(u, v) << '\\n';\r\
    \n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    ../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/lca-jump.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; cin >> n >> q;\r\n\tLCAJump L;\r\n\tL.init(n);\r\n\tfor (int i =\
    \ 1; i < n; i++) {\r\n\t\tint p; cin >> p;\r\n\t\tL.ae(i, p);\r\n\t}\r\n\tL.gen(0);\r\
    \n\twhile (q--) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\tcout << L.lca(u, v) <<\
    \ '\\n';\r\n\t}\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/lca-jump.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-lca-lca-jump.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-lca-lca-jump.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-lca-lca-jump.test.cpp
- /verify/verify/yosupo/yosupo-lca-lca-jump.test.cpp.html
title: verify/yosupo/yosupo-lca-lca-jump.test.cpp
---

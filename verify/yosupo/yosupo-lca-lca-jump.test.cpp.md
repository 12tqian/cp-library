---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nstruct LCAJump {\n\tint n;\n\tstd::vector<std::vector<int>> par;\n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> depth;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\t\
    int d = 1;\n\t\twhile ((1 << d) < n) d++;\n\t\tpar.assign(d, std::vector<int>(n));\n\
    \t\tadj.resize(n);\n\t\tdepth.resize(n);\n\t}\n\n\tvoid ae(int x, int y) {\n\t\
    \tadj[x].push_back(y);\n\t\tadj[y].push_back(x);\n\t}\n\n\tvoid gen(int root =\
    \ 0) {\n\t\tpar[0][root] = root;\n\t\tdfs(root);\n\t}\n\n\tvoid dfs(int src =\
    \ 0) {\n\t\tfor (int i = 1; i < (int)par.size(); i++) {\n\t\t\tpar[i][src] = par[i\
    \ - 1][par[i - 1][src]];\n\t\t}\n\t\tfor (int nxt : adj[src]) {\n\t\t\tif (nxt\
    \ == par[0][src]) continue;\n\t\t\tdepth[nxt] = depth[par[0][nxt] = src] + 1;\n\
    \t\t\tdfs(nxt);\n\t\t}\n\t}\n\n\tint jump(int x, int d) {\n\t\tfor (int i = 0;\
    \ i < (int)par.size(); i++) {\n\t\t\tif ((d >> i) & 1) {\n\t\t\t\tx = par[i][x];\n\
    \t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\t\n\tint lca(int x, int y) {\n\t\tif (depth[x]\
    \ < depth[y]) std::swap(x, y);\n\t\tx = jump(x, depth[x] - depth[y]);\n\t\tif\
    \ (x == y) return x;\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\n\t\
    \t\tint nx = par[i][x];\n\t\t\tint ny = par[i][y];\n\t\t\tif (nx != ny) x = nx,\
    \ y = ny;\n\t\t}\n\t\treturn par[0][x];\n\t}\n};\n\nint main() {\n\tusing namespace\
    \ std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tLCAJump\
    \ L;\n\tL.init(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint p; cin >> p;\n\t\t\
    L.ae(i, p);\n\t}\n\tL.gen(0);\n\twhile (q--) {\n\t\tint u, v; cin >> u >> v;\n\
    \t\tcout << L.lca(u, v) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/graphs/lca-jump.hpp\"\n\nint main() {\n\tusing namespace\
    \ std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tLCAJump\
    \ L;\n\tL.init(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint p; cin >> p;\n\t\t\
    L.ae(i, p);\n\t}\n\tL.gen(0);\n\twhile (q--) {\n\t\tint u, v; cin >> u >> v;\n\
    \t\tcout << L.lca(u, v) << '\\n';\n\t}\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/lca-jump.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-lca-lca-jump.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 01:53:36-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-lca-lca-jump.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-lca-lca-jump.test.cpp
- /verify/verify/yosupo/yosupo-lca-lca-jump.test.cpp.html
title: verify/yosupo/yosupo-lca-lca-jump.test.cpp
---

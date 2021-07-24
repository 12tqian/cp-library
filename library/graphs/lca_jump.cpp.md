---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/lca_jump.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * To support forest, call gen for each roots\n */\nstruct LCAJump {\n\t\
    int n;\n\tstd::vector<std::vector<int>> par;\n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> depth;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\t\
    int d = 1;\n\t\twhile ((1 << d) < n) d++;\n\t\tpar.assign(d, std::vector<int>(n));\n\
    \t\tadj.resize(n);\n\t\tdepth.resize(n);\n\t}\n\n\tvoid ae(int x, int y) {\n\t\
    \tadj[x].push_back(y);\n\t\tadj[y].push_back(x);\n\t}\n\n\tvoid gen(int root =\
    \ 0) {\n\t\tpar[0][root] = root;\n\t\tdfs(root);\n\t}\n\n\tvoid dfs(int src =\
    \ 0) {\n\t\tfor (int i = 1; i < (int)par.size(); i++) {\n\t\t\tpar[i][src] = par[i\
    \ - 1][par[i - 1][src]];\n\t\t}\n\t\tfor (int nxt: adj[src]) {\n\t\t\tif (nxt\
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
  code: "#include <bits/stdc++.h>\n\n/**\n * To support forest, call gen for each\
    \ roots\n */\nstruct LCAJump {\n\tint n;\n\tstd::vector<std::vector<int>> par;\n\
    \tstd::vector<std::vector<int>> adj;\n\tstd::vector<int> depth;\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\tint d = 1;\n\t\twhile ((1 << d) < n) d++;\n\t\tpar.assign(d,\
    \ std::vector<int>(n));\n\t\tadj.resize(n);\n\t\tdepth.resize(n);\n\t}\n\n\tvoid\
    \ ae(int x, int y) {\n\t\tadj[x].push_back(y);\n\t\tadj[y].push_back(x);\n\t}\n\
    \n\tvoid gen(int root = 0) {\n\t\tpar[0][root] = root;\n\t\tdfs(root);\n\t}\n\n\
    \tvoid dfs(int src = 0) {\n\t\tfor (int i = 1; i < (int)par.size(); i++) {\n\t\
    \t\tpar[i][src] = par[i - 1][par[i - 1][src]];\n\t\t}\n\t\tfor (int nxt: adj[src])\
    \ {\n\t\t\tif (nxt == par[0][src]) continue;\n\t\t\tdepth[nxt] = depth[par[0][nxt]\
    \ = src] + 1;\n\t\t\tdfs(nxt);\n\t\t}\n\t}\n\n\tint jump(int x, int d) {\n\t\t\
    for (int i = 0; i < (int)par.size(); i++) {\n\t\t\tif ((d >> i) & 1) {\n\t\t\t\
    \tx = par[i][x];\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\t\n\tint lca(int x, int\
    \ y) {\n\t\tif (depth[x] < depth[y]) std::swap(x, y);\n\t\tx = jump(x, depth[x]\
    \ - depth[y]);\n\t\tif (x == y) return x;\n\t\tfor (int i = (int)par.size() -\
    \ 1; i >= 0; i--) {\n\t\t\tint nx = par[i][x];\n\t\t\tint ny = par[i][y];\n\t\t\
    \tif (nx != ny) x = nx, y = ny;\n\t\t}\n\t\treturn par[0][x];\n\t}\n};\n\nint\
    \ main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n,\
    \ q; cin >> n >> q;\n\tLCAJump L;\n\tL.init(n);\n\tfor (int i = 1; i < n; i++)\
    \ {\n\t\tint p; cin >> p;\n\t\tL.ae(i, p);\n\t}\n\tL.gen(0);\n\twhile (q--) {\n\
    \t\tint u, v; cin >> u >> v;\n\t\tcout << L.lca(u, v) << '\\n';\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca_jump.cpp
  requiredBy: []
  timestamp: '2021-07-10 12:34:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/lca_jump.cpp
layout: document
redirect_from:
- /library/library/graphs/lca_jump.cpp
- /library/library/graphs/lca_jump.cpp.html
title: library/graphs/lca_jump.cpp
---

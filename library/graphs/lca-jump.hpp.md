---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-lca-lca-jump.test.cpp
    title: verify/yosupo/yosupo-lca-lca-jump.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\nstruct LCAJump {\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ par;\r\n\tstd::vector<std::vector<int>> adj;\r\n\tstd::vector<int> depth;\r\n\
    \r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\tint d = 1;\r\n\t\twhile ((1 <<\
    \ d) < n) d++;\r\n\t\tpar.assign(d, std::vector<int>(n));\r\n\t\tadj.resize(n);\r\
    \n\t\tdepth.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int x, int y) {\r\n\t\tadj[x].push_back(y);\r\
    \n\t\tadj[y].push_back(x);\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[0][root]\
    \ = root;\r\n\t\tdfs(root);\r\n\t}\r\n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor\
    \ (int i = 1; i < (int)par.size(); i++) {\r\n\t\t\tpar[i][src] = par[i - 1][par[i\
    \ - 1][src]];\r\n\t\t}\r\n\t\tfor (int nxt : adj[src]) {\r\n\t\t\tif (nxt == par[0][src])\
    \ continue;\r\n\t\t\tdepth[nxt] = depth[par[0][nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint jump(int x, int d) {\r\n\t\tfor (int i = 0; i < (int)par.size();\
    \ i++) {\r\n\t\t\tif ((d >> i) & 1) {\r\n\t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn x;\r\n\t}\r\n\t\r\n\tint lca(int x, int y) {\r\n\t\tif (depth[x]\
    \ < depth[y]) std::swap(x, y);\r\n\t\tx = jump(x, depth[x] - depth[y]);\r\n\t\t\
    if (x == y) return x;\r\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\r\
    \n\t\t\tint nx = par[i][x];\r\n\t\t\tint ny = par[i][y];\r\n\t\t\tif (nx != ny)\
    \ x = nx, y = ny;\r\n\t\t}\r\n\t\treturn par[0][x];\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nstruct LCAJump {\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ par;\r\n\tstd::vector<std::vector<int>> adj;\r\n\tstd::vector<int> depth;\r\n\
    \r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\tint d = 1;\r\n\t\twhile ((1 <<\
    \ d) < n) d++;\r\n\t\tpar.assign(d, std::vector<int>(n));\r\n\t\tadj.resize(n);\r\
    \n\t\tdepth.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int x, int y) {\r\n\t\tadj[x].push_back(y);\r\
    \n\t\tadj[y].push_back(x);\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[0][root]\
    \ = root;\r\n\t\tdfs(root);\r\n\t}\r\n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor\
    \ (int i = 1; i < (int)par.size(); i++) {\r\n\t\t\tpar[i][src] = par[i - 1][par[i\
    \ - 1][src]];\r\n\t\t}\r\n\t\tfor (int nxt : adj[src]) {\r\n\t\t\tif (nxt == par[0][src])\
    \ continue;\r\n\t\t\tdepth[nxt] = depth[par[0][nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint jump(int x, int d) {\r\n\t\tfor (int i = 0; i < (int)par.size();\
    \ i++) {\r\n\t\t\tif ((d >> i) & 1) {\r\n\t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn x;\r\n\t}\r\n\t\r\n\tint lca(int x, int y) {\r\n\t\tif (depth[x]\
    \ < depth[y]) std::swap(x, y);\r\n\t\tx = jump(x, depth[x] - depth[y]);\r\n\t\t\
    if (x == y) return x;\r\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\r\
    \n\t\t\tint nx = par[i][x];\r\n\t\t\tint ny = par[i][y];\r\n\t\t\tif (nx != ny)\
    \ x = nx, y = ny;\r\n\t\t}\r\n\t\treturn par[0][x];\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca-jump.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-lca-lca-jump.test.cpp
documentation_of: library/graphs/lca-jump.hpp
layout: document
title: LCA Jump
---

## LCA Jump

### Functions
- `init(n)`: Initializes variables
- `gen(root)`: Generates from $root$, can easily change to vector for forests. Just repeat `gen`$ for each root. Does this in $\mathcal O(n \log (n))$.
- `jump(x, d)`: Jump $d$ upwards from node $x$ in $\mathcal O(\log n)$. 
- `lca(x, y)`: Lowest common ancestor of $x, y$ in $\mathcal O(\log n)$. 


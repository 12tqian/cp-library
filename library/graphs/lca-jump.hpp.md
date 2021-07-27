---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lca-jump.test.cpp
    title: test/lca-jump.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n/**\n * To support forest, call gen for each roots\n */\nstruct\
    \ LCAJump {\n\tint n;\n\tstd::vector<std::vector<int>> par;\n\tstd::vector<std::vector<int>>\
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
    \ y = ny;\n\t\t}\n\t\treturn par[0][x];\n\t}\n};\n"
  code: "#pragma once\n\n/**\n * To support forest, call gen for each roots\n */\n\
    struct LCAJump {\n\tint n;\n\tstd::vector<std::vector<int>> par;\n\tstd::vector<std::vector<int>>\
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
    \ y = ny;\n\t\t}\n\t\treturn par[0][x];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca-jump.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:29:57-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lca-jump.test.cpp
documentation_of: library/graphs/lca-jump.hpp
layout: document
redirect_from:
- /library/library/graphs/lca-jump.hpp
- /library/library/graphs/lca-jump.hpp.html
title: library/graphs/lca-jump.hpp
---
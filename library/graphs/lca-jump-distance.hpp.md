---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-QTREE2.test.cpp
    title: verify/spoj/spoj-QTREE2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate<class T> struct LCAJumpDistance {\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ par;\r\n\tstd::vector<std::vector<std::pair<int, T>>> adj;\r\n\tstd::vector<int>\
    \ depth;\r\n\tstd::vector<T> depth_dist;\r\n\r\n\tvoid init(int _n) {\r\n\t\t\
    n = _n;\r\n\t\tint d = 1;\r\n\t\twhile ((1 << d) < n) d++;\r\n\t\tpar.assign(d,\
    \ std::vector<int>(n));\r\n\t\tadj.resize(n);\r\n\t\tdepth.resize(n);\r\n\t\t\
    depth_dist.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int x, int y, T c = 1) {\r\n\t\t\
    adj[x].emplace_back(y, c);\r\n\t\tadj[y].emplace_back(x, c);\r\n\t}\r\n\r\n\t\
    void gen(int root = 0) {\r\n\t\tpar[0][root] = root;\r\n\t\tdfs(root);\r\n\t}\r\
    \n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor (int i = 1; i < (int)par.size(); i++)\
    \ {\r\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\r\n\t\t}\r\n\t\tfor (auto\
    \ nxt: adj[src]) {\r\n\t\t\tif (nxt.first == par[0][src]) continue;\r\n\t\t\t\
    depth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src] + nxt.second;\r\n\t\
    \t\tdepth[nxt.first] = depth[par[0][nxt.first] = src] + 1;\r\n\t\t\tdfs(nxt.first);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint jump(int x, int d) {\r\n\t\tfor (int i = 0; i < (int)par.size();\
    \ i++) {\r\n\t\t\tif ((d >> i) & 1) {\r\n\t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn x;\r\n\t}\r\n\r\n\tint lca(int x, int y) {\r\n\t\tif (depth[x]\
    \ < depth[y]) std::swap(x, y);\r\n\t\tx = jump(x, depth[x] - depth[y]);\r\n\t\t\
    if (x == y) return x;\r\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\r\
    \n\t\t\tint nx = par[i][x];\r\n\t\t\tint ny = par[i][y];\r\n\t\t\tif (nx != ny)\
    \ x = nx, y = ny;\r\n\t\t}\r\n\t\treturn par[0][x];\r\n\t}\r\n\r\n\tT distance(int\
    \ x, int y) {\r\n\t\tint l = lca(x, y);\r\n\t\treturn depth_dist[x] + depth_dist[y]\
    \ - 2 * depth_dist[l];\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class T> struct LCAJumpDistance {\r\n\tint n;\r\
    \n\tstd::vector<std::vector<int>> par;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ T>>> adj;\r\n\tstd::vector<int> depth;\r\n\tstd::vector<T> depth_dist;\r\n\r\
    \n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\tint d = 1;\r\n\t\twhile ((1 << d)\
    \ < n) d++;\r\n\t\tpar.assign(d, std::vector<int>(n));\r\n\t\tadj.resize(n);\r\
    \n\t\tdepth.resize(n);\r\n\t\tdepth_dist.resize(n);\r\n\t}\r\n\r\n\tvoid ae(int\
    \ x, int y, T c = 1) {\r\n\t\tadj[x].emplace_back(y, c);\r\n\t\tadj[y].emplace_back(x,\
    \ c);\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[0][root] = root;\r\n\
    \t\tdfs(root);\r\n\t}\r\n\r\n\tvoid dfs(int src = 0) {\r\n\t\tfor (int i = 1;\
    \ i < (int)par.size(); i++) {\r\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\r\
    \n\t\t}\r\n\t\tfor (auto nxt: adj[src]) {\r\n\t\t\tif (nxt.first == par[0][src])\
    \ continue;\r\n\t\t\tdepth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src]\
    \ + nxt.second;\r\n\t\t\tdepth[nxt.first] = depth[par[0][nxt.first] = src] + 1;\r\
    \n\t\t\tdfs(nxt.first);\r\n\t\t}\r\n\t}\r\n\r\n\tint jump(int x, int d) {\r\n\t\
    \tfor (int i = 0; i < (int)par.size(); i++) {\r\n\t\t\tif ((d >> i) & 1) {\r\n\
    \t\t\t\tx = par[i][x];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n\r\n\tint\
    \ lca(int x, int y) {\r\n\t\tif (depth[x] < depth[y]) std::swap(x, y);\r\n\t\t\
    x = jump(x, depth[x] - depth[y]);\r\n\t\tif (x == y) return x;\r\n\t\tfor (int\
    \ i = (int)par.size() - 1; i >= 0; i--) {\r\n\t\t\tint nx = par[i][x];\r\n\t\t\
    \tint ny = par[i][y];\r\n\t\t\tif (nx != ny) x = nx, y = ny;\r\n\t\t}\r\n\t\t\
    return par[0][x];\r\n\t}\r\n\r\n\tT distance(int x, int y) {\r\n\t\tint l = lca(x,\
    \ y);\r\n\t\treturn depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\r\n\t}\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca-jump-distance.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-QTREE2.test.cpp
documentation_of: library/graphs/lca-jump-distance.hpp
layout: document
redirect_from:
- /library/library/graphs/lca-jump-distance.hpp
- /library/library/graphs/lca-jump-distance.hpp.html
title: library/graphs/lca-jump-distance.hpp
---

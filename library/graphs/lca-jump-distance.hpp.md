---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\ntemplate<class T> struct LCAJumpDistance {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ par;\n\tstd::vector<std::vector<std::pair<int, T>>> adj;\n\tstd::vector<int>\
    \ depth;\n\tstd::vector<T> depth_dist;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\
    \t\tint d = 1;\n\t\twhile ((1 << d) < n) d++;\n\t\tpar.assign(d, std::vector<int>(n));\n\
    \t\tadj.resize(n);\n\t\tdepth.resize(n);\n\t\tdepth_dist.resize(n);\n\t}\n\n\t\
    void ae(int x, int y, T c = 1) {\n\t\tadj[x].emplace_back(y, c);\n\t\tadj[y].emplace_back(x,\
    \ c);\n\t}\n\n\tvoid gen(int root = 0) {\n\t\tpar[0][root] = root;\n\t\tdfs(root);\n\
    \t}\n\n\tvoid dfs(int src = 0) {\n\t\tfor (int i = 1; i < (int)par.size(); i++)\
    \ {\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\n\t\t}\n\t\tfor (auto nxt:\
    \ adj[src]) {\n\t\t\tif (nxt.first == par[0][src]) continue;\n\t\t\tdepth_dist[nxt.first]\
    \ = depth_dist[par[0][nxt.first] = src] + nxt.second;\n\t\t\tdepth[nxt.first]\
    \ = depth[par[0][nxt.first] = src] + 1;\n\t\t\tdfs(nxt.first);\n\t\t}\n\t}\n\n\
    \tint jump(int x, int d) {\n\t\tfor (int i = 0; i < (int)par.size(); i++) {\n\t\
    \t\tif ((d >> i) & 1) {\n\t\t\t\tx = par[i][x];\n\t\t\t}\n\t\t}\n\t\treturn x;\n\
    \t}\n\n\tint lca(int x, int y) {\n\t\tif (depth[x] < depth[y]) std::swap(x, y);\n\
    \t\tx = jump(x, depth[x] - depth[y]);\n\t\tif (x == y) return x;\n\t\tfor (int\
    \ i = (int)par.size() - 1; i >= 0; i--) {\n\t\t\tint nx = par[i][x];\n\t\t\tint\
    \ ny = par[i][y];\n\t\t\tif (nx != ny) x = nx, y = ny;\n\t\t}\n\t\treturn par[0][x];\n\
    \t}\n\n\tT distance(int x, int y) {\n\t\tint l = lca(x, y);\n\t\treturn depth_dist[x]\
    \ + depth_dist[y] - 2 * depth_dist[l];\n\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T> struct LCAJumpDistance {\n\tint n;\n\t\
    std::vector<std::vector<int>> par;\n\tstd::vector<std::vector<std::pair<int, T>>>\
    \ adj;\n\tstd::vector<int> depth;\n\tstd::vector<T> depth_dist;\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\tint d = 1;\n\t\twhile ((1 << d) < n) d++;\n\t\tpar.assign(d,\
    \ std::vector<int>(n));\n\t\tadj.resize(n);\n\t\tdepth.resize(n);\n\t\tdepth_dist.resize(n);\n\
    \t}\n\n\tvoid ae(int x, int y, T c = 1) {\n\t\tadj[x].emplace_back(y, c);\n\t\t\
    adj[y].emplace_back(x, c);\n\t}\n\n\tvoid gen(int root = 0) {\n\t\tpar[0][root]\
    \ = root;\n\t\tdfs(root);\n\t}\n\n\tvoid dfs(int src = 0) {\n\t\tfor (int i =\
    \ 1; i < (int)par.size(); i++) {\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\n\
    \t\t}\n\t\tfor (auto nxt: adj[src]) {\n\t\t\tif (nxt.first == par[0][src]) continue;\n\
    \t\t\tdepth_dist[nxt.first] = depth_dist[par[0][nxt.first] = src] + nxt.second;\n\
    \t\t\tdepth[nxt.first] = depth[par[0][nxt.first] = src] + 1;\n\t\t\tdfs(nxt.first);\n\
    \t\t}\n\t}\n\n\tint jump(int x, int d) {\n\t\tfor (int i = 0; i < (int)par.size();\
    \ i++) {\n\t\t\tif ((d >> i) & 1) {\n\t\t\t\tx = par[i][x];\n\t\t\t}\n\t\t}\n\t\
    \treturn x;\n\t}\n\n\tint lca(int x, int y) {\n\t\tif (depth[x] < depth[y]) std::swap(x,\
    \ y);\n\t\tx = jump(x, depth[x] - depth[y]);\n\t\tif (x == y) return x;\n\t\t\
    for (int i = (int)par.size() - 1; i >= 0; i--) {\n\t\t\tint nx = par[i][x];\n\t\
    \t\tint ny = par[i][y];\n\t\t\tif (nx != ny) x = nx, y = ny;\n\t\t}\n\t\treturn\
    \ par[0][x];\n\t}\n\n\tT distance(int x, int y) {\n\t\tint l = lca(x, y);\n\t\t\
    return depth_dist[x] + depth_dist[y] - 2 * depth_dist[l];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/lca-jump-distance.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/lca-jump-distance.hpp
layout: document
redirect_from:
- /library/library/graphs/lca-jump-distance.hpp
- /library/library/graphs/lca-jump-distance.hpp.html
title: library/graphs/lca-jump-distance.hpp
---

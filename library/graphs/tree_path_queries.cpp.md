---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/tree_path_queries.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class T> struct LCAJumpSparse {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ par;\n\tstd::vector<std::vector<T>> sparse;\n\tstd::vector<T> vals;\n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> depth;\n\n\tT comb(T a, T b) {\n\t\treturn min(a, b);\n\
    \t}\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tint d = 1;\n\t\twhile ((1 << d)\
    \ < n) d++;\n\t\tpar.assign(d, std::vector<int>(n));\n\t\tadj.resize(n);\n\t\t\
    depth.resize(n);\n\t\tvals.resize(n);\n\t}\n\n\tvoid set_val(int x, T v) {\n\t\
    \tvals[x] = v;\n\t}\n\n\tvoid ae(int x, int y) {\n\t\tadj[x].push_back(y);\n\t\
    \tadj[y].push_back(x);\n\t}\n\n\tvoid gen(int root = 0) {\n\t\tpar[0][root] =\
    \ root;\n\t\tsparse[0][root] = vals[root];\n\t\tdfs(root);\n\t}\n\n\tvoid dfs(int\
    \ src = 0) {\n\t\tfor (int i = 1; i < (int)par.size(); i++) {\n\t\t\tpar[i][src]\
    \ = par[i - 1][par[i - 1][src]];\n\t\t\tsparse[i][src] = comb(sparse[i - 1][src],\
    \ sparse[i - 1][par[i - 1][src]]);\n\t\t}\n\t\tfor (int nxt: adj[src]) {\n\t\t\
    \tif (nxt == par[0][src]) continue;\n\t\t\tdepth[nxt] = depth[par[0][nxt] = src]\
    \ + 1;\n\t\t\tdfs(nxt);\n\t\t}\n\t}\n\n\tint jump(int x, int d) {\n\t\tfor (int\
    \ i = 0; i < (int)par.size(); i++) {\n\t\t\tif ((d >> i) & 1) {\n\t\t\t\tx = par[i][x];\n\
    \t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\n\tint lca(int x, int y) {\n\t\tif (depth[x]\
    \ < depth[y]) std::swap(x, y);\n\t\tx = jump(x, depth[x] - depth[y]);\n\t\tif\
    \ (x == y) return x;\n\t\tfor (int i = (int)par.size() - 1; i >= 0; i--) {\n\t\
    \t\tint nx = par[i][x];\n\t\t\tint ny = par[i][y];\n\t\t\tif (nx != ny) x = nx,\
    \ y = ny;\n\t\t}\n\t\treturn par[0][x];\n\t}\n\n\tT query(int x, int y) {\n\t\t\
    int anc = lca(x, y);\n\t\tint d = 31 - __builtin_clz(depth[x] - depth[anc]);\n\
    \t\tT res1 = comb(sparse[d][x], sparse[d][jump(x, depth[x] - depth[anc] - (1 <<\
    \ d) + 1)]);\n\t\td = 31 - __builtin_clz(depth[y] - depth[anc]);\n\t\tT res2 =\
    \ comb(sparse[d][y], sparse[d][jump(y, depth[y] - depth[anc] - (1 << d) + 1)]);\n\
    \t\treturn comb(res1, res2);\n\t}\n};\n\nint main() {\n\tLCAJumpSparse<int> L;\n\
    \treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct LCAJumpSparse {\n\t\
    int n;\n\tstd::vector<std::vector<int>> par;\n\tstd::vector<std::vector<T>> sparse;\n\
    \tstd::vector<T> vals;\n\tstd::vector<std::vector<int>> adj;\n\tstd::vector<int>\
    \ depth;\n\n\tT comb(T a, T b) {\n\t\treturn min(a, b);\n\t}\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\tint d = 1;\n\t\twhile ((1 << d) < n) d++;\n\t\tpar.assign(d,\
    \ std::vector<int>(n));\n\t\tadj.resize(n);\n\t\tdepth.resize(n);\n\t\tvals.resize(n);\n\
    \t}\n\n\tvoid set_val(int x, T v) {\n\t\tvals[x] = v;\n\t}\n\n\tvoid ae(int x,\
    \ int y) {\n\t\tadj[x].push_back(y);\n\t\tadj[y].push_back(x);\n\t}\n\n\tvoid\
    \ gen(int root = 0) {\n\t\tpar[0][root] = root;\n\t\tsparse[0][root] = vals[root];\n\
    \t\tdfs(root);\n\t}\n\n\tvoid dfs(int src = 0) {\n\t\tfor (int i = 1; i < (int)par.size();\
    \ i++) {\n\t\t\tpar[i][src] = par[i - 1][par[i - 1][src]];\n\t\t\tsparse[i][src]\
    \ = comb(sparse[i - 1][src], sparse[i - 1][par[i - 1][src]]);\n\t\t}\n\t\tfor\
    \ (int nxt: adj[src]) {\n\t\t\tif (nxt == par[0][src]) continue;\n\t\t\tdepth[nxt]\
    \ = depth[par[0][nxt] = src] + 1;\n\t\t\tdfs(nxt);\n\t\t}\n\t}\n\n\tint jump(int\
    \ x, int d) {\n\t\tfor (int i = 0; i < (int)par.size(); i++) {\n\t\t\tif ((d >>\
    \ i) & 1) {\n\t\t\t\tx = par[i][x];\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\n\t\
    int lca(int x, int y) {\n\t\tif (depth[x] < depth[y]) std::swap(x, y);\n\t\tx\
    \ = jump(x, depth[x] - depth[y]);\n\t\tif (x == y) return x;\n\t\tfor (int i =\
    \ (int)par.size() - 1; i >= 0; i--) {\n\t\t\tint nx = par[i][x];\n\t\t\tint ny\
    \ = par[i][y];\n\t\t\tif (nx != ny) x = nx, y = ny;\n\t\t}\n\t\treturn par[0][x];\n\
    \t}\n\n\tT query(int x, int y) {\n\t\tint anc = lca(x, y);\n\t\tint d = 31 - __builtin_clz(depth[x]\
    \ - depth[anc]);\n\t\tT res1 = comb(sparse[d][x], sparse[d][jump(x, depth[x] -\
    \ depth[anc] - (1 << d) + 1)]);\n\t\td = 31 - __builtin_clz(depth[y] - depth[anc]);\n\
    \t\tT res2 = comb(sparse[d][y], sparse[d][jump(y, depth[y] - depth[anc] - (1 <<\
    \ d) + 1)]);\n\t\treturn comb(res1, res2);\n\t}\n};\n\nint main() {\n\tLCAJumpSparse<int>\
    \ L;\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/tree_path_queries.cpp
  requiredBy: []
  timestamp: '2021-07-10 12:34:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/tree_path_queries.cpp
layout: document
redirect_from:
- /library/library/graphs/tree_path_queries.cpp
- /library/library/graphs/tree_path_queries.cpp.html
title: library/graphs/tree_path_queries.cpp
---

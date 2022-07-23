---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
    title: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\n\r\ntemplate <class T> struct LazySeg {\r\n\tstd::vector<T> sum,\
    \ lazy;\r\n\tint sz;\r\n\r\n\tvoid init(int sz_) {\r\n\t\tsz = 1;\r\n\t\twhile\
    \ (sz < sz_) sz *= 2;\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tlazy.assign(2 * sz,\
    \ 0);\r\n\t}\r\n\r\n\tvoid push(int ind, int L, int R) {\r\n\t\tsum[ind] += (R\
    \ - L + 1) * lazy[ind];\r\n\t\tif (L != R) {\r\n\t\t\tlazy[2 * ind] += lazy[ind];\r\
    \n\t\t\tlazy[2 * ind + 1] += lazy[ind];\r\n\t\t}\r\n\t\tlazy[ind] = 0;\r\n\t}\r\
    \n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\
    \n\t}\r\n\r\n\tvoid build() {\r\n\t\tfor (int i = sz - 1; i >= 1; i--) {\r\n\t\
    \t\tpull(i);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid upd(int lo, int hi, T inc, int ind\
    \ = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind,\
    \ L, R);\r\n\t\tif (hi < L || R < lo) return;\r\n\t\tif (lo <= L && R <= hi) {\r\
    \n\t\t\tlazy[ind] = inc;\r\n\t\t\tpush(ind, L, R);\r\n\t\t\treturn;\r\n\t\t}\r\
    \n\t\tint M = (L + R) / 2;\r\n\t\tupd(lo, hi, inc, 2 * ind, L, M);\r\n\t\tupd(lo,\
    \ hi, inc, 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\r\n\tT qsum(int\
    \ lo, int hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\
    \n\t\tpush(ind, L, R);\r\n\t\tif (lo > R || L > hi) return 0;\r\n\t\tif (lo <=\
    \ L && R <= hi) return sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\n\r\n\
    const bool VALUES_IN_VERTICES = true;\r\n\r\ntemplate <class T> struct HeavyLight\
    \ {\r\n\tstd::vector<int> parent, heavy, depth, root, tree_pos;\r\n\tLazySeg<T>\
    \ tree;\r\n\r\n\ttemplate <class G> int dfs(const G& graph, int v) {\r\n\t\tint\
    \ size = 1, max_subtree = 0;\r\n\t\tfor (int u : graph[v]) if (u != parent[v])\
    \ {\r\n\t\t\tparent[u] = v;\r\n\t\t\tdepth[u] = depth[v] + 1;\r\n\t\t\tint subtree\
    \ = dfs(graph, u);\r\n\t\t\tif (subtree > max_subtree) heavy[v] = u, max_subtree\
    \ = subtree;\r\n\t\t\tsize += subtree;\r\n\t\t}\r\n\t\treturn size;\r\n\t}\r\n\
    \r\n\ttemplate <class B> void process_path(int u, int v, B op) {\r\n\t\tfor (;\
    \ root[u] != root[v]; v = parent[root[v]]) {\r\n\t\t\tif (depth[root[u]] > depth[root[v]])\
    \ std::swap(u, v);\r\n\t\t\top(tree_pos[root[v]], tree_pos[v]);\r\n\t\t}\r\n\t\
    \tif (depth[u] > depth[v]) std::swap(u, v);\r\n\t\top(tree_pos[u] + (VALUES_IN_VERTICES\
    \ ? 0 : 1), tree_pos[v]);\r\n\t}\r\n\r\n\ttemplate <class G>\r\n\tvoid init(const\
    \ G& graph, int r = 0) {\r\n\t\tint n = (int)graph.size();\r\n\t\theavy.assign(n,\
    \ -1);\r\n\t\tparent.assign(n, 0);\r\n\t\tdepth.assign(n, 0);\r\n\t\troot.assign(n,\
    \ 0);\r\n\t\ttree_pos.assign(n, 0);\r\n\t\ttree.init(n);\r\n\t\tparent[r] = -1;\r\
    \n\t\tdepth[r] = 0;\r\n\t\tdfs(graph, r);\r\n\t\tfor (int i = 0, current_pos =\
    \ 0; i < n; ++i)\r\n\t\t\tif (parent[i] == -1 || heavy[parent[i]] != i)\r\n\t\t\
    \tfor (int j = i; j != -1; j = heavy[j]) {\r\n\t\t\t\troot[j] = i;\r\n\t\t\t\t\
    tree_pos[j] = current_pos++;\r\n\t\t\t}\r\n\t}\r\n\r\n\tvoid modify_path(int u,\
    \ int v, const T& value) {\r\n\t\tprocess_path(u, v, [this, &value](int l, int\
    \ r) { tree.upd(l, r, value); });\r\n\t}\r\n\t\r\n\tT query_path(int u, int v)\
    \ {\r\n\t\tT res = 0;\r\n\t\tprocess_path(u, v, [this, &res](int l, int r) { res\
    \ += tree.qsum(l, r); });\r\n\t\treturn res;\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../data-structures/1d-range-queries/lazy-segment-tree.hpp\"\
    \r\n\r\nconst bool VALUES_IN_VERTICES = true;\r\n\r\ntemplate <class T> struct\
    \ HeavyLight {\r\n\tstd::vector<int> parent, heavy, depth, root, tree_pos;\r\n\
    \tLazySeg<T> tree;\r\n\r\n\ttemplate <class G> int dfs(const G& graph, int v)\
    \ {\r\n\t\tint size = 1, max_subtree = 0;\r\n\t\tfor (int u : graph[v]) if (u\
    \ != parent[v]) {\r\n\t\t\tparent[u] = v;\r\n\t\t\tdepth[u] = depth[v] + 1;\r\n\
    \t\t\tint subtree = dfs(graph, u);\r\n\t\t\tif (subtree > max_subtree) heavy[v]\
    \ = u, max_subtree = subtree;\r\n\t\t\tsize += subtree;\r\n\t\t}\r\n\t\treturn\
    \ size;\r\n\t}\r\n\r\n\ttemplate <class B> void process_path(int u, int v, B op)\
    \ {\r\n\t\tfor (; root[u] != root[v]; v = parent[root[v]]) {\r\n\t\t\tif (depth[root[u]]\
    \ > depth[root[v]]) std::swap(u, v);\r\n\t\t\top(tree_pos[root[v]], tree_pos[v]);\r\
    \n\t\t}\r\n\t\tif (depth[u] > depth[v]) std::swap(u, v);\r\n\t\top(tree_pos[u]\
    \ + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);\r\n\t}\r\n\r\n\ttemplate <class\
    \ G>\r\n\tvoid init(const G& graph, int r = 0) {\r\n\t\tint n = (int)graph.size();\r\
    \n\t\theavy.assign(n, -1);\r\n\t\tparent.assign(n, 0);\r\n\t\tdepth.assign(n,\
    \ 0);\r\n\t\troot.assign(n, 0);\r\n\t\ttree_pos.assign(n, 0);\r\n\t\ttree.init(n);\r\
    \n\t\tparent[r] = -1;\r\n\t\tdepth[r] = 0;\r\n\t\tdfs(graph, r);\r\n\t\tfor (int\
    \ i = 0, current_pos = 0; i < n; ++i)\r\n\t\t\tif (parent[i] == -1 || heavy[parent[i]]\
    \ != i)\r\n\t\t\tfor (int j = i; j != -1; j = heavy[j]) {\r\n\t\t\t\troot[j] =\
    \ i;\r\n\t\t\t\ttree_pos[j] = current_pos++;\r\n\t\t\t}\r\n\t}\r\n\r\n\tvoid modify_path(int\
    \ u, int v, const T& value) {\r\n\t\tprocess_path(u, v, [this, &value](int l,\
    \ int r) { tree.upd(l, r, value); });\r\n\t}\r\n\t\r\n\tT query_path(int u, int\
    \ v) {\r\n\t\tT res = 0;\r\n\t\tprocess_path(u, v, [this, &res](int l, int r)\
    \ { res += tree.qsum(l, r); });\r\n\t\treturn res;\r\n\t}\r\n};\r\n"
  dependsOn:
  - library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  isVerificationFile: false
  path: library/graphs/heavy-light-decomposition2.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
documentation_of: library/graphs/heavy-light-decomposition2.hpp
layout: document
title: Old Heavy Light Decomposition
---

## Old Heavy Light Decomposition

This uses my old lazy segment tree implementation, but it's still worth keeping around. 

### Functions
- `init(graph, r)`: Initializes with a graph $graph$ and a root $r$. You can easily change $r$ to a vector of roots and DFS each of them to support a forest. 
- `modify_path(u, v)`: Modifies path from $u$ to $v$. 
- `query_path(u, v)`: Queries path from $u$ to $v$. 

### Variables
- `VALUES_IN_VERTICES`: Set `true` if you want values in vertices, `false` if in edges. 


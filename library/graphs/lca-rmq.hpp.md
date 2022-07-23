---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1074F.test.cpp
    title: verify/codeforces/codeforces-1074F.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
    title: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\r\n\r\ntemplate <class T> struct SparseTable {\r\n\tstd::vector<T>\
    \ v;\r\n\tstd::vector<std::vector<int>> jump;\r\n\r\n\tint level(int x) { return\
    \ 31 - __builtin_clz(x); }\r\n\r\n\tint comb(int a, int b) {\r\n\t\treturn v[a]\
    \ == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\r\n\t}\r\n\r\n\tvoid init(const\
    \ std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\t\tjump = {std::vector<int>((int)v.size())};\r\
    \n\t\tiota(jump[0].begin(), jump[0].end(), 0);\r\n\t\tfor (int j = 1; (1 << j)\
    \ <= (int)v.size(); j++) {\r\n\t\t\tjump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\r\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\r\
    \n\t\t\t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint index(int l, int r) {\r\n\t\tassert(l <=\
    \ r);\r\n\t\tint d = level(r - l + 1);\r\n\t\treturn comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn v[index(l,\
    \ r)];\r\n\t}\r\n};\n\r\nstruct LCARMQ {\r\n\tint n; \r\n\tstd::vector<std::vector<int>>\
    \ adj;\r\n\tstd::vector<int> dep, in, par, rev, out, pos;\r\n\tstd::vector<std::pair<int,\
    \ int>> tmp;\r\n\tSparseTable<std::pair<int, int>> S;\r\n\tstd::vector<std::vector<int>>\
    \ sparse;\r\n\tint ti = 0;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    adj.resize(n);\r\n\t\tdep = in = out = par = rev = pos = std::vector<int>(n);\r\
    \n\t\tsparse = {std::vector<int>(n)};\r\n\t\tfor (int j = 1; (1 << j) <= n; j++)\
    \ {\r\n\t\t\tsparse.push_back(std::vector<int>(n - (1 << j) + 1));\r\n\t\t}\r\n\
    \t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\n\t\tadj[v].push_back(u);\r\
    \n\t}\r\n\r\n\tvoid dfs(int src) {\r\n\t\tin[src] = ti++;\r\n\t\tsparse[0][in[src]]\
    \ = src;\r\n\t\tpos[src] = (int)tmp.size();\r\n\t\ttmp.emplace_back(dep[src],\
    \ src);\r\n\t\tfor (auto &nxt : adj[src]) {\r\n\t\t\tif (nxt == par[src]) continue;\r\
    \n\t\t\tdep[nxt] = dep[par[nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\n\t\t\ttmp.emplace_back(dep[src],\
    \ src);\r\n\t\t}\r\n\t\tout[src] = ti;\r\n\t}\r\n\r\n\tinline int mini(int u,\
    \ int v) {\r\n\t\treturn (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v]))\
    \ ? u : v;\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[root] = root;\r\
    \n\t\tdfs(root);\r\n\t\tS.init(tmp); \r\n\t\tfor (int j = 1; j < (int)sparse.size();\
    \ j++) {\r\n\t\t\tfor (int i = 0; i < (int)sparse[j].size(); i++) {\r\n\t\t\t\t\
    sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint lca(int u, int v) {\r\n\t\tu = pos[u];\r\n\t\
    \tv = pos[v];\r\n\t\tif (u > v) std::swap(u, v);\r\n\t\treturn S.query(u, v).second;\r\
    \n\t}\r\n\r\n\tint dist(int u, int v) {\r\n\t\treturn dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\r\n\t}\r\n\r\n\tbool is_ancestor(int anc, int src) {\r\n\t\treturn in[anc]\
    \ <= in[src] && out[anc] >= out[src];\r\n\t}\r\n\r\n\tint get_child(int anc, int\
    \ src) {\r\n\t\tif (!is_ancestor(anc, src)) return -1;\r\n\t\tint l = in[anc]\
    \ + 1;\r\n\t\tint r = in[src];\r\n\t\tint d = 31 - __builtin_clz(r - l + 1);\r\
    \n\t\treturn mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\r\n\t}\r\n\t\r\n\
    \tstd::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\r\n\t\t\
    auto cmp = [&](int a, int b) {\r\n\t\t\treturn pos[a] < pos[b];\r\n\t\t};\r\n\t\
    \tsort(nodes.begin(), nodes.end(), cmp);\r\n\t\tfor (int i = (int)nodes.size()\
    \ - 2; i >= 0; i--) {\r\n\t\t\tnodes.push_back(lca(nodes[i], nodes[i + 1]));\r\
    \n\t\t}\r\n\t\tsort(nodes.begin(), nodes.end(), cmp);\r\n\t\tnodes.erase(unique(nodes.begin(),\
    \ nodes.end()), nodes.end());\r\n\t\tstd::vector<std::pair<int, int>> ret{{0,\
    \ nodes[0]}};\r\n\t\tfor (int i = 0; i < (int)nodes.size(); i++) {\r\n\t\t\trev[nodes[i]]\
    \ = i;\r\n\t\t}\r\n\t\tfor (int i = 1; i < (int)nodes.size(); i++) {\r\n\t\t\t\
    ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);\r\n\t\t}\r\n\t\t\
    return ret;\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"../data-structures/1d-range-queries/sparse-table.hpp\"\
    \r\n\r\nstruct LCARMQ {\r\n\tint n; \r\n\tstd::vector<std::vector<int>> adj;\r\
    \n\tstd::vector<int> dep, in, par, rev, out, pos;\r\n\tstd::vector<std::pair<int,\
    \ int>> tmp;\r\n\tSparseTable<std::pair<int, int>> S;\r\n\tstd::vector<std::vector<int>>\
    \ sparse;\r\n\tint ti = 0;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\t\
    adj.resize(n);\r\n\t\tdep = in = out = par = rev = pos = std::vector<int>(n);\r\
    \n\t\tsparse = {std::vector<int>(n)};\r\n\t\tfor (int j = 1; (1 << j) <= n; j++)\
    \ {\r\n\t\t\tsparse.push_back(std::vector<int>(n - (1 << j) + 1));\r\n\t\t}\r\n\
    \t}\r\n\r\n\tvoid ae(int u, int v) {\r\n\t\tadj[u].push_back(v);\r\n\t\tadj[v].push_back(u);\r\
    \n\t}\r\n\r\n\tvoid dfs(int src) {\r\n\t\tin[src] = ti++;\r\n\t\tsparse[0][in[src]]\
    \ = src;\r\n\t\tpos[src] = (int)tmp.size();\r\n\t\ttmp.emplace_back(dep[src],\
    \ src);\r\n\t\tfor (auto &nxt : adj[src]) {\r\n\t\t\tif (nxt == par[src]) continue;\r\
    \n\t\t\tdep[nxt] = dep[par[nxt] = src] + 1;\r\n\t\t\tdfs(nxt);\r\n\t\t\ttmp.emplace_back(dep[src],\
    \ src);\r\n\t\t}\r\n\t\tout[src] = ti;\r\n\t}\r\n\r\n\tinline int mini(int u,\
    \ int v) {\r\n\t\treturn (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v]))\
    \ ? u : v;\r\n\t}\r\n\r\n\tvoid gen(int root = 0) {\r\n\t\tpar[root] = root;\r\
    \n\t\tdfs(root);\r\n\t\tS.init(tmp); \r\n\t\tfor (int j = 1; j < (int)sparse.size();\
    \ j++) {\r\n\t\t\tfor (int i = 0; i < (int)sparse[j].size(); i++) {\r\n\t\t\t\t\
    sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint lca(int u, int v) {\r\n\t\tu = pos[u];\r\n\t\
    \tv = pos[v];\r\n\t\tif (u > v) std::swap(u, v);\r\n\t\treturn S.query(u, v).second;\r\
    \n\t}\r\n\r\n\tint dist(int u, int v) {\r\n\t\treturn dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\r\n\t}\r\n\r\n\tbool is_ancestor(int anc, int src) {\r\n\t\treturn in[anc]\
    \ <= in[src] && out[anc] >= out[src];\r\n\t}\r\n\r\n\tint get_child(int anc, int\
    \ src) {\r\n\t\tif (!is_ancestor(anc, src)) return -1;\r\n\t\tint l = in[anc]\
    \ + 1;\r\n\t\tint r = in[src];\r\n\t\tint d = 31 - __builtin_clz(r - l + 1);\r\
    \n\t\treturn mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\r\n\t}\r\n\t\r\n\
    \tstd::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\r\n\t\t\
    auto cmp = [&](int a, int b) {\r\n\t\t\treturn pos[a] < pos[b];\r\n\t\t};\r\n\t\
    \tsort(nodes.begin(), nodes.end(), cmp);\r\n\t\tfor (int i = (int)nodes.size()\
    \ - 2; i >= 0; i--) {\r\n\t\t\tnodes.push_back(lca(nodes[i], nodes[i + 1]));\r\
    \n\t\t}\r\n\t\tsort(nodes.begin(), nodes.end(), cmp);\r\n\t\tnodes.erase(unique(nodes.begin(),\
    \ nodes.end()), nodes.end());\r\n\t\tstd::vector<std::pair<int, int>> ret{{0,\
    \ nodes[0]}};\r\n\t\tfor (int i = 0; i < (int)nodes.size(); i++) {\r\n\t\t\trev[nodes[i]]\
    \ = i;\r\n\t\t}\r\n\t\tfor (int i = 1; i < (int)nodes.size(); i++) {\r\n\t\t\t\
    ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);\r\n\t\t}\r\n\t\t\
    return ret;\r\n\t}\r\n};\r\n"
  dependsOn:
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: false
  path: library/graphs/lca-rmq.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/codeforces/codeforces-1074F.test.cpp
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/yosupo/yosupo-lca-lca-rmq.test.cpp
documentation_of: library/graphs/lca-rmq.hpp
layout: document
title: LCA RMQ
---

## LCA RMQ

### Functions
- `init(n)`: Initializes variables
- `gen(root)`: Generates from $root$, can easily change to vector for forests. Just repeat `gen` for each root in $\mathcal O(n \log (n))$. 
- `is_ancestor(anc, src)`: Checks if $anc$ is ancestor of $src$ in $\mathcal O(1)$. 
- `lca(x, y)`: Lowest common ancestor of $x, y$ in $\mathcal O(1)$. 
- `compress(nodes)`: Tree compression of nodes. 
	- It returns a list of (parent, original index). 
	- Parent is the parent of the node in the compressed tree.
	- Original index is the node it represents in the origial tree. 
	- Works in $\mathcal O(S \log (S))$ if $nodes$ is of size $S$. 
- `get_child(anc, src)`: Returns the child of $anc$ whose subtree contains $src$ in $\mathcal O(1)$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/graphs%20(12)/Trees%20(10)/LCArmq%20(10.2).h)

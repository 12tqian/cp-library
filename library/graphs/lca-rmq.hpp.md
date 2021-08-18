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
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
    title: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\n\ntemplate <class T> struct SparseTable {\n\tstd::vector<T> v;\n\
    \tstd::vector<std::vector<int>> jump;\n\n\tint level(int x) { return 31 - __builtin_clz(x);\
    \ }\n\n\tint comb(int a, int b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) :\
    \ (v[a] < v[b] ? a : b);\n\t}\n\n\tvoid init(const std::vector<T>& _v) {\n\t\t\
    v = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\t\tiota(jump[0].begin(),\
    \ jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <= (int)v.size(); j++) {\n\t\
    \t\tjump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));\n\t\t\tfor\
    \ (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\t\tjump[j][i] = comb(jump[j\
    \ - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tint index(int\
    \ l, int r) {\n\t\tassert(l <= r);\n\t\tint d = level(r - l + 1);\n\t\treturn\
    \ comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\treturn v[index(l, r)];\n\t}\n};\n\nstruct LCARMQ {\n\tint n; \n\tstd::vector<std::vector<int>>\
    \ adj;\n\tstd::vector<int> dep, in, par, rev, out, pos;\n\tstd::vector<std::pair<int,\
    \ int>> tmp;\n\tSparseTable<std::pair<int, int>> S;\n\tstd::vector<std::vector<int>>\
    \ sparse;\n\tint ti = 0;\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tadj.resize(n);\n\
    \t\tdep = in = out = par = rev = pos = std::vector<int>(n);\n\t\tsparse = {std::vector<int>(n)};\n\
    \t\tfor (int j = 1; (1 << j) <= n; j++) {\n\t\t\tsparse.push_back(std::vector<int>(n\
    \ - (1 << j) + 1));\n\t\t}\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\
    \t\tadj[v].push_back(u);\n\t}\n\n\tvoid dfs(int src) {\n\t\tin[src] = ti++;\n\t\
    \tsparse[0][in[src]] = src;\n\t\tpos[src] = (int)tmp.size();\n\t\ttmp.emplace_back(dep[src],\
    \ src);\n\t\tfor (auto &nxt : adj[src]) {\n\t\t\tif (nxt == par[src]) continue;\n\
    \t\t\tdep[nxt] = dep[par[nxt] = src] + 1;\n\t\t\tdfs(nxt);\n\t\t\ttmp.emplace_back(dep[src],\
    \ src);\n\t\t}\n\t\tout[src] = ti;\n\t}\n\n\tinline int mini(int u, int v) {\n\
    \t\treturn (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;\n\
    \t}\n\n\tvoid gen(int root = 0) {\n\t\tpar[root] = root;\n\t\tdfs(root);\n\t\t\
    S.init(tmp); \n\t\tfor (int j = 1; j < (int)sparse.size(); j++) {\n\t\t\tfor (int\
    \ i = 0; i < (int)sparse[j].size(); i++) {\n\t\t\t\tsparse[j][i] = mini(sparse[j\
    \ - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tint lca(int\
    \ u, int v) {\n\t\tu = pos[u];\n\t\tv = pos[v];\n\t\tif (u > v) std::swap(u, v);\n\
    \t\treturn S.query(u, v).second;\n\t}\n\n\tint dist(int u, int v) {\n\t\treturn\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\t}\n\n\tbool is_ancestor(int anc, int\
    \ src) {\n\t\treturn in[anc] <= in[src] && out[anc] >= out[src];\n\t}\n\n\tint\
    \ get_child(int anc, int src) {\n\t\tif (!is_ancestor(anc, src)) return -1;\n\t\
    \tint l = in[anc] + 1;\n\t\tint r = in[src];\n\t\tint d = 31 - __builtin_clz(r\
    \ - l + 1);\n\t\treturn mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\n\t}\n\
    \t\n\tstd::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\n\t\t\
    auto cmp = [&](int a, int b) {\n\t\t\treturn pos[a] < pos[b];\n\t\t};\n\t\tsort(nodes.begin(),\
    \ nodes.end(), cmp);\n\t\tfor (int i = (int)nodes.size() - 2; i >= 0; i--) {\n\
    \t\t\tnodes.push_back(lca(nodes[i], nodes[i + 1]));\n\t\t}\n\t\tsort(nodes.begin(),\
    \ nodes.end(), cmp);\n\t\tnodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());\n\
    \t\tstd::vector<std::pair<int, int>> ret{{0, nodes[0]}};\n\t\tfor (int i = 0;\
    \ i < (int)nodes.size(); i++) {\n\t\t\trev[nodes[i]] = i;\n\t\t}\n\t\tfor (int\
    \ i = 1; i < (int)nodes.size(); i++) {\n\t\t\tret.emplace_back(rev[lca(nodes[i\
    \ - 1], nodes[i])], nodes[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "#pragma once\n\n#include \"../data-structures/1d-range-queries/sparse-table.hpp\"\
    \n\nstruct LCARMQ {\n\tint n; \n\tstd::vector<std::vector<int>> adj;\n\tstd::vector<int>\
    \ dep, in, par, rev, out, pos;\n\tstd::vector<std::pair<int, int>> tmp;\n\tSparseTable<std::pair<int,\
    \ int>> S;\n\tstd::vector<std::vector<int>> sparse;\n\tint ti = 0;\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\tadj.resize(n);\n\t\tdep = in = out = par = rev = pos\
    \ = std::vector<int>(n);\n\t\tsparse = {std::vector<int>(n)};\n\t\tfor (int j\
    \ = 1; (1 << j) <= n; j++) {\n\t\t\tsparse.push_back(std::vector<int>(n - (1 <<\
    \ j) + 1));\n\t\t}\n\t}\n\n\tvoid ae(int u, int v) {\n\t\tadj[u].push_back(v);\n\
    \t\tadj[v].push_back(u);\n\t}\n\n\tvoid dfs(int src) {\n\t\tin[src] = ti++;\n\t\
    \tsparse[0][in[src]] = src;\n\t\tpos[src] = (int)tmp.size();\n\t\ttmp.emplace_back(dep[src],\
    \ src);\n\t\tfor (auto &nxt : adj[src]) {\n\t\t\tif (nxt == par[src]) continue;\n\
    \t\t\tdep[nxt] = dep[par[nxt] = src] + 1;\n\t\t\tdfs(nxt);\n\t\t\ttmp.emplace_back(dep[src],\
    \ src);\n\t\t}\n\t\tout[src] = ti;\n\t}\n\n\tinline int mini(int u, int v) {\n\
    \t\treturn (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;\n\
    \t}\n\n\tvoid gen(int root = 0) {\n\t\tpar[root] = root;\n\t\tdfs(root);\n\t\t\
    S.init(tmp); \n\t\tfor (int j = 1; j < (int)sparse.size(); j++) {\n\t\t\tfor (int\
    \ i = 0; i < (int)sparse[j].size(); i++) {\n\t\t\t\tsparse[j][i] = mini(sparse[j\
    \ - 1][i], sparse[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tint lca(int\
    \ u, int v) {\n\t\tu = pos[u];\n\t\tv = pos[v];\n\t\tif (u > v) std::swap(u, v);\n\
    \t\treturn S.query(u, v).second;\n\t}\n\n\tint dist(int u, int v) {\n\t\treturn\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\t}\n\n\tbool is_ancestor(int anc, int\
    \ src) {\n\t\treturn in[anc] <= in[src] && out[anc] >= out[src];\n\t}\n\n\tint\
    \ get_child(int anc, int src) {\n\t\tif (!is_ancestor(anc, src)) return -1;\n\t\
    \tint l = in[anc] + 1;\n\t\tint r = in[src];\n\t\tint d = 31 - __builtin_clz(r\
    \ - l + 1);\n\t\treturn mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);\n\t}\n\
    \t\n\tstd::vector<std::pair<int, int>> compress(std::vector<int> nodes) {\n\t\t\
    auto cmp = [&](int a, int b) {\n\t\t\treturn pos[a] < pos[b];\n\t\t};\n\t\tsort(nodes.begin(),\
    \ nodes.end(), cmp);\n\t\tfor (int i = (int)nodes.size() - 2; i >= 0; i--) {\n\
    \t\t\tnodes.push_back(lca(nodes[i], nodes[i + 1]));\n\t\t}\n\t\tsort(nodes.begin(),\
    \ nodes.end(), cmp);\n\t\tnodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());\n\
    \t\tstd::vector<std::pair<int, int>> ret{{0, nodes[0]}};\n\t\tfor (int i = 0;\
    \ i < (int)nodes.size(); i++) {\n\t\t\trev[nodes[i]] = i;\n\t\t}\n\t\tfor (int\
    \ i = 1; i < (int)nodes.size(); i++) {\n\t\t\tret.emplace_back(rev[lca(nodes[i\
    \ - 1], nodes[i])], nodes[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  dependsOn:
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: false
  path: library/graphs/lca-rmq.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:21:48-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  - verify/codeforces/codeforces-1074F.test.cpp
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

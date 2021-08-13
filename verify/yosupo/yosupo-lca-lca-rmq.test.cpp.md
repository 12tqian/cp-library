---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: library/graphs/lca-rmq.hpp
    title: library/graphs/lca-rmq.hpp
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
    \n/**\n * O(n log n) preprocessing with O(1) query\n * Compress compute sthe minimal\
    \ subtree containing\n * all node LCAs and comrpesses edges\n * O(S log S) compression\n\
    \ * Returns list of (parent, original index)\n * Parent is the parent of node\
    \ in compressed tree\n * Original index is the node it represents\n * get_child\
    \ also returns the subtree child of node and -1 if it doesn't exist in O(1)\n\
    \ * To support forest, gen on all the roots, initialize tmp and sparse at the\
    \ end\n */\n\n\n/**\n * This Sparse Table stores indices of things\n * For destructive\
    \ combinations like gcd, use associative_range_query.cpp\n * Use this for min,\
    \ max, and when you need the indices of things\n */\n\ntemplate <class T> struct\
    \ SparseTable {\n\tstd::vector<T> v;\n\tstd::vector<std::vector<int>> jump;\n\n\
    \tint level(int x) { return 31 - __builtin_clz(x); }\n\n\tint comb(int a, int\
    \ b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n\t\
    }\n\n\tvoid init(const std::vector<T> &_v) {\n\t\tv = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\
    \t\tiota(jump[0].begin(), jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <=\
    \ (int)v.size(); j++) {\n\t\t\tjump.push_back(std::vector<int>((int)v.size() -\
    \ (1 << j) + 1));\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\
    \t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tint index(int l, int r) {\n\t\tassert(l <= r);\n\t\tint d =\
    \ level(r - l + 1);\n\t\treturn comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\treturn v[index(l, r)];\n\t}\n};\n\nstruct\
    \ LCARMQ {\n\tint n; \n\tstd::vector<std::vector<int>> adj;\n\tstd::vector<int>\
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
    \ - 1], nodes[i])], nodes[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n\nint main()\
    \ {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin\
    \ >> n >> q;\n\tLCARMQ L;\n\tL.init(n);\n\tfor (int i = 1; i < n; i++) {\n\t\t\
    int p; cin >> p;\n\t\tL.ae(i, p);\n\t}\n\tL.gen(0);\n\twhile (q--) {\n\t\tint\
    \ u, v; cin >> u >> v;\n\t\tcout << L.lca(u, v) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/graphs/lca-rmq.hpp\"\n\nint main() {\n\tusing namespace\
    \ std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; cin >> n >> q;\n\tLCARMQ\
    \ L;\n\tL.init(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint p; cin >> p;\n\t\t\
    L.ae(i, p);\n\t}\n\tL.gen(0);\n\twhile (q--) {\n\t\tint u, v; cin >> u >> v;\n\
    \t\tcout << L.lca(u, v) << '\\n';\n\t}\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/lca-rmq.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-lca-lca-rmq.test.cpp
- /verify/verify/yosupo/yosupo-lca-lca-rmq.test.cpp.html
title: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
---

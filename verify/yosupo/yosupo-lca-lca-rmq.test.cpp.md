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
    title: LCA RMQ
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
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n\r\n\
    #include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\
    \n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\
    \n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\
    \n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <set>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nusing namespace std;\n\r\n\r\ntemplate <class T> struct SparseTable\
    \ {\r\n\tstd::vector<T> v;\r\n\tstd::vector<std::vector<int>> jump;\r\n\r\n\t\
    int level(int x) { return 31 - __builtin_clz(x); }\r\n\r\n\tint comb(int a, int\
    \ b) {\r\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\r\n\
    \t}\r\n\r\n\tvoid init(const std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\t\tjump\
    \ = {std::vector<int>((int)v.size())};\r\n\t\tiota(jump[0].begin(), jump[0].end(),\
    \ 0);\r\n\t\tfor (int j = 1; (1 << j) <= (int)v.size(); j++) {\r\n\t\t\tjump.push_back(std::vector<int>((int)v.size()\
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
    return ret;\r\n\t}\r\n};\r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; cin >> n >> q;\r\n\tLCARMQ L;\r\n\tL.init(n);\r\n\tfor (int i =\
    \ 1; i < n; i++) {\r\n\t\tint p; cin >> p;\r\n\t\tL.ae(i, p);\r\n\t}\r\n\tL.gen(0);\r\
    \n\twhile (q--) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\tcout << L.lca(u, v) <<\
    \ '\\n';\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    ../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/lca-rmq.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; cin >> n >> q;\r\n\tLCARMQ L;\r\n\tL.init(n);\r\n\tfor (int i =\
    \ 1; i < n; i++) {\r\n\t\tint p; cin >> p;\r\n\t\tL.ae(i, p);\r\n\t}\r\n\tL.gen(0);\r\
    \n\twhile (q--) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\tcout << L.lca(u, v) <<\
    \ '\\n';\r\n\t}\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/lca-rmq.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-lca-lca-rmq.test.cpp
- /verify/verify/yosupo/yosupo-lca-lca-rmq.test.cpp.html
title: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
---

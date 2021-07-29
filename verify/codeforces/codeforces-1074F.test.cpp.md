---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: library/data-structures/1d-range-queries/sparse-table.hpp
  - icon: ':question:'
    path: library/graphs/lca-rmq.hpp
    title: library/graphs/lca-rmq.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/1074/problem/F
    links:
    - https://codeforces.com/contest/1074/problem/F
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1074/problem/F\"\n\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
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
    \ - 1], nodes[i])], nodes[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n\ntemplate <class\
    \ T> struct SegmentTree {\n\tusing U = pair<T, int>;\n\n\tconst U ID = make_pair(numeric_limits<T>::max(),\
    \ 1);\n\n\tint sz;\t\n\t\n\tvector<U> st; // min, cnt\n\tvector<T> lz; // lazy\n\
    \n\tvoid init(int _sz) {\n\t\tsz = 1;\n\t\twhile (sz < _sz) {\n\t\t\tsz <<= 1;\n\
    \t\t}\n\t\tst.assign(2 * sz, make_pair(0, 1));\n\t\tlz.assign(2 * sz, 0);\n\t\t\
    for (int i = sz - 1; i >= 1; --i) {\n\t\t\tpull(i);\n\t\t}\n\t}\n\n\tU comb(U\
    \ x, U y) {\n\t\tU res;\n\t\tif (x.first < y.first) {\n\t\t\tres = x;\n\t\t} else\
    \ if (x.first > y.first) {\n\t\t\tres = y;\n\t\t} else {\n\t\t\tres.first = x.first;\n\
    \t\t\tres.second = x.second + y.second;\n\t\t}\n\t\treturn res;\n\t}\n\n\tvoid\
    \ pull(int i) {\n\t\tst[i] = comb(st[2 * i], st[2 * i + 1]);\n\t}\n\n\tvoid push(int\
    \ i, int l, int r) {\n\t\tif (lz[i] == 0) {\n\t\t\treturn;\n\t\t}\n\t\tst[i].first\
    \ += lz[i];\n\t\tif (l != r) {\n\t\t\tfor (int j = 0; j < 2; ++j) {\n\t\t\t\t\
    lz[2 * i + j] += lz[i];\n\t\t\t}\n\t\t}\n\t\tlz[i] = 0;\n\t}\n\n\tvoid upd(int\
    \ lo, int hi, T inc, int i = 1, int l = 0, int r = -1) {\n\t\tif (r == -1) {\n\
    \t\t\tr += sz;\n\t\t}\n\t\tpush(i, l, r);\n\t\tif (r < lo || hi < l) {\n\n\t\t\
    } else if (lo <= l && r <= hi) {\n\t\t\tlz[i] = inc;\n\t\t\tpush(i, l, r);\n\t\
    \t} else {\n\t\t\tint m = (l + r) >> 1;\n\t\t\tupd(lo, hi, inc, 2 * i, l, m);\n\
    \t\t\tupd(lo, hi, inc, 2 * i + 1, m + 1, r);\n\t\t\tpull(i);\n\t\t}\n\t}\n\n\t\
    U query(int lo, int hi, int i = 1, int l = 0, int r = -1) {\n\t\tif (r == -1)\
    \ {\n\t\t\tr += sz;\n\t\t}\n\t\tpush(i, l, r);\n\t\tif (r < lo || hi < l) {\n\t\
    \t\treturn ID;\n\t\t} else if (lo <= l && r <= hi) {\n\t\t\treturn st[i];\n\t\t\
    } else {\n\t\t\tint m = (l + r) >> 1;\n\t\t\treturn comb(query(lo, hi, 2 * i,\
    \ l, m), query(lo, hi, 2 * i + 1, m + 1, r));\n\t\t}\n\t}\n\n\tint zeros(int lo,\
    \ int hi) {\n\t\tauto res = query(lo, hi);\n\t\tif (res.first == 0) {\n\t\t\t\
    return res.second;\n\t\t} else {\n\t\t\treturn 0;\n\t\t}\n\t}\n};\n\nint main()\
    \ {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n, q;\n\tcin >>\
    \ n >> q;\n\tLCARMQ L;\n\tL.init(n);\n\tvector<vector<int>> g(n);\n\tfor (int\
    \ i = 0; i < n - 1; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\
    \t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\t\tL.ae(u, v);\n\t}\t\n\tvector<int>\
    \ in(n);\n\tvector<int> out(n);\n\tint ti = 0;\n\tfunction<void(int, int)> dfs\
    \ = [&](int u, int p) {\n\t\tin[u] = ti++;\n\t\tfor (int v : g[u]) {\n\t\t\tif\
    \ (v != p) {\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\t}\n\t\tout[u] = ti - 1;\n\t};\n\
    \tdfs(0, -1);\n\tL.gen(0);\n\tset<pair<int, int>> used;\n\tSegmentTree<int> seg;\n\
    \tseg.init(n);\t\n\twhile (q--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t--u,\
    \ --v;\n\t\tif (u > v) {\n\t\t\tswap(u, v);\n\t\t}\n\t\tauto add = [&](int u,\
    \ int v, int t) {\n\t\t\tint lca = L.lca(u, v);\n\t\t\tif (lca == v) {\n\t\t\t\
    \tswap(u, v);\n\t\t\t}\n\t\t\tif (lca == u) {\n\t\t\t\tint child = L.get_child(u,\
    \ v);\n\t\t\t\tseg.upd(in[child], out[child], t);\n\t\t\t\tseg.upd(in[v], out[v],\
    \ -t);\n\t\t\t} else {\n\t\t\t\tseg.upd(0, n - 1, t);\n\t\t\t\tseg.upd(in[u],\
    \ out[u], -t);\n\t\t\t\tseg.upd(in[v], out[v], -t);\n\t\t\t}\n\t\t};\n\t\tif (used.count(make_pair(u,\
    \ v))) {\n\t\t\tused.erase(make_pair(u, v));\n\t\t\tadd(u, v, -1);\n\t\t} else\
    \ {\n\t\t\tused.emplace(u, v);\n\t\t\tadd(u, v, 1);\n\t\t}\n\t\tcout << seg.zeros(0,\
    \ n - 1) << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1074/problem/F\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/lca-rmq.hpp\"\
    \n\ntemplate <class T> struct SegmentTree {\n\tusing U = pair<T, int>;\n\n\tconst\
    \ U ID = make_pair(numeric_limits<T>::max(), 1);\n\n\tint sz;\t\n\t\n\tvector<U>\
    \ st; // min, cnt\n\tvector<T> lz; // lazy\n\n\tvoid init(int _sz) {\n\t\tsz =\
    \ 1;\n\t\twhile (sz < _sz) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\tst.assign(2 * sz, make_pair(0,\
    \ 1));\n\t\tlz.assign(2 * sz, 0);\n\t\tfor (int i = sz - 1; i >= 1; --i) {\n\t\
    \t\tpull(i);\n\t\t}\n\t}\n\n\tU comb(U x, U y) {\n\t\tU res;\n\t\tif (x.first\
    \ < y.first) {\n\t\t\tres = x;\n\t\t} else if (x.first > y.first) {\n\t\t\tres\
    \ = y;\n\t\t} else {\n\t\t\tres.first = x.first;\n\t\t\tres.second = x.second\
    \ + y.second;\n\t\t}\n\t\treturn res;\n\t}\n\n\tvoid pull(int i) {\n\t\tst[i]\
    \ = comb(st[2 * i], st[2 * i + 1]);\n\t}\n\n\tvoid push(int i, int l, int r) {\n\
    \t\tif (lz[i] == 0) {\n\t\t\treturn;\n\t\t}\n\t\tst[i].first += lz[i];\n\t\tif\
    \ (l != r) {\n\t\t\tfor (int j = 0; j < 2; ++j) {\n\t\t\t\tlz[2 * i + j] += lz[i];\n\
    \t\t\t}\n\t\t}\n\t\tlz[i] = 0;\n\t}\n\n\tvoid upd(int lo, int hi, T inc, int i\
    \ = 1, int l = 0, int r = -1) {\n\t\tif (r == -1) {\n\t\t\tr += sz;\n\t\t}\n\t\
    \tpush(i, l, r);\n\t\tif (r < lo || hi < l) {\n\n\t\t} else if (lo <= l && r <=\
    \ hi) {\n\t\t\tlz[i] = inc;\n\t\t\tpush(i, l, r);\n\t\t} else {\n\t\t\tint m =\
    \ (l + r) >> 1;\n\t\t\tupd(lo, hi, inc, 2 * i, l, m);\n\t\t\tupd(lo, hi, inc,\
    \ 2 * i + 1, m + 1, r);\n\t\t\tpull(i);\n\t\t}\n\t}\n\n\tU query(int lo, int hi,\
    \ int i = 1, int l = 0, int r = -1) {\n\t\tif (r == -1) {\n\t\t\tr += sz;\n\t\t\
    }\n\t\tpush(i, l, r);\n\t\tif (r < lo || hi < l) {\n\t\t\treturn ID;\n\t\t} else\
    \ if (lo <= l && r <= hi) {\n\t\t\treturn st[i];\n\t\t} else {\n\t\t\tint m =\
    \ (l + r) >> 1;\n\t\t\treturn comb(query(lo, hi, 2 * i, l, m), query(lo, hi, 2\
    \ * i + 1, m + 1, r));\n\t\t}\n\t}\n\n\tint zeros(int lo, int hi) {\n\t\tauto\
    \ res = query(lo, hi);\n\t\tif (res.first == 0) {\n\t\t\treturn res.second;\n\t\
    \t} else {\n\t\t\treturn 0;\n\t\t}\n\t}\n};\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tLCARMQ L;\n\tL.init(n);\n\
    \tvector<vector<int>> g(n);\n\tfor (int i = 0; i < n - 1; ++i) {\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\t--u, --v;\n\t\tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\
    \t\tL.ae(u, v);\n\t}\t\n\tvector<int> in(n);\n\tvector<int> out(n);\n\tint ti\
    \ = 0;\n\tfunction<void(int, int)> dfs = [&](int u, int p) {\n\t\tin[u] = ti++;\n\
    \t\tfor (int v : g[u]) {\n\t\t\tif (v != p) {\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\
    \t}\n\t\tout[u] = ti - 1;\n\t};\n\tdfs(0, -1);\n\tL.gen(0);\n\tset<pair<int, int>>\
    \ used;\n\tSegmentTree<int> seg;\n\tseg.init(n);\t\n\twhile (q--) {\n\t\tint u,\
    \ v;\n\t\tcin >> u >> v;\n\t\t--u, --v;\n\t\tif (u > v) {\n\t\t\tswap(u, v);\n\
    \t\t}\n\t\tauto add = [&](int u, int v, int t) {\n\t\t\tint lca = L.lca(u, v);\n\
    \t\t\tif (lca == v) {\n\t\t\t\tswap(u, v);\n\t\t\t}\n\t\t\tif (lca == u) {\n\t\
    \t\t\tint child = L.get_child(u, v);\n\t\t\t\tseg.upd(in[child], out[child], t);\n\
    \t\t\t\tseg.upd(in[v], out[v], -t);\n\t\t\t} else {\n\t\t\t\tseg.upd(0, n - 1,\
    \ t);\n\t\t\t\tseg.upd(in[u], out[u], -t);\n\t\t\t\tseg.upd(in[v], out[v], -t);\n\
    \t\t\t}\n\t\t};\n\t\tif (used.count(make_pair(u, v))) {\n\t\t\tused.erase(make_pair(u,\
    \ v));\n\t\t\tadd(u, v, -1);\n\t\t} else {\n\t\t\tused.emplace(u, v);\n\t\t\t\
    add(u, v, 1);\n\t\t}\n\t\tcout << seg.zeros(0, n - 1) << '\\n';\n\t}\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/lca-rmq.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1074F.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 19:45:54-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1074F.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1074F.test.cpp
- /verify/verify/codeforces/codeforces-1074F.test.cpp.html
title: verify/codeforces/codeforces-1074F.test.cpp
---

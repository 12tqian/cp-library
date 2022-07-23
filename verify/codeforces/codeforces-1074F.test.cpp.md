---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/sparse-table.hpp
    title: Sparse Table
  - icon: ':question:'
    path: library/graphs/lca-rmq.hpp
    title: LCA RMQ
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
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/1074/problem/F\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\ntemplate <class T> struct\
    \ SparseTable {\r\n\tstd::vector<T> v;\r\n\tstd::vector<std::vector<int>> jump;\r\
    \n\r\n\tint level(int x) { return 31 - __builtin_clz(x); }\r\n\r\n\tint comb(int\
    \ a, int b) {\r\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a :\
    \ b);\r\n\t}\r\n\r\n\tvoid init(const std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\
    \t\tjump = {std::vector<int>((int)v.size())};\r\n\t\tiota(jump[0].begin(), jump[0].end(),\
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
    return ret;\r\n\t}\r\n};\r\n\r\ntemplate <class T> struct SegmentTree {\r\n\t\
    using U = pair<T, int>;\r\n\r\n\tconst U ID = make_pair(numeric_limits<T>::max(),\
    \ 1);\r\n\r\n\tint sz;\t\r\n\t\r\n\tvector<U> st; // min, cnt\r\n\tvector<T> lz;\
    \ // lazy\r\n\r\n\tvoid init(int _sz) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < _sz)\
    \ {\r\n\t\t\tsz <<= 1;\r\n\t\t}\r\n\t\tst.assign(2 * sz, make_pair(0, 1));\r\n\
    \t\tlz.assign(2 * sz, 0);\r\n\t\tfor (int i = sz - 1; i >= 1; --i) {\r\n\t\t\t\
    pull(i);\r\n\t\t}\r\n\t}\r\n\r\n\tU comb(U x, U y) {\r\n\t\tU res;\r\n\t\tif (x.first\
    \ < y.first) {\r\n\t\t\tres = x;\r\n\t\t} else if (x.first > y.first) {\r\n\t\t\
    \tres = y;\r\n\t\t} else {\r\n\t\t\tres.first = x.first;\r\n\t\t\tres.second =\
    \ x.second + y.second;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tvoid pull(int\
    \ i) {\r\n\t\tst[i] = comb(st[2 * i], st[2 * i + 1]);\r\n\t}\r\n\r\n\tvoid push(int\
    \ i, int l, int r) {\r\n\t\tif (lz[i] == 0) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\t\
    st[i].first += lz[i];\r\n\t\tif (l != r) {\r\n\t\t\tfor (int j = 0; j < 2; ++j)\
    \ {\r\n\t\t\t\tlz[2 * i + j] += lz[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\tlz[i] = 0;\r\
    \n\t}\r\n\r\n\tvoid upd(int lo, int hi, T inc, int i = 1, int l = 0, int r = -1)\
    \ {\r\n\t\tif (r == -1) {\r\n\t\t\tr += sz;\r\n\t\t}\r\n\t\tpush(i, l, r);\r\n\
    \t\tif (r < lo || hi < l) {\r\n\r\n\t\t} else if (lo <= l && r <= hi) {\r\n\t\t\
    \tlz[i] = inc;\r\n\t\t\tpush(i, l, r);\r\n\t\t} else {\r\n\t\t\tint m = (l + r)\
    \ >> 1;\r\n\t\t\tupd(lo, hi, inc, 2 * i, l, m);\r\n\t\t\tupd(lo, hi, inc, 2 *\
    \ i + 1, m + 1, r);\r\n\t\t\tpull(i);\r\n\t\t}\r\n\t}\r\n\r\n\tU query(int lo,\
    \ int hi, int i = 1, int l = 0, int r = -1) {\r\n\t\tif (r == -1) {\r\n\t\t\t\
    r += sz;\r\n\t\t}\r\n\t\tpush(i, l, r);\r\n\t\tif (r < lo || hi < l) {\r\n\t\t\
    \treturn ID;\r\n\t\t} else if (lo <= l && r <= hi) {\r\n\t\t\treturn st[i];\r\n\
    \t\t} else {\r\n\t\t\tint m = (l + r) >> 1;\r\n\t\t\treturn comb(query(lo, hi,\
    \ 2 * i, l, m), query(lo, hi, 2 * i + 1, m + 1, r));\r\n\t\t}\r\n\t}\r\n\r\n\t\
    int zeros(int lo, int hi) {\r\n\t\tauto res = query(lo, hi);\r\n\t\tif (res.first\
    \ == 0) {\r\n\t\t\treturn res.second;\r\n\t\t} else {\r\n\t\t\treturn 0;\r\n\t\
    \t}\r\n\t}\r\n};\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tLCARMQ L;\r\n\tL.init(n);\r\n\tvector<vector<int>>\
    \ g(n);\r\n\tfor (int i = 0; i < n - 1; ++i) {\r\n\t\tint u, v;\r\n\t\tcin >>\
    \ u >> v;\r\n\t\t--u, --v;\r\n\t\tg[u].push_back(v);\r\n\t\tg[v].push_back(u);\r\
    \n\t\tL.ae(u, v);\r\n\t}\t\r\n\tvector<int> in(n);\r\n\tvector<int> out(n);\r\n\
    \tint ti = 0;\r\n\tfunction<void(int, int)> dfs = [&](int u, int p) {\r\n\t\t\
    in[u] = ti++;\r\n\t\tfor (int v : g[u]) {\r\n\t\t\tif (v != p) {\r\n\t\t\t\tdfs(v,\
    \ u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tout[u] = ti - 1;\r\n\t};\r\n\tdfs(0, -1);\r\n\
    \tL.gen(0);\r\n\tset<pair<int, int>> used;\r\n\tSegmentTree<int> seg;\r\n\tseg.init(n);\t\
    \r\n\twhile (q--) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\t--u, --v;\r\n\
    \t\tif (u > v) {\r\n\t\t\tswap(u, v);\r\n\t\t}\r\n\t\tauto add = [&](int u, int\
    \ v, int t) {\r\n\t\t\tint lca = L.lca(u, v);\r\n\t\t\tif (lca == v) {\r\n\t\t\
    \t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\tif (lca == u) {\r\n\t\t\t\tint child = L.get_child(u,\
    \ v);\r\n\t\t\t\tseg.upd(in[child], out[child], t);\r\n\t\t\t\tseg.upd(in[v],\
    \ out[v], -t);\r\n\t\t\t} else {\r\n\t\t\t\tseg.upd(0, n - 1, t);\r\n\t\t\t\t\
    seg.upd(in[u], out[u], -t);\r\n\t\t\t\tseg.upd(in[v], out[v], -t);\r\n\t\t\t}\r\
    \n\t\t};\r\n\t\tif (used.count(make_pair(u, v))) {\r\n\t\t\tused.erase(make_pair(u,\
    \ v));\r\n\t\t\tadd(u, v, -1);\r\n\t\t} else {\r\n\t\t\tused.emplace(u, v);\r\n\
    \t\t\tadd(u, v, 1);\r\n\t\t}\r\n\t\tcout << seg.zeros(0, n - 1) << '\\n';\r\n\t\
    }\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/1074/problem/F\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/lca-rmq.hpp\"\
    \r\n\r\ntemplate <class T> struct SegmentTree {\r\n\tusing U = pair<T, int>;\r\
    \n\r\n\tconst U ID = make_pair(numeric_limits<T>::max(), 1);\r\n\r\n\tint sz;\t\
    \r\n\t\r\n\tvector<U> st; // min, cnt\r\n\tvector<T> lz; // lazy\r\n\r\n\tvoid\
    \ init(int _sz) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < _sz) {\r\n\t\t\tsz <<= 1;\r\
    \n\t\t}\r\n\t\tst.assign(2 * sz, make_pair(0, 1));\r\n\t\tlz.assign(2 * sz, 0);\r\
    \n\t\tfor (int i = sz - 1; i >= 1; --i) {\r\n\t\t\tpull(i);\r\n\t\t}\r\n\t}\r\n\
    \r\n\tU comb(U x, U y) {\r\n\t\tU res;\r\n\t\tif (x.first < y.first) {\r\n\t\t\
    \tres = x;\r\n\t\t} else if (x.first > y.first) {\r\n\t\t\tres = y;\r\n\t\t} else\
    \ {\r\n\t\t\tres.first = x.first;\r\n\t\t\tres.second = x.second + y.second;\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tvoid pull(int i) {\r\n\t\tst[i] = comb(st[2\
    \ * i], st[2 * i + 1]);\r\n\t}\r\n\r\n\tvoid push(int i, int l, int r) {\r\n\t\
    \tif (lz[i] == 0) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tst[i].first += lz[i];\r\n\
    \t\tif (l != r) {\r\n\t\t\tfor (int j = 0; j < 2; ++j) {\r\n\t\t\t\tlz[2 * i +\
    \ j] += lz[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\tlz[i] = 0;\r\n\t}\r\n\r\n\tvoid upd(int\
    \ lo, int hi, T inc, int i = 1, int l = 0, int r = -1) {\r\n\t\tif (r == -1) {\r\
    \n\t\t\tr += sz;\r\n\t\t}\r\n\t\tpush(i, l, r);\r\n\t\tif (r < lo || hi < l) {\r\
    \n\r\n\t\t} else if (lo <= l && r <= hi) {\r\n\t\t\tlz[i] = inc;\r\n\t\t\tpush(i,\
    \ l, r);\r\n\t\t} else {\r\n\t\t\tint m = (l + r) >> 1;\r\n\t\t\tupd(lo, hi, inc,\
    \ 2 * i, l, m);\r\n\t\t\tupd(lo, hi, inc, 2 * i + 1, m + 1, r);\r\n\t\t\tpull(i);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tU query(int lo, int hi, int i = 1, int l = 0, int r =\
    \ -1) {\r\n\t\tif (r == -1) {\r\n\t\t\tr += sz;\r\n\t\t}\r\n\t\tpush(i, l, r);\r\
    \n\t\tif (r < lo || hi < l) {\r\n\t\t\treturn ID;\r\n\t\t} else if (lo <= l &&\
    \ r <= hi) {\r\n\t\t\treturn st[i];\r\n\t\t} else {\r\n\t\t\tint m = (l + r) >>\
    \ 1;\r\n\t\t\treturn comb(query(lo, hi, 2 * i, l, m), query(lo, hi, 2 * i + 1,\
    \ m + 1, r));\r\n\t\t}\r\n\t}\r\n\r\n\tint zeros(int lo, int hi) {\r\n\t\tauto\
    \ res = query(lo, hi);\r\n\t\tif (res.first == 0) {\r\n\t\t\treturn res.second;\r\
    \n\t\t} else {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n};\r\n\r\nint main() {\r\n\
    \tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n, q;\r\n\tcin\
    \ >> n >> q;\r\n\tLCARMQ L;\r\n\tL.init(n);\r\n\tvector<vector<int>> g(n);\r\n\
    \tfor (int i = 0; i < n - 1; ++i) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\
    \t\t--u, --v;\r\n\t\tg[u].push_back(v);\r\n\t\tg[v].push_back(u);\r\n\t\tL.ae(u,\
    \ v);\r\n\t}\t\r\n\tvector<int> in(n);\r\n\tvector<int> out(n);\r\n\tint ti =\
    \ 0;\r\n\tfunction<void(int, int)> dfs = [&](int u, int p) {\r\n\t\tin[u] = ti++;\r\
    \n\t\tfor (int v : g[u]) {\r\n\t\t\tif (v != p) {\r\n\t\t\t\tdfs(v, u);\r\n\t\t\
    \t}\r\n\t\t}\r\n\t\tout[u] = ti - 1;\r\n\t};\r\n\tdfs(0, -1);\r\n\tL.gen(0);\r\
    \n\tset<pair<int, int>> used;\r\n\tSegmentTree<int> seg;\r\n\tseg.init(n);\t\r\
    \n\twhile (q--) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\t--u, --v;\r\n\t\
    \tif (u > v) {\r\n\t\t\tswap(u, v);\r\n\t\t}\r\n\t\tauto add = [&](int u, int\
    \ v, int t) {\r\n\t\t\tint lca = L.lca(u, v);\r\n\t\t\tif (lca == v) {\r\n\t\t\
    \t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\tif (lca == u) {\r\n\t\t\t\tint child = L.get_child(u,\
    \ v);\r\n\t\t\t\tseg.upd(in[child], out[child], t);\r\n\t\t\t\tseg.upd(in[v],\
    \ out[v], -t);\r\n\t\t\t} else {\r\n\t\t\t\tseg.upd(0, n - 1, t);\r\n\t\t\t\t\
    seg.upd(in[u], out[u], -t);\r\n\t\t\t\tseg.upd(in[v], out[v], -t);\r\n\t\t\t}\r\
    \n\t\t};\r\n\t\tif (used.count(make_pair(u, v))) {\r\n\t\t\tused.erase(make_pair(u,\
    \ v));\r\n\t\t\tadd(u, v, -1);\r\n\t\t} else {\r\n\t\t\tused.emplace(u, v);\r\n\
    \t\t\tadd(u, v, 1);\r\n\t\t}\r\n\t\tcout << seg.zeros(0, n - 1) << '\\n';\r\n\t\
    }\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/lca-rmq.hpp
  - library/data-structures/1d-range-queries/sparse-table.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-1074F.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-1074F.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-1074F.test.cpp
- /verify/verify/codeforces/codeforces-1074F.test.cpp.html
title: verify/codeforces/codeforces-1074F.test.cpp
---

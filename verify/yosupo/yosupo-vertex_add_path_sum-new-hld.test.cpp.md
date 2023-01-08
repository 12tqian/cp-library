---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
    title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/heavy-light-decomposition.hpp
    title: library/graphs/heavy-light-decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class G> \r\nstruct\
    \ HeavyLightDecomposition {\r\nprivate:\r\n\tvoid dfs_sz(int cur) {\r\n\t\tsize[cur]\
    \ = 1;\r\n\t\tfor (auto& dst : g[cur]) {\r\n\t\t\tif (dst == par[cur]) {\r\n\t\
    \t\t\tif (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\r\n\t\t\t\t\tstd::swap(g[cur][0],\
    \ g[cur][1]);\r\n\t\t\t\telse\r\n\t\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdepth[dst]\
    \ = depth[cur] + 1;\r\n\t\t\tpar[dst] = cur;\r\n\t\t\tdfs_sz(dst);\r\n\t\t\tsize[cur]\
    \ += size[dst];\r\n\t\t\tif (size[dst] > size[g[cur][0]]) {\r\n\t\t\t\tstd::swap(dst,\
    \ g[cur][0]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dfs_hld(int cur) {\r\n\t\
    \tdown[cur] = id++;\r\n\t\tfor (auto dst : g[cur]) {\r\n\t\t\tif (dst == par[cur])\
    \ continue;\r\n\t\t\tnxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\r\
    \n\t\t\tdfs_hld(dst);\r\n\t\t}\r\n\t\tup[cur] = id;\r\n\t}\r\n\r\n\t// [u, v)\r\
    \n\tstd::vector<std::pair<int, int>> ascend(int u, int v) const {\r\n\t\tstd::vector<std::pair<int,\
    \ int>> res;\r\n\t\twhile (nxt[u] != nxt[v]) {\r\n\t\t\tres.emplace_back(down[u],\
    \ down[nxt[u]]);\r\n\t\t\tu = par[nxt[u]];\r\n\t\t}\r\n\t\tif (u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\r\n\t\treturn res;\r\n\t}\r\n\r\n\t// (u, v]\r\n\tstd::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\r\n\t\tif (u == v) return {};\r\n\t\tif\
    \ (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\r\n\t\tauto res = descend(u,\
    \ par[nxt[v]]);\r\n\t\tres.emplace_back(down[nxt[v]], down[v]);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\r\npublic:\r\n\tG g;\r\n\tint id;\r\n\tstd::vector<int> size,\
    \ depth, down, up, nxt, par;\r\n\r\n\tHeavyLightDecomposition(G& _g, std::vector<int>\
    \ roots = {0})\r\n\t\t\t: g(_g),\r\n\t\t\t\tid(0),\r\n\t\t\t\tsize(g.size(), 0),\r\
    \n\t\t\t\tdepth(g.size(), 0),\r\n\t\t\t\tdown(g.size(), -1),\r\n\t\t\t\tup(g.size(),\
    \ -1),\r\n\t\t\t\tnxt(g.size(), 0), \r\n\t\t\t\tpar(g.size(), 0) {\r\n\t\tfor\
    \ (int root : roots) {\r\n\t\t\tpar[root] = nxt[root] = root;\r\n\t\t\tdfs_sz(root);\r\
    \n\t\t\tdfs_hld(root);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build(std::vector<int> roots)\
    \ {\r\n\t\tfor (int root : roots) {\r\n\t\t\tpar[root] = nxt[root] = root;\r\n\
    \t\t\tdfs_sz(root);\r\n\t\t\tdfs_hld(root);\r\n\t\t}\r\n\t}\r\n\r\n\t// [l, r],\
    \ inclusive for subtree\r\n\tstd::pair<int, int> idx(int i) const { return {down[i],\
    \ up[i] - 1}; }\r\n\r\n\ttemplate <class F>\r\n\tvoid path_query(int u, int v,\
    \ bool vertex, const F& f) {\r\n\t\tint l = lca(u, v);\r\n\t\tfor (auto&& [a,\
    \ b] : ascend(u, l)) {\r\n\t\t\tint s = a + 1, t = b;\r\n\t\t\ts > t ? f(t, s\
    \ - 1) : f(s, t - 1);\r\n\t\t}\r\n\t\tif (vertex) f(down[l], down[l]);\r\n\t\t\
    for (auto&& [a, b] : descend(l, v)) {\r\n\t\t\tint s = a, t = b + 1;\r\n\t\t\t\
    s > t ? f(t, s - 1) : f(s, t - 1);\r\n\t\t}\r\n\t}\r\n\r\n\ttemplate <class F>\r\
    \n\tvoid path_noncommutative_query(int u, int v, bool vertex, const F& f) {\r\n\
    \t\tint l = lca(u, v);\r\n\t\tfor (auto&& [a, b] : ascend(u, l)) f(a + 1, b -\
    \ 1);\r\n\t\tif (vertex) f(down[l], down[l]);\r\n\t\tfor (auto&& [a, b] : descend(l,\
    \ v)) f(a, b);\r\n\t}\r\n\r\n\ttemplate <class F>\r\n\tvoid subtree_query(int\
    \ u, bool vertex, const F& f) {\r\n\t\tf(down[u] + int(!vertex), up[u] - 1);\r\
    \n\t}\r\n\r\n\tint lca(int a, int b) {\r\n\t\twhile (nxt[a] != nxt[b]) {\r\n\t\
    \t\tif (down[a] < down[b]) std::swap(a, b);\r\n\t\t\ta = par[nxt[a]];\r\n\t\t\
    }\r\n\t\treturn depth[a] < depth[b] ? a : b;\r\n\t}\r\n\r\n\tint dist(int a, int\
    \ b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\r\n};\n\r\ntemplate\
    \ <class D, class L, class OpDD, class OpDL, class OpLL> struct LazySegmentTree\
    \ {\r\n\tD e_d;\r\n\tL e_l;\r\n\tOpDD op_dd; \r\n\tOpDL op_dl;\r\n\tOpLL op_ll;\r\
    \n\tint sz, lg;  \r\n\tstd::vector<D> d;\r\n\tstd::vector<L> lz;\r\n\r\n\tvoid\
    \ init(const std::vector<D>& v) {\r\n\t\tint n = int(v.size());\r\n\t\tlg = 1;\r\
    \n\t\twhile ((1 << lg) < n) lg++;\r\n\t\tsz = 1 << lg;\r\n\t\td = std::vector<D>(2\
    \ * sz, e_d);\r\n\t\tlz = std::vector<L>(2 * sz, e_l);\r\n\t\tfor (int i = 0;\
    \ i < n; i++) d[sz + i] = v[i];\r\n\t\tfor (int i = sz - 1; i >= 0; i--) {\r\n\
    \t\t\tupdate(i);\r\n\t\t}\r\n\t}\r\n\r\n\tLazySegmentTree(const std::vector<D>&\
    \ v,\r\n\t\t\tD _e_d,\r\n\t\t\tL _e_l,\r\n\t\t\tOpDD _op_dd,\r\n\t\t\tOpDL _op_dl,\r\
    \n\t\t\tOpLL _op_ll)\r\n\t\t: e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl),\
    \ op_ll(_op_ll) {\r\n\t\tinit(v);\r\n\t}\r\n\r\n\tvoid all_add(int k, L x) {\r\
    \n\t\td[k] = op_dl(d[k], x);\r\n\t\tif (k < sz) lz[k] = op_ll(lz[k], x);\r\n\t\
    }\r\n\r\n\tvoid push(int k) {\r\n\t\tall_add(2 * k, lz[k]);\r\n\t\tall_add(2 *\
    \ k + 1, lz[k]);\r\n\t\tlz[k] = e_l;\r\n\t}\r\n\r\n\tvoid update(int k) { d[k]\
    \ = op_dd(d[2 * k], d[2 * k + 1]); }\r\n\r\n\tvoid set(int p, D x) {\r\n\t\tp\
    \ += sz;\r\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\r\n\t\td[p] = x;\r\
    \n\t\tfor (int i = 1; i <= lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tvoid add(int\
    \ a, int b, L x, int l, int r, int k) {\r\n\t\tif (b <= l || r <= a) return;\r\
    \n\t\tif (a <= l && r <= b) {\r\n\t\t\tall_add(k, x);\r\n\t\t\treturn;\r\n\t\t\
    }\r\n\t\tpush(k);\r\n\t\tint mid = (l + r) / 2;\r\n\t\tadd(a, b, x, l, mid, 2\
    \ * k);\r\n\t\tadd(a, b, x, mid, r, 2 * k + 1);\r\n\t\tupdate(k);\r\n\t}\r\n\r\
    \n\tvoid add(int a, int b, L x) {\r\n\t\t++b;\r\n\t\ta += sz;\r\n\t\tb += sz;\r\
    \n\t\tfor (int i = lg; i >= 1; i--) {\r\n\t\t\tif (((a >> i) << i) != a) push(a\
    \ >> i);\r\n\t\t\tif (((b >> i) << i) != b) push((b - 1) >> i);\r\n\t\t}\r\n\t\
    \t{\r\n\t\t\tint a2 = a, b2 = b;\r\n\t\t\twhile (a < b) {\r\n\t\t\t\tif (a & 1)\
    \ all_add(a++, x);\r\n\t\t\t\tif (b & 1) all_add(--b, x);\r\n\t\t\t\ta >>= 1;\r\
    \n\t\t\t\tb >>= 1;\r\n\t\t\t}\r\n\t\t\ta = a2;\r\n\t\t\tb = b2;\r\n\t\t}\r\n\t\
    \tfor (int i = 1; i <= lg; i++) {\r\n\t\t\tif (((a >> i) << i) != a) update(a\
    \ >> i);\r\n\t\t\tif (((b >> i) << i) != b) update((b - 1) >> i);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tD single(int p) {\r\n\t\tp += sz;\r\n\t\tfor (int i = lg; i >= 1;\
    \ i--) push(p >> i);\r\n\t\treturn d[p];\r\n\t}\r\n\r\n\tD sum(int a, int b, int\
    \ l, int r, int k) {\r\n\t\tif (b <= l || r <= a) return e_d;\r\n\t\tif (a <=\
    \ l && r <= b) return d[k];\r\n\t\tpush(k);\r\n\t\tint mid = (l + r) / 2;\r\n\t\
    \treturn op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));\r\n\t\
    }\r\n\r\n\tD sum(int a, int b) {\r\n\t\t++b;\r\n\t\tif (a == b) return e_d;\r\n\
    \t\ta += sz;\r\n\t\tb += sz;\r\n\t\tfor (int i = lg; i >= 1; i--) {\r\n\t\t\t\
    if (((a >> i) << i) != a) push(a >> i);\r\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\r\n\t\t}\r\n\t\tD sml = e_d, smr = e_d;\r\n\t\twhile (a < b) {\r\
    \n\t\t\tif (a & 1) sml = op_dd(sml, d[a++]);\r\n\t\t\tif (b & 1) smr = op_dd(d[--b],\
    \ smr);\r\n\t\t\ta >>= 1;\r\n\t\t\tb >>= 1;\r\n\t\t}\r\n\t\treturn op_dd(sml,\
    \ smr);\r\n\t}\r\n\r\n\tD all_sum() const { return d[1]; }\r\n};\r\n\r\ntemplate\
    \ <class D, class L, class OpDD, class OpDL, class OpLL>\r\nLazySegmentTree<D,\
    \ L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D> v,\r\n\t\t\t\t\t\t\
    \t\t\t\tD e_d,\r\n\t\t\t\t\t\t\t\t\t\tL e_l,\r\n\t\t\t\t\t\t\t\t\t\tOpDD op_dd,\r\
    \n\t\t\t\t\t\t\t\t\t\tOpDL op_dl,\r\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll) {\r\n\treturn\
    \ LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);\r\
    \n}\r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(false);\r\
    \n\tint n, q;\r\n\tstruct Node {\r\n\t\tlong long v;\r\n\t\tint size;\r\n\t\t\r\
    \n\t\tNode() : v(0), size(1) {}\r\n\t\tNode(long long _v, int _size) : v(_v),\
    \ size(_size) {}\r\n\t};\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\tcin >> a[i];\r\n\tvector<vector<int>> graph(n);\r\n\
    \tfor (int i = 0; i < n - 1; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\
    \t\tgraph[u].push_back(v);\r\n\t\tgraph[v].push_back(u);\r\n\t}\r\n\tHeavyLightDecomposition\
    \ H(graph);\r\n\tauto seg = get_lazy_segment_tree(\r\n\t\tvector<Node>(n),\r\n\
    \t\tNode(), 0LL,\r\n\t\t[&](Node x, Node y) { return Node{x.v + y.v, x.size +\
    \ y.size}; },\r\n\t\t[&](Node x, long long y) { return Node{x.v + y * x.size,\
    \ x.size}; },\r\n\t\t[&](long long x, long long y) { return x + y; }\r\n\t);\r\
    \n\tfor (int i = 0; i < n; i++)\r\n\t\tH.path_query(i, i, true, [&](int l, int\
    \ r) {\r\n\t\t\tseg.add(l, r, a[i]);\r\n\t\t});\r\n\twhile (q--) {\r\n\t\tint\
    \ t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >>\
    \ p >> x;\r\n\t\t\tH.path_query(p, p, true, [&](int l, int r) {\r\n\t\t\t\tseg.add(l,\
    \ r, x);\r\n\t\t\t});\r\n\t\t} else\t{\r\n\t\t\tint u, v;\r\n\t\t\tcin >> u >>\
    \ v;\r\n\t\t\tlong long ans = 0;\r\n\t\t\tH.path_query(u, v, true, [&](int l,\
    \ int r) {\r\n\t\t\t\tans += seg.sum(l, r).v;\r\n\t\t\t});\r\n\t\t\tcout << ans\
    \ << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/heavy-light-decomposition.hpp\"\
    \r\n#include \"../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(false);\r\
    \n\tint n, q;\r\n\tstruct Node {\r\n\t\tlong long v;\r\n\t\tint size;\r\n\t\t\r\
    \n\t\tNode() : v(0), size(1) {}\r\n\t\tNode(long long _v, int _size) : v(_v),\
    \ size(_size) {}\r\n\t};\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\tcin >> a[i];\r\n\tvector<vector<int>> graph(n);\r\n\
    \tfor (int i = 0; i < n - 1; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\
    \t\tgraph[u].push_back(v);\r\n\t\tgraph[v].push_back(u);\r\n\t}\r\n\tHeavyLightDecomposition\
    \ H(graph);\r\n\tauto seg = get_lazy_segment_tree(\r\n\t\tvector<Node>(n),\r\n\
    \t\tNode(), 0LL,\r\n\t\t[&](Node x, Node y) { return Node{x.v + y.v, x.size +\
    \ y.size}; },\r\n\t\t[&](Node x, long long y) { return Node{x.v + y * x.size,\
    \ x.size}; },\r\n\t\t[&](long long x, long long y) { return x + y; }\r\n\t);\r\
    \n\tfor (int i = 0; i < n; i++)\r\n\t\tH.path_query(i, i, true, [&](int l, int\
    \ r) {\r\n\t\t\tseg.add(l, r, a[i]);\r\n\t\t});\r\n\twhile (q--) {\r\n\t\tint\
    \ t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >>\
    \ p >> x;\r\n\t\t\tH.path_query(p, p, true, [&](int l, int r) {\r\n\t\t\t\tseg.add(l,\
    \ r, x);\r\n\t\t\t});\r\n\t\t} else\t{\r\n\t\t\tint u, v;\r\n\t\t\tcin >> u >>\
    \ v;\r\n\t\t\tlong long ans = 0;\r\n\t\t\tH.path_query(u, v, true, [&](int l,\
    \ int r) {\r\n\t\t\t\tans += seg.sum(l, r).v;\r\n\t\t\t});\r\n\t\t\tcout << ans\
    \ << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/heavy-light-decomposition.hpp
  - library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
- /verify/verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp.html
title: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
    title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  - icon: ':x:'
    path: library/graphs/heavy-light-decomposition.hpp
    title: library/graphs/heavy-light-decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    template <class G> \nstruct HeavyLightDecomposition {\nprivate:\n\tvoid dfs_sz(int\
    \ cur) {\n\t\tsize[cur] = 1;\n\t\tfor (auto& dst : g[cur]) {\n\t\t\tif (dst ==\
    \ par[cur]) {\n\t\t\t\tif (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \t\t\t\t\tswap(g[cur][0], g[cur][1]);\n\t\t\t\telse\n\t\t\t\t\tcontinue;\n\t\t\
    \t}\n\t\t\tdepth[dst] = depth[cur] + 1;\n\t\t\tpar[dst] = cur;\n\t\t\tdfs_sz(dst);\n\
    \t\t\tsize[cur] += size[dst];\n\t\t\tif (size[dst] > size[g[cur][0]]) {\n\t\t\t\
    \tswap(dst, g[cur][0]);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs_hld(int cur) {\n\t\t\
    down[cur] = id++;\n\t\tfor (auto dst : g[cur]) {\n\t\t\tif (dst == par[cur]) continue;\n\
    \t\t\tnxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\t\t\tdfs_hld(dst);\n\
    \t\t}\n\t\tup[cur] = id;\n\t}\n\n\t// [u, v)\n\tstd::vector<std::pair<int, int>>\
    \ ascend(int u, int v) const {\n\t\tstd::vector<std::pair<int, int>> res;\n\t\t\
    while (nxt[u] != nxt[v]) {\n\t\t\tres.emplace_back(down[u], down[nxt[u]]);\n\t\
    \t\tu = par[nxt[u]];\n\t\t}\n\t\tif (u != v) res.emplace_back(down[u], down[v]\
    \ + 1);\n\t\treturn res;\n\t}\n\n\t// (u, v]\n\tstd::vector<std::pair<int, int>>\
    \ descend(int u, int v) const {\n\t\tif (u == v) return {};\n\t\tif (nxt[u] ==\
    \ nxt[v]) return {{down[u] + 1, down[v]}};\n\t\tauto res = descend(u, par[nxt[v]]);\n\
    \t\tres.emplace_back(down[nxt[v]], down[v]);\n\t\treturn res;\n\t}\n\npublic:\n\
    \tG g;\n\tint id;\n\tstd::vector<int> size, depth, down, up, nxt, par;\n\t\n\t\
    HeavyLightDecomposition(G& _g, std::vector<int> roots = {0})\n\t\t\t: g(_g),\n\
    \t\t\t\tid(0),\n\t\t\t\tsize(g.size(), 0),\n\t\t\t\tdepth(g.size(), 0),\n\t\t\t\
    \tdown(g.size(), -1),\n\t\t\t\tup(g.size(), -1),\n\t\t\t\tnxt(g.size(), 0), \n\
    \t\t\t\tpar(g.size(), 0) {\n\t\tfor (int root : roots) {\n\t\t\tcout << g.size()\
    \ << endl;\n\t\t\tpar[root] = nxt[root] = root;\n\t\t\tdfs_sz(root);\n\t\t\tdfs_hld(root);\n\
    \t\t}\n\t}\n\n\tvoid build(std::vector<int> roots) {\n\t\tfor (int root : roots)\
    \ {\n\t\t\tpar[root] = nxt[root] = root;\n\t\t\tdfs_sz(root);\n\t\t\tdfs_hld(root);\n\
    \t\t}\n\t}\n\n\t// [l, r], inclusive for subtree\n\tstd::pair<int, int> idx(int\
    \ i) const { return {down[i], up[i] - 1}; }\n\n\ttemplate <class F>\n\tvoid path_query(int\
    \ u, int v, bool vertex, const F& f) {\n\t\tint l = lca(u, v);\n\t\tfor (auto&&\
    \ [a, b] : ascend(u, l)) {\n\t\t\tint s = a + 1, t = b;\n\t\t\ts > t ? f(t, s\
    \ - 1) : f(s, t - 1);\n\t\t}\n\t\tif (vertex) f(down[l], down[l]);\n\t\tfor (auto&&\
    \ [a, b] : descend(l, v)) {\n\t\t\tint s = a, t = b + 1;\n\t\t\ts > t ? f(t, s\
    \ - 1) : f(s, t - 1);\n\t\t}\n\t}\n\n\ttemplate <class F>\n\tvoid path_noncommutative_query(int\
    \ u, int v, bool vertex, const F& f) {\n\t\tint l = lca(u, v);\n\t\tfor (auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b - 1);\n\t\tif (vertex) f(down[l], down[l]);\n\
    \t\tfor (auto&& [a, b] : descend(l, v)) f(a, b);\n\t}\n\n\ttemplate <class F>\n\
    \tvoid subtree_query(int u, bool vertex, const F& f) {\n\t\tf(down[u] + int(!vertex),\
    \ up[u] - 1);\n\t}\n\n\tint lca(int a, int b) {\n\t\twhile (nxt[a] != nxt[b])\
    \ {\n\t\t\tif (down[a] < down[b]) swap(a, b);\n\t\t\ta = par[nxt[a]];\n\t\t}\n\
    \t\treturn depth[a] < depth[b] ? a : b;\n\t}\n\n\tint dist(int a, int b) { return\
    \ depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n\ntemplate <class D, class\
    \ L, class OpDD, class OpDL, class OpLL> struct LazySegmentTree {\n\tD e_d;\n\t\
    L e_l;\n\tOpDD op_dd; \n\tOpDL op_dl;\n\tOpLL op_ll;\n\tint sz, lg;  \n\tstd::vector<D>\
    \ d;\n\tstd::vector<L> lz;\n\n\tLazySegmentTree(const std::vector<D>& v,\n\t\t\
    \tD _e_d,\n\t\t\tL _e_l,\n\t\t\tOpDD _op_dd,\n\t\t\tOpDL _op_dl,\n\t\t\tOpLL _op_ll)\n\
    \t\t: e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {\n\t\t\
    int n = int(v.size());\n\t\tlg = 1;\n\t\twhile ((1 << lg) < n) lg++;\n\t\tsz =\
    \ 1 << lg;\n\t\td = std::vector<D>(2 * sz, e_d);\n\t\tlz = std::vector<L>(2 *\
    \ sz, e_l);\n\t\tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\n\t\tfor (int i\
    \ = sz - 1; i >= 0; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\tvoid all_add(int\
    \ k, L x) {\n\t\td[k] = op_dl(d[k], x);\n\t\tif (k < sz) lz[k] = op_ll(lz[k],\
    \ x);\n\t}\n\n\tvoid push(int k) {\n\t\tall_add(2 * k, lz[k]);\n\t\tall_add(2\
    \ * k + 1, lz[k]);\n\t\tlz[k] = e_l;\n\t}\n\n\tvoid update(int k) { d[k] = op_dd(d[2\
    \ * k], d[2 * k + 1]); }\n\n\tvoid set(int p, D x) {\n\t\tp += sz;\n\t\tfor (int\
    \ i = lg; i >= 1; i--) push(p >> i);\n\t\td[p] = x;\n\t\tfor (int i = 1; i <=\
    \ lg; i++) update(p >> i);\n\t}\n\n\tvoid add(int a, int b, L x, int l, int r,\
    \ int k) {\n\t\tif (b <= l || r <= a) return;\n\t\tif (a <= l && r <= b) {\n\t\
    \t\tall_add(k, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k);\n\t\tint mid = (l + r)\
    \ / 2;\n\t\tadd(a, b, x, l, mid, 2 * k);\n\t\tadd(a, b, x, mid, r, 2 * k + 1);\n\
    \t\tupdate(k);\n\t}\n\n\tvoid add(int a, int b, L x) {\n\t\t++b;\n\t\ta += sz;\n\
    \t\tb += sz;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\t\tif (((a >> i) << i) !=\
    \ a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b - 1) >> i);\n\t\t\
    }\n\t\t{\n\t\t\tint a2 = a, b2 = b;\n\t\t\twhile (a < b) {\n\t\t\t\tif (a & 1)\
    \ all_add(a++, x);\n\t\t\t\tif (b & 1) all_add(--b, x);\n\t\t\t\ta >>= 1;\n\t\t\
    \t\tb >>= 1;\n\t\t\t}\n\t\t\ta = a2;\n\t\t\tb = b2;\n\t\t}\n\t\tfor (int i = 1;\
    \ i <= lg; i++) {\n\t\t\tif (((a >> i) << i) != a) update(a >> i);\n\t\t\tif (((b\
    \ >> i) << i) != b) update((b - 1) >> i);\n\t\t}\n\t}\n\n\tD single(int p) {\n\
    \t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\n\t\treturn d[p];\n\
    \t}\n\n\tD sum(int a, int b, int l, int r, int k) {\n\t\tif (b <= l || r <= a)\
    \ return e_d;\n\t\tif (a <= l && r <= b) return d[k];\n\t\tpush(k);\n\t\tint mid\
    \ = (l + r) / 2;\n\t\treturn op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r,\
    \ 2 * k + 1));\n\t}\n\n\tD sum(int a, int b) {\n\t\t++b;\n\t\tif (a == b) return\
    \ e_d;\n\t\ta += sz;\n\t\tb += sz;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\t\t\
    if (((a >> i) << i) != a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\n\t\t}\n\t\tD sml = e_d, smr = e_d;\n\t\twhile (a < b) {\n\t\t\t\
    if (a & 1) sml = op_dd(sml, d[a++]);\n\t\t\tif (b & 1) smr = op_dd(d[--b], smr);\n\
    \t\t\ta >>= 1;\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn op_dd(sml, smr);\n\t}\n\n\t\
    D all_sum() const { return d[1]; }\n};\n\ntemplate <class D, class L, class OpDD,\
    \ class OpDL, class OpLL>\nLazySegmentTree<D, L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D>\
    \ v,\n\t\t\t\t\t\t\t\t\t\tD e_d,\n\t\t\t\t\t\t\t\t\t\tL e_l,\n\t\t\t\t\t\t\t\t\
    \t\tOpDD op_dd,\n\t\t\t\t\t\t\t\t\t\tOpDL op_dl,\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll)\
    \ {\n\treturn LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl,\
    \ op_ll);\n}\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(false);\n\
    \tint n, q;\n\tstruct Node {\n\t\tlong long v;\n\t\tint size;\n\t\tNode() : v(0),\
    \ size(1) {}\n\t\tNode(long long _v, int _size) : v(_v), size(_size) {}\n\t};\n\
    \tcin >> n >> q;\n\tvector<int> a(n);\n\tfor (int i = 0; i < n; i++)\n\t\tcin\
    \ >> a[i];\n\tvector<vector<int>> graph(n);\n\tfor (int i = 0; i < n - 1; i++)\
    \ {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
    \t}\n\tHeavyLightDecomposition H(graph);\n\tauto seg = get_lazy_segment_tree(\n\
    \t\tvector<Node>(n),\n\t\tNode(), 0LL,\n\t\t[&](Node x, Node y) { return Node{x.v\
    \ + y.v, x.size + y.size}; },\n\t\t[&](Node x, long long y) { return Node{x.v\
    \ + y * x.size, x.size}; },\n\t\t[&](long long x, long long y) { return x + y;\
    \ }\n\t);\n\tfor (int i = 0; i < n; i++)\n\t\tH.path_query(i, i, true, [&](int\
    \ l, int r) {\n\t\t\tseg.add(l, r, a[i]);\n\t\t});\n\twhile (q--) {\n\t\tint t;\n\
    \t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\t\
    H.path_query(p, p, true, [&](int l, int r) {\n\t\t\t\tseg.add(l, r, x);\n\t\t\t\
    });\n\t\t} else\t{\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlong long ans\
    \ = 0;\n\t\t\tH.path_query(u, v, true, [&](int l, int r) {\n\t\t\t\tans += seg.sum(l,\
    \ r).v;\n\t\t\t});\n\t\t\tcout << ans << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/heavy-light-decomposition.hpp\"\
    \n#include \"../../library/data-structures/1d-range-queries/general-full-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(false);\n\
    \tint n, q;\n\tstruct Node {\n\t\tlong long v;\n\t\tint size;\n\t\tNode() : v(0),\
    \ size(1) {}\n\t\tNode(long long _v, int _size) : v(_v), size(_size) {}\n\t};\n\
    \tcin >> n >> q;\n\tvector<int> a(n);\n\tfor (int i = 0; i < n; i++)\n\t\tcin\
    \ >> a[i];\n\tvector<vector<int>> graph(n);\n\tfor (int i = 0; i < n - 1; i++)\
    \ {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
    \t}\n\tHeavyLightDecomposition H(graph);\n\tauto seg = get_lazy_segment_tree(\n\
    \t\tvector<Node>(n),\n\t\tNode(), 0LL,\n\t\t[&](Node x, Node y) { return Node{x.v\
    \ + y.v, x.size + y.size}; },\n\t\t[&](Node x, long long y) { return Node{x.v\
    \ + y * x.size, x.size}; },\n\t\t[&](long long x, long long y) { return x + y;\
    \ }\n\t);\n\tfor (int i = 0; i < n; i++)\n\t\tH.path_query(i, i, true, [&](int\
    \ l, int r) {\n\t\t\tseg.add(l, r, a[i]);\n\t\t});\n\twhile (q--) {\n\t\tint t;\n\
    \t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\t\
    H.path_query(p, p, true, [&](int l, int r) {\n\t\t\t\tseg.add(l, r, x);\n\t\t\t\
    });\n\t\t} else\t{\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlong long ans\
    \ = 0;\n\t\t\tH.path_query(u, v, true, [&](int l, int r) {\n\t\t\t\tans += seg.sum(l,\
    \ r).v;\n\t\t\t});\n\t\t\tcout << ans << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/heavy-light-decomposition.hpp
  - library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
  requiredBy: []
  timestamp: '2021-07-31 13:53:30-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
- /verify/verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp.html
title: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
---

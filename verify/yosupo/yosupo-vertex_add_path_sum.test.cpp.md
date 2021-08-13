---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/heavy-light-decomposition2.hpp
    title: Old Heavy Light Decomposition
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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\ntemplate <class T> struct LazySeg {\n\tstd::vector<T> sum, lazy;\n\tint sz;\n\
    \n\tvoid init(int sz_) {\n\t\tsz = 1;\n\t\twhile (sz < sz_) sz *= 2;\n\t\tsum.assign(2\
    \ * sz, 0);\n\t\tlazy.assign(2 * sz, 0);\n\t}\n\n\tvoid push(int ind, int L, int\
    \ R) {\n\t\tsum[ind] += (R - L + 1) * lazy[ind];\n\t\tif (L != R) {\n\t\t\tlazy[2\
    \ * ind] += lazy[ind];\n\t\t\tlazy[2 * ind + 1] += lazy[ind];\n\t\t}\n\t\tlazy[ind]\
    \ = 0;\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n\t}\n\n\tvoid build() {\n\t\tfor (int i = sz - 1; i >= 1; i--) {\n\t\t\
    \tpull(i);\n\t\t}\n\t}\n\n\tvoid upd(int lo, int hi, T inc, int ind = 1, int L\
    \ = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif\
    \ (hi < L || R < lo) return;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tlazy[ind] =\
    \ inc;\n\t\t\tpush(ind, L, R);\n\t\t\treturn;\n\t\t}\n\t\tint M = (L + R) / 2;\n\
    \t\tupd(lo, hi, inc, 2 * ind, L, M);\n\t\tupd(lo, hi, inc, 2 * ind + 1, M + 1,\
    \ R);\n\t\tpull(ind);\n\t}\n\n\tT qsum(int lo, int hi, int ind = 1, int L = 0,\
    \ int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo >\
    \ R || L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint\
    \ M = (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 *\
    \ ind + 1, M + 1, R);\n\t}\n};\n\nconst bool VALUES_IN_VERTICES = true;\n\ntemplate\
    \ <class T> struct HeavyLight {\n\tstd::vector<int> parent, heavy, depth, root,\
    \ tree_pos;\n\tLazySeg<T> tree;\n\n\ttemplate <class G> int dfs(const G &graph,\
    \ int v) {\n\t\tint size = 1, max_subtree = 0;\n\t\tfor (int u : graph[v]) if\
    \ (u != parent[v]) {\n\t\t\tparent[u] = v;\n\t\t\tdepth[u] = depth[v] + 1;\n\t\
    \t\tint subtree = dfs(graph, u);\n\t\t\tif (subtree > max_subtree) heavy[v] =\
    \ u, max_subtree = subtree;\n\t\t\tsize += subtree;\n\t\t}\n\t\treturn size;\n\
    \t}\n\n\ttemplate <class B> void process_path(int u, int v, B op) {\n\t\tfor (;\
    \ root[u] != root[v]; v = parent[root[v]]) {\n\t\t\tif (depth[root[u]] > depth[root[v]])\
    \ std::swap(u, v);\n\t\t\top(tree_pos[root[v]], tree_pos[v]);\n\t\t}\n\t\tif (depth[u]\
    \ > depth[v]) std::swap(u, v);\n\t\top(tree_pos[u] + (VALUES_IN_VERTICES ? 0 :\
    \ 1), tree_pos[v]);\n\t}\n\n\ttemplate <class G>\n\tvoid init(const G &graph,\
    \ int r = 0) {\n\t\tint n = (int)graph.size();\n\t\theavy.assign(n, -1);\n\t\t\
    parent.assign(n, 0);\n\t\tdepth.assign(n, 0);\n\t\troot.assign(n, 0);\n\t\ttree_pos.assign(n,\
    \ 0);\n\t\ttree.init(n);\n\t\tparent[r] = -1;\n\t\tdepth[r] = 0;\n\t\tdfs(graph,\
    \ r);\n\t\tfor (int i = 0, current_pos = 0; i < n; ++i)\n\t\t\tif (parent[i] ==\
    \ -1 || heavy[parent[i]] != i)\n\t\t\tfor (int j = i; j != -1; j = heavy[j]) {\n\
    \t\t\t\troot[j] = i;\n\t\t\t\ttree_pos[j] = current_pos++;\n\t\t\t}\n\t}\n\n\t\
    void modify_path(int u, int v, const T &value) {\n\t\tprocess_path(u, v, [this,\
    \ &value](int l, int r) { tree.upd(l, r, value); });\n\t}\n\t\n\tT query_path(int\
    \ u, int v) {\n\t\tT res = 0;\n\t\tprocess_path(u, v, [this, &res](int l, int\
    \ r) { res += tree.qsum(l, r); });\n\t\treturn res;\n\t}\n};\n\nint main() {\n\
    \tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(false);\n\tHeavyLight<long\
    \ long> H;\n\tint n, q; cin >> n >> q;\n\tvector<int> a(n);\n\tfor (int i = 0;\
    \ i < n; i++) cin >> a[i];\n\tvector<vector<int>> graph(n);\n\tfor (int i = 0;\
    \ i < n - 1; i++) {\n\t\tint u, v; cin >> u >> v;\n\t\tgraph[u].push_back(v);\n\
    \t\tgraph[v].push_back(u);\n\t}\n\tH.init(graph);\n\tfor (int i = 0; i < n; i++)\
    \ H.modify_path(i, i, a[i]);\n\twhile (q--) {\n\t\tint t; cin >> t;\n\t\tif (t\
    \ == 0) {\n\t\t\tint p, x; cin >> p >> x;\n\t\t\tH.modify_path(p, p, x);\n\t\t\
    } else {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tcout << H.query_path(u,\
    \ v) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/graphs/heavy-light-decomposition2.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(false);\n\
    \tHeavyLight<long long> H;\n\tint n, q; cin >> n >> q;\n\tvector<int> a(n);\n\t\
    for (int i = 0; i < n; i++) cin >> a[i];\n\tvector<vector<int>> graph(n);\n\t\
    for (int i = 0; i < n - 1; i++) {\n\t\tint u, v; cin >> u >> v;\n\t\tgraph[u].push_back(v);\n\
    \t\tgraph[v].push_back(u);\n\t}\n\tH.init(graph);\n\tfor (int i = 0; i < n; i++)\
    \ H.modify_path(i, i, a[i]);\n\twhile (q--) {\n\t\tint t; cin >> t;\n\t\tif (t\
    \ == 0) {\n\t\t\tint p, x; cin >> p >> x;\n\t\t\tH.modify_path(p, p, x);\n\t\t\
    } else {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tcout << H.query_path(u,\
    \ v) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/heavy-light-decomposition2.hpp
  - library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-08-13 00:57:55-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
- /verify/verify/yosupo/yosupo-vertex_add_path_sum.test.cpp.html
title: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
---

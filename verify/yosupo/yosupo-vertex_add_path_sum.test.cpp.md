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
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\ntemplate <class T> struct\
    \ LazySeg {\r\n\tstd::vector<T> sum, lazy;\r\n\tint sz;\r\n\r\n\tvoid init(int\
    \ sz_) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < sz_) sz *= 2;\r\n\t\tsum.assign(2 *\
    \ sz, 0);\r\n\t\tlazy.assign(2 * sz, 0);\r\n\t}\r\n\r\n\tvoid push(int ind, int\
    \ L, int R) {\r\n\t\tsum[ind] += (R - L + 1) * lazy[ind];\r\n\t\tif (L != R) {\r\
    \n\t\t\tlazy[2 * ind] += lazy[ind];\r\n\t\t\tlazy[2 * ind + 1] += lazy[ind];\r\
    \n\t\t}\r\n\t\tlazy[ind] = 0;\r\n\t}\r\n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind]\
    \ = sum[2 * ind] + sum[2 * ind + 1];\r\n\t}\r\n\r\n\tvoid build() {\r\n\t\tfor\
    \ (int i = sz - 1; i >= 1; i--) {\r\n\t\t\tpull(i);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\r\n\t\t\
    if (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi < L || R < lo) return;\r\
    \n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tlazy[ind] = inc;\r\n\t\t\tpush(ind, L,\
    \ R);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tint M = (L + R) / 2;\r\n\t\tupd(lo, hi,\
    \ inc, 2 * ind, L, M);\r\n\t\tupd(lo, hi, inc, 2 * ind + 1, M + 1, R);\r\n\t\t\
    pull(ind);\r\n\t}\r\n\r\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (lo\
    \ > R || L > hi) return 0;\r\n\t\tif (lo <= L && R <= hi) return sum[ind];\r\n\
    \t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo,\
    \ hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\n\r\nconst bool VALUES_IN_VERTICES\
    \ = true;\r\n\r\ntemplate <class T> struct HeavyLight {\r\n\tstd::vector<int>\
    \ parent, heavy, depth, root, tree_pos;\r\n\tLazySeg<T> tree;\r\n\r\n\ttemplate\
    \ <class G> int dfs(const G& graph, int v) {\r\n\t\tint size = 1, max_subtree\
    \ = 0;\r\n\t\tfor (int u : graph[v]) if (u != parent[v]) {\r\n\t\t\tparent[u]\
    \ = v;\r\n\t\t\tdepth[u] = depth[v] + 1;\r\n\t\t\tint subtree = dfs(graph, u);\r\
    \n\t\t\tif (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;\r\n\t\t\
    \tsize += subtree;\r\n\t\t}\r\n\t\treturn size;\r\n\t}\r\n\r\n\ttemplate <class\
    \ B> void process_path(int u, int v, B op) {\r\n\t\tfor (; root[u] != root[v];\
    \ v = parent[root[v]]) {\r\n\t\t\tif (depth[root[u]] > depth[root[v]]) std::swap(u,\
    \ v);\r\n\t\t\top(tree_pos[root[v]], tree_pos[v]);\r\n\t\t}\r\n\t\tif (depth[u]\
    \ > depth[v]) std::swap(u, v);\r\n\t\top(tree_pos[u] + (VALUES_IN_VERTICES ? 0\
    \ : 1), tree_pos[v]);\r\n\t}\r\n\r\n\ttemplate <class G>\r\n\tvoid init(const\
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
    \ += tree.qsum(l, r); });\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\nint main() {\r\
    \n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(false);\r\n\tHeavyLight<long\
    \ long> H;\r\n\tint n, q; cin >> n >> q;\r\n\tvector<int> a(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) cin >> a[i];\r\n\tvector<vector<int>> graph(n);\r\n\tfor\
    \ (int i = 0; i < n - 1; i++) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\tgraph[u].push_back(v);\r\
    \n\t\tgraph[v].push_back(u);\r\n\t}\r\n\tH.init(graph);\r\n\tfor (int i = 0; i\
    \ < n; i++) H.modify_path(i, i, a[i]);\r\n\twhile (q--) {\r\n\t\tint t; cin >>\
    \ t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x; cin >> p >> x;\r\n\t\t\tH.modify_path(p,\
    \ p, x);\r\n\t\t} else {\r\n\t\t\tint u, v;\r\n\t\t\tcin >> u >> v;\r\n\t\t\t\
    cout << H.query_path(u, v) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/graphs/heavy-light-decomposition2.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(false);\r\
    \n\tHeavyLight<long long> H;\r\n\tint n, q; cin >> n >> q;\r\n\tvector<int> a(n);\r\
    \n\tfor (int i = 0; i < n; i++) cin >> a[i];\r\n\tvector<vector<int>> graph(n);\r\
    \n\tfor (int i = 0; i < n - 1; i++) {\r\n\t\tint u, v; cin >> u >> v;\r\n\t\t\
    graph[u].push_back(v);\r\n\t\tgraph[v].push_back(u);\r\n\t}\r\n\tH.init(graph);\r\
    \n\tfor (int i = 0; i < n; i++) H.modify_path(i, i, a[i]);\r\n\twhile (q--) {\r\
    \n\t\tint t; cin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x; cin >> p >> x;\r\
    \n\t\t\tH.modify_path(p, p, x);\r\n\t\t} else {\r\n\t\t\tint u, v;\r\n\t\t\tcin\
    \ >> u >> v;\r\n\t\t\tcout << H.query_path(u, v) << '\\n';\r\n\t\t}\r\n\t}\r\n\
    \treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/heavy-light-decomposition2.hpp
  - library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
- /verify/verify/yosupo/yosupo-vertex_add_path_sum.test.cpp.html
title: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
---

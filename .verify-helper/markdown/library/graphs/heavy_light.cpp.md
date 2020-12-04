---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\graphs\\\\heavy_light.cpp\"\n#include<bits/stdc++.h>\r\
    \n\r\ntemplate <class T> struct LazySeg {\r\n    std::vector<T> sum, lazy;\r\n\
    \    int sz;\r\n    void init(int sz_) {\r\n        sz = 1;\r\n        while (sz\
    \ < sz_) sz *= 2;\r\n        sum.assign(2 * sz, 0);\r\n        lazy.assign(2 *\
    \ sz, 0);\r\n    }\r\n    void push(int ind, int L, int R) {\r\n        sum[ind]\
    \ += (R - L + 1) * lazy[ind];\r\n        if (L != R) {\r\n            lazy[2 *\
    \ ind] += lazy[ind];\r\n            lazy[2 * ind + 1] += lazy[ind];\r\n      \
    \  }\r\n        lazy[ind] = 0;\r\n    }\r\n    void pull(int ind) {\r\n      \
    \  sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\n    }\r\n    void build() {\r\
    \n        for (int i = sz - 1; i >= 1; i--) {\r\n            pull(i);\r\n    \
    \    }\r\n    }\r\n    void upd(int lo, int hi, T inc, int ind = 1, int L = 0,\
    \ int R = -1) {\r\n        if (R == -1) R += sz;\r\n        push(ind, L, R);\r\
    \n        if (hi < L || R < lo) return ;\r\n        if (lo <= L && R <= hi) {\r\
    \n            lazy[ind] = inc;\r\n            push(ind, L, R);\r\n           \
    \ return;\r\n        }\r\n        int M = (L + R) / 2;\r\n        upd(lo, hi,\
    \ inc, 2 * ind, L, M);\r\n        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);\r\n\
    \        pull(ind);\r\n    }\r\n    T qsum(int lo, int hi, int ind = 1, int L\
    \ = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\n        push(ind, L,\
    \ R);\r\n        if (lo > R || L > hi) return 0;\r\n        if (lo <= L && R <=\
    \ hi) return sum[ind];\r\n        int M = (L + R) / 2;\r\n        return qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n    }\r\n};\r\n\
    const bool VALUES_IN_VERTICES = true;\r\ntemplate <class T> class HeavyLight {\r\
    \n    std::vector<int> parent, heavy, depth, root, tree_pos;\r\n    LazySeg<T>\
    \ tree;\r\n\r\n    template <class G> int dfs(const G& graph, int v) {\r\n   \
    \     int size = 1, max_subtree = 0;\r\n        for (int u : graph[v]) if (u !=\
    \ parent[v]) {\r\n            parent[u] = v;\r\n            depth[u] = depth[v]\
    \ + 1;\r\n            int subtree = dfs(graph, u);\r\n            if (subtree\
    \ > max_subtree) heavy[v] = u, max_subtree = subtree;\r\n            size += subtree;\r\
    \n        }\r\n        return size;\r\n    }\r\n    template <class B> void process_path(int\
    \ u, int v, B op) {\r\n        for (; root[u] != root[v]; v = parent[root[v]])\
    \ {\r\n            if (depth[root[u]] > depth[root[v]]) std::swap(u, v);\r\n \
    \           \r\n            op(tree_pos[root[v]], tree_pos[v]);\r\n        }\r\
    \n        if (depth[u] > depth[v]) std::swap(u, v);\r\n        op(tree_pos[u]\
    \ + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);\r\n    }\r\n\r\npublic:\r\n  \
    \  template <class G>\r\n    void init(const G& graph, int r = 0) {\r\n      \
    \  int n = graph.size();\r\n        heavy.assign(n, -1);\r\n        parent.assign(n,\
    \ 0);\r\n        depth.assign(n, 0);\r\n        root.assign(n, 0);\r\n       \
    \ tree_pos.assign(n, 0);\r\n        tree.init(n);\r\n        parent[r] = -1;\r\
    \n        depth[r] = 0;\r\n        dfs(graph, r);\r\n        for (int i = 0, current_pos\
    \ = 0; i < n; ++i)\r\n            if (parent[i] == -1 || heavy[parent[i]] != i)\r\
    \n            for (int j = i; j != -1; j = heavy[j]) {\r\n                root[j]\
    \ = i;\r\n                tree_pos[j] = current_pos++;\r\n            }\r\n  \
    \  }\r\n    void modify_path(int u, int v, const T& value) {\r\n        process_path(u,\
    \ v, [this, &value](int l, int r) { tree.upd(l, r, value); });\r\n    }\r\n  \
    \  T query_path(int u, int v) {\r\n        T res = 0;\r\n        process_path(u,\
    \ v, [this, &res](int l, int r) { res += tree.qsum(l, r); });\r\n        return\
    \ res;\r\n    }\r\n};\r\n\r\nint main() {\r\n    using namespace std;\r\n    HeavyLight<long\
    \ long> H;\r\n    int n, q; cin >> n >> q;\r\n    vector<int> a(n);\r\n    for\
    \ (int i = 0; i < n; i++) cin >> a[i];\r\n    vector<vector<int>> graph(n);\r\n\
    \    for (int i = 0; i < n - 1; i++) {\r\n        int u, v; cin >> u >> v;\r\n\
    \        graph[u].push_back(v);\r\n        graph[v].push_back(u);\r\n    }\r\n\
    \    H.init(graph);\r\n    for (int i = 0; i < n; i++) H.modify_path(i, i, a[i]);\r\
    \n    while (q--) {\r\n        int t; cin >> t;\r\n        if (t == 0) {\r\n \
    \           int p, x; cin >> p >> x;\r\n            H.modify_path(p, p, x);\r\n\
    \        } else {\r\n            int u, v;\r\n            cin >> u >> v;\r\n \
    \           cout << H.query_path(u, v) << '\\n';\r\n        }\r\n    }\r\n   \
    \ return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\ntemplate <class T> struct LazySeg {\r\n  \
    \  std::vector<T> sum, lazy;\r\n    int sz;\r\n    void init(int sz_) {\r\n  \
    \      sz = 1;\r\n        while (sz < sz_) sz *= 2;\r\n        sum.assign(2 *\
    \ sz, 0);\r\n        lazy.assign(2 * sz, 0);\r\n    }\r\n    void push(int ind,\
    \ int L, int R) {\r\n        sum[ind] += (R - L + 1) * lazy[ind];\r\n        if\
    \ (L != R) {\r\n            lazy[2 * ind] += lazy[ind];\r\n            lazy[2\
    \ * ind + 1] += lazy[ind];\r\n        }\r\n        lazy[ind] = 0;\r\n    }\r\n\
    \    void pull(int ind) {\r\n        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\
    \n    }\r\n    void build() {\r\n        for (int i = sz - 1; i >= 1; i--) {\r\
    \n            pull(i);\r\n        }\r\n    }\r\n    void upd(int lo, int hi, T\
    \ inc, int ind = 1, int L = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\
    \n        push(ind, L, R);\r\n        if (hi < L || R < lo) return ;\r\n     \
    \   if (lo <= L && R <= hi) {\r\n            lazy[ind] = inc;\r\n            push(ind,\
    \ L, R);\r\n            return;\r\n        }\r\n        int M = (L + R) / 2;\r\
    \n        upd(lo, hi, inc, 2 * ind, L, M);\r\n        upd(lo, hi, inc, 2 * ind\
    \ + 1, M + 1, R);\r\n        pull(ind);\r\n    }\r\n    T qsum(int lo, int hi,\
    \ int ind = 1, int L = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\n \
    \       push(ind, L, R);\r\n        if (lo > R || L > hi) return 0;\r\n      \
    \  if (lo <= L && R <= hi) return sum[ind];\r\n        int M = (L + R) / 2;\r\n\
    \        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1,\
    \ R);\r\n    }\r\n};\r\nconst bool VALUES_IN_VERTICES = true;\r\ntemplate <class\
    \ T> class HeavyLight {\r\n    std::vector<int> parent, heavy, depth, root, tree_pos;\r\
    \n    LazySeg<T> tree;\r\n\r\n    template <class G> int dfs(const G& graph, int\
    \ v) {\r\n        int size = 1, max_subtree = 0;\r\n        for (int u : graph[v])\
    \ if (u != parent[v]) {\r\n            parent[u] = v;\r\n            depth[u]\
    \ = depth[v] + 1;\r\n            int subtree = dfs(graph, u);\r\n            if\
    \ (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;\r\n           \
    \ size += subtree;\r\n        }\r\n        return size;\r\n    }\r\n    template\
    \ <class B> void process_path(int u, int v, B op) {\r\n        for (; root[u]\
    \ != root[v]; v = parent[root[v]]) {\r\n            if (depth[root[u]] > depth[root[v]])\
    \ std::swap(u, v);\r\n            \r\n            op(tree_pos[root[v]], tree_pos[v]);\r\
    \n        }\r\n        if (depth[u] > depth[v]) std::swap(u, v);\r\n        op(tree_pos[u]\
    \ + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);\r\n    }\r\n\r\npublic:\r\n  \
    \  template <class G>\r\n    void init(const G& graph, int r = 0) {\r\n      \
    \  int n = graph.size();\r\n        heavy.assign(n, -1);\r\n        parent.assign(n,\
    \ 0);\r\n        depth.assign(n, 0);\r\n        root.assign(n, 0);\r\n       \
    \ tree_pos.assign(n, 0);\r\n        tree.init(n);\r\n        parent[r] = -1;\r\
    \n        depth[r] = 0;\r\n        dfs(graph, r);\r\n        for (int i = 0, current_pos\
    \ = 0; i < n; ++i)\r\n            if (parent[i] == -1 || heavy[parent[i]] != i)\r\
    \n            for (int j = i; j != -1; j = heavy[j]) {\r\n                root[j]\
    \ = i;\r\n                tree_pos[j] = current_pos++;\r\n            }\r\n  \
    \  }\r\n    void modify_path(int u, int v, const T& value) {\r\n        process_path(u,\
    \ v, [this, &value](int l, int r) { tree.upd(l, r, value); });\r\n    }\r\n  \
    \  T query_path(int u, int v) {\r\n        T res = 0;\r\n        process_path(u,\
    \ v, [this, &res](int l, int r) { res += tree.qsum(l, r); });\r\n        return\
    \ res;\r\n    }\r\n};\r\n\r\nint main() {\r\n    using namespace std;\r\n    HeavyLight<long\
    \ long> H;\r\n    int n, q; cin >> n >> q;\r\n    vector<int> a(n);\r\n    for\
    \ (int i = 0; i < n; i++) cin >> a[i];\r\n    vector<vector<int>> graph(n);\r\n\
    \    for (int i = 0; i < n - 1; i++) {\r\n        int u, v; cin >> u >> v;\r\n\
    \        graph[u].push_back(v);\r\n        graph[v].push_back(u);\r\n    }\r\n\
    \    H.init(graph);\r\n    for (int i = 0; i < n; i++) H.modify_path(i, i, a[i]);\r\
    \n    while (q--) {\r\n        int t; cin >> t;\r\n        if (t == 0) {\r\n \
    \           int p, x; cin >> p >> x;\r\n            H.modify_path(p, p, x);\r\n\
    \        } else {\r\n            int u, v;\r\n            cin >> u >> v;\r\n \
    \           cout << H.query_path(u, v) << '\\n';\r\n        }\r\n    }\r\n   \
    \ return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\graphs\heavy_light.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:56:19-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\graphs\heavy_light.cpp
layout: document
redirect_from:
- /library\library\graphs\heavy_light.cpp
- /library\library\graphs\heavy_light.cpp.html
title: library\graphs\heavy_light.cpp
---

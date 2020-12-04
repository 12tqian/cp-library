---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/heavy_light.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate <class T> struct LazySeg {\n    std::vector<T> sum, lazy;\n    int\
    \ sz;\n    void init(int sz_) {\n        sz = 1;\n        while (sz < sz_) sz\
    \ *= 2;\n        sum.assign(2 * sz, 0);\n        lazy.assign(2 * sz, 0);\n   \
    \ }\n    void push(int ind, int L, int R) {\n        sum[ind] += (R - L + 1) *\
    \ lazy[ind];\n        if (L != R) {\n            lazy[2 * ind] += lazy[ind];\n\
    \            lazy[2 * ind + 1] += lazy[ind];\n        }\n        lazy[ind] = 0;\n\
    \    }\n    void pull(int ind) {\n        sum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n    }\n    void build() {\n        for (int i = sz - 1; i >= 1; i--)\
    \ {\n            pull(i);\n        }\n    }\n    void upd(int lo, int hi, T inc,\
    \ int ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n     \
    \   push(ind, L, R);\n        if (hi < L || R < lo) return ;\n        if (lo <=\
    \ L && R <= hi) {\n            lazy[ind] = inc;\n            push(ind, L, R);\n\
    \            return;\n        }\n        int M = (L + R) / 2;\n        upd(lo,\
    \ hi, inc, 2 * ind, L, M);\n        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);\n\
    \        pull(ind);\n    }\n    T qsum(int lo, int hi, int ind = 1, int L = 0,\
    \ int R = -1) {\n        if (R == -1) R += sz;\n        push(ind, L, R);\n   \
    \     if (lo > R || L > hi) return 0;\n        if (lo <= L && R <= hi) return\
    \ sum[ind];\n        int M = (L + R) / 2;\n        return qsum(lo, hi, 2 * ind,\
    \ L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n    }\n};\nconst bool VALUES_IN_VERTICES\
    \ = true;\ntemplate <class T> class HeavyLight {\n    std::vector<int> parent,\
    \ heavy, depth, root, tree_pos;\n    LazySeg<T> tree;\n\n    template <class G>\
    \ int dfs(const G& graph, int v) {\n        int size = 1, max_subtree = 0;\n \
    \       for (int u : graph[v]) if (u != parent[v]) {\n            parent[u] =\
    \ v;\n            depth[u] = depth[v] + 1;\n            int subtree = dfs(graph,\
    \ u);\n            if (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;\n\
    \            size += subtree;\n        }\n        return size;\n    }\n    template\
    \ <class B> void process_path(int u, int v, B op) {\n        for (; root[u] !=\
    \ root[v]; v = parent[root[v]]) {\n            if (depth[root[u]] > depth[root[v]])\
    \ std::swap(u, v);\n            \n            op(tree_pos[root[v]], tree_pos[v]);\n\
    \        }\n        if (depth[u] > depth[v]) std::swap(u, v);\n        op(tree_pos[u]\
    \ + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);\n    }\n\npublic:\n    template\
    \ <class G>\n    void init(const G& graph, int r = 0) {\n        int n = graph.size();\n\
    \        heavy.assign(n, -1);\n        parent.assign(n, 0);\n        depth.assign(n,\
    \ 0);\n        root.assign(n, 0);\n        tree_pos.assign(n, 0);\n        tree.init(n);\n\
    \        parent[r] = -1;\n        depth[r] = 0;\n        dfs(graph, r);\n    \
    \    for (int i = 0, current_pos = 0; i < n; ++i)\n            if (parent[i] ==\
    \ -1 || heavy[parent[i]] != i)\n            for (int j = i; j != -1; j = heavy[j])\
    \ {\n                root[j] = i;\n                tree_pos[j] = current_pos++;\n\
    \            }\n    }\n    void modify_path(int u, int v, const T& value) {\n\
    \        process_path(u, v, [this, &value](int l, int r) { tree.upd(l, r, value);\
    \ });\n    }\n    T query_path(int u, int v) {\n        T res = 0;\n        process_path(u,\
    \ v, [this, &res](int l, int r) { res += tree.qsum(l, r); });\n        return\
    \ res;\n    }\n};\n\nint main() {\n    using namespace std;\n    HeavyLight<long\
    \ long> H;\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    for (int\
    \ i = 0; i < n; i++) cin >> a[i];\n    vector<vector<int>> graph(n);\n    for\
    \ (int i = 0; i < n - 1; i++) {\n        int u, v; cin >> u >> v;\n        graph[u].push_back(v);\n\
    \        graph[v].push_back(u);\n    }\n    H.init(graph);\n    for (int i = 0;\
    \ i < n; i++) H.modify_path(i, i, a[i]);\n    while (q--) {\n        int t; cin\
    \ >> t;\n        if (t == 0) {\n            int p, x; cin >> p >> x;\n       \
    \     H.modify_path(p, p, x);\n        } else {\n            int u, v;\n     \
    \       cin >> u >> v;\n            cout << H.query_path(u, v) << '\\n';\n   \
    \     }\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class T> struct LazySeg {\n    std::vector<T>\
    \ sum, lazy;\n    int sz;\n    void init(int sz_) {\n        sz = 1;\n       \
    \ while (sz < sz_) sz *= 2;\n        sum.assign(2 * sz, 0);\n        lazy.assign(2\
    \ * sz, 0);\n    }\n    void push(int ind, int L, int R) {\n        sum[ind] +=\
    \ (R - L + 1) * lazy[ind];\n        if (L != R) {\n            lazy[2 * ind] +=\
    \ lazy[ind];\n            lazy[2 * ind + 1] += lazy[ind];\n        }\n       \
    \ lazy[ind] = 0;\n    }\n    void pull(int ind) {\n        sum[ind] = sum[2 *\
    \ ind] + sum[2 * ind + 1];\n    }\n    void build() {\n        for (int i = sz\
    \ - 1; i >= 1; i--) {\n            pull(i);\n        }\n    }\n    void upd(int\
    \ lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n        if (R == -1)\
    \ R += sz;\n        push(ind, L, R);\n        if (hi < L || R < lo) return ;\n\
    \        if (lo <= L && R <= hi) {\n            lazy[ind] = inc;\n           \
    \ push(ind, L, R);\n            return;\n        }\n        int M = (L + R) /\
    \ 2;\n        upd(lo, hi, inc, 2 * ind, L, M);\n        upd(lo, hi, inc, 2 * ind\
    \ + 1, M + 1, R);\n        pull(ind);\n    }\n    T qsum(int lo, int hi, int ind\
    \ = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (lo > R || L > hi) return 0;\n        if (lo <= L && R <=\
    \ hi) return sum[ind];\n        int M = (L + R) / 2;\n        return qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n    }\n};\nconst\
    \ bool VALUES_IN_VERTICES = true;\ntemplate <class T> class HeavyLight {\n   \
    \ std::vector<int> parent, heavy, depth, root, tree_pos;\n    LazySeg<T> tree;\n\
    \n    template <class G> int dfs(const G& graph, int v) {\n        int size =\
    \ 1, max_subtree = 0;\n        for (int u : graph[v]) if (u != parent[v]) {\n\
    \            parent[u] = v;\n            depth[u] = depth[v] + 1;\n          \
    \  int subtree = dfs(graph, u);\n            if (subtree > max_subtree) heavy[v]\
    \ = u, max_subtree = subtree;\n            size += subtree;\n        }\n     \
    \   return size;\n    }\n    template <class B> void process_path(int u, int v,\
    \ B op) {\n        for (; root[u] != root[v]; v = parent[root[v]]) {\n       \
    \     if (depth[root[u]] > depth[root[v]]) std::swap(u, v);\n            \n  \
    \          op(tree_pos[root[v]], tree_pos[v]);\n        }\n        if (depth[u]\
    \ > depth[v]) std::swap(u, v);\n        op(tree_pos[u] + (VALUES_IN_VERTICES ?\
    \ 0 : 1), tree_pos[v]);\n    }\n\npublic:\n    template <class G>\n    void init(const\
    \ G& graph, int r = 0) {\n        int n = graph.size();\n        heavy.assign(n,\
    \ -1);\n        parent.assign(n, 0);\n        depth.assign(n, 0);\n        root.assign(n,\
    \ 0);\n        tree_pos.assign(n, 0);\n        tree.init(n);\n        parent[r]\
    \ = -1;\n        depth[r] = 0;\n        dfs(graph, r);\n        for (int i = 0,\
    \ current_pos = 0; i < n; ++i)\n            if (parent[i] == -1 || heavy[parent[i]]\
    \ != i)\n            for (int j = i; j != -1; j = heavy[j]) {\n              \
    \  root[j] = i;\n                tree_pos[j] = current_pos++;\n            }\n\
    \    }\n    void modify_path(int u, int v, const T& value) {\n        process_path(u,\
    \ v, [this, &value](int l, int r) { tree.upd(l, r, value); });\n    }\n    T query_path(int\
    \ u, int v) {\n        T res = 0;\n        process_path(u, v, [this, &res](int\
    \ l, int r) { res += tree.qsum(l, r); });\n        return res;\n    }\n};\n\n\
    int main() {\n    using namespace std;\n    HeavyLight<long long> H;\n    int\
    \ n, q; cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++)\
    \ cin >> a[i];\n    vector<vector<int>> graph(n);\n    for (int i = 0; i < n -\
    \ 1; i++) {\n        int u, v; cin >> u >> v;\n        graph[u].push_back(v);\n\
    \        graph[v].push_back(u);\n    }\n    H.init(graph);\n    for (int i = 0;\
    \ i < n; i++) H.modify_path(i, i, a[i]);\n    while (q--) {\n        int t; cin\
    \ >> t;\n        if (t == 0) {\n            int p, x; cin >> p >> x;\n       \
    \     H.modify_path(p, p, x);\n        } else {\n            int u, v;\n     \
    \       cin >> u >> v;\n            cout << H.query_path(u, v) << '\\n';\n   \
    \     }\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/heavy_light.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/heavy_light.cpp
layout: document
redirect_from:
- /library/library/graphs/heavy_light.cpp
- /library/library/graphs/heavy_light.cpp.html
title: library/graphs/heavy_light.cpp
---

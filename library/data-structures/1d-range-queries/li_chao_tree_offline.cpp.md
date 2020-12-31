---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/li_chao_tree_offline.cpp\"\
    \n#include <bits/stdc++.h>\n// Set to minimums, negate for maximums\ntemplate\
    \ <class T> struct LiChaoTree {\n    struct Line {\n        T slope, intercept;\n\
    \        Line(T slope, T intercept) : slope(slope), intercept(intercept) {}\n\
    \        inline T get(T x) const { return slope * x + intercept; }\n        inline\
    \ bool over(const Line& other, const T& x) {\n            return get(x) < other.get(x);\n\
    \        }\n    };\n    std::vector<T> xset;\n    std::vector<Line> seg;\n   \
    \ int sz;\n    LiChaoTree(const std::vector<T>& x) : xset(x) {\n        sort(xset.begin(),\
    \ xset.end());\n        xset.erase(unique(xset.begin(), xset.end()), xset.end());\n\
    \        sz = 1;\n        while (sz < (int) xset.size()) sz <<= 1;\n        while\
    \ ((int) xset.size() < sz) xset.push_back(xset.back());\n        seg.assign(2\
    \ * sz, Line(0, std::numeric_limits<T>::max()));\n    }\n    int get_more_idx(T\
    \ k) {\n        return lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n\
    \    }\n    int get_less_idx(T k) {\n        int ret = upper_bound(xset.begin(),\
    \ xset.end(), k) - xset.begin();\n        return std::max(0, ret - 1);\n    }\n\
    \    void inner_update(T a, T b, int ind, int L, int R) {\n        Line line(a,\
    \ b);\n        while (true) {\n            int M = (L + R) >> 1;\n           \
    \ bool l_over = line.over(seg[ind], xset[L]);\n            bool r_over = line.over(seg[ind],\
    \ xset[R - 1]);\n            if (l_over == r_over) {\n                if (l_over)\
    \ std::swap(seg[ind], line);\n                return;\n            }\n       \
    \     bool m_over = line.over(seg[ind], xset[M]);\n            if (m_over) std::swap(seg[ind],\
    \ line);\n            if (l_over != m_over) \n                ind = (ind << 1),\
    \ R = M;\n            else \n                ind = (ind << 1) | 1, L = M;\n\n\
    \        }\n    }\n    void inner_update(T a, T b, int ind) {\n        int L,\
    \ R;\n        int up = 31 - __builtin_clz(ind);\n        L = (sz >> up) * (ind\
    \ - (1 << up));\n        R = L + (sz >> up);\n        inner_update(a, b, ind,\
    \ L, R);\n    }\n    void update(T a, T b) { inner_update(a, b, 1, 0, sz); }\n\
    \    void update_segment(T a, T b, T lo, T hi) {\n        int L = get_more_idx(lo)\
    \ + sz;\n        int R = get_less_idx(hi) + sz + 1;\n        for (; L < R; L >>=\
    \ 1, R >>= 1) {\n            if (L & 1) inner_update(a, b, L++);\n           \
    \ if (R & 1) inner_update(a, b, --R);\n        }\n    }\n    T inner_query(T x,\
    \ int ind) {\n        T ret = seg[ind].get(x);\n        while (ind > 1) {\n  \
    \          ind = ind >> 1;\n            ret = std::min(ret, seg[ind].get(x));\n\
    \        }\n        return ret;\n    }\n    T query_idx(int k) {\n        const\
    \ T x = xset[k];\n        k += sz;\n        return inner_query(x, k);\n    }\n\
    \    T query(T x) { return query_idx(get_more_idx(x)); }\n};\n\nint main() {\n\
    \    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\
    \ cin >> n >> q;\n    vector<long long> a(n), b(n), l(n), r(n);\n    for (int\
    \ i = 0; i < n; i++) \n        cin >> l[i] >> r[i] >> a[i] >> b[i];\n    vector<long\
    \ long> c(q), d(q), e(q), f(q), g(q);\n    vector<long long> xs;\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> c[i];\n        if (c[i]) {\n          \
    \  cin >> d[i];\n            xs.push_back(d[i]);\n        } else {\n         \
    \   cin >> d[i] >> e[i] >> f[i] >> g[i];\n        }\n    }\n    xs.push_back(numeric_limits<long\
    \ long>::min());\n    xs.push_back(numeric_limits<long long>::max());\n    LiChaoTree<long\
    \ long> L(xs);\n    for (int i = 0; i < n; i++) {\n        L.update_segment(a[i],\
    \ b[i], l[i], r[i] - 1);\n    }\n    for (int i = 0; i < q; i++) {\n        if\
    \ (c[i]) {\n            long long ans = L.query(d[i]);\n            if (ans ==\
    \ numeric_limits<long long>::max()) \n                cout << \"INFINITY\\n\"\
    ;\n            else \n                cout << ans << '\\n';\n        } else {\n\
    \            L.update_segment(f[i], g[i], d[i], e[i] - 1);\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n// Set to minimums, negate for maximums\ntemplate\
    \ <class T> struct LiChaoTree {\n    struct Line {\n        T slope, intercept;\n\
    \        Line(T slope, T intercept) : slope(slope), intercept(intercept) {}\n\
    \        inline T get(T x) const { return slope * x + intercept; }\n        inline\
    \ bool over(const Line& other, const T& x) {\n            return get(x) < other.get(x);\n\
    \        }\n    };\n    std::vector<T> xset;\n    std::vector<Line> seg;\n   \
    \ int sz;\n    LiChaoTree(const std::vector<T>& x) : xset(x) {\n        sort(xset.begin(),\
    \ xset.end());\n        xset.erase(unique(xset.begin(), xset.end()), xset.end());\n\
    \        sz = 1;\n        while (sz < (int) xset.size()) sz <<= 1;\n        while\
    \ ((int) xset.size() < sz) xset.push_back(xset.back());\n        seg.assign(2\
    \ * sz, Line(0, std::numeric_limits<T>::max()));\n    }\n    int get_more_idx(T\
    \ k) {\n        return lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n\
    \    }\n    int get_less_idx(T k) {\n        int ret = upper_bound(xset.begin(),\
    \ xset.end(), k) - xset.begin();\n        return std::max(0, ret - 1);\n    }\n\
    \    void inner_update(T a, T b, int ind, int L, int R) {\n        Line line(a,\
    \ b);\n        while (true) {\n            int M = (L + R) >> 1;\n           \
    \ bool l_over = line.over(seg[ind], xset[L]);\n            bool r_over = line.over(seg[ind],\
    \ xset[R - 1]);\n            if (l_over == r_over) {\n                if (l_over)\
    \ std::swap(seg[ind], line);\n                return;\n            }\n       \
    \     bool m_over = line.over(seg[ind], xset[M]);\n            if (m_over) std::swap(seg[ind],\
    \ line);\n            if (l_over != m_over) \n                ind = (ind << 1),\
    \ R = M;\n            else \n                ind = (ind << 1) | 1, L = M;\n\n\
    \        }\n    }\n    void inner_update(T a, T b, int ind) {\n        int L,\
    \ R;\n        int up = 31 - __builtin_clz(ind);\n        L = (sz >> up) * (ind\
    \ - (1 << up));\n        R = L + (sz >> up);\n        inner_update(a, b, ind,\
    \ L, R);\n    }\n    void update(T a, T b) { inner_update(a, b, 1, 0, sz); }\n\
    \    void update_segment(T a, T b, T lo, T hi) {\n        int L = get_more_idx(lo)\
    \ + sz;\n        int R = get_less_idx(hi) + sz + 1;\n        for (; L < R; L >>=\
    \ 1, R >>= 1) {\n            if (L & 1) inner_update(a, b, L++);\n           \
    \ if (R & 1) inner_update(a, b, --R);\n        }\n    }\n    T inner_query(T x,\
    \ int ind) {\n        T ret = seg[ind].get(x);\n        while (ind > 1) {\n  \
    \          ind = ind >> 1;\n            ret = std::min(ret, seg[ind].get(x));\n\
    \        }\n        return ret;\n    }\n    T query_idx(int k) {\n        const\
    \ T x = xset[k];\n        k += sz;\n        return inner_query(x, k);\n    }\n\
    \    T query(T x) { return query_idx(get_more_idx(x)); }\n};\n\nint main() {\n\
    \    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\
    \ cin >> n >> q;\n    vector<long long> a(n), b(n), l(n), r(n);\n    for (int\
    \ i = 0; i < n; i++) \n        cin >> l[i] >> r[i] >> a[i] >> b[i];\n    vector<long\
    \ long> c(q), d(q), e(q), f(q), g(q);\n    vector<long long> xs;\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> c[i];\n        if (c[i]) {\n          \
    \  cin >> d[i];\n            xs.push_back(d[i]);\n        } else {\n         \
    \   cin >> d[i] >> e[i] >> f[i] >> g[i];\n        }\n    }\n    xs.push_back(numeric_limits<long\
    \ long>::min());\n    xs.push_back(numeric_limits<long long>::max());\n    LiChaoTree<long\
    \ long> L(xs);\n    for (int i = 0; i < n; i++) {\n        L.update_segment(a[i],\
    \ b[i], l[i], r[i] - 1);\n    }\n    for (int i = 0; i < q; i++) {\n        if\
    \ (c[i]) {\n            long long ans = L.query(d[i]);\n            if (ans ==\
    \ numeric_limits<long long>::max()) \n                cout << \"INFINITY\\n\"\
    ;\n            else \n                cout << ans << '\\n';\n        } else {\n\
    \            L.update_segment(f[i], g[i], d[i], e[i] - 1);\n        }\n    }\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/li_chao_tree_offline.cpp
  requiredBy: []
  timestamp: '2020-12-31 00:22:03-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/li_chao_tree_offline.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/li_chao_tree_offline.cpp
- /library/library/data-structures/1d-range-queries/li_chao_tree_offline.cpp.html
title: library/data-structures/1d-range-queries/li_chao_tree_offline.cpp
---

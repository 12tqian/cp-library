---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/associative_range_query.cpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <class T> struct RangeQuery {\n    int\
    \ sz; \n    std::vector<std::vector<T>> st;\n    T id = 0;\n    std::vector<T>\
    \ a;\n\n    T comb(T a, T b) { return a + b; }  \n\n    void fill(int l, int r,\
    \ int ind) {\n        if (ind < 0) return;\n        int m = (l + r) >> 1;\n  \
    \      T prod = id;\n        for (int i = m - 1; i >= l; i--) \n            st[i][ind]\
    \ = prod = comb(a[i], prod);\n        prod = id;\n        for (int i = m; i <\
    \ r; i++) \n            st[i][ind] = prod = comb(prod, a[i]);\n        fill(l,\
    \ m, ind - 1);\n        fill(m, r, ind - 1);\n    }\n\n    void init(std::vector<T>\
    \ a_) {\n        a = a_;\n        sz = 1;\n        while ((1 << sz) < (int)a.size())\
    \ sz++;\n        st = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\n\
    \        a.resize(1 << sz);\n        fill(0, (1 << sz), sz - 1);\n    }\n\n  \
    \  T query(int l, int r) {\n        if (l == r) return a[l];\n        int t =\
    \ 31 - __builtin_clz(r ^ l);\n        return comb(st[l][t], st[r][t]);\n    }\n\
    };\n\nint main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> a(n);\n    for (int i = 0;\
    \ i < n; i++) \n        cin >> a[i];\n    RangeQuery<long long> R; \n    R.init(a);\n\
    \    while (q--) {\n        int l, r; cin >> l >> r;\n        r--;\n        cout\
    \ << R.query(l, r) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct RangeQuery {\n    int\
    \ sz; \n    std::vector<std::vector<T>> st;\n    T id = 0;\n    std::vector<T>\
    \ a;\n\n    T comb(T a, T b) { return a + b; }  \n\n    void fill(int l, int r,\
    \ int ind) {\n        if (ind < 0) return;\n        int m = (l + r) >> 1;\n  \
    \      T prod = id;\n        for (int i = m - 1; i >= l; i--) \n            st[i][ind]\
    \ = prod = comb(a[i], prod);\n        prod = id;\n        for (int i = m; i <\
    \ r; i++) \n            st[i][ind] = prod = comb(prod, a[i]);\n        fill(l,\
    \ m, ind - 1);\n        fill(m, r, ind - 1);\n    }\n\n    void init(std::vector<T>\
    \ a_) {\n        a = a_;\n        sz = 1;\n        while ((1 << sz) < (int)a.size())\
    \ sz++;\n        st = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\n\
    \        a.resize(1 << sz);\n        fill(0, (1 << sz), sz - 1);\n    }\n\n  \
    \  T query(int l, int r) {\n        if (l == r) return a[l];\n        int t =\
    \ 31 - __builtin_clz(r ^ l);\n        return comb(st[l][t], st[r][t]);\n    }\n\
    };\n\nint main() {\n    using namespace std;\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> a(n);\n    for (int i = 0;\
    \ i < n; i++) \n        cin >> a[i];\n    RangeQuery<long long> R; \n    R.init(a);\n\
    \    while (q--) {\n        int l, r; cin >> l >> r;\n        r--;\n        cout\
    \ << R.query(l, r) << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/associative_range_query.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:38:16-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/associative_range_query.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/associative_range_query.cpp
- /library/library/data-structures/1d-range-queries/associative_range_query.cpp.html
title: library/data-structures/1d-range-queries/associative_range_query.cpp
---

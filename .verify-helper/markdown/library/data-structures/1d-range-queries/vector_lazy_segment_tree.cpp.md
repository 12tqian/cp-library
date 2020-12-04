---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\data-structures\\\\1d-range-queries\\\\vector_lazy_segment_tree.cpp\"\
    \n#include<bits/stdc++.h>\r\ntemplate <class T> struct LazySeg {\r\n    std::vector<T>\
    \ sum, lazy;\r\n    int sz;\r\n    void init(int sz_) {\r\n        sz = 1;\r\n\
    \        while (sz < sz_) sz *= 2;\r\n        sum.assign(2 * sz, 0);\r\n     \
    \   lazy.assign(2 * sz, 0);\r\n    }\r\n    void push(int ind, int L, int R) {\r\
    \n        sum[ind] += (R - L + 1) * lazy[ind];\r\n        if (L != R) {\r\n  \
    \          lazy[2 * ind] += lazy[ind];\r\n            lazy[2 * ind + 1] += lazy[ind];\r\
    \n        }\r\n        lazy[ind] = 0;\r\n    }\r\n    void pull(int ind) {\r\n\
    \        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\n    }\r\n    void build()\
    \ {\r\n        for (int i = sz - 1; i >= 1; i--) {\r\n            pull(i);\r\n\
    \        }\r\n    }\r\n    void upd(int lo, int hi, T inc, int ind = 1, int L\
    \ = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\n        push(ind, L,\
    \ R);\r\n        if (hi < L || R < lo) return ;\r\n        if (lo <= L && R <=\
    \ hi) {\r\n            lazy[ind] = inc;\r\n            push(ind, L, R);\r\n  \
    \          return;\r\n        }\r\n        int M = (L + R) / 2;\r\n        upd(lo,\
    \ hi, inc, 2 * ind, L, M);\r\n        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);\r\
    \n        pull(ind);\r\n    }\r\n    T qsum(int lo, int hi, int ind = 1, int L\
    \ = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\n        push(ind, L,\
    \ R);\r\n        if (lo > R || L > hi) return 0;\r\n        if (lo <= L && R <=\
    \ hi) return sum[ind];\r\n        int M = (L + R) / 2;\r\n        return qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n    }\r\n};\r\n\
    int main() {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\ntemplate <class T> struct LazySeg {\r\n    std::vector<T>\
    \ sum, lazy;\r\n    int sz;\r\n    void init(int sz_) {\r\n        sz = 1;\r\n\
    \        while (sz < sz_) sz *= 2;\r\n        sum.assign(2 * sz, 0);\r\n     \
    \   lazy.assign(2 * sz, 0);\r\n    }\r\n    void push(int ind, int L, int R) {\r\
    \n        sum[ind] += (R - L + 1) * lazy[ind];\r\n        if (L != R) {\r\n  \
    \          lazy[2 * ind] += lazy[ind];\r\n            lazy[2 * ind + 1] += lazy[ind];\r\
    \n        }\r\n        lazy[ind] = 0;\r\n    }\r\n    void pull(int ind) {\r\n\
    \        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\n    }\r\n    void build()\
    \ {\r\n        for (int i = sz - 1; i >= 1; i--) {\r\n            pull(i);\r\n\
    \        }\r\n    }\r\n    void upd(int lo, int hi, T inc, int ind = 1, int L\
    \ = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\n        push(ind, L,\
    \ R);\r\n        if (hi < L || R < lo) return ;\r\n        if (lo <= L && R <=\
    \ hi) {\r\n            lazy[ind] = inc;\r\n            push(ind, L, R);\r\n  \
    \          return;\r\n        }\r\n        int M = (L + R) / 2;\r\n        upd(lo,\
    \ hi, inc, 2 * ind, L, M);\r\n        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);\r\
    \n        pull(ind);\r\n    }\r\n    T qsum(int lo, int hi, int ind = 1, int L\
    \ = 0, int R = -1) {\r\n        if (R == -1) R += sz;\r\n        push(ind, L,\
    \ R);\r\n        if (lo > R || L > hi) return 0;\r\n        if (lo <= L && R <=\
    \ hi) return sum[ind];\r\n        int M = (L + R) / 2;\r\n        return qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n    }\r\n};\r\n\
    int main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\data-structures\1d-range-queries\vector_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-12-03 19:13:49-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\data-structures\1d-range-queries\vector_lazy_segment_tree.cpp
layout: document
redirect_from:
- /library\library\data-structures\1d-range-queries\vector_lazy_segment_tree.cpp
- /library\library\data-structures\1d-range-queries\vector_lazy_segment_tree.cpp.html
title: library\data-structures\1d-range-queries\vector_lazy_segment_tree.cpp
---

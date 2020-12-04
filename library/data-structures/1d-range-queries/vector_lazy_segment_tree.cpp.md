---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/vector_lazy_segment_tree.cpp\"\
    \n#include<bits/stdc++.h>\ntemplate <class T> struct LazySeg {\n    std::vector<T>\
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
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n    }\n};\nint main()\
    \ {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\ntemplate <class T> struct LazySeg {\n    std::vector<T>\
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
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n    }\n};\nint main()\
    \ {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/vector_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/vector_lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/vector_lazy_segment_tree.cpp
- /library/library/data-structures/1d-range-queries/vector_lazy_segment_tree.cpp.html
title: library/data-structures/1d-range-queries/vector_lazy_segment_tree.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/mult_add_seg.cpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\ntemplate <class T> struct\
    \ AffineSeg {\n    int sz;\n    std::vector<T> sum, mult, add;\n\n    void push(int\
    \ ind, int L, int R) { // modify values for current node\n        sum[ind] *=\
    \ mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n        if (L != R) {\n    \
    \        mult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n       \
    \     add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n            add[2\
    \ * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n        }\n        add[ind]\
    \ = 0; mult[ind] = 1;\n    }\n\n    void init(int n) {\n        sz = 1;\n    \
    \    while (sz < n) sz *= 2;\n        mult.assign(2 * sz, 1);\n        sum.assign(2\
    \ * sz, 0);\n        add.assign(2 * sz, 0);\n    }\n\n    void pull(int ind) {\n\
    \        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n    }\n\n    // t == 0 is\
    \ add, t == 1 is for multiplying\n    void upd(int t, int lo, int hi, T inc, int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (hi < L || R < lo) return;\n        if (lo <= L && R <= hi)\
    \ {\n            if(t == 0) add[ind] = inc;  \n            else mult[ind] = inc;\n\
    \            push(ind, L, R); return;\n        }\n        int M = (L + R) / 2;\n\
    \        upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1,\
    \ M + 1, R);\n        pull(ind);\n    }\n    \n    T qsum(int lo, int hi, int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (lo > R || L > hi) return 0;\n        if (lo <= L && R <=\
    \ hi) return sum[ind];\n        int M = (L + R) / 2;\n        return qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n    }\n};\n\nint\
    \ main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nusing namespace std;\n\ntemplate <class T> struct\
    \ AffineSeg {\n    int sz;\n    std::vector<T> sum, mult, add;\n\n    void push(int\
    \ ind, int L, int R) { // modify values for current node\n        sum[ind] *=\
    \ mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n        if (L != R) {\n    \
    \        mult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n       \
    \     add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n            add[2\
    \ * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n        }\n        add[ind]\
    \ = 0; mult[ind] = 1;\n    }\n\n    void init(int n) {\n        sz = 1;\n    \
    \    while (sz < n) sz *= 2;\n        mult.assign(2 * sz, 1);\n        sum.assign(2\
    \ * sz, 0);\n        add.assign(2 * sz, 0);\n    }\n\n    void pull(int ind) {\n\
    \        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n    }\n\n    // t == 0 is\
    \ add, t == 1 is for multiplying\n    void upd(int t, int lo, int hi, T inc, int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (hi < L || R < lo) return;\n        if (lo <= L && R <= hi)\
    \ {\n            if(t == 0) add[ind] = inc;  \n            else mult[ind] = inc;\n\
    \            push(ind, L, R); return;\n        }\n        int M = (L + R) / 2;\n\
    \        upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1,\
    \ M + 1, R);\n        pull(ind);\n    }\n    \n    T qsum(int lo, int hi, int\
    \ ind = 1, int L = 0, int R = -1) {\n        if (R == -1) R += sz;\n        push(ind,\
    \ L, R);\n        if (lo > R || L > hi) return 0;\n        if (lo <= L && R <=\
    \ hi) return sum[ind];\n        int M = (L + R) / 2;\n        return qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n    }\n};\n\nint\
    \ main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/mult_add_seg.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/mult_add_seg.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/mult_add_seg.cpp
- /library/library/data-structures/1d-range-queries/mult_add_seg.cpp.html
title: library/data-structures/1d-range-queries/mult_add_seg.cpp
---

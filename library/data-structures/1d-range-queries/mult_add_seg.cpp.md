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
    \n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, int SZ>\
    \ struct AffineSeg {\n    T sum[2 * SZ], mult[2 * SZ], add[2 * SZ];\n    void\
    \ push(int ind, int L, int R) { // modify values for current node\n        sum[ind]\
    \ *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n        if (L != R) {\n \
    \           mult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n    \
    \        add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n            add[2\
    \ * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n        }\n        add[ind]\
    \ = 0; mult[ind] = 1;\n    }\n    void init() {\n        for(int i = 0; i < 2\
    \ * SZ; i++){\n            mult[i] = 1;\n            sum[i] = 0;\n           \
    \ add[i] = 0;\n        }\n        return;\n    }\n    void pull(int ind) {\n \
    \       sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n    }\n    /// t == 0 is\
    \ add, t == 1 is for multiplying\n    void upd(int lo, int hi, int t, T inc, int\
    \ ind = 1, int L = 0, int R = SZ - 1) {\n        push(ind, L, R);\n        if\
    \ (hi < L || R < lo) return;\n        if (lo <= L && R <= hi) {\n            if(t\
    \ == 0) add[ind] = inc;\n            else mult[ind] = inc;\n            push(ind,\
    \ L, R); return;\n        }\n        int M = (L + R) / 2;\n        upd(lo, hi,\
    \ t, inc, 2 * ind, L, M); upd(lo, hi, t, inc, 2 * ind + 1, M + 1, R);\n      \
    \  pull(ind);\n    }\n    T qsum(int lo, int hi, int ind = 1, int L = 0, int R\
    \ = SZ - 1) {\n        push(ind, L, R);\n        if (lo > R || L > hi) return\
    \ 0;\n        if (lo <= L && R <= hi) return sum[ind];\n        int M = (L + R)\
    \ / 2;\n        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\n    }\n};\nint main() {\n    return 0;\n}\n\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, int SZ>\
    \ struct AffineSeg {\n    T sum[2 * SZ], mult[2 * SZ], add[2 * SZ];\n    void\
    \ push(int ind, int L, int R) { // modify values for current node\n        sum[ind]\
    \ *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n        if (L != R) {\n \
    \           mult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n    \
    \        add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n            add[2\
    \ * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n        }\n        add[ind]\
    \ = 0; mult[ind] = 1;\n    }\n    void init() {\n        for(int i = 0; i < 2\
    \ * SZ; i++){\n            mult[i] = 1;\n            sum[i] = 0;\n           \
    \ add[i] = 0;\n        }\n        return;\n    }\n    void pull(int ind) {\n \
    \       sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n    }\n    /// t == 0 is\
    \ add, t == 1 is for multiplying\n    void upd(int lo, int hi, int t, T inc, int\
    \ ind = 1, int L = 0, int R = SZ - 1) {\n        push(ind, L, R);\n        if\
    \ (hi < L || R < lo) return;\n        if (lo <= L && R <= hi) {\n            if(t\
    \ == 0) add[ind] = inc;\n            else mult[ind] = inc;\n            push(ind,\
    \ L, R); return;\n        }\n        int M = (L + R) / 2;\n        upd(lo, hi,\
    \ t, inc, 2 * ind, L, M); upd(lo, hi, t, inc, 2 * ind + 1, M + 1, R);\n      \
    \  pull(ind);\n    }\n    T qsum(int lo, int hi, int ind = 1, int L = 0, int R\
    \ = SZ - 1) {\n        push(ind, L, R);\n        if (lo > R || L > hi) return\
    \ 0;\n        if (lo <= L && R <= hi) return sum[ind];\n        int M = (L + R)\
    \ / 2;\n        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\n    }\n};\nint main() {\n    return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/mult_add_seg.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/mult_add_seg.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/mult_add_seg.cpp
- /library/library/data-structures/1d-range-queries/mult_add_seg.cpp.html
title: library/data-structures/1d-range-queries/mult_add_seg.cpp
---

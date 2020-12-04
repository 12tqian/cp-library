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
    \n#include<bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <class T, int\
    \ SZ> struct AffineSeg {\r\n    T sum[2 * SZ], mult[2 * SZ], add[2 * SZ];\r\n\
    \    void push(int ind, int L, int R) { // modify values for current node\r\n\
    \        sum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\r\n      \
    \  if (L != R) {\r\n            mult[2 * ind] *= mult[ind]; mult[2 * ind + 1]\
    \ *= mult[ind];\r\n            add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\r\
    \n            add[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\r\n\
    \        }\r\n        add[ind] = 0; mult[ind] = 1;\r\n    }\r\n    void init()\
    \ {\r\n        for(int i = 0; i < 2 * SZ; i++){\r\n            mult[i] = 1;\r\n\
    \            sum[i] = 0;\r\n            add[i] = 0;\r\n        }\r\n        return;\r\
    \n    }\r\n    void pull(int ind) {\r\n        sum[ind] = sum[2 * ind] + sum[2\
    \ * ind + 1];\r\n    }\r\n    /// t == 0 is add, t == 1 is for multiplying\r\n\
    \    void upd(int lo, int hi, int t, T inc, int ind = 1, int L = 0, int R = SZ\
    \ - 1) {\r\n        push(ind, L, R);\r\n        if (hi < L || R < lo) return;\r\
    \n        if (lo <= L && R <= hi) {\r\n            if(t == 0) add[ind] = inc;\r\
    \n            else mult[ind] = inc;\r\n            push(ind, L, R); return;\r\n\
    \        }\r\n        int M = (L + R) / 2;\r\n        upd(lo, hi, t, inc, 2 *\
    \ ind, L, M); upd(lo, hi, t, inc, 2 * ind + 1, M + 1, R);\r\n        pull(ind);\r\
    \n    }\r\n    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1)\
    \ {\r\n        push(ind, L, R);\r\n        if (lo > R || L > hi) return 0;\r\n\
    \        if (lo <= L && R <= hi) return sum[ind];\r\n        int M = (L + R) /\
    \ 2;\r\n        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n\r\n"
  code: "#include<bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <class T,\
    \ int SZ> struct AffineSeg {\r\n    T sum[2 * SZ], mult[2 * SZ], add[2 * SZ];\r\
    \n    void push(int ind, int L, int R) { // modify values for current node\r\n\
    \        sum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\r\n      \
    \  if (L != R) {\r\n            mult[2 * ind] *= mult[ind]; mult[2 * ind + 1]\
    \ *= mult[ind];\r\n            add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\r\
    \n            add[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\r\n\
    \        }\r\n        add[ind] = 0; mult[ind] = 1;\r\n    }\r\n    void init()\
    \ {\r\n        for(int i = 0; i < 2 * SZ; i++){\r\n            mult[i] = 1;\r\n\
    \            sum[i] = 0;\r\n            add[i] = 0;\r\n        }\r\n        return;\r\
    \n    }\r\n    void pull(int ind) {\r\n        sum[ind] = sum[2 * ind] + sum[2\
    \ * ind + 1];\r\n    }\r\n    /// t == 0 is add, t == 1 is for multiplying\r\n\
    \    void upd(int lo, int hi, int t, T inc, int ind = 1, int L = 0, int R = SZ\
    \ - 1) {\r\n        push(ind, L, R);\r\n        if (hi < L || R < lo) return;\r\
    \n        if (lo <= L && R <= hi) {\r\n            if(t == 0) add[ind] = inc;\r\
    \n            else mult[ind] = inc;\r\n            push(ind, L, R); return;\r\n\
    \        }\r\n        int M = (L + R) / 2;\r\n        upd(lo, hi, t, inc, 2 *\
    \ ind, L, M); upd(lo, hi, t, inc, 2 * ind + 1, M + 1, R);\r\n        pull(ind);\r\
    \n    }\r\n    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1)\
    \ {\r\n        push(ind, L, R);\r\n        if (lo > R || L > hi) return 0;\r\n\
    \        if (lo <= L && R <= hi) return sum[ind];\r\n        int M = (L + R) /\
    \ 2;\r\n        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/mult_add_seg.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:53:05-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/mult_add_seg.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/mult_add_seg.cpp
- /library/library/data-structures/1d-range-queries/mult_add_seg.cpp.html
title: library/data-structures/1d-range-queries/mult_add_seg.cpp
---

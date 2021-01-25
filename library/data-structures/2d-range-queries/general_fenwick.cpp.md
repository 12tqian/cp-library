---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/2d-range-queries/general_fenwick.cpp\"\
    \n#include<bits/stdc++.h>\n\n/**\n * 1-indexed \n * log(n)^2 query, update\n *\
    \ O(n^2) space\n */\n\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x);\
    \ } \n\ntemplate <class T, int ...Ns> struct BIT {\n    T val = 0; void upd(T\
    \ v) { val += v; }\n    T query() { return val; }\n};\n\ntemplate <class T, int\
    \ N, int... Ns> struct BIT<T, N, Ns...> {\n    BIT<T, Ns...> bit[N + 1];\n\n \
    \   template <typename... Args> void upd(int pos, Args... args) { \n        assert(pos\
    \ > 0);\n        for (; pos <= N; pos += pos & -pos) \n            bit[pos].upd(args...);\
    \ \n    }\n\n    template <typename... Args> T sum(int r, Args... args) {\n  \
    \      T res = 0; \n        for (; r; r -= r & -r) \n            res += bit[r].query(args...);\
    \ \n        return res; \n    }\n\n    template <typename... Args> T query(int\
    \ l, int r, Args... args) { \n        return sum(r, args...) - sum(l - 1, args...);\
    \ \n    }\n\n    int get_kth(T des) { \n        assert(des > 0);\n        int\
    \ ind = 0;\n        for (int i = 1 << bits(N); i; i /= 2)\n            if (ind\
    \ + i <= N && bit[ind + i].val < des)\n                des -= bit[ind += i].val;\n\
    \        assert(ind < N); return ind + 1;\n    }\n}; \n\n"
  code: "#include<bits/stdc++.h>\n\n/**\n * 1-indexed \n * log(n)^2 query, update\n\
    \ * O(n^2) space\n */\n\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 -\
    \ __builtin_clz(x); } \n\ntemplate <class T, int ...Ns> struct BIT {\n    T val\
    \ = 0; void upd(T v) { val += v; }\n    T query() { return val; }\n};\n\ntemplate\
    \ <class T, int N, int... Ns> struct BIT<T, N, Ns...> {\n    BIT<T, Ns...> bit[N\
    \ + 1];\n\n    template <typename... Args> void upd(int pos, Args... args) { \n\
    \        assert(pos > 0);\n        for (; pos <= N; pos += pos & -pos) \n    \
    \        bit[pos].upd(args...); \n    }\n\n    template <typename... Args> T sum(int\
    \ r, Args... args) {\n        T res = 0; \n        for (; r; r -= r & -r) \n \
    \           res += bit[r].query(args...); \n        return res; \n    }\n\n  \
    \  template <typename... Args> T query(int l, int r, Args... args) { \n      \
    \  return sum(r, args...) - sum(l - 1, args...); \n    }\n\n    int get_kth(T\
    \ des) { \n        assert(des > 0);\n        int ind = 0;\n        for (int i\
    \ = 1 << bits(N); i; i /= 2)\n            if (ind + i <= N && bit[ind + i].val\
    \ < des)\n                des -= bit[ind += i].val;\n        assert(ind < N);\
    \ return ind + 1;\n    }\n}; \n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/general_fenwick.cpp
  requiredBy: []
  timestamp: '2021-01-25 13:56:14-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/general_fenwick.cpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/general_fenwick.cpp
- /library/library/data-structures/2d-range-queries/general_fenwick.cpp.html
title: library/data-structures/2d-range-queries/general_fenwick.cpp
---

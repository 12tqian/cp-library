---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n/**\n * 1-indexed \n * log(n)^2 query, update\n * O(n^2) space\n\
    \ */\n\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x);\
    \ } \n\ntemplate <class T, int ...Ns> struct BIT {\n\tT val = 0; void upd(T v)\
    \ { val += v; }\n\tT query() { return val; }\n};\n\ntemplate <class T, int N,\
    \ int... Ns> struct BIT<T, N, Ns...> {\n\tBIT<T, Ns...> bit[N + 1];\n\n\ttemplate\
    \ <typename... Args> void upd(int pos, Args... args) { \n\t\tassert(pos > 0);\n\
    \t\tfor (; pos <= N; pos += pos & -pos) \n\t\t\tbit[pos].upd(args...); \n\t}\n\
    \n\ttemplate <typename... Args> T sum(int r, Args... args) {\n\t\tT res = 0; \n\
    \t\tfor (; r; r -= r & -r) \n\t\t\tres += bit[r].query(args...); \n\t\treturn\
    \ res; \n\t}\n\n\ttemplate <typename... Args> T query(int l, int r, Args... args)\
    \ { \n\t\treturn sum(r, args...) - sum(l - 1, args...); \n\t}\n\n\tint get_kth(T\
    \ des) { \n\t\tassert(des > 0);\n\t\tint ind = 0;\n\t\tfor (int i = 1 << bits(N);\
    \ i; i /= 2)\n\t\t\tif (ind + i <= N && bit[ind + i].val < des)\n\t\t\t\tdes -=\
    \ bit[ind += i].val;\n\t\tassert(ind < N); return ind + 1;\n\t}\n}; \n\n"
  code: "#pragma once\n\n/**\n * 1-indexed \n * log(n)^2 query, update\n * O(n^2)\
    \ space\n */\n\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x);\
    \ } \n\ntemplate <class T, int ...Ns> struct BIT {\n\tT val = 0; void upd(T v)\
    \ { val += v; }\n\tT query() { return val; }\n};\n\ntemplate <class T, int N,\
    \ int... Ns> struct BIT<T, N, Ns...> {\n\tBIT<T, Ns...> bit[N + 1];\n\n\ttemplate\
    \ <typename... Args> void upd(int pos, Args... args) { \n\t\tassert(pos > 0);\n\
    \t\tfor (; pos <= N; pos += pos & -pos) \n\t\t\tbit[pos].upd(args...); \n\t}\n\
    \n\ttemplate <typename... Args> T sum(int r, Args... args) {\n\t\tT res = 0; \n\
    \t\tfor (; r; r -= r & -r) \n\t\t\tres += bit[r].query(args...); \n\t\treturn\
    \ res; \n\t}\n\n\ttemplate <typename... Args> T query(int l, int r, Args... args)\
    \ { \n\t\treturn sum(r, args...) - sum(l - 1, args...); \n\t}\n\n\tint get_kth(T\
    \ des) { \n\t\tassert(des > 0);\n\t\tint ind = 0;\n\t\tfor (int i = 1 << bits(N);\
    \ i; i /= 2)\n\t\t\tif (ind + i <= N && bit[ind + i].val < des)\n\t\t\t\tdes -=\
    \ bit[ind += i].val;\n\t\tassert(ind < N); return ind + 1;\n\t}\n}; \n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/general-fenwick.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/general-fenwick.hpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/general-fenwick.hpp
- /library/library/data-structures/2d-range-queries/general-fenwick.hpp.html
title: library/data-structures/2d-range-queries/general-fenwick.hpp
---

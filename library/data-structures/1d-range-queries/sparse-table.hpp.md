---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graphs/lca-rmq.hpp
    title: LCA RMQ
  - icon: ':heavy_check_mark:'
    path: library/string/suffix-array-lcp.hpp
    title: Suffix Array with Longest Common Prefix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1074F.test.cpp
    title: verify/codeforces/codeforces-1074F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
    title: verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
    title: verify/yosupo/yosupo-suffixarray-lcp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct SparseTable {\r\n\tstd::vector<T> v;\r\
    \n\tstd::vector<std::vector<int>> jump;\r\n\r\n\tint level(int x) { return 31\
    \ - __builtin_clz(x); }\r\n\r\n\tint comb(int a, int b) {\r\n\t\treturn v[a] ==\
    \ v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\r\n\t}\r\n\r\n\tvoid init(const\
    \ std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\t\tjump = {std::vector<int>((int)v.size())};\r\
    \n\t\tiota(jump[0].begin(), jump[0].end(), 0);\r\n\t\tfor (int j = 1; (1 << j)\
    \ <= (int)v.size(); j++) {\r\n\t\t\tjump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\r\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\r\
    \n\t\t\t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint index(int l, int r) {\r\n\t\tassert(l <=\
    \ r);\r\n\t\tint d = level(r - l + 1);\r\n\t\treturn comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn v[index(l,\
    \ r)];\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct SparseTable {\r\n\tstd::vector<T>\
    \ v;\r\n\tstd::vector<std::vector<int>> jump;\r\n\r\n\tint level(int x) { return\
    \ 31 - __builtin_clz(x); }\r\n\r\n\tint comb(int a, int b) {\r\n\t\treturn v[a]\
    \ == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\r\n\t}\r\n\r\n\tvoid init(const\
    \ std::vector<T>& _v) {\r\n\t\tv = _v;\r\n\t\tjump = {std::vector<int>((int)v.size())};\r\
    \n\t\tiota(jump[0].begin(), jump[0].end(), 0);\r\n\t\tfor (int j = 1; (1 << j)\
    \ <= (int)v.size(); j++) {\r\n\t\t\tjump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\r\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\r\
    \n\t\t\t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint index(int l, int r) {\r\n\t\tassert(l <=\
    \ r);\r\n\t\tint d = level(r - l + 1);\r\n\t\treturn comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn v[index(l,\
    \ r)];\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/sparse-table.hpp
  requiredBy:
  - library/string/suffix-array-lcp.hpp
  - library/graphs/lca-rmq.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1074F.test.cpp
  - verify/yosupo/yosupo-lca-lca-rmq.test.cpp
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/yosupo/yosupo-suffixarray-lcp.test.cpp
documentation_of: library/data-structures/1d-range-queries/sparse-table.hpp
layout: document
title: Sparse Table
---

## Sparse Table

Unfortunately, I'm not sure how to template this to do $\max$ also since you have to access `v`. This can't be modified for "destrutive combinations" like $\gcd$. 

### Assumptions
- $0$-indexed. 

### Functions
- `comb(a, b)`: You can modify this for different combinations, right now it's set to get the $min$ of elements at indices $a, b$ with tie broken by the minimum index. 
- `index(l, r)`: Gets index of $\text{min}$ element in range $[l, r]$ in $\mathcal O(1)$. 
- `query(l, r)`: Gets minimum element in range $[l, r]$ in $\mathcal O(1)$. 
- `init(v)`: Initializes for array $v$ in $\mathcal O(n \log(n))$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/Static%20Range%20Queries%20(9.1)/RMQ%20(9.1).h)

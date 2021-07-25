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
  bundledCode: "\n/**\n * This Sparse Table stores indices of things\n * For destructive\
    \ combinations like gcd, use associative_range_query.cpp\n * Use this for min,\
    \ max, and when you need the indices of things\n */\n\ntemplate <class T> struct\
    \ SparseTable {\n\tstd::vector<T> v;\n\tstd::vector<std::vector<int>> jump;\n\n\
    \tint level(int x) { return 31 - __builtin_clz(x); }\n\n\tint comb(int a, int\
    \ b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n\t\
    }\n\n\tvoid init(const std::vector<T> &_v) {\n\t\tv = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\
    \t\tiota(jump[0].begin(), jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <=\
    \ (int)v.size(); j++) {\n\t\t\tjump.push_back(std::vector<int>((int)v.size() -\
    \ (1 << j) + 1));\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\
    \t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tint index(int l, int r) {\n\t\tassert(l <= r);\n\t\tint d =\
    \ level(r - l + 1);\n\t\treturn comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\treturn v[index(l, r)];\n\t}\n};\n"
  code: "#pragma once\n\n/**\n * This Sparse Table stores indices of things\n * For\
    \ destructive combinations like gcd, use associative_range_query.cpp\n * Use this\
    \ for min, max, and when you need the indices of things\n */\n\ntemplate <class\
    \ T> struct SparseTable {\n\tstd::vector<T> v;\n\tstd::vector<std::vector<int>>\
    \ jump;\n\n\tint level(int x) { return 31 - __builtin_clz(x); }\n\n\tint comb(int\
    \ a, int b) {\n\t\treturn v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n\
    \t}\n\n\tvoid init(const std::vector<T> &_v) {\n\t\tv = _v;\n\t\tjump = {std::vector<int>((int)v.size())};\n\
    \t\tiota(jump[0].begin(), jump[0].end(), 0);\n\t\tfor (int j = 1; (1 << j) <=\
    \ (int)v.size(); j++) {\n\t\t\tjump.push_back(std::vector<int>((int)v.size() -\
    \ (1 << j) + 1));\n\t\t\tfor (int i = 0; i < (int)jump[j].size(); i++) {\n\t\t\
    \t\tjump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tint index(int l, int r) {\n\t\tassert(l <= r);\n\t\tint d =\
    \ level(r - l + 1);\n\t\treturn comb(jump[d][l], jump[d][r - (1 << d) + 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\treturn v[index(l, r)];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/sparse-table.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:49:44-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/sparse-table.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/sparse-table.hpp
- /library/library/data-structures/1d-range-queries/sparse-table.hpp.html
title: library/data-structures/1d-range-queries/sparse-table.hpp
---

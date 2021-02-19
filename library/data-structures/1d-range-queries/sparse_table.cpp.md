---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/sparse_table.cpp\"\
    \n#include<bits/stdc++.h>\n\ntemplate <class T> struct SparseTable {\n    std::vector<T>\
    \ v;\n    std::vector<std::vector<int>> jump;\n\n    int level(int x) { return\
    \ 31 - __builtin_clz(x); }\n\n    int comb(int a, int b) {\n        return v[a]\
    \ == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n    }\n\n    void init(const\
    \ std::vector<T>& _v) {\n        v = _v;\n        jump = {std::vector<int>((int)v.size())};\n\
    \        iota(jump[0].begin(), jump[0].end(), 0);\n        for (int j = 1; (1\
    \ << j) <= (int)v.size(); j++) {\n            jump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\n            for (int i = 0; i < (int)jump[j].size(); i++)\
    \ {\n                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j\
    \ - 1))]);\n            }\n        }\n    }\n\n    int index(int l, int r) {\n\
    \        assert(l <= r);\n        int d = level(r - l + 1);\n        return comb(jump[d][l],\
    \ jump[d][r - (1 << d) + 1]);\n    }\n\n    T query(int l, int r) {\n        return\
    \ v[index(l, r)];\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class T> struct SparseTable {\n    std::vector<T>\
    \ v;\n    std::vector<std::vector<int>> jump;\n\n    int level(int x) { return\
    \ 31 - __builtin_clz(x); }\n\n    int comb(int a, int b) {\n        return v[a]\
    \ == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\n    }\n\n    void init(const\
    \ std::vector<T>& _v) {\n        v = _v;\n        jump = {std::vector<int>((int)v.size())};\n\
    \        iota(jump[0].begin(), jump[0].end(), 0);\n        for (int j = 1; (1\
    \ << j) <= (int)v.size(); j++) {\n            jump.push_back(std::vector<int>((int)v.size()\
    \ - (1 << j) + 1));\n            for (int i = 0; i < (int)jump[j].size(); i++)\
    \ {\n                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j\
    \ - 1))]);\n            }\n        }\n    }\n\n    int index(int l, int r) {\n\
    \        assert(l <= r);\n        int d = level(r - l + 1);\n        return comb(jump[d][l],\
    \ jump[d][r - (1 << d) + 1]);\n    }\n\n    T query(int l, int r) {\n        return\
    \ v[index(l, r)];\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/sparse_table.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/sparse_table.cpp
- /library/library/data-structures/1d-range-queries/sparse_table.cpp.html
title: library/data-structures/1d-range-queries/sparse_table.cpp
---

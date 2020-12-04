---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\data-structures\\\\1d-range-queries\\\\sparse_table.cpp\"\
    \n#include<bits/stdc++.h>\r\ntemplate <class T> struct SparseTable {\r\n    std::vector<T>\
    \ v;\r\n    std::vector<std::vector<int>> jump;\r\n    int level(int x) {\r\n\
    \        return 31 - __builtin_clz(x);\r\n    }\r\n    int comb(int a, int b)\
    \ {\r\n        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);\r\
    \n    }\r\n    void init(const std::vector<T>& _v) {\r\n        v = _v;\r\n  \
    \      jump = {std::vector<int>(v.size())};\r\n        iota(jump[0].begin(), jump[0].end(),\
    \ 0);\r\n        for (int j = 1; (1 << j) <= v.size(); j++) {\r\n            jump.push_back(std::vector<int>(v.size()\
    \ - (1 << j) + 1));\r\n            for (int i = 0; i < jump[j].size(); i++) {\r\
    \n                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j -\
    \ 1))]);\r\n            }\r\n        }\r\n    }\r\n    int index(int l, int r)\
    \ {\r\n        assert(l <= r);\r\n        int d = level(r - l + 1);\r\n      \
    \  return comb(jump[d][l], jump[d][r - (1 << d) + 1]);\r\n    }\r\n    T query(int\
    \ l, int r) {\r\n        return v[index(l, r)];\r\n    }\r\n};\r\nint main() {\r\
    \n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\ntemplate <class T> struct SparseTable {\r\n  \
    \  std::vector<T> v;\r\n    std::vector<std::vector<int>> jump;\r\n    int level(int\
    \ x) {\r\n        return 31 - __builtin_clz(x);\r\n    }\r\n    int comb(int a,\
    \ int b) {\r\n        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a\
    \ : b);\r\n    }\r\n    void init(const std::vector<T>& _v) {\r\n        v = _v;\r\
    \n        jump = {std::vector<int>(v.size())};\r\n        iota(jump[0].begin(),\
    \ jump[0].end(), 0);\r\n        for (int j = 1; (1 << j) <= v.size(); j++) {\r\
    \n            jump.push_back(std::vector<int>(v.size() - (1 << j) + 1));\r\n \
    \           for (int i = 0; i < jump[j].size(); i++) {\r\n                jump[j][i]\
    \ = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);\r\n            }\r\n\
    \        }\r\n    }\r\n    int index(int l, int r) {\r\n        assert(l <= r);\r\
    \n        int d = level(r - l + 1);\r\n        return comb(jump[d][l], jump[d][r\
    \ - (1 << d) + 1]);\r\n    }\r\n    T query(int l, int r) {\r\n        return\
    \ v[index(l, r)];\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\data-structures\1d-range-queries\sparse_table.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:53:28-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\data-structures\1d-range-queries\sparse_table.cpp
layout: document
redirect_from:
- /library\library\data-structures\1d-range-queries\sparse_table.cpp
- /library\library\data-structures\1d-range-queries\sparse_table.cpp.html
title: library\data-structures\1d-range-queries\sparse_table.cpp
---

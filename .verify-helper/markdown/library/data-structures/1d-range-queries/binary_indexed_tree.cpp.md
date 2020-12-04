---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/binary_indexed_tree.cpp\"\
    \n#include<bits/stdc++.h>\r\n\r\ntemplate <class T> struct BIT {\r\n    std::vector<T>\
    \ bit;\r\n    int n;\r\n    void init(int n_) {\r\n        n = n_;\r\n       \
    \ bit.resize(n);\r\n    }\r\n    void init(std::vector<int> a) {\r\n        n\
    \ = (int) a.size();\r\n        for (int i = 0; i < (int) a.size(); i++) {\r\n\
    \            add(i, a[i]);\r\n        }\r\n    }\r\n    T sum(int r) {\r\n   \
    \     T ret = 0;\r\n        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];\r\
    \n        return ret;\r\n    }\r\n    T query(int l, int r) {\r\n        return\
    \ sum(r) - sum(l - 1);\r\n    }\r\n    void add(int idx, T delta) {\r\n      \
    \  for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;\r\n    }\r\n};\r\n\
    \r\nint main() {\r\n    return 0;\r\n}\n"
  code: "#include<bits/stdc++.h>\r\n\r\ntemplate <class T> struct BIT {\r\n    std::vector<T>\
    \ bit;\r\n    int n;\r\n    void init(int n_) {\r\n        n = n_;\r\n       \
    \ bit.resize(n);\r\n    }\r\n    void init(std::vector<int> a) {\r\n        n\
    \ = (int) a.size();\r\n        for (int i = 0; i < (int) a.size(); i++) {\r\n\
    \            add(i, a[i]);\r\n        }\r\n    }\r\n    T sum(int r) {\r\n   \
    \     T ret = 0;\r\n        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];\r\
    \n        return ret;\r\n    }\r\n    T query(int l, int r) {\r\n        return\
    \ sum(r) - sum(l - 1);\r\n    }\r\n    void add(int idx, T delta) {\r\n      \
    \  for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;\r\n    }\r\n};\r\n\
    \r\nint main() {\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:52:53-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/binary_indexed_tree.cpp
- /library/library/data-structures/1d-range-queries/binary_indexed_tree.cpp.html
title: library/data-structures/1d-range-queries/binary_indexed_tree.cpp
---

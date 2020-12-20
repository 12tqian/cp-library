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
    \n#include<bits/stdc++.h>\n\ntemplate <class T> struct BIT {\n    std::vector<T>\
    \ bit;\n    int n;\n    void init(int n_) {\n        n = n_;\n        bit.resize(n);\n\
    \    }\n    void init(std::vector<T>& a) {\n        n = (int) a.size();\n    \
    \    a.assign(n, 0);\n        for (int i = 0; i < (int) a.size(); i++) {\n   \
    \         add(i, a[i]);\n        }\n    }\n    T sum(int r) {\n        T ret =\
    \ 0;\n        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];\n        return\
    \ ret;\n    }\n    T query(int l, int r) {\n        return sum(r) - sum(l - 1);\n\
    \    }\n    void add(int idx, T delta) {\n        for (; idx < n; idx = idx |\
    \ (idx + 1)) bit[idx] += delta;\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class T> struct BIT {\n    std::vector<T>\
    \ bit;\n    int n;\n    void init(int n_) {\n        n = n_;\n        bit.resize(n);\n\
    \    }\n    void init(std::vector<T>& a) {\n        n = (int) a.size();\n    \
    \    a.assign(n, 0);\n        for (int i = 0; i < (int) a.size(); i++) {\n   \
    \         add(i, a[i]);\n        }\n    }\n    T sum(int r) {\n        T ret =\
    \ 0;\n        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];\n        return\
    \ ret;\n    }\n    T query(int l, int r) {\n        return sum(r) - sum(l - 1);\n\
    \    }\n    void add(int idx, T delta) {\n        for (; idx < n; idx = idx |\
    \ (idx + 1)) bit[idx] += delta;\n    }\n};\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2020-12-20 13:44:35-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/binary_indexed_tree.cpp
- /library/library/data-structures/1d-range-queries/binary_indexed_tree.cpp.html
title: library/data-structures/1d-range-queries/binary_indexed_tree.cpp
---

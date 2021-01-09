---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/fenwick.cpp\"\n\
    #include<bits/stdc++.h>\n\ntemplate <class T> struct FenwickTree {\n    std::vector<T>\
    \ fwt;\n    int n;\n\n    void init(int n_) {\n        n = n_;\n        fwt.resize(n);\n\
    \    }\n\n    void init(std::vector<T>& a) {\n        n = (int) a.size();\n  \
    \      a.assign(n, 0);\n        for (int i = 0; i < (int) a.size(); i++) {\n \
    \           add(i, a[i]);\n        }\n    }\n\n    T sum(int r) {\n        T ret\
    \ = 0;\n        for (; r >= 0; r = (r & (r + 1)) - 1) \n            ret += fwt[r];\n\
    \        return ret;\n    }\n\n    T query(int l, int r) {\n        return sum(r)\
    \ - sum(l - 1);\n    }\n    \n    void add(int idx, T delta) {\n        for (;\
    \ idx < n; idx = idx | (idx + 1)) \n            fwt[idx] += delta;\n    }\n};\n\
    \nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class T> struct FenwickTree {\n    std::vector<T>\
    \ fwt;\n    int n;\n\n    void init(int n_) {\n        n = n_;\n        fwt.resize(n);\n\
    \    }\n\n    void init(std::vector<T>& a) {\n        n = (int) a.size();\n  \
    \      a.assign(n, 0);\n        for (int i = 0; i < (int) a.size(); i++) {\n \
    \           add(i, a[i]);\n        }\n    }\n\n    T sum(int r) {\n        T ret\
    \ = 0;\n        for (; r >= 0; r = (r & (r + 1)) - 1) \n            ret += fwt[r];\n\
    \        return ret;\n    }\n\n    T query(int l, int r) {\n        return sum(r)\
    \ - sum(l - 1);\n    }\n    \n    void add(int idx, T delta) {\n        for (;\
    \ idx < n; idx = idx | (idx + 1)) \n            fwt[idx] += delta;\n    }\n};\n\
    \nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/fenwick.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/fenwick.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/fenwick.cpp
- /library/library/data-structures/1d-range-queries/fenwick.cpp.html
title: library/data-structures/1d-range-queries/fenwick.cpp
---

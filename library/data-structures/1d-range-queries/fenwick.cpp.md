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
    #include <bits/stdc++.h>\n\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T>\
    \ fwt;\n\tint n;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\
    \t}\n\n\tvoid init(std::vector<T> &a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t\
    }\n\t}\n\n\tT sum(int r) {\n\t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1))\
    \ - 1) \n\t\t\tret += fwt[r];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\treturn sum(r) - sum(l - 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\
    \t\tfor (; idx < n; idx = idx | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};\n\
    \nint main() {\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T>\
    \ fwt;\n\tint n;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\
    \t}\n\n\tvoid init(std::vector<T> &a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t\
    }\n\t}\n\n\tT sum(int r) {\n\t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1))\
    \ - 1) \n\t\t\tret += fwt[r];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\treturn sum(r) - sum(l - 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\
    \t\tfor (; idx < n; idx = idx | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};\n\
    \nint main() {\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/fenwick.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/fenwick.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/fenwick.cpp
- /library/library/data-structures/1d-range-queries/fenwick.cpp.html
title: library/data-structures/1d-range-queries/fenwick.cpp
---

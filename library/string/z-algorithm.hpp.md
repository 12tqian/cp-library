---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-zalgorithm.test.cpp
    title: verify/yosupo/yosupo-zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class C> std::vector<int> z_algorithm(C s) {\r\n\tint\
    \ n = (int)s.size();\r\n\tstd::vector<int> a(n);\r\n\ta[0] = n;\r\n\tint i = 1,\
    \ j = 0;\r\n\twhile (i < n) {\r\n\t\twhile (i + j < n && s[j] == s[i + j]) ++j;\r\
    \n\t\ta[i] = j;\r\n\t\tif (j == 0) {\r\n\t\t\t++i;\r\n\t\t\tcontinue;\r\n\t\t\
    }\r\n\t\tint k = 1;\r\n\t\twhile (i + k < n && k + a[k] < j) a[i + k] = a[k],\
    \ ++k;\r\n\t\ti += k;\r\n\t\tj -= k;\r\n\t}\r\n\treturn a;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class C> std::vector<int> z_algorithm(C s)\
    \ {\r\n\tint n = (int)s.size();\r\n\tstd::vector<int> a(n);\r\n\ta[0] = n;\r\n\
    \tint i = 1, j = 0;\r\n\twhile (i < n) {\r\n\t\twhile (i + j < n && s[j] == s[i\
    \ + j]) ++j;\r\n\t\ta[i] = j;\r\n\t\tif (j == 0) {\r\n\t\t\t++i;\r\n\t\t\tcontinue;\r\
    \n\t\t}\r\n\t\tint k = 1;\r\n\t\twhile (i + k < n && k + a[k] < j) a[i + k] =\
    \ a[k], ++k;\r\n\t\ti += k;\r\n\t\tj -= k;\r\n\t}\r\n\treturn a;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-zalgorithm.test.cpp
documentation_of: library/string/z-algorithm.hpp
layout: document
redirect_from:
- /library/library/string/z-algorithm.hpp
- /library/library/string/z-algorithm.hpp.html
title: library/string/z-algorithm.hpp
---

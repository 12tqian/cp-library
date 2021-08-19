---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-zalgorithm.test.cpp
    title: verify/yosupo/yosupo-zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class C> std::vector<int> z_algorithm(C s) {\n\tint n\
    \ = (int)s.size();\n\tstd::vector<int> a(n);\n\ta[0] = n;\n\tint i = 1, j = 0;\n\
    \twhile (i < n) {\n\t\twhile (i + j < n && s[j] == s[i + j]) ++j;\n\t\ta[i] =\
    \ j;\n\t\tif (j == 0) {\n\t\t\t++i;\n\t\t\tcontinue;\n\t\t}\n\t\tint k = 1;\n\t\
    \twhile (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;\n\t\ti += k;\n\t\tj\
    \ -= k;\n\t}\n\treturn a;\n}\n"
  code: "#pragma once\n\ntemplate <class C> std::vector<int> z_algorithm(C s) {\n\t\
    int n = (int)s.size();\n\tstd::vector<int> a(n);\n\ta[0] = n;\n\tint i = 1, j\
    \ = 0;\n\twhile (i < n) {\n\t\twhile (i + j < n && s[j] == s[i + j]) ++j;\n\t\t\
    a[i] = j;\n\t\tif (j == 0) {\n\t\t\t++i;\n\t\t\tcontinue;\n\t\t}\n\t\tint k =\
    \ 1;\n\t\twhile (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;\n\t\ti += k;\n\
    \t\tj -= k;\n\t}\n\treturn a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2021-08-19 11:01:30-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-zalgorithm.test.cpp
documentation_of: library/string/z-algorithm.hpp
layout: document
redirect_from:
- /library/library/string/z-algorithm.hpp
- /library/library/string/z-algorithm.hpp.html
title: library/string/z-algorithm.hpp
---

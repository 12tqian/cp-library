---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-MMFSUNDARAM.test.cpp
    title: verify/spoj/spoj-MMFSUNDARAM.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <int SZ> struct Sieve {\r\n\tstd::bitset<SZ> pri;\r\n\
    \tstd::vector<int> pr;\r\n\t\r\n\tSieve() {\r\n\t\tpri.set();\r\n\t\tpri[0] =\
    \ pri[1] = 0;\r\n\t\tfor (int i = 4; i < SZ; i += 2) {\r\n\t\t\tpri[i] = 0;\r\n\
    \t\t}\r\n\t\tfor (int i = 3; i * i < SZ; i += 2) {\r\n\t\t\tif (pri[i]) {\r\n\t\
    \t\t\tfor (int j = i * i; j < SZ; j += 2 * i) {\r\n\t\t\t\t\tpri[j] = 0;\r\n\t\
    \t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 0; i < SZ; i++) {\r\n\t\t\tif\
    \ (pri[i]) {\r\n\t\t\t\tpr.push_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <int SZ> struct Sieve {\r\n\tstd::bitset<SZ>\
    \ pri;\r\n\tstd::vector<int> pr;\r\n\t\r\n\tSieve() {\r\n\t\tpri.set();\r\n\t\t\
    pri[0] = pri[1] = 0;\r\n\t\tfor (int i = 4; i < SZ; i += 2) {\r\n\t\t\tpri[i]\
    \ = 0;\r\n\t\t}\r\n\t\tfor (int i = 3; i * i < SZ; i += 2) {\r\n\t\t\tif (pri[i])\
    \ {\r\n\t\t\t\tfor (int j = i * i; j < SZ; j += 2 * i) {\r\n\t\t\t\t\tpri[j] =\
    \ 0;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 0; i < SZ; i++) {\r\n\
    \t\t\tif (pri[i]) {\r\n\t\t\t\tpr.push_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/sieve.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-MMFSUNDARAM.test.cpp
documentation_of: library/number-theory/sieve.hpp
layout: document
redirect_from:
- /library/library/number-theory/sieve.hpp
- /library/library/number-theory/sieve.hpp.html
title: library/number-theory/sieve.hpp
---

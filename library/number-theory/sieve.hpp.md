---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/spoj/spoj-MMFSUNDARAM.test.cpp
    title: verify/spoj/spoj-MMFSUNDARAM.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\ntemplate <int SZ> struct Sieve {\n\tstd::bitset<SZ> pri;\n\tstd::vector<int>\
    \ pr;\n\t\n\tSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1] = 0;\n\t\tfor (int\
    \ i = 4; i < SZ; i += 2) {\n\t\t\tpri[i] = 0;\n\t\t}\n\t\tfor (int i = 3; i *\
    \ i < SZ; i += 2) {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor (int j = i * i; j < SZ;\
    \ j += 2 * i) {\n\t\t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int\
    \ i = 0; i < SZ; i++) {\n\t\t\tif (pri[i]) {\n\t\t\t\tpr.push_back(i);\n\t\t\t\
    }\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <int SZ> struct Sieve {\n\tstd::bitset<SZ> pri;\n\
    \tstd::vector<int> pr;\n\t\n\tSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1] =\
    \ 0;\n\t\tfor (int i = 4; i < SZ; i += 2) {\n\t\t\tpri[i] = 0;\n\t\t}\n\t\tfor\
    \ (int i = 3; i * i < SZ; i += 2) {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor (int j =\
    \ i * i; j < SZ; j += 2 * i) {\n\t\t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t\tfor (int i = 0; i < SZ; i++) {\n\t\t\tif (pri[i]) {\n\t\t\t\tpr.push_back(i);\n\
    \t\t\t}\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/sieve.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/spoj/spoj-MMFSUNDARAM.test.cpp
documentation_of: library/number-theory/sieve.hpp
layout: document
redirect_from:
- /library/library/number-theory/sieve.hpp
- /library/library/number-theory/sieve.hpp.html
title: library/number-theory/sieve.hpp
---

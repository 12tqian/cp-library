---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/sieve.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <int SZ> struct Sieve {\n\tstd::bitset<SZ> pri;\n\tstd::vector<int>\
    \ pr;\n\t\n\tSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1] = 0;\n\t\tfor (int\
    \ i = 4; i < SZ; i += 2) {\n\t\t\tpri[i] = 0;\n\t\t}\n\t\tfor (int i = 3; i *\
    \ i < SZ; i += 2) {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor (int j = i * i; j < SZ;\
    \ j += 2 * i) {\n\t\t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int\
    \ i = 0; i < SZ; i++) {\n\t\t\tif (pri[i]) {\n\t\t\t\tpr.push_back(i);\n\t\t\t\
    }\n\t\t}\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <int SZ> struct Sieve {\n\tstd::bitset<SZ>\
    \ pri;\n\tstd::vector<int> pr;\n\t\n\tSieve() {\n\t\tpri.set();\n\t\tpri[0] =\
    \ pri[1] = 0;\n\t\tfor (int i = 4; i < SZ; i += 2) {\n\t\t\tpri[i] = 0;\n\t\t\
    }\n\t\tfor (int i = 3; i * i < SZ; i += 2) {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor\
    \ (int j = i * i; j < SZ; j += 2 * i) {\n\t\t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t\tfor (int i = 0; i < SZ; i++) {\n\t\t\tif (pri[i]) {\n\t\t\t\t\
    pr.push_back(i);\n\t\t\t}\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/sieve.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/sieve.cpp
layout: document
redirect_from:
- /library/library/number-theory/sieve.cpp
- /library/library/number-theory/sieve.cpp.html
title: library/number-theory/sieve.cpp
---

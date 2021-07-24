---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/fast_factor_sieve.cpp\"\n#include\
    \ <bits/stdc++.h>\n\ntemplate <int SZ> struct Sieve {\n\tint spf[SZ];\n\t\n\t\
    Sieve() {\n\t\tspf[1] = 1;\n\t\tfor (int i = 2; i < SZ; i++) \n\t\t\tspf[i] =\
    \ i;\n\t\tfor (int i = 4; i < SZ; i += 2) \n\t\t\tspf[i] = 2;\n\t\tfor (int i\
    \ = 3; i * i < SZ; i++) \n\t\t\tif (spf[i] == i) \n\t\t\t\tfor (int j = i * i;\
    \ j < SZ; j += i) \n\t\t\t\t\tif (spf[j] == j) \n\t\t\t\t\t\tspf[j] = i;\n\t}\n\
    \n\tstd::vector<std::pair<int, int>> factor(int x) {\n\t\tstd::vector<std::pair<int,\
    \ int>> ret;\n\t\twhile (x != 1) {\n\t\t\tif ((int)ret.size() == 0) \n\t\t\t\t\
    ret.emplace_back(spf[x], 1);\n\t\t\telse {\n\t\t\t\tif (ret.back().first == spf[x])\
    \ \n\t\t\t\t\tret.back().second++;\n\t\t\t\telse \n\t\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\n\t\t\t}\n\t\t\tx /= spf[x];\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <int SZ> struct Sieve {\n\tint spf[SZ];\n\
    \t\n\tSieve() {\n\t\tspf[1] = 1;\n\t\tfor (int i = 2; i < SZ; i++) \n\t\t\tspf[i]\
    \ = i;\n\t\tfor (int i = 4; i < SZ; i += 2) \n\t\t\tspf[i] = 2;\n\t\tfor (int\
    \ i = 3; i * i < SZ; i++) \n\t\t\tif (spf[i] == i) \n\t\t\t\tfor (int j = i *\
    \ i; j < SZ; j += i) \n\t\t\t\t\tif (spf[j] == j) \n\t\t\t\t\t\tspf[j] = i;\n\t\
    }\n\n\tstd::vector<std::pair<int, int>> factor(int x) {\n\t\tstd::vector<std::pair<int,\
    \ int>> ret;\n\t\twhile (x != 1) {\n\t\t\tif ((int)ret.size() == 0) \n\t\t\t\t\
    ret.emplace_back(spf[x], 1);\n\t\t\telse {\n\t\t\t\tif (ret.back().first == spf[x])\
    \ \n\t\t\t\t\tret.back().second++;\n\t\t\t\telse \n\t\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\n\t\t\t}\n\t\t\tx /= spf[x];\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/fast_factor_sieve.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/fast_factor_sieve.cpp
layout: document
redirect_from:
- /library/library/number-theory/fast_factor_sieve.cpp
- /library/library/number-theory/fast_factor_sieve.cpp.html
title: library/number-theory/fast_factor_sieve.cpp
---

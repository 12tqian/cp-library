---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/atcoder/atcoder-abc210_f.test.cpp
    title: verify/atcoder/atcoder-abc210_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1553G.test.cpp
    title: verify/codeforces/codeforces-1553G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <int SZ> struct Sieve {\n\tint spf[SZ];\n\t\n\tSieve()\
    \ {\n\t\tspf[1] = 1;\n\t\tfor (int i = 2; i < SZ; i++) \n\t\t\tspf[i] = i;\n\t\
    \tfor (int i = 4; i < SZ; i += 2) \n\t\t\tspf[i] = 2;\n\t\tfor (int i = 3; i *\
    \ i < SZ; i++) \n\t\t\tif (spf[i] == i) \n\t\t\t\tfor (int j = i * i; j < SZ;\
    \ j += i) \n\t\t\t\t\tif (spf[j] == j) \n\t\t\t\t\t\tspf[j] = i;\n\t}\n\n\tstd::vector<std::pair<int,\
    \ int>> factor(int x) {\n\t\tstd::vector<std::pair<int, int>> ret;\n\t\twhile\
    \ (x != 1) {\n\t\t\tif ((int)ret.size() == 0) \n\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\n\t\t\telse {\n\t\t\t\tif (ret.back().first == spf[x]) \n\t\t\t\t\tret.back().second++;\n\
    \t\t\t\telse \n\t\t\t\t\tret.emplace_back(spf[x], 1);\n\t\t\t}\n\t\t\tx /= spf[x];\n\
    \t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <int SZ> struct Sieve {\n\tint spf[SZ];\n\t\n\t\
    Sieve() {\n\t\tspf[1] = 1;\n\t\tfor (int i = 2; i < SZ; i++) \n\t\t\tspf[i] =\
    \ i;\n\t\tfor (int i = 4; i < SZ; i += 2) \n\t\t\tspf[i] = 2;\n\t\tfor (int i\
    \ = 3; i * i < SZ; i++) \n\t\t\tif (spf[i] == i) \n\t\t\t\tfor (int j = i * i;\
    \ j < SZ; j += i) \n\t\t\t\t\tif (spf[j] == j) \n\t\t\t\t\t\tspf[j] = i;\n\t}\n\
    \n\tstd::vector<std::pair<int, int>> factor(int x) {\n\t\tstd::vector<std::pair<int,\
    \ int>> ret;\n\t\twhile (x != 1) {\n\t\t\tif ((int)ret.size() == 0) \n\t\t\t\t\
    ret.emplace_back(spf[x], 1);\n\t\t\telse {\n\t\t\t\tif (ret.back().first == spf[x])\
    \ \n\t\t\t\t\tret.back().second++;\n\t\t\t\telse \n\t\t\t\t\tret.emplace_back(spf[x],\
    \ 1);\n\t\t\t}\n\t\t\tx /= spf[x];\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/fast-factor-sieve.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/atcoder/atcoder-abc210_f.test.cpp
  - verify/codeforces/codeforces-1553G.test.cpp
documentation_of: library/number-theory/fast-factor-sieve.hpp
layout: document
redirect_from:
- /library/library/number-theory/fast-factor-sieve.hpp
- /library/library/number-theory/fast-factor-sieve.hpp.html
title: library/number-theory/fast-factor-sieve.hpp
---

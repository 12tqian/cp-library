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
  bundledCode: "\r\ntemplate <int SZ> struct Sieve {\r\n\tint spf[SZ];\r\n\t\r\n\t\
    Sieve() {\r\n\t\tspf[1] = 1;\r\n\t\tfor (int i = 2; i < SZ; i++) \r\n\t\t\tspf[i]\
    \ = i;\r\n\t\tfor (int i = 4; i < SZ; i += 2) \r\n\t\t\tspf[i] = 2;\r\n\t\tfor\
    \ (int i = 3; i * i < SZ; i++) \r\n\t\t\tif (spf[i] == i) \r\n\t\t\t\tfor (int\
    \ j = i * i; j < SZ; j += i) \r\n\t\t\t\t\tif (spf[j] == j) \r\n\t\t\t\t\t\tspf[j]\
    \ = i;\r\n\t}\r\n\r\n\tstd::vector<std::pair<int, int>> factor(int x) {\r\n\t\t\
    std::vector<std::pair<int, int>> ret;\r\n\t\twhile (x != 1) {\r\n\t\t\tif ((int)ret.size()\
    \ == 0) \r\n\t\t\t\tret.emplace_back(spf[x], 1);\r\n\t\t\telse {\r\n\t\t\t\tif\
    \ (ret.back().first == spf[x]) \r\n\t\t\t\t\tret.back().second++;\r\n\t\t\t\t\
    else \r\n\t\t\t\t\tret.emplace_back(spf[x], 1);\r\n\t\t\t}\r\n\t\t\tx /= spf[x];\r\
    \n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <int SZ> struct Sieve {\r\n\tint spf[SZ];\r\n\
    \t\r\n\tSieve() {\r\n\t\tspf[1] = 1;\r\n\t\tfor (int i = 2; i < SZ; i++) \r\n\t\
    \t\tspf[i] = i;\r\n\t\tfor (int i = 4; i < SZ; i += 2) \r\n\t\t\tspf[i] = 2;\r\
    \n\t\tfor (int i = 3; i * i < SZ; i++) \r\n\t\t\tif (spf[i] == i) \r\n\t\t\t\t\
    for (int j = i * i; j < SZ; j += i) \r\n\t\t\t\t\tif (spf[j] == j) \r\n\t\t\t\t\
    \t\tspf[j] = i;\r\n\t}\r\n\r\n\tstd::vector<std::pair<int, int>> factor(int x)\
    \ {\r\n\t\tstd::vector<std::pair<int, int>> ret;\r\n\t\twhile (x != 1) {\r\n\t\
    \t\tif ((int)ret.size() == 0) \r\n\t\t\t\tret.emplace_back(spf[x], 1);\r\n\t\t\
    \telse {\r\n\t\t\t\tif (ret.back().first == spf[x]) \r\n\t\t\t\t\tret.back().second++;\r\
    \n\t\t\t\telse \r\n\t\t\t\t\tret.emplace_back(spf[x], 1);\r\n\t\t\t}\r\n\t\t\t\
    x /= spf[x];\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/fast-factor-sieve.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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

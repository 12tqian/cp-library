---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/fast_factor_sieve.cpp\"\n#include<bits/stdc++.h>\r\
    \ntemplate <int SZ> struct Sieve {\r\n    int spf[SZ];\r\n    Sieve() {\r\n  \
    \      spf[1] = 1;\r\n        for (int i = 2; i < SZ; i++) \r\n            spf[i]\
    \ = i;\r\n        for (int i = 4; i < SZ; i += 2) \r\n            spf[i] = 2;\r\
    \n        for (int i = 3; i * i < SZ; i++) \r\n            if (spf[i] == i) \r\
    \n                for (int j = i * i; j < SZ; j += i) \r\n                   \
    \ if (spf[j] == j) \r\n                        spf[j] = i;\r\n    }\r\n    std::vector<std::pair<int,\
    \ int>> factor(int x) {\r\n        std::vector<std::pair<int, int>> ret;\r\n \
    \       while (x != 1) {\r\n            if ((int) ret.size() == 0) \r\n      \
    \          ret.emplace_back(spf[x], 1);\r\n            else {\r\n            \
    \    if (ret.back().first == spf[x]) \r\n                    ret.back().second++;\r\
    \n                else \r\n                    ret.emplace_back(spf[x], 1);\r\n\
    \            }\r\n            x /= spf[x];\r\n        }\r\n        return ret;\r\
    \n    }\r\n};\r\n\r\nint main() {\r\n    return 0;\r\n}\n"
  code: "#include<bits/stdc++.h>\r\ntemplate <int SZ> struct Sieve {\r\n    int spf[SZ];\r\
    \n    Sieve() {\r\n        spf[1] = 1;\r\n        for (int i = 2; i < SZ; i++)\
    \ \r\n            spf[i] = i;\r\n        for (int i = 4; i < SZ; i += 2) \r\n\
    \            spf[i] = 2;\r\n        for (int i = 3; i * i < SZ; i++) \r\n    \
    \        if (spf[i] == i) \r\n                for (int j = i * i; j < SZ; j +=\
    \ i) \r\n                    if (spf[j] == j) \r\n                        spf[j]\
    \ = i;\r\n    }\r\n    std::vector<std::pair<int, int>> factor(int x) {\r\n  \
    \      std::vector<std::pair<int, int>> ret;\r\n        while (x != 1) {\r\n \
    \           if ((int) ret.size() == 0) \r\n                ret.emplace_back(spf[x],\
    \ 1);\r\n            else {\r\n                if (ret.back().first == spf[x])\
    \ \r\n                    ret.back().second++;\r\n                else \r\n  \
    \                  ret.emplace_back(spf[x], 1);\r\n            }\r\n         \
    \   x /= spf[x];\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\nint\
    \ main() {\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/fast_factor_sieve.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:57:11-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/fast_factor_sieve.cpp
layout: document
redirect_from:
- /library/library/number-theory/fast_factor_sieve.cpp
- /library/library/number-theory/fast_factor_sieve.cpp.html
title: library/number-theory/fast_factor_sieve.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/fast_factor_sieve.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate <int SZ> struct Sieve {\n    int spf[SZ];\n    \n    Sieve() {\n  \
    \      spf[1] = 1;\n        for (int i = 2; i < SZ; i++) \n            spf[i]\
    \ = i;\n        for (int i = 4; i < SZ; i += 2) \n            spf[i] = 2;\n  \
    \      for (int i = 3; i * i < SZ; i++) \n            if (spf[i] == i) \n    \
    \            for (int j = i * i; j < SZ; j += i) \n                    if (spf[j]\
    \ == j) \n                        spf[j] = i;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> factor(int x) {\n        std::vector<std::pair<int, int>> ret;\n     \
    \   while (x != 1) {\n            if ((int) ret.size() == 0) \n              \
    \  ret.emplace_back(spf[x], 1);\n            else {\n                if (ret.back().first\
    \ == spf[x]) \n                    ret.back().second++;\n                else\
    \ \n                    ret.emplace_back(spf[x], 1);\n            }\n        \
    \    x /= spf[x];\n        }\n        return ret;\n    }\n};\n\nint main() {\n\
    \    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <int SZ> struct Sieve {\n    int spf[SZ];\n\
    \    \n    Sieve() {\n        spf[1] = 1;\n        for (int i = 2; i < SZ; i++)\
    \ \n            spf[i] = i;\n        for (int i = 4; i < SZ; i += 2) \n      \
    \      spf[i] = 2;\n        for (int i = 3; i * i < SZ; i++) \n            if\
    \ (spf[i] == i) \n                for (int j = i * i; j < SZ; j += i) \n     \
    \               if (spf[j] == j) \n                        spf[j] = i;\n    }\n\
    \n    std::vector<std::pair<int, int>> factor(int x) {\n        std::vector<std::pair<int,\
    \ int>> ret;\n        while (x != 1) {\n            if ((int) ret.size() == 0)\
    \ \n                ret.emplace_back(spf[x], 1);\n            else {\n       \
    \         if (ret.back().first == spf[x]) \n                    ret.back().second++;\n\
    \                else \n                    ret.emplace_back(spf[x], 1);\n   \
    \         }\n            x /= spf[x];\n        }\n        return ret;\n    }\n\
    };\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/fast_factor_sieve.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/fast_factor_sieve.cpp
layout: document
redirect_from:
- /library/library/number-theory/fast_factor_sieve.cpp
- /library/library/number-theory/fast_factor_sieve.cpp.html
title: library/number-theory/fast_factor_sieve.cpp
---

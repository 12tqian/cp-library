---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/sieve.cpp\"\n#include<bits/stdc++.h>\r\
    \ntemplate <int SZ> struct Sieve {\r\n    std::bitset<SZ> pri;\r\n    std::vector<int>\
    \ pr;\r\n    Sieve() {\r\n        pri.set();\r\n        pri[0] = pri[1] = 0;\r\
    \n        for (int i = 4; i < SZ; i += 2) {\r\n            pri[i] = 0;\r\n   \
    \     }\r\n        for (int i = 3; i * i < SZ; i += 2) {\r\n            if (pri[i])\
    \ {\r\n                for (int j = i * i; j < SZ; j += 2 * i) {\r\n         \
    \           pri[j] = 0;\r\n                }\r\n            }\r\n        }\r\n\
    \        for (int i = 0; i < SZ; i++) {\r\n            if (pri[i]) {\r\n     \
    \           pr.push_back(i);\r\n            }\r\n        }\r\n    }\r\n};\r\n\
    int main() {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\ntemplate <int SZ> struct Sieve {\r\n    std::bitset<SZ>\
    \ pri;\r\n    std::vector<int> pr;\r\n    Sieve() {\r\n        pri.set();\r\n\
    \        pri[0] = pri[1] = 0;\r\n        for (int i = 4; i < SZ; i += 2) {\r\n\
    \            pri[i] = 0;\r\n        }\r\n        for (int i = 3; i * i < SZ; i\
    \ += 2) {\r\n            if (pri[i]) {\r\n                for (int j = i * i;\
    \ j < SZ; j += 2 * i) {\r\n                    pri[j] = 0;\r\n               \
    \ }\r\n            }\r\n        }\r\n        for (int i = 0; i < SZ; i++) {\r\n\
    \            if (pri[i]) {\r\n                pr.push_back(i);\r\n           \
    \ }\r\n        }\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/sieve.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:57:26-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/sieve.cpp
layout: document
redirect_from:
- /library/library/number-theory/sieve.cpp
- /library/library/number-theory/sieve.cpp.html
title: library/number-theory/sieve.cpp
---

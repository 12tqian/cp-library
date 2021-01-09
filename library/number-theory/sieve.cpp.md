---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/sieve.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate <int SZ> struct Sieve {\n    std::bitset<SZ> pri;\n    std::vector<int>\
    \ pr;\n    \n    Sieve() {\n        pri.set();\n        pri[0] = pri[1] = 0;\n\
    \        for (int i = 4; i < SZ; i += 2) {\n            pri[i] = 0;\n        }\n\
    \        for (int i = 3; i * i < SZ; i += 2) {\n            if (pri[i]) {\n  \
    \              for (int j = i * i; j < SZ; j += 2 * i) {\n                   \
    \ pri[j] = 0;\n                }\n            }\n        }\n        for (int i\
    \ = 0; i < SZ; i++) {\n            if (pri[i]) {\n                pr.push_back(i);\n\
    \            }\n        }\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <int SZ> struct Sieve {\n    std::bitset<SZ>\
    \ pri;\n    std::vector<int> pr;\n    \n    Sieve() {\n        pri.set();\n  \
    \      pri[0] = pri[1] = 0;\n        for (int i = 4; i < SZ; i += 2) {\n     \
    \       pri[i] = 0;\n        }\n        for (int i = 3; i * i < SZ; i += 2) {\n\
    \            if (pri[i]) {\n                for (int j = i * i; j < SZ; j += 2\
    \ * i) {\n                    pri[j] = 0;\n                }\n            }\n\
    \        }\n        for (int i = 0; i < SZ; i++) {\n            if (pri[i]) {\n\
    \                pr.push_back(i);\n            }\n        }\n    }\n};\n\nint\
    \ main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/sieve.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/sieve.cpp
layout: document
redirect_from:
- /library/library/number-theory/sieve.cpp
- /library/library/number-theory/sieve.cpp.html
title: library/number-theory/sieve.cpp
---

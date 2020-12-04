---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/gosper_hack.cpp\"\n#include<bits/stdc++.h>\r\
    \nstd::string binary(unsigned long long n ) { //long long to binary string\r\n\
    \    std::string result;\r\n    do result.push_back('0' + (n & 1));\r\n    while\
    \ (n >>= 1);\r\n    reverse(result.begin(), result.end());\r\n    return result;\r\
    \n}\r\nint main() {\r\n    int n = 4;\r\n    for (int sz = 1; sz <= n; sz++) {\r\
    \n        long long c = (1 << sz) - 1;\r\n        while (c < (1 << n)) {\r\n \
    \           std::cout << binary(c) << std::endl; // do stuff to binary string\
    \ with sz 1's\r\n            long long a = c & -c;\r\n            long long b\
    \ = c + a;\r\n            c = (c ^ b) / 4 / a | b;\r\n        }\r\n    }\r\n \
    \   return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\nstd::string binary(unsigned long long n ) { //long\
    \ long to binary string\r\n    std::string result;\r\n    do result.push_back('0'\
    \ + (n & 1));\r\n    while (n >>= 1);\r\n    reverse(result.begin(), result.end());\r\
    \n    return result;\r\n}\r\nint main() {\r\n    int n = 4;\r\n    for (int sz\
    \ = 1; sz <= n; sz++) {\r\n        long long c = (1 << sz) - 1;\r\n        while\
    \ (c < (1 << n)) {\r\n            std::cout << binary(c) << std::endl; // do stuff\
    \ to binary string with sz 1's\r\n            long long a = c & -c;\r\n      \
    \      long long b = c + a;\r\n            c = (c ^ b) / 4 / a | b;\r\n      \
    \  }\r\n    }\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/gosper_hack.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:54:33-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/gosper_hack.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/gosper_hack.cpp
- /library/library/dynamic-programming/gosper_hack.cpp.html
title: library/dynamic-programming/gosper_hack.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/gosper_hack.cpp\"\n#include<bits/stdc++.h>\n\
    \nstd::string binary(unsigned long long n ) { //long long to binary string\n \
    \   std::string result;\n    do result.push_back('0' + (n & 1));\n    while (n\
    \ >>= 1);\n    reverse(result.begin(), result.end());\n    return result;\n}\n\
    \nint main() {\n    int n = 4;\n    for (int sz = 1; sz <= n; sz++) {\n      \
    \  long long c = (1 << sz) - 1;\n        while (c < (1 << n)) {\n            std::cout\
    \ << binary(c) << std::endl; // do stuff to binary string with sz 1's\n      \
    \      long long a = c & -c;\n            long long b = c + a;\n            c\
    \ = (c ^ b) / 4 / a | b;\n        }\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nstd::string binary(unsigned long long n ) { //long\
    \ long to binary string\n    std::string result;\n    do result.push_back('0'\
    \ + (n & 1));\n    while (n >>= 1);\n    reverse(result.begin(), result.end());\n\
    \    return result;\n}\n\nint main() {\n    int n = 4;\n    for (int sz = 1; sz\
    \ <= n; sz++) {\n        long long c = (1 << sz) - 1;\n        while (c < (1 <<\
    \ n)) {\n            std::cout << binary(c) << std::endl; // do stuff to binary\
    \ string with sz 1's\n            long long a = c & -c;\n            long long\
    \ b = c + a;\n            c = (c ^ b) / 4 / a | b;\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/gosper_hack.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/gosper_hack.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/gosper_hack.cpp
- /library/library/dynamic-programming/gosper_hack.cpp.html
title: library/dynamic-programming/gosper_hack.cpp
---

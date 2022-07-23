---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-gosper-hack.test.cpp
    title: verify/unit-test/unit-test-gosper-hack.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstd::string binary(unsigned long long n) { //long long to binary\
    \ string\r\n\tstd::string result;\r\n\tdo result.push_back('0' + (n & 1));\r\n\
    \twhile (n >>= 1);\r\n\treverse(result.begin(), result.end());\r\n\treturn result;\r\
    \n}\r\n\r\nstd::vector<int> gosper_generate(int n) {\r\n\tstd::vector<int> res{0};\r\
    \n\tfor (int sz = 1; sz <= n; sz++) {\r\n\t\tlong long c = (1 << sz) - 1;\r\n\t\
    \twhile (c < (1 << n)) {\r\n\t\t\tres.pb(c);\r\n\t\t\tlong long a = c & -c;\r\n\
    \t\t\tlong long b = c + a;\r\n\t\t\tc = (c ^ b) / 4 / a | b;\r\n\t\t}\r\n\t}\r\
    \n\treturn res;\r\n}\r\n"
  code: "#pragma once\r\n\r\nstd::string binary(unsigned long long n) { //long long\
    \ to binary string\r\n\tstd::string result;\r\n\tdo result.push_back('0' + (n\
    \ & 1));\r\n\twhile (n >>= 1);\r\n\treverse(result.begin(), result.end());\r\n\
    \treturn result;\r\n}\r\n\r\nstd::vector<int> gosper_generate(int n) {\r\n\tstd::vector<int>\
    \ res{0};\r\n\tfor (int sz = 1; sz <= n; sz++) {\r\n\t\tlong long c = (1 << sz)\
    \ - 1;\r\n\t\twhile (c < (1 << n)) {\r\n\t\t\tres.pb(c);\r\n\t\t\tlong long a\
    \ = c & -c;\r\n\t\t\tlong long b = c + a;\r\n\t\t\tc = (c ^ b) / 4 / a | b;\r\n\
    \t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/gosper-hack.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-gosper-hack.test.cpp
documentation_of: library/dynamic-programming/gosper-hack.hpp
layout: document
redirect_from:
- /library/library/dynamic-programming/gosper-hack.hpp
- /library/library/dynamic-programming/gosper-hack.hpp.html
title: library/dynamic-programming/gosper-hack.hpp
---

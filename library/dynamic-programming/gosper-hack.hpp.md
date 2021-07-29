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
  bundledCode: "\nstd::string binary(unsigned long long n ) { //long long to binary\
    \ string\n\tstd::string result;\n\tdo result.push_back('0' + (n & 1));\n\twhile\
    \ (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn result;\n}\n"
  code: "#pragma once\n\nstd::string binary(unsigned long long n ) { //long long to\
    \ binary string\n\tstd::string result;\n\tdo result.push_back('0' + (n & 1));\n\
    \twhile (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn result;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/gosper-hack.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:49:44-04:00'
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

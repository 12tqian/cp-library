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
    \ (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn result;\n}\n\n\
    std::vector<int> gosper_generate(int n) {\n\tstd::vector<int> res{0};\n\tfor (int\
    \ sz = 1; sz <= n; sz++) {\n\t\tlong long c = (1 << sz) - 1;\n\t\twhile (c < (1\
    \ << n)) {\n\t\t\tres.pb(c);\n\t\t\tlong long a = c & -c;\n\t\t\tlong long b =\
    \ c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n\nstd::string binary(unsigned long long n ) { //long long to\
    \ binary string\n\tstd::string result;\n\tdo result.push_back('0' + (n & 1));\n\
    \twhile (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn result;\n\
    }\n\nstd::vector<int> gosper_generate(int n) {\n\tstd::vector<int> res{0};\n\t\
    for (int sz = 1; sz <= n; sz++) {\n\t\tlong long c = (1 << sz) - 1;\n\t\twhile\
    \ (c < (1 << n)) {\n\t\t\tres.pb(c);\n\t\t\tlong long a = c & -c;\n\t\t\tlong\
    \ long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\t}\n\treturn res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/gosper-hack.hpp
  requiredBy: []
  timestamp: '2021-07-29 01:54:19-04:00'
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

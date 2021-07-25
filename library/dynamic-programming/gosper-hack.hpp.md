---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\nstd::string binary(unsigned long long n ) { //long long to binary\
    \ string\n\tstd::string result;\n\tdo result.push_back('0' + (n & 1));\n\twhile\
    \ (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn result;\n}\n\n\
    int main() {\n\tint n = 4;\n\tfor (int sz = 1; sz <= n; sz++) {\n\t\tlong long\
    \ c = (1 << sz) - 1;\n\t\twhile (c < (1 << n)) {\n\t\t\tstd::cout << binary(c)\
    \ << std::endl; // do stuff to binary string with sz 1's\n\t\t\tlong long a =\
    \ c & -c;\n\t\t\tlong long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\
    \t}\n\treturn 0;\n}\n"
  code: "#pragma once\n\nstd::string binary(unsigned long long n ) { //long long to\
    \ binary string\n\tstd::string result;\n\tdo result.push_back('0' + (n & 1));\n\
    \twhile (n >>= 1);\n\treverse(result.begin(), result.end());\n\treturn result;\n\
    }\n\nint main() {\n\tint n = 4;\n\tfor (int sz = 1; sz <= n; sz++) {\n\t\tlong\
    \ long c = (1 << sz) - 1;\n\t\twhile (c < (1 << n)) {\n\t\t\tstd::cout << binary(c)\
    \ << std::endl; // do stuff to binary string with sz 1's\n\t\t\tlong long a =\
    \ c & -c;\n\t\t\tlong long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\
    \t}\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/gosper-hack.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/gosper-hack.hpp
layout: document
redirect_from:
- /library/library/dynamic-programming/gosper-hack.hpp
- /library/library/dynamic-programming/gosper-hack.hpp.html
title: library/dynamic-programming/gosper-hack.hpp
---
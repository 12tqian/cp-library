---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/dynamic-programming/gosper-hack.hpp
    title: library/dynamic-programming/gosper-hack.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links: []
  bundledCode: "#define IGNORE \"self tested\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <iostream>\n#include <iomanip>\n#include\
    \ <list>\n#include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <vector>\n\nusing namespace std;\n\nstd::string binary(unsigned long\
    \ long n ) { //long long to binary string\n\tstd::string result;\n\tdo result.push_back('0'\
    \ + (n & 1));\n\twhile (n >>= 1);\n\treverse(result.begin(), result.end());\n\t\
    return result;\n}\n\nint main() {\n\tint n = 4;\n\tfor (int sz = 1; sz <= n; sz++)\
    \ {\n\t\tlong long c = (1 << sz) - 1;\n\t\twhile (c < (1 << n)) {\n\t\t\tstd::cout\
    \ << binary(c) << std::endl; // do stuff to binary string with sz 1's\n\t\t\t\
    long long a = c & -c;\n\t\t\tlong long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a |\
    \ b;\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define IGNORE \"self tested\"\n\n#include \"../../library/contest/template-minimal.hpp\"\
    \n#include \"../../library/dynamic-programming/gosper-hack.hpp\"\n\nint main()\
    \ {\n\tint n = 4;\n\tfor (int sz = 1; sz <= n; sz++) {\n\t\tlong long c = (1 <<\
    \ sz) - 1;\n\t\twhile (c < (1 << n)) {\n\t\t\tstd::cout << binary(c) << std::endl;\
    \ // do stuff to binary string with sz 1's\n\t\t\tlong long a = c & -c;\n\t\t\t\
    long long b = c + a;\n\t\t\tc = (c ^ b) / 4 / a | b;\n\t\t}\n\t}\n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/gosper-hack.hpp
  isVerificationFile: true
  path: verify/unit-test/unit-test-gosper-hack.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:55:20-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit-test/unit-test-gosper-hack.test.cpp
layout: document
redirect_from:
- /verify/verify/unit-test/unit-test-gosper-hack.test.cpp
- /verify/verify/unit-test/unit-test-gosper-hack.test.cpp.html
title: verify/unit-test/unit-test-gosper-hack.test.cpp
---
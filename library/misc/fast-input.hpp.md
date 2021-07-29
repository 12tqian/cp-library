---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1553G.test.cpp
    title: verify/codeforces/codeforces-1553G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ninline char gc() { // like getchar()\n\tstatic char buf[1 << 16];\n\
    \tstatic size_t bc, be;\n\tif (bc >= be) {\n\t\tbuf[0] = 0, bc = 0;\n\t\tbe =\
    \ fread(buf, 1, sizeof(buf), stdin);\n\t}\n\treturn buf[bc++]; // returns 0 on\
    \ EOF\n}\n\nint read_int() {\n\tint a, c;\n\twhile ((a = gc()) < 40);\n\tif (a\
    \ == '-') return -read_int();\n\twhile ((c = gc()) >= 48) a = a * 10 + c - 480;\n\
    \treturn a - 48;\n}\n"
  code: "#pragma once\n\ninline char gc() { // like getchar()\n\tstatic char buf[1\
    \ << 16];\n\tstatic size_t bc, be;\n\tif (bc >= be) {\n\t\tbuf[0] = 0, bc = 0;\n\
    \t\tbe = fread(buf, 1, sizeof(buf), stdin);\n\t}\n\treturn buf[bc++]; // returns\
    \ 0 on EOF\n}\n\nint read_int() {\n\tint a, c;\n\twhile ((a = gc()) < 40);\n\t\
    if (a == '-') return -read_int();\n\twhile ((c = gc()) >= 48) a = a * 10 + c -\
    \ 480;\n\treturn a - 48;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast-input.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1553G.test.cpp
documentation_of: library/misc/fast-input.hpp
layout: document
redirect_from:
- /library/library/misc/fast-input.hpp
- /library/library/misc/fast-input.hpp.html
title: library/misc/fast-input.hpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/codeforces/codeforces-1553G.test.cpp
    title: verify/codeforces/codeforces-1553G.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ninline char gc() { // like getchar()\r\n\tstatic char buf[1 <<\
    \ 16];\r\n\tstatic size_t bc, be;\r\n\tif (bc >= be) {\r\n\t\tbuf[0] = 0, bc =\
    \ 0;\r\n\t\tbe = fread(buf, 1, sizeof(buf), stdin);\r\n\t}\r\n\treturn buf[bc++];\
    \ // returns 0 on EOF\r\n}\r\n\r\nint read_int() {\r\n\tint a, c;\r\n\twhile ((a\
    \ = gc()) < 40);\r\n\tif (a == '-') return -read_int();\r\n\twhile ((c = gc())\
    \ >= 48) a = a * 10 + c - 480;\r\n\treturn a - 48;\r\n}\n"
  code: "#pragma once\r\n\r\ninline char gc() { // like getchar()\r\n\tstatic char\
    \ buf[1 << 16];\r\n\tstatic size_t bc, be;\r\n\tif (bc >= be) {\r\n\t\tbuf[0]\
    \ = 0, bc = 0;\r\n\t\tbe = fread(buf, 1, sizeof(buf), stdin);\r\n\t}\r\n\treturn\
    \ buf[bc++]; // returns 0 on EOF\r\n}\r\n\r\nint read_int() {\r\n\tint a, c;\r\
    \n\twhile ((a = gc()) < 40);\r\n\tif (a == '-') return -read_int();\r\n\twhile\
    \ ((c = gc()) >= 48) a = a * 10 + c - 480;\r\n\treturn a - 48;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast-input.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/codeforces/codeforces-1553G.test.cpp
documentation_of: library/misc/fast-input.hpp
layout: document
redirect_from:
- /library/library/misc/fast-input.hpp
- /library/library/misc/fast-input.hpp.html
title: library/misc/fast-input.hpp
---

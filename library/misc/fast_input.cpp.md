---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/misc/fast_input.cpp\"\n#include <bits/stdc++.h>\n\
    \ninline char gc() { // like getchar()\n\tstatic char buf[1 << 16];\n\tstatic\
    \ size_t bc, be;\n\tif (bc >= be) {\n\t\tbuf[0] = 0, bc = 0;\n\t\tbe = fread(buf,\
    \ 1, sizeof(buf), stdin);\n\t}\n\treturn buf[bc++]; // returns 0 on EOF\n}\n\n\
    int read_int() {\n\tint a, c;\n\twhile ((a = gc()) < 40);\n\tif (a == '-') return\
    \ -read_int();\n\twhile ((c = gc()) >= 48) a = a * 10 + c - 480;\n\treturn a -\
    \ 48;\n}\n"
  code: "#include <bits/stdc++.h>\n\ninline char gc() { // like getchar()\n\tstatic\
    \ char buf[1 << 16];\n\tstatic size_t bc, be;\n\tif (bc >= be) {\n\t\tbuf[0] =\
    \ 0, bc = 0;\n\t\tbe = fread(buf, 1, sizeof(buf), stdin);\n\t}\n\treturn buf[bc++];\
    \ // returns 0 on EOF\n}\n\nint read_int() {\n\tint a, c;\n\twhile ((a = gc())\
    \ < 40);\n\tif (a == '-') return -read_int();\n\twhile ((c = gc()) >= 48) a =\
    \ a * 10 + c - 480;\n\treturn a - 48;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast_input.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/fast_input.cpp
layout: document
redirect_from:
- /library/library/misc/fast_input.cpp
- /library/library/misc/fast_input.cpp.html
title: library/misc/fast_input.cpp
---

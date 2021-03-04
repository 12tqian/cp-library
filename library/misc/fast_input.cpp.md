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
    \ninline char gc() { // like getchar()\n    static char buf[1 << 16];\n    static\
    \ size_t bc, be;\n    if (bc >= be) {\n        buf[0] = 0, bc = 0;\n        be\
    \ = fread(buf, 1, sizeof(buf), stdin);\n    }\n    return buf[bc++]; // returns\
    \ 0 on EOF\n}\n\nint read_int() {\n    int a, c;\n    while ((a = gc()) < 40);\n\
    \    if (a == '-') return -read_int();\n    while ((c = gc()) >= 48) a = a * 10\
    \ + c - 480;\n    return a - 48;\n}\n"
  code: "#include <bits/stdc++.h>\n\ninline char gc() { // like getchar()\n    static\
    \ char buf[1 << 16];\n    static size_t bc, be;\n    if (bc >= be) {\n       \
    \ buf[0] = 0, bc = 0;\n        be = fread(buf, 1, sizeof(buf), stdin);\n    }\n\
    \    return buf[bc++]; // returns 0 on EOF\n}\n\nint read_int() {\n    int a,\
    \ c;\n    while ((a = gc()) < 40);\n    if (a == '-') return -read_int();\n  \
    \  while ((c = gc()) >= 48) a = a * 10 + c - 480;\n    return a - 48;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/fast_input.cpp
  requiredBy: []
  timestamp: '2021-03-04 16:44:44-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/fast_input.cpp
layout: document
redirect_from:
- /library/library/misc/fast_input.cpp
- /library/library/misc/fast_input.cpp.html
title: library/misc/fast_input.cpp
---

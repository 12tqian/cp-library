---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/mod_operations.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace ModOperations {\n\nconst int MOD = 1e9 + 7;\n\nint mpow(long long\
    \ b, long long e) {\n\tlong long r = 1;\n\twhile (e) {\n\t\tif (e & 1) {\n\t\t\
    \tr *= b; \n\t\t\tr %= MOD;\n\t\t}\n\t\tb *= b; \n\t\tb %= MOD;\n\t\te >>= 1;\n\
    \t}\n\treturn r;\n}\n\nint minv(int a) { assert(a); return mpow(a, MOD - 2); }\n\
    int add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }\nint sub(int\
    \ a, int b) { a -= b; if (a < 0) a += MOD; return a; }\nint mul(int a, int b)\
    \ { return 1LL * a * b % MOD; }\nint divi(int a, int b) { return mul(a, minv(b));\
    \ }\nint neg(int a) { return a == 0 ? 0 : MOD - a; }\nint mod(long long v) { \n\
    \tv = int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v += MOD; return v;\
    \ }\n\t\nint madd(int &a, int b) { return a = add(a, b); }\nint msub(int &a, int\
    \ b) { return a = sub(a, b); }\nint mmul(int &a, int b) { return a = mul(a, b);\
    \ }\nint mdivi(int &a, int b) { return a = divi(a, b); }\n\n} // ModOperations\n\
    \n"
  code: "#include <bits/stdc++.h>\n\nnamespace ModOperations {\n\nconst int MOD =\
    \ 1e9 + 7;\n\nint mpow(long long b, long long e) {\n\tlong long r = 1;\n\twhile\
    \ (e) {\n\t\tif (e & 1) {\n\t\t\tr *= b; \n\t\t\tr %= MOD;\n\t\t}\n\t\tb *= b;\
    \ \n\t\tb %= MOD;\n\t\te >>= 1;\n\t}\n\treturn r;\n}\n\nint minv(int a) { assert(a);\
    \ return mpow(a, MOD - 2); }\nint add(int a, int b) { a += b; if (a >= MOD) a\
    \ -= MOD; return a; }\nint sub(int a, int b) { a -= b; if (a < 0) a += MOD; return\
    \ a; }\nint mul(int a, int b) { return 1LL * a * b % MOD; }\nint divi(int a, int\
    \ b) { return mul(a, minv(b)); }\nint neg(int a) { return a == 0 ? 0 : MOD - a;\
    \ }\nint mod(long long v) { \n\tv = int((-MOD < v && v < MOD) ? v : v % MOD);\
    \ if (v < 0) v += MOD; return v; }\n\t\nint madd(int &a, int b) { return a = add(a,\
    \ b); }\nint msub(int &a, int b) { return a = sub(a, b); }\nint mmul(int &a, int\
    \ b) { return a = mul(a, b); }\nint mdivi(int &a, int b) { return a = divi(a,\
    \ b); }\n\n} // ModOperations\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod_operations.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/mod_operations.cpp
layout: document
redirect_from:
- /library/library/numerical/mod_operations.cpp
- /library/library/numerical/mod_operations.cpp.html
title: library/numerical/mod_operations.cpp
---
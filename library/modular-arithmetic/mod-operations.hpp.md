---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1299D.test.cpp
    title: verify/codeforces/codeforces-1299D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nnamespace ModOperations {\n\nconst int MOD = 1e9 + 7;\n\nint mpow(long\
    \ long b, long long e) {\n\tlong long r = 1;\n\twhile (e) {\n\t\tif (e & 1) {\n\
    \t\t\tr *= b; \n\t\t\tr %= MOD;\n\t\t}\n\t\tb *= b; \n\t\tb %= MOD;\n\t\te >>=\
    \ 1;\n\t}\n\treturn r;\n}\n\nint minv(int a) { assert(a); return mpow(a, MOD -\
    \ 2); }\nint add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }\n\
    int sub(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }\nint mul(int\
    \ a, int b) { return 1LL * a * b % MOD; }\nint divi(int a, int b) { return mul(a,\
    \ minv(b)); }\nint neg(int a) { return a == 0 ? 0 : MOD - a; }\nint mod(long long\
    \ v) { \n\tv = int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v += MOD;\
    \ return v; }\n\t\nint madd(int &a, int b) { return a = add(a, b); }\nint msub(int\
    \ &a, int b) { return a = sub(a, b); }\nint mmul(int &a, int b) { return a = mul(a,\
    \ b); }\nint mdivi(int &a, int b) { return a = divi(a, b); }\n\n} // ModOperations\n"
  code: "#pragma once\n\nnamespace ModOperations {\n\nconst int MOD = 1e9 + 7;\n\n\
    int mpow(long long b, long long e) {\n\tlong long r = 1;\n\twhile (e) {\n\t\t\
    if (e & 1) {\n\t\t\tr *= b; \n\t\t\tr %= MOD;\n\t\t}\n\t\tb *= b; \n\t\tb %= MOD;\n\
    \t\te >>= 1;\n\t}\n\treturn r;\n}\n\nint minv(int a) { assert(a); return mpow(a,\
    \ MOD - 2); }\nint add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return\
    \ a; }\nint sub(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }\nint\
    \ mul(int a, int b) { return 1LL * a * b % MOD; }\nint divi(int a, int b) { return\
    \ mul(a, minv(b)); }\nint neg(int a) { return a == 0 ? 0 : MOD - a; }\nint mod(long\
    \ long v) { \n\tv = int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v +=\
    \ MOD; return v; }\n\t\nint madd(int &a, int b) { return a = add(a, b); }\nint\
    \ msub(int &a, int b) { return a = sub(a, b); }\nint mmul(int &a, int b) { return\
    \ a = mul(a, b); }\nint mdivi(int &a, int b) { return a = divi(a, b); }\n\n} //\
    \ ModOperations"
  dependsOn: []
  isVerificationFile: false
  path: library/modular-arithmetic/mod-operations.hpp
  requiredBy: []
  timestamp: '2021-07-31 14:30:12-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1299D.test.cpp
documentation_of: library/modular-arithmetic/mod-operations.hpp
layout: document
redirect_from:
- /library/library/modular-arithmetic/mod-operations.hpp
- /library/library/modular-arithmetic/mod-operations.hpp.html
title: library/modular-arithmetic/mod-operations.hpp
---

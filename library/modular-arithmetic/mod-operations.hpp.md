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
  bundledCode: "\r\nnamespace ModOperations {\r\n\r\nconst int MOD = 1e9 + 7;\r\n\r\
    \nint mpow(long long b, long long e) {\r\n\tlong long r = 1;\r\n\twhile (e) {\r\
    \n\t\tif (e & 1) {\r\n\t\t\tr *= b; \r\n\t\t\tr %= MOD;\r\n\t\t}\r\n\t\tb *= b;\
    \ \r\n\t\tb %= MOD;\r\n\t\te >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\nint minv(int\
    \ a) { assert(a); return mpow(a, MOD - 2); }\r\nint add(int a, int b) { a += b;\
    \ if (a >= MOD) a -= MOD; return a; }\r\nint sub(int a, int b) { a -= b; if (a\
    \ < 0) a += MOD; return a; }\r\nint mul(int a, int b) { return 1LL * a * b % MOD;\
    \ }\r\nint divi(int a, int b) { return mul(a, minv(b)); }\r\nint neg(int a) {\
    \ return a == 0 ? 0 : MOD - a; }\r\nint mod(long long v) { \r\n\tv = int((-MOD\
    \ < v && v < MOD) ? v : v % MOD); if (v < 0) v += MOD; return v; }\r\n\t\r\nint\
    \ madd(int& a, int b) { return a = add(a, b); }\r\nint msub(int& a, int b) { return\
    \ a = sub(a, b); }\r\nint mmul(int& a, int b) { return a = mul(a, b); }\r\nint\
    \ mdivi(int& a, int b) { return a = divi(a, b); }\r\n\r\n} // ModOperations\n"
  code: "#pragma once\r\n\r\nnamespace ModOperations {\r\n\r\nconst int MOD = 1e9\
    \ + 7;\r\n\r\nint mpow(long long b, long long e) {\r\n\tlong long r = 1;\r\n\t\
    while (e) {\r\n\t\tif (e & 1) {\r\n\t\t\tr *= b; \r\n\t\t\tr %= MOD;\r\n\t\t}\r\
    \n\t\tb *= b; \r\n\t\tb %= MOD;\r\n\t\te >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\
    \r\nint minv(int a) { assert(a); return mpow(a, MOD - 2); }\r\nint add(int a,\
    \ int b) { a += b; if (a >= MOD) a -= MOD; return a; }\r\nint sub(int a, int b)\
    \ { a -= b; if (a < 0) a += MOD; return a; }\r\nint mul(int a, int b) { return\
    \ 1LL * a * b % MOD; }\r\nint divi(int a, int b) { return mul(a, minv(b)); }\r\
    \nint neg(int a) { return a == 0 ? 0 : MOD - a; }\r\nint mod(long long v) { \r\
    \n\tv = int((-MOD < v && v < MOD) ? v : v % MOD); if (v < 0) v += MOD; return\
    \ v; }\r\n\t\r\nint madd(int& a, int b) { return a = add(a, b); }\r\nint msub(int&\
    \ a, int b) { return a = sub(a, b); }\r\nint mmul(int& a, int b) { return a =\
    \ mul(a, b); }\r\nint mdivi(int& a, int b) { return a = divi(a, b); }\r\n\r\n\
    } // ModOperations"
  dependsOn: []
  isVerificationFile: false
  path: library/modular-arithmetic/mod-operations.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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

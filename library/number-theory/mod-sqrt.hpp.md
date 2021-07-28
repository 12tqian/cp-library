---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-sqrt_mod.test.cpp
    title: verify/yosupo/yosupo-sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nunsigned xrand() {\n\tstatic unsigned x = 314159265, y = 358979323,\
    \ z = 846264338, w = 327950288;\n\tunsigned t = x ^ x << 11; x = y; y = z; z =\
    \ w; return w = w ^ w >> 19 ^ t ^ t >> 8;\n}\n\nlong long mod_inverse(long long\
    \ a, long long m) {\n\tlong long b = m, x = 1, y = 0, t;\n\tfor (; ; ) {\n\t\t\
    t = a / b, a -= t * b;\n\t\tif (a == 0) {\n\t\t\tassert(b == 1 || b == -1);\n\t\
    \t\tif ( b== -1) y = -y;\n\t\t\treturn (y < 0) ? (y + m) : y;\n\t\t}\n\t\tx -=\
    \ t * y;\n\t\tt = b / a, b -= t * a;\n\t\tif (b == 0) {\n\t\t\tassert (a == 1\
    \ || a == -1);\n\t\t\tif (a == -1) x = -x;\n\t\t\treturn (x < 0) ? (x + m) : x;\n\
    \t\t}\n\t\ty -= t * x;\n\t}\n}\n\nint jacobi(long long a, long long m) {\n\tint\
    \ s = 1;\n\tif (a < 0) a = a % m + m;\n\tfor (; m > 1; ) {\n\t\ta %= m;\n\t\t\
    if (a == 0) return 0;\n\t\tconst int r = __builtin_ctz(a);\n\t\tif ((r & 1) &&\
    \ ((m + 2) & 4)) s = -s;\n\t\ta >>= r;\n\t\tif (a & m & 2) s = -s;\n\t\tstd::swap(a,\
    \ m);\n\t}\n\treturn s;\n}\n\nstd::vector<long long> mod_sqrt(long long a, long\
    \ long p) {\n\tif (p == 2) return {a & 1};\n\tconst int j = jacobi(a, p);\n\t\
    if (j == 0) return {0};\n\tif (j == -1) return {};\n\tlong long b, d;\n\tfor (;\
    \ ; ) {\n\t\tb = xrand() % p;\n\t\td = (b * b - a) % p;\n\t\tif (d < 0) d += p;\n\
    \t\tif (jacobi(d, p) == -1) break;\n\t}\n\tlong long f0 = b, f1 = 1, g0 = 1, g1\
    \ = 0, tmp;\n\tfor (long long e = (p + 1) >> 1; e; e >>= 1) {\n\t\tif (e & 1)\
    \ {\n\t\t\ttmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;\n\t\t\tg1 = (g0 * f1 + g1\
    \ * f0) % p;\n\t\t\tg0 = tmp;\n\t\t}\n\t\ttmp = (f0 * f0 + d * ((f1 * f1) % p))\
    \ % p;\n\t\tf1 = (2 * f0 * f1) % p;\n\t\tf0 = tmp;\n\t}\n\treturn (g0 < p - g0)\
    \ ? std::vector<long long>{g0, p - g0} : std::vector<long long>{p - g0, g0};\n\
    }\n"
  code: "#pragma once\n\nunsigned xrand() {\n\tstatic unsigned x = 314159265, y =\
    \ 358979323, z = 846264338, w = 327950288;\n\tunsigned t = x ^ x << 11; x = y;\
    \ y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;\n}\n\nlong long mod_inverse(long\
    \ long a, long long m) {\n\tlong long b = m, x = 1, y = 0, t;\n\tfor (; ; ) {\n\
    \t\tt = a / b, a -= t * b;\n\t\tif (a == 0) {\n\t\t\tassert(b == 1 || b == -1);\n\
    \t\t\tif ( b== -1) y = -y;\n\t\t\treturn (y < 0) ? (y + m) : y;\n\t\t}\n\t\tx\
    \ -= t * y;\n\t\tt = b / a, b -= t * a;\n\t\tif (b == 0) {\n\t\t\tassert (a ==\
    \ 1 || a == -1);\n\t\t\tif (a == -1) x = -x;\n\t\t\treturn (x < 0) ? (x + m) :\
    \ x;\n\t\t}\n\t\ty -= t * x;\n\t}\n}\n\nint jacobi(long long a, long long m) {\n\
    \tint s = 1;\n\tif (a < 0) a = a % m + m;\n\tfor (; m > 1; ) {\n\t\ta %= m;\n\t\
    \tif (a == 0) return 0;\n\t\tconst int r = __builtin_ctz(a);\n\t\tif ((r & 1)\
    \ && ((m + 2) & 4)) s = -s;\n\t\ta >>= r;\n\t\tif (a & m & 2) s = -s;\n\t\tstd::swap(a,\
    \ m);\n\t}\n\treturn s;\n}\n\nstd::vector<long long> mod_sqrt(long long a, long\
    \ long p) {\n\tif (p == 2) return {a & 1};\n\tconst int j = jacobi(a, p);\n\t\
    if (j == 0) return {0};\n\tif (j == -1) return {};\n\tlong long b, d;\n\tfor (;\
    \ ; ) {\n\t\tb = xrand() % p;\n\t\td = (b * b - a) % p;\n\t\tif (d < 0) d += p;\n\
    \t\tif (jacobi(d, p) == -1) break;\n\t}\n\tlong long f0 = b, f1 = 1, g0 = 1, g1\
    \ = 0, tmp;\n\tfor (long long e = (p + 1) >> 1; e; e >>= 1) {\n\t\tif (e & 1)\
    \ {\n\t\t\ttmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;\n\t\t\tg1 = (g0 * f1 + g1\
    \ * f0) % p;\n\t\t\tg0 = tmp;\n\t\t}\n\t\ttmp = (f0 * f0 + d * ((f1 * f1) % p))\
    \ % p;\n\t\tf1 = (2 * f0 * f1) % p;\n\t\tf0 = tmp;\n\t}\n\treturn (g0 < p - g0)\
    \ ? std::vector<long long>{g0, p - g0} : std::vector<long long>{p - g0, g0};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/mod-sqrt.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-sqrt_mod.test.cpp
documentation_of: library/number-theory/mod-sqrt.hpp
layout: document
redirect_from:
- /library/library/number-theory/mod-sqrt.hpp
- /library/library/number-theory/mod-sqrt.hpp.html
title: library/number-theory/mod-sqrt.hpp
---
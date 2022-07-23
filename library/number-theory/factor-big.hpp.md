---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-factorize.test.cpp
    title: verify/yosupo/yosupo-factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\nnamespace FactorBig {\r\n\r\nlong long gcd(long long _a, long\
    \ long _b) {\r\n\tunsigned long long a = abs(_a), b = abs(_b);\r\n\tif (a == 0)\
    \ return b;\r\n\tif (b == 0) return a;\r\n\tauto bsf = [](unsigned long long x)\
    \ -> int {\r\n\t\treturn __builtin_ctzll(x);\r\n\t};\r\n\tint shift = bsf(a |\
    \ b);\r\n\ta >>= bsf(a);\r\n\tdo {\r\n\t\tb >>= bsf(b);\r\n\t\tif (a > b) \r\n\
    \t\t\tstd::swap(a, b);\r\n\t\tb -= a;\r\n\t} while (b);\r\n\treturn (a << shift);\r\
    \n}\r\n\r\ntemplate <class T, class U> T pow_mod(T x, U n, T md) {\r\n\tT r =\
    \ 1 % md;\r\n\tx %= md;\r\n\twhile (n) {\r\n\t\tif (n & 1) r = (r * x) % md;\r\
    \n\t\tx = (x * x) % md;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\nbool\
    \ is_prime(long long n) {\r\n\tif (n <= 1) return false;\r\n\tif (n == 2) return\
    \ true;\r\n\tif (n % 2 == 0) return false;\r\n\tlong long d = n - 1;\r\n\twhile\
    \ (d % 2 == 0) d /= 2;\r\n\tfor (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37}) {\r\n\t\tif (n <= a) break;\r\n\t\tlong long t = d;\r\n\t\tlong\
    \ long y = pow_mod<__int128_t>(a, t, n);  // over\r\n\t\twhile (t != n - 1 &&\
    \ y != 1 && y != n - 1) {\r\n\t\t\ty = __int128_t(y) * y % n;  // flow\r\n\t\t\
    \tt <<= 1;\r\n\t\t}\r\n\t\tif (y != n - 1 && t % 2 == 0) {\r\n\t\t\treturn false;\r\
    \n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\r\nlong long pollard_single(long long\
    \ n) {\r\n\tauto f = [&](long long x) { return (__int128_t(x) * x + 1) % n; };\r\
    \n\tif (is_prime(n)) return n;\r\n\tif (n % 2 == 0) return 2;\r\n\tlong long st\
    \ = 0;\r\n\twhile (true) {\r\n\t\tst++;\r\n\t\tlong long x = st, y = f(x);\r\n\
    \t\twhile (true) {\r\n\t\t\tlong long p = gcd((y - x + n), n);\r\n\t\t\tif (p\
    \ == 0 || p == n) break;\r\n\t\t\tif (p != 1) return p;\r\n\t\t\tx = f(x);\r\n\
    \t\t\ty = f(f(y));\r\n\t\t}\r\n\t}\r\n}\r\n\r\nstd::vector<long long> pollard(long\
    \ long n) {\r\n\tif (n == 1) return {};\r\n\tlong long x = pollard_single(n);\r\
    \n\tif (x == n) return {x};\r\n\tstd::vector<long long> le = pollard(x);\r\n\t\
    std::vector<long long> ri = pollard(n / x);\r\n\tle.insert(le.end(), ri.begin(),\
    \ ri.end());\r\n\treturn le;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\nnamespace FactorBig {\r\n\r\nlong long gcd(long long\
    \ _a, long long _b) {\r\n\tunsigned long long a = abs(_a), b = abs(_b);\r\n\t\
    if (a == 0) return b;\r\n\tif (b == 0) return a;\r\n\tauto bsf = [](unsigned long\
    \ long x) -> int {\r\n\t\treturn __builtin_ctzll(x);\r\n\t};\r\n\tint shift =\
    \ bsf(a | b);\r\n\ta >>= bsf(a);\r\n\tdo {\r\n\t\tb >>= bsf(b);\r\n\t\tif (a >\
    \ b) \r\n\t\t\tstd::swap(a, b);\r\n\t\tb -= a;\r\n\t} while (b);\r\n\treturn (a\
    \ << shift);\r\n}\r\n\r\ntemplate <class T, class U> T pow_mod(T x, U n, T md)\
    \ {\r\n\tT r = 1 % md;\r\n\tx %= md;\r\n\twhile (n) {\r\n\t\tif (n & 1) r = (r\
    \ * x) % md;\r\n\t\tx = (x * x) % md;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n\
    }\r\n\r\nbool is_prime(long long n) {\r\n\tif (n <= 1) return false;\r\n\tif (n\
    \ == 2) return true;\r\n\tif (n % 2 == 0) return false;\r\n\tlong long d = n -\
    \ 1;\r\n\twhile (d % 2 == 0) d /= 2;\r\n\tfor (long long a : {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37}) {\r\n\t\tif (n <= a) break;\r\n\t\tlong long t\
    \ = d;\r\n\t\tlong long y = pow_mod<__int128_t>(a, t, n);  // over\r\n\t\twhile\
    \ (t != n - 1 && y != 1 && y != n - 1) {\r\n\t\t\ty = __int128_t(y) * y % n; \
    \ // flow\r\n\t\t\tt <<= 1;\r\n\t\t}\r\n\t\tif (y != n - 1 && t % 2 == 0) {\r\n\
    \t\t\treturn false;\r\n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\r\nlong long pollard_single(long\
    \ long n) {\r\n\tauto f = [&](long long x) { return (__int128_t(x) * x + 1) %\
    \ n; };\r\n\tif (is_prime(n)) return n;\r\n\tif (n % 2 == 0) return 2;\r\n\tlong\
    \ long st = 0;\r\n\twhile (true) {\r\n\t\tst++;\r\n\t\tlong long x = st, y = f(x);\r\
    \n\t\twhile (true) {\r\n\t\t\tlong long p = gcd((y - x + n), n);\r\n\t\t\tif (p\
    \ == 0 || p == n) break;\r\n\t\t\tif (p != 1) return p;\r\n\t\t\tx = f(x);\r\n\
    \t\t\ty = f(f(y));\r\n\t\t}\r\n\t}\r\n}\r\n\r\nstd::vector<long long> pollard(long\
    \ long n) {\r\n\tif (n == 1) return {};\r\n\tlong long x = pollard_single(n);\r\
    \n\tif (x == n) return {x};\r\n\tstd::vector<long long> le = pollard(x);\r\n\t\
    std::vector<long long> ri = pollard(n / x);\r\n\tle.insert(le.end(), ri.begin(),\
    \ ri.end());\r\n\treturn le;\r\n}\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/factor-big.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-factorize.test.cpp
documentation_of: library/number-theory/factor-big.hpp
layout: document
redirect_from:
- /library/library/number-theory/factor-big.hpp
- /library/library/number-theory/factor-big.hpp.html
title: library/number-theory/factor-big.hpp
---

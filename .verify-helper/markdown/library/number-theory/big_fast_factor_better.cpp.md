---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/big_fast_factor_better.cpp\"\n#include<bits/stdc++.h>\r\
    \n\r\nnamespace FactorBig {\r\n\r\nlong long gcd(long long _a, long long _b) {\r\
    \n    unsigned long long a = abs(_a), b = abs(_b);\r\n    if (a == 0) return b;\r\
    \n    if (b == 0) return a;\r\n    auto bsf = [](unsigned long long x) -> int\
    \ {\r\n        return __builtin_ctzll(x);\r\n    };\r\n    int shift = bsf(a |\
    \ b);\r\n    a >>= bsf(a);\r\n    do {\r\n        b >>= bsf(b);\r\n        if\
    \ (a > b) \r\n            std::swap(a, b);\r\n        b -= a;\r\n    } while (b);\r\
    \n    return (a << shift);\r\n}\r\n\r\ntemplate <class T, class U> T pow_mod(T\
    \ x, U n, T md) {\r\n    T r = 1 % md;\r\n    x %= md;\r\n    while (n) {\r\n\
    \        if (n & 1) r = (r * x) % md;\r\n        x = (x * x) % md;\r\n       \
    \ n >>= 1;\r\n    }\r\n    return r;\r\n}\r\n\r\nbool is_prime(long long n) {\r\
    \n    if (n <= 1) return false;\r\n    if (n == 2) return true;\r\n    if (n %\
    \ 2 == 0) return false;\r\n    long long d = n - 1;\r\n    while (d % 2 == 0)\
    \ d /= 2;\r\n    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})\
    \ {\r\n        if (n <= a) break;\r\n        long long t = d;\r\n        long\
    \ long y = pow_mod<__int128_t>(a, t, n);  // over\r\n        while (t != n - 1\
    \ && y != 1 && y != n - 1) {\r\n            y = __int128_t(y) * y % n;  // flow\r\
    \n            t <<= 1;\r\n        }\r\n        if (y != n - 1 && t % 2 == 0) {\r\
    \n            return false;\r\n        }\r\n    }\r\n    return true;\r\n}\r\n\
    \r\nlong long pollard_single(long long n) {\r\n    auto f = [&](long long x) {\
    \ return (__int128_t(x) * x + 1) % n; };\r\n    if (is_prime(n)) return n;\r\n\
    \    if (n % 2 == 0) return 2;\r\n    long long st = 0;\r\n    while (true) {\r\
    \n        st++;\r\n        long long x = st, y = f(x);\r\n        while (true)\
    \ {\r\n            long long p = gcd((y - x + n), n);\r\n            if (p ==\
    \ 0 || p == n) break;\r\n            if (p != 1) return p;\r\n            x =\
    \ f(x);\r\n            y = f(f(y));\r\n        }\r\n    }\r\n}\r\n\r\nstd::vector<long\
    \ long> pollard(long long n) {\r\n    if (n == 1) return {};\r\n    long long\
    \ x = pollard_single(n);\r\n    if (x == n) return {x};\r\n    std::vector<long\
    \ long> le = pollard(x);\r\n    std::vector<long long> ri = pollard(n / x);\r\n\
    \    le.insert(le.end(), ri.begin(), ri.end());\r\n    return le;\r\n}\r\n\r\n\
    }\r\n\r\nint main() {\r\n    using namespace std;\r\n    using namespace FactorBig;\r\
    \n    int q;\r\n    scanf(\"%d\", &q);\r\n    map<long long, vector<long long>>\
    \ cache;\r\n    for (int i = 0; i < q; i++) {\r\n        long long a;\r\n    \
    \    scanf(\"%lld\", &a);\r\n        if (!cache.count(a)) {\r\n            auto\
    \ v = pollard(a);\r\n            sort(v.begin(), v.end());\r\n            cache[a]\
    \ = v;\r\n        }\r\n        auto v = cache[a];\r\n        printf(\"%d\", int(v.size()));\r\
    \n        for (auto d: v) printf(\" %lld\", d);\r\n        printf(\"\\n\");\r\n\
    \    }\r\n    return 0;\r\n}\n"
  code: "#include<bits/stdc++.h>\r\n\r\nnamespace FactorBig {\r\n\r\nlong long gcd(long\
    \ long _a, long long _b) {\r\n    unsigned long long a = abs(_a), b = abs(_b);\r\
    \n    if (a == 0) return b;\r\n    if (b == 0) return a;\r\n    auto bsf = [](unsigned\
    \ long long x) -> int {\r\n        return __builtin_ctzll(x);\r\n    };\r\n  \
    \  int shift = bsf(a | b);\r\n    a >>= bsf(a);\r\n    do {\r\n        b >>= bsf(b);\r\
    \n        if (a > b) \r\n            std::swap(a, b);\r\n        b -= a;\r\n \
    \   } while (b);\r\n    return (a << shift);\r\n}\r\n\r\ntemplate <class T, class\
    \ U> T pow_mod(T x, U n, T md) {\r\n    T r = 1 % md;\r\n    x %= md;\r\n    while\
    \ (n) {\r\n        if (n & 1) r = (r * x) % md;\r\n        x = (x * x) % md;\r\
    \n        n >>= 1;\r\n    }\r\n    return r;\r\n}\r\n\r\nbool is_prime(long long\
    \ n) {\r\n    if (n <= 1) return false;\r\n    if (n == 2) return true;\r\n  \
    \  if (n % 2 == 0) return false;\r\n    long long d = n - 1;\r\n    while (d %\
    \ 2 == 0) d /= 2;\r\n    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,\
    \ 31, 37}) {\r\n        if (n <= a) break;\r\n        long long t = d;\r\n   \
    \     long long y = pow_mod<__int128_t>(a, t, n);  // over\r\n        while (t\
    \ != n - 1 && y != 1 && y != n - 1) {\r\n            y = __int128_t(y) * y % n;\
    \  // flow\r\n            t <<= 1;\r\n        }\r\n        if (y != n - 1 && t\
    \ % 2 == 0) {\r\n            return false;\r\n        }\r\n    }\r\n    return\
    \ true;\r\n}\r\n\r\nlong long pollard_single(long long n) {\r\n    auto f = [&](long\
    \ long x) { return (__int128_t(x) * x + 1) % n; };\r\n    if (is_prime(n)) return\
    \ n;\r\n    if (n % 2 == 0) return 2;\r\n    long long st = 0;\r\n    while (true)\
    \ {\r\n        st++;\r\n        long long x = st, y = f(x);\r\n        while (true)\
    \ {\r\n            long long p = gcd((y - x + n), n);\r\n            if (p ==\
    \ 0 || p == n) break;\r\n            if (p != 1) return p;\r\n            x =\
    \ f(x);\r\n            y = f(f(y));\r\n        }\r\n    }\r\n}\r\n\r\nstd::vector<long\
    \ long> pollard(long long n) {\r\n    if (n == 1) return {};\r\n    long long\
    \ x = pollard_single(n);\r\n    if (x == n) return {x};\r\n    std::vector<long\
    \ long> le = pollard(x);\r\n    std::vector<long long> ri = pollard(n / x);\r\n\
    \    le.insert(le.end(), ri.begin(), ri.end());\r\n    return le;\r\n}\r\n\r\n\
    }\r\n\r\nint main() {\r\n    using namespace std;\r\n    using namespace FactorBig;\r\
    \n    int q;\r\n    scanf(\"%d\", &q);\r\n    map<long long, vector<long long>>\
    \ cache;\r\n    for (int i = 0; i < q; i++) {\r\n        long long a;\r\n    \
    \    scanf(\"%lld\", &a);\r\n        if (!cache.count(a)) {\r\n            auto\
    \ v = pollard(a);\r\n            sort(v.begin(), v.end());\r\n            cache[a]\
    \ = v;\r\n        }\r\n        auto v = cache[a];\r\n        printf(\"%d\", int(v.size()));\r\
    \n        for (auto d: v) printf(\" %lld\", d);\r\n        printf(\"\\n\");\r\n\
    \    }\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/big_fast_factor_better.cpp
  requiredBy: []
  timestamp: '2020-11-28 21:15:23-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/big_fast_factor_better.cpp
layout: document
redirect_from:
- /library/library/number-theory/big_fast_factor_better.cpp
- /library/library/number-theory/big_fast_factor_better.cpp.html
title: library/number-theory/big_fast_factor_better.cpp
---

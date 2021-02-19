---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/big_fast_factor_better.cpp\"\n#include<bits/stdc++.h>\n\
    \nnamespace FactorBig {\n\nlong long gcd(long long _a, long long _b) {\n    unsigned\
    \ long long a = abs(_a), b = abs(_b);\n    if (a == 0) return b;\n    if (b ==\
    \ 0) return a;\n    auto bsf = [](unsigned long long x) -> int {\n        return\
    \ __builtin_ctzll(x);\n    };\n    int shift = bsf(a | b);\n    a >>= bsf(a);\n\
    \    do {\n        b >>= bsf(b);\n        if (a > b) \n            std::swap(a,\
    \ b);\n        b -= a;\n    } while (b);\n    return (a << shift);\n}\n\ntemplate\
    \ <class T, class U> T pow_mod(T x, U n, T md) {\n    T r = 1 % md;\n    x %=\
    \ md;\n    while (n) {\n        if (n & 1) r = (r * x) % md;\n        x = (x *\
    \ x) % md;\n        n >>= 1;\n    }\n    return r;\n}\n\nbool is_prime(long long\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2) return true;\n    if (n\
    \ % 2 == 0) return false;\n    long long d = n - 1;\n    while (d % 2 == 0) d\
    \ /= 2;\n    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})\
    \ {\n        if (n <= a) break;\n        long long t = d;\n        long long y\
    \ = pow_mod<__int128_t>(a, t, n);  // over\n        while (t != n - 1 && y !=\
    \ 1 && y != n - 1) {\n            y = __int128_t(y) * y % n;  // flow\n      \
    \      t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n        \
    \    return false;\n        }\n    }\n    return true;\n}\n\nlong long pollard_single(long\
    \ long n) {\n    auto f = [&](long long x) { return (__int128_t(x) * x + 1) %\
    \ n; };\n    if (is_prime(n)) return n;\n    if (n % 2 == 0) return 2;\n    long\
    \ long st = 0;\n    while (true) {\n        st++;\n        long long x = st, y\
    \ = f(x);\n        while (true) {\n            long long p = gcd((y - x + n),\
    \ n);\n            if (p == 0 || p == n) break;\n            if (p != 1) return\
    \ p;\n            x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n\n\
    std::vector<long long> pollard(long long n) {\n    if (n == 1) return {};\n  \
    \  long long x = pollard_single(n);\n    if (x == n) return {x};\n    std::vector<long\
    \ long> le = pollard(x);\n    std::vector<long long> ri = pollard(n / x);\n  \
    \  le.insert(le.end(), ri.begin(), ri.end());\n    return le;\n}\n\n}\n\nint main()\
    \ {\n    using namespace std;\n    using namespace FactorBig;\n    int q;\n  \
    \  scanf(\"%d\", &q);\n    map<long long, vector<long long>> cache;\n    for (int\
    \ i = 0; i < q; i++) {\n        long long a;\n        scanf(\"%lld\", &a);\n \
    \       if (!cache.count(a)) {\n            auto v = pollard(a);\n           \
    \ sort(v.begin(), v.end());\n            cache[a] = v;\n        }\n        auto\
    \ v = cache[a];\n        printf(\"%d\", (int)v.size());\n        for (auto d:\
    \ v) printf(\" %lld\", d);\n        printf(\"\\n\");\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nnamespace FactorBig {\n\nlong long gcd(long long\
    \ _a, long long _b) {\n    unsigned long long a = abs(_a), b = abs(_b);\n    if\
    \ (a == 0) return b;\n    if (b == 0) return a;\n    auto bsf = [](unsigned long\
    \ long x) -> int {\n        return __builtin_ctzll(x);\n    };\n    int shift\
    \ = bsf(a | b);\n    a >>= bsf(a);\n    do {\n        b >>= bsf(b);\n        if\
    \ (a > b) \n            std::swap(a, b);\n        b -= a;\n    } while (b);\n\
    \    return (a << shift);\n}\n\ntemplate <class T, class U> T pow_mod(T x, U n,\
    \ T md) {\n    T r = 1 % md;\n    x %= md;\n    while (n) {\n        if (n & 1)\
    \ r = (r * x) % md;\n        x = (x * x) % md;\n        n >>= 1;\n    }\n    return\
    \ r;\n}\n\nbool is_prime(long long n) {\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n    long long d =\
    \ n - 1;\n    while (d % 2 == 0) d /= 2;\n    for (long long a : {2, 3, 5, 7,\
    \ 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (n <= a) break;\n        long\
    \ long t = d;\n        long long y = pow_mod<__int128_t>(a, t, n);  // over\n\
    \        while (t != n - 1 && y != 1 && y != n - 1) {\n            y = __int128_t(y)\
    \ * y % n;  // flow\n            t <<= 1;\n        }\n        if (y != n - 1 &&\
    \ t % 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n\
    }\n\nlong long pollard_single(long long n) {\n    auto f = [&](long long x) {\
    \ return (__int128_t(x) * x + 1) % n; };\n    if (is_prime(n)) return n;\n   \
    \ if (n % 2 == 0) return 2;\n    long long st = 0;\n    while (true) {\n     \
    \   st++;\n        long long x = st, y = f(x);\n        while (true) {\n     \
    \       long long p = gcd((y - x + n), n);\n            if (p == 0 || p == n)\
    \ break;\n            if (p != 1) return p;\n            x = f(x);\n         \
    \   y = f(f(y));\n        }\n    }\n}\n\nstd::vector<long long> pollard(long long\
    \ n) {\n    if (n == 1) return {};\n    long long x = pollard_single(n);\n   \
    \ if (x == n) return {x};\n    std::vector<long long> le = pollard(x);\n    std::vector<long\
    \ long> ri = pollard(n / x);\n    le.insert(le.end(), ri.begin(), ri.end());\n\
    \    return le;\n}\n\n}\n\nint main() {\n    using namespace std;\n    using namespace\
    \ FactorBig;\n    int q;\n    scanf(\"%d\", &q);\n    map<long long, vector<long\
    \ long>> cache;\n    for (int i = 0; i < q; i++) {\n        long long a;\n   \
    \     scanf(\"%lld\", &a);\n        if (!cache.count(a)) {\n            auto v\
    \ = pollard(a);\n            sort(v.begin(), v.end());\n            cache[a] =\
    \ v;\n        }\n        auto v = cache[a];\n        printf(\"%d\", (int)v.size());\n\
    \        for (auto d: v) printf(\" %lld\", d);\n        printf(\"\\n\");\n   \
    \ }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/big_fast_factor_better.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/big_fast_factor_better.cpp
layout: document
redirect_from:
- /library/library/number-theory/big_fast_factor_better.cpp
- /library/library/number-theory/big_fast_factor_better.cpp.html
title: library/number-theory/big_fast_factor_better.cpp
---

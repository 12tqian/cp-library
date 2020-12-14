---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number-theory/mod_sqrt.cpp\"\n#include <bits/stdc++.h>\n\
    \nunsigned xrand() {\n    static unsigned x = 314159265, y = 358979323, z = 846264338,\
    \ w = 327950288;\n    unsigned t = x ^ x << 11; x = y; y = z; z = w; return w\
    \ = w ^ w >> 19 ^ t ^ t >> 8;\n}\n\nlong long mod_inverse(long long a, long long\
    \ m) {\n    long long b = m, x = 1, y = 0, t;\n    for (; ; ) {\n        t = a\
    \ / b, a -= t * b;\n        if (a == 0) {\n            assert(b == 1 || b == -1);\n\
    \            if ( b== -1) y = -y;\n            return (y < 0) ? (y + m) : y;\n\
    \        }\n        x -= t * y;\n        t = b / a, b -= t * a;\n        if (b\
    \ == 0) {\n            assert (a == 1 || a == -1);\n            if (a == -1) x\
    \ = -x;\n            return (x < 0) ? (x + m) : x;\n        }\n        y -= t\
    \ * x;\n    }\n}\n\nint jacobi(long long a, long long m) {\n    int s = 1;\n \
    \   if (a < 0) a = a % m + m;\n    for (; m > 1; ) {\n        a %= m;\n      \
    \  if (a == 0) return 0;\n        const int r = __builtin_ctz(a);\n        if\
    \ ((r & 1) && ((m + 2) & 4)) s = -s;\n        a >>= r;\n        if (a & m & 2)\
    \ s = -s;\n        std::swap(a, m);\n    }\n    return s;\n}\n\nstd::vector<long\
    \ long> mod_sqrt(long long a, long long p) {\n    if (p == 2) return {a & 1};\n\
    \    const int j = jacobi(a, p);\n    if (j == 0) return {0};\n    if (j == -1)\
    \ return {};\n    long long b, d;\n    for (; ; ) {\n        b = xrand() % p;\n\
    \        d = (b * b - a) % p;\n        if (d < 0) d += p;\n        if (jacobi(d,\
    \ p) == -1) break;\n    }\n    long long f0 = b, f1 = 1, g0 = 1, g1 = 0, tmp;\n\
    \    for (long long e = (p + 1) >> 1; e; e >>= 1) {\n        if (e & 1) {\n  \
    \          tmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;\n            g1 = (g0 *\
    \ f1 + g1 * f0) % p;\n            g0 = tmp;\n        }\n        tmp = (f0 * f0\
    \ + d * ((f1 * f1) % p)) % p;\n        f1 = (2 * f0 * f1) % p;\n        f0 = tmp;\n\
    \    }\n    return (g0 < p - g0) ? std::vector<long long>{g0, p - g0} : std::vector<long\
    \ long>{p - g0, g0};\n}\n\nint main() {\n    using namespace std;\n    int tt;\
    \ cin >> tt;\n    while (tt--) {\n        long long y, p;\n        cin >> y >>\
    \ p;\n        auto res = mod_sqrt(y, p);\n        if (res.empty()) cout << -1\
    \ << '\\n';\n        else cout << res[0] << '\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nunsigned xrand() {\n    static unsigned x = 314159265,\
    \ y = 358979323, z = 846264338, w = 327950288;\n    unsigned t = x ^ x << 11;\
    \ x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;\n}\n\nlong long mod_inverse(long\
    \ long a, long long m) {\n    long long b = m, x = 1, y = 0, t;\n    for (; ;\
    \ ) {\n        t = a / b, a -= t * b;\n        if (a == 0) {\n            assert(b\
    \ == 1 || b == -1);\n            if ( b== -1) y = -y;\n            return (y <\
    \ 0) ? (y + m) : y;\n        }\n        x -= t * y;\n        t = b / a, b -= t\
    \ * a;\n        if (b == 0) {\n            assert (a == 1 || a == -1);\n     \
    \       if (a == -1) x = -x;\n            return (x < 0) ? (x + m) : x;\n    \
    \    }\n        y -= t * x;\n    }\n}\n\nint jacobi(long long a, long long m)\
    \ {\n    int s = 1;\n    if (a < 0) a = a % m + m;\n    for (; m > 1; ) {\n  \
    \      a %= m;\n        if (a == 0) return 0;\n        const int r = __builtin_ctz(a);\n\
    \        if ((r & 1) && ((m + 2) & 4)) s = -s;\n        a >>= r;\n        if (a\
    \ & m & 2) s = -s;\n        std::swap(a, m);\n    }\n    return s;\n}\n\nstd::vector<long\
    \ long> mod_sqrt(long long a, long long p) {\n    if (p == 2) return {a & 1};\n\
    \    const int j = jacobi(a, p);\n    if (j == 0) return {0};\n    if (j == -1)\
    \ return {};\n    long long b, d;\n    for (; ; ) {\n        b = xrand() % p;\n\
    \        d = (b * b - a) % p;\n        if (d < 0) d += p;\n        if (jacobi(d,\
    \ p) == -1) break;\n    }\n    long long f0 = b, f1 = 1, g0 = 1, g1 = 0, tmp;\n\
    \    for (long long e = (p + 1) >> 1; e; e >>= 1) {\n        if (e & 1) {\n  \
    \          tmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;\n            g1 = (g0 *\
    \ f1 + g1 * f0) % p;\n            g0 = tmp;\n        }\n        tmp = (f0 * f0\
    \ + d * ((f1 * f1) % p)) % p;\n        f1 = (2 * f0 * f1) % p;\n        f0 = tmp;\n\
    \    }\n    return (g0 < p - g0) ? std::vector<long long>{g0, p - g0} : std::vector<long\
    \ long>{p - g0, g0};\n}\n\nint main() {\n    using namespace std;\n    int tt;\
    \ cin >> tt;\n    while (tt--) {\n        long long y, p;\n        cin >> y >>\
    \ p;\n        auto res = mod_sqrt(y, p);\n        if (res.empty()) cout << -1\
    \ << '\\n';\n        else cout << res[0] << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/mod_sqrt.cpp
  requiredBy: []
  timestamp: '2020-12-14 17:44:59-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/mod_sqrt.cpp
layout: document
redirect_from:
- /library/library/number-theory/mod_sqrt.cpp
- /library/library/number-theory/mod_sqrt.cpp.html
title: library/number-theory/mod_sqrt.cpp
---

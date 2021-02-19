---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/unused/big_fast_factor_failed.cpp\"\n#include<bits/stdc++.h>\n\
    \ntemplate <int SZ> struct Sieve {\n    std::bitset<SZ> pri;\n    std::vector<int>\
    \ pr;\n    Sieve() {\n        pri.set();\n        pri[0] = pri[1] = 0;\n     \
    \   for (int i = 4; i < SZ; i += 2) {\n            pri[i] = 0;\n        }\n  \
    \      for (int i = 3; i * i < SZ; i += 2) {\n            if (pri[i]) {\n    \
    \            for (int j = i * i; j < SZ; j += 2 * i) {\n                    pri[j]\
    \ = 0;\n                }\n            }\n        }\n        for (int i = 0; i\
    \ < SZ; i++) {\n            if (pri[i]) {\n                pr.push_back(i);\n\
    \            }\n        }\n    }\n};\n\nnamespace FactorFast {\n\nstd::mt19937\
    \ random_number((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\n\
    Sieve<(1 << 20)> S;\n\nunsigned long long mod_mul(unsigned long long a, unsigned\
    \ long long b, unsigned long long mod) {\n    long long ret = a * b - mod * (unsigned\
    \ long long) ((long double) a * b / mod);\n    return ret + ((ret < 0) - (ret\
    \ >= (long long) mod)) * mod;\n}\n\nunsigned long long mod_pow(unsigned long long\
    \ a, unsigned long long b, unsigned long long mod) {\n    if (b == 0) {\n    \
    \    return 1;\n    }\n    unsigned long long res = mod_pow(a, b / 2, mod);\n\
    \    res = mod_mul(res, res, mod);\n    if (b & 1) {\n        return mod_mul(res,\
    \ a, mod);\n    }\n    return res;\n}\n\nbool miller_rabin(long long p) {\n  \
    \  if (p == 2) {\n        return true;\n    } else if (p == 1 || p % 2 == 0) {\n\
    \        return false;\n    }\n    long long s = p - 1;\n    while (s % 2 == 0)\
    \ {\n        s /= 2;\n    }\n    for (int i = 0; i < 30; i++) {\n        long\
    \ long a = random_number() % (p - 1) + 1;\n        long long tmp = s;\n      \
    \  long long mod = mod_pow(a, tmp, p);\n        while (tmp != p - 1 && mod !=\
    \ 1 && mod != p - 1) {\n            mod = mod_mul(mod, mod, p);\n            tmp\
    \ *= 2;\n        }\n        if (mod != p - 1 && tmp % 2 == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n\nlong long f(long long a, long\
    \ long n, long long& has) {\n    return (mod_mul(a, a, n) + has) % n;\n}\n\nstd::vector<std::pair<long\
    \ long, long long>> pollards_rho(long long d) {\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    auto& pr = S.pr;\n    for (int i = 0; i < (int)pr.size()\
    \ && pr[i] * pr[i] <= d; i++) {\n        if (d % pr[i] == 0) {\n            int\
    \ co = 0;\n            while (d % pr[i] == 0) {\n                d /= pr[i];\n\
    \                co++;\n            }\n            res.emplace_back(pr[i], co);\n\
    \        }\n    }\n    if (d > 1) {\n        if (miller_rabin(d)) {\n        \
    \    res.emplace_back(d, 1);\n        } else {\n            while (true) {\n \
    \               long long has = random_number() % 2321 + 47;\n               \
    \ long long x = 2, y = 2, c = 1;\n                for (; c == 1; c = std::__gcd(abs(x\
    \ - y), d)) {\n                    x = f(x, d, has);\n                    y =\
    \ f(f(y, d, has), d, has);\n                }\n                if (c != d) {\n\
    \                    d /= c;\n                    if (d > c) {\n             \
    \           std::swap(d, c);\n                    }\n                    if (c\
    \ == d) {\n                        res.emplace_back(c, 2);\n                 \
    \   } else {\n                        res.emplace_back(c, 1);\n              \
    \          res.emplace_back(d, 1);\n                    }\n                  \
    \  break;\n                }\n            }\n        }\n    }\n    return res;\n\
    }\n\n}\n\n\nint main() {\n    using namespace FactorFast;\n    using namespace\
    \ std;\n    int q; cin >> q;\n    while (q--) {\n        long long a; cin >> a;\n\
    \        auto f = pollards_rho(a);\n        int tot = 0;\n        for (auto x\
    \ : f) {\n            tot += x.second;\n        }\n        cout << tot << \" \"\
    ;\n        for (auto x : f) {\n            for (int i = 0; i < x.second; i++)\
    \ \n                cout << x.first << \" \";\n        }\n        cout << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <int SZ> struct Sieve {\n    std::bitset<SZ>\
    \ pri;\n    std::vector<int> pr;\n    Sieve() {\n        pri.set();\n        pri[0]\
    \ = pri[1] = 0;\n        for (int i = 4; i < SZ; i += 2) {\n            pri[i]\
    \ = 0;\n        }\n        for (int i = 3; i * i < SZ; i += 2) {\n           \
    \ if (pri[i]) {\n                for (int j = i * i; j < SZ; j += 2 * i) {\n \
    \                   pri[j] = 0;\n                }\n            }\n        }\n\
    \        for (int i = 0; i < SZ; i++) {\n            if (pri[i]) {\n         \
    \       pr.push_back(i);\n            }\n        }\n    }\n};\n\nnamespace FactorFast\
    \ {\n\nstd::mt19937 random_number((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\n\
    Sieve<(1 << 20)> S;\n\nunsigned long long mod_mul(unsigned long long a, unsigned\
    \ long long b, unsigned long long mod) {\n    long long ret = a * b - mod * (unsigned\
    \ long long) ((long double) a * b / mod);\n    return ret + ((ret < 0) - (ret\
    \ >= (long long) mod)) * mod;\n}\n\nunsigned long long mod_pow(unsigned long long\
    \ a, unsigned long long b, unsigned long long mod) {\n    if (b == 0) {\n    \
    \    return 1;\n    }\n    unsigned long long res = mod_pow(a, b / 2, mod);\n\
    \    res = mod_mul(res, res, mod);\n    if (b & 1) {\n        return mod_mul(res,\
    \ a, mod);\n    }\n    return res;\n}\n\nbool miller_rabin(long long p) {\n  \
    \  if (p == 2) {\n        return true;\n    } else if (p == 1 || p % 2 == 0) {\n\
    \        return false;\n    }\n    long long s = p - 1;\n    while (s % 2 == 0)\
    \ {\n        s /= 2;\n    }\n    for (int i = 0; i < 30; i++) {\n        long\
    \ long a = random_number() % (p - 1) + 1;\n        long long tmp = s;\n      \
    \  long long mod = mod_pow(a, tmp, p);\n        while (tmp != p - 1 && mod !=\
    \ 1 && mod != p - 1) {\n            mod = mod_mul(mod, mod, p);\n            tmp\
    \ *= 2;\n        }\n        if (mod != p - 1 && tmp % 2 == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n\nlong long f(long long a, long\
    \ long n, long long& has) {\n    return (mod_mul(a, a, n) + has) % n;\n}\n\nstd::vector<std::pair<long\
    \ long, long long>> pollards_rho(long long d) {\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    auto& pr = S.pr;\n    for (int i = 0; i < (int)pr.size()\
    \ && pr[i] * pr[i] <= d; i++) {\n        if (d % pr[i] == 0) {\n            int\
    \ co = 0;\n            while (d % pr[i] == 0) {\n                d /= pr[i];\n\
    \                co++;\n            }\n            res.emplace_back(pr[i], co);\n\
    \        }\n    }\n    if (d > 1) {\n        if (miller_rabin(d)) {\n        \
    \    res.emplace_back(d, 1);\n        } else {\n            while (true) {\n \
    \               long long has = random_number() % 2321 + 47;\n               \
    \ long long x = 2, y = 2, c = 1;\n                for (; c == 1; c = std::__gcd(abs(x\
    \ - y), d)) {\n                    x = f(x, d, has);\n                    y =\
    \ f(f(y, d, has), d, has);\n                }\n                if (c != d) {\n\
    \                    d /= c;\n                    if (d > c) {\n             \
    \           std::swap(d, c);\n                    }\n                    if (c\
    \ == d) {\n                        res.emplace_back(c, 2);\n                 \
    \   } else {\n                        res.emplace_back(c, 1);\n              \
    \          res.emplace_back(d, 1);\n                    }\n                  \
    \  break;\n                }\n            }\n        }\n    }\n    return res;\n\
    }\n\n}\n\n\nint main() {\n    using namespace FactorFast;\n    using namespace\
    \ std;\n    int q; cin >> q;\n    while (q--) {\n        long long a; cin >> a;\n\
    \        auto f = pollards_rho(a);\n        int tot = 0;\n        for (auto x\
    \ : f) {\n            tot += x.second;\n        }\n        cout << tot << \" \"\
    ;\n        for (auto x : f) {\n            for (int i = 0; i < x.second; i++)\
    \ \n                cout << x.first << \" \";\n        }\n        cout << '\\\
    n';\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/unused/big_fast_factor_failed.cpp
  requiredBy: []
  timestamp: '2021-02-19 14:37:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/unused/big_fast_factor_failed.cpp
layout: document
redirect_from:
- /library/library/unused/big_fast_factor_failed.cpp
- /library/library/unused/big_fast_factor_failed.cpp.html
title: library/unused/big_fast_factor_failed.cpp
---

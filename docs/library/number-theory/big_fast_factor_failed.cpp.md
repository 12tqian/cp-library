---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\number-theory\\\\big_fast_factor_failed.cpp\"\
    \n#include<bits/stdc++.h>\r\n\r\ntemplate <int SZ> struct Sieve {\r\n    std::bitset<SZ>\
    \ pri;\r\n    std::vector<int> pr;\r\n    Sieve() {\r\n        pri.set();\r\n\
    \        pri[0] = pri[1] = 0;\r\n        for (int i = 4; i < SZ; i += 2) {\r\n\
    \            pri[i] = 0;\r\n        }\r\n        for (int i = 3; i * i < SZ; i\
    \ += 2) {\r\n            if (pri[i]) {\r\n                for (int j = i * i;\
    \ j < SZ; j += 2 * i) {\r\n                    pri[j] = 0;\r\n               \
    \ }\r\n            }\r\n        }\r\n        for (int i = 0; i < SZ; i++) {\r\n\
    \            if (pri[i]) {\r\n                pr.push_back(i);\r\n           \
    \ }\r\n        }\r\n    }\r\n};\r\n\r\nnamespace FactorFast {\r\n\r\nstd::mt19937\
    \ random_number((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \nSieve<(1 << 20)> S;\r\n\r\nunsigned long long mod_mul(unsigned long long a,\
    \ unsigned long long b, unsigned long long mod) {\r\n    long long ret = a * b\
    \ - mod * (unsigned long long) ((long double) a * b / mod);\r\n    return ret\
    \ + ((ret < 0) - (ret >= (long long) mod)) * mod;\r\n}\r\n\r\nunsigned long long\
    \ mod_pow(unsigned long long a, unsigned long long b, unsigned long long mod)\
    \ {\r\n    if (b == 0) {\r\n        return 1;\r\n    }\r\n    unsigned long long\
    \ res = mod_pow(a, b / 2, mod);\r\n    res = mod_mul(res, res, mod);\r\n    if\
    \ (b & 1) {\r\n        return mod_mul(res, a, mod);\r\n    }\r\n    return res;\r\
    \n}\r\n\r\nbool miller_rabin(long long p) {\r\n    if (p == 2) {\r\n        return\
    \ true;\r\n    } else if (p == 1 || p % 2 == 0) {\r\n        return false;\r\n\
    \    }\r\n    long long s = p - 1;\r\n    while (s % 2 == 0) {\r\n        s /=\
    \ 2;\r\n    }\r\n    for (int i = 0; i < 30; i++) {\r\n        long long a = random_number()\
    \ % (p - 1) + 1;\r\n        long long tmp = s;\r\n        long long mod = mod_pow(a,\
    \ tmp, p);\r\n        while (tmp != p - 1 && mod != 1 && mod != p - 1) {\r\n \
    \           mod = mod_mul(mod, mod, p);\r\n            tmp *= 2;\r\n        }\r\
    \n        if (mod != p - 1 && tmp % 2 == 0) {\r\n            return false;\r\n\
    \        }\r\n    }\r\n    return true;\r\n}\r\n\r\nlong long f(long long a, long\
    \ long n, long long& has) {\r\n    return (mod_mul(a, a, n) + has) % n;\r\n}\r\
    \n\r\nstd::vector<std::pair<long long, long long>> pollards_rho(long long d) {\r\
    \n    std::vector<std::pair<long long, long long>> res;\r\n    auto& pr = S.pr;\r\
    \n    for (int i = 0; i < int(pr.size()) && pr[i] * pr[i] <= d; i++) {\r\n   \
    \     if (d % pr[i] == 0) {\r\n            int co = 0;\r\n            while (d\
    \ % pr[i] == 0) {\r\n                d /= pr[i];\r\n                co++;\r\n\
    \            }\r\n            res.emplace_back(pr[i], co);\r\n        }\r\n  \
    \  }\r\n    if (d > 1) {\r\n        if (miller_rabin(d)) {\r\n            res.emplace_back(d,\
    \ 1);\r\n        } else {\r\n            while (true) {\r\n                long\
    \ long has = random_number() % 2321 + 47;\r\n                long long x = 2,\
    \ y = 2, c = 1;\r\n                for (; c == 1; c = std::__gcd(abs(x - y), d))\
    \ {\r\n                    x = f(x, d, has);\r\n                    y = f(f(y,\
    \ d, has), d, has);\r\n                }\r\n                if (c != d) {\r\n\
    \                    d /= c;\r\n                    if (d > c) {\r\n         \
    \               std::swap(d, c);\r\n                    }\r\n                \
    \    if (c == d) {\r\n                        res.emplace_back(c, 2);\r\n    \
    \                } else {\r\n                        res.emplace_back(c, 1);\r\
    \n                        res.emplace_back(d, 1);\r\n                    }\r\n\
    \                    break;\r\n                }\r\n            }\r\n        }\r\
    \n    }\r\n    return res;\r\n}\r\n\r\n}\r\n\r\n\r\nint main() {\r\n    using\
    \ namespace FactorFast;\r\n    using namespace std;\r\n    int q; cin >> q;\r\n\
    \    while (q--) {\r\n        long long a; cin >> a;\r\n        auto f = pollards_rho(a);\r\
    \n        int tot = 0;\r\n        for (auto x : f) {\r\n            tot += x.second;\r\
    \n        }\r\n        cout << tot << \" \";\r\n        for (auto x : f) {\r\n\
    \            for (int i = 0; i < x.second; i++) \r\n                cout << x.first\
    \ << \" \";\r\n        }\r\n        cout << '\\n';\r\n    }\r\n    return 0;\r\
    \n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\ntemplate <int SZ> struct Sieve {\r\n    std::bitset<SZ>\
    \ pri;\r\n    std::vector<int> pr;\r\n    Sieve() {\r\n        pri.set();\r\n\
    \        pri[0] = pri[1] = 0;\r\n        for (int i = 4; i < SZ; i += 2) {\r\n\
    \            pri[i] = 0;\r\n        }\r\n        for (int i = 3; i * i < SZ; i\
    \ += 2) {\r\n            if (pri[i]) {\r\n                for (int j = i * i;\
    \ j < SZ; j += 2 * i) {\r\n                    pri[j] = 0;\r\n               \
    \ }\r\n            }\r\n        }\r\n        for (int i = 0; i < SZ; i++) {\r\n\
    \            if (pri[i]) {\r\n                pr.push_back(i);\r\n           \
    \ }\r\n        }\r\n    }\r\n};\r\n\r\nnamespace FactorFast {\r\n\r\nstd::mt19937\
    \ random_number((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \nSieve<(1 << 20)> S;\r\n\r\nunsigned long long mod_mul(unsigned long long a,\
    \ unsigned long long b, unsigned long long mod) {\r\n    long long ret = a * b\
    \ - mod * (unsigned long long) ((long double) a * b / mod);\r\n    return ret\
    \ + ((ret < 0) - (ret >= (long long) mod)) * mod;\r\n}\r\n\r\nunsigned long long\
    \ mod_pow(unsigned long long a, unsigned long long b, unsigned long long mod)\
    \ {\r\n    if (b == 0) {\r\n        return 1;\r\n    }\r\n    unsigned long long\
    \ res = mod_pow(a, b / 2, mod);\r\n    res = mod_mul(res, res, mod);\r\n    if\
    \ (b & 1) {\r\n        return mod_mul(res, a, mod);\r\n    }\r\n    return res;\r\
    \n}\r\n\r\nbool miller_rabin(long long p) {\r\n    if (p == 2) {\r\n        return\
    \ true;\r\n    } else if (p == 1 || p % 2 == 0) {\r\n        return false;\r\n\
    \    }\r\n    long long s = p - 1;\r\n    while (s % 2 == 0) {\r\n        s /=\
    \ 2;\r\n    }\r\n    for (int i = 0; i < 30; i++) {\r\n        long long a = random_number()\
    \ % (p - 1) + 1;\r\n        long long tmp = s;\r\n        long long mod = mod_pow(a,\
    \ tmp, p);\r\n        while (tmp != p - 1 && mod != 1 && mod != p - 1) {\r\n \
    \           mod = mod_mul(mod, mod, p);\r\n            tmp *= 2;\r\n        }\r\
    \n        if (mod != p - 1 && tmp % 2 == 0) {\r\n            return false;\r\n\
    \        }\r\n    }\r\n    return true;\r\n}\r\n\r\nlong long f(long long a, long\
    \ long n, long long& has) {\r\n    return (mod_mul(a, a, n) + has) % n;\r\n}\r\
    \n\r\nstd::vector<std::pair<long long, long long>> pollards_rho(long long d) {\r\
    \n    std::vector<std::pair<long long, long long>> res;\r\n    auto& pr = S.pr;\r\
    \n    for (int i = 0; i < int(pr.size()) && pr[i] * pr[i] <= d; i++) {\r\n   \
    \     if (d % pr[i] == 0) {\r\n            int co = 0;\r\n            while (d\
    \ % pr[i] == 0) {\r\n                d /= pr[i];\r\n                co++;\r\n\
    \            }\r\n            res.emplace_back(pr[i], co);\r\n        }\r\n  \
    \  }\r\n    if (d > 1) {\r\n        if (miller_rabin(d)) {\r\n            res.emplace_back(d,\
    \ 1);\r\n        } else {\r\n            while (true) {\r\n                long\
    \ long has = random_number() % 2321 + 47;\r\n                long long x = 2,\
    \ y = 2, c = 1;\r\n                for (; c == 1; c = std::__gcd(abs(x - y), d))\
    \ {\r\n                    x = f(x, d, has);\r\n                    y = f(f(y,\
    \ d, has), d, has);\r\n                }\r\n                if (c != d) {\r\n\
    \                    d /= c;\r\n                    if (d > c) {\r\n         \
    \               std::swap(d, c);\r\n                    }\r\n                \
    \    if (c == d) {\r\n                        res.emplace_back(c, 2);\r\n    \
    \                } else {\r\n                        res.emplace_back(c, 1);\r\
    \n                        res.emplace_back(d, 1);\r\n                    }\r\n\
    \                    break;\r\n                }\r\n            }\r\n        }\r\
    \n    }\r\n    return res;\r\n}\r\n\r\n}\r\n\r\n\r\nint main() {\r\n    using\
    \ namespace FactorFast;\r\n    using namespace std;\r\n    int q; cin >> q;\r\n\
    \    while (q--) {\r\n        long long a; cin >> a;\r\n        auto f = pollards_rho(a);\r\
    \n        int tot = 0;\r\n        for (auto x : f) {\r\n            tot += x.second;\r\
    \n        }\r\n        cout << tot << \" \";\r\n        for (auto x : f) {\r\n\
    \            for (int i = 0; i < x.second; i++) \r\n                cout << x.first\
    \ << \" \";\r\n        }\r\n        cout << '\\n';\r\n    }\r\n    return 0;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\number-theory\big_fast_factor_failed.cpp
  requiredBy: []
  timestamp: '2020-11-28 21:09:23-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\number-theory\big_fast_factor_failed.cpp
layout: document
redirect_from:
- /library\library\number-theory\big_fast_factor_failed.cpp
- /library\library\number-theory\big_fast_factor_failed.cpp.html
title: library\number-theory\big_fast_factor_failed.cpp
---

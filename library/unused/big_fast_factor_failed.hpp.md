---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/unused/big_fast_factor_failed.hpp\"\n\ntemplate\
    \ <int SZ> struct Sieve {\n\tstd::bitset<SZ> pri;\n\tstd::vector<int> pr;\n\t\
    Sieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1] = 0;\n\t\tfor (int i = 4; i < SZ;\
    \ i += 2) {\n\t\t\tpri[i] = 0;\n\t\t}\n\t\tfor (int i = 3; i * i < SZ; i += 2)\
    \ {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor (int j = i * i; j < SZ; j += 2 * i) {\n\t\
    \t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < SZ; i++)\
    \ {\n\t\t\tif (pri[i]) {\n\t\t\t\tpr.push_back(i);\n\t\t\t}\n\t\t}\n\t}\n};\n\n\
    namespace FactorFast {\n\nstd::mt19937 random_number((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());\n\
    Sieve<(1 << 20)> S;\n\nunsigned long long mod_mul(unsigned long long a, unsigned\
    \ long long b, unsigned long long mod) {\n\tlong long ret = a * b - mod * (unsigned\
    \ long long) ((long double) a * b / mod);\n\treturn ret + ((ret < 0) - (ret >=\
    \ (long long) mod)) * mod;\n}\n\nunsigned long long mod_pow(unsigned long long\
    \ a, unsigned long long b, unsigned long long mod) {\n\tif (b == 0) {\n\t\treturn\
    \ 1;\n\t}\n\tunsigned long long res = mod_pow(a, b / 2, mod);\n\tres = mod_mul(res,\
    \ res, mod);\n\tif (b & 1) {\n\t\treturn mod_mul(res, a, mod);\n\t}\n\treturn\
    \ res;\n}\n\nbool miller_rabin(long long p) {\n\tif (p == 2) {\n\t\treturn true;\n\
    \t} else if (p == 1 || p % 2 == 0) {\n\t\treturn false;\n\t}\n\tlong long s =\
    \ p - 1;\n\twhile (s % 2 == 0) {\n\t\ts /= 2;\n\t}\n\tfor (int i = 0; i < 30;\
    \ i++) {\n\t\tlong long a = random_number() % (p - 1) + 1;\n\t\tlong long tmp\
    \ = s;\n\t\tlong long mod = mod_pow(a, tmp, p);\n\t\twhile (tmp != p - 1 && mod\
    \ != 1 && mod != p - 1) {\n\t\t\tmod = mod_mul(mod, mod, p);\n\t\t\ttmp *= 2;\n\
    \t\t}\n\t\tif (mod != p - 1 && tmp % 2 == 0) {\n\t\t\treturn false;\n\t\t}\n\t\
    }\n\treturn true;\n}\n\nlong long f(long long a, long long n, long long &has)\
    \ {\n\treturn (mod_mul(a, a, n) + has) % n;\n}\n\nstd::vector<std::pair<long long,\
    \ long long>> pollards_rho(long long d) {\n\tstd::vector<std::pair<long long,\
    \ long long>> res;\n\tauto &pr = S.pr;\n\tfor (int i = 0; i < (int)pr.size() &&\
    \ pr[i] * pr[i] <= d; i++) {\n\t\tif (d % pr[i] == 0) {\n\t\t\tint co = 0;\n\t\
    \t\twhile (d % pr[i] == 0) {\n\t\t\t\td /= pr[i];\n\t\t\t\tco++;\n\t\t\t}\n\t\t\
    \tres.emplace_back(pr[i], co);\n\t\t}\n\t}\n\tif (d > 1) {\n\t\tif (miller_rabin(d))\
    \ {\n\t\t\tres.emplace_back(d, 1);\n\t\t} else {\n\t\t\twhile (true) {\n\t\t\t\
    \tlong long has = random_number() % 2321 + 47;\n\t\t\t\tlong long x = 2, y = 2,\
    \ c = 1;\n\t\t\t\tfor (; c == 1; c = std::__gcd(abs(x - y), d)) {\n\t\t\t\t\t\
    x = f(x, d, has);\n\t\t\t\t\ty = f(f(y, d, has), d, has);\n\t\t\t\t}\n\t\t\t\t\
    if (c != d) {\n\t\t\t\t\td /= c;\n\t\t\t\t\tif (d > c) {\n\t\t\t\t\t\tstd::swap(d,\
    \ c);\n\t\t\t\t\t}\n\t\t\t\t\tif (c == d) {\n\t\t\t\t\t\tres.emplace_back(c, 2);\n\
    \t\t\t\t\t} else {\n\t\t\t\t\t\tres.emplace_back(c, 1);\n\t\t\t\t\t\tres.emplace_back(d,\
    \ 1);\n\t\t\t\t\t}\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ res;\n}\n\n}\n\nint main() {\n\tusing namespace FactorFast;\n\tusing namespace\
    \ std;\n\tint q; cin >> q;\n\twhile (q--) {\n\t\tlong long a; cin >> a;\n\t\t\
    auto f = pollards_rho(a);\n\t\tint tot = 0;\n\t\tfor (auto x : f) {\n\t\t\ttot\
    \ += x.second;\n\t\t}\n\t\tcout << tot << \" \";\n\t\tfor (auto x : f) {\n\t\t\
    \tfor (int i = 0; i < x.second; i++) \n\t\t\t\tcout << x.first << \" \";\n\t\t\
    }\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#pragma once\n\ntemplate <int SZ> struct Sieve {\n\tstd::bitset<SZ> pri;\n\
    \tstd::vector<int> pr;\n\tSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1] = 0;\n\
    \t\tfor (int i = 4; i < SZ; i += 2) {\n\t\t\tpri[i] = 0;\n\t\t}\n\t\tfor (int\
    \ i = 3; i * i < SZ; i += 2) {\n\t\t\tif (pri[i]) {\n\t\t\t\tfor (int j = i *\
    \ i; j < SZ; j += 2 * i) {\n\t\t\t\t\tpri[j] = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\tfor (int i = 0; i < SZ; i++) {\n\t\t\tif (pri[i]) {\n\t\t\t\tpr.push_back(i);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n\nnamespace FactorFast {\n\nstd::mt19937 random_number((uint32_t)\
    \ std::chrono::steady_clock::now().time_since_epoch().count());\nSieve<(1 << 20)>\
    \ S;\n\nunsigned long long mod_mul(unsigned long long a, unsigned long long b,\
    \ unsigned long long mod) {\n\tlong long ret = a * b - mod * (unsigned long long)\
    \ ((long double) a * b / mod);\n\treturn ret + ((ret < 0) - (ret >= (long long)\
    \ mod)) * mod;\n}\n\nunsigned long long mod_pow(unsigned long long a, unsigned\
    \ long long b, unsigned long long mod) {\n\tif (b == 0) {\n\t\treturn 1;\n\t}\n\
    \tunsigned long long res = mod_pow(a, b / 2, mod);\n\tres = mod_mul(res, res,\
    \ mod);\n\tif (b & 1) {\n\t\treturn mod_mul(res, a, mod);\n\t}\n\treturn res;\n\
    }\n\nbool miller_rabin(long long p) {\n\tif (p == 2) {\n\t\treturn true;\n\t}\
    \ else if (p == 1 || p % 2 == 0) {\n\t\treturn false;\n\t}\n\tlong long s = p\
    \ - 1;\n\twhile (s % 2 == 0) {\n\t\ts /= 2;\n\t}\n\tfor (int i = 0; i < 30; i++)\
    \ {\n\t\tlong long a = random_number() % (p - 1) + 1;\n\t\tlong long tmp = s;\n\
    \t\tlong long mod = mod_pow(a, tmp, p);\n\t\twhile (tmp != p - 1 && mod != 1 &&\
    \ mod != p - 1) {\n\t\t\tmod = mod_mul(mod, mod, p);\n\t\t\ttmp *= 2;\n\t\t}\n\
    \t\tif (mod != p - 1 && tmp % 2 == 0) {\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn\
    \ true;\n}\n\nlong long f(long long a, long long n, long long &has) {\n\treturn\
    \ (mod_mul(a, a, n) + has) % n;\n}\n\nstd::vector<std::pair<long long, long long>>\
    \ pollards_rho(long long d) {\n\tstd::vector<std::pair<long long, long long>>\
    \ res;\n\tauto &pr = S.pr;\n\tfor (int i = 0; i < (int)pr.size() && pr[i] * pr[i]\
    \ <= d; i++) {\n\t\tif (d % pr[i] == 0) {\n\t\t\tint co = 0;\n\t\t\twhile (d %\
    \ pr[i] == 0) {\n\t\t\t\td /= pr[i];\n\t\t\t\tco++;\n\t\t\t}\n\t\t\tres.emplace_back(pr[i],\
    \ co);\n\t\t}\n\t}\n\tif (d > 1) {\n\t\tif (miller_rabin(d)) {\n\t\t\tres.emplace_back(d,\
    \ 1);\n\t\t} else {\n\t\t\twhile (true) {\n\t\t\t\tlong long has = random_number()\
    \ % 2321 + 47;\n\t\t\t\tlong long x = 2, y = 2, c = 1;\n\t\t\t\tfor (; c == 1;\
    \ c = std::__gcd(abs(x - y), d)) {\n\t\t\t\t\tx = f(x, d, has);\n\t\t\t\t\ty =\
    \ f(f(y, d, has), d, has);\n\t\t\t\t}\n\t\t\t\tif (c != d) {\n\t\t\t\t\td /= c;\n\
    \t\t\t\t\tif (d > c) {\n\t\t\t\t\t\tstd::swap(d, c);\n\t\t\t\t\t}\n\t\t\t\t\t\
    if (c == d) {\n\t\t\t\t\t\tres.emplace_back(c, 2);\n\t\t\t\t\t} else {\n\t\t\t\
    \t\t\tres.emplace_back(c, 1);\n\t\t\t\t\t\tres.emplace_back(d, 1);\n\t\t\t\t\t\
    }\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n\n}\n\n\
    int main() {\n\tusing namespace FactorFast;\n\tusing namespace std;\n\tint q;\
    \ cin >> q;\n\twhile (q--) {\n\t\tlong long a; cin >> a;\n\t\tauto f = pollards_rho(a);\n\
    \t\tint tot = 0;\n\t\tfor (auto x : f) {\n\t\t\ttot += x.second;\n\t\t}\n\t\t\
    cout << tot << \" \";\n\t\tfor (auto x : f) {\n\t\t\tfor (int i = 0; i < x.second;\
    \ i++) \n\t\t\t\tcout << x.first << \" \";\n\t\t}\n\t\tcout << '\\n';\n\t}\n\t\
    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/unused/big_fast_factor_failed.hpp
  requiredBy: []
  timestamp: '2021-07-24 18:14:21-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/unused/big_fast_factor_failed.hpp
layout: document
redirect_from:
- /library/library/unused/big_fast_factor_failed.hpp
- /library/library/unused/big_fast_factor_failed.hpp.html
title: library/unused/big_fast_factor_failed.hpp
---

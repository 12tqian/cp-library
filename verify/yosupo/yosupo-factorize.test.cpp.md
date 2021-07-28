---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/factor-big.hpp
    title: library/number-theory/factor-big.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nnamespace FactorBig {\n\nlong long gcd(long long _a, long long _b) {\n\tunsigned\
    \ long long a = abs(_a), b = abs(_b);\n\tif (a == 0) return b;\n\tif (b == 0)\
    \ return a;\n\tauto bsf = [](unsigned long long x) -> int {\n\t\treturn __builtin_ctzll(x);\n\
    \t};\n\tint shift = bsf(a | b);\n\ta >>= bsf(a);\n\tdo {\n\t\tb >>= bsf(b);\n\t\
    \tif (a > b) \n\t\t\tstd::swap(a, b);\n\t\tb -= a;\n\t} while (b);\n\treturn (a\
    \ << shift);\n}\n\ntemplate <class T, class U> T pow_mod(T x, U n, T md) {\n\t\
    T r = 1 % md;\n\tx %= md;\n\twhile (n) {\n\t\tif (n & 1) r = (r * x) % md;\n\t\
    \tx = (x * x) % md;\n\t\tn >>= 1;\n\t}\n\treturn r;\n}\n\nbool is_prime(long long\
    \ n) {\n\tif (n <= 1) return false;\n\tif (n == 2) return true;\n\tif (n % 2 ==\
    \ 0) return false;\n\tlong long d = n - 1;\n\twhile (d % 2 == 0) d /= 2;\n\tfor\
    \ (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n\t\tif (n <=\
    \ a) break;\n\t\tlong long t = d;\n\t\tlong long y = pow_mod<__int128_t>(a, t,\
    \ n);  // over\n\t\twhile (t != n - 1 && y != 1 && y != n - 1) {\n\t\t\ty = __int128_t(y)\
    \ * y % n;  // flow\n\t\t\tt <<= 1;\n\t\t}\n\t\tif (y != n - 1 && t % 2 == 0)\
    \ {\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn true;\n}\n\nlong long pollard_single(long\
    \ long n) {\n\tauto f = [&](long long x) { return (__int128_t(x) * x + 1) % n;\
    \ };\n\tif (is_prime(n)) return n;\n\tif (n % 2 == 0) return 2;\n\tlong long st\
    \ = 0;\n\twhile (true) {\n\t\tst++;\n\t\tlong long x = st, y = f(x);\n\t\twhile\
    \ (true) {\n\t\t\tlong long p = gcd((y - x + n), n);\n\t\t\tif (p == 0 || p ==\
    \ n) break;\n\t\t\tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\
    \t\t}\n\t}\n}\n\nstd::vector<long long> pollard(long long n) {\n\tif (n == 1)\
    \ return {};\n\tlong long x = pollard_single(n);\n\tif (x == n) return {x};\n\t\
    std::vector<long long> le = pollard(x);\n\tstd::vector<long long> ri = pollard(n\
    \ / x);\n\tle.insert(le.end(), ri.begin(), ri.end());\n\treturn le;\n}\n\n}\n\n\
    int main() {\n\tusing namespace FactorBig;\n\tint q;\n\tscanf(\"%d\", &q);\n\t\
    map<long long, vector<long long>> cache;\n\tfor (int i = 0; i < q; i++) {\n\t\t\
    long long a;\n\t\tscanf(\"%lld\", &a);\n\t\tif (!cache.count(a)) {\n\t\t\tauto\
    \ v = pollard(a);\n\t\t\tsort(v.begin(), v.end());\n\t\t\tcache[a] = v;\n\t\t\
    }\n\t\tauto v = cache[a];\n\t\tprintf(\"%d\", (int)v.size());\n\t\tfor (auto d:\
    \ v) printf(\" %lld\", d);\n\t\tprintf(\"\\n\");\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/number-theory/factor-big.hpp\"\
    \n\nint main() {\n\tusing namespace FactorBig;\n\tint q;\n\tscanf(\"%d\", &q);\n\
    \tmap<long long, vector<long long>> cache;\n\tfor (int i = 0; i < q; i++) {\n\t\
    \tlong long a;\n\t\tscanf(\"%lld\", &a);\n\t\tif (!cache.count(a)) {\n\t\t\tauto\
    \ v = pollard(a);\n\t\t\tsort(v.begin(), v.end());\n\t\t\tcache[a] = v;\n\t\t\
    }\n\t\tauto v = cache[a];\n\t\tprintf(\"%d\", (int)v.size());\n\t\tfor (auto d:\
    \ v) printf(\" %lld\", d);\n\t\tprintf(\"\\n\");\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/factor-big.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-factorize.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-factorize.test.cpp
- /verify/verify/yosupo/yosupo-factorize.test.cpp.html
title: verify/yosupo/yosupo-factorize.test.cpp
---

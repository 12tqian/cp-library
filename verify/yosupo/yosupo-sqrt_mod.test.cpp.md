---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/number-theory/mod-sqrt.hpp
    title: library/number-theory/mod-sqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nunsigned xrand() {\n\tstatic unsigned x = 314159265, y = 358979323, z = 846264338,\
    \ w = 327950288;\n\tunsigned t = x ^ x << 11; x = y; y = z; z = w; return w =\
    \ w ^ w >> 19 ^ t ^ t >> 8;\n}\n\nlong long mod_inverse(long long a, long long\
    \ m) {\n\tlong long b = m, x = 1, y = 0, t;\n\tfor (; ; ) {\n\t\tt = a / b, a\
    \ -= t * b;\n\t\tif (a == 0) {\n\t\t\tassert(b == 1 || b == -1);\n\t\t\tif ( b==\
    \ -1) y = -y;\n\t\t\treturn (y < 0) ? (y + m) : y;\n\t\t}\n\t\tx -= t * y;\n\t\
    \tt = b / a, b -= t * a;\n\t\tif (b == 0) {\n\t\t\tassert (a == 1 || a == -1);\n\
    \t\t\tif (a == -1) x = -x;\n\t\t\treturn (x < 0) ? (x + m) : x;\n\t\t}\n\t\ty\
    \ -= t * x;\n\t}\n}\n\nint jacobi(long long a, long long m) {\n\tint s = 1;\n\t\
    if (a < 0) a = a % m + m;\n\tfor (; m > 1; ) {\n\t\ta %= m;\n\t\tif (a == 0) return\
    \ 0;\n\t\tconst int r = __builtin_ctz(a);\n\t\tif ((r & 1) && ((m + 2) & 4)) s\
    \ = -s;\n\t\ta >>= r;\n\t\tif (a & m & 2) s = -s;\n\t\tstd::swap(a, m);\n\t}\n\
    \treturn s;\n}\n\nstd::vector<long long> mod_sqrt(long long a, long long p) {\n\
    \tif (p == 2) return {a & 1};\n\tconst int j = jacobi(a, p);\n\tif (j == 0) return\
    \ {0};\n\tif (j == -1) return {};\n\tlong long b, d;\n\tfor (; ; ) {\n\t\tb =\
    \ xrand() % p;\n\t\td = (b * b - a) % p;\n\t\tif (d < 0) d += p;\n\t\tif (jacobi(d,\
    \ p) == -1) break;\n\t}\n\tlong long f0 = b, f1 = 1, g0 = 1, g1 = 0, tmp;\n\t\
    for (long long e = (p + 1) >> 1; e; e >>= 1) {\n\t\tif (e & 1) {\n\t\t\ttmp =\
    \ (g0 * f0 + d * ((g1 * f1) % p)) % p;\n\t\t\tg1 = (g0 * f1 + g1 * f0) % p;\n\t\
    \t\tg0 = tmp;\n\t\t}\n\t\ttmp = (f0 * f0 + d * ((f1 * f1) % p)) % p;\n\t\tf1 =\
    \ (2 * f0 * f1) % p;\n\t\tf0 = tmp;\n\t}\n\treturn (g0 < p - g0) ? std::vector<long\
    \ long>{g0, p - g0} : std::vector<long long>{p - g0, g0};\n}\n\nint main() {\n\
    \tusing namespace std;\n\tint tt; cin >> tt;\n\twhile (tt--) {\n\t\tlong long\
    \ y, p;\n\t\tcin >> y >> p;\n\t\tauto res = mod_sqrt(y, p);\n\t\tif (res.empty())\
    \ cout << -1 << '\\n';\n\t\telse cout << res[0] << '\\n';\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/number-theory/mod-sqrt.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tint tt; cin >> tt;\n\twhile (tt--)\
    \ {\n\t\tlong long y, p;\n\t\tcin >> y >> p;\n\t\tauto res = mod_sqrt(y, p);\n\
    \t\tif (res.empty()) cout << -1 << '\\n';\n\t\telse cout << res[0] << '\\n';\n\
    \t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/number-theory/mod-sqrt.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-sqrt_mod.test.cpp
- /verify/verify/yosupo/yosupo-sqrt_mod.test.cpp.html
title: verify/yosupo/yosupo-sqrt_mod.test.cpp
---

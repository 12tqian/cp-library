---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/modular-arithmetic/mod-sqrt.hpp
    title: library/modular-arithmetic/mod-sqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\r\n\r\
    \n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nunsigned xrand() {\r\n\t\
    static unsigned x = 314159265, y = 358979323, z = 846264338, w = 327950288;\r\n\
    \tunsigned t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^\
    \ t >> 8;\r\n}\r\n\r\nlong long mod_inverse(long long a, long long m) {\r\n\t\
    long long b = m, x = 1, y = 0, t;\r\n\tfor (; ; ) {\r\n\t\tt = a / b, a -= t *\
    \ b;\r\n\t\tif (a == 0) {\r\n\t\t\tassert(b == 1 || b == -1);\r\n\t\t\tif ( b==\
    \ -1) y = -y;\r\n\t\t\treturn (y < 0) ? (y + m) : y;\r\n\t\t}\r\n\t\tx -= t *\
    \ y;\r\n\t\tt = b / a, b -= t * a;\r\n\t\tif (b == 0) {\r\n\t\t\tassert (a ==\
    \ 1 || a == -1);\r\n\t\t\tif (a == -1) x = -x;\r\n\t\t\treturn (x < 0) ? (x +\
    \ m) : x;\r\n\t\t}\r\n\t\ty -= t * x;\r\n\t}\r\n}\r\n\r\nint jacobi(long long\
    \ a, long long m) {\r\n\tint s = 1;\r\n\tif (a < 0) a = a % m + m;\r\n\tfor (;\
    \ m > 1; ) {\r\n\t\ta %= m;\r\n\t\tif (a == 0) return 0;\r\n\t\tconst int r =\
    \ __builtin_ctz(a);\r\n\t\tif ((r & 1) && ((m + 2) & 4)) s = -s;\r\n\t\ta >>=\
    \ r;\r\n\t\tif (a & m & 2) s = -s;\r\n\t\tstd::swap(a, m);\r\n\t}\r\n\treturn\
    \ s;\r\n}\r\n\r\nstd::vector<long long> mod_sqrt(long long a, long long p) {\r\
    \n\tif (p == 2) return {a & 1};\r\n\tconst int j = jacobi(a, p);\r\n\tif (j ==\
    \ 0) return {0};\r\n\tif (j == -1) return {};\r\n\tlong long b, d;\r\n\tfor (;\
    \ ; ) {\r\n\t\tb = xrand() % p;\r\n\t\td = (b * b - a) % p;\r\n\t\tif (d < 0)\
    \ d += p;\r\n\t\tif (jacobi(d, p) == -1) break;\r\n\t}\r\n\tlong long f0 = b,\
    \ f1 = 1, g0 = 1, g1 = 0, tmp;\r\n\tfor (long long e = (p + 1) >> 1; e; e >>=\
    \ 1) {\r\n\t\tif (e & 1) {\r\n\t\t\ttmp = (g0 * f0 + d * ((g1 * f1) % p)) % p;\r\
    \n\t\t\tg1 = (g0 * f1 + g1 * f0) % p;\r\n\t\t\tg0 = tmp;\r\n\t\t}\r\n\t\ttmp =\
    \ (f0 * f0 + d * ((f1 * f1) % p)) % p;\r\n\t\tf1 = (2 * f0 * f1) % p;\r\n\t\t\
    f0 = tmp;\r\n\t}\r\n\treturn (g0 < p - g0) ? std::vector<long long>{g0, p - g0}\
    \ : std::vector<long long>{p - g0, g0};\r\n}\n\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tint tt; cin >> tt;\r\n\twhile (tt--) {\r\n\t\tlong long y, p;\r\n\t\
    \tcin >> y >> p;\r\n\t\tauto res = mod_sqrt(y, p);\r\n\t\tif (res.empty()) cout\
    \ << -1 << '\\n';\r\n\t\telse cout << res[0] << '\\n';\r\n\t}\r\n\treturn 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\r\n\r\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/modular-arithmetic/mod-sqrt.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tint tt; cin >> tt;\r\n\twhile\
    \ (tt--) {\r\n\t\tlong long y, p;\r\n\t\tcin >> y >> p;\r\n\t\tauto res = mod_sqrt(y,\
    \ p);\r\n\t\tif (res.empty()) cout << -1 << '\\n';\r\n\t\telse cout << res[0]\
    \ << '\\n';\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/modular-arithmetic/mod-sqrt.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-sqrt_mod.test.cpp
- /verify/verify/yosupo/yosupo-sqrt_mod.test.cpp.html
title: verify/yosupo/yosupo-sqrt_mod.test.cpp
---

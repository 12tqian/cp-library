---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/numerical/karatsuba.hpp
    title: library/numerical/karatsuba.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\nnamespace\
    \ Karatsuba {\n\nint size(int s) {\n\treturn s > 1 ? 32 - __builtin_clz(s - 1)\
    \ : 0;\n}\n\ntemplate <class T> void karatsuba(T *a, T *b, T *c, T *t, int n)\
    \ {\n\tint ca = 0, cb = 0;\n\tfor (int i = 0; i < n; i++)\n\t\tca += (a[i] !=\
    \ 0), cb += (b[i] != 0);\n\tif (std::min(ca, cb) <= 1500 / n) { // not many multiplications\n\
    \t\tif (ca > cb) \n\t\t\tstd::swap(ca, cb);\n\t\tfor (int i = 0; i < n; i++) \n\
    \t\t\tif (a[i] != 0)\n\t\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\t\tc[i + j]\
    \ += a[i] * b[j];\n\n\t} else {\n\t\tint h = n >> 1;\n\t\tkaratsuba(a, b, c, t,\
    \ h); // a0 * b0\n\t\tkaratsuba(a + h, b + h, c + n, t, h); // a1 * b1\n\t\tfor\
    \ (int i = 0; i < h; i++)\n\t\t\ta[i] += a[i + h], b[i] += b[i + h];\n\t\tkaratsuba(a,\
    \ b, t, t + n, h); // (a0 + a1) * (b0 + b1)\n\t\tfor (int i = 0; i < h; i++)\n\
    \t\t\ta[i] -= a[i + h], b[i] -= b[i + h];\n\t\tfor (int i = 0; i < n; i++)\n\t\
    \t\tt[i] -= c[i] + c[i + n];\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tc[i + h]\
    \ += t[i], t[i] = 0;\n\t}\n}\n\ntemplate <class T> std::vector<T> convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tint sa = (int)a.size(), sb = (int)b.size();\n\tif\
    \ (!sa || !sb) \n\t\treturn {};\n\tint n = (1 << size(std::max(sa, sb)));\n\t\
    a.resize(n);\n\tb.resize(n);\n\tstd::vector<T> c(2 * n), t(2 * n);\n\tkaratsuba(&a[0],\
    \ &b[0], &c[0], &t[0], n);\n\tc.resize(sa + sb - 1);\n\treturn c;\n}\n\n}\n\n\
    int main() {\n\tconst int MOD = 1e9 + 7;\n\tusing namespace Karatsuba;\n\tios_base::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint sa, sb;\n\tcin >> sa >> sb;\n\tvector<long long> a(sa);\n\
    \tfor (int i = 0; i < sa; i++)\n\t\tcin >> a[i];\n\tvector<long long> b(sb);\n\
    \tfor (int i = 0; i < sb; i++)\n\t\tcin >> b[i];\n\tvector<long long> c = convolution<long\
    \ long>(a, b);\n\tfor (int i = 0; i < (int)c.size(); i++)\n\t\tcout << c[i] %\
    \ MOD << \" \";\n\tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/numerical/karatsuba.hpp\"\
    \n\nint main() {\n\tconst int MOD = 1e9 + 7;\n\tusing namespace Karatsuba;\n\t\
    ios_base::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint sa, sb;\n\tcin >>\
    \ sa >> sb;\n\tvector<long long> a(sa);\n\tfor (int i = 0; i < sa; i++)\n\t\t\
    cin >> a[i];\n\tvector<long long> b(sb);\n\tfor (int i = 0; i < sb; i++)\n\t\t\
    cin >> b[i];\n\tvector<long long> c = convolution<long long>(a, b);\n\tfor (int\
    \ i = 0; i < (int)c.size(); i++)\n\t\tcout << c[i] % MOD << \" \";\n\tcout <<\
    \ '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/karatsuba.hpp
  isVerificationFile: true
  path: test/karatsuba.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/karatsuba.test.cpp
layout: document
redirect_from:
- /verify/test/karatsuba.test.cpp
- /verify/test/karatsuba.test.cpp.html
title: test/karatsuba.test.cpp
---

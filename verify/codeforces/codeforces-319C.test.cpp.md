---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/dynamic-programming/monotonic-convex-hull.hpp
    title: Monotonic Convex Hull Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/319/problem/C
    links:
    - https://codeforces.com/contest/319/problem/C
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/319/problem/C\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nconst long long INF = 1e18;\r\
    \n\r\nstruct Line {\r\n\tmutable long long a, b, lst;\r\n\r\n\tlong long eval(long\
    \ long x) {\r\n\t\treturn a * x + b;\r\n\t}\r\n\r\n\tbool operator<(const Line&\
    \ y) const {\r\n\t\treturn a < y.a;\r\n\t}\r\n\r\n\tlong long floor_div(long long\
    \ a, long long b) {\r\n\t\treturn a / b - ((a ^ b) < 0 && a % b);\r\n\t}\r\n\r\
    \n\tlong long bet(const Line& y) {\r\n\t\tassert(a <= y.a);\r\n\t\treturn a ==\
    \ y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);\r\n\t}\r\n};\r\n\
    \r\nstruct ConvexHullDeque : std::deque<Line> {\r\n\tvoid add_back(Line L) {\r\
    \n\t\twhile (true) {\r\n\t\t\tauto a = back();\r\n\t\t\tpop_back();\r\n\t\t\t\
    a.lst = a.bet(L);\r\n\t\t\tif (size() && back().lst >= a.lst) {\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tpush_back(a);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tL.lst = INF;\r\
    \n\t\tpush_back(L);\r\n\t}\r\n\r\n\tvoid add_front(Line L) {\r\n\t\twhile (true)\
    \ {\r\n\t\t\tif (!size()) {\r\n\t\t\t\tL.lst = INF;\r\n\t\t\t\tbreak;\r\n\t\t\t\
    }\r\n\t\t\tif ((L.lst = L.bet(front())) >= front().lst) {\r\n\t\t\t\tpop_front();\r\
    \n\t\t\t} else {\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t\tpush_front(L);\r\
    \n\t}\r\n\r\n\tvoid add(long long a, long long b) {\r\n\t\t// comment this out\
    \ for max\r\n\t\ta = -a; b = -b;\r\n\t\tif (!size() || a <= front().a) {\r\n\t\
    \t\tadd_front({a, b, 0});\r\n\t\t} else {\r\n\t\t\tassert(a >= back().a);\r\n\t\
    \t\tadd_back({a, b, 0});\r\n\t\t}\r\n\t}\r\n\r\n\tint ord = 1; // 1 = increasing,\
    \ -1 = decreasing\r\n\r\n\tlong long query(long long x) {\r\n\t\t// flip negatives\
    \ for max\r\n\t\tassert(ord);\r\n\t\tif (ord == 1) {\r\n\t\t\twhile (front().lst\
    \ < x) {\r\n\t\t\t\tpop_front();\r\n\t\t\t}\r\n\t\t\treturn -front().eval(x);\r\
    \n\t\t} else {\r\n\t\t\twhile (size() > 1 && prev(prev(end()))->lst >= x) {\r\n\
    \t\t\t\tpop_back();\r\n\t\t\t}\r\n\t\t\treturn -back().eval(x);\r\n\t\t}\r\n\t\
    }\r\n};\n\r\n// 189 div 1C\r\nint main() {\r\n\tstd::ios_base::sync_with_stdio(0);\r\
    \n\tstd::cin.tie(0);\r\n\tint n; std::cin >> n;\r\n\tstd::vector<long long> a(n),\
    \ b(n);\r\n\tfor (int i = 0; i < n; i++) std::cin >> a[i];\r\n\tfor (int i = 0;\
    \ i < n; i++) std::cin >> b[i];\r\n\tstd::vector<long long> pre(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) {\r\n\t\tpre[i] = a[i] + (i ? pre[i - 1] : 0);\r\n\t}\r\n\
    \tConvexHullDeque C;\r\n\tstd::vector<long long> dp(n);\r\n\tfor (int i = 0; i\
    \ < n; i++) {\r\n\t\tif (i == 0) {\r\n\t\t\tdp[i] = 0;\r\n\t\t\tC.add(b[i], dp[i]);\r\
    \n\t\t} else {\r\n\t\t\tdp[i] = C.query(a[i]);\r\n\t\t\tC.add(b[i], dp[i]);\r\n\
    \t\t}\r\n\t}\r\n\tstd::cout << dp[n - 1] << '\\n';\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/319/problem/C\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/dynamic-programming/monotonic-convex-hull.hpp\"\
    \r\n\r\n// 189 div 1C\r\nint main() {\r\n\tstd::ios_base::sync_with_stdio(0);\r\
    \n\tstd::cin.tie(0);\r\n\tint n; std::cin >> n;\r\n\tstd::vector<long long> a(n),\
    \ b(n);\r\n\tfor (int i = 0; i < n; i++) std::cin >> a[i];\r\n\tfor (int i = 0;\
    \ i < n; i++) std::cin >> b[i];\r\n\tstd::vector<long long> pre(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) {\r\n\t\tpre[i] = a[i] + (i ? pre[i - 1] : 0);\r\n\t}\r\n\
    \tConvexHullDeque C;\r\n\tstd::vector<long long> dp(n);\r\n\tfor (int i = 0; i\
    \ < n; i++) {\r\n\t\tif (i == 0) {\r\n\t\t\tdp[i] = 0;\r\n\t\t\tC.add(b[i], dp[i]);\r\
    \n\t\t} else {\r\n\t\t\tdp[i] = C.query(a[i]);\r\n\t\t\tC.add(b[i], dp[i]);\r\n\
    \t\t}\r\n\t}\r\n\tstd::cout << dp[n - 1] << '\\n';\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/monotonic-convex-hull.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-319C.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-319C.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-319C.test.cpp
- /verify/verify/codeforces/codeforces-319C.test.cpp.html
title: verify/codeforces/codeforces-319C.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\r\nstruct Line {\r\n  mutable long long a, b, lst;\r\n\r\n  long long eval(long\
    \ long x) { return a * x + b; }\r\n\r\n  bool operator<(const Line& y) const {\
    \ return a < y.a; }\r\n\r\n  long long floor_div(long long a, long long b) {\r\
    \n    return a / b - ((a ^ b) < 0 && a % b);\r\n  }\r\n\r\n  long long bet(const\
    \ Line& y) {\r\n    assert(a <= y.a);\r\n    return a == y.a ? (b >= y.b ? INF\
    \ : -INF) : floor_div(b - y.b, y.a - a);\r\n  }\r\n};\r\n\r\nstruct ConvexHullDeque\
    \ : std::deque<Line> {\r\n  ConvexHullDeque() = default;\r\n\r\n  void add_back(Line\
    \ L) {\r\n    while (true) {\r\n      auto a = back();\r\n      pop_back();\r\n\
    \      a.lst = a.bet(L);\r\n      if (size() && back().lst >= a.lst) {\r\n   \
    \     continue;\r\n      }\r\n      push_back(a);\r\n      break;\r\n    }\r\n\
    \    L.lst = INF;\r\n    push_back(L);\r\n  }\r\n\r\n  void add_front(Line L)\
    \ {\r\n    while (true) {\r\n      if (!size()) {\r\n        L.lst = INF;\r\n\
    \        break;\r\n      }\r\n      if ((L.lst = L.bet(front())) >= front().lst)\
    \ {\r\n        pop_front();\r\n      } else {\r\n        break;\r\n      }\r\n\
    \    }\r\n    push_front(L);\r\n  }\r\n\r\n  void add(long long a, long long b)\
    \ {\r\n    // comment this out for max\r\n    a = -a;\r\n    b = -b;\r\n    if\
    \ (!size() || a <= front().a) {\r\n      add_front({a, b, 0});\r\n    } else {\r\
    \n      assert(a >= back().a);\r\n      add_back({a, b, 0});\r\n    }\r\n  }\r\
    \n\r\n  int ord = 1;  // 1 = increasing, -1 = decreasing\r\n\r\n  long long query(long\
    \ long x) {\r\n    // flip negatives for max\r\n    assert(ord);\r\n    if (ord\
    \ == 1) {\r\n      while (front().lst < x) {\r\n        pop_front();\r\n     \
    \ }\r\n      return -front().eval(x);\r\n    } else {\r\n      while (size() >\
    \ 1 && prev(prev(end()))->lst >= x) {\r\n        pop_back();\r\n      }\r\n  \
    \    return -back().eval(x);\r\n    }\r\n  }\r\n};\n\r\n// 189 div 1C\r\nint main()\
    \ {\r\n\tstd::ios_base::sync_with_stdio(0);\r\n\tstd::cin.tie(0);\r\n\tint n;\
    \ std::cin >> n;\r\n\tstd::vector<long long> a(n), b(n);\r\n\tfor (int i = 0;\
    \ i < n; i++) std::cin >> a[i];\r\n\tfor (int i = 0; i < n; i++) std::cin >> b[i];\r\
    \n\tstd::vector<long long> pre(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\t\
    pre[i] = a[i] + (i ? pre[i - 1] : 0);\r\n\t}\r\n\tConvexHullDeque C;\r\n\tstd::vector<long\
    \ long> dp(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tif (i == 0) {\r\n\t\t\
    \tdp[i] = 0;\r\n\t\t\tC.add(b[i], dp[i]);\r\n\t\t} else {\r\n\t\t\tdp[i] = C.query(a[i]);\r\
    \n\t\t\tC.add(b[i], dp[i]);\r\n\t\t}\r\n\t}\r\n\tstd::cout << dp[n - 1] << '\\\
    n';\r\n\treturn 0;\r\n}\r\n"
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
  timestamp: '2023-01-08 16:36:58-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-319C.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-319C.test.cpp
- /verify/verify/codeforces/codeforces-319C.test.cpp.html
title: verify/codeforces/codeforces-319C.test.cpp
---

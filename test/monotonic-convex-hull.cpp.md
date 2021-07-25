---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':warning:'
    path: library/dynamic-programming/monotonic-convex-hull.hpp
    title: library/dynamic-programming/monotonic-convex-hull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#define IGNORE\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <iostream>\n#include <iomanip>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <vector>\n\
    \nusing namespace std;\n\n// answers min queries currently\n// don't forget to\
    \ change ord\n\nconst long long INF = 1e18;\nstruct Line {\n\tmutable long long\
    \ a, b, lst;\n\n\tlong long eval(long long x) {\n\t\treturn a * x + b;\n\t}\n\n\
    \tbool operator<(const Line &y) const {\n\t\treturn a < y.a;\n\t}\n\n\tlong long\
    \ floor_div(long long a, long long b) {\n\t\treturn a / b - ((a ^ b) < 0 && a\
    \ % b);\n\t}\n\n\tlong long bet(const Line &y) {\n\t\tassert(a <= y.a);\n\t\t\
    return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);\n\t}\n\
    };\n\nstruct ConvexHullDeque : std::deque<Line> {\n\tvoid add_back(Line L) {\n\
    \t\twhile (true) {\n\t\t\tauto a = back();\n\t\t\tpop_back();\n\t\t\ta.lst = a.bet(L);\n\
    \t\t\tif (size() && back().lst >= a.lst) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\t\
    push_back(a);\n\t\t\tbreak;\n\t\t}\n\t\tL.lst = INF;\n\t\tpush_back(L);\n\t}\n\
    \n\tvoid add_front(Line L) {\n\t\twhile (true) {\n\t\t\tif (!size()) {\n\t\t\t\
    \tL.lst = INF;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tif ((L.lst = L.bet(front())) >=\
    \ front().lst) {\n\t\t\t\tpop_front();\n\t\t\t} else {\n\t\t\t\tbreak;\n\t\t\t\
    }\n\t\t}\n\t\tpush_front(L);\n\t}\n\n\tvoid add(long long a, long long b) {\n\t\
    \t// comment this out for max\n\t\ta = -a; b = -b;\n\t\tif (!size() || a <= front().a)\
    \ {\n\t\t\tadd_front({a, b, 0});\n\t\t} else {\n\t\t\tassert(a >= back().a);\n\
    \t\t\tadd_back({a, b, 0});\n\t\t}\n\t}\n\n\tint ord = 1; // 1 = increasing, -1\
    \ = decreasing\n\n\tlong long query(long long x) {\n\t\t// flip negatives for\
    \ max\n\t\tassert(ord);\n\t\tif (ord == 1) {\n\t\t\twhile (front().lst < x) {\n\
    \t\t\t\tpop_front();\n\t\t\t}\n\t\t\treturn -front().eval(x);\n\t\t} else {\n\t\
    \t\twhile (size() > 1 && prev(prev(end()))->lst >= x) {\n\t\t\t\tpop_back();\n\
    \t\t\t}\n\t\t\treturn -back().eval(x);\n\t\t}\n\t}\n};\n\n// 189 div 1C\nint main()\
    \ {\n\tstd::ios_base::sync_with_stdio(0);\n\tstd::cin.tie(0);\n\tint n; std::cin\
    \ >> n;\n\tstd::vector<long long> a(n), b(n);\n\tfor (int i = 0; i < n; i++) std::cin\
    \ >> a[i];\n\tfor (int i = 0; i < n; i++) std::cin >> b[i];\n\tstd::vector<long\
    \ long> pre(n);\n\tfor (int i = 0; i < n; i++) {\n\t\tpre[i] = a[i] + (i ? pre[i\
    \ - 1] : 0);\n\t}\n\tConvexHullDeque C;\n\tstd::vector<long long> dp(n);\n\tfor\
    \ (int i = 0; i < n; i++) {\n\t\tif (i == 0) {\n\t\t\tdp[i] = 0;\n\t\t\tC.add(b[i],\
    \ dp[i]);\n\t\t} else {\n\t\t\tdp[i] = C.query(a[i]);\n\t\t\tC.add(b[i], dp[i]);\n\
    \t\t}\n\t}\n\tstd::cout << dp[n - 1] << '\\n';\n\treturn 0;\n}\n"
  code: "#define IGNORE\n\n#include \"../library/contest/template-minimal.hpp\"\n\
    #include \"../library/dynamic-programming/monotonic-convex-hull.hpp\"\n\n// 189\
    \ div 1C\nint main() {\n\tstd::ios_base::sync_with_stdio(0);\n\tstd::cin.tie(0);\n\
    \tint n; std::cin >> n;\n\tstd::vector<long long> a(n), b(n);\n\tfor (int i =\
    \ 0; i < n; i++) std::cin >> a[i];\n\tfor (int i = 0; i < n; i++) std::cin >>\
    \ b[i];\n\tstd::vector<long long> pre(n);\n\tfor (int i = 0; i < n; i++) {\n\t\
    \tpre[i] = a[i] + (i ? pre[i - 1] : 0);\n\t}\n\tConvexHullDeque C;\n\tstd::vector<long\
    \ long> dp(n);\n\tfor (int i = 0; i < n; i++) {\n\t\tif (i == 0) {\n\t\t\tdp[i]\
    \ = 0;\n\t\t\tC.add(b[i], dp[i]);\n\t\t} else {\n\t\t\tdp[i] = C.query(a[i]);\n\
    \t\t\tC.add(b[i], dp[i]);\n\t\t}\n\t}\n\tstd::cout << dp[n - 1] << '\\n';\n\t\
    return 0;\n}\n"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/dynamic-programming/monotonic-convex-hull.hpp
  isVerificationFile: false
  path: test/monotonic-convex-hull.cpp
  requiredBy: []
  timestamp: '2021-07-24 22:12:48-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/monotonic-convex-hull.cpp
layout: document
redirect_from:
- /library/test/monotonic-convex-hull.cpp
- /library/test/monotonic-convex-hull.cpp.html
title: test/monotonic-convex-hull.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/monotonic-convex-hull.cpp
    title: test/monotonic-convex-hull.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n// answers min queries currently\n// don't forget to change ord\n\
    \nconst long long INF = 1e18;\nstruct Line {\n\tmutable long long a, b, lst;\n\
    \n\tlong long eval(long long x) {\n\t\treturn a * x + b;\n\t}\n\n\tbool operator<(const\
    \ Line &y) const {\n\t\treturn a < y.a;\n\t}\n\n\tlong long floor_div(long long\
    \ a, long long b) {\n\t\treturn a / b - ((a ^ b) < 0 && a % b);\n\t}\n\n\tlong\
    \ long bet(const Line &y) {\n\t\tassert(a <= y.a);\n\t\treturn a == y.a ? (b >=\
    \ y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);\n\t}\n};\n\nstruct ConvexHullDeque\
    \ : std::deque<Line> {\n\tvoid add_back(Line L) {\n\t\twhile (true) {\n\t\t\t\
    auto a = back();\n\t\t\tpop_back();\n\t\t\ta.lst = a.bet(L);\n\t\t\tif (size()\
    \ && back().lst >= a.lst) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tpush_back(a);\n\
    \t\t\tbreak;\n\t\t}\n\t\tL.lst = INF;\n\t\tpush_back(L);\n\t}\n\n\tvoid add_front(Line\
    \ L) {\n\t\twhile (true) {\n\t\t\tif (!size()) {\n\t\t\t\tL.lst = INF;\n\t\t\t\
    \tbreak;\n\t\t\t}\n\t\t\tif ((L.lst = L.bet(front())) >= front().lst) {\n\t\t\t\
    \tpop_front();\n\t\t\t} else {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tpush_front(L);\n\
    \t}\n\n\tvoid add(long long a, long long b) {\n\t\t// comment this out for max\n\
    \t\ta = -a; b = -b;\n\t\tif (!size() || a <= front().a) {\n\t\t\tadd_front({a,\
    \ b, 0});\n\t\t} else {\n\t\t\tassert(a >= back().a);\n\t\t\tadd_back({a, b, 0});\n\
    \t\t}\n\t}\n\n\tint ord = 1; // 1 = increasing, -1 = decreasing\n\n\tlong long\
    \ query(long long x) {\n\t\t// flip negatives for max\n\t\tassert(ord);\n\t\t\
    if (ord == 1) {\n\t\t\twhile (front().lst < x) {\n\t\t\t\tpop_front();\n\t\t\t\
    }\n\t\t\treturn -front().eval(x);\n\t\t} else {\n\t\t\twhile (size() > 1 && prev(prev(end()))->lst\
    \ >= x) {\n\t\t\t\tpop_back();\n\t\t\t}\n\t\t\treturn -back().eval(x);\n\t\t}\n\
    \t}\n};\n"
  code: "#pragma once\n\n// answers min queries currently\n// don't forget to change\
    \ ord\n\nconst long long INF = 1e18;\nstruct Line {\n\tmutable long long a, b,\
    \ lst;\n\n\tlong long eval(long long x) {\n\t\treturn a * x + b;\n\t}\n\n\tbool\
    \ operator<(const Line &y) const {\n\t\treturn a < y.a;\n\t}\n\n\tlong long floor_div(long\
    \ long a, long long b) {\n\t\treturn a / b - ((a ^ b) < 0 && a % b);\n\t}\n\n\t\
    long long bet(const Line &y) {\n\t\tassert(a <= y.a);\n\t\treturn a == y.a ? (b\
    \ >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);\n\t}\n};\n\nstruct ConvexHullDeque\
    \ : std::deque<Line> {\n\tvoid add_back(Line L) {\n\t\twhile (true) {\n\t\t\t\
    auto a = back();\n\t\t\tpop_back();\n\t\t\ta.lst = a.bet(L);\n\t\t\tif (size()\
    \ && back().lst >= a.lst) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tpush_back(a);\n\
    \t\t\tbreak;\n\t\t}\n\t\tL.lst = INF;\n\t\tpush_back(L);\n\t}\n\n\tvoid add_front(Line\
    \ L) {\n\t\twhile (true) {\n\t\t\tif (!size()) {\n\t\t\t\tL.lst = INF;\n\t\t\t\
    \tbreak;\n\t\t\t}\n\t\t\tif ((L.lst = L.bet(front())) >= front().lst) {\n\t\t\t\
    \tpop_front();\n\t\t\t} else {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tpush_front(L);\n\
    \t}\n\n\tvoid add(long long a, long long b) {\n\t\t// comment this out for max\n\
    \t\ta = -a; b = -b;\n\t\tif (!size() || a <= front().a) {\n\t\t\tadd_front({a,\
    \ b, 0});\n\t\t} else {\n\t\t\tassert(a >= back().a);\n\t\t\tadd_back({a, b, 0});\n\
    \t\t}\n\t}\n\n\tint ord = 1; // 1 = increasing, -1 = decreasing\n\n\tlong long\
    \ query(long long x) {\n\t\t// flip negatives for max\n\t\tassert(ord);\n\t\t\
    if (ord == 1) {\n\t\t\twhile (front().lst < x) {\n\t\t\t\tpop_front();\n\t\t\t\
    }\n\t\t\treturn -front().eval(x);\n\t\t} else {\n\t\t\twhile (size() > 1 && prev(prev(end()))->lst\
    \ >= x) {\n\t\t\t\tpop_back();\n\t\t\t}\n\t\t\treturn -back().eval(x);\n\t\t}\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/monotonic-convex-hull.hpp
  requiredBy:
  - test/monotonic-convex-hull.cpp
  timestamp: '2021-07-24 21:49:44-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/monotonic-convex-hull.hpp
layout: document
redirect_from:
- /library/library/dynamic-programming/monotonic-convex-hull.hpp
- /library/library/dynamic-programming/monotonic-convex-hull.hpp.html
title: library/dynamic-programming/monotonic-convex-hull.hpp
---

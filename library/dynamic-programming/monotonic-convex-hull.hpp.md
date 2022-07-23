---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-319C.test.cpp
    title: verify/codeforces/codeforces-319C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nconst long long INF = 1e18;\r\n\r\nstruct Line {\r\n\tmutable\
    \ long long a, b, lst;\r\n\r\n\tlong long eval(long long x) {\r\n\t\treturn a\
    \ * x + b;\r\n\t}\r\n\r\n\tbool operator<(const Line& y) const {\r\n\t\treturn\
    \ a < y.a;\r\n\t}\r\n\r\n\tlong long floor_div(long long a, long long b) {\r\n\
    \t\treturn a / b - ((a ^ b) < 0 && a % b);\r\n\t}\r\n\r\n\tlong long bet(const\
    \ Line& y) {\r\n\t\tassert(a <= y.a);\r\n\t\treturn a == y.a ? (b >= y.b ? INF\
    \ : -INF) : floor_div(b - y.b, y.a - a);\r\n\t}\r\n};\r\n\r\nstruct ConvexHullDeque\
    \ : std::deque<Line> {\r\n\tvoid add_back(Line L) {\r\n\t\twhile (true) {\r\n\t\
    \t\tauto a = back();\r\n\t\t\tpop_back();\r\n\t\t\ta.lst = a.bet(L);\r\n\t\t\t\
    if (size() && back().lst >= a.lst) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\t\
    push_back(a);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tL.lst = INF;\r\n\t\tpush_back(L);\r\
    \n\t}\r\n\r\n\tvoid add_front(Line L) {\r\n\t\twhile (true) {\r\n\t\t\tif (!size())\
    \ {\r\n\t\t\t\tL.lst = INF;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tif ((L.lst =\
    \ L.bet(front())) >= front().lst) {\r\n\t\t\t\tpop_front();\r\n\t\t\t} else {\r\
    \n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t\tpush_front(L);\r\n\t}\r\n\r\n\tvoid\
    \ add(long long a, long long b) {\r\n\t\t// comment this out for max\r\n\t\ta\
    \ = -a; b = -b;\r\n\t\tif (!size() || a <= front().a) {\r\n\t\t\tadd_front({a,\
    \ b, 0});\r\n\t\t} else {\r\n\t\t\tassert(a >= back().a);\r\n\t\t\tadd_back({a,\
    \ b, 0});\r\n\t\t}\r\n\t}\r\n\r\n\tint ord = 1; // 1 = increasing, -1 = decreasing\r\
    \n\r\n\tlong long query(long long x) {\r\n\t\t// flip negatives for max\r\n\t\t\
    assert(ord);\r\n\t\tif (ord == 1) {\r\n\t\t\twhile (front().lst < x) {\r\n\t\t\
    \t\tpop_front();\r\n\t\t\t}\r\n\t\t\treturn -front().eval(x);\r\n\t\t} else {\r\
    \n\t\t\twhile (size() > 1 && prev(prev(end()))->lst >= x) {\r\n\t\t\t\tpop_back();\r\
    \n\t\t\t}\r\n\t\t\treturn -back().eval(x);\r\n\t\t}\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nconst long long INF = 1e18;\r\n\r\nstruct Line {\r\n\t\
    mutable long long a, b, lst;\r\n\r\n\tlong long eval(long long x) {\r\n\t\treturn\
    \ a * x + b;\r\n\t}\r\n\r\n\tbool operator<(const Line& y) const {\r\n\t\treturn\
    \ a < y.a;\r\n\t}\r\n\r\n\tlong long floor_div(long long a, long long b) {\r\n\
    \t\treturn a / b - ((a ^ b) < 0 && a % b);\r\n\t}\r\n\r\n\tlong long bet(const\
    \ Line& y) {\r\n\t\tassert(a <= y.a);\r\n\t\treturn a == y.a ? (b >= y.b ? INF\
    \ : -INF) : floor_div(b - y.b, y.a - a);\r\n\t}\r\n};\r\n\r\nstruct ConvexHullDeque\
    \ : std::deque<Line> {\r\n\tvoid add_back(Line L) {\r\n\t\twhile (true) {\r\n\t\
    \t\tauto a = back();\r\n\t\t\tpop_back();\r\n\t\t\ta.lst = a.bet(L);\r\n\t\t\t\
    if (size() && back().lst >= a.lst) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\t\
    push_back(a);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tL.lst = INF;\r\n\t\tpush_back(L);\r\
    \n\t}\r\n\r\n\tvoid add_front(Line L) {\r\n\t\twhile (true) {\r\n\t\t\tif (!size())\
    \ {\r\n\t\t\t\tL.lst = INF;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tif ((L.lst =\
    \ L.bet(front())) >= front().lst) {\r\n\t\t\t\tpop_front();\r\n\t\t\t} else {\r\
    \n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t\tpush_front(L);\r\n\t}\r\n\r\n\tvoid\
    \ add(long long a, long long b) {\r\n\t\t// comment this out for max\r\n\t\ta\
    \ = -a; b = -b;\r\n\t\tif (!size() || a <= front().a) {\r\n\t\t\tadd_front({a,\
    \ b, 0});\r\n\t\t} else {\r\n\t\t\tassert(a >= back().a);\r\n\t\t\tadd_back({a,\
    \ b, 0});\r\n\t\t}\r\n\t}\r\n\r\n\tint ord = 1; // 1 = increasing, -1 = decreasing\r\
    \n\r\n\tlong long query(long long x) {\r\n\t\t// flip negatives for max\r\n\t\t\
    assert(ord);\r\n\t\tif (ord == 1) {\r\n\t\t\twhile (front().lst < x) {\r\n\t\t\
    \t\tpop_front();\r\n\t\t\t}\r\n\t\t\treturn -front().eval(x);\r\n\t\t} else {\r\
    \n\t\t\twhile (size() > 1 && prev(prev(end()))->lst >= x) {\r\n\t\t\t\tpop_back();\r\
    \n\t\t\t}\r\n\t\t\treturn -back().eval(x);\r\n\t\t}\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/monotonic-convex-hull.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-319C.test.cpp
documentation_of: library/dynamic-programming/monotonic-convex-hull.hpp
layout: document
title: Monotonic Convex Hull Trick
---

## Monotonic Convex Hull Trick

I should make this general for not just `long long`. 

### Assumptions
- Currently asssumes we're answering minimum queries. This can be changed with negative signs. 
- Also currently assumes the queries are in increasing order. You can flip this by changing $ord$ to $1$ or $-1$. 
- Assumes you add lines in monotonic slope order. 

### Functions
- `add(a, b)`: Adds line to hull with slope `a` and $y$-intercept `b` in $\mathcal O(1)$. 
- `query(x)`: Finds minimum at `x` in $\mathcal O(1)$. 

### Variables
- `ord`: determines whether queries are in increasing or decreasing order. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/4aa96cd195a770c3a7f8977441020036d84b4f24/Implementations/content/data-structures/STL%20(5)/LCDeque.h)
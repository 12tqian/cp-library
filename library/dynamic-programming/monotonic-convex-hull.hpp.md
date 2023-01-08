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
  bundledCode: "\r\nconst long long INF = 1e18;\r\n\r\nstruct Line {\r\n  mutable\
    \ long long a, b, lst;\r\n\r\n  long long eval(long long x) { return a * x + b;\
    \ }\r\n\r\n  bool operator<(const Line& y) const { return a < y.a; }\r\n\r\n \
    \ long long floor_div(long long a, long long b) {\r\n    return a / b - ((a ^\
    \ b) < 0 && a % b);\r\n  }\r\n\r\n  long long bet(const Line& y) {\r\n    assert(a\
    \ <= y.a);\r\n    return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b,\
    \ y.a - a);\r\n  }\r\n};\r\n\r\nstruct ConvexHullDeque : std::deque<Line> {\r\n\
    \  ConvexHullDeque() = default;\r\n\r\n  void add_back(Line L) {\r\n    while\
    \ (true) {\r\n      auto a = back();\r\n      pop_back();\r\n      a.lst = a.bet(L);\r\
    \n      if (size() && back().lst >= a.lst) {\r\n        continue;\r\n      }\r\
    \n      push_back(a);\r\n      break;\r\n    }\r\n    L.lst = INF;\r\n    push_back(L);\r\
    \n  }\r\n\r\n  void add_front(Line L) {\r\n    while (true) {\r\n      if (!size())\
    \ {\r\n        L.lst = INF;\r\n        break;\r\n      }\r\n      if ((L.lst =\
    \ L.bet(front())) >= front().lst) {\r\n        pop_front();\r\n      } else {\r\
    \n        break;\r\n      }\r\n    }\r\n    push_front(L);\r\n  }\r\n\r\n  void\
    \ add(long long a, long long b) {\r\n    // comment this out for max\r\n    a\
    \ = -a;\r\n    b = -b;\r\n    if (!size() || a <= front().a) {\r\n      add_front({a,\
    \ b, 0});\r\n    } else {\r\n      assert(a >= back().a);\r\n      add_back({a,\
    \ b, 0});\r\n    }\r\n  }\r\n\r\n  int ord = 1;  // 1 = increasing, -1 = decreasing\r\
    \n\r\n  long long query(long long x) {\r\n    // flip negatives for max\r\n  \
    \  assert(ord);\r\n    if (ord == 1) {\r\n      while (front().lst < x) {\r\n\
    \        pop_front();\r\n      }\r\n      return -front().eval(x);\r\n    } else\
    \ {\r\n      while (size() > 1 && prev(prev(end()))->lst >= x) {\r\n        pop_back();\r\
    \n      }\r\n      return -back().eval(x);\r\n    }\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\nconst long long INF = 1e18;\r\n\r\nstruct Line {\r\n\
    \  mutable long long a, b, lst;\r\n\r\n  long long eval(long long x) { return\
    \ a * x + b; }\r\n\r\n  bool operator<(const Line& y) const { return a < y.a;\
    \ }\r\n\r\n  long long floor_div(long long a, long long b) {\r\n    return a /\
    \ b - ((a ^ b) < 0 && a % b);\r\n  }\r\n\r\n  long long bet(const Line& y) {\r\
    \n    assert(a <= y.a);\r\n    return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b\
    \ - y.b, y.a - a);\r\n  }\r\n};\r\n\r\nstruct ConvexHullDeque : std::deque<Line>\
    \ {\r\n  ConvexHullDeque() = default;\r\n\r\n  void add_back(Line L) {\r\n   \
    \ while (true) {\r\n      auto a = back();\r\n      pop_back();\r\n      a.lst\
    \ = a.bet(L);\r\n      if (size() && back().lst >= a.lst) {\r\n        continue;\r\
    \n      }\r\n      push_back(a);\r\n      break;\r\n    }\r\n    L.lst = INF;\r\
    \n    push_back(L);\r\n  }\r\n\r\n  void add_front(Line L) {\r\n    while (true)\
    \ {\r\n      if (!size()) {\r\n        L.lst = INF;\r\n        break;\r\n    \
    \  }\r\n      if ((L.lst = L.bet(front())) >= front().lst) {\r\n        pop_front();\r\
    \n      } else {\r\n        break;\r\n      }\r\n    }\r\n    push_front(L);\r\
    \n  }\r\n\r\n  void add(long long a, long long b) {\r\n    // comment this out\
    \ for max\r\n    a = -a;\r\n    b = -b;\r\n    if (!size() || a <= front().a)\
    \ {\r\n      add_front({a, b, 0});\r\n    } else {\r\n      assert(a >= back().a);\r\
    \n      add_back({a, b, 0});\r\n    }\r\n  }\r\n\r\n  int ord = 1;  // 1 = increasing,\
    \ -1 = decreasing\r\n\r\n  long long query(long long x) {\r\n    // flip negatives\
    \ for max\r\n    assert(ord);\r\n    if (ord == 1) {\r\n      while (front().lst\
    \ < x) {\r\n        pop_front();\r\n      }\r\n      return -front().eval(x);\r\
    \n    } else {\r\n      while (size() > 1 && prev(prev(end()))->lst >= x) {\r\n\
    \        pop_back();\r\n      }\r\n      return -back().eval(x);\r\n    }\r\n\
    \  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/monotonic-convex-hull.hpp
  requiredBy: []
  timestamp: '2023-01-08 16:36:58-05:00'
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
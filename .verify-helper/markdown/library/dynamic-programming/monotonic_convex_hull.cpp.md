---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/monotonic_convex_hull.cpp\"\n\
    #include<bits/stdc++.h>\r\n// answers min queries currently\r\n// don't forget\
    \ to change ord\r\n\r\nconst long long INF = 1e18;\r\nstruct Line {\r\n    mutable\
    \ long long a, b, lst;\r\n    long long eval(long long x) {\r\n        return\
    \ a * x + b;\r\n    }\r\n    bool operator < (const Line& y) const {\r\n     \
    \   return a < y.a;\r\n    }\r\n    long long floor_div(long long a, long long\
    \ b) {\r\n        return a / b - ((a ^ b) < 0 && a % b);\r\n    }\r\n    long\
    \ long bet(const Line& y) {\r\n        assert(a <= y.a);\r\n        return a ==\
    \ y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);\r\n    }\r\n};\r\
    \nstruct ConvexHullDeque : std::deque<Line> {\r\n    void add_back(Line L) {\r\
    \n        while (true) {\r\n            auto a = back();\r\n            pop_back();\r\
    \n            a.lst = a.bet(L);\r\n            if (size() && back().lst >= a.lst)\
    \ {\r\n                continue;\r\n            }\r\n            push_back(a);\r\
    \n            break;\r\n        }\r\n        L.lst = INF;\r\n        push_back(L);\r\
    \n    }\r\n    void add_front(Line L) {\r\n        while (true) {\r\n        \
    \    if (!size()) {\r\n                L.lst = INF;\r\n                break;\r\
    \n            }\r\n            if ((L.lst = L.bet(front())) >= front().lst) {\r\
    \n                pop_front();\r\n            } else {\r\n                break;\r\
    \n            }\r\n        }\r\n        push_front(L);\r\n    }\r\n    void add(long\
    \ long a, long long b) {\r\n        // comment this out for max\r\n        a =\
    \ -a; b = -b;\r\n        if (!size() || a <= front().a) {\r\n            add_front({a,\
    \ b, 0});\r\n        } else {\r\n            assert(a >= back().a);\r\n      \
    \      add_back({a, b, 0});\r\n        }\r\n    }\r\n    int ord = 1; // 1 = increasing,\
    \ -1 = decreasing\r\n    long long query(long long x) {\r\n        // flip negatives\
    \ for max\r\n        assert(ord);\r\n        if (ord == 1) {\r\n            while\
    \ (front().lst < x) {\r\n                pop_front();\r\n            }\r\n   \
    \         return -front().eval(x);\r\n        } else {\r\n            while (size()\
    \ > 1 && prev(prev(end()))-> lst >= x) {\r\n                pop_back();\r\n  \
    \          }\r\n            return -back().eval(x);\r\n        }\r\n    }\r\n\
    };\r\n\r\n// 189 div 1C\r\nint main() {\r\n    std::ios_base::sync_with_stdio(0);\r\
    \n    std::cin.tie(0);\r\n    int n; std::cin >> n;\r\n    std::vector<long long>\
    \ a(n), b(n);\r\n    for (int i = 0; i < n; i++) std::cin >> a[i];\r\n    for\
    \ (int i = 0; i < n; i++) std::cin >> b[i];\r\n    std::vector<long long> pre(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        pre[i] = a[i] + (i ? pre[i - 1]\
    \ : 0);\r\n    }\r\n    ConvexHullDeque C;\r\n    std::vector<long long> dp(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        if (i == 0) {\r\n            dp[i]\
    \ = 0;\r\n            C.add(b[i], dp[i]);\r\n        } else {\r\n            dp[i]\
    \ = C.query(a[i]);\r\n            C.add(b[i], dp[i]);\r\n        }\r\n    }\r\n\
    \    std::cout << dp[n - 1] << '\\n';\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n// answers min queries currently\r\n// don't forget\
    \ to change ord\r\n\r\nconst long long INF = 1e18;\r\nstruct Line {\r\n    mutable\
    \ long long a, b, lst;\r\n    long long eval(long long x) {\r\n        return\
    \ a * x + b;\r\n    }\r\n    bool operator < (const Line& y) const {\r\n     \
    \   return a < y.a;\r\n    }\r\n    long long floor_div(long long a, long long\
    \ b) {\r\n        return a / b - ((a ^ b) < 0 && a % b);\r\n    }\r\n    long\
    \ long bet(const Line& y) {\r\n        assert(a <= y.a);\r\n        return a ==\
    \ y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);\r\n    }\r\n};\r\
    \nstruct ConvexHullDeque : std::deque<Line> {\r\n    void add_back(Line L) {\r\
    \n        while (true) {\r\n            auto a = back();\r\n            pop_back();\r\
    \n            a.lst = a.bet(L);\r\n            if (size() && back().lst >= a.lst)\
    \ {\r\n                continue;\r\n            }\r\n            push_back(a);\r\
    \n            break;\r\n        }\r\n        L.lst = INF;\r\n        push_back(L);\r\
    \n    }\r\n    void add_front(Line L) {\r\n        while (true) {\r\n        \
    \    if (!size()) {\r\n                L.lst = INF;\r\n                break;\r\
    \n            }\r\n            if ((L.lst = L.bet(front())) >= front().lst) {\r\
    \n                pop_front();\r\n            } else {\r\n                break;\r\
    \n            }\r\n        }\r\n        push_front(L);\r\n    }\r\n    void add(long\
    \ long a, long long b) {\r\n        // comment this out for max\r\n        a =\
    \ -a; b = -b;\r\n        if (!size() || a <= front().a) {\r\n            add_front({a,\
    \ b, 0});\r\n        } else {\r\n            assert(a >= back().a);\r\n      \
    \      add_back({a, b, 0});\r\n        }\r\n    }\r\n    int ord = 1; // 1 = increasing,\
    \ -1 = decreasing\r\n    long long query(long long x) {\r\n        // flip negatives\
    \ for max\r\n        assert(ord);\r\n        if (ord == 1) {\r\n            while\
    \ (front().lst < x) {\r\n                pop_front();\r\n            }\r\n   \
    \         return -front().eval(x);\r\n        } else {\r\n            while (size()\
    \ > 1 && prev(prev(end()))-> lst >= x) {\r\n                pop_back();\r\n  \
    \          }\r\n            return -back().eval(x);\r\n        }\r\n    }\r\n\
    };\r\n\r\n// 189 div 1C\r\nint main() {\r\n    std::ios_base::sync_with_stdio(0);\r\
    \n    std::cin.tie(0);\r\n    int n; std::cin >> n;\r\n    std::vector<long long>\
    \ a(n), b(n);\r\n    for (int i = 0; i < n; i++) std::cin >> a[i];\r\n    for\
    \ (int i = 0; i < n; i++) std::cin >> b[i];\r\n    std::vector<long long> pre(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        pre[i] = a[i] + (i ? pre[i - 1]\
    \ : 0);\r\n    }\r\n    ConvexHullDeque C;\r\n    std::vector<long long> dp(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        if (i == 0) {\r\n            dp[i]\
    \ = 0;\r\n            C.add(b[i], dp[i]);\r\n        } else {\r\n            dp[i]\
    \ = C.query(a[i]);\r\n            C.add(b[i], dp[i]);\r\n        }\r\n    }\r\n\
    \    std::cout << dp[n - 1] << '\\n';\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/monotonic_convex_hull.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:09:02-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/monotonic_convex_hull.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/monotonic_convex_hull.cpp
- /library/library/dynamic-programming/monotonic_convex_hull.cpp.html
title: library/dynamic-programming/monotonic_convex_hull.cpp
---

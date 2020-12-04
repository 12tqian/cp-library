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
    #include<bits/stdc++.h>\n// answers min queries currently\n// don't forget to\
    \ change ord\n\nconst long long INF = 1e18;\nstruct Line {\n    mutable long long\
    \ a, b, lst;\n    long long eval(long long x) {\n        return a * x + b;\n \
    \   }\n    bool operator < (const Line& y) const {\n        return a < y.a;\n\
    \    }\n    long long floor_div(long long a, long long b) {\n        return a\
    \ / b - ((a ^ b) < 0 && a % b);\n    }\n    long long bet(const Line& y) {\n \
    \       assert(a <= y.a);\n        return a == y.a ? (b >= y.b ? INF : -INF) :\
    \ floor_div(b - y.b, y.a - a);\n    }\n};\nstruct ConvexHullDeque : std::deque<Line>\
    \ {\n    void add_back(Line L) {\n        while (true) {\n            auto a =\
    \ back();\n            pop_back();\n            a.lst = a.bet(L);\n          \
    \  if (size() && back().lst >= a.lst) {\n                continue;\n         \
    \   }\n            push_back(a);\n            break;\n        }\n        L.lst\
    \ = INF;\n        push_back(L);\n    }\n    void add_front(Line L) {\n       \
    \ while (true) {\n            if (!size()) {\n                L.lst = INF;\n \
    \               break;\n            }\n            if ((L.lst = L.bet(front()))\
    \ >= front().lst) {\n                pop_front();\n            } else {\n    \
    \            break;\n            }\n        }\n        push_front(L);\n    }\n\
    \    void add(long long a, long long b) {\n        // comment this out for max\n\
    \        a = -a; b = -b;\n        if (!size() || a <= front().a) {\n         \
    \   add_front({a, b, 0});\n        } else {\n            assert(a >= back().a);\n\
    \            add_back({a, b, 0});\n        }\n    }\n    int ord = 1; // 1 = increasing,\
    \ -1 = decreasing\n    long long query(long long x) {\n        // flip negatives\
    \ for max\n        assert(ord);\n        if (ord == 1) {\n            while (front().lst\
    \ < x) {\n                pop_front();\n            }\n            return -front().eval(x);\n\
    \        } else {\n            while (size() > 1 && prev(prev(end()))-> lst >=\
    \ x) {\n                pop_back();\n            }\n            return -back().eval(x);\n\
    \        }\n    }\n};\n\n// 189 div 1C\nint main() {\n    std::ios_base::sync_with_stdio(0);\n\
    \    std::cin.tie(0);\n    int n; std::cin >> n;\n    std::vector<long long> a(n),\
    \ b(n);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int i = 0;\
    \ i < n; i++) std::cin >> b[i];\n    std::vector<long long> pre(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        pre[i] = a[i] + (i ? pre[i - 1] : 0);\n    }\n\
    \    ConvexHullDeque C;\n    std::vector<long long> dp(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (i == 0) {\n            dp[i] = 0;\n            C.add(b[i],\
    \ dp[i]);\n        } else {\n            dp[i] = C.query(a[i]);\n            C.add(b[i],\
    \ dp[i]);\n        }\n    }\n    std::cout << dp[n - 1] << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#include<bits/stdc++.h>\n// answers min queries currently\n// don't forget\
    \ to change ord\n\nconst long long INF = 1e18;\nstruct Line {\n    mutable long\
    \ long a, b, lst;\n    long long eval(long long x) {\n        return a * x + b;\n\
    \    }\n    bool operator < (const Line& y) const {\n        return a < y.a;\n\
    \    }\n    long long floor_div(long long a, long long b) {\n        return a\
    \ / b - ((a ^ b) < 0 && a % b);\n    }\n    long long bet(const Line& y) {\n \
    \       assert(a <= y.a);\n        return a == y.a ? (b >= y.b ? INF : -INF) :\
    \ floor_div(b - y.b, y.a - a);\n    }\n};\nstruct ConvexHullDeque : std::deque<Line>\
    \ {\n    void add_back(Line L) {\n        while (true) {\n            auto a =\
    \ back();\n            pop_back();\n            a.lst = a.bet(L);\n          \
    \  if (size() && back().lst >= a.lst) {\n                continue;\n         \
    \   }\n            push_back(a);\n            break;\n        }\n        L.lst\
    \ = INF;\n        push_back(L);\n    }\n    void add_front(Line L) {\n       \
    \ while (true) {\n            if (!size()) {\n                L.lst = INF;\n \
    \               break;\n            }\n            if ((L.lst = L.bet(front()))\
    \ >= front().lst) {\n                pop_front();\n            } else {\n    \
    \            break;\n            }\n        }\n        push_front(L);\n    }\n\
    \    void add(long long a, long long b) {\n        // comment this out for max\n\
    \        a = -a; b = -b;\n        if (!size() || a <= front().a) {\n         \
    \   add_front({a, b, 0});\n        } else {\n            assert(a >= back().a);\n\
    \            add_back({a, b, 0});\n        }\n    }\n    int ord = 1; // 1 = increasing,\
    \ -1 = decreasing\n    long long query(long long x) {\n        // flip negatives\
    \ for max\n        assert(ord);\n        if (ord == 1) {\n            while (front().lst\
    \ < x) {\n                pop_front();\n            }\n            return -front().eval(x);\n\
    \        } else {\n            while (size() > 1 && prev(prev(end()))-> lst >=\
    \ x) {\n                pop_back();\n            }\n            return -back().eval(x);\n\
    \        }\n    }\n};\n\n// 189 div 1C\nint main() {\n    std::ios_base::sync_with_stdio(0);\n\
    \    std::cin.tie(0);\n    int n; std::cin >> n;\n    std::vector<long long> a(n),\
    \ b(n);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int i = 0;\
    \ i < n; i++) std::cin >> b[i];\n    std::vector<long long> pre(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        pre[i] = a[i] + (i ? pre[i - 1] : 0);\n    }\n\
    \    ConvexHullDeque C;\n    std::vector<long long> dp(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (i == 0) {\n            dp[i] = 0;\n            C.add(b[i],\
    \ dp[i]);\n        } else {\n            dp[i] = C.query(a[i]);\n            C.add(b[i],\
    \ dp[i]);\n        }\n    }\n    std::cout << dp[n - 1] << '\\n';\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/monotonic_convex_hull.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/monotonic_convex_hull.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/monotonic_convex_hull.cpp
- /library/library/dynamic-programming/monotonic_convex_hull.cpp.html
title: library/dynamic-programming/monotonic_convex_hull.cpp
---

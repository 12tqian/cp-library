---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/dynamic_convex_hull_trick.cpp\"\
    \n#include<bits/stdc++.h>\n\nconst long long INF = 1e18;\n\nstruct ConvexHullTrick\
    \ {\n    // modified for minimums\n    struct line {\n        long long m, b;\
    \ long double x, val;\n        bool is_query;\n\n        line(long long _m = 0,\
    \ long long _b = 0){\n            m = _m, b = _b, val = 0, x = -INF, is_query\
    \ = false;\n        }\n\n        long long eval(long long x) const { return m\
    \ * x + b; }\n        bool parallel(const line &l) const { return m == l.m; }\n\
    \        long double intersect(const line &l) const {\n            return parallel(l)\
    \ ? INF : 1.0 * (l.b - b) / (m - l.m);\n        }\n\n        bool operator < (const\
    \ line &l) const {\n            if (l.is_query) return x < l.val;\n          \
    \  else return m < l.m;\n        }\n    };\n\n    std::set<line> hull;\n\n   \
    \ bool hull_prev(std::set<line>::iterator it) { return it != hull.begin(); }\n\
    \    bool hull_next(std::set<line>::iterator it) { return it != hull.end() &&\
    \ next(it) != hull.end(); }\n    bool bad(const line &l1, const line &l2, const\
    \ line &l3) { return l1.intersect(l3) <= l1.intersect(l2); }\n    bool bad(std::set<line>::iterator\
    \ it) { return hull_prev(it) && hull_next(it) && bad(*prev(it), *it, *next(it));\
    \ }\n\n    std::set<line>::iterator update(std::set<line>::iterator it) {\n  \
    \      if (!hull_prev(it)) return it;\n        long double x = it->intersect(*prev(it));\n\
    \        line tmp(*it); tmp.x = x;\n        it = hull.erase(it);\n        return\
    \ hull.insert(it, tmp);\n    }\n\n    void add_line(long long m, long long b)\
    \ {\n        m = -m, b = -b;\n        line l(m, b);\n        std::set<line>::iterator\
    \ it = hull.lower_bound(l);\n        if (it != hull.end() && l.parallel(*it))\
    \ {\n            if(it->b < b) it = hull.erase(it);\n            else return;\n\
    \        }\n        it = hull.insert(it, l);\n        if (bad(it)) return (void)\
    \ hull.erase(it);\n        while (hull_prev(it) && bad(prev(it))) hull.erase(prev(it));\n\
    \        while (hull_next(it) && bad(next(it))) hull.erase(next(it));\n      \
    \  it = update(it);\n        if (hull_prev(it)) update(prev(it));\n        if\
    \ (hull_next(it)) update(next(it));\n    }\n    \n    long long query(long long\
    \ x) const {\n        if (hull.empty()) return INF;\n        line q; q.val = x,\
    \ q.is_query = 1;\n        std::set<line>::iterator it = --hull.lower_bound(q);\n\
    \        return -(it->eval(x));\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nconst long long INF = 1e18;\n\nstruct ConvexHullTrick\
    \ {\n    // modified for minimums\n    struct line {\n        long long m, b;\
    \ long double x, val;\n        bool is_query;\n\n        line(long long _m = 0,\
    \ long long _b = 0){\n            m = _m, b = _b, val = 0, x = -INF, is_query\
    \ = false;\n        }\n\n        long long eval(long long x) const { return m\
    \ * x + b; }\n        bool parallel(const line &l) const { return m == l.m; }\n\
    \        long double intersect(const line &l) const {\n            return parallel(l)\
    \ ? INF : 1.0 * (l.b - b) / (m - l.m);\n        }\n\n        bool operator < (const\
    \ line &l) const {\n            if (l.is_query) return x < l.val;\n          \
    \  else return m < l.m;\n        }\n    };\n\n    std::set<line> hull;\n\n   \
    \ bool hull_prev(std::set<line>::iterator it) { return it != hull.begin(); }\n\
    \    bool hull_next(std::set<line>::iterator it) { return it != hull.end() &&\
    \ next(it) != hull.end(); }\n    bool bad(const line &l1, const line &l2, const\
    \ line &l3) { return l1.intersect(l3) <= l1.intersect(l2); }\n    bool bad(std::set<line>::iterator\
    \ it) { return hull_prev(it) && hull_next(it) && bad(*prev(it), *it, *next(it));\
    \ }\n\n    std::set<line>::iterator update(std::set<line>::iterator it) {\n  \
    \      if (!hull_prev(it)) return it;\n        long double x = it->intersect(*prev(it));\n\
    \        line tmp(*it); tmp.x = x;\n        it = hull.erase(it);\n        return\
    \ hull.insert(it, tmp);\n    }\n\n    void add_line(long long m, long long b)\
    \ {\n        m = -m, b = -b;\n        line l(m, b);\n        std::set<line>::iterator\
    \ it = hull.lower_bound(l);\n        if (it != hull.end() && l.parallel(*it))\
    \ {\n            if(it->b < b) it = hull.erase(it);\n            else return;\n\
    \        }\n        it = hull.insert(it, l);\n        if (bad(it)) return (void)\
    \ hull.erase(it);\n        while (hull_prev(it) && bad(prev(it))) hull.erase(prev(it));\n\
    \        while (hull_next(it) && bad(next(it))) hull.erase(next(it));\n      \
    \  it = update(it);\n        if (hull_prev(it)) update(prev(it));\n        if\
    \ (hull_next(it)) update(next(it));\n    }\n    \n    long long query(long long\
    \ x) const {\n        if (hull.empty()) return INF;\n        line q; q.val = x,\
    \ q.is_query = 1;\n        std::set<line>::iterator it = --hull.lower_bound(q);\n\
    \        return -(it->eval(x));\n    }\n};\n\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/dynamic_convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/dynamic_convex_hull_trick.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/dynamic_convex_hull_trick.cpp
- /library/library/dynamic-programming/dynamic_convex_hull_trick.cpp.html
title: library/dynamic-programming/dynamic_convex_hull_trick.cpp
---

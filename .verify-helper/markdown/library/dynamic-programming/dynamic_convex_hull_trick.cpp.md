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
    \n#include<bits/stdc++.h>\r\n\r\nconst long long INF = 1e18;\r\nstruct ConvexHullTrick\
    \ {\r\n    // modified for minimums\r\n    struct line {\r\n        long long\
    \ m, b; long double x, val;\r\n        bool is_query;\r\n        line(long long\
    \ _m = 0, long long _b = 0){\r\n            m = _m, b = _b, val = 0, x = -INF,\
    \ is_query = false;\r\n        }\r\n        long long eval(long long x) const\
    \ { return m * x + b; }\r\n        bool parallel(const line &l) const { return\
    \ m == l.m; }\r\n        long double intersect(const line &l) const {\r\n    \
    \        return parallel(l) ? INF : 1.0 * (l.b - b) / (m - l.m);\r\n        }\r\
    \n        bool operator < (const line &l) const {\r\n            if(l.is_query)\
    \ return x < l.val;\r\n            else return m < l.m;\r\n        }\r\n    };\r\
    \n    std::set<line> hull;\r\n    bool hull_prev(std::set<line> :: iterator it)\
    \ { return it != hull.begin(); }\r\n    bool hull_next(std::set<line> :: iterator\
    \ it) { return it != hull.end() && next(it) != hull.end(); }\r\n    bool bad(const\
    \ line &l1, const line &l2, const line &l3) { return l1.intersect(l3) <= l1.intersect(l2);\
    \ }\r\n    bool bad(std::set<line> :: iterator it) { return hull_prev(it) && hull_next(it)\
    \ && bad(*prev(it), *it, *next(it)); }\r\n    std::set<line> :: iterator update(std::set<line>\
    \ :: iterator it) {\r\n        if(!hull_prev(it)) return it;\r\n        long double\
    \ x = it -> intersect(*prev(it));\r\n        line tmp(*it); tmp.x = x;\r\n   \
    \     it = hull.erase(it);\r\n        return hull.insert(it, tmp);\r\n    }\r\n\
    \    void add_line(long long m, long long b) {\r\n        m = -m, b = -b;\r\n\
    \        line l(m, b);\r\n        std::set<line> :: iterator it = hull.lower_bound(l);\r\
    \n        if(it != hull.end() && l.parallel(*it)) {\r\n            if(it -> b\
    \ < b) it = hull.erase(it);\r\n            else return;\r\n        }\r\n     \
    \   it = hull.insert(it, l);\r\n        if(bad(it)) return (void) hull.erase(it);\r\
    \n        while(hull_prev(it) && bad(prev(it))) hull.erase(prev(it));\r\n    \
    \    while(hull_next(it) && bad(next(it))) hull.erase(next(it));\r\n        it\
    \ = update(it);\r\n        if(hull_prev(it)) update(prev(it));\r\n        if(hull_next(it))\
    \ update(next(it));\r\n    }\r\n    long long query(long long x) const {\r\n \
    \       if(hull.empty()) return INF;\r\n        line q; q.val = x, q.is_query\
    \ = 1;\r\n        std::set<line> :: iterator it = --hull.lower_bound(q);\r\n \
    \       return -(it -> eval(x));\r\n    }\r\n};\r\n\r\nint main() {\r\n    return\
    \ 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\nconst long long INF = 1e18;\r\nstruct ConvexHullTrick\
    \ {\r\n    // modified for minimums\r\n    struct line {\r\n        long long\
    \ m, b; long double x, val;\r\n        bool is_query;\r\n        line(long long\
    \ _m = 0, long long _b = 0){\r\n            m = _m, b = _b, val = 0, x = -INF,\
    \ is_query = false;\r\n        }\r\n        long long eval(long long x) const\
    \ { return m * x + b; }\r\n        bool parallel(const line &l) const { return\
    \ m == l.m; }\r\n        long double intersect(const line &l) const {\r\n    \
    \        return parallel(l) ? INF : 1.0 * (l.b - b) / (m - l.m);\r\n        }\r\
    \n        bool operator < (const line &l) const {\r\n            if(l.is_query)\
    \ return x < l.val;\r\n            else return m < l.m;\r\n        }\r\n    };\r\
    \n    std::set<line> hull;\r\n    bool hull_prev(std::set<line> :: iterator it)\
    \ { return it != hull.begin(); }\r\n    bool hull_next(std::set<line> :: iterator\
    \ it) { return it != hull.end() && next(it) != hull.end(); }\r\n    bool bad(const\
    \ line &l1, const line &l2, const line &l3) { return l1.intersect(l3) <= l1.intersect(l2);\
    \ }\r\n    bool bad(std::set<line> :: iterator it) { return hull_prev(it) && hull_next(it)\
    \ && bad(*prev(it), *it, *next(it)); }\r\n    std::set<line> :: iterator update(std::set<line>\
    \ :: iterator it) {\r\n        if(!hull_prev(it)) return it;\r\n        long double\
    \ x = it -> intersect(*prev(it));\r\n        line tmp(*it); tmp.x = x;\r\n   \
    \     it = hull.erase(it);\r\n        return hull.insert(it, tmp);\r\n    }\r\n\
    \    void add_line(long long m, long long b) {\r\n        m = -m, b = -b;\r\n\
    \        line l(m, b);\r\n        std::set<line> :: iterator it = hull.lower_bound(l);\r\
    \n        if(it != hull.end() && l.parallel(*it)) {\r\n            if(it -> b\
    \ < b) it = hull.erase(it);\r\n            else return;\r\n        }\r\n     \
    \   it = hull.insert(it, l);\r\n        if(bad(it)) return (void) hull.erase(it);\r\
    \n        while(hull_prev(it) && bad(prev(it))) hull.erase(prev(it));\r\n    \
    \    while(hull_next(it) && bad(next(it))) hull.erase(next(it));\r\n        it\
    \ = update(it);\r\n        if(hull_prev(it)) update(prev(it));\r\n        if(hull_next(it))\
    \ update(next(it));\r\n    }\r\n    long long query(long long x) const {\r\n \
    \       if(hull.empty()) return INF;\r\n        line q; q.val = x, q.is_query\
    \ = 1;\r\n        std::set<line> :: iterator it = --hull.lower_bound(q);\r\n \
    \       return -(it -> eval(x));\r\n    }\r\n};\r\n\r\nint main() {\r\n    return\
    \ 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/dynamic_convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:07:18-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/dynamic_convex_hull_trick.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/dynamic_convex_hull_trick.cpp
- /library/library/dynamic-programming/dynamic_convex_hull_trick.cpp.html
title: library/dynamic-programming/dynamic_convex_hull_trick.cpp
---

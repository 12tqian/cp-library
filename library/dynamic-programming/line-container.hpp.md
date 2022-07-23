---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-line_add_get_min.test.cpp
    title: verify/yosupo/yosupo-line_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct Line {\r\n\tmutable T k, m, p;\r\n\t\
    \r\n\tbool operator<(const Line<T>& o) const { return k < o.k; }\r\n\tbool operator<(T\
    \ x) const { return p < x; }\r\n};\r\n\r\ntemplate <class T> struct LineContainer\
    \ : std::multiset<Line<T>, std::less<>> {\r\n\t// (for doubles, use INF = 1/.0,\
    \ div(a,b) = a/b)\r\n\tconst T INF = std::numeric_limits<T>::max();\r\n\r\n\t\
    T div(T a, T b) { // floored division\r\n\t\treturn a / b - ((a ^ b) < 0 && a\
    \ % b); \r\n\t}\r\n\r\n\tusing super = std::multiset<Line<T>, std::less<>>;\r\n\
    \tusing iterator = typename LineContainer<T>::iterator;\r\n\t\r\n\tbool isect(iterator\
    \ x, iterator y) {\r\n\t\tif (y == super::end()) \r\n\t\t\treturn x->p = INF,\
    \ 0;\r\n\t\tif (x->k == y->k) \r\n\t\t\tx->p = x->m > y->m ? INF : -INF;\r\n\t\
    \telse \r\n\t\t\tx->p = div(y->m - x->m, x->k - y->k);\r\n\t\treturn x->p >= y->p;\r\
    \n\t}\r\n\t\r\n\tvoid add_line(T k, T m) {\r\n\t\tk = -k, m = -m;\r\n\t\tauto\
    \ z = super::insert({k, m, 0}), y = z++, x = y;\r\n\t\twhile (isect(y, z)) \r\n\
    \t\t\tz = super::erase(z);\r\n\t\tif (x != super::begin() && isect(--x, y)) \r\
    \n\t\t\tisect(x, y = super::erase(y));\r\n\t\twhile ((y = x) != super::begin()\
    \ && (--x)->p >= y->p)\r\n\t\t\tisect(x, super::erase(y));\r\n\t}\r\n\t\r\n\t\
    T query(T x) {\r\n\t\tassert(!super::empty());\r\n\t\tauto l = *super::lower_bound(x);\r\
    \n\t\treturn -(l.k * x + l.m);\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct Line {\r\n\tmutable T k, m,\
    \ p;\r\n\t\r\n\tbool operator<(const Line<T>& o) const { return k < o.k; }\r\n\
    \tbool operator<(T x) const { return p < x; }\r\n};\r\n\r\ntemplate <class T>\
    \ struct LineContainer : std::multiset<Line<T>, std::less<>> {\r\n\t// (for doubles,\
    \ use INF = 1/.0, div(a,b) = a/b)\r\n\tconst T INF = std::numeric_limits<T>::max();\r\
    \n\r\n\tT div(T a, T b) { // floored division\r\n\t\treturn a / b - ((a ^ b) <\
    \ 0 && a % b); \r\n\t}\r\n\r\n\tusing super = std::multiset<Line<T>, std::less<>>;\r\
    \n\tusing iterator = typename LineContainer<T>::iterator;\r\n\t\r\n\tbool isect(iterator\
    \ x, iterator y) {\r\n\t\tif (y == super::end()) \r\n\t\t\treturn x->p = INF,\
    \ 0;\r\n\t\tif (x->k == y->k) \r\n\t\t\tx->p = x->m > y->m ? INF : -INF;\r\n\t\
    \telse \r\n\t\t\tx->p = div(y->m - x->m, x->k - y->k);\r\n\t\treturn x->p >= y->p;\r\
    \n\t}\r\n\t\r\n\tvoid add_line(T k, T m) {\r\n\t\tk = -k, m = -m;\r\n\t\tauto\
    \ z = super::insert({k, m, 0}), y = z++, x = y;\r\n\t\twhile (isect(y, z)) \r\n\
    \t\t\tz = super::erase(z);\r\n\t\tif (x != super::begin() && isect(--x, y)) \r\
    \n\t\t\tisect(x, y = super::erase(y));\r\n\t\twhile ((y = x) != super::begin()\
    \ && (--x)->p >= y->p)\r\n\t\t\tisect(x, super::erase(y));\r\n\t}\r\n\t\r\n\t\
    T query(T x) {\r\n\t\tassert(!super::empty());\r\n\t\tauto l = *super::lower_bound(x);\r\
    \n\t\treturn -(l.k * x + l.m);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/line-container.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-line_add_get_min.test.cpp
documentation_of: library/dynamic-programming/line-container.hpp
layout: document
title: Line Container
---

## Line Container

This is currently modified for minimums. To modify for maximums, comment the first line in `add_line` and get rid of the negative of the `return` statement in `query`. 

This implementation is also blazingly fast for some reason, performs almost like constant time per operation. 

### Functions
- `add_line(k, m)`: Adds a line with slope $k$ and $y$-intercept $m$. 
- `query(x)`: Finds minimum of lines at location $x$. 

### Resources
- [KACTL](https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h)
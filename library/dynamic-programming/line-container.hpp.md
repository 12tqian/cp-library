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
  bundledCode: "\ntemplate <class T> struct Line {\n\tmutable T k, m, p;\n\t\n\tbool\
    \ operator<(const Line<T>& o) const { return k < o.k; }\n\tbool operator<(T x)\
    \ const { return p < x; }\n};\n\ntemplate <class T> struct LineContainer : std::multiset<Line<T>,\
    \ std::less<>> {\n\t// (for doubles, use INF = 1/.0, div(a,b) = a/b)\n\tconst\
    \ T INF = std::numeric_limits<T>::max();\n\n\tT div(T a, T b) { // floored division\n\
    \t\treturn a / b - ((a ^ b) < 0 && a % b); \n\t}\n\n\tusing super = std::multiset<Line<T>,\
    \ std::less<>>;\n\tusing iterator = typename LineContainer<T>::iterator;\n\t\n\
    \tbool isect(iterator x, iterator y) {\n\t\tif (y == super::end()) \n\t\t\treturn\
    \ x->p = INF, 0;\n\t\tif (x->k == y->k) \n\t\t\tx->p = x->m > y->m ? INF : -INF;\n\
    \t\telse \n\t\t\tx->p = div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\
    \t}\n\t\n\tvoid add_line(T k, T m) {\n\t\tk = -k, m = -m;\n\t\tauto z = super::insert({k,\
    \ m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) \n\t\t\tz = super::erase(z);\n\
    \t\tif (x != super::begin() && isect(--x, y)) \n\t\t\tisect(x, y = super::erase(y));\n\
    \t\twhile ((y = x) != super::begin() && (--x)->p >= y->p)\n\t\t\tisect(x, super::erase(y));\n\
    \t}\n\t\n\tT query(T x) {\n\t\tassert(!super::empty());\n\t\tauto l = *super::lower_bound(x);\n\
    \t\treturn -(l.k * x + l.m);\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct Line {\n\tmutable T k, m, p;\n\t\
    \n\tbool operator<(const Line<T>& o) const { return k < o.k; }\n\tbool operator<(T\
    \ x) const { return p < x; }\n};\n\ntemplate <class T> struct LineContainer :\
    \ std::multiset<Line<T>, std::less<>> {\n\t// (for doubles, use INF = 1/.0, div(a,b)\
    \ = a/b)\n\tconst T INF = std::numeric_limits<T>::max();\n\n\tT div(T a, T b)\
    \ { // floored division\n\t\treturn a / b - ((a ^ b) < 0 && a % b); \n\t}\n\n\t\
    using super = std::multiset<Line<T>, std::less<>>;\n\tusing iterator = typename\
    \ LineContainer<T>::iterator;\n\t\n\tbool isect(iterator x, iterator y) {\n\t\t\
    if (y == super::end()) \n\t\t\treturn x->p = INF, 0;\n\t\tif (x->k == y->k) \n\
    \t\t\tx->p = x->m > y->m ? INF : -INF;\n\t\telse \n\t\t\tx->p = div(y->m - x->m,\
    \ x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\t\n\tvoid add_line(T k, T m)\
    \ {\n\t\tk = -k, m = -m;\n\t\tauto z = super::insert({k, m, 0}), y = z++, x =\
    \ y;\n\t\twhile (isect(y, z)) \n\t\t\tz = super::erase(z);\n\t\tif (x != super::begin()\
    \ && isect(--x, y)) \n\t\t\tisect(x, y = super::erase(y));\n\t\twhile ((y = x)\
    \ != super::begin() && (--x)->p >= y->p)\n\t\t\tisect(x, super::erase(y));\n\t\
    }\n\t\n\tT query(T x) {\n\t\tassert(!super::empty());\n\t\tauto l = *super::lower_bound(x);\n\
    \t\treturn -(l.k * x + l.m);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/line-container.hpp
  requiredBy: []
  timestamp: '2021-08-13 00:37:31-04:00'
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
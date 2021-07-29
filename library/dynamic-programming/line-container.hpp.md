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
  bundledCode: "\n// modified for minimums\n\ntemplate <class T> struct Line {\n\t\
    mutable T k, m, p;\n\t\n\tbool operator<(const Line<T>& o) const { return k <\
    \ o.k; }\n\tbool operator<(T x) const { return p < x; }\n};\n\ntemplate <class\
    \ T> struct LineContainer : std::multiset<Line<T>, std::less<>> {\n\t// (for doubles,\
    \ use INF = 1/.0, div(a,b) = a/b)\n\tconst T INF = std::numeric_limits<T>::max();\n\
    \n\tT div(T a, T b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 &&\
    \ a % b); \n\t}\n\n\tusing super = std::multiset<Line<T>, std::less<>>;\n\tusing\
    \ iterator = typename LineContainer<T>::iterator;\n\t\n\tbool isect(iterator x,\
    \ iterator y) {\n\t\tif (y == super::end()) \n\t\t\treturn x->p = INF, 0;\n\t\t\
    if (x->k == y->k) \n\t\t\tx->p = x->m > y->m ? INF : -INF;\n\t\telse \n\t\t\t\
    x->p = div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\t\n\tvoid\
    \ add_line(T k, T m) {\n\t\tk = -k, m = -m;\n\t\tauto z = super::insert({k, m,\
    \ 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) \n\t\t\tz = super::erase(z);\n\
    \t\tif (x != super::begin() && isect(--x, y)) \n\t\t\tisect(x, y = super::erase(y));\n\
    \t\twhile ((y = x) != super::begin() && (--x)->p >= y->p)\n\t\t\tisect(x, super::erase(y));\n\
    \t}\n\t\n\tT query(T x) {\n\t\tassert(!super::empty());\n\t\tauto l = *super::lower_bound(x);\n\
    \t\treturn -(l.k * x + l.m);\n\t}\n};\n"
  code: "#pragma once\n\n// modified for minimums\n\ntemplate <class T> struct Line\
    \ {\n\tmutable T k, m, p;\n\t\n\tbool operator<(const Line<T>& o) const { return\
    \ k < o.k; }\n\tbool operator<(T x) const { return p < x; }\n};\n\ntemplate <class\
    \ T> struct LineContainer : std::multiset<Line<T>, std::less<>> {\n\t// (for doubles,\
    \ use INF = 1/.0, div(a,b) = a/b)\n\tconst T INF = std::numeric_limits<T>::max();\n\
    \n\tT div(T a, T b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 &&\
    \ a % b); \n\t}\n\n\tusing super = std::multiset<Line<T>, std::less<>>;\n\tusing\
    \ iterator = typename LineContainer<T>::iterator;\n\t\n\tbool isect(iterator x,\
    \ iterator y) {\n\t\tif (y == super::end()) \n\t\t\treturn x->p = INF, 0;\n\t\t\
    if (x->k == y->k) \n\t\t\tx->p = x->m > y->m ? INF : -INF;\n\t\telse \n\t\t\t\
    x->p = div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\t\n\tvoid\
    \ add_line(T k, T m) {\n\t\tk = -k, m = -m;\n\t\tauto z = super::insert({k, m,\
    \ 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) \n\t\t\tz = super::erase(z);\n\
    \t\tif (x != super::begin() && isect(--x, y)) \n\t\t\tisect(x, y = super::erase(y));\n\
    \t\twhile ((y = x) != super::begin() && (--x)->p >= y->p)\n\t\t\tisect(x, super::erase(y));\n\
    \t}\n\t\n\tT query(T x) {\n\t\tassert(!super::empty());\n\t\tauto l = *super::lower_bound(x);\n\
    \t\treturn -(l.k * x + l.m);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/line-container.hpp
  requiredBy: []
  timestamp: '2021-07-28 19:22:19-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-line_add_get_min.test.cpp
documentation_of: library/dynamic-programming/line-container.hpp
layout: document
redirect_from:
- /library/library/dynamic-programming/line-container.hpp
- /library/library/dynamic-programming/line-container.hpp.html
title: library/dynamic-programming/line-container.hpp
---

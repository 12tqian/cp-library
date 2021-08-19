---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class T> struct Affine {\n\tT a, b;\n\t\n\tconstexpr Affine()\
    \ : a(1), b(0) {}\n\tconstexpr Affine(T _a, T _b) : a(_a), b(_b) {}\n\tconstexpr\
    \ Affine(T _b) : a(0), b(_b) {}\n\n\tT operator()(T x) { return a * x + b; }\n\
    \t\n\tAffine operator-() { return Affine(-a, -b); }\n\t\n\tfriend Affine operator*(const\
    \ Affine& l, const Affine& r) {\n\t\treturn Affine(l.a * r.a, l.b * r.a + r.b);\
    \ }\n\tfriend Affine operator-(const Affine& l, const Affine& r) { return Affine(l.a\
    \ - r.a, l.b - r.b); }\n\tfriend Affine operator+(const Affine& l, const Affine&\
    \ r) { return Affine(l.a + r.a, l.b + r.b); }\n\t\n\tfriend Affine operator+(const\
    \ Affine& l, const T& r) { return Affine(l.a, l.b + r); }\n\tfriend Affine operator-(const\
    \ Affine& l, const T& r) { return Affine(l.a, l.b - r); }\n\tfriend Affine operator*(const\
    \ Affine& l, const T& r) { return Affine(l.a * r, l.b * r); }\n\tfriend Affine\
    \ operator/(const Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }\n\
    \n\tfriend Affine operator+(const T& l, Affine& r) { return r + l; }\n\tfriend\
    \ Affine operator-(const T& l, Affine& r) { return -r + l; }\n\tfriend Affine\
    \ operator*(const T& l, Affine& r) { return r * l; }\n\t\n\tfriend Affine& operator+=(Affine&\
    \ l, const Affine& r) { return l = l + r; }\n\tfriend Affine& operator-=(Affine&\
    \ l, const Affine& r) { return l = l - r; }\n\tfriend Affine& operator*=(Affine&\
    \ l, const Affine& r) { return l = l * r; }\n\n\tfriend Affine& operator+=(Affine&\
    \ l, const T& r) { return l = l + r; }\n\tfriend Affine& operator-=(Affine& l,\
    \ const T& r) { return l = l - r; }\n\tfriend Affine& operator*=(Affine& l, const\
    \ T& r) { return l = l * r; }\n\n\tbool operator==(const Affine& r) const { return\
    \ a == r.a && b == r.b; }\n\tbool operator!=(const Affine& r) const { return a\
    \ != r.a || b != r.b; }\n\n\tfriend ostream& operator<<(ostream& os, const Affine&\
    \ r) {\n\t\tos << \"( \" << r.a << \", \" << r.b << \" )\"; return os; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct Affine {\n\tT a, b;\n\t\n\tconstexpr\
    \ Affine() : a(1), b(0) {}\n\tconstexpr Affine(T _a, T _b) : a(_a), b(_b) {}\n\
    \tconstexpr Affine(T _b) : a(0), b(_b) {}\n\n\tT operator()(T x) { return a *\
    \ x + b; }\n\t\n\tAffine operator-() { return Affine(-a, -b); }\n\t\n\tfriend\
    \ Affine operator*(const Affine& l, const Affine& r) {\n\t\treturn Affine(l.a\
    \ * r.a, l.b * r.a + r.b); }\n\tfriend Affine operator-(const Affine& l, const\
    \ Affine& r) { return Affine(l.a - r.a, l.b - r.b); }\n\tfriend Affine operator+(const\
    \ Affine& l, const Affine& r) { return Affine(l.a + r.a, l.b + r.b); }\n\t\n\t\
    friend Affine operator+(const Affine& l, const T& r) { return Affine(l.a, l.b\
    \ + r); }\n\tfriend Affine operator-(const Affine& l, const T& r) { return Affine(l.a,\
    \ l.b - r); }\n\tfriend Affine operator*(const Affine& l, const T& r) { return\
    \ Affine(l.a * r, l.b * r); }\n\tfriend Affine operator/(const Affine& l, const\
    \ T& r) { return Affine(l.a / r, l.b / r); }\n\n\tfriend Affine operator+(const\
    \ T& l, Affine& r) { return r + l; }\n\tfriend Affine operator-(const T& l, Affine&\
    \ r) { return -r + l; }\n\tfriend Affine operator*(const T& l, Affine& r) { return\
    \ r * l; }\n\t\n\tfriend Affine& operator+=(Affine& l, const Affine& r) { return\
    \ l = l + r; }\n\tfriend Affine& operator-=(Affine& l, const Affine& r) { return\
    \ l = l - r; }\n\tfriend Affine& operator*=(Affine& l, const Affine& r) { return\
    \ l = l * r; }\n\n\tfriend Affine& operator+=(Affine& l, const T& r) { return\
    \ l = l + r; }\n\tfriend Affine& operator-=(Affine& l, const T& r) { return l\
    \ = l - r; }\n\tfriend Affine& operator*=(Affine& l, const T& r) { return l =\
    \ l * r; }\n\n\tbool operator==(const Affine& r) const { return a == r.a && b\
    \ == r.b; }\n\tbool operator!=(const Affine& r) const { return a != r.a || b !=\
    \ r.b; }\n\n\tfriend ostream& operator<<(ostream& os, const Affine& r) {\n\t\t\
    os << \"( \" << r.a << \", \" << r.b << \" )\"; return os; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/affine.hpp
  requiredBy: []
  timestamp: '2021-08-18 22:34:30-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_set_range_composite.test.cpp
documentation_of: library/math/affine.hpp
layout: document
redirect_from:
- /library/library/math/affine.hpp
- /library/library/math/affine.hpp.html
title: library/math/affine.hpp
---

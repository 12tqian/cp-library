---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct Affine {\r\n\tT a, b;\r\n\t\r\n\tconstexpr\
    \ Affine() : a(1), b(0) {}\r\n\tconstexpr Affine(T _a, T _b) : a(_a), b(_b) {}\r\
    \n\tconstexpr Affine(T _b) : a(0), b(_b) {}\r\n\r\n\tT operator()(T x) { return\
    \ a * x + b; }\r\n\t\r\n\tAffine operator-() { return Affine(-a, -b); }\r\n\t\r\
    \n\tfriend Affine operator*(const Affine& l, const Affine& r) {\r\n\t\treturn\
    \ Affine(l.a * r.a, l.b * r.a + r.b); }\r\n\tfriend Affine operator-(const Affine&\
    \ l, const Affine& r) { return Affine(l.a - r.a, l.b - r.b); }\r\n\tfriend Affine\
    \ operator+(const Affine& l, const Affine& r) { return Affine(l.a + r.a, l.b +\
    \ r.b); }\r\n\t\r\n\tfriend Affine operator+(const Affine& l, const T& r) { return\
    \ Affine(l.a, l.b + r); }\r\n\tfriend Affine operator-(const Affine& l, const\
    \ T& r) { return Affine(l.a, l.b - r); }\r\n\tfriend Affine operator*(const Affine&\
    \ l, const T& r) { return Affine(l.a * r, l.b * r); }\r\n\tfriend Affine operator/(const\
    \ Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }\r\n\r\n\tfriend\
    \ Affine operator+(const T& l, Affine& r) { return r + l; }\r\n\tfriend Affine\
    \ operator-(const T& l, Affine& r) { return -r + l; }\r\n\tfriend Affine operator*(const\
    \ T& l, Affine& r) { return r * l; }\r\n\t\r\n\tfriend Affine& operator+=(Affine&\
    \ l, const Affine& r) { return l = l + r; }\r\n\tfriend Affine& operator-=(Affine&\
    \ l, const Affine& r) { return l = l - r; }\r\n\tfriend Affine& operator*=(Affine&\
    \ l, const Affine& r) { return l = l * r; }\r\n\r\n\tfriend Affine& operator+=(Affine&\
    \ l, const T& r) { return l = l + r; }\r\n\tfriend Affine& operator-=(Affine&\
    \ l, const T& r) { return l = l - r; }\r\n\tfriend Affine& operator*=(Affine&\
    \ l, const T& r) { return l = l * r; }\r\n\r\n\tbool operator==(const Affine&\
    \ r) const { return a == r.a && b == r.b; }\r\n\tbool operator!=(const Affine&\
    \ r) const { return a != r.a || b != r.b; }\r\n\r\n\tfriend ostream& operator<<(ostream&\
    \ os, const Affine& r) {\r\n\t\tos << \"( \" << r.a << \", \" << r.b << \" )\"\
    ; return os; }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct Affine {\r\n\tT a, b;\r\n\t\
    \r\n\tconstexpr Affine() : a(1), b(0) {}\r\n\tconstexpr Affine(T _a, T _b) : a(_a),\
    \ b(_b) {}\r\n\tconstexpr Affine(T _b) : a(0), b(_b) {}\r\n\r\n\tT operator()(T\
    \ x) { return a * x + b; }\r\n\t\r\n\tAffine operator-() { return Affine(-a, -b);\
    \ }\r\n\t\r\n\tfriend Affine operator*(const Affine& l, const Affine& r) {\r\n\
    \t\treturn Affine(l.a * r.a, l.b * r.a + r.b); }\r\n\tfriend Affine operator-(const\
    \ Affine& l, const Affine& r) { return Affine(l.a - r.a, l.b - r.b); }\r\n\tfriend\
    \ Affine operator+(const Affine& l, const Affine& r) { return Affine(l.a + r.a,\
    \ l.b + r.b); }\r\n\t\r\n\tfriend Affine operator+(const Affine& l, const T& r)\
    \ { return Affine(l.a, l.b + r); }\r\n\tfriend Affine operator-(const Affine&\
    \ l, const T& r) { return Affine(l.a, l.b - r); }\r\n\tfriend Affine operator*(const\
    \ Affine& l, const T& r) { return Affine(l.a * r, l.b * r); }\r\n\tfriend Affine\
    \ operator/(const Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }\r\
    \n\r\n\tfriend Affine operator+(const T& l, Affine& r) { return r + l; }\r\n\t\
    friend Affine operator-(const T& l, Affine& r) { return -r + l; }\r\n\tfriend\
    \ Affine operator*(const T& l, Affine& r) { return r * l; }\r\n\t\r\n\tfriend\
    \ Affine& operator+=(Affine& l, const Affine& r) { return l = l + r; }\r\n\tfriend\
    \ Affine& operator-=(Affine& l, const Affine& r) { return l = l - r; }\r\n\tfriend\
    \ Affine& operator*=(Affine& l, const Affine& r) { return l = l * r; }\r\n\r\n\
    \tfriend Affine& operator+=(Affine& l, const T& r) { return l = l + r; }\r\n\t\
    friend Affine& operator-=(Affine& l, const T& r) { return l = l - r; }\r\n\tfriend\
    \ Affine& operator*=(Affine& l, const T& r) { return l = l * r; }\r\n\r\n\tbool\
    \ operator==(const Affine& r) const { return a == r.a && b == r.b; }\r\n\tbool\
    \ operator!=(const Affine& r) const { return a != r.a || b != r.b; }\r\n\r\n\t\
    friend ostream& operator<<(ostream& os, const Affine& r) {\r\n\t\tos << \"( \"\
    \ << r.a << \", \" << r.b << \" )\"; return os; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/affine.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-point_set_range_composite.test.cpp
documentation_of: library/math/affine.hpp
layout: document
redirect_from:
- /library/library/math/affine.hpp
- /library/library/math/affine.hpp.html
title: library/math/affine.hpp
---
